#pragma once

#include "SystemHeader.h"
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

	//��«��
	void init_FirstDoll();
	void init_SecondDoll();
	void init_ThirdDoll();
	void init_FourthDoll();
	void init_FifthDoll();
	void init_SixthDoll();
	void init_SeventhDoll();
	void init_others();
	void init_Grandpa();
	Animation* createAnimation(const char* prefixName, int start, int end, float delay);
private:
	static AnimationManager * instance;
};
