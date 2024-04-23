#ifndef MAINWINDOW
#define MAINWINDOW

//ѧ����¼�����
LRESULT CALLBACK StuWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_BUTTON_VIEW_BASIC_INFO: //�鿴��Ϣ
            ShowStuWindow();
            break;
        case ID_BUTTON_VIEW_ALL_COURSES:
            StuClassWindow();
            break;
        case ID_BUTTON_QUERY_SUBJECT_SCORE:
            StuClassScoreWindow();
            break;
        case ID_BUTTON_QUERY_TOTAL_SCORE:
            StuAllScoreWindow();
            break;
        case ID_BUTTON_VIEW_RANKING:
            SearchGradeWindow();
            break;
        case ID_BUTTON_CHANGE_PASSWORD:
            ChangeStuWindow();
            break;
        case ID_BUTTON_EXIT_SYSTEM:
            DestroyWindow(hwnd);
            UnregisterClass("StudentWin", GetModuleHandle(NULL));
            break;
            break;
        }
        break;

    case WM_CLOSE: //�ر�ȷ��
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("StudentWin", GetModuleHandle(NULL));
        }
        else   
            return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

//��ʦ��¼�����
LRESULT CALLBACK TeaWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_COMMAND:
        switch (LOWORD(wParam))
        {
            case ID_BUTTON_TEA_VIEW_BASIC_INFO:
                TeaShowStuWindow();
                break;
            case ID_BUTTON_TEA_VIEW_ALL_COURSES:
                StuClassWindow();
                break;
            case ID_BUTTON_TEA_QUERY_DETAILED_SCORE:
                AdmStuWindow();
                break;
            case ID_BUTTON_TEA_VIEW_RANKING:
                SearchGradeWindow();
                break;
            case ID_BUTTON_TEA_ANALISE_COURSE:
                ClassAnalyWindow();
                break;
            case ID_BUTTON_TEA_INPUT_SCORE:
                AdmEntStuorScoWindow();
                break;
            case ID_BUTTON_TEA_CHANGE_SCORE:
                TeaChangeScoreWindow();
                break;
            case ID_BUTTON_TEA_INPUT_NEWCOURSE:
                TeaInCouWindow();
                break;
            case ID_BUTTON_TEA_DELETE_STUDENT:
                TeaOutStuWindow();
                break;
            case ID_BUTTON_TEA_INPUT_HONOR:
                TeaEnthorWindow();
                break;
            case ID_BUTTON_TEA_INPUT_PUNISH:
                TeaEntpunWindow();
                break;
            case ID_BUTTON_TEA_CHANGE_PASSWORD:
                ChangeTeaWindow();
                break;
            case ID_BUTTON_TEA_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("TeacherWin", GetModuleHandle(NULL));
                break;
                break;
        }
        break;

        case WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("TeacherWin", GetModuleHandle(NULL));
            }
            else   
                return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

//����Ա��¼�����
LRESULT CALLBACK AdminWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_COMMAND:
        switch (LOWORD(wParam))
        {
            case ID_BUTTON_ROOT_VIEW_STUDENT_INFO:
                ShowStutoAdmWindow(); 
                break;
            case ID_BUTTON_ROOT_VIEW_TEACHER_INFO:
                ShowTeatoAdmWindow();
                break;
            case ID_BUTTON_ROOT_VIEW_COURSES_INFO:
                ShowCostoAdmWindow();
                break;
            case ID_BUTTON_ROOT_VIEW_DETAILED_SCORE:
                AdmStuWindow();
                break;
            case ID_BUTTON_ROOT_VIEW_RANKING:
                SearchGradeWindow();
                break;
            case ID_BUTTON_ROOT_CHANGE_SCORE:
                AdmChangeScoreWindow();
                break;
            case ID_BUTTON_ROOT_INPUT_NEWCOURSE:
                AdmInCouWindow();
                break;
            case ID_BUTTON_ROOT_INPUT_NEWTEACHER:
                AdmInTeaWindow();
                break;
            case ID_BUTTON_ROOT_INPUT_NEWSTUDENT:
                AdmInStuWindow();
                break;
            case ID_BUTTON_ROOT_DELETE_STUDENT:
                AdmOutStuWindow();
                break;
            case ID_BUTTON_ROOT_INPUT_HONOR:
                AdmEnthorWindow();
                break;
            case ID_BUTTON_ROOT_INPUT_PUNISH:
                AdmEntpunWindow();
                break;
            case ID_BUTTON_ROOT_ANALISE_COURSE:
                ClassAnalyWindow();
                break;
            case ID_BUTTON_ROOT_INPUT_SCORE:
                AdmEntStuorScoWindow();
                break;
            case ID_BUTTON_ROOT_EXAMINE_APPLY:
                AmdAppWindow();
                break;
            case ID_BUTTON_ROOT_CHANGE_PASSWORD:
                ChangeAdmWindow();
                break;  
            case ID_BUTTON_ROOT_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("AdminWin", GetModuleHandle(NULL));
                break;
                break;
        }
        break;

        case WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("AdminWin", GetModuleHandle(NULL));
            }
            else   
                return 0;
	
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }	

    return 0;
}

