#ifndef SHOWTOMULT
#define SHOWTOMULT

//ѧ��(��ʦ)��ʾ�Լ����пγ�
LRESULT CALLBACK StuClassProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    int NUMLINES=200;
    switch (msg)
    {
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case ID_BUTTON_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("StuClassWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_SIZE:
            cxCliect=LOWORD(lParam);
            cyClient=HIWORD(lParam);

        case WM_VSCROLL:
            if(LOWORD(wParam)==SB_LINEUP)
                    iVscrollPos -=1;
            if(LOWORD(wParam)==SB_LINEDOWN)
                    iVscrollPos +=1;
            if(LOWORD(wParam)==SB_PAGEUP)
                    iVscrollPos -= cyClient / cyChar;
            if(LOWORD(wParam)==SB_PAGEDOWN)
                    iVscrollPos += cyClient / cyChar;
            if(LOWORD(wParam)==SB_THUMBTRACK)
                    iVscrollPos = HIWORD(wParam);
            if(LOWORD(wParam)==SB_THUMBPOSITION)

            iVscrollPos=max(0,min(iVscrollPos,NUMLINES-1));
            if(iVscrollPos!=GetScrollPos(hwnd,SB_VERT))
            {
                    SetScrollPos(hwnd,SB_VERT,iVscrollPos,TRUE);
                    InvalidateRect(hwnd,NULL,TRUE);
                    UpdateWindow(hwnd);
            }
            return 0;

        case WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("StuClassWin", GetModuleHandle(NULL));
            }
            else   
                return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        case WM_CREATE:
            hdc=GetDC(hwnd);
            GetTextMetrics(hdc,&tm);
            cxChar=tm.tmAveCharWidth;
            cxCaps=(tm.tmPitchAndFamily&1?3:2)*cxChar/2;
            cyChar=tm.tmHeight+tm.tmExternalLeading;
            ReleaseDC(hwnd,hdc);

            SetScrollRange(hwnd,SB_VERT,0,NUMLINES-1,FALSE);
            SetScrollPos(hwnd,SB_VERT,0,TRUE);

            return 0;

        case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps); 
        showcls();
        cnty=0;
        EndPaint(hwnd, &ps);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//(ѧ������ʦ������Ա)��רҵ�ɼ�
