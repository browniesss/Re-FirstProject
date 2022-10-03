#pragma comment (lib,"Msimg32.lib")
#pragma comment (lib, "winmm.lib")
#include "resource.h"
#include "함수.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	//CALLBACK 매크로
HINSTANCE g_hInst;										//인스턴스 핸들
LPCTSTR lpszClass = TEXT("Re:First Project");				//제목 표시줄에 표시되는 내용
HWND hWndMain, hwndm;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam,
	int nCmdShow)
{
	HWND hWnd;											//윈도우 핸들 선언
	MSG Message;										//메세지 구조체 변수 선언
	WNDCLASS WndClass;									//Windows Class 구조체 변수 선언
	g_hInst = hInstance;								//hInstance값을 외부에서도 사용할 수 있도록 전역변수에 값을 저장

	WndClass.cbClsExtra = 0;							//예약 영역. 지금은 사용X
	WndClass.cbWndExtra = 0;							//예약 영역
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 윈도우의 배경 색상을 지정
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		//윈도우의 마우스포인터 모양을 지정
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//윈도우의 커서 아이콘 모양 지정
	WndClass.hInstance = hInstance;						//윈도우 클래스를 등록하는 프로그램 번호
	WndClass.lpfnWndProc = WndProc;						//윈도우 메세지 처리 함수 지정
	WndClass.lpszClassName = lpszClass;					//윈도우 클래스의 이름 지정
	WndClass.lpszMenuName = NULL;						//메뉴 지정
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;			//윈도우의 스타일을 정의

	RegisterClass(&WndClass);							//WNDCLASS 구조체의 번지를 전달


	hWnd = CreateWindow(lpszClass, lpszClass,			//윈도우를 생성
		WS_OVERLAPPEDWINDOW,/* CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT*/
		 0,0,1920,1080, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd;
	//메세지 루프를 실행
	while (GetMessage(&Message, NULL, 0, 0)) {			//Queue에 있는 메세지를 읽어들인다
		TranslateMessage(&Message);						//키보드 입력 메세지를 가공하여 프로그램에서 쉽게 
														//  사용할 수 있도록
		DispatchMessage(&Message);						//메세지를 윈도우의 메세지 처리 함수 WndProc로 전달
	}
	return (int)Message.wParam;							//탈출 코드. 프로그램 종료
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

	//키다운에서 값을 받아야함
	static int invensel = 0; //0~2 q~w키 
	static int Keynum = 0; //0~2
	static int inven_index = 0;
	static int crash_item = 0; //충돌한 아이템이 없는 상태
	static int EX_index = 2;
	//

	//파티창선택변수
	static int Party_sel = 0;
	//
	static int Party_next = 1;
	static int Party_part = 1;
	static int Start_Timer1 = 0;

	//

	//start_메뉴
	static BOOL start_bool = true;
	static int start = -1; //1이 시작
	static int sel = 0; //0:시작하기, 1:이어하기 2:종료
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


		if (Party_sel == 3) //partychatwindows//3이 되는 순간 타이머1이 켜진다.
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

			//인벤토리
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

			//시작전 메뉴
			if (start == -1)
			{
				if (sel == 0) //시작선택시 나레이션 시작
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
			//시작전 메뉴
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
				AddItem(player, crash_item, &inven_index); //충돌부근에 갈 경우 crash_item에 충돌한 item_type가 들어간다. //충돌부근이 아닐 경우 0값이 들어간다.

				if (InteractionCheck == false)
					InteractionCheck = true;
				else if (InteractionCheck == true)
					InteractionCheck = false;
				//파티대화 시작은 스페이스바
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

			//파티선택창
		case VK_F1:

			if (crash_Baek) //draw_Baek까지 넣으면 충돌하고 깨운다음에 대화를 이어갈 수 있다.
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

		//시작화면
		startBitmap(g_hInst, hWnd, start, sel);
		//
		if (Party_sel == 1) //일단1
		{
			KillTimer(hWnd, 1); //화면멈추고
			if (!Road_PartyWindows(g_hInst, hWndMain, &Party_sel, &Party_next, &Party_part))
			{
				SetTimer(hWnd, 1, 10, NULL); //시나리오가 다 끝나면 타이머가 시작되도록
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