void StudentWindow()
{
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = StuWndProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"StudentWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("ѧ������ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("StudentWin"), TEXT("�޸�ѧ��"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    600, 200, 500, 480, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("�޸�ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�鿴�Լ��Ļ�����Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    130, 50, 200, 30, hwndChange, (HMENU)ID_BUTTON_VIEW_BASIC_INFO, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�鿴��ǰ���пγ̵Ļ�����Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    130, 100, 200, 30, hwndChange, (HMENU)ID_BUTTON_VIEW_ALL_COURSES, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("��ѯ�Լ��ķֿƳɼ�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    130, 150, 200, 30, hwndChange, (HMENU)ID_BUTTON_QUERY_SUBJECT_SCORE, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("��ѯ�Լ�������ɼ�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    130, 200, 200, 30, hwndChange, (HMENU)ID_BUTTON_QUERY_TOTAL_SCORE, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�鿴��רҵ�ɼ��Ű�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    130, 250, 200, 30, hwndChange, (HMENU)ID_BUTTON_VIEW_RANKING, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�޸�����"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    130, 300, 200, 30, hwndChange, (HMENU)ID_BUTTON_CHANGE_PASSWORD, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    130, 350, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void AdminWindow()
{
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdminWndProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdminWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����Ա����ע��ʧ��"),TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdminWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
	500, 200, 650, 550, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�鿴��ǰ����ѧ���Ļ�����Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 50, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_VIEW_STUDENT_INFO, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�鿴��ǰ������ʦ�Ļ�����Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 100, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_VIEW_TEACHER_INFO, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("�鿴��ǰ���пγ̵Ļ�����Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 150, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_VIEW_COURSES_INFO, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�鿴ѧ����ϸ��Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 200, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_VIEW_DETAILED_SCORE, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("�鿴�ɼ�����"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 250, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_VIEW_RANKING, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�޸�ѧ���ɼ�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 300, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_CHANGE_SCORE, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("¼���¿γ�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 350, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_INPUT_NEWCOURSE, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("��������ʦ��Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 400, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_INPUT_NEWTEACHER, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("ת��ѧ��"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 50, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_INPUT_NEWSTUDENT, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("ת��ѧ��"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 100, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_DELETE_STUDENT, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("¼��ѧ���ۺ����ʼӷ���"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 150, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_INPUT_HONOR, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("¼��ѧ���������"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 200, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_INPUT_PUNISH, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("�鿴�γ̳ɼ�����"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 250, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_ANALISE_COURSE, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("����¼��ɼ�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 300, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_INPUT_SCORE, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("��������"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 350, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXAMINE_APPLY, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�޸�����"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 400, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_CHANGE_PASSWORD, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	100, 450, 400, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void TeacherWindow()
{
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = TeaWndProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"TeacherWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("��ʦ����ע��ʧ��"),TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("TeacherWin"), TEXT("��ʦ"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
	500, 200, 650, 700, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("��ʦ���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�鿴��ǰ����ѧ���Ļ�����Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 150, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_VIEW_BASIC_INFO, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�鿴��ǰ���пγ̵Ļ�����Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 200, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_VIEW_ALL_COURSES, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("�鿴ѧ����ϸ��Ϣ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 250, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_QUERY_DETAILED_SCORE, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�鿴�ɼ�����"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 300, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_VIEW_RANKING, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("�鿴�γ̳ɼ�����"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 350, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_ANALISE_COURSE, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("����¼��ɼ�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	50, 400, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_INPUT_SCORE, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("�����޸�ѧ���ɼ�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 150, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_CHANGE_SCORE, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("����¼���¿γ�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 200, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_INPUT_NEWCOURSE, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("����ת��ѧ��"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 250, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_DELETE_STUDENT, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("����¼��ѧ���ۺ����ʼӷ���"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 300, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_INPUT_HONOR, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("����¼��ѧ���������"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 350, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_INPUT_PUNISH, NULL, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("�޸�����"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	320, 400, 250, 30, hwndChange, (HMENU)ID_BUTTON_TEA_CHANGE_PASSWORD, NULL, NULL);
	CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
	100, 450, 350, 30, hwndChange, (HMENU)ID_BUTTON_TEA_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

#endif
