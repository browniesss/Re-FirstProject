#include "함수.h"
#include "resource.h"

//시작화면
HBITMAP BITMAP_start_menu[3];
HBITMAP BITMAP_start;

void startBitmap(HINSTANCE g_hInst, HWND hwnd, int start, int sel)
{
	HDC hdc;
	RECT crt;
	GetClientRect(hwnd, &crt);
	hdc = GetDC(hwnd);

	if (BITMAP_start == NULL)
	{
		BITMAP_start = LoadBitmap(g_hInst, MAKEINTRESOURCE(S_START_BACK));
		BITMAP_start_menu[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(S_START_START));
		BITMAP_start_menu[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(S_START_EXIT));
		BITMAP_start_menu[2] = LoadBitmap(g_hInst, MAKEINTRESOURCE(S_START_RESUME));
	}

	if (start == -1)
	{
		if (sel == 0)
		{
			DrawBitmap(hdc, 0, 0, BITMAP_start); //배경
			start_transblt(hdc, 870, 570, BITMAP_start_menu[0], RGB(255, 255, 255), 1);
			start_transblt(hdc, 870, 640, BITMAP_start_menu[2], RGB(255, 255, 255), 0);
			start_transblt(hdc, 870, 710, BITMAP_start_menu[1], RGB(255, 255, 255), 0);
		}
		if (sel == 1)
		{
			DrawBitmap(hdc, 0, 0, BITMAP_start); //배경
			start_transblt(hdc, 870, 570, BITMAP_start_menu[0], RGB(255, 255, 255), 0);
			start_transblt(hdc, 870, 640, BITMAP_start_menu[2], RGB(255, 255, 255), 1);
			start_transblt(hdc, 870, 710, BITMAP_start_menu[1], RGB(255, 255, 255), 0);
		}
		if (sel == 2)
		{
			DrawBitmap(hdc, 0, 0, BITMAP_start); //배경
			start_transblt(hdc, 870, 570, BITMAP_start_menu[0], RGB(255, 255, 255), 0);
			start_transblt(hdc, 870, 640, BITMAP_start_menu[2], RGB(255, 255, 255), 0);
			start_transblt(hdc, 870, 710, BITMAP_start_menu[1], RGB(255, 255, 255), 1);
		}
	}

	ReleaseDC(hwnd, hdc);
}

void start_transblt(HDC hdc, int x, int y, HBITMAP hBit, COLORREF color, int X_sel)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth / 2;
	by = bit.bmHeight;

	TransparentBlt(hdc, x, y, bx, by, MemDC, X_sel * 170, 0, bx, by, color);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}
//


void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

