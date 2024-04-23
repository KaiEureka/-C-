#ifndef ADMAPPLY
#define ADMAPPLY
//����Ա����
LRESULT CALLBACK AmdAppProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if(msg==WM_COMMAND){
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            int tmp=SendMessage(g_hComboBoxpaiming0Type, CB_GETCURSEL, 0, 0);
            if(tmp==-1)
            {
                MessageBox(NULL,TEXT("��ѡ���������"),TEXT("��ʾ"),MB_OK);
                return 0;
            }
            if(tmp==0) 
            {
                str1='a';
                flag=1;
            }
            else if(tmp==1) 
            {
                str1='r';
                flag=1;
            }
            else if(tmp==2) 
            {
                str1='w';
                flag=1;
            }
            InvalidateRect(hwnd,NULL,TRUE);
            UpdateWindow(hwnd);
        }
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            //ɾ���Ѿ���������Ϣ���������������
            FILE* fp=fopen(EA,"w");
            apt* Q=aptlih;
            apt* lQ;
            if(aptlih!=NULL)
            {
                while(Q!=NULL)
                {
                    if(Q->status!=0)
                    {
                        if(Q->pre!=NULL)Q->pre->next=Q->next;
                        if(Q->next!=NULL)Q->next->pre=Q->pre;
                        lQ=Q;
                        if(Q==aptlih)aptlih=aptlih->next;
                        Q=Q->next;
                        free(lQ);  //����ѧС����bug
                    }
                    else
                    {
                        fprintf(fp,"%s",Q->str);
                        //fgets�����������ñ����Դ�\n
                        Q=Q->next;
                    }
                    
                }
            }
            fclose(fp);
            DestroyWindow(hwnd);
            UnregisterClass("AmdAppWin", GetModuleHandle(NULL));
            return 0;
        }
    }

	if(msg==WM_PAINT)
	{
        if(flag==0)
        {
            hdc = BeginPaint(hwnd, &ps);
			examineofroot();
			cnty=0;
			EndPaint(hwnd, &ps);
        }
		if(flag==1)
		{
            if(P!=NULL)
            {
            dealwithch(P,str1);
            P=P->next;
			hdc = BeginPaint(hwnd, &ps);
			examineofroot();
			cnty=0;
			EndPaint(hwnd, &ps);
            }
            else{
            hdc = BeginPaint(hwnd, &ps);
            wsprintf(szBuffer,TEXT("��ǰû�������Ϣ!"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,0,szBuffer,iTarget);
			cnty=0;
			EndPaint(hwnd, &ps);
            }
		}
	}

    if(msg==WM_CREATE)
    {
        //��ȡ�ַ����
        hdc=GetDC(hwnd);
        GetTextMetrics(hdc,&tm);
        cxChar=tm.tmAveCharWidth;
        cxCaps=(tm.tmPitchAndFamily&1?3:2)*cxChar/2; //��ȡ�ַ�ƽ�����
        cyChar=tm.tmHeight+tm.tmExternalLeading;
        ReleaseDC(hwnd,hdc);

        CreateWindow(TEXT("STATIC"), TEXT("�������ͣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 220, 80, 20,hwnd, NULL, NULL, NULL);

        // ������ѯ��ť
        CreateWindow(TEXT("BUTTON"), TEXT("��һ��"),WS_VISIBLE | WS_CHILD,
            120, 300, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN  , NULL, NULL);

        //����ѡ����
        g_hComboBoxpaiming0Type = CreateWindow(
        TEXT("COMBOBOX"), TEXT(""),
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        150, 220, 200, 200,
        hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);

        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("��׼"));
        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("���"));
        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("����"));
    }

    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            //ɾ���Ѿ���������Ϣ���������������
            FILE* fp=fopen(EA,"w");
            apt* Q=aptlih;
            apt* lQ;
            if(aptlih!=NULL)
            {
                while(Q!=NULL)
                {
                    if(Q->status!=0)
                    {
                        if(Q->pre!=NULL)Q->pre->next=Q->next;
                        if(Q->next!=NULL)Q->next->pre=Q->pre;
                        lQ=Q;
                        if(Q==aptlih)aptlih=aptlih->next;
                        Q=Q->next;
                        free(lQ);  //����ѧС����bug
                    }
                    else
                    {
                        fprintf(fp,"%s",Q->str);
                        //fgets�����������ñ����Դ�\n
                        Q=Q->next;
                    }
                }
            }
            fclose(fp);
            DestroyWindow(hwnd);
            UnregisterClass("AmdAppWin", GetModuleHandle(NULL));
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

