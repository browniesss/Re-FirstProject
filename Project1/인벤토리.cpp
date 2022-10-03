#include "�Լ�.h"

bool CheckInven[invenSize];
RECT InvenRT[3] = { {},{},{} };
int index = 0;

void DrawInventory(HDC hMemDC, OBJECTIVE* item[], ENTITY* player, int invensel) //���� �������� ���� ���� �Լ�����
{
	int k = 0;

	for (int i = invensel; i <= invensel + 2; i++) //inven�迭 0��°���� 2��°���� ����Ѵ�.
	{
		if (player->inven[i] == item[0]->type) //����
		{
			TransBlt(hMemDC, 117 + k * 117, INVEN_Y + 57, item[0]->O_B, RGB(59, 255, 0));
		}
		else if (player->inven[i] == item[1]->type)
		{
			TransBlt(hMemDC, 117 + k * 117, INVEN_Y + 57, item[1]->O_B, RGB(59, 255, 0));
		}
		else if (player->inven[i] == item[2]->type)
		{
			TransBlt(hMemDC, 117 + k * 117, INVEN_Y + 57, item[2]->O_B, RGB(59, 255, 0));
		}
		else if (player->inven[i] == item[3]->type)
		{
			TransBlt(hMemDC, 117 + k * 117, INVEN_Y + 57, item[3]->O_B, RGB(59, 255, 0));
		}
		else if (player->inven[i] == item[4]->type)
		{
			TransBlt(hMemDC, 117 + k * 117, INVEN_Y + 57, item[4]->O_B, RGB(59, 255, 0));
		}
		k++;
	}
}

BOOL AddItem(ENTITY* player, int type, int* pl_inven_index)
{
	//player->inven[*pl_inven_index] = 10001;

	if (type == 0)
	{
		return false;
	}

	for (int i = 0; i < invenSize; i++) //���� Ÿ���� �ִ� ��� ����X
	{
		if (player->inven[i] == type)
		{
			return false;
		}
	}

	if (*pl_inven_index == 5) //������ ���ð�� �������� ���������
	{
		return false; //������ �ε����� ��� 
	}
	player->inven[*pl_inven_index] = type;
	*pl_inven_index = *pl_inven_index + 1;
	return true;
}

void DeleteItem(ENTITY* player)
{
	for (int i = 0; i < invenSize; i++)
	{
		if (CheckInven[i] == true)
		{
			player->inven[i] = NULL;
		}
	}
}

void SelectItem(ENTITY* player, int key)
{
	for (int i = 0; i < invenSize; i++) {
		CheckInven[i] = false;
	}
	CheckInven[key] = true;
}

int UseItem(ENTITY* player) {
	for (int i = 0; i < invenSize; i++) {
		if (CheckInven[i] == true) {
			int pasi;
			pasi = player->inven[i];
			player->inven[i] = NULL;
			return pasi;
		}
	}
}