void TransBlt(HDC hdc, int x, int y, HBITMAP hBit, COLORREF color) {

	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	TransparentBlt(hdc, x, y, bx, by, MemDC, 0, 0, bx, by, color);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

void StretchDraw(HDC hdc, int x, int y, HBITMAP hBit, int sizex, int sizey) {
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	StretchBlt(hdc, x, y, sizex, sizey, MemDC, 0, 0, bx, by, SRCCOPY);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

void DrawAnim(HDC hdc, int x, int y, int divideX, int divideY, int xstart, int ystart, HBITMAP hBit, COLORREF color)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	TransparentBlt(hdc, x, y, bx / divideX, by / divideY, MemDC, xstart, ystart, bx / divideX, by / divideY, color);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

int AnimIndex(int i, int size) {
	if (i < size)
		i++;
	else if (i >= size)
		i = 0;

	return i;
}


//대화창
HBITMAP BitMap_PartyWindows;
HBITMAP BitMap_Char[2];
//

//파티창


void Conver(HWND hwnd, HINSTANCE g_hInst, int type, LPCWSTR text) {
	RECT crt, rt, srt;
	HDC hdc, hMemDC;
	HFONT font, oldfont;
	HBITMAP hBit = NULL, OldBit;

	srt.left = 200;
	srt.top = 650;
	srt.right = srt.left + 200;
	srt.bottom = srt.top + 200;

	rt.left = 200;
	rt.top = 730;
	rt.right = rt.left + 1500;
	rt.bottom = rt.top + 384;

	GetClientRect(hwnd, &crt);
	hdc = GetDC(hwnd);

	font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
		VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
	oldfont = (HFONT)SelectObject(hdc, font);
	//이거 필요한건가?
	if (hBit == NULL)
		hBit = CreateCompatibleBitmap(hdc, crt.right, crt.bottom);

	if (type != NULL)
		TransBlt(hdc, 150, 600, LoadBitmap(g_hInst, MAKEINTRESOURCE(CONVER)), RGB(59, 255, 0));

	hMemDC = CreateCompatibleDC(hdc);
	OldBit = (HBITMAP)SelectObject(hMemDC, hBit);

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(255, 255, 255));

	if (type == C_SIN_Conver) {
		TransBlt(hdc, 170, 163, LoadBitmap(g_hInst, MAKEINTRESOURCE(C_SIN_Conver)), RGB(31, 12, 3));
		DrawText(hdc, TEXT("신성오"), -1, &srt, DT_WORDBREAK);
	}
	else if (type == C_BAEK_Conver) {
		TransBlt(hdc, 170, 53, LoadBitmap(g_hInst, MAKEINTRESOURCE(C_BAEK_Conver)),  RGB(31, 12, 3));
		DrawText(hdc, TEXT("백가온"), -1, &srt, DT_WORDBREAK);
	}
	else if(type == NULL)
		DrawText(hdc, TEXT("나레이션"), -1, &srt, DT_WORDBREAK);

	SelectObject(hdc, oldfont);
	DeleteObject(font);
	
	font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
		VARIABLE_PITCH | FF_ROMAN, TEXT("고딕"));
	oldfont = (HFONT)SelectObject(hdc, font);

	DrawText(hdc, text, -1, &rt, DT_WORDBREAK);

	SelectObject(hdc, oldfont);
	DeleteObject(font);

	SelectObject(hMemDC, OldBit);
	DeleteDC(hMemDC);
	ReleaseDC(hwnd, hdc);
}

BOOL Road_PartyWindows(HINSTANCE g_hInst, HWND hwnd,
	int* Party_sel, int* Party_next, int* Party_part)
{
	RECT crt;
	HDC hdc;

	if (*Party_part == 2) //시나리오가 다 끝나면 구문이 돌지 못하도록 한다.
	{
		return false;
	}

	hdc = GetDC(hwnd);

	if (*Party_sel == 1)
	{

		if (*Party_part == 1)
		{
			if (*Party_next == 1)
			{
				Conver(hwnd, g_hInst, C_BAEK_Conver, TEXT("뭐 궁금한 거라도 있나?"));
			}
			else if (*Party_next == 2)
			{
				Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("아니 딱히 없는데..."));
			}
			else if (*Party_next == 3)
			{
				Conver(hwnd, g_hInst, C_BAEK_Conver, TEXT("...시시하군."));
			}
			else if (*Party_next == 4)
			{
				*Party_sel = 3; //선택해제
				*Party_part = 2; //다음 시나리오로 이동!
				*Party_next = 1; //다시 초기화
			}

		}
	}

	ReleaseDC(hwnd, hdc);
	return true;
}

