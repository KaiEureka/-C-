#ifndef __DIRECTSHOW
#define __DIRECTSHOW

void showstudent()
{
    stunode* p=stulih;
    while(p!=NULL)
    {
        student st=p->stu;
        wsprintf(szBuffer,TEXT("ѧ��������%s"),st.name);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("ѧ�ţ�%s"),st.id);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("�Ա�%d"),st.gender);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("רҵ��%s"),st.major);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("��Դ�أ�%s"),st.home);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("�༶��:%d"),st.Class);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        showgcofastu(p);
        cnty++;
        p=p->next;
    }
	return;
}

void showstudentscores()
{
    stunode* p=stulih;
    if(p->pre==NULL)p=p->next;
    wsprintf(szBuffer,TEXT("-----------------------------------------"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    while(p!=NULL)
    {
        student st=p->stu;
        wsprintf(szBuffer,TEXT("ѧ��������%s"),st.name);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("ѧ�ţ�%s"),st.id);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("רҵ:%s"),st.major);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        showhpofastu(p);
        showgcofastu(p);
        cnty+=2;
        showscoresofastu(p);
        cnty++;
        p=p->next;
    }
    wsprintf(szBuffer,TEXT("-----------------------------------"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
	return;
}

void showcls()
{
    clsnode *p=clslih;
    wsprintf(szBuffer,TEXT("---------------------------------------"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    while(p!=NULL)
    {
        cls st=p->clsif;
        wsprintf(szBuffer,TEXT("�γ����ƣ�%s"),st.name);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("�γ̱�ţ�%s"),st.id);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("�γ����ʣ�%d"),st.nature);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        sprintf(szBuffer,TEXT("ѧ�֣�%.1lf"),st.cdt);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("��ʦ��%s"),st.teacher);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        cnty++;
        p=p->next;
    }
    wsprintf(szBuffer,TEXT("---------------------------------------"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
	return;
}

void showgcofastu(stunode* stuuser)
{
	cptsg(stuuser);
    wsprintf(szBuffer,TEXT("�ɼ�����"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    sprintf(szBuffer,TEXT("�����޿γɼ�������:%.4lf     ����:%.4lf"),stuuser->stu.csco,stuuser->stu.cgpa);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    sprintf(szBuffer,TEXT("�����гɼ���  ����:%.4lf     ����:%.4lf"),stuuser->stu.ssco,stuuser->stu.sgpa);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    sprintf(szBuffer,TEXT("���ܳɼ���    ����:%.4lf     ����:%.4lf"),stuuser->stu.tsco,stuuser->stu.tgpa);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    sprintf(szBuffer,TEXT("��������ѧ���ܳɼ���    ����:%.4lf     ����:%.4lf"),stuuser->stu.osco,stuuser->stu.ogpa);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
	return;
}

void showhpofastu(stunode* stuuser)
{
    wsprintf(szBuffer,TEXT("ѧ����������"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    strnode* h=stuuser->stu.honorh;
    if(h->pre==NULL)h=h->next;
    if(h==NULL)printf("��\n");
    while(h!=NULL)
    {
        wsprintf(szBuffer,TEXT("�ӷ���Ŀ���ƣ�%s"),h->s);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        sprintf(szBuffer,TEXT("�ӷַ�ֵ��%lf"),h->inf);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        h=h->next;
    }
    cnty++;
    wsprintf(szBuffer,TEXT("ѧ�����񴦷�"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    h=stuuser->stu.punishh;
    if(h->pre==NULL)h=h->next;
    if(h==NULL)
    {
        wsprintf(szBuffer,TEXT("��"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    }
    while(h!=NULL)
    {
        wsprintf(szBuffer,TEXT("����Ե�ɣ�%s"),h->s);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        sprintf(szBuffer,TEXT("�ӷֵȼ���%lf"),h->inf);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        h=h->next;
    }
    cnty++;
	return;
}

void showscoresofastu(stunode* astu)
{
    cosnode* h=astu->stu.scoreh;
    if(astu->stu.scoreh->pre==NULL&&astu->stu.scoreh->next!=NULL)astu->stu.scoreh=astu->stu.scoreh->next;
    if(h==NULL||h!=NULL&&astu->stu.scoreh->pre==NULL)
    {
        wsprintf(szBuffer,TEXT("��ѧѧ��δ¼���κ�һ�ųɼ������޳ɼ���ʾ��"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        return;
    }
    while(h!=NULL)
    {
        wsprintf(szBuffer,TEXT("�γ����ƣ�%s"),h->cos.c->name);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("�γ̱�ţ�%s"),h->cos.c->id);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
		if(h->cos.c->nature==0)
        {
            wsprintf(szBuffer,TEXT("�γ����ʣ�����"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        }
		else if(h->cos.c->nature==1)
        {
            wsprintf(szBuffer,TEXT("�γ����ʣ�ѡ��"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        }
		else if(h->cos.c->nature==2)
        {
            wsprintf(szBuffer,TEXT("�γ����ʣ���ѡ"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        }
            wsprintf(szBuffer,TEXT("�ڿν�ʦ��%s"),h->cos.c->teacher);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
            sprintf(szBuffer,TEXT("ѧ�֣�%.1lf"),h->cos.c->cdt);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
		if(h->cos.first==1)
        {
            wsprintf(szBuffer,TEXT("�Ƿ�Ϊ���ޣ���"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        }
		else
        {
            wsprintf(szBuffer,TEXT("�Ƿ�Ϊ���ޣ���"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        }
            sprintf(szBuffer,TEXT("���㣺%.1lf"),h->cos.gp);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
		if(h->cos.c->nature!=1)
        {
            wsprintf(szBuffer,TEXT("�ɼ���%d"),h->cos.score);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        }
		else
		{
            wsprintf(szBuffer,TEXT("�ɼ���"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,0,cyChar*((cnty)-iVscrollPos),szBuffer,iTarget);
			showoptionalscore(h->cos.score);
            cnty++;
		}
        cnty++;
        h=h->next;
    }
	return;
}

#endif
