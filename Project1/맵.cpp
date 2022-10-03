#pragma comment (lib, "winmm.lib")
#include "resource.h"
#include "함수.h"

OBJECTIVE* item[OB_C], * BI, * table[TB_C], * clue[CL_C], * wall[W_C], * statue[S_C], * guard[G_C], * effect, * inven[3], * machine, * LockDoor, * Hint[H_C], * Baek, * Door[D_C];

OBJECTIVE* returnObj;

HBITMAP char_UI[2], ConverUI[3];

BOOL Clear = FALSE;

void InvenC(HINSTANCE g_hInst) {
	inven[0] = CreateObject(Inven_1, 156, 171, 0, 0,0, INVEN_X, INVEN_Y - 200, true, 5, NonItem, 0, 0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(Inven_3)));
	inven[1] = CreateObject(Inven_2, 598, 188, 0, 0,0, INVEN_X, INVEN_Y, true, 5, NonItem, 0, 0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(Inven_2)));
	inven[2] = CreateObject(Inven_3, 342, 197, 0, 0,0, (INVEN_X + 80) + 1 * 147, INVEN_Y + 21, true, 5, NonItem, 0, 0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(Inven_1)));
}
void Map(HINSTANCE g_hInst, ENTITY* player) {
	for (int i = 0; i < OB_C; i++) {
		if (item[i] != NULL)
			item[i] = NULL;
	}
	for (int i = 0; i < TB_C; i++) {
		if (table[i] != NULL)
			table[i] = NULL;
	}
	for (int i = 0; i < CL_C; i++) {
		if (clue[i] != NULL)
			clue[i] = NULL;
	}
	for (int i = 0; i < S_C; i++) {
		if (statue[i] != NULL)
			statue[i] = NULL;
	}
	for (int i = 0; i < W_C; i++) {
		if (wall[i] != NULL)
			wall[i] = NULL;
	}
	for (int i = 0; i < G_C; i++) {
		if (guard[i] != NULL)
			guard[i] = NULL;
	}
	for (int i = 0; i < H_C; i++) {
		if (Hint[i] != NULL)
			Hint[i] = NULL;
	}
	for (int i = 0; i < D_C; i++) {
		if (Door[i] != NULL)
			Door[i] = NULL;
	}
	if (effect != NULL)
		effect = NULL;
	if (BI != NULL)
		BI = NULL;
	if (machine != NULL)
		machine = NULL;
	if (Baek != NULL)
		Baek = NULL;
	if (LockDoor != NULL)
		LockDoor = NULL;

	//아이템
	item[0] = CreateObject(O_Grape, 64, 64, 20, 20,0, 1145, 225, true, 5, Item, 0, 0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_Grape)));
	item[1] = CreateObject(O_Mugwork, 64, 64, 20, 20,0, 820, 225, true, 5, Item, 0, 0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_Mugwork)));
	item[2] = CreateObject(O_Spinash, 64, 64, 20, 20,0, 800, 725, true, 5, Item, 0, 0, 0,LoadBitmap(g_hInst, MAKEINTRESOURCE(O_Spinash)));
	item[3] = CreateObject(O_Raidsh, 64, 64, 20, 20,0, 1100, 725, true, 5, Item, 0, 0, 0,LoadBitmap(g_hInst, MAKEINTRESOURCE(O_Raidsh)));
	item[4] = CreateObject(O_GarLic, 64, 64, 20, 20,0, 1395, 725, true, 5, Item, 0, 0, 0,LoadBitmap(g_hInst, MAKEINTRESOURCE(O_GarLic)));


	//가온, 신성 UI
	char_UI[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP15));
	char_UI[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP16));

	//대화창
	ConverUI[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(CONVER));
	ConverUI[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(C_SIN_Conver));
	ConverUI[2] = LoadBitmap(g_hInst, MAKEINTRESOURCE(C_BAEK_Conver));


	if (player->mapIndex == 1) {
		//플레이어
		Updata(player, 1050, 350, true, 5, -1, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(C_SIN_MOVE)));

		//배경
		BI = CreateObject(MAP1_1, 0, 0, 0,0, 0, 0, 0, true, 0, NonItem,0,0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(MAP1_1)));
		//벽
		wall[0] = CreateObject(WALL, 10, 1000, 0, 0,0, 670, 64, true, 0,0, NonItem,0,0, NULL);
		wall[1] = CreateObject(WALL, 10, 1000, 0, 0,0, 1650, 64, true, 0,0, NonItem,0,0, NULL);
		wall[2] = CreateObject(WALL, 1000, 10, 0, 0,0, 670, 264, true, 0,0, NonItem,0,0,NULL);
		wall[3] = CreateObject(WALL, 1000, 10, 0, 0,0, 670, 900, true, 0,0, NonItem,0,0, NULL);

		//테이블
		table[0] = CreateObject(O_Table_2, 256, 128, 10, 100,0, 1050, 225, true, 0, NonItem,0,0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_Table_2)));
		table[1] = CreateObject(O_Table_2, 256, 128, 10, 100,0, 725, 225, true, 0, NonItem,0,0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_Table_2)));
		table[2] = CreateObject(O_Table_2, 256, 128, 10, 100,0, 1300, 725, true, 0, NonItem,0,0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_Table_2)));
		table[3] = CreateObject(O_Table_2, 256, 128, 10, 100,0, 1000, 725, true, 0, NonItem,0,0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_Table_2)));
		table[4] = CreateObject(O_Table_2, 256, 128, 10, 100,0, 700, 725, true, 0, NonItem,0,0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_Table_2)));
		
		//단서
		clue[0] = CreateObject(O_CLUE_base, 64, 150, 20, 20,0, 1400, 175, true, 5, Item,0,0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CLUE_base)));
		clue[1] = CreateObject(O_CLUE_base, 64, 150, 20, 20,0, 1500, 175, true, 5, Item,0,0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CLUE_base)));

		//단서 출력
		Hint[0] = CreateObject(O_CLUE_1, 500, 500, 0, 0, 0, 700, 250, false, 5, NonItem, 0, 0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CLUE_1)));
		Hint[1] = CreateObject(O_CLUE_2, 500, 500, 0, 0, 0, 700, 250, false, 5, NonItem, 0, 0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CLUE_2)));

		Door[0] = CreateObject(O_DOOR2, 50, 100, 0, 0, 0, 1650, 600, true, 5, Item, 0, 0,0, NULL);
	}
	else if (player->mapIndex == 2) { 

		Updata(player, 1600, 500, true, 5, -1, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(C_SIN_MOVE)));
		//배경
		BI = CreateObject(MAP1_2, 0, 0, 0, 0, 0, 0,0, true, 0, NonItem,0,0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(MAP1_2)));
		//벽
		wall[0] = CreateObject(WALL, 10, 1000, 0, 0,0, 510, 64, true, 0, NonItem, 0,0,0, NULL);
		wall[1] = CreateObject(WALL, 10, 1000, 0, 0,0, 1800, 64, true, 0, NonItem, 0,0,0, NULL);
		wall[2] = CreateObject(WALL, 1500, 10, 0, 0,0, 500, 224, true, 0, NonItem, 0,0,0, NULL);
		wall[3] = CreateObject(WALL, 1500, 10, 0, 0,0, 500, 880, true, 0, NonItem, 0,0,0, NULL);
		//석상
		statue[0] = CreateObject(O_BEAR, 128, 256, 20, 60, 70, 650, 600, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_BEAR)));
		statue[1] = CreateObject(O_LION, 128, 256, 20, 60, 70, 1100, 600, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_LION)));
		statue[2] = CreateObject(O_TIGER, 128, 256, 20, 60, 70, 1600, 600, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_TIGER)));
		statue[3] = CreateObject(O_WOLF, 128, 256, 20, 60, 70, 1600, 130, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_WOLF)));
		statue[4] = CreateObject(O_DOG, 128, 256, 20, 60, 70, 1100, 130, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_DOG)));
		statue[5] = CreateObject(O_RABBIT, 128, 256, 20, 70, 60, 650, 130, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_RABBIT)));
		statue[6] = CreateObject(O_DECO, 64, 128, 10, 10, 0, 530, 150, true, 5, NonItem, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_DECO)));
		statue[7] = CreateObject(O_DECO, 64, 128, 10, 10, 0, 1725, 150, true, 5, NonItem, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_DECO)));
		//가림막
		guard[0] = CreateObject(O_CF_1, 256, 128, 10, 100, 15, 600, 500, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CF_1)));
		guard[1] = CreateObject(O_CF_1, 256, 128, 10, 100, 15, 1050, 450, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CF_1)));
		guard[2] = CreateObject(O_CF_1, 256, 128, 30, 100, 15, 1500, 450, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CF_1)));
		guard[3] = CreateObject(O_CF_3, 64, 256, 10, 100, 15, 900, 200, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CF_3)));
		guard[4] = CreateObject(O_CF_3, 64, 256, 10, 100, 15, 1400, 200, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CF_3)));
		guard[5] = CreateObject(O_CF_3, 64, 256, 10, 100, 15, 1400, 600, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CF_3)));
		guard[6] = CreateObject(O_CF_2, 64, 256, 10, 100, 0, 1000, 600, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CF_2)));
		//이펙트
		effect = CreateObject(O_EFF_HEART, 64, 64, 0, 0, 0,0, 0, false, 5, NonItem, 0, 0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_EFF_HEART)));
		//백가온
		Baek = CreateObject(O_BAEK, 175, 175, 40, 10, 100, 650, 500, true, 5, Item, 0, 0,0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_BAEK)));

		Door[0] = CreateObject(O_DOOR1, 50, 100, 0, 0, 0, 1800, 760, true, 5, Item, 0, 0,0, NULL);
		Door[1] = CreateObject(O_DOOR2, 50, 100, 0, 0, 0, 1800, 480, true, 5, Item, 0, 0, 0, NULL);

	}
	else if (player->mapIndex == 3) {

		Updata(player, 800, 500, true, 5, -1, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(C_SIN_MOVE)));

		//배경
		BI = CreateObject(MAP1_3, 0, 0, 0, 0, 0, 0, 0, true, 0, NonItem, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(MAP1_3)));

		//기계
		machine = CreateObject(O_MACHIN, 256, 192, 20, 40, 0, 800, 225, true, 5, Item, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_MACHIN)));

		//벽
		wall[0] = CreateObject(WALL, 10, 1000, 0, 0, 0, 670, 64, true, 0, NonItem, 0, 0, 0, NULL);
		wall[1] = CreateObject(WALL, 10, 1000, 0, 0, 0, 1650, 64, true, 0, NonItem, 0, 0, 0, NULL);
		wall[2] = CreateObject(WALL, 1000, 10, 0, 0, 0, 670, 304, true, 0, NonItem, 0, 0, 0, NULL);
		wall[3] = CreateObject(WALL, 1000, 10, 0, 0, 0, 670, 810, true, 0, NonItem, 0, 0, 0, NULL);

		//가림막
		guard[0] = CreateObject(O_CF_3, 64, 256, 0, 40, 0, 1200, 200, true, 0, NonItem, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CF_3)));
		guard[1] = CreateObject(O_CF_3, 64, 256, 0, 40, 0, 1200, 550, true, 0, NonItem, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_CF_3)));
		if (Clear == false)
			LockDoor = CreateObject(O_LOCKDOOR, 64, 256, 0, 0, 0, 1200, 400, true, 0, NonItem, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_LOCKDOOR)));
		else if (Clear == true)
			LockDoor = CreateObject(O_LOCKDOOR, 0, 0, 0, 0, 0, 1200, 400, false, 0, NonItem, 0, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(O_LOCKDOOR)));

		Door[0] = CreateObject(O_DOOR1, 50, 100, 0, 0, 0, 640, 650, true, 5, Item, 0, 0, 0, NULL);
		Door[1] = CreateObject(O_CLEAR, 50, 100, 0, 0, 0, 1625, 650, true, 5, Item, 0, 0, 0, NULL);
	}
}

