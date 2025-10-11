#include <windows.h>
using namespace std;

#define BLOCK1 1
#define BLOCK2 2
#define BLOCK3 3
#define BLOCK4 4
#define BLOCK5 5
#define BLOCK6 6
#define BLOCK7 7
#define BLOCK8 8
#define BLOCK9 9

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp);
void AddControls (HWND);
void AddMenus (HWND);

HMENU hMenu;
HWND hButton1,hButton2,hButton3;
HWND hButton4,hButton5,hButton6;
HWND hButton7,hButton8,hButton9;
HWND hTurn;

bool isXturn = true;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,LPSTR args,int ncmdshow){
	WNDCLASSW wc = {0};
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;
	
 	if (!RegisterClassW(&wc))
	 	return -1;
	 	
	CreateWindowW(L"myWindowClass", L"tic tac toe",
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				100, 100 , 360, 430,
				NULL, NULL, hInst, NULL);
	
	MSG msg = {0};
	while (GetMessage(&msg,NULL,NULL,NULL)){
	 	TranslateMessage (&msg);
	 	DispatchMessage(&msg);
	}
	return 0;
	
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp){
	switch(msg){
 	case WM_CREATE:
 		AddMenus(hWnd);
	 	AddControls(hWnd);
	 	break;
 	case WM_DESTROY:
 		PostQuitMessage(0);
 		break;
 	case WM_COMMAND:
 	 	switch(wp){
 			case BLOCK1:
 				SetWindowTextW(hButton1, isXturn ? L"X" : L"O");
 				isXturn = !isXturn;
 				SetWindowTextW(hTurn, isXturn ? L"Turn : X" : L"Turn : O");
 				break;
 				
 			case BLOCK2:
 				SetWindowTextW(hButton2, isXturn ? L"X" : L"O");
 				isXturn = !isXturn;
 				SetWindowTextW(hTurn, isXturn ? L"Turn : X" : L"Turn : O");
 				break;
 				
 			case BLOCK3:
 				SetWindowTextW(hButton3, isXturn ? L"X" : L"O");
 				isXturn = !isXturn;
 				SetWindowTextW(hTurn, isXturn ? L"Turn : X" : L"Turn : O");
 				break;

 			case BLOCK4:
 				SetWindowTextW(hButton4, isXturn ? L"X" : L"O");
 				isXturn = !isXturn;
 				SetWindowTextW(hTurn, isXturn ? L"Turn : X" : L"Turn : O");
 				break;
 				
 			case BLOCK5:
 				SetWindowTextW(hButton5, isXturn ? L"X" : L"O");
 				isXturn = !isXturn;
 				SetWindowTextW(hTurn, isXturn ? L"Turn : X" : L"Turn : O");
 				break;

 			case BLOCK6:
 				SetWindowTextW(hButton6, isXturn ? L"X" : L"O");
 				isXturn = !isXturn;
 				SetWindowTextW(hTurn, isXturn ? L"Turn : X" : L"Turn : O");
 				break;
 				
 			case BLOCK7:
 				SetWindowTextW(hButton7, isXturn ? L"X" : L"O");
 				isXturn = !isXturn;
 				SetWindowTextW(hTurn, isXturn ? L"Turn : X" : L"Turn : O");
 				break;

 			case BLOCK8:
 				SetWindowTextW(hButton8, isXturn ? L"X" : L"O");
 				isXturn = !isXturn;
 				SetWindowTextW(hTurn, isXturn ? L"Turn : X" : L"Turn : O");
 				break;

 			case BLOCK9:
 				SetWindowTextW(hButton9, isXturn ? L"X" : L"O");
 				isXturn = !isXturn;
 				SetWindowTextW(hTurn, isXturn ? L"Turn : X" : L"Turn : O");
 				break;
	 	}
 	 	break;
 	default:
	 	return DefWindowProcW(hWnd,msg,wp,lp);
	}
	return 0;
}

void AddMenus (HWND hWnd){
	hMenu = CreateMenu();
	SetMenu(hWnd,hMenu);
}

void AddControls(HWND hWnd)
{
	hTurn = CreateWindowW(L"Edit", L"Turn : X",
						WS_VISIBLE | WS_CHILD | SS_CENTER,
						120, 17, 100, 25,
						hWnd,NULL,NULL,NULL);
	
	hButton1 = CreateWindowW(L"Button", L"",
						WS_VISIBLE | WS_CHILD,
						10, 50, 100, 100,
						hWnd,(HMENU)BLOCK1,NULL,NULL);
	
	hButton2 = CreateWindowW(L"Button", L"",
						WS_VISIBLE | WS_CHILD,
						120, 50, 100, 100,
						hWnd,(HMENU)BLOCK2,NULL,NULL);
	
	hButton3 = CreateWindowW(L"Button", L"",
						WS_VISIBLE | WS_CHILD,
						230, 50, 100, 100,
						hWnd,(HMENU)BLOCK3,NULL,NULL);
	
	hButton4 = CreateWindowW(L"Button", L"",
						WS_VISIBLE | WS_CHILD,
						10, 160, 100, 100,
						hWnd,(HMENU)BLOCK4,NULL,NULL);
	
	hButton5 = CreateWindowW(L"Button", L"",
						WS_VISIBLE | WS_CHILD,
						120, 160, 100, 100,
						hWnd,(HMENU)BLOCK5,NULL,NULL);
	
	hButton6 = CreateWindowW(L"Button", L"",
						WS_VISIBLE | WS_CHILD,
						230, 160, 100, 100,
						hWnd,(HMENU)BLOCK6,NULL,NULL);
	
	hButton7 = CreateWindowW(L"Button", L"",
						WS_VISIBLE | WS_CHILD,
						10, 270, 100, 100,
						hWnd,(HMENU)BLOCK7,NULL,NULL);
	
	hButton8 = CreateWindowW(L"Button", L"",
						WS_VISIBLE | WS_CHILD,
						120, 270, 100, 100,
						hWnd,(HMENU)BLOCK8,NULL,NULL);
	
	hButton9 = CreateWindowW(L"Button", L"",
						WS_VISIBLE | WS_CHILD,
						230, 270, 100, 100,
						hWnd,(HMENU)BLOCK9,NULL,NULL);
}


