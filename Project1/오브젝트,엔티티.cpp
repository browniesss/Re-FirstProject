#include "�Լ�.h"

ENTITY* CreateEntity(int type, int sizeX,int sizeY, int x, int y, bool show,int speed, int ChatIndex, int ChatPage) {
	ENTITY* newen = (ENTITY*)malloc(sizeof(ENTITY));

	newen->sizex = sizeX;
	newen->sizey = sizeY;
	newen->speed = speed;

	newen->point.x = x;
	newen->point.y = y;
	// �����̵�� �ΰ� �׸��� �ٿ��� �Ѿ���� �ٷ� ����ȭ������? 

	//����� ������ ��
	newen->rect.left = x ;
	newen->rect.right = x + sizeX;
	newen->rect.top = y ;
	newen->rect.bottom = y + sizeY;

	newen->type = type;
	newen->show = show;

	newen->ChatIndex = ChatIndex;
	newen->ChatPage = ChatPage;

	return newen;
}

OBJECTIVE* CreateObject(int type, int sizeX,int sizeY,int cutX,int cutY,int cutTY, int x, int y, bool show, int speed, int ObjectType,int animIndex, int motionIndex,int soundIndex,HBITMAP O_B)
{
	OBJECTIVE* newob = (OBJECTIVE*)malloc(sizeof(OBJECTIVE));

	newob->sizex = sizeX;
	newob->sizey = sizeY;
	newob->speed = speed;
	newob->animIndex = animIndex;
	newob->motionIndex = motionIndex;

	newob->point.x = x;
	newob->point.y = y;
	//����� ������ ��
	newob->rect.left = x + cutX;
	newob->rect.right = x + sizeX - cutX;
	newob->rect.top = y + cutTY;
	newob->rect.bottom = y + sizeY - cutY;

	newob->type = type;
	newob->show = show;

	newob->O_B = O_B;

	return newob;
}