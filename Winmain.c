#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "project.h"

char ORDER[100]="./order.txt";
char EA[100]="./ea.txt";
char SCORE[100]="./scorelist.txt";
char CLS[100]="./clslist.txt";
char ROOT[100]="./rootlist.txt";
char TEA[100]="./teacherlist.txt";
char STU[100]="./stulist.txt";

HWND g_hComboBoxLoginType;
HWND g_hComboBoxpaiming0Type;
HWND g_hComboBoxpaiming1Type;
HWND g_hComboBoxpaiming2Type;
HWND g_hComboBoxpaiming3Type;
HWND g_hEditUsername;
HWND g_hEditUsername1;
HWND g_hEditPassword;
HWND g_hEditPassword0;
HWND g_hEditPassword1;
HWND g_hEditUseryear;
HWND g_hEditUsermajor;
HWND g_hEditUserclass;
HWND g_hEditUserid;
HWND g_hEditUserid1;
HWND g_hEditUsergender;
HWND g_hEditUserpwd;
HWND g_hEditUserpwd1;
HWND g_hEditUserhome;
HWND g_hEditUserypwd;
HWND g_hEditStuname;
HWND g_hEditevent;
HWND g_hEditpoint;
HWND g_hComboBoxPunishType;
HWND g_hEditCourse;
HWND g_hEditGrade;
TCHAR szBuffer[128];
size_t iTarget;
HDC hdc;
PAINTSTRUCT ps;
TEXTMETRIC tm;

char majornow[100],Bclass[100],str1,ch,str[10000];
int ordern,tos=1,req_1,req_2,Ayear,Aclass,cntx,cnty,flag;
int aid,Tstu,i,j,emptynum=0,flaginson2=0;//account id; teacher or student
stunode *stulih,*stulit,*stunowinall,*stuuser,*astu;
cosnode *coslih,*coslit,*cosnowinall;
clsnode *clslih,*clslit,*clstobe;
teanode *tealih,*tealit,*teauser;
rootnode *rootlih,*rootlit,*rootuser;
apt *aptlih=NULL,*Q,*P;
nstunode *nstulihh,*nstuinall;
static int cxChar,cxCaps,cyChar,cxCliect,cyClient,iVscrollPos;

