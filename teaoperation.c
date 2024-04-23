#ifndef TEAOPERATION
#define TEAOPERATION
//��ʦ¼��ӷ��� 
LRESULT CALLBACK TeaEnthorProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
		char stuname[100], eventnow[100],pointnow[100];
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case ID_BUTTON_LOGIN:
                GetWindowTextA(g_hEditStuname, stuname, sizeof(stuname));
                GetWindowTextA(g_hEditevent, eventnow, sizeof(eventnow));
                GetWindowTextA(g_hEditpoint, pointnow, sizeof(pointnow));

                stunode *Astu;
				Astu=searchstu(stuname);
				if(Astu!=NULL)
                {
                	if(strlen(eventnow)==0)
					{
						MessageBox(NULL,TEXT("������ӷ���"),TEXT("����"),MB_OK);
						return 0;
					}
                	if(strlen(pointnow)==0)
					{
						MessageBox(NULL,TEXT("������ӷ�ֵ"),TEXT("����"),MB_OK);
						return 0;
					}
                    int flagnow1=0,flagnow2=0,i=0,len=strlen(pointnow);
                    double sc=0,xs=0,zs=0.1;
                    for(i=0;i<len;i++)
                    {
                        if(pointnow[i]!='.'&&(pointnow[i]<'0'||pointnow[i]>'9'))
                        {flagnow1=1;break;}
                        if(pointnow[i]=='.')
						{
							if(i==0||i==len-1||flagnow2==1)
							{flagnow1=1;break;}
							flagnow2=1;
						}
						else
						{
							if(flagnow2==0)
								sc=sc*10+pointnow[i]-'0';
							else xs+=zs*(pointnow[i]-'0'),zs*=0.1;
						}
					}
					sc+=xs;
                    if(sc>=0&&sc<=1&&flagnow1==0)
                    {
                MessageBox(NULL,TEXT("������Ϣ�Ѿ����沢�ϱ�����ȴ�����Ա������"),TEXT("ͨ��"),MB_OK);
                FILE* fp=fopen(EA,"a+");
                fprintf(fp,"enterhonor;%s;%s;%.2lf;%s;\n",astu->stu.name,str,sc,teauser->tea.name);
                fclose(fp);
                    }
                    else MessageBox(NULL,TEXT("¼�����������������ȷ����ֵ��"),TEXT("����"),MB_ICONERROR);
                }
                else MessageBox(NULL,TEXT("ѧ�������ڣ�����������"),TEXT("����"),MB_ICONERROR);
                break;

            case ID_BUTTON_ROOT_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("TeaEnthorWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_CREATE:
            CreateWindow(TEXT("STATIC"), TEXT("ѧ����������ѧ�ţ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 70, 135, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("���ۺ����ʼӷ��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 115, 135, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("¼����Ŀ�ڼ����۲��ʱ���ӵķ�ֵ��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 160, 135, 40,hwnd, NULL, NULL, NULL);

            g_hEditStuname = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                200, 70, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

            g_hEditevent = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                200, 115, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

            g_hEditpoint = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                200, 160, 200, 40,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

            CreateWindow(TEXT("BUTTON"), TEXT("ȷ�����"),WS_VISIBLE | WS_CHILD,
                130, 225, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

            break;

        case  WM_CLOSE:
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("TeaEnthorWin", GetModuleHandle(NULL));
            }
            else return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//��ʦ¼��ͷ�
LRESULT CALLBACK TeaEntpunProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_COMMAND:
            if(LOWORD(wParam)==ID_BUTTON_LOGIN) 
            {
                char stuname[100], eventnow[100];
                GetWindowTextA(g_hEditStuname, stuname, sizeof(stuname));
                GetWindowTextA(g_hEditevent, eventnow, sizeof(eventnow));
				int PunishTypeIndex = SendMessage(g_hComboBoxPunishType, CB_GETCURSEL, 0, 0);

                stunode *Astu;
				Astu=searchstu(stuname);
				if(Astu!=NULL)
                {
                	if(strlen(eventnow)==0)
					{
						MessageBox(NULL,TEXT("�����봦������"),TEXT("����"),MB_OK);
						return 0;
					}
                	if(PunishTypeIndex==-1)
					{
						MessageBox(NULL,TEXT("��ѡ�񴦷�����"),TEXT("����"),MB_OK);
						return 0;
					}
                    MessageBox(NULL,TEXT("������Ϣ�Ѿ����沢�ϱ�����ȴ�����Ա������"),TEXT("ͨ��"),MB_OK);
                    FILE* fp=fopen(EA,"a+");
                    fprintf(fp,"enterpunish;%s;%s;%d;%s;\n",astu->stu.name,str,PunishTypeIndex+1,teauser->tea.name);
                    fclose(fp);
                }
                else MessageBox(NULL,TEXT("ѧ�������ڣ�����������"),TEXT("����"),MB_ICONERROR);
                break;
			}
            else if(LOWORD(wParam)==ID_BUTTON_ROOT_EXIT_SYSTEM)
            {
                DestroyWindow(hwnd);
                UnregisterClass("TeaEntpunWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_CREATE:
            CreateWindow(TEXT("STATIC"), TEXT("ѧ����������ѧ�ţ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 70, 135, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("�������ɣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 115, 135, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("��������"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 160, 135, 20,hwnd, NULL, NULL, NULL);

            g_hEditStuname = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                200, 70, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

            g_hEditevent = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                200, 115, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

            g_hComboBoxPunishType = CreateWindow(
                TEXT("COMBOBOX"), TEXT(""),
                WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
                200, 160, 200, 200,
                hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);
		
            SendMessage(g_hComboBoxPunishType, CB_ADDSTRING, 0, (LPARAM)TEXT("����"));
            SendMessage(g_hComboBoxPunishType, CB_ADDSTRING, 0, (LPARAM)TEXT("���ؾ���"));
            SendMessage(g_hComboBoxPunishType, CB_ADDSTRING, 0, (LPARAM)TEXT("����"));
            SendMessage(g_hComboBoxPunishType, CB_ADDSTRING, 0, (LPARAM)TEXT("���ش���"));
            SendMessage(g_hComboBoxPunishType, CB_ADDSTRING, 0, (LPARAM)TEXT("��У�쿴"));
            SendMessage(g_hComboBoxPunishType, CB_ADDSTRING, 0, (LPARAM)TEXT("����"));

            CreateWindow(TEXT("BUTTON"), TEXT("ȷ�����"),WS_VISIBLE | WS_CHILD,
                130, 225, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

            break;

        case  WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("TeaEntpunWin", GetModuleHandle(NULL));
            }
            else return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//��ʦ¼��γ�
LRESULT CALLBACK TeaInCouProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if(msg==WM_COMMAND){
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            int nature=SendMessage(g_hEditUsergender,CB_GETCURSEL, 0, 0);
            char tea[20],name[50],id[20],credit[20];
            GetWindowTextA(g_hEditUseryear, credit, sizeof(credit));
            GetWindowTextA(g_hEditUsermajor, tea, sizeof(tea));
            GetWindowTextA(g_hEditUsername1, name, sizeof(name));
            GetWindowTextA(g_hEditUserid, id, sizeof(id));
			if(strlen(credit)==0||strlen(tea)==0||strlen(name)==0||strlen(id)==0||nature==-1)
            {
            	MessageBox(NULL,TEXT("�������ݲ�����"),TEXT("����"),MB_OK);
                return 0;
			}
			teanode *teanow1=tealih;
			while(teanow1!=NULL)
			{
				if(strcmp(teanow1->tea.name,tea)==0){break;}
				teanow1=teanow1->next;
			}
			if(teanow1==NULL)
			{
				MessageBox(NULL,TEXT("δ�鵽�ý�ʦ������������"),TEXT("����"),MB_OK);
				return 0;
			}
			clsnode *clsnow1=clslih;
			while(clsnow1!=NULL)
			{
				if(strcmp(clsnow1->clsif.id,id)==0)
				{
					MessageBox(NULL,TEXT("������ͬ��ŵĿγ̣�������������"),TEXT("����"),MB_OK);
					return 0;
				}
				clsnow1=clsnow1->next;
			}
			int flagnow1=0,flagnow2=0,i=0,len=strlen(credit);
            double Acredit=0,xs=0,zs=0.1;
            for(i=0;i<len;i++)
            {
                if(credit[i]!='.'&&(credit[i]<'0'||credit[i]>'9'))
                {flagnow1=1;break;}
                if(credit[i]=='.')
                {
                    if(i==0||i==len-1||flagnow2==1)
                    {flagnow1=1;break;}
                    flagnow2=1;
                }
                else
                {
                    if(flagnow2==0)
                        Acredit=Acredit*10+credit[i]-'0';
                    else xs+=zs*(credit[i]-'0'),zs*=0.1;
                }
            }
            Acredit+=xs;
            if(flagnow1==1||Acredit>10)
            {
            	MessageBox(NULL,TEXT("ѧ���쳣������������"),TEXT("����"),MB_OK);
				return 0;
			}
            
            if(MessageBox(NULL,TEXT("�Ƿ�����¼��ÿγ�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
			{
	            MessageBox(NULL,TEXT("������Ϣ�Ѿ����沢�ϱ�����ȴ�����Ա������"),TEXT("ͨ��"),MB_OK);
	            FILE* fp=fopen(EA,"a+");
	            fprintf(fp,"inputcourse;%s;%s;%d;%s;%lf;%s;\n",name,id,nature,tea,Acredit,teauser->tea.name);
	            fclose(fp);
			}

        }
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("TeaInCouWin", GetModuleHandle(NULL));
            return 0;
        }
    }

    if(msg==WM_CREATE)
    {
        CreateWindow(TEXT("STATIC"), TEXT("�γ�����"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 75, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�γ̱�ţ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 120, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�ڿν�ʦ��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 165, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�γ����ʣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 210, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�γ�ѧ�֣�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 255, 80, 20,hwnd, NULL, NULL, NULL);

        g_hEditUsername1 = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
            150, 75, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

        g_hEditUserid = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 120, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditUsermajor = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 165, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditUseryear = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 255, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("ִ��"),WS_VISIBLE | WS_CHILD,
            120, 300, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN  , NULL, NULL);

        g_hEditUsergender = CreateWindow(
        TEXT("COMBOBOX"), TEXT(""),
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        150, 210, 200, 200,
        hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);

        SendMessage(g_hEditUsergender, CB_ADDSTRING, 0, (LPARAM)TEXT("����"));
        SendMessage(g_hEditUsergender, CB_ADDSTRING, 0, (LPARAM)TEXT("ѡ��"));
        SendMessage(g_hEditUsergender, CB_ADDSTRING, 0, (LPARAM)TEXT("��ѡ"));
    }

    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("TeaInCouWin", GetModuleHandle(NULL));
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

//��ʦת��ѧ��
LRESULT CALLBACK TeaOutStuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if(msg==WM_COMMAND){
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            char name[20];
            GetWindowTextA(g_hEditUsername1, name, sizeof(name));
            deletestuoftea(name);
        }
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("TeaOutStuWin", GetModuleHandle(NULL));
            return 0;
        }
    }

    if(msg==WM_CREATE)
    {
        CreateWindow(TEXT("STATIC"), TEXT("������"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 75, 80, 20,hwnd, NULL, NULL, NULL);

        g_hEditUsername1 = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
            150, 75, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("ִ�в���"),WS_VISIBLE | WS_CHILD,
            120, 130, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN  , NULL, NULL);
    }

    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("TeaOutStuWin", GetModuleHandle(NULL));
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

//��ʦ�޸�ѧ���ɼ� 
LRESULT CALLBACK TeaChangeScoreProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
    int i=0;
    int NUMLINES=100;
    if(msg==WM_COMMAND)
	{
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            char stuname[100],coursenow[100],gradenow[100];
            GetWindowTextA(g_hEditStuname, stuname, sizeof(stuname));
            GetWindowTextA(g_hEditCourse, coursenow, sizeof(coursenow));
            GetWindowTextA(g_hEditGrade, gradenow, sizeof(gradenow));
			int naturenow=SendMessage(g_hComboBoxpaiming0Type, CB_GETCURSEL, 0, 0);
			
			stunode *Astu;
			Astu=searchstu(stuname);
			if(Astu==NULL)
			{
				MessageBox(NULL,TEXT("ѧ�������ڣ�����������"),TEXT("����"),MB_OK);
				return 0;
			}
			clsnode *Acls;
			Acls=searchcls(coursenow);
			if(Acls==NULL)
			{
				MessageBox(NULL,TEXT("�γ̲����ڣ�����������"),TEXT("����"),MB_OK);
				return 0;
			}
			if(strlen(gradenow)==0)
			{
				MessageBox(NULL,TEXT("�ɼ��������"),TEXT("����"),MB_OK);
				return 0;
			}
			int cfind=0;
			if(Astu->stu.scoreh->pre==NULL&&Astu->stu.scoreh->next!=NULL)Astu->stu.scoreh=Astu->stu.scoreh->next;
			cosnode* pnow=Astu->stu.scoreh;
			while(pnow!=NULL&&pnow->pre!=NULL)
			{
				if(pnow->cos.c==&(Acls->clsif))cfind=1;
				pnow=pnow->next;
			}
			if(cfind==0)
			{
				MessageBox(NULL,TEXT("��ѧ����δ��ɸÿγ̵�ѧϰ������������"),TEXT("����"),MB_OK);
				return 0;
			}
			
			int i=0,flagnow=0,len=strlen(gradenow),gradere;
			for(i=0;i<len;i++)
			{
				if(gradenow[i]<'0'||gradenow[i]>'9')
				{
					flagnow=1;
					break;
				}
				gradere=gradere*10+gradenow[i]-'0';
			}
			if(flagnow==1||gradere>100)
			{
				MessageBox(NULL,TEXT("�����쳣������������"),TEXT("����"),MB_OK);
				return 0;
			}
			if(naturenow==-1)
			{
				MessageBox(NULL,TEXT("��ѡ��ѧϰ����"),TEXT("����"),MB_OK);
				return 0;
			}
            MessageBox(NULL,TEXT("������Ϣ�Ѿ����沢�ϱ�����ȴ�����Ա������"),TEXT("ͨ��"),MB_OK);
            FILE* fp=fopen(EA,"a+");
            fprintf(fp,"changescoreofastu;%s;%s;%d;%d;%s;\n",Astu->stu.name,Acls->clsif.name,gradere,naturenow,teauser->tea.name);
            fclose(fp);
        }
        if(LOWORD(wParam)==ID_BUTTON_ROOT_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("TeaChangeScoreWin", GetModuleHandle(NULL));
            return 0;
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

        CreateWindow(TEXT("STATIC"), TEXT("ѧ��������ѧ�ţ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            10, 75, 160, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�γ����ƻ�γ̱�ţ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            10, 120, 160, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�³ɼ���"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            10, 165, 160, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("ѧϰ���ʣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            10, 210, 160, 20,hwnd, NULL, NULL, NULL);

        g_hEditStuname = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
            200, 75, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

        g_hEditCourse = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            200, 120, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditGrade = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            200, 165, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);
            
            
        g_hComboBoxpaiming0Type = CreateWindow(
        TEXT("COMBOBOX"), TEXT(""),
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        200, 210, 200, 200,
        hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);

        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("����"));
        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("����"));

        CreateWindow(TEXT("BUTTON"), TEXT("ȷ���޸�"),WS_VISIBLE | WS_CHILD,
            120, 260, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN  , NULL, NULL);

    }

        if(msg==WM_CLOSE)
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("TeaChangeScoreWin", GetModuleHandle(NULL));
        }
		else return 0;

    if(msg==WM_DESTROY)
    {
        PostQuitMessage(0);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//��ʦչʾ����ѧ����Ϣ
LRESULT CALLBACK TeaShowStuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{   
    int NUMLINES=350;
    switch (msg)
    {
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case ID_BUTTON_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("TeaShowStuWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_SIZE:
            cxCliect=LOWORD(lParam);  //��ȡ����ʵʱ����(����)
            cyClient=HIWORD(lParam);  //��ȡ����ʵʱ����(�߶�)

        case WM_VSCROLL://��ֱ������
            if(LOWORD(wParam)==SB_LINEUP)//���Ϲ���һ��
                    iVscrollPos -=1;
            if(LOWORD(wParam)==SB_LINEDOWN)//���¹���һ��
                    iVscrollPos +=1;
            if(LOWORD(wParam)==SB_PAGEUP)//���Ϲ���һҳ
                    iVscrollPos -= cyClient / cyChar;
            if(LOWORD(wParam)==SB_PAGEDOWN)//���¹���һҳ
                    iVscrollPos += cyClient / cyChar;
            if(LOWORD(wParam)==SB_THUMBTRACK)//ץס����������
                    iVscrollPos = HIWORD(wParam);
            if(LOWORD(wParam)==SB_THUMBPOSITION)//

            iVscrollPos=max(0,min(iVscrollPos,NUMLINES-1));
            //max(a,b)  (((a)>(b))?(a):(b))
            //min(a,b)  (((a)<(b))?(a):(b))
            if(iVscrollPos!=GetScrollPos(hwnd,SB_VERT))//���������λ�øı�
            {
                    //�������ù�����λ��
                    SetScrollPos(hwnd,SB_VERT,iVscrollPos,TRUE);
                    //�����ػ���Ϣ
                    InvalidateRect(hwnd,NULL,TRUE);
                    UpdateWindow(hwnd);
            }
            return 0;

        case WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("TeaShowStuWin", GetModuleHandle(NULL));
            }
            else   
                return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        case WM_CREATE: //��ȡ�ַ����
            hdc=GetDC(hwnd);
            GetTextMetrics(hdc,&tm);
            cxChar=tm.tmAveCharWidth;
            cxCaps=(tm.tmPitchAndFamily&1?3:2)*cxChar/2; //��ȡ�ַ�ƽ�����
            cyChar=tm.tmHeight+tm.tmExternalLeading;
            ReleaseDC(hwnd,hdc);

            //���ù�������Χ(�ܹ��ж��ٸ�λ��)
            SetScrollRange(hwnd,SB_VERT,0,NUMLINES-1,FALSE);
            //���ù�����λ��
            SetScrollPos(hwnd,SB_VERT,0,TRUE);

            return 0;

        case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps); 
        showstudent();
        cnty=0;
        EndPaint(hwnd, &ps);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void TeaInCouWindow()
{
    HWND hwnd;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = TeaInCouProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"TeaInCouWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("TeaInCouWin"), TEXT("ѧ��"), 
	(WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
    600, 300, 450, 500, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 350, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void TeaEnthorWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = TeaEnthorProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"TeaEnthorWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("TeaEnthorWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 500, 450, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 300, 230, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void TeaOutStuWindow()
{
    HWND hwnd;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = TeaOutStuProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"TeaOutStuWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("TeaOutStuWin"), TEXT("ѧ��"), 
	(WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
    600, 400, 400, 400, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 200, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void TeaEntpunWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = TeaEntpunProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"TeaEntpunWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("TeaEntpunWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 500, 450, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 300, 230, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void TeaChangeScoreWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = TeaChangeScoreProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"TeaChangeScoreWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("TeaChangeScoreWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 450, 450, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 330, 200, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void TeaShowStuWindow()
{
    cntx=0,cnty=0;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = TeaShowStuProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"TeaShowStuWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("TeaShowStuWin"), TEXT("ѧ��"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    500, 200, 700, 500, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    400, 350, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

#endif
