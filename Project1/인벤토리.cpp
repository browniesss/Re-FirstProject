#include "함수.h"

bool CheckInven[invenSize];
RECT InvenRT[3] = { {},{},{} };
int index = 0;

void DrawInventory(HDC hMemDC, OBJECTIVE* item[], ENTITY* player, int invensel) //들어온 아이템을 띄우기 위한 함수구문
{
	int k = 0;

	for (int i = invensel; i <= invensel + 2; i++) //inven배열 0번째에서 2번째까지 출력한다.
	{
		if (player->inven[i] == item[0]->type) //포도
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

	for (int i = 0; i < invenSize; i++) //같은 타입이 있는 경우 대입X
	{
		if (player->inven[i] == type)
		{
			return false;
		}
	}

	if (*pl_inven_index == 5) //아이템 선택경우 아이템이 사라져야함
	{
		return false; //마지막 인덱스인 경우 
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