LRESULT CALLBACK SearchGradeProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
    int i=0;
    int NUMLINES=100;
    if(msg==WM_COMMAND){
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            ordern=SendMessage(g_hComboBoxpaiming0Type, CB_GETCURSEL, 0, 0)+1;
            req_1=SendMessage(g_hComboBoxpaiming1Type, CB_GETCURSEL, 0, 0);
            req_2=SendMessage(g_hComboBoxpaiming2Type, CB_GETCURSEL, 0, 0)+1;

            char year[100],classnow[100];
            int p=0;
            GetWindowTextA(g_hEditUseryear, year, sizeof(year));
            GetWindowTextA(g_hEditUsermajor, majornow, sizeof(majornow));
            GetWindowTextA(g_hEditUserclass, classnow, sizeof(classnow));
            if(ordern==0)
            {
				MessageBox(NULL,TEXT("��ѡ����������"),TEXT("����"),MB_OK);
				return 0;
			}
			if(req_1==-1)
            {
				MessageBox(NULL,TEXT("��ѡ������˳��"),TEXT("����"),MB_OK);
				return 0;
			}
			if(req_2==0)
            {
				MessageBox(NULL,TEXT("��ѡ����������"),TEXT("����"),MB_OK);
				return 0;
			}
            Ayear=0;
            while(year[p]>='0'&&year[p]<='9')
            {
                Ayear=Ayear*10+(year[p]-'0');
                p++;
            }
            Aclass=p=0;
            while(classnow[p]>='0'&&classnow[p]<='9')
            {
                Aclass=Aclass*10+(classnow[p]-'0');
                p++;
            }
            if(searchyear(Ayear)==0)
                MessageBox(NULL,TEXT("δ�鵽�ڸ�����ѧ��ѧ��������������"),TEXT("����"),MB_OK);
            else{
                if(searchmajor(majornow)==0)
                    MessageBox(NULL,TEXT("δ�鵽��רҵ��ѧ��������������"),TEXT("����"),MB_OK);
                else{
                    flag=1;
                    InvalidateRect(hwnd,NULL,TRUE);
                    UpdateWindow(hwnd);
                }
            }

        }
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("SearchGradeWin", GetModuleHandle(NULL));
            return 0;
        }
    }

	if(msg==WM_SIZE)
	{
        cxCliect=LOWORD(lParam);
        cyClient=HIWORD(lParam);
	}

	if(msg==WM_VSCROLL)
	{
		if(LOWORD(wParam)==SB_LINEUP)
                iVscrollPos -=1;
        if(LOWORD(wParam)==SB_LINEDOWN)
                iVscrollPos +=1;
        if(LOWORD(wParam)==SB_PAGEUP)
                iVscrollPos -= cyClient / cyChar;
        if(LOWORD(wParam)==SB_PAGEDOWN)
                iVscrollPos += cyClient / cyChar;
        if(LOWORD(wParam)==SB_THUMBTRACK)
                iVscrollPos = HIWORD(wParam);
        if(LOWORD(wParam)==SB_THUMBPOSITION)

        iVscrollPos=max(0,min(iVscrollPos,NUMLINES-1));
        if(iVscrollPos!=GetScrollPos(hwnd,SB_VERT))
        {
                SetScrollPos(hwnd,SB_VERT,iVscrollPos,TRUE);
                InvalidateRect(hwnd,NULL,TRUE);
                UpdateWindow(hwnd);
        }
        return 0;
	}

	if(msg==WM_PAINT)
	{
		if(flag==1)
		{
			hdc = BeginPaint(hwnd, &ps);
			sort_three(Ayear,majornow,ordern,req_1,req_2,Aclass);
			cnty=0;
			EndPaint(hwnd, &ps);
		}
	}

    if(msg==WM_CREATE)
    {
        hdc=GetDC(hwnd);
        GetTextMetrics(hdc,&tm);
        cxChar=tm.tmAveCharWidth;
        cxCaps=(tm.tmPitchAndFamily&1?3:2)*cxChar/2;
        cyChar=tm.tmHeight+tm.tmExternalLeading;
        ReleaseDC(hwnd,hdc);
        
        SetScrollRange(hwnd,SB_VERT,0,NUMLINES-1,FALSE);
        SetScrollPos(hwnd,SB_VERT,0,TRUE);

        CreateWindow(TEXT("STATIC"), TEXT("�������ͣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 75, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("����˳��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 120, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�������ݣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 165, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("��ѧ��ݣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 210, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("רҵ��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 255, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�༶(ѡ��)��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 300, 80, 20,hwnd, NULL, NULL, NULL);

        g_hEditUseryear = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
            150, 210, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

        g_hEditUsermajor = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 255, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditUserclass = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 300, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("��ѯ"),WS_VISIBLE | WS_CHILD,
            120, 335, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN  , NULL, NULL);

        g_hComboBoxpaiming0Type = CreateWindow(
        TEXT("COMBOBOX"), TEXT(""),
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        150, 75, 200, 200,
        hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);

        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("�ۺ�����"));
        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("�ְ�����"));
        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("�༶ѧ������"));

        g_hComboBoxpaiming1Type = CreateWindow(
        TEXT("COMBOBOX"), TEXT(""),
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        150, 120, 200, 200,
        hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);

        SendMessage(g_hComboBoxpaiming1Type, CB_ADDSTRING, 0, (LPARAM)TEXT("�Ӹߵ���"));
        SendMessage(g_hComboBoxpaiming1Type, CB_ADDSTRING, 0, (LPARAM)TEXT("�ӵ͵���"));

        g_hComboBoxpaiming2Type = CreateWindow(
        TEXT("COMBOBOX"), TEXT(""),
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        150, 165, 200, 200,
        hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);

        SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("�ܼ�������"));
        SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("���޿μ�������"));
        SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("���м�������"));
        SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("������������"));
		SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("�ܳɼ�����"));
        SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("���޿γɼ�����"));
        SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("���гɼ�����"));
        SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("�����ɼ�����"));
    }

    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("SearchGradeWin", GetModuleHandle(NULL));
        }
        else   
                return 0;
    }

    if(msg==WM_DESTROY)
    {
        PostQuitMessage(0);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//����Ա(��ʦ)�鿴ѧ���ܳɼ�
LRESULT CALLBACK AdmStuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    int NUMLINES=8000;
    if(msg==WM_COMMAND){
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AdmStuWin", GetModuleHandle(NULL));
            return 0;
        }
    }

	if(msg==WM_SIZE)
	{
        cxCliect=LOWORD(lParam);
        cyClient=HIWORD(lParam);
	}
        

	if(msg==WM_VSCROLL)
	{
		if(LOWORD(wParam)==SB_LINEUP)
                iVscrollPos -=1;
        if(LOWORD(wParam)==SB_LINEDOWN)
                iVscrollPos +=1;
        if(LOWORD(wParam)==SB_PAGEUP)
                iVscrollPos -= cyClient / cyChar;
        if(LOWORD(wParam)==SB_PAGEDOWN)
                iVscrollPos += cyClient / cyChar;
        if(LOWORD(wParam)==SB_THUMBTRACK)
                iVscrollPos = HIWORD(wParam);
        if(LOWORD(wParam)==SB_THUMBPOSITION)

        iVscrollPos=max(0,min(iVscrollPos,NUMLINES-1));
        if(iVscrollPos!=GetScrollPos(hwnd,SB_VERT))
        {
                SetScrollPos(hwnd,SB_VERT,iVscrollPos,TRUE);
                InvalidateRect(hwnd,NULL,TRUE);
                UpdateWindow(hwnd);
        }
        return 0;
	}

	if(msg==WM_PAINT)
	{
			hdc = BeginPaint(hwnd, &ps);
            showstudentscores();
			cnty=0;
			EndPaint(hwnd, &ps);
	}

    if(msg==WM_CREATE)
    {
        hdc=GetDC(hwnd);
        GetTextMetrics(hdc,&tm);
        cxChar=tm.tmAveCharWidth;
        cxCaps=(tm.tmPitchAndFamily&1?3:2)*cxChar/2;
        cyChar=tm.tmHeight+tm.tmExternalLeading;
        ReleaseDC(hwnd,hdc);
        
        SetScrollRange(hwnd,SB_VERT,0,NUMLINES-1,FALSE);
        SetScrollPos(hwnd,SB_VERT,0,TRUE);
    }

    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AdmStuWin", GetModuleHandle(NULL));
        }
        else   
                return 0;
        }

    if(msg==WM_DESTROY)
    {
        PostQuitMessage(0);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//����Ա(��ʦ)�鿴�γ̷���
LRESULT CALLBACK ClassAnalyProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    int NUMLINES=100;
    if(msg==WM_COMMAND){
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            GetWindowTextA(g_hEditUseryear, Bclass, sizeof(Bclass));
            if(searchcls(Bclass)==NULL)
                MessageBox(NULL,TEXT("δ��ѯ���ÿγ̣�����������"),TEXT("����"),MB_OK);
            else{
                    flag=1;
                    InvalidateRect(hwnd,NULL,TRUE);
                    UpdateWindow(hwnd);
                }

        }
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("ClassAnalyWin", GetModuleHandle(NULL));
            return 0;
        }
    }

	if(msg==WM_SIZE)
	{
        cxCliect=LOWORD(lParam);
        cyClient=HIWORD(lParam);
	}
        

	if(msg==WM_VSCROLL)
	{
		if(LOWORD(wParam)==SB_LINEUP)
                iVscrollPos -=1;
        if(LOWORD(wParam)==SB_LINEDOWN)
                iVscrollPos +=1;
        if(LOWORD(wParam)==SB_PAGEUP)
                iVscrollPos -= cyClient / cyChar;
        if(LOWORD(wParam)==SB_PAGEDOWN)
                iVscrollPos += cyClient / cyChar;
        if(LOWORD(wParam)==SB_THUMBTRACK)
                iVscrollPos = HIWORD(wParam);
        if(LOWORD(wParam)==SB_THUMBPOSITION)

        iVscrollPos=max(0,min(iVscrollPos,NUMLINES-1));
        if(iVscrollPos!=GetScrollPos(hwnd,SB_VERT))
        {
                SetScrollPos(hwnd,SB_VERT,iVscrollPos,TRUE);
                InvalidateRect(hwnd,NULL,TRUE);
                UpdateWindow(hwnd);
        }
        return 0;
	}

	if(msg==WM_PAINT)
	{
		if(flag==1)
		{
			hdc = BeginPaint(hwnd, &ps);
			survey_subject(searchcls(Bclass));
			cnty=0;
			EndPaint(hwnd, &ps);
		}
	}

    if(msg==WM_CREATE)
    {
        hdc=GetDC(hwnd);
        GetTextMetrics(hdc,&tm);
        cxChar=tm.tmAveCharWidth;
        cxCaps=(tm.tmPitchAndFamily&1?3:2)*cxChar/2;
        cyChar=tm.tmHeight+tm.tmExternalLeading;
        ReleaseDC(hwnd,hdc);

        SetScrollRange(hwnd,SB_VERT,0,NUMLINES-1,FALSE);
        SetScrollPos(hwnd,SB_VERT,0,TRUE);

        CreateWindow(TEXT("STATIC"), TEXT("��ѯ�γ̣�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 120, 80, 20,hwnd, NULL, NULL, NULL);

        g_hEditUseryear = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
            150, 120, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("��ѯ"),WS_VISIBLE | WS_CHILD,
            120, 250, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN  , NULL, NULL);

    }

    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("ClassAnalyWin", GetModuleHandle(NULL));
        }
        else   
            return 0;
        }

    if(msg==WM_DESTROY)
    {
        PostQuitMessage(0);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void StuClassWindow()
{
    cntx=0,cnty=0;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = StuClassProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"StuClassWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("StuClassWin"), TEXT("ѧ��"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    500, 200, 700, 500, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    300, 350, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void SearchGradeWindow()
{
    HWND hwnd;
	cntx=0,cnty=0,flag=0;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = SearchGradeProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"SearchGradeWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("SearchGradeWin"), TEXT("ѧ��"), 
	(WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
    400, 200, 900, 700, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 400, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void AdmStuWindow()
{
    HWND hwnd;
	cntx=0,cnty=0,flag=0;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdmStuProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdmStuWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdmStuWin"), TEXT("����Ա"), 
	(WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
    450, 200, 900, 700, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        500, 400, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void ClassAnalyWindow()
{
    HWND hwnd;
	cntx=0,cnty=0,flag=0;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = ClassAnalyProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"ClassAnalyWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("ClassAnalyWin"), TEXT("����Ա"), 
	(WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
    400, 200, 900, 700, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 400, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

#endif
