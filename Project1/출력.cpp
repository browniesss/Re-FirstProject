#include "�Լ�.h"
#include "resource.h"

//����ȭ��
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
			DrawBitmap(hdc, 0, 0, BITMAP_start); //���
			start_transblt(hdc, 870, 570, BITMAP_start_menu[0], RGB(255, 255, 255), 1);
			start_transblt(hdc, 870, 640, BITMAP_start_menu[2], RGB(255, 255, 255), 0);
			start_transblt(hdc, 870, 710, BITMAP_start_menu[1], RGB(255, 255, 255), 0);
		}
		if (sel == 1)
		{
			DrawBitmap(hdc, 0, 0, BITMAP_start); //���
			start_transblt(hdc, 870, 570, BITMAP_start_menu[0], RGB(255, 255, 255), 0);
			start_transblt(hdc, 870, 640, BITMAP_start_menu[2], RGB(255, 255, 255), 1);
			start_transblt(hdc, 870, 710, BITMAP_start_menu[1], RGB(255, 255, 255), 0);
		}
		if (sel == 2)
		{
			DrawBitmap(hdc, 0, 0, BITMAP_start); //���
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


//��ȭâ
HBITMAP BitMap_PartyWindows;
HBITMAP BitMap_Char[2];
//

//��Ƽâ


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
		VARIABLE_PITCH | FF_ROMAN, TEXT("���"));
	oldfont = (HFONT)SelectObject(hdc, font);
	//�̰� �ʿ��Ѱǰ�?
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
		DrawText(hdc, TEXT("�ż���"), -1, &srt, DT_WORDBREAK);
	}
	else if (type == C_BAEK_Conver) {
		TransBlt(hdc, 170, 53, LoadBitmap(g_hInst, MAKEINTRESOURCE(C_BAEK_Conver)),  RGB(31, 12, 3));
		DrawText(hdc, TEXT("�鰡��"), -1, &srt, DT_WORDBREAK);
	}
	else if(type == NULL)
		DrawText(hdc, TEXT("�����̼�"), -1, &srt, DT_WORDBREAK);

	SelectObject(hdc, oldfont);
	DeleteObject(font);
	
	font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
		VARIABLE_PITCH | FF_ROMAN, TEXT("���"));
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

	if (*Party_part == 2) //�ó������� �� ������ ������ ���� ���ϵ��� �Ѵ�.
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
				Conver(hwnd, g_hInst, C_BAEK_Conver, TEXT("�� �ñ��� �Ŷ� �ֳ�?"));
			}
			else if (*Party_next == 2)
			{
				Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("�ƴ� ���� ���µ�..."));
			}
			else if (*Party_next == 3)
			{
				Conver(hwnd, g_hInst, C_BAEK_Conver, TEXT("...�ý��ϱ�."));
			}
			else if (*Party_next == 4)
			{
				*Party_sel = 3; //��������
				*Party_part = 2; //���� �ó������� �̵�!
				*Party_next = 1; //�ٽ� �ʱ�ȭ
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
			Conver(hwnd, g_hInst, NULL, TEXT("21���� �Ĺݱ���, �η��� ������ ������ ��ȭ�س�����."));
		}
		else if (S == 1) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_2)));
			Conver(hwnd, g_hInst, NULL, TEXT("�׷� �η��� ������ ���Ӱ� ��ǥ�� ���� ����, ź���� ���� ���̾���."));
		}
		else if (S == 2) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_3)));
			Conver(hwnd, g_hInst, NULL, TEXT("ź��. �η��� ���ο� ������ ��������� ������� ����� ���� ���� ������ �Ǵ��� ����Ϸ��ߴ�."));
		}
		else if (S == 3) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_3)));
			Conver(hwnd, g_hInst, NULL, TEXT("�׵��� ���� ���� ������ �η�. �ƴ�� �̺�. �׷��� ���縦 â���Ϸ� ������ ���и� �ݺ��ߴ�."));
		}
		else if (S == 4) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_4)));
			Conver(hwnd, g_hInst, NULL, TEXT("�׷��� ���� �� õ�簡 ���ο� ����� �����ߴ�."));
		}
		else if (S == 5) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_4)));
			Conver(hwnd, g_hInst, NULL, TEXT("�ƴ�� �̺�κ��� �Ļ��� �ΰ�. �� �ΰ��� �����Ͽ�, ���ο� ź���� �Ǹ����� ���ڰ�."));
		}
		else if (S == 6) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_5)));
			Conver(hwnd, g_hInst, NULL, TEXT("���� �����ڵ��� �׵��� ���ƴ� �հ������ϰ� �׵鿡 ���� �̾߱⸦ ������ �ʾҴ�, ���� ���� ��Ȥ�� �����ڵ��� �׿� �Բ� ���� �������� �������."));
		}
		else if (S == 7) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_6)));
			Conver(hwnd, g_hInst, NULL, TEXT("�������� ���ο� ������ �� ���̶� �Ͼ� �ǽ�ġ ���� �׵���, ���� ���İ���."));
		}
		else if (S == 8) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_6)));
			Conver(hwnd, g_hInst, NULL, TEXT("������ �������� ������ ���� ����̵��� �ƴ�� �̺꿡 ������ �Ǵ��� �׵��� ������ ����̵��� ������ �����߰� �� ��Ȥ�� ������ ���� �巯����."));
		}
		else if (S == 9) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_7)));
			Conver(hwnd, g_hInst, NULL, TEXT("������ ������� �װ����� ã�ư� �η��� �׷��� �˸� ���ߴٴ� ����� �������� �ʱ� ���� ������ ���� ��� �͵��� ���� �׿���."));
		}
		else if (S == 10) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_8)));
			Conver(hwnd, g_hInst, NULL, TEXT("�� ���忡�� ��Ƴ��� �� �־��� ������� ����̵���̾���, �ű⼭ ��Ƴ��� ������ ���̵��� �ڽ��� �θ�, �ڽ��� �̸����� ��ä ��ư���."));
		}
		else if (S == 11) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_9)));
			Conver(hwnd, g_hInst, NULL, TEXT("�׷� �߾��� ������ ���� ����. Re:First-Project ��� ��Ҹ��� �����"));
		}
		else if (S == 12) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_10)));
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("�� ���� �̰��� �� �Ⱦ��µ�, �����ͼ� ���� ���� �׸��⵵ �ϳ�."));
		}
		else if (S == 13) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_10)));
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("��¥ �� �� �ٽ� �� ���ƿ� �� �˾Ҵµ��� �̰��� �� ������ ���� ����� �������� ���� �ִٴϱ. �� �� ������?"));
		}
		else if (S == 14) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_10)));
			Conver(hwnd, g_hInst, NULL, TEXT("��¥ ������ �� ���� �ƴϾ�����? ���� �����Ѵ�."));
		}
		else if (S == 15) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_10)));
			Conver(hwnd, g_hInst, NULL, TEXT("�� ���� �̰��� ���� � ���� �Ͼ��, �ϳ��� �������� ���ߴ�."));
		}
		else if (S == 16) {
			DrawBitmap(hdc, 0, 0, LoadBitmap(g_hInst, MAKEINTRESOURCE(P_11)));
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("�? ���� �� �ٽ� �ȿ���? ��? �ű� �ۿ� �ƹ��� �����? ���� �ȿ�����!!! �ȿ� ��� �����ٰ�!!!!"));
		}
	}
	else if (type == 'P1') {
		if (S == 17) {
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("���塦. �� �� ������� ���� �����ס�. ��ȭ�� ���ϴϱ�, �ϴ� ������ �Ű�� �صѱ�?"));
		}
		else if (S == 18) {
			Conver(hwnd, g_hInst, NULL, TEXT("���� �׷��� ���� �̰��� �����ִٴ� ���� �������� �˷ȴ�."));
		}
		else if (S == 19) {
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("������. ���Ϸ� �´ٰ� �����ϱ�, ������ ��������! �׷���. �̷� �� ���� Ž�����̸� ���� �غ��ڳ�! ��Ž�� �ż��� �����Ŵ�!"));
		}
		else if (S == 20) {
			Conver(hwnd, g_hInst, C_SIN_Conver, TEXT("�׷� �� ����. ������ �����غ���?"));
		}
	}
	SelectObject(hMemDC, OldBit);
	DeleteDC(hMemDC);
	ReleaseDC(hwnd, hdc);
}