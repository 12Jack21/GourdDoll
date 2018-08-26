#pragma once
#include "cocos2d.h"
USING_NS_CC;
class AnimationManager {
public:
	static AnimationManager*getInstance();
	void init(); 
	
	//���Ķ���

	//��������
	//����
	void init_bat();
	//�۷侫
	void init_bee();
	//��򼾫
	void init_wugong();
	//��ţ��
	void init_tianniu();
	//��󡾫
	void init_frog();
	//�߾�
	void init_snake();
	//Ы�Ӿ�
	void init_xiezi();

	Animation* createAnimation(const char* prefixName, int start, int end, float delay);
};