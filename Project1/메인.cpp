#pragma comment (lib,"Msimg32.lib")
#pragma comment (lib, "winmm.lib")
#include "resource.h"
#include "�Լ�.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	//CALLBACK ��ũ��
HINSTANCE g_hInst;										//�ν��Ͻ� �ڵ�
LPCTSTR lpszClass = TEXT("Re:First Project");				//���� ǥ���ٿ� ǥ�õǴ� ����
HWND hWndMain, hwndm;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam,
	int nCmdShow)
{
	HWND hWnd;											//������ �ڵ� ����
	MSG Message;										//�޼��� ����ü ���� ����
	WNDCLASS WndClass;									//Windows Class ����ü ���� ����
	g_hInst = hInstance;								//hInstance���� �ܺο����� ����� �� �ֵ��� ���������� ���� ����

	WndClass.cbClsExtra = 0;							//���� ����. ������ ���X
	WndClass.cbWndExtra = 0;							//���� ����
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �������� ��� ������ ����
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		//�������� ���콺������ ����� ����
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//�������� Ŀ�� ������ ��� ����
	WndClass.hInstance = hInstance;						//������ Ŭ������ ����ϴ� ���α׷� ��ȣ
	WndClass.lpfnWndProc = WndProc;						//������ �޼��� ó�� �Լ� ����
	WndClass.lpszClassName = lpszClass;					//������ Ŭ������ �̸� ����
	WndClass.lpszMenuName = NULL;						//�޴� ����
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;			//�������� ��Ÿ���� ����

	RegisterClass(&WndClass);							//WNDCLASS ����ü�� ������ ����


	hWnd = CreateWindow(lpszClass, lpszClass,			//�����츦 ����
		WS_OVERLAPPEDWINDOW,/* CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT*/
		 0,0,1920,1080, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd;
	//�޼��� ������ ����
	while (GetMessage(&Message, NULL, 0, 0)) {			//Queue�� �ִ� �޼����� �о���δ�
		TranslateMessage(&Message);						//Ű���� �Է� �޼����� �����Ͽ� ���α׷����� ���� 
														//  ����� �� �ֵ���
		DispatchMessage(&Message);						//�޼����� �������� �޼��� ó�� �Լ� WndProc�� ����
	}
	return (int)Message.wParam;							//Ż�� �ڵ�. ���α׷� ����
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static HBITMAP OldBit, hBit;
	static HDC hMemDC;
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rt, pRT;
	static ENTITY* player;
	static int Crash = 0;

	static bool InteractionCheck = FALSE;
	static bool* InterPointer;
	InterPointer = &InteractionCheck;
	static int pi = 0, mi = 0, bi = 0;
	static OBJECTIVE* ObjectAnim;

	static int S = 0, P1 = 0;

	//Ű�ٿ�� ���� �޾ƾ���
	static int invensel = 0; //0~2 q~wŰ 
	static int Keynum = 0; //0~2
	static int inven_index = 0;
	static int crash_item = 0; //�浹�� �������� ���� ����
	static int EX_index = 2;
	//

	//��Ƽâ���ú���
	static int Party_sel = 0;
	//
	static int Party_next = 1;
	static int Party_part = 1;
	static int Start_Timer1 = 0;

	//

	//start_�޴�
	static BOOL start_bool = true;
	static int start = -1; //1�� ����
	static int sel = 0; //0:�����ϱ�, 1:�̾��ϱ� 2:����
	//

	static int a = 0;


	//
	static BOOL draw_Baek = false;
	static BOOL crash_Baek = false;
	//


	switch (iMessage)
	{
	case WM_CREATE:
		PlaySound(MAKEINTRESOURCE(W_BGM), g_hInst, SND_RESOURCE | SND_ASYNC);
		GetClientRect(hWnd, &rt);
		SetTimer(hWnd, 4, 10, NULL);
		return 0;
	case WM_TIMER:


		if (Party_sel == 3) //partychatwindows//3�� �Ǵ� ���� Ÿ�̸�1�� ������.
		{
			SetTimer(hWnd, 1, 10, NULL);
			Party_sel = 0;
		}


		switch (wParam)
		{
		case 1:
			player->CrashDir = Obstacle(pRT, &Crash, player->direct, &crash_item, &crash_Baek);

			ObjectAnim = OnTimer(player, rt, pRT, hWndMain, hMemDC, 
				OldBit, hBit, InteractionCheck, pi, mi,bi, Keynum, invensel
				, &draw_Baek, &Party_part,g_hInst);

			if (player->show == true)
			{
				if (GetKeyState(VK_LEFT) & 0x8000)
				{
					player->direct = 2;
					SetRect(&pRT, player->point.x + 50, player->point.y + 60, player->point.x + player->sizex - 50, player->point.y + player->sizey);
					if (!(Crash == 1 && player->CrashDir == 2)) {
						player->point.x -= player->speed;
					}
				}
				if (GetKeyState(VK_RIGHT) & 0x8000)
				{
					player->direct = 1;
					SetRect(&pRT, player->point.x + 50, player->point.y + 60, player->point.x + player->sizex - 50, player->point.y + player->sizey);
					if (!(Crash == 1 && player->CrashDir == 1)) {
						player->point.x += player->speed;
					}
				}
				if (GetKeyState(VK_UP) & 0x8000)
				{
					player->direct = 3;
					SetRect(&pRT, player->point.x + 50, player->point.y + 60, player->point.x + player->sizex - 50, player->point.y + player->sizey);
					if (!(Crash == 1 && player->CrashDir == 3)) {
						player->point.y -= player->speed;
					}
				}
				if (GetKeyState(VK_DOWN) & 0x8000)
				{
					player->direct = 0;
					SetRect(&pRT, player->point.x + 50, player->point.y + 60, player->point.x + player->sizex - 50, player->point.y + player->sizey);
					if (!(Crash == 1 && player->CrashDir == 0)) {
						player->point.y += player->speed;
					}
				}
			}
			break;
		case 2:
			if (player->direct != -1)
				pi = AnimIndex(pi, 3);
			if (*InterPointer == true && Crash == 1) {
				Animation(ObjectAnim, InterPointer,hWndMain,player, g_hInst, &draw_Baek);
			}
			break;
		case 3:
			mi = AnimIndex(mi, 1);
			bi = AnimIndex(bi, 3);
			break;
		case 4:
			if (S > 11) {
				KillTimer(hWnd, 4);
			}
			break;
		}
		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 'Q':
			if (invensel == 0) //EX_Index_item
			{
				break;
			}
			invensel--;
			break;

		case 'E':
			if (invensel == 2)
			{
				break;
			}
			invensel++;
			break;

			//�κ��丮
		case '1':
			Keynum = 0;
			SelectItem(player, Keynum + invensel);
			break;
		case '2':
			Keynum = 1;
			SelectItem(player, Keynum + invensel);
			break;
		case '3':
			Keynum = 2;
			SelectItem(player, Keynum + invensel);
			break;
		case VK_RETURN:

			//������ �޴�
			if (start == -1)
			{
				if (sel == 0) //���ۼ��ý� �����̼� ����
				{
					start = 1;
					SetTimer(hWnd, 4, 300, NULL);
				}
				if (sel == 2)
				{
					PostQuitMessage(0);
				}
			}

			if (start != -1)
			{
				if (S < 17)
				{
					movie(hWndMain, g_hInst, 'S', S);
					S += 1;
					if (S == 17)
						PlaySound(MAKEINTRESOURCE(W_D_KNOCK), g_hInst, SND_RESOURCE | SND_ASYNC);
				}
				else
				{
					if (a == 0)
					{
						player = CreateEntity(Player, 175, 175, rt.right / 2, rt.bottom / 2, true, 5, 1,1);
						player->mapIndex = 1;
						InvenC(g_hInst);
						Map(g_hInst, player);
						hdc = GetDC(hWnd);

						hBit = CreateCompatibleBitmap(hdc, rt.right, rt.bottom);
						hMemDC = CreateCompatibleDC(hdc);
						OldBit = (HBITMAP)SelectObject(hMemDC, hBit);
						FillRect(hMemDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));
						SelectObject(hMemDC, OldBit);
						DeleteDC(hMemDC);
						ReleaseDC(hWnd, hdc);

						SetTimer(hWnd, 1, 10, NULL);
						SetTimer(hWnd, 2, 150, NULL);
						SetTimer(hWnd, 3, 300, NULL);
						a = 1;
						PlaySound(NULL, g_hInst, SND_ASYNC);

					}
					else
					{
						if (player->mapIndex > 0 && player->mapIndex < 3)
							player->mapIndex++;
						else if (player->mapIndex == 3)
							player->mapIndex = 1;
						Map(g_hInst, player);
					}
				}
			}

			break;
		case VK_UP:

			if (start == -1)
			{
				if (sel == 0)
				{
					break;
				}
				sel--;
			}
			break;
		case VK_DOWN:

			if (start == -1)
			{
				if (sel == 2)
				{
					break;
				}
				sel++;
			}
			break;
		case VK_SPACE:
			//������ �޴�
			if (start == -1)
			{
				if (sel == 0)
				{
					start = 1;
					SetTimer(hWnd, 4, 300, NULL);
				}
				if (sel == 2)
				{
					PostQuitMessage(0);
				}
			}

			if (start != -1)
			{
				AddItem(player, crash_item, &inven_index); //�浹�αٿ� �� ��� crash_item�� �浹�� item_type�� ����. //�浹�α��� �ƴ� ��� 0���� ����.

				if (InteractionCheck == false)
					InteractionCheck = true;
				else if (InteractionCheck == true)
					InteractionCheck = false;
				//��Ƽ��ȭ ������ �����̽���
				if (Party_sel != 0) //partychatwindows
				{
					Party_next++;
				}
				else
				{
					SetTimer(hWnd, 1, 10, NULL);
				}
				//
			}

			if (player->ChatPage == 1) {
				player->ChatIndex++;
				if (player->ChatIndex == 5)
					player->ChatPage = 2;
			}
			if (player->ChatPage == 3) {
				player->ChatIndex++;
				if (player->ChatIndex == 31)
					player->ChatPage = 4;
			}
			if (player->ChatPage == 5) {
				player->ChatIndex++;
				if (player->ChatIndex == 47)
					player->ChatPage = 6;
			}
			if (player->ChatPage == 7) {
				player->ChatIndex++;
			}
			break;

			//��Ƽ����â
		case VK_F1:

			if (crash_Baek) //draw_Baek���� ������ �浹�ϰ� ��������� ��ȭ�� �̾ �� �ִ�.
			{
				Party_sel = 1;
			}

			break;
		}
		return 0;
	case WM_KEYUP:
		switch (wParam) 
		{
		case VK_LEFT:
		case VK_RIGHT:
		case VK_UP:
		case VK_DOWN:
			if (start != -1) {
				player->pasDirect = player->direct;
				player->direct = -1;
				break;
			}
		}

		InvalidateRect(hWnd, NULL, false);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		DrawBitmap(hdc, 0, 0, hBit);

		//����ȭ��
		startBitmap(g_hInst, hWnd, start, sel);
		//
		if (Party_sel == 1) //�ϴ�1
		{
			KillTimer(hWnd, 1); //ȭ����߰�
			if (!Road_PartyWindows(g_hInst, hWndMain, &Party_sel, &Party_next, &Party_part))
			{
				SetTimer(hWnd, 1, 10, NULL); //�ó������� �� ������ Ÿ�̸Ӱ� ���۵ǵ���
			}
		}
		//
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}