void AmdAppWindow()
{
    HWND hwnd;
    P=aptlih;

	cntx=0,cnty=0,flag=0;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AmdAppProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AmdAppWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AmdAppWin"), TEXT("����Ա"), 
	(WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
    200, 200, 900, 700, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 380, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void examineofroot()
{
	if(P==NULL)
	{
    wsprintf(szBuffer,TEXT("��ǰû�д������Ϣ!"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
		return;
	}
	if(P!=NULL)
	{
		if(P->status==0)
		{
            wsprintf(szBuffer,TEXT("��ǰ��������Ŀ��Ϣ����:"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
			char* S=P->str;
			int j,p=0;
			if(S[0]=='\n'||S[0]=='\r') return;
			char ordername[300];
			for(j=0;S[p]!=';';j++)
			{
				ordername[j]=S[p];
				p++;
			}
			ordername[j]='\0';p++;
			char teachername[100];
			if(strcmp(ordername,"deletestu")==0)
			{
				char astuname[100];
				for(j=0;S[p]!=';';j++)
				{
					astuname[j]=S[p];
					p++;
				}
				astuname[j]='\0';p++;
				for(j=0;S[p]!=';';j++)
				{
					teachername[j]=S[p];
					p++;
				}
				teachername[j]='\0';p++;
                wsprintf(szBuffer,TEXT("�������ͣ����뿪��ѧ��"));
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                wsprintf(szBuffer,TEXT("������Դ��%s��ʦ"),teachername);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                wsprintf(szBuffer,TEXT("�������ݣ����󿪳�%s"),astuname);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
			}
			else if(strcmp(ordername,"changescoreofastu")==0)
			{
				char astr[100];
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				stunode* astu=searchstu(astr);
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				clsnode* acls=searchcls(astr);
				int anum=0;
				while(S[p]!=';')
				{
					if(S[p]>='0'&&S[p]<='9')
						anum=anum*10+S[p]-'0';
					p++;
				}
				p++;
				int newscore=anum;
				anum=0;
				while(S[p]!=';')
				{
					if(S[p]>='0'&&S[p]<='9')
						anum=anum*10+S[p]-'0';
					p++;
				}
				p++;
				int isfirst=anum;
				for(j=0;S[p]!=';';j++)
				{
					teachername[j]=S[p];
					p++;
				}
				teachername[j]='\0';p++;
                wsprintf(szBuffer,TEXT("�������ͣ������޸�ѧ���ɼ�"));
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                wsprintf(szBuffer,TEXT("������Դ��%s��ʦ"),teachername);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
				if(isfirst==1)
                {
                    wsprintf(szBuffer,TEXT("�������ݣ�����%sͬѧ��%s�ɼ��޸�Ϊ%d�֣��ұ��Ϊ����"),astu->stu.name,acls->clsif.name,newscore);
                    iTarget=lstrlen(szBuffer);
                    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
				else
                {
                    wsprintf(szBuffer,TEXT("�������ݣ�����%sͬѧ��%s�ɼ��޸�Ϊ%d�֣��ұ��Ϊ����"),astu->stu.name,acls->clsif.name,newscore);
                    iTarget=lstrlen(szBuffer);
                    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
			}
			else if(strcmp(ordername,"enterhonor")==0)
			{
				char astr[100];
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				stunode* astu=searchstu(astr);
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				int flag=0;
				double zs=0.0,xs=0.0,adouble,m1=0.1;
				for(j=0;S[p]!=';';j++)
				{
					if(S[p]=='.')
					{
						flag=1;p++;
						continue;
					}
					if(flag==0)
					{
						zs=zs*10+S[p]-'0';
					}
					else
					{
						xs+=m1*(S[p]-'0');
						m1*=0.1;
					}
					p++;
				}
				adouble=zs+xs;p++;
				for(j=0;S[p]!=';';j++)
				{
					teachername[j]=S[p];
					p++;
				}
				teachername[j]='\0';p++;
                wsprintf(szBuffer,TEXT("�������ͣ�����¼��ѧ��������ӷ���Ŀ"));
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                wsprintf(szBuffer,TEXT("������Դ��%s��ʦ"),teachername);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                sprintf(szBuffer,TEXT("�������ݣ�����Ϊ%sͬѧ¼��������ӷ���Ŀ������Ϊ%s�����мӷַ�ֵΪ%lf"),astu->stu.name,astr,adouble);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
			}
			else if(strcmp(ordername,"enterpunish")==0)
			{
				char astr[100];
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				stunode* astu=searchstu(astr);
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				int flag=0;
				double zs=0.0,xs=0.0,adouble,m1=0.1;
				for(j=0;S[p]!=';';j++)
				{
					if(S[p]=='.')
					{
						flag=1;p++;
						continue;
					}
					if(flag==0)
					{
						zs=zs*10+S[p]-'0';
					}
					else
					{
						xs+=m1*(S[p]-'0');
						m1*=0.1;
					}
					p++;
				}
				adouble=zs+xs;p++;
				for(j=0;S[p]!=';';j++)
				{
					teachername[j]=S[p];
					p++;
				}
				teachername[j]='\0';p++;
                wsprintf(szBuffer,TEXT("�������ͣ�����¼��ѧ��������Ϣ"));
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                wsprintf(szBuffer,TEXT("������Դ��%s��ʦ"),teachername);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
				if(fabs(adouble-1)<1e-5)
                {
                wsprintf(szBuffer,TEXT("�������ݣ�����Ϊ%sͬѧ¼�봦����Ϣ������Ϊ%s����������Ϊ����"),astu->stu.name,astr);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
				else if(fabs(adouble-2)<1e-5)
                {
                wsprintf(szBuffer,TEXT("�������ݣ�����Ϊ%sͬѧ¼�봦����Ϣ������Ϊ%s����������Ϊ���ؾ���"),astu->stu.name,astr);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
				else if(fabs(adouble-3)<1e-5)
                {
                wsprintf(szBuffer,TEXT("�������ݣ�����Ϊ%sͬѧ¼�봦����Ϣ������Ϊ%s����������Ϊ����"),astu->stu.name,astr);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
				else if(fabs(adouble-4)<1e-5)
                {
                wsprintf(szBuffer,TEXT("�������ݣ�����Ϊ%sͬѧ¼�봦����Ϣ������Ϊ%s����������Ϊ���ش���"),astu->stu.name,astr);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
				else if(fabs(adouble-5)<1e-5)
                {
                wsprintf(szBuffer,TEXT("�������ݣ�����Ϊ%sͬѧ¼�봦����Ϣ������Ϊ%s����������Ϊ��У�鿴"),astu->stu.name,astr);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
				else if(fabs(adouble-6)<1e-5)
                {
                wsprintf(szBuffer,TEXT("�������ݣ�����Ϊ%sͬѧ¼�봦����Ϣ������Ϊ%s����������ΪȰ��"),astu->stu.name,astr);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
			}
			else if(strcmp(ordername,"inputcourse")==0)
			{
				char astr1[100];
				for(j=0;S[p]!=';';j++)
				{
					astr1[j]=S[p];
					p++;
				}
				astr1[j]='\0';p++;
				char astr2[100];
				for(j=0;S[p]!=';';j++)
				{
					astr2[j]=S[p];
					p++;
				}
				astr2[j]='\0';p++;
				int anum=0;
				while(S[p]!=';')
				{
					if(S[p]>='0'&&S[p]<='9')
						anum=anum*10+S[p]-'0';
					p++;
				}
				p++;
				char astr3[100];
				for(j=0;S[p]!=';';j++)
				{
					astr3[j]=S[p];
					p++;
				}
				astr3[j]='\0';p++;
				int flag=0;
				double zs=0.0,xs=0.0,adouble,m1=0.1;
				for(j=0;S[p]!=';';j++)
				{
					if(S[p]=='.')
					{
						flag=1;p++;
						continue;
					}
					if(flag==0)
					{
						zs=zs*10+S[p]-'0';
					}
					else
					{
						xs+=m1*(S[p]-'0');
						m1*=0.1;
					}
					p++;
				}
				adouble=zs+xs;
				p++;
				for(j=0;S[p]!=';';j++)
				{
					teachername[j]=S[p];
					p++;
				}
				teachername[j]='\0';p++;
                wsprintf(szBuffer,TEXT("�������ͣ�����¼���¿γ���Ϣ"));
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                wsprintf(szBuffer,TEXT("������Դ��%s��ʦ"),teachername);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
				if(anum==0)
                {
                    wsprintf(szBuffer,TEXT("�������ݣ�����¼���¿γ̣��γ�����Ϊ%s,�γ����Ϊ%s,�γ�����Ϊ����"),astr1,astr2);
                    iTarget=lstrlen(szBuffer);
                    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
				else if(anum==1)
                {
                    wsprintf(szBuffer,TEXT("�������ݣ�����¼���¿γ̣��γ�����Ϊ%s,�γ����Ϊ%s,�γ�����Ϊѡ��"),astr1,astr2);
                    iTarget=lstrlen(szBuffer);
                    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
				else if(anum==2)
                {
                    wsprintf(szBuffer,TEXT("�������ݣ�����¼���¿γ̣��γ�����Ϊ%s,�γ����Ϊ%s,�γ�����Ϊ��ѡ"),astr1,astr2);
                    iTarget=lstrlen(szBuffer);
                    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
                }
                sprintf(szBuffer,TEXT("�ڿν�ʦΪ%s,�γ���ռѧ��Ϊ%lf"),astr3,adouble);
                iTarget=lstrlen(szBuffer);
                TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
			}
			else
			{
				printf("ERROR:%s\n",ordername);
			}
		}
	}
	return;
}

void dealwithch(apt* P,char ch)
{
	int hereflag;
		hereflag=1;
		char* S=P->str;
		int j,p=0;
		if(S[0]=='\n'||S[0]=='\r')return;
		char ordername[300];
		for(j=0;S[p]!=';';j++)
		{
			ordername[j]=S[p];
			p++;
		}
		ordername[j]='\0';p++;
		if(ch=='w'){P->status=0;}
		else if(ch=='a')
		{
			P->status=1;
			if(strcmp(ordername,"deletestu")==0)
			{
				char astuname[100];
				for(j=0;S[p]!=';';j++)
				{
					astuname[j]=S[p];
					p++;
				}
				astuname[j]='\0';p++;
				deletestudent(searchstu(astuname));
				FILE* fp=fopen(ORDER,"a+");
				fprintf(fp,"deletestu;%s;\n",astuname);
				fclose(fp);
			}
			else if(strcmp(ordername,"changescoreofastu")==0)
			{
				char astr[100];
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				stunode* astu=searchstu(astr);
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				clsnode* acls=searchcls(astr);
				int anum=0;
				while(S[p]!=';')
				{
					if(S[p]>='0'&&S[p]<='9')
						anum=anum*10+S[p]-'0';
					p++;
				}
				p++;
				int newscore=anum;
				anum=0;
				while(S[p]!=';')
				{
					if(S[p]>='0'&&S[p]<='9')
						anum=anum*10+S[p]-'0';
					p++;
				}
				p++;
				int isfirst=anum;
				changescoreofastu(astu,acls,newscore,isfirst);
				FILE* fp=fopen(ORDER,"a+");
				fprintf(fp,"changescoreofastu;%s;%s;%d;%d;\n",astu->stu.name,acls->clsif.name,newscore,isfirst);
				fclose(fp);
			}
			else if(strcmp(ordername,"enterhonor")==0)
			{
				char astr[100];
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				stunode* astu=searchstu(astr);
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				int flag=0;
				double zs=0.0,xs=0.0,adouble,m1=0.1;
				for(j=0;S[p]!=';';j++)
				{
					if(S[p]=='.')
					{
						flag=1;p++;
						continue;
					}
					if(flag==0)
					{
						zs=zs*10+S[p]-'0';
					}
					else
					{
						xs+=m1*(S[p]-'0');
						m1*=0.1;
					}
					p++;
				}
				adouble=zs+xs;p++;
				enterhonor(astu,astr,adouble);
				FILE* fp=fopen(ORDER,"a+");
				fprintf(fp,"enterhonor;%s;%s;%.2lf;\n",astu->stu.name,astr,adouble);
				fclose(fp);
			}
			else if(strcmp(ordername,"enterpunish")==0)
			{
				char astr[100];
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				stunode* astu=searchstu(astr);
				for(j=0;S[p]!=';';j++)
				{
					astr[j]=S[p];
					p++;
				}
				astr[j]='\0';p++;
				int flag=0;
				double zs=0.0,xs=0.0,adouble,m1=0.1;
				for(j=0;S[p]!=';';j++)
				{
					if(S[p]=='.')
					{
						flag=1;p++;
						continue;
					}
					if(flag==0)
					{
						zs=zs*10+S[p]-'0';
					}
					else
					{
						xs+=m1*(S[p]-'0');
						m1*=0.1;
					}
					p++;
				}
				adouble=zs+xs;p++;
				enterpunish(astu,astr,adouble);
				FILE* fp=fopen(ORDER,"a+");
				fprintf(fp,"enterpunish;%s;%s;%d;\n",astu->stu.name,astr,(int)(adouble));
				fclose(fp);
			}
			else if(strcmp(ordername,"inputcourse")==0)
			{
				char astr1[100];
				for(j=0;S[p]!=';';j++)
				{
					astr1[j]=S[p];
					p++;
				}
				astr1[j]='\0';p++;
				char astr2[100];
				for(j=0;S[p]!=';';j++)
				{
					astr2[j]=S[p];
					p++;
				}
				astr2[j]='\0';p++;
				int anum=0;
				while(S[p]!=';')
				{
					if(S[p]>='0'&&S[p]<='9')
						anum=anum*10+S[p]-'0';
					p++;
				}
				p++;
				char astr3[100];
				for(j=0;S[p]!=';';j++)
				{
					astr3[j]=S[p];
					p++;
				}
				astr3[j]='\0';p++;
				int flag=0;
				double zs=0.0,xs=0.0,adouble,m1=0.1;
				for(j=0;S[p]!=';';j++)
				{
					if(S[p]=='.')
					{
						flag=1;p++;
						continue;
					}
					if(flag==0)
					{
						zs=zs*10+S[p]-'0';
					}
					else
					{
						xs+=m1*(S[p]-'0');
						m1*=0.1;
					}
					p++;
				}
				adouble=zs+xs;
				inputcourse(astr1,astr2,anum,astr3,adouble);
				FILE* fp=fopen(ORDER,"a+");
				fprintf(fp,"inputcourse;%s;%s;%d;%s;%lf;\n",astr1,astr2,anum,astr3,adouble);
				fclose(fp);
			}
			else
			{
				;//ERROR
			}
		}
		else if(ch=='r')
		{
			P->status=2;
		}
}

#endif