void Animation(OBJECTIVE* ObjectAnim, bool* InteractionCheck,HWND hWndMain, ENTITY* player, HINSTANCE g_hInst, BOOL* draw_Baek) {
	int BearItem;
	int DogItem;
	if (ObjectAnim->type == O_BEAR) { // 곰 석상 인벤토리 체크해서 마늘과 쑥 있을시에 
		if (ObjectAnim->motionIndex == 0) {
			BearItem = UseItem(player);
			if (BearItem == O_Grape) { //포도를 줬다는 메세지
				exit(1);
			}
			else if (BearItem == O_Mugwork) { //쑥을 줬다는 메세지
				ObjectAnim->motionIndex = 1;
				*InteractionCheck = FALSE;
			}
			else if (BearItem == O_Spinash) { //시금치를 줬다는 메세지
				*InteractionCheck = FALSE;
			}
			else if (BearItem == O_GarLic) { //마늘을 줬다는 메세지
				ObjectAnim->motionIndex = 1;
				*InteractionCheck = FALSE;
			}
			else if (BearItem == O_Raidsh) { //무를 줬다는 메세지
				*InteractionCheck = FALSE;
			}
		}
		else if (ObjectAnim->motionIndex == 1) {
			BearItem = UseItem(player);
			if (BearItem == O_Grape) { //포도를 줬다는 메세지
				exit(1);
			}
			else if (BearItem == O_Mugwork) { //쑥을 줬다는 메세지
				ObjectAnim->motionIndex = 2;
			}
			else if (BearItem == O_Spinash) { //시금치를 줬다는 메세지
				*InteractionCheck = FALSE;
			}
			else if (BearItem == O_GarLic) { //마늘을 줬다는 메세지
				ObjectAnim->motionIndex = 2;
			}
			else if (BearItem == O_Raidsh) { //무를 줬다는 메세지
				*InteractionCheck = FALSE;
			}
		}
		else if (ObjectAnim->motionIndex == 2) {
			PlaySound(MAKEINTRESOURCE(W_M2_BTOH), g_hInst, SND_RESOURCE | SND_ASYNC);
			if (ObjectAnim->animIndex < 14)
				ObjectAnim->animIndex++;
			if (ObjectAnim->animIndex == 13) {
				*InteractionCheck = FALSE;
				ObjectAnim->motionIndex++;
			}
		}
	}
	else if (ObjectAnim->type == O_CF_1) { // 가로 가림막 
		PlaySound(MAKEINTRESOURCE(W_M2_BREAK), g_hInst, SND_RESOURCE | SND_ASYNC);
		if (ObjectAnim->show == true)
			ObjectAnim->show = false;
		if (ObjectAnim->show == false) {
			if (statue[0]->motionIndex == 3 && guard[0]->show == false) {
				PlaySound(MAKEINTRESOURCE(W_M2_BREAK), g_hInst, SND_RESOURCE | SND_ASYNC);
				if (statue[5]->animIndex < 3)
					statue[5]->animIndex++;
				if (statue[5]->animIndex == 3) {
					*InteractionCheck = FALSE;
					statue[5]->motionIndex++;
				}
			}
		}
	}
	else if (ObjectAnim->type == O_CF_3) { // 세로 X없는 가림막
		PlaySound(MAKEINTRESOURCE(W_M2_BREAK), g_hInst, SND_RESOURCE | SND_ASYNC);
		if (ObjectAnim->show == true)
			ObjectAnim->show = false;
		if (statue[5]->motionIndex == 1 && guard[3]->show == false && statue[4]->motionIndex != 1) { // 개가 토끼 먹는 장면
			PlaySound(MAKEINTRESOURCE(W_M2_MOVING), g_hInst, SND_RESOURCE | SND_ASYNC);
			Updata(guard[0], 0, 0, false, 0, guard[1]->O_B);
			if (statue[4]->point.x > 650)
				statue[4]->point.x -= 50;
			if (statue[4]->point.x <= 650) {
				statue[5]->show = false;
				Updata(effect, statue[4]->point.x + 32, statue[4]->point.y + 70, true, 0, effect->O_B);
				SetRect(&statue[4]->rect, statue[4]->point.x + 10, statue[4]->point.y + 60, statue[4]->point.x + statue[4]->sizex - 10, statue[4]->point.y + statue[4]->sizey - 60);

				if (effect->animIndex < 16)
					effect->animIndex++;
				if (effect->animIndex == 16) {
					*InteractionCheck = FALSE;
					statue[4]->motionIndex = 1;
				}
			}
		}
		if (statue[4]->motionIndex == 1 && guard[4]->show == false && statue[4]->motionIndex != 2) { // 가림막 내리고 늑대 파괴
			PlaySound(MAKEINTRESOURCE(W_M2_BREAK), g_hInst, SND_RESOURCE | SND_ASYNC);
			Updata(guard[3], 0, 0, false, 0, guard[1]->O_B);
			if (statue[3]->animIndex < 3)
				statue[3]->animIndex++;
			if (statue[3]->animIndex == 3) {
				statue[4]->motionIndex = 2;
				*InteractionCheck = FALSE;
			}
		}
		if (statue[4]->motionIndex == 2 && guard[5]->show == false && guard[2]->show == false && statue[4]->motionIndex != 3) { // 가림막 내리고 사자 호랑이 석상 파괴
			PlaySound(MAKEINTRESOURCE(W_M2_BREAK), g_hInst, SND_RESOURCE | SND_ASYNC);
			if (statue[1]->animIndex < 3)
				statue[1]->animIndex++;
			if (statue[2]->animIndex < 3)
				statue[2]->animIndex++;
			if (statue[1]->animIndex == 3 && statue[2]->animIndex == 3) {
				statue[4]->motionIndex = 3;
				*InteractionCheck = FALSE;
			}
			Updata(guard[0], 0, 0, false, 0, guard[1]->O_B);
			Updata(guard[1], 0, 0, false, 0, guard[1]->O_B);
			Updata(guard[2], 0, 0, false, 0, guard[1]->O_B);
			Updata(guard[3], 0, 0, false, 0, guard[1]->O_B);
			Updata(guard[4], 0, 0, false, 0, guard[1]->O_B);

		}
		else { // 위 조건이 충족이 안될시 충족이 안됐다는 대화창 출력

		}
	}
	else if (ObjectAnim->type == O_DOG) {
		if (ObjectAnim->motionIndex == 3) {
			DogItem = UseItem(player);
			if (DogItem == O_Grape) { //포도를 줬다는 메세지
				ObjectAnim->motionIndex = 4;
				PlaySound(MAKEINTRESOURCE(W_M2_BREAK), g_hInst, SND_RESOURCE | SND_ASYNC);
			}
			else if (DogItem == O_Mugwork) { //쑥을 줬다는 메세지
				*InteractionCheck = FALSE;
			}
			else if (DogItem == O_Spinash) { //시금치를 줬다는 메세지
				*InteractionCheck = FALSE;
			}
			else if (DogItem == O_GarLic) { //마늘을 줬다는 메세지
				*InteractionCheck = FALSE;
			}
			else if (DogItem == O_Raidsh) { //무를 줬다는 메세지
				*InteractionCheck = FALSE;
			}
		}
		else if (ObjectAnim->motionIndex == 4) { // 포도를 줬을때
			if (ObjectAnim->animIndex < 3)
				ObjectAnim->animIndex++;
			if (ObjectAnim->animIndex == 3) {
				ObjectAnim->motionIndex = 5;
				Clear = true;
				player->ChatPage = 5;
				*InteractionCheck = FALSE;
			}
		}
	}
	else if (ObjectAnim == clue[0]) {
		PlaySound(MAKEINTRESOURCE(W_M1_NOTE), g_hInst, SND_RESOURCE | SND_ASYNC);
		if (Hint[0]->show == false)
			Hint[0]->show = true;
		else if (Hint[0]->show == true)
			Hint[0]->show = false;
		*InteractionCheck = FALSE;
	}
	else if (ObjectAnim == clue[1]) {
		PlaySound(MAKEINTRESOURCE(W_M1_NOTE), g_hInst, SND_RESOURCE | SND_ASYNC);
		if (Hint[1]->show == false)
			Hint[1]->show = true;
		else if (Hint[1]->show == true)
			Hint[1]->show = false;
		*InteractionCheck = FALSE;
	}
	else if (ObjectAnim->type == O_BAEK) {
		ObjectAnim->motionIndex++;
		if (ObjectAnim->animIndex < 2) {
			ObjectAnim->animIndex++;
			player->ChatPage = 3;
		}
		if (ObjectAnim->animIndex == 2) {
			ObjectAnim->motionIndex = 2;
			*InteractionCheck = FALSE;
		}
	}
	else if (ObjectAnim->type == O_DOOR1) {
		PlaySound(MAKEINTRESOURCE(W_M2_OPEN), g_hInst, SND_RESOURCE | SND_ASYNC);
		player->mapIndex--;
		Map(g_hInst, player);
		*InteractionCheck = FALSE;
	}
	else if (ObjectAnim->type == O_DOOR2) {
		PlaySound(MAKEINTRESOURCE(W_M2_OPEN), g_hInst, SND_RESOURCE | SND_ASYNC);
		player->mapIndex++;
		Map(g_hInst, player);
		*InteractionCheck = FALSE;
	}
	else if (ObjectAnim->type == O_CLEAR) {
		player->ChatPage = 7;
		*InteractionCheck = FALSE;
	}
}

