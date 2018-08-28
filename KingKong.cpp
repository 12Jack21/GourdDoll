#include "Kingkong.h"
#include "GameManager.h"


bool Kingkong::init() {
	if (!Sprite::init()) {
		return false;
	}
	bulletSprite = Sprite::createWithSpriteFrameName(".png");
	addChild(bulletSprite);
	this->setMaxForce(500);

	return true;
}
void Kingkong::shoot(Point location) {
	setPosition(location);
	auto move = MoveBy::create(0.5f, Point(0, -320));
	runAction(Sequence::create(move,
		CallFuncN::create(CC_CALLBACK_0(Kingkong::removeKingkong, this)),
		NULL));
}
void Kingkong::removeKingkong()
{

	auto instance = GameManager::getInstance();

	auto kingkongPostion = this->getPosition() + this->getParent()->getPosition();

	auto monsterVector = instance->monsterVector;

	for (int j = 0; j < monsterVector.size(); j++)
	{
		auto monster = monsterVector.at(j);
		auto monsterPosition = monster->monsterSprite->getPosition();

		if (monster != NULL && kingkongPostion.distance(monsterPosition) <= 50 && monster->getAttackByDoll())
		{
			//音效
			SoundManager::playKingkong();
			auto curHp = monster->getCurHp();

			curHp = curHp - this->getMaxForce() + monster->getArmor();

			if (curHp <= 0) {
				curHp = 0;
			}
			monster->setCurHp(curHp);

			monster->getHpBar()->setPercentage((curHp / monster->getMaxHp()) * 100);

			if (curHp == 0) {
				monster->death();;
				//instance->monsterVector.eraseObject(monster);
			}
		}
	}
	//技能结束后的地裂效果
	bulletSprite->runAction(Sequence::create(
		Animate::create(AnimationCache::getInstance()->getAnimation("")),
		CallFuncN::create(CC_CALLBACK_0(Kingkong::removeFromParent, this))
		, NULL));

}