void movie(HWND hwnd, HINSTANCE g_hInst, int type, int S) {
	RECT crt;
	static HDC hdc, hMemDC;
	static HBITMAP hBit = NULL, OldBit;

	GetClientRect(hwnd, &crt);
	hdc = GetDC(hwnd);

	if (hBit == NULL)
		hBit = CreateCompatibleBitmap(hdc, crt.right, crt.bottom);

	hMemDC = CreateCompatibleDC(hdc);
	OldBit = (HBITMAP)SelectObject(hMemDC, hBit);

	if (type == 'S') {
		if (S == 0) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_1)));
			Conver(hwnd, g_hInst, NULL, TEXT("21세기 후반까지, 인류의 과학은 무한히 진화해나갔다."));
		}
		else if (S == 1) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_2)));
			Conver(hwnd, g_hInst, NULL, TEXT("그런 인류의 과학이 새롭게 목표로 잡은 것은, 탄생에 관한 것이었다."));
		}
		else if (S == 2) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_3)));
			Conver(hwnd, g_hInst, NULL, TEXT("탄생. 인류는 새로운 생명이 만들어지는 고귀함을 지우고 신이 지닌 생명의 권능을 모방하려했다."));
		}
		else if (S == 3) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_3)));
			Conver(hwnd, g_hInst, NULL, TEXT("그들은 신이 만든 최초의 인류. 아담과 이브. 그러한 존재를 창조하려 했으나 실패를 반복했다."));
		}
		else if (S == 4) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_4)));
			Conver(hwnd, g_hInst, NULL, TEXT("그러던 와중 한 천재가 새로운 방식을 제안했다."));
		}
		else if (S == 5) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_4)));
			Conver(hwnd, g_hInst, NULL, TEXT("아담과 이브로부터 파생된 인간. 그 인간을 연구하여, 새로운 탄생의 실마리를 얻자고."));
		}
		else if (S == 6) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_5)));
			Conver(hwnd, g_hInst, NULL, TEXT("남은 과학자들은 그들을 미쳤다 손가락질하고 그들에 대한 이야기를 꺼내지 않았다, 그의 말에 현혹된 과학자들은 그와 함께 떠나 연구실을 만들었다."));
		}
		else if (S == 7) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_6)));
			Conver(hwnd, g_hInst, NULL, TEXT("연구실은 새로운 에덴이 될 것이라 믿어 의심치 않은 그들은, 점차 미쳐갔다."));
		}
		else if (S == 8) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_6)));
			Conver(hwnd, g_hInst, NULL, TEXT("선악의 개념조차 익히지 못한 어린아이들이 아담과 이브에 가깝다 판단한 그들은 수많은 어린아이들을 가지고 실험했고 이 잔혹한 실험이 세상에 드러났다."));
		}
		else if (S == 9) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_7)));
			Conver(hwnd, g_hInst, NULL, TEXT("수많은 사람들이 그곳으로 찾아가 인류가 그러한 죄를 범했다는 사실을 인정하지 않기 위해 연구실 안의 모든 것들을 전부 죽였다."));
		}
		else if (S == 10) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_8)));
			Conver(hwnd, g_hInst, NULL, TEXT("그 현장에서 살아남을 수 있었던 존재들은 어린아이들뿐이었고, 거기서 살아남은 수많은 아이들은 자신의 부모, 자신의 이름조차 모른채 살아갔다."));
		}
		else if (S == 11) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_9)));
			Conver(hwnd, g_hInst, NULL, TEXT("그런 추악한 실험은 끝이 났다. Re:First-Project 라는 어둠만을 남기고…"));
		}
		else if (S == 12) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_10)));
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("그 때는 이곳이 참 싫었는데, 이제와서 보니 나름 그립기도 하네."));
		}
		else if (S == 13) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_10)));
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("진짜 두 번 다시 안 돌아올 줄 알았는데… 이곳에 내 가족에 대한 기록이 남아있을 수도 있다니까…. 한 번 들어가볼까?"));
		}
		else if (S == 14) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_10)));
			Conver(hwnd, g_hInst, NULL, TEXT("진짜 몰랐던 것 내가 아니었을까? 나는 생각한다."));
		}
		else if (S == 15) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_10)));
			Conver(hwnd, g_hInst, NULL, TEXT("그 때는 이곳에 갇혀 어떤 일이 일어날지, 하나도 예상하지 못했다."));
		}
		else if (S == 16) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_11)));
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("어…? 문이 왜 다시 안열려? 어? 거기 밖에 아무도 없어요? 문이 안열려요!!! 안에 사람 갇혔다고!!!!"));
		}
	}
	else if (type == 'P1') {
		if (S == 17) {
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("젠장…. 또 이 빌어먹을 곳에 갇히네…. 전화는 통하니까, 일단 경찰에 신고는 해둘까?"));
		}
		else if (S == 18) {
			Conver(hwnd, g_hInst, NULL, TEXT("나는 그렇게 내가 이곳에 갇혀있다는 것을 경찰에게 알렸다."));
		}
		else if (S == 19) {
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("오케이. 구하러 온다고 했으니까, 문제는 없을꺼야! 그럼…. 이럴 때 말고 탐정놀이를 언제 해보겠냐! 명탐정 신성오 나가신다!"));
		}
		else if (S == 20) {
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("그럼 한 번…. 수색을 시작해볼까?"));
		}
	}
	SelectObject(hMemDC, OldBit);
	DeleteDC(hMemDC);
	ReleaseDC(hwnd, hdc);
}