//������
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
    switch(msg) {
        case WM_COMMAND:
            switch(LOWORD(wParam)) {
                case ID_BUTTON_LOGIN:
                    {
                        // ��ȡѡ��ĵ�¼����
                        int loginTypeIndex = SendMessage(g_hComboBoxLoginType, CB_GETCURSEL, 0, 0);

                        char username[100], password[100];
                        GetWindowTextA(g_hEditUsername, username, sizeof(username));
                        GetWindowTextA(g_hEditPassword, password, sizeof(password));

                        // ����ѡ��ĵ�¼���ͽ��в�ͬ�ĵ�¼��֤
                        if(loginTypeIndex==-1){
                        	MessageBox(hwnd,TEXT("��ѡ���¼���"), TEXT("��ʾ"), MB_OK);
                        	return 0;
						}
                        switch (loginTypeIndex) {
                            case 0: // ѧ��
                                stuuser=searchstuid(username);
                                if (stuuser!=NULL&&strcmp(password,stuuser->stu.pwd)==0) {
                                    MessageBoxA(hwnd,TEXT("��¼�ɹ���"), TEXT("��ʾ"), MB_OK);
                                    tos=1;StudentWindow();
                                } else {
                                    MessageBoxA(hwnd, TEXT("�˺Ż�����������������룡"), TEXT("����"), MB_OK | MB_ICONERROR);
                                }
                                break;
                            case 1: // ��ʦ
                                teauser=searchtea(username);
                                if (teauser!=NULL&&strcmp(password,teauser->tea.pwd)==0) {
                                    MessageBoxA(hwnd,TEXT("��¼�ɹ���"), TEXT("��ʾ"), MB_OK);
                                    tos=0;TeacherWindow();
                                } else {
                                    MessageBoxA(hwnd, TEXT("�˺Ż�����������������룡"), TEXT("����"), MB_OK | MB_ICONERROR);
                                }
                                break;
                            case 2: // ����Ա
                                rootuser=searchroot(username);
                                if(rootuser!=NULL&&strcmp(password,rootuser->rt.pwd)==0) {
                                    MessageBoxA(hwnd,TEXT("��¼�ɹ���"), TEXT("��ʾ"), MB_OK);
                                    tos=1;AdminWindow();
                                } else {
                                    MessageBoxA(hwnd, TEXT("�˺Ż�����������������룡"), TEXT("����"), MB_OK | MB_ICONERROR);
                                }
                                break;
                        }
                    }
                    break;
            }
            break;

        case WM_CLOSE: //�ر�ȷ��
        if(MessageBox(NULL,TEXT("�Ƿ�رոó���"),TEXT("��ȷ��"),MB_YESNO)==IDYES)
                DestroyWindow(hwnd);
        else   
                return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
    WNDCLASS wc = {0};
    HWND hwnd;
    MSG Msg;

    // ע�ᴰ����
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = TEXT("WindowClass");
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, TEXT("����ע��ʧ�ܣ�"), TEXT("����"), MB_ICONERROR);
        return 0;
    }

    // ��������
    Initialization();
    hwnd = CreateWindowEx(
        0,
        TEXT("WindowClass"),
        TEXT("��¼����"),
        WS_OVERLAPPEDWINDOW,
        650, 300, 450, 300,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, TEXT("���ڴ���ʧ�ܣ�"), TEXT("����"), MB_ICONERROR);
        return 0;
    }

    // ������ӭ����
    CreateWindow(
        TEXT("STATIC"), TEXT("��ӭʹ�ý������ϵͳ����ѡ����ݣ��������˺������¼��"),
        WS_VISIBLE | WS_CHILD | SS_CENTER,
        0, 30, 450, 30,
        hwnd, NULL, NULL, NULL);
    CreateWindow(
        TEXT("STATIC"), TEXT("���ͣ�"),
        WS_VISIBLE | WS_CHILD | SS_LEFT,
        50, 75, 50, 20,
        hwnd, NULL, NULL, NULL);
    CreateWindow(
        TEXT("STATIC"), TEXT("�˺ţ�"),
        WS_VISIBLE | WS_CHILD | SS_LEFT,
        50, 120, 50, 20,
        hwnd, NULL, NULL, NULL);
    CreateWindow(
        TEXT("STATIC"), TEXT("���룺"),
        WS_VISIBLE | WS_CHILD | SS_LEFT,
        50, 165, 50, 20,
        hwnd, NULL, NULL, NULL);

    // ������¼��ʽѡ��������
    g_hComboBoxLoginType = CreateWindow(
        TEXT("COMBOBOX"), TEXT(""),
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        130, 75, 200, 200,
        hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);

    SendMessage(g_hComboBoxLoginType, CB_ADDSTRING, 0, (LPARAM)TEXT("ѧ��"));
    SendMessage(g_hComboBoxLoginType, CB_ADDSTRING, 0, (LPARAM)TEXT("��ʦ"));
    SendMessage(g_hComboBoxLoginType, CB_ADDSTRING, 0, (LPARAM)TEXT("����Ա"));

    // �����˺������
    g_hEditUsername = CreateWindow(
        TEXT("EDIT"), TEXT(""),
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        130, 120, 200, 20,
        hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

    // �������������
    g_hEditPassword = CreateWindow(
        TEXT("EDIT"), TEXT(""),
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
        130, 165, 200, 20,
        hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

    // ������¼��ť
    CreateWindow(
        TEXT("BUTTON"), TEXT("��¼"),
        WS_VISIBLE | WS_CHILD,
        150, 200, 150, 45,
        hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

    // ��ʾ����
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // ��Ϣѭ��
    while (GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}
