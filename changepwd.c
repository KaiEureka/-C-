#ifndef CHANGEPWD
#define CHANGEPWD

//ѧ��������
LRESULT CALLBACK ChangeStuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
		char username[100], password[100], password1[100];
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case ID_BUTTON_LOGIN:
                
                GetWindowTextA(g_hEditUsername1, username, sizeof(username));
                GetWindowTextA(g_hEditPassword0, password, sizeof(password));
                GetWindowTextA(g_hEditPassword1, password1, sizeof(password1));
                if(strcmp(username,stuuser->stu.pwd)==0)
                {
                    if(strcmp(username,password)!=0)
                    {
                    	if(strlen(password)==0)
	                	{
	                		MessageBox(NULL,TEXT("������������"),TEXT("��ʾ"),MB_OK);
	                		return 0;
						}
                        if(strcmp(password1,password)==0)
                        {
                        MessageBox(NULL,TEXT("�����޸ĳɹ�"),TEXT("��ʾ"),MB_OK);
                        changepwdofstu(stuuser,password);
                        FILE *fp=fopen(ORDER,"a+");
                        fprintf(fp,"changepwdofstu;%s;%s;\n",stuuser->stu.name,password);
                        fclose(fp);
                        }
                        else
                            MessageBox(NULL,TEXT("�������������벻һ��"),TEXT("����"),MB_ICONERROR);
                    }
                    else
                        MessageBox(NULL,TEXT("�����벻����ԭ����һ��"),TEXT("����"),MB_ICONERROR);
                }
                else
                    MessageBox(NULL,TEXT("ԭ�����������"),TEXT("����"),MB_ICONERROR);
                break;

            case ID_BUTTON_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("ChangeStuWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_CREATE:
        	CreateWindow(TEXT("STATIC"), TEXT("ԭ���룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 70, 80, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("�����룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 115, 80, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("ȷ�����룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 160, 80, 20,hwnd, NULL, NULL, NULL);

            g_hEditUsername1 = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                150, 70, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

            g_hEditPassword0 = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
                150, 115, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

            g_hEditPassword1 = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
                150, 160, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

            CreateWindow(TEXT("BUTTON"), TEXT("�޸�"),WS_VISIBLE | WS_CHILD,
                130, 205, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

            break;

        case WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("ChangeStuWin", GetModuleHandle(NULL));
            }
            else   
                return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//��ʦ������
LRESULT CALLBACK ChangeTeaProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
	{ 
		char username[100], password[100], password1[100];
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case ID_BUTTON_LOGIN:
               
                GetWindowTextA(g_hEditUsername1, username, sizeof(username));
                GetWindowTextA(g_hEditPassword0, password, sizeof(password));
                GetWindowTextA(g_hEditPassword1, password1, sizeof(password1));
                if(strcmp(username,teauser->tea.pwd)==0)
                {
                	if(strlen(password)==0)
                	{
                		MessageBox(NULL,TEXT("������������"),TEXT("��ʾ"),MB_OK);
                		return 0;
					}
                    if(strcmp(username,password)!=0)
                    {
                        if(strcmp(password1,password)==0)
                        {
                        MessageBox(NULL,TEXT("�����޸ĳɹ�"),TEXT("��ʾ"),MB_OK);
                        changepwdoftea(teauser,password);
                        FILE *fp=fopen(ORDER,"a+");
                        fprintf(fp,"changepwdoftea;%s;%s;\n",teauser->tea.account,password);
                        fclose(fp);
                        }
                        else
                            MessageBox(NULL,TEXT("�������������벻һ��"),TEXT("����"),MB_ICONERROR);
                    }
                    else
                        MessageBox(NULL,TEXT("�����벻����ԭ����һ��"),TEXT("����"),MB_ICONERROR);
                }
                else
                    MessageBox(NULL,TEXT("ԭ�����������"),TEXT("����"),MB_ICONERROR);
                break;

            case ID_BUTTON_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("ChangeTeaWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_CREATE:
            CreateWindow(TEXT("STATIC"), TEXT("ԭ���룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 70, 80, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("�����룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 115, 80, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("ȷ�����룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 160, 80, 20,hwnd, NULL, NULL, NULL);

            g_hEditUsername1 = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                150, 70, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

            g_hEditPassword0 = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
                150, 115, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

            g_hEditPassword1 = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
                150, 160, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

            CreateWindow(TEXT("BUTTON"), TEXT("�޸�"),WS_VISIBLE | WS_CHILD,
                130, 205, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

            break;

        case WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("ChangeTeaWin", GetModuleHandle(NULL));
            }
            else   
                return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//����Ա������
LRESULT CALLBACK ChangeAdmProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
	{
		char username[100], password[100], password1[100];
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case ID_BUTTON_LOGIN:
                
                GetWindowTextA(g_hEditUsername1, username, sizeof(username));
                GetWindowTextA(g_hEditPassword0, password, sizeof(password));
                GetWindowTextA(g_hEditPassword1, password1, sizeof(password1));
                if(strcmp(username,rootuser->rt.pwd)==0)
                {
                    if(strcmp(username,password)!=0)
                    {
                    	if(strlen(password)==0)
	                	{
	                		MessageBox(NULL,TEXT("������������"),TEXT("��ʾ"),MB_OK);
	                		return 0;
						}
                        if(strcmp(password1,password)==0)
                        {
                        MessageBox(NULL,TEXT("�����޸ĳɹ�"),TEXT("��ʾ"),MB_OK);
                        changepwdofroot(rootuser,password);
                        FILE *fp=fopen(ORDER,"a+");
                        fprintf(fp,"changepwdofroot;%s;%s;\n",rootuser->rt.account,password);
                        fclose(fp);
                        }
                        else
                            MessageBox(NULL,TEXT("�������������벻һ��"),TEXT("����"),MB_ICONERROR);
                    }
                    else
                        MessageBox(NULL,TEXT("�����벻����ԭ����һ��"),TEXT("����"),MB_ICONERROR);
                }
                else
                    MessageBox(NULL,TEXT("ԭ�����������"),TEXT("����"),MB_ICONERROR);
                break;

            case ID_BUTTON_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("ChangeAdmWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_CREATE:
            CreateWindow(TEXT("STATIC"), TEXT("ԭ���룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 70, 80, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("�����룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 115, 80, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("ȷ�����룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 160, 80, 20,hwnd, NULL, NULL, NULL);

            g_hEditUsername1 = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                150, 70, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

            g_hEditPassword0 = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
                150, 115, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

            g_hEditPassword1 = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
                150, 160, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

            CreateWindow(TEXT("BUTTON"), TEXT("�޸�"),WS_VISIBLE | WS_CHILD,
                130, 205, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

            break;

        case WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("ChangeAdmWin", GetModuleHandle(NULL));
            }
            else   
                return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void ChangeStuWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = ChangeStuProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"ChangeStuWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("ChangeStuWin"), TEXT("ѧ��"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 400, 400, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 270, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void ChangeTeaWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = ChangeTeaProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"ChangeTeaWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("ChangeTeaWin"), TEXT("��ʦ"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 400, 400, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("��ʦ���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 270, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void ChangeAdmWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = ChangeAdmProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"ChangeAdmWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("ChangeAdmWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 400, 400, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 270, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void changepwdofstu(stunode* stuuser,char* astr)
{
	if(stuuser!=NULL)
	{
		strcpy(stuuser->stu.pwd,astr);
	}
}

void changepwdoftea(teanode* teauser,char* astr)
{
	if(teauser!=NULL)
	{
		strcpy(teauser->tea.pwd,astr);
	}
}

void changepwdofroot(rootnode* rootuser,char* astr)
{
	if(rootuser!=NULL)
	{
		strcpy(rootuser->rt.pwd,astr);
	}
}

#endif