OBJECTIVE* ObjectAnim(RECT rt) {
	for (int i = 0; i < OB_C; i++)
	{
		if (InRect(rt, item[i])) {
			return item[i];
		}
		for (int i = 0; i < TB_C; i++) {
			if (InRect(rt, table[i])) {
				return table[i];
				break;
			}
			for (int i = 0; i < CL_C; i++) {
				if (InRect(rt, clue[i])) {
					return clue[i];
					break;
				}
				for (int i = 0; i < W_C; i++) {
					if (InRect(rt, wall[i])) {
						return wall[i];
						break;
					}
					for (int i = 0; i < S_C; i++) {
						if (InRect(rt, statue[i])) {
							return statue[i];
							break;
						}for (int i = 0; i < G_C; i++) {
							if (InRect(rt, guard[i])) {
								return guard[i];
								break;
							}for (int i = 0; i < 1; i++) {
								if (InRect(rt, machine)) {
									return machine;
									break;
								}
								for (int i = 0; i < 1; i++) {
									if (InRect(rt, LockDoor)) {
										return LockDoor;
										break;
									}for (int i = 0; i < 1; i++) {
										if (InRect(rt, Baek)) {
											return Baek;
											break;
										}for (int i = 0; i < D_C; i++) {
											if (InRect(rt, Door[i])) {
												return Door[i];
												break;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}



void Updata(ENTITY* entity, int dx, int dy, bool show, int speed, int Direct, int pasDirect, HBITMAP newbit) {
	//dx, dy는 추후 추가
	entity->point.x = dx;
	entity->point.y = dy;
	entity->direct = Direct;
	entity->pasDirect = pasDirect;
	entity->show = show;
	entity->speed = speed;
	entity->E_B = newbit;
}

void Updata(OBJECTIVE* object, int dx, int dy, bool show, int speed, HBITMAP newbit) {
	//dx, dy는 추후 추가
	object->point.x = dx;
	object->point.y = dy;
	object->show = show;
	object->speed = speed;
	object->O_B = newbit;
	SetRect(&object->rect, 0, 0, 0, 0);
}
OBJECTIVE* OnTimer(ENTITY* player, RECT rt,RECT pRT, HWND hwnd, HDC hMemDC, HBITMAP OldBit, HBITMAP hBit, int InteractionCheck, int pi,int mi,int bi, int Keynum, int invensel
	, BOOL* draw_Baek, int* Party_part,HINSTANCE g_hInst)

{
	RECT crt;
	HDC hdc;
	HFONT font, oldfont;

	hdc = GetDC(hwnd);

	hMemDC = CreateCompatibleDC(hdc);
	OldBit = (HBITMAP)SelectObject(hMemDC, hBit);

	DrawBitmap(hMemDC, 0, 0, BI->O_B);// 배경
	//문
	for (int i = 0; i < D_C; i++) {
		if (Door[i] != NULL) {
			if (Door[i]->show == true) {
				TransBlt(hMemDC, Door[i]->point.x, Door[i]->point.y, Door[i]->O_B, RGB(59, 255, 0));
			}
		}
	}

	//벽(판정확인용)
	for (int i = 0; i < W_C; i++) {
		if (wall[i] != NULL)
			StretchDraw(hMemDC, wall[i]->point.x, wall[i]->point.y, wall[i]->O_B, wall[i]->sizex, wall[i]->sizey);
	}
	//단서방
	// 테이블
	for (int i = 0; i < TB_C; i++) {
		if(table[i] !=NULL)
			TransBlt(hMemDC, table[i]->point.x, table[i]->point.y, table[i]->O_B, RGB(59, 255, 0));
	}
	for (int i = 0; i < CL_C; i++) {
		if(clue[i] !=NULL)
			TransBlt(hMemDC, clue[i]->point.x, clue[i]->point.y, clue[i]->O_B, RGB(59, 255, 0));
	}
	//단서 이미지 출력
	for (int i = 0; i < H_C; i++) {
		if (Hint[i] != NULL) {
			if (Hint[i]->show == true)
				TransBlt(hMemDC, Hint[i]->point.x, Hint[i]->point.y, Hint[i]->O_B, RGB(59, 255, 0));
		}
	}
	//아이템
	for (int i = 0; i < OB_C; i++)
	{
		if (item[i] != NULL) {
			if (item[i]->show == true)
				TransBlt(hMemDC, item[i]->point.x, item[i]->point.y, item[i]->O_B, RGB(59, 255, 0));

		}
	}if (player->mapIndex >= 2) {
		//아이템
		Updata(item[0], 0, 0, false, 5, item[0]->O_B);
		Updata(item[1], 0, 0, false, 5, item[1]->O_B);
		Updata(item[2], 0, 0, false, 5, item[2]->O_B);
		Updata(item[3], 0, 0, false, 5, item[3]->O_B);
		Updata(item[4], 0, 0, false, 5, item[4]->O_B);
	}

	//석상방
	
	//곰 석상
	if (statue[0] != NULL) {
		if (statue[0]->show == true)
			DrawAnim(hMemDC, statue[0]->point.x, statue[0]->point.y, 14, 1, 128 * statue[0]->animIndex, 0, statue[0]->O_B, RGB(59, 255, 0));
	}
	//곰석상 제외 5개의 석상
	for (int i = 1; i < S_C-2; i++) {
		if (statue[i] != NULL) {
			if (statue[i]->show == true)
				DrawAnim(hMemDC, statue[i]->point.x, statue[i]->point.y, 4, 1, 128 * statue[i]->animIndex, 0, statue[i]->O_B, RGB(59, 255, 0));
		}
	}
	//장식 석상
	for (int i = 6; i < 8; i++) {
		if (statue[i] != NULL)
			TransBlt(hMemDC, statue[i]->point.x, statue[i]->point.y, statue[i]->O_B, RGB(59, 255, 0));
	}
	//가림막 가로
	for (int i = 0; i < G_C - 4; i++) {
		if (guard[i] != NULL) {
			if (guard[i]->show == true) {
				DrawAnim(hMemDC, guard[i]->point.x, guard[i]->point.y, 2, 1, guard[i]->animIndex * 256, 0, guard[i]->O_B, RGB(59, 255, 0));
			}
		}
	}
	//가림막 세로
	for (int i = 3; i < G_C-1; i++) {
		if (guard[i] != NULL) {
			if (guard[i]->show == true) {
				DrawAnim(hMemDC, guard[i]->point.x, guard[i]->point.y, 2, 1, guard[i]->animIndex * 64, 0, guard[i]->O_B, RGB(59, 255, 0));
			}
		}
	}
	if (guard[6] != NULL) {
		if (guard[6]->show == true)
			TransBlt(hMemDC, guard[6]->point.x, guard[6]->point.y, guard[6]->O_B, RGB(59, 255, 0));
	}
	//백가온
	if (Baek != NULL) {
		if (Baek->show == true && *draw_Baek == false) {
			if (Baek->motionIndex == 0)
				DrawAnim(hMemDC, Baek->point.x, Baek->point.y, 4, 4, 175 * bi, 175 * (Baek->motionIndex + 1), Baek->O_B, RGB(59, 255, 0));
			else if (Baek->motionIndex == 1)
				DrawAnim(hMemDC, Baek->point.x, Baek->point.y, 4, 4, 175 * Baek->animIndex, 175 * (Baek->motionIndex + 1), Baek->O_B, RGB(59, 255, 0));
			else if (Baek->motionIndex == 2)
				DrawAnim(hMemDC, Baek->point.x, Baek->point.y, 4, 4, 175 * Baek->animIndex, 175 * (Baek->motionIndex), Baek->O_B, RGB(59, 255, 0));
		}
	}
	//하트 이펙트
	if (effect != NULL) {
		if (effect->show == true)
			DrawAnim(hMemDC, effect->point.x, effect->point.y, 15, 1, 64 * effect->animIndex, 0, effect->O_B, RGB(59, 255, 0));
	}
	//기계
	if (player->mapIndex == 3) {
		if (machine != NULL) {
			if (machine->show == true)
				DrawAnim(hMemDC, machine->point.x, machine->point.y, 2, 1, 256 * mi, 0, machine->O_B, RGB(59, 255, 0));
		}
		if (LockDoor != NULL) {
			if (LockDoor->show == true)
				TransBlt(hMemDC, LockDoor->point.x, LockDoor->point.y, LockDoor->O_B, RGB(59, 255, 0));
		}
	}
	//대화창
	if (player->ChatPage==1) {
		RECT srt, rt;

		srt.left = 200;
		srt.top = 650;
		srt.right = srt.left + 200;
		srt.bottom = srt.top + 200;

		rt.left = 200;
		rt.top = 730;
		rt.right = rt.left + 1500;
		rt.bottom = rt.top + 384;
		if (player->ChatIndex == 1) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("젠장…. 또 이 빌어먹을 곳에 갇히네…. 전화는 통하니까, 일단 경찰에 신고는 해둘까?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 2) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("나는 그렇게 내가 이곳에 갇혀있다는 것을 경찰에게 알렸다."), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 3) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("오케이. 구하러 온다고 했으니까, 문제는 없을꺼야! 그럼…. 이럴 때 말고 탐정놀이를 언제 해보겠냐! 명탐정 신성오 나가신다!"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 4) {

			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("그럼 한 번…. 수색을 시작해볼까?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
	}
	else if (player->ChatPage == 3) {
		RECT srt, rt;

		srt.left = 200;
		srt.top = 650;
		srt.right = srt.left + 200;
		srt.bottom = srt.top + 200;

		rt.left = 200;
		rt.top = 730;
		rt.right = rt.left + 1500;
		rt.bottom = rt.top + 384;
		if (player->ChatIndex == 6) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("누구..신지?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 7) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("흠..."), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 8) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("저기? 여기서 주무시면 입돌아가요!"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 9) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("시끄럽게 누구… 네 녀석! 어디로 들어왔지?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 10) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("네….? 정문으로… 들어왔는데…"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 11) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("정문으로? 문은 열어두고 들어온거겠지?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 12) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("아니…. 문이 잠겨서…"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 13) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("….. 이 녀석, 쓸모없군."), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 14) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("아니! 사람한테 초면부터 쓸모없다는 말을 합니까!"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 15) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("그래서, 넌 나를 여기서 꺼내줄 수 있나?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 16) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("아… 그건"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 17) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("봐라. 쓸모없군."), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 18) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("(와… 이 사람… 재수없어…)"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 19) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("아무튼 저 쪽에 보이는 방문을 열려면 이 방에서 어떠한 방법을 찾아야 되는 듯 하다."), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 20) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("그… 그래서…?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 21) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("난 모르겠으니 네가 풀어봐라."), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 22) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("네? 제가요?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 23) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("너의 쓸모를 증명해봐라."), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 24) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("네.. 네… "), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 25) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("… 힌트를 하나만 주자면…"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 26) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("넵? 힌트요?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 27) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("벽을 잘 확인해봐라. 이 벽. 바닥 안쪽의 공간으로 넣을 수 있는 듯하다."), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 28) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("… 벽을… 내릴 수 있다…?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 29) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("그리고 이 방에 있는 6개의 동물 석상 등, 여러가지에서 힌트를 찾아 다음 방으로 나아가는 거겠지."), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
		}
		else if (player->ChatIndex == 30) {
			font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);
			TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

			SetBkMode(hMemDC, TRANSPARENT);
			SetTextColor(hMemDC, RGB(255, 255, 255));
			TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
			DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
			//텍스트 출력
			SelectObject(hMemDC, oldfont);
			DeleteObject(font);


			font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
				VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
			oldfont = (HFONT)SelectObject(hMemDC, font);

			DrawText(hMemDC, TEXT("동물 석상…  분명 이전 방에 단서같은 것들과 먹을거리가 있었는데 설마?"), -1, &rt, DT_WORDBREAK);

			SelectObject(hMemDC, oldfont);
			DeleteObject(font);

			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			ReleaseDC(hwnd, hdc);
			*draw_Baek = true;
		}
	}
	else if (player->ChatPage == 5) {
	RECT srt, rt;

	srt.left = 200;
	srt.top = 650;
	srt.right = srt.left + 200;
	srt.bottom = srt.top + 200;

	rt.left = 200;
	rt.top = 730;
	rt.right = rt.left + 1500;
	rt.bottom = rt.top + 384;
	if (player->ChatIndex == 32) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("클리어! 어때요? 제법이죠?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 33) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("내 안에 너에 대한 평가를 5살 수준에서 초등학생 수준으로 올려주지."), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 34) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("켁… 그래도 어린아이 수준이냐…"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 35) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("그래도 쓸모없다고 했던 건 취소하지. 제법이었다. 신성오."), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 36) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("앗… 역시 방금 제법 멋졌죠? 근데… 제 이름은 어떻게 아셨어요?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 37) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("… 정정하지 역시 쓸모없군. 네녀석이 아까전 명탐정 신성오라고 하지 않았나."), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 38) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("와… 그렇네요. 근데 저는 형 이름 모르는데요?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 39) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("이름 모르는 건 둘째 치고, 내가 왜 니 형이지?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 40) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("그야, 나보다 나이들어 보이니까?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 41) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("너 몇살이지?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 42) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("18살이요!"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 43) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("…. 그냥 형이라 불러"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 44) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("이름은요?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 45) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("백가온이다."), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 46) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("넵. 가온이 형."), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	}
	else if (player->ChatPage == 7) {
	RECT srt, rt;

	srt.left = 200;
	srt.top = 650;
	srt.right = srt.left + 200;
	srt.bottom = srt.top + 200;

	rt.left = 200;
	rt.top = 730;
	rt.right = rt.left + 1500;
	rt.bottom = rt.top + 384;
	if (player->ChatIndex == 48) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("통로가… 상당히 긴데요?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 49) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("문은…. 다시 열리는 걸 보아하니, 입구처럼 잠기지는 않을 듯 하다."), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 50) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("그래도 게임으로 치면 다음 스테이지로 넘어가는 과정이라 해야겠죠?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 51) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("… 부정할 수는 없겠군."), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 52) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 163, ConverUI[1], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("그럼 갈까요? 형?"), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	else if (player->ChatIndex == 53) {
		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);
		TransBlt(hMemDC, 150, 600, ConverUI[0], RGB(59, 255, 0));

		SetBkMode(hMemDC, TRANSPARENT);
		SetTextColor(hMemDC, RGB(255, 255, 255));
		TransBlt(hMemDC, 170, 53, ConverUI[2], RGB(31, 12, 3));
		DrawText(hMemDC, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
		//텍스트 출력
		SelectObject(hMemDC, oldfont);
		DeleteObject(font);


		font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
		oldfont = (HFONT)SelectObject(hMemDC, font);

		DrawText(hMemDC, TEXT("그래. 조심하면서 가라."), -1, &rt, DT_WORDBREAK);

		SelectObject(hMemDC, oldfont);
		DeleteObject(font);

		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hdc);
	}
	}
	

	//파티
	StretchDraw(hMemDC, INVEN_X + 58, INVEN_Y - 125, char_UI[1], 80, 80); //신성이UI
	if (player->ChatPage>=4)
	{
		StretchDraw(hMemDC, INVEN_X + 199, INVEN_Y - 125, char_UI[0], 80, 80); //가온이UI
	}
	//

	//플레이어(고정)
	if (player->show == TRUE)
	{
		if (player->direct == -1)
			DrawAnim(hMemDC, player->point.x, player->point.y, 4, 4, 175, player->pasDirect * 175, player->E_B, RGB(59, 255, 0));

		DrawAnim(hMemDC, player->point.x, player->point.y, 4, 4, 175 * pi, 175 * player->direct, player->E_B, RGB(59, 255, 0));
	}

	//인벤토리
	if (inven[0] != NULL)
		TransBlt(hMemDC, INVEN_X, INVEN_Y - 200, inven[0]->O_B, RGB(255, 255, 255));
	if (inven[1] != NULL)
		TransBlt(hMemDC, INVEN_X, INVEN_Y, inven[1]->O_B, RGB(255, 255, 255));
	if (inven[2] != NULL)
		TransBlt(hMemDC, (INVEN_X + 67) + Keynum * 120, INVEN_Y + 20, inven[2]->O_B, RGB(255, 255, 255)); //(너비)
	DrawInventory(hMemDC, item, player, invensel); //인벤토리에 넣어진 아이템 출력
	//

	returnObj = ObjectAnim(pRT);


	SelectObject(hMemDC, OldBit);
	DeleteDC(hMemDC);
	ReleaseDC(hwnd, hdc);
	InvalidateRect(hwnd, NULL, FALSE);

	return returnObj;
}

int Obstacle(RECT rt, int* crash, int dir, int* crash_type, BOOL* crash_Baek)
{
	for (int i = 0; i < OB_C; i++)
	{
		if (InRect(rt, item[i]) && item[i]->show == true)
		{
			*crash = 1;
			*crash_type = item[i]->type;
			break;
		}
		else
			*crash = 0;
		for (int i = 0; i < TB_C; i++)
		{
			if (InRect(rt, table[i]) && table[i]->show == true)
			{
				*crash = 1;
				break;
			}
			else
				*crash = 0;
			for (int i = 0; i < CL_C; i++)
			{
				if (InRect(rt, clue[i]) && clue[i]->show == true)
				{
					*crash = 1;
					break;
				}
				else
				{
					*crash = 0;
				}
				for (int i = 0; i < W_C; i++)
				{
					if (InRect(rt, wall[i]))
					{
						*crash = 1;
						break;
					}
					else
					{
						*crash = 0;
					}
					for (int i = 0; i < S_C; i++)
					{
						if (InRect(rt, statue[i]) && statue[i]->show == true)
						{
							*crash = 1;
							break;
						}
						else
						{
							*crash = 0;
						}
						for (int i = 0; i < G_C; i++) {
							if (InRect(rt, guard[i])) {
								*crash = 1;
								break;
							}
							else
							{
								*crash = 0;
							}
							for (int i = 0; i < 1; i++) {
								if (InRect(rt, machine)) {
									*crash = 1;
									break;
								}
								else
								{
									*crash = 0;
								}
							}
							for (int i = 0; i < 1; i++) {
								if (InRect(rt, Baek)) {
									*crash = 1;
									*crash_Baek = true;
									break;
								}
								else
								{
									*crash = 0;
									*crash_Baek = false;
								}for (int i = 0; i < 1; i++) {
									if (InRect(rt, LockDoor) && LockDoor->show == true) {
										*crash = 1;
										break;
									}
									else
									{
										*crash = 0;
									}for (int i = 0; i < D_C; i++) {
										if (InRect(rt, Door[i])) {
											*crash = 1;
											break;
										}
										else
										{
											*crash = 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return dir;
}