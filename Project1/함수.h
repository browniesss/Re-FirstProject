//�Լ���
#include <windows.h>
#include <memory.h>

#define invenSize 5

#define INVEN_X 20 //��Ʈ�������ġ��ũ�λ��
#define INVEN_Y 700

//�÷��̾� �Ǵ� �����
typedef struct ENTITY {
	RECT rect;
	POINT point;
	int type, sizex = 20, sizey = 20, inven[invenSize];
	BOOL show = FALSE;
	int mapIndex = 0;
	int speed;
	int direct, pasDirect;
	int CrashDir;
	int ChatIndex;
	int ChatPage;
	HBITMAP E_B;
}ENTITY;

//�� ���� �̿� ��ȣ�ۿ��� �ʿ��� �͵�
typedef struct OBJECTIVE {
	RECT rect;
	POINT point;
	int type, sizex = 20, sizey = 20;
	BOOL select = FALSE;
	bool show;
	int speed, ObjectType;
	HBITMAP O_B = NULL;
	int motionIndex;
	int animIndex;
	int soundIndex;
}OBJECTIVE;

//ȭ�� ��� ����
void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit);
void TransBlt(HDC hdc, int x, int y, HBITMAP hBit, COLORREF color);
void StretchDraw(HDC hdc, int x, int y, HBITMAP hBit, int sizex, int sizey);

//
OBJECTIVE* OnTimer(ENTITY* player, RECT rt, RECT pRT, HWND hwnd, HDC hMemDC, HBITMAP OldBit, HBITMAP hBit,
	int InteractionCheck, int pi, int mi, int bi, int Keynum, int invensel
, BOOL* draw_Baek, int* Party_part,  HINSTANCE g_hInst);
//

void DrawAnim(HDC hdc, int x, int y, int divideX, int divideY, int xstart, int ystart, HBITMAP hBit, COLORREF color);
int AnimIndex(int i, int size); // �ִϸ��̼� �Ѱ��ִ� �Լ�
void Map(HINSTANCE g_hInst, ENTITY* player);
void movie(HWND hwnd, HINSTANCE g_hInst, int type, int S);
void Conver(HWND hwnd, HINSTANCE g_hInst, int type, LPCWSTR text);

//��ȣ�ۿ� ����
BOOL InRect(RECT prt, OBJECTIVE* ob);
int Obstacle(RECT rt, int* crash, int dir, int* crash_type, BOOL *crash_Baek);
void Updata(ENTITY* entity, int dx, int dy, bool show, int speed, int Direct,int pasDirect, HBITMAP newbit);
void Updata(OBJECTIVE* object, int dx, int dy, bool show, int speed, HBITMAP newbit);
OBJECTIVE* ObjectAnim(RECT rt);

//
void Animation(OBJECTIVE* ObjectAnim, bool* InteractionCheck, HWND hWndMain, ENTITY* player, HINSTANCE g_hInst, BOOL* draw_Baek);
//

//�κ��丮 ����
void DrawInventory(HDC hMemDC, OBJECTIVE* ObjectBitmap[], ENTITY* player, int invensel); //�κ��丮�� ���� ������ ���
BOOL AddItem(ENTITY* player, int type, int* pl_inven_index);
void DeleteItem(ENTITY* player);
void SelectItem(ENTITY* player, int key);
void InvenC(HINSTANCE g_hInst);
int UseItem(ENTITY* player);

//������Ʈ,��ƼƼ
#define W_C 4
#define OB_C 10
#define TB_C 5
#define CL_C 2
#define S_C 8
#define G_C 7
#define H_C 2
#define D_C 5

ENTITY* CreateEntity(int type, int sizeX, int sizeY, int x, int y, bool show, int speed, int ChatIndex,	int ChatPage);
OBJECTIVE* CreateObject(int type, int sizeX, int sizeY, int cutX, int cutY,int cutTY, int x, int y, bool show, int speed, int ObjectType, int animIndex, int motionIndex, int soundIndex, HBITMAP O_B);

//��Ƽâ
BOOL Road_PartyWindows(HINSTANCE g_hInst, HWND hwnd,
	int* Party_sel, int* Party_next, int* Party_part);

#define Party_X 175
#define Party_Y 600

//��
#define Char_B_X 200
#define Char_B_Y 50

#define TEXT_B_X 450
#define TEXT_B_Y 750
//

//��
#define Char_S_X 200
#define Char_S_Y 160

#define TEXT_S_X 700
#define TEXT_S_Y 750
//

//����ȭ��
void startBitmap(HINSTANCE g_hInst, HWND hwnd, int start, int sel);
void start_transblt(HDC hdc, int x, int y,
	HBITMAP hBit, COLORREF color, int X_sel);
//