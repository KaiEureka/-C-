#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ID_BUTTON_LOGIN 1
#define ID_COMBOBOX_LOGIN_TYPE 2
#define IDC_EDIT_USERNAME 3
#define IDC_EDIT_PASSWORD 4

#define ID_BUTTON_VIEW_BASIC_INFO      101
#define ID_BUTTON_VIEW_ALL_COURSES     102
#define ID_BUTTON_QUERY_SUBJECT_SCORE  103
#define ID_BUTTON_QUERY_TOTAL_SCORE    104
#define ID_BUTTON_VIEW_RANKING         105
#define ID_BUTTON_CHANGE_PASSWORD      106
#define ID_BUTTON_EXIT_SYSTEM          107
#define ID_BUTTON_SEARCH               108

#define ID_BUTTON_TEA_VIEW_BASIC_INFO        1201
#define ID_BUTTON_TEA_VIEW_ALL_COURSES       1202
#define ID_BUTTON_TEA_QUERY_DETAILED_SCORE   1203
#define ID_BUTTON_TEA_VIEW_RANKING           1204
#define ID_BUTTON_TEA_ANALISE_COURSE         1205
#define ID_BUTTON_TEA_INPUT_SCORE            1206
#define ID_BUTTON_TEA_CHANGE_SCORE           1207
#define ID_BUTTON_TEA_INPUT_NEWCOURSE        1208
#define ID_BUTTON_TEA_DELETE_STUDENT         1209
#define ID_BUTTON_TEA_INPUT_HONOR            1210
#define ID_BUTTON_TEA_INPUT_PUNISH           1211
#define ID_BUTTON_TEA_CHANGE_PASSWORD        1212
#define ID_BUTTON_TEA_EXIT_SYSTEM            1213

#define ID_BUTTON_ROOT_VIEW_STUDENT_INFO        1301
#define ID_BUTTON_ROOT_VIEW_TEACHER_INFO        1302
#define ID_BUTTON_ROOT_VIEW_COURSES_INFO        1303
#define ID_BUTTON_ROOT_VIEW_DETAILED_SCORE      1304
#define ID_BUTTON_ROOT_VIEW_RANKING             1305
#define ID_BUTTON_ROOT_CHANGE_SCORE             1306
#define ID_BUTTON_ROOT_INPUT_NEWCOURSE          1307
#define ID_BUTTON_ROOT_INPUT_NEWTEACHER         1308
#define ID_BUTTON_ROOT_INPUT_NEWSTUDENT         1309
#define ID_BUTTON_ROOT_DELETE_STUDENT           1310
#define ID_BUTTON_ROOT_INPUT_HONOR              1311
#define ID_BUTTON_ROOT_INPUT_PUNISH             1312
#define ID_BUTTON_ROOT_ANALISE_COURSE           1313
#define ID_BUTTON_ROOT_INPUT_SCORE              1314
#define ID_BUTTON_ROOT_EXAMINE_APPLY            1315
#define ID_BUTTON_ROOT_CHANGE_PASSWORD          1316
#define ID_BUTTON_ROOT_EXIT_SYSTEM              1317

char ORDER[100]="./order.txt";
char EA[100]="./ea.txt";
char SCORE[100]="./scorelist.txt";
char CLS[100]="./clslist.txt";
char ROOT[100]="./rootlist.txt";
char TEA[100]="./teacherlist.txt";
char STU[100]="./stulist.txt";

int cntx,cnty,flag; 
char majornow[100],Bclass[100],str1;
int ordern,tos=1,req_1,req_2,Ayear,Aclass; 

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
static int cxChar,cxCaps,cyChar,cxCliect,cyClient,iVscrollPos;




#ifndef __STRUCTOFPJ
#define __STRUCTOFPJ

typedef struct applyment
{
    char str[1000];
    int status;//0 ����δ���� 1������׼ 2������
    struct applyment *next;
    struct applyment *pre;
}apt;
typedef struct strnode
{
    char s[200];
    double inf;//influnce of gpa
    struct strnode * next;
    struct strnode * pre;
}strnode;
typedef struct classitself
{
    char name[100];
    char id[20];//the id of class
    int nature;//0 is Compulsory course while 1 is optional course of study while 2 is optional compulsory courses
    char teacher[100];//teacher's name
    double cdt;
}cls;
typedef struct course
{
    cls* c;
    int first;//1 is first while 0 is re-study
    int score;
    double gp;
}course;
typedef struct cosnode
{
    course cos;
    struct cosnode* next;
    struct cosnode* pre;
}cosnode;
typedef struct clsnode
{
    cls clsif;
    struct clsnode* next;
    struct clsnode* pre;
}clsnode;
typedef struct student
{
    char name[20];
    char id[30];//student number
    int gender;//1 is male while 0 is female
    int year;//Year of enrollment
    int Class;
    double cgpa;
    double csco;
    double tgpa;
    double tsco;
    double sgpa;
    double ssco;
	double ogpa;
    double osco;
    char pwd[30];
    char home[20];//province of stu
    char major[100];
    cosnode *scoreh,*scoret;
    strnode *honorh,*honort;
    strnode *punishh,*punisht;
}student;
typedef struct stunode
{
    student stu;
    struct stunode* next;
    struct stunode* pre;
}stunode;
typedef struct nstunode                //Stuָ��ѧ�� Cosָ��ѧ��ѧϰ�����ſγ�
{
	int freenum;						//����һ�������� �����������Ȼ̫������QwQ 
    stunode *Stu;
    cosnode *Cos;
    struct nstunode *next;
    struct nstunode *pre;
}nstunode;
typedef struct teacher
{
	char name[50];
	char account[50];
	char pwd[50];
}teacher;
typedef struct teanode
{
	teacher tea;
	struct teanode* next;
	struct teanode* pre;
}teanode;
typedef struct root
{
	char name[50];
	char account[50];
	char pwd[50];
}root;
typedef struct rootnode
{
	root rt;
	struct rootnode* next;
	struct rootnode* pre;
}rootnode;

#endif



int aid,Tstu,i,j;//account id; teacher or student
char ch;
char str[10000];
stunode *stulih,*stulit;
cosnode *coslih,*coslit;
clsnode *clslih,*clslit;
teanode *tealih,*tealit;
rootnode *rootlih,*rootlit;
apt *aptlih=NULL;
stunode *stuuser,*astu;
teanode *teauser;
rootnode *rootuser;
apt *Q,*P;

#ifndef __DECLARATION
#define __DECLARATION

#ifndef MAXINPUT 
#define MAXINPUT 10000
#endif

extern char ORDER[100];
extern char EA[100];
extern char SCORE[100];
extern char CLS[100];
extern char ROOT[100];
extern char TEA[100];
extern char STU[100];
extern int aid,tos,Tstu,i,j;//account id; teacher or student
extern char ch,str[10000];
extern stunode *stulih,*stulit;
extern cosnode *coslih,*coslit;
extern clsnode *clslih,*clslit;
extern teanode *tealih,*tealit;
extern rootnode *rootlih,*rootlit;
extern apt *aptlih;
extern stunode *stuuser,*astu;
extern teanode *teauser;
extern rootnode *rootuser;
inline cosnode *sort_bycls(stunode *stunow);

double maxdouble(double x,double y);
void showscoresofastu(stunode* astu);
void cptsg(stunode *Stu);//����ѧ���ı��޿ξ��֡����޿ξ�����ѡ�޿ξ��֡�ѡ�޿ξ���
double cptgp(int sco);
stunode* searchstu(char* str);
stunode* searchstuid(char* str);
clsnode* searchcls(char* str);
void login();
void Initialization();
void InitializationOfSTU();
void InitializationOfTEA();
void InitializationOfCLS();
void InitializationOfORDER();
void InitializationOfROOT();
void InitializationOfSCORE();
void InitializationOfEA();
void inputscore(stunode* pstu,clsnode* pcls,int sc,double gp,int isfirst);
void showstudent();
void showteacher();
void showcls();
void showfunoftea();
void showfunofstu();
void showfunofroot();
void deletestudent(stunode* Stu);
void inputcourse(char Name[],char Id[],int Nature,char Teacher[],double Credit);
void showgcofastu(stunode* stuuser);
void changescoreofastu(stunode* astu,clsnode* acls,int newscore,int isfirst);
void analysetea();
void analysestu();
void analyseroot();
void changepwd();
void showstudentscores();
void enterhonor(stunode *Stu,char S[],double Inf);
void enterpunish(stunode *Stu,char S[],double Inf);
void showhpofastu(stunode* stuuser);
void survey_subject(clsnode *Cls);
int searchmajor(char* str);
void sort_three(int year,char majornow[],int ordern,int req_1,int req_2,int classre);
int searchyear(int wheyear);
inline int sort_three_cmp(int require,stunode *x,stunode *y,int ord);
void sort_free(stunode *xxx,nstunode *yyy,nstunode *zzz);
void sort_print1(int req1,int req2);
void sort_print2(stunode *stow,int studnum);
void inputstuascr(int choose);
void inputScore(cosnode *conn);
void createnewstu(char* aname,char* aid,int agender,char* amajor,int ayear,int aclass,char* apwd,char* ahome);
void showoptionalscore(int sco);
void changepwdofstu(stunode* stuuser,char* str);
void changemajorofstu(stunode* stuuser,char* str);
void changepwdoftea(teanode* teauser,char* str);
void changepwdofroot(rootnode* rootuser,char* str);
void changescoreofroot();
void inputcourseofroot();
void addstudentofroot(char aname[],char aid[],int agender,char amajor[],int ayear,int aclass,char apwd[],char ahome[]);
void deletestuofroot(char str[]);
void enterhonorofroot();
void enterpunishofroot();
void inputnewteacher(char tname[],char taccount[],char tpwd[]);
void examineofroot();
void inputcourseoftea();
void deletestuoftea(char str[]);
void enputhonoroftea();
void enterpunishoftea();
rootnode* searchroot(char* str);
teanode* searchtea(char* str);
void StudentWindow();
void ShowStuWindow();
void ChangeStuWindow();
void SearchGradeWindow();
void TeacherWindow();
void AdminWindow(); 
void ChangeTeaWindow();
void ChangeAdmWindow();
void AdmStuWindow();
void ClassAnalyWindow();
void AmdAppWindow();
void StuClassWindow();
void StuClassScoreWindow();
void StuAllScoreWindow();
void TeaShowStuWindow();
void AdmInStuWindow();
void AdmOutStuWindow();
void AdmInTeaWindow();
void AdmInCouWindow();
void ShowTeatoAdmWindow();
void ShowCostoAdmWindow();
void AdmEntpunWindow();
void ShowStutoAdmWindow();
void AdmEnthorWindow();
void AdmChangeScoreWindow();
void TeaInCouWindow();
void TeaEnthorWindow();
void TeaOutStuWindow();
void TeaEntpunWindow();
void TeaChangeScoreWindow();
void AdmEntStuorScoWindow(); 
void InputScoreWindow();
void AESorSSon1Window();
void AESorSSon2Window();
void AdmEntStuorScoWindow();

void dealwithch(apt* P,char ch);

//int max(int a,int b)
//{
//        return (((a)>(b))?(a):(b));
//}
//int min(int a,int b)  
//{
//        return (((a)<(b))?(a):(b));
//}

#endif

nstunode *nstulihh=NULL,*nstuinall=NULL;
cosnode *cosnowinall;
stunode *stunowinall;
clsnode *clstobe;
int emptynum=0;
int flaginson2=0;

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

//¼�����ҳ�� 
LRESULT CALLBACK InputScoreProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
    int i=0;
    int NUMLINES=20;
    if(msg==WM_COMMAND)
	{
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            char gradenow[100];
            GetWindowTextA(g_hEditGrade, gradenow, sizeof(gradenow));
			int naturenow=SendMessage(g_hComboBoxpaiming3Type, CB_GETCURSEL, 0, 0);
			
			int i=0,flagnow=0,len=strlen(gradenow),gradere,flagnow1=0;
			if(cosnowinall->cos.c->nature!=1)
			{
				for(i=0;i<len;i++)
				{
					flagnow1=1;
					if(gradenow[i]<'0'||gradenow[i]>'9')
					{
						flagnow=1;
						break;
					}
					gradere=gradere*10+gradenow[i]-'0';
				}
				if(naturenow!=-1)
				{
					MessageBox(NULL,TEXT("�ÿγ̲���ѡ�޿Σ�����ѡ��λ"),TEXT("��ʾ"),MB_OK);
				}
				if(flagnow==1||flagnow1==0||gradere<0||gradere>100)
				{
					MessageBox(NULL,TEXT("�����쳣������������"),TEXT("����"),MB_OK);
					return 0;
				}
				
				if(MessageBox(NULL,TEXT("��ȷ���Ƿ�¼��óɼ�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
				{
					flaginson2=1;
                    cosnowinall->cos.score=gradere;
                    cosnowinall->cos.gp=cptgp(gradere);
                    MessageBox(NULL,TEXT("�ɼ�¼���޸ĳɹ�"),TEXT("��ʾ"),MB_OK);
                    FILE* fp=fopen(ORDER,"a+");
                    fprintf(fp,"changescoreofastu;%s;%s;%d;%d;\n",stunowinall->stu.name,clstobe->clsif.name,gradere,cosnowinall->cos.first);
                    fclose(fp);
                    return 0;
				}
			}
			else
			{
				if(naturenow==-1)
				{
					MessageBox(NULL,TEXT("��ѡ��λ"),TEXT("����"),MB_OK);
					return 0;
				}
				if(naturenow==0)gradere=95;
				else if(naturenow==1)gradere=85;
				else if(naturenow==2)gradere=75;
				else if(naturenow==3)gradere=60;
				else if(naturenow==4)gradere=45;
				if(naturenow!=-1)
				{
					MessageBox(NULL,TEXT("�ÿγ���ѡ�޿Σ���������ɼ�"),TEXT("��ʾ"),MB_OK);
				}
				if(MessageBox(NULL,TEXT("��ȷ���Ƿ�¼��óɼ�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
                {
                    cosnowinall->cos.score=gradere;
                    cosnowinall->cos.gp=cptgp(gradere);
                    MessageBox(NULL,TEXT("�ɼ�¼���޸ĳɹ�"),TEXT("��ʾ"),MB_OK);
                    FILE* fp=fopen(ORDER,"a+");
                    fprintf(fp,"changescoreofastu;%s;%s;%d;%d;\n",stunowinall->stu.name,clstobe->clsif.name,gradere,cosnowinall->cos.first);
                    fclose(fp);
                    return 0;
				}
			}
        }
        if(LOWORD(wParam)==ID_BUTTON_ROOT_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("InputScoreWin", GetModuleHandle(NULL));
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

        CreateWindow(TEXT("STATIC"), TEXT("����ɼ�(���ÿγ�Ϊ���޻���ѡ)��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            10, 50, 110, 40,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("ѡ��λ(���ÿγ�Ϊѡ��)��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            10, 100, 110, 40,hwnd, NULL, NULL, NULL);

        g_hEditGrade = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 50, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);
            
            
        g_hComboBoxpaiming3Type = CreateWindow(
        TEXT("COMBOBOX"), TEXT(""),
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        150, 100, 200, 200,
        hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);

        SendMessage(g_hComboBoxpaiming3Type, CB_ADDSTRING, 0, (LPARAM)TEXT("A"));
        SendMessage(g_hComboBoxpaiming3Type, CB_ADDSTRING, 0, (LPARAM)TEXT("B"));
        SendMessage(g_hComboBoxpaiming3Type, CB_ADDSTRING, 0, (LPARAM)TEXT("C"));
        SendMessage(g_hComboBoxpaiming3Type, CB_ADDSTRING, 0, (LPARAM)TEXT("D"));
        SendMessage(g_hComboBoxpaiming3Type, CB_ADDSTRING, 0, (LPARAM)TEXT("E"));
        
        CreateWindow(TEXT("BUTTON"), TEXT("ȷ��¼��"),WS_VISIBLE | WS_CHILD,
            110, 150, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN  , NULL, NULL);

    }
    if(msg==WM_CLOSE)
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("InputScoreWin", GetModuleHandle(NULL));
        }
        else return 0;

    if(msg==WM_DESTROY)
    {
        PostQuitMessage(0);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//����¼����ҳ��һ 
LRESULT CALLBACK AESorSSon1Proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_COMMAND:
            if(LOWORD(wParam)==ID_BUTTON_LOGIN) 
            {
                char stuname[100];
                GetWindowTextA(g_hEditStuname, stuname, sizeof(stuname));
				int choosenow = SendMessage(g_hComboBoxpaiming1Type, CB_GETCURSEL, 0, 0);
				if(choosenow==-1)
                {
                    MessageBox(NULL,TEXT("����ѡ�����"),TEXT("��ʾ"),MB_OK);
                    return 0;
                }
                stunode *Astu;
				Astu=searchstu(stuname);
				if(Astu==NULL)
                {
                    MessageBox(NULL,TEXT("δ�鵽��ѧ��������������"),TEXT("��ʾ"),MB_OK);
                    return 0;
                }
                if(Astu->stu.scoreh->pre==NULL&&Astu->stu.scoreh->next!=NULL)
                Astu->stu.scoreh=Astu->stu.scoreh->next;
                cosnode *cosnow=Astu->stu.scoret;
                while(cosnow!=NULL&&cosnow->pre!=NULL)
                {
                    if(strcmp(cosnow->cos.c->name,clstobe->clsif.name)==0)
                    {
                        if(choosenow==0)
                        {
                            if(cosnow->cos.score==-1)
                            {
                                MessageBox(NULL,TEXT("��ѧ����¼��ÿγ�,�ҳɼ�δ¼��,�����Ƿ�"),TEXT("��ʾ"),MB_OK);
                                return 0;
                            }
                            if(MessageBox(NULL,TEXT("��ѧ���Ƿ��ٴ����޸ÿγ�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
                            {
                                MessageBox(NULL,TEXT("¼��ɹ�,�������޶����ÿγ̣�ѧϰ������Ϊ����"),TEXT("��ʾ"),MB_OK);
                                cosnode *tmp1=(struct cosnode*)malloc(sizeof(struct cosnode));
                                tmp1->cos.c=&(clstobe->clsif);tmp1->pre=Astu->stu.scoret;tmp1->next=NULL;
                                tmp1->cos.first=0;tmp1->cos.score=-1;tmp1->cos.gp=-1;
                                Astu->stu.scoret->next=tmp1;
                                Astu->stu.scoret=tmp1;
                                FILE* fp=fopen(ORDER,"a+");
                                fprintf(fp,"inputscore;%s;%s;%d;%.4lf;%d;\n",Astu->stu.name,clstobe->clsif.name,-1,-1.0,0);
                                fclose(fp);
                                if(Astu->stu.scoreh->pre==NULL&&Astu->stu.scoret->next!=NULL)
                                Astu->stu.scoreh=Astu->stu.scoreh->next;
                            }
                            return 0;
                        }
                        else
                        {
                            if(cosnow->cos.score!=-1)
                            {
                                MessageBox(NULL,TEXT("��ѧ���ÿƳɼ���¼��,�����Ƿ�"),TEXT("��ʾ"),MB_OK);
                                return 0;
                            }
							if(MessageBox(NULL,TEXT("�Ƿ�Ϊ��ѧ��¼��ÿγ̵ĳɼ�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
							{
								stunowinall=Astu;
								cosnowinall=cosnow;
								InputScoreWindow();
							}
                            return 0;
						}
                    }
                    cosnow=cosnow->pre;
                }
                if(choosenow==1)
                {
                    MessageBox(NULL,TEXT("��ѧ��δ¼��ÿγ̻�ɼ���ȫ��¼��,�����Ƿ�"),TEXT("��ʾ"),MB_OK);
                    return 0;
                }
                else
                {
                    if(MessageBox(NULL,TEXT("�Ƿ�Ϊ��ѧ��¼��ÿγ�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
                    {
                        MessageBox(NULL,TEXT("¼��ɹ�,���Ǹ�����һ���޶��ÿγ�,ѧϰ����Ĭ����Ϊ����"),TEXT("��ʾ"),MB_OK);
                        cosnode *tmp1=(struct cosnode*)malloc(sizeof(struct cosnode));
                        tmp1->cos.c=&(clstobe->clsif);tmp1->pre=Astu->stu.scoret;tmp1->next=NULL;
                        tmp1->cos.first=0;tmp1->cos.score=-1;tmp1->cos.gp=-1;
                        Astu->stu.scoret->next=tmp1;
                        Astu->stu.scoret=tmp1;
                        FILE* fp=fopen(ORDER,"a+");
                        fprintf(fp,"inputscore;%s;%s;%d;%.4lf;%d;\n",Astu->stu.name,clstobe->clsif.name,-1,-1,0);
                        fclose(fp);
                        if(Astu->stu.scoreh->pre==NULL&&Astu->stu.scoret->next!=NULL)
                        Astu->stu.scoreh=Astu->stu.scoreh->next;
                    }
                    return 0;
                }
                break;
			}
            else if(LOWORD(wParam)==ID_BUTTON_ROOT_EXIT_SYSTEM)
            {
                DestroyWindow(hwnd);
                UnregisterClass("AESorSSon1Win", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_CREATE:
            CreateWindow(TEXT("STATIC"), TEXT("ѧ�����ƣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                20, 70, 80, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("ѡ��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
				20, 110, 80, 20,hwnd, NULL, NULL, NULL);
                
            g_hEditStuname = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                120, 70, 240, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

            g_hComboBoxpaiming1Type = CreateWindow(
                TEXT("COMBOBOX"), TEXT(""),
                WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
                120, 110, 240, 200,
                hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);
        
            SendMessage(g_hComboBoxpaiming1Type, CB_ADDSTRING, 0, (LPARAM)TEXT("Ϊ��ѧ����¼����ſγ�"));
            SendMessage(g_hComboBoxpaiming1Type, CB_ADDSTRING, 0, (LPARAM)TEXT("Ϊ��ѧ��¼��ÿγ̵����³ɼ�"));

            CreateWindow(TEXT("BUTTON"), TEXT("ȷ��"),WS_VISIBLE | WS_CHILD,
                100, 140, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

            break;

        case  WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("AESorSSon1Win", GetModuleHandle(NULL));
            }
            else return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//����¼����ҳ��� 
LRESULT CALLBACK AESorSSon2Proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int i=0;
	int NUMLINES=20;
    if(msg==WM_COMMAND)
    {
        if(LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            int choosenow=SendMessage(g_hComboBoxpaiming0Type, CB_GETCURSEL, 0, 0);
            if(choosenow==-1)
            {
                MessageBox(NULL,TEXT("��ѡ�����"),TEXT("��ʾ"),MB_OK);
                return 0;
            }
            if(choosenow==0)
            {
                nstuinall=nstuinall->next;
                if(nstuinall==NULL)
                {
                    MessageBox(NULL,TEXT("��չʾ������δ¼��ɼ���ѧ�����Զ��˳�"),TEXT("��ʾ"),MB_OK);
                    DestroyWindow(hwnd);
                    UnregisterClass("AESorSSon2Win", GetModuleHandle(NULL));
                }
                InvalidateRect(hwnd,NULL,TRUE);
                UpdateWindow(hwnd);
                return 0;
            }
            else
            {
                cosnowinall=nstuinall->Cos;
                stunowinall=nstuinall->Stu;
                InputScoreWindow();
                if(flaginson2==1)
                {	
                    emptynum-=1;
                    nstuinall=nstuinall->next;
                    flaginson2=0;
                }
                if(nstuinall==NULL)
                {
                    MessageBox(NULL,TEXT("��չʾ������δ¼��ɼ���ѧ�����Զ��˳�"),TEXT("��ʾ"),MB_OK);
                    DestroyWindow(hwnd);
                    UnregisterClass("AESorSSon2Win", GetModuleHandle(NULL));
                }
				InvalidateRect(hwnd,NULL,TRUE);
                UpdateWindow(hwnd);
                return 0;
			}
		}
        else if(LOWORD(wParam)==ID_BUTTON_ROOT_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AESorSSon2Win", GetModuleHandle(NULL));
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

		CreateWindow(TEXT("STATIC"), TEXT("ѡ��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
			40, 110, 50, 20,hwnd, NULL, NULL, NULL);

        g_hComboBoxpaiming0Type = CreateWindow(
            TEXT("COMBOBOX"), TEXT(""),
            WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
            110, 110, 200, 200,
            hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);
    
        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("����"));
        SendMessage(g_hComboBoxpaiming0Type, CB_ADDSTRING, 0, (LPARAM)TEXT("����¼�����"));

        CreateWindow(TEXT("BUTTON"), TEXT("ȷ��ѡ��"),WS_VISIBLE | WS_CHILD,
            100, 150, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);
            return 0; 
	}
	if(msg==WM_PAINT)
    {
        hdc = BeginPaint(hwnd, &ps); 

        wsprintf(szBuffer,TEXT("�ÿγ̵�ǰ�� %d ��ѧ��δ¼��ɼ�"),emptynum);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
        
        wsprintf(szBuffer,TEXT("��ǰ��Ҫ¼��ɼ���ѧ��������ѧ�ţ�"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
        
        wsprintf(szBuffer,TEXT("%s  %s"),nstuinall->Stu->stu.name,nstuinall->Stu->stu.id);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
        
        EndPaint(hwnd, &ps);
		return 0;
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
    if(msg==WM_CLOSE)
	{
		if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AESorSSon2Win", GetModuleHandle(NULL));
        }
        else return 0;
    }
	if(msg==WM_DESTROY)
	{
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//����¼����ҳ�� 
LRESULT CALLBACK AdmEntStuorScoProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int NUMLINES=20;
    switch (msg)
    {
        case WM_COMMAND:
            if(LOWORD(wParam)==ID_BUTTON_LOGIN) 
            {
                char coursenow[1000];
                GetWindowTextA(g_hEditCourse, coursenow, sizeof(coursenow));
				int choosenow = SendMessage(g_hComboBoxpaiming2Type, CB_GETCURSEL, 0, 0);
				
				clsnode *Acls;
				Acls=searchcls(coursenow);

                if(Acls==NULL)
                {
                    MessageBox(NULL,TEXT("δ�ҵ����ſγ̣�����¼��ÿγ�"),TEXT("��ʾ"),MB_OK);
                    return 0;
                }
                if(choosenow==-1)
                {
                    MessageBox(NULL,TEXT("��ѡ��¼�뷽ʽ"),TEXT("��ʾ"),MB_OK);
                    return 0;
                }
                clstobe=Acls;
                
                if(tos==0&&strcmp(teauser->tea.name,clstobe->clsif.teacher)!=0)
                {
                    MessageBox(NULL,TEXT("�ÿγ̵��ڿν�ʦ������������Ȩ����!"),TEXT("��ʾ"),MB_OK);
                    return 0;
                }
                inputstuascr(choosenow);
                return 0; 
			}
            else if(LOWORD(wParam)==ID_BUTTON_ROOT_EXIT_SYSTEM)
            {
                DestroyWindow(hwnd);
                UnregisterClass("AdmEntStuorScoWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_CREATE:
            CreateWindow(TEXT("STATIC"), TEXT("�γ����ƣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
                50, 70, 80, 20,hwnd, NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("ѡ��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
				50, 110, 80, 20,hwnd, NULL, NULL, NULL);
				
            g_hEditCourse = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                150, 70, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

            g_hComboBoxpaiming2Type = CreateWindow(
                TEXT("COMBOBOX"), TEXT(""),
                WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
                150, 110, 200, 200,
                hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);
        
            SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("����¼��"));
            SendMessage(g_hComboBoxpaiming2Type, CB_ADDSTRING, 0, (LPARAM)TEXT("һ��¼��ɼ�"));

            CreateWindow(TEXT("BUTTON"), TEXT("����"),WS_VISIBLE | WS_CHILD,
                130, 140, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

            break;

        case  WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("AdmEntStuorScoWin", GetModuleHandle(NULL));
            }
            else return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
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

//����Ա�޸�ѧ���ɼ� 
LRESULT CALLBACK AdmChangeScoreProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
			MessageBox(NULL,TEXT("�ɼ��޸ĳɹ�"),TEXT("��ʾ"),MB_OK);
			FILE* fp=fopen(ORDER,"a+");
			fprintf(fp,"changescoreofastu;%s;%s;%d;%d;\n",Astu->stu.name,Acls->clsif.name,gradere,naturenow);
			fclose(fp);
			changescoreofastu(Astu,Acls,gradere,naturenow);
        }
        if(LOWORD(wParam)==ID_BUTTON_ROOT_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AdmChangeScoreWin", GetModuleHandle(NULL));
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
	        UnregisterClass("AdmChangeScoreWin", GetModuleHandle(NULL));
	    }
		else return 0;

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

//����Ա¼��ӷ��� 
LRESULT CALLBACK AdmEnthorProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
                    	if(MessageBox(NULL,TEXT("�Ƿ�Ϊ��ѧ��¼��üӷ���"),TEXT("��ʾ"),MB_YESNO)==IDYES)
                    	{
                    		MessageBox(NULL,TEXT("���ۺ����ʼӷ���¼��ɹ�"),TEXT("��ʾ"),MB_OK);
	                        FILE* fp=fopen(ORDER,"a+");
							fprintf(fp,"enterhonor;%s;%s;%.2lf;\n",Astu->stu.name,eventnow,sc);
							fclose(fp);
							enterhonor(Astu,eventnow,sc);
						}
                    }
                    else MessageBox(NULL,TEXT("¼�����������������ȷ����ֵ��"),TEXT("����"),MB_ICONERROR);
                }
                else MessageBox(NULL,TEXT("ѧ�������ڣ�����������"),TEXT("����"),MB_ICONERROR);
                break;

            case ID_BUTTON_ROOT_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("AdmEnthorWin", GetModuleHandle(NULL));
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
		        UnregisterClass("AdmEnthorWin", GetModuleHandle(NULL));
		    }
	    	else return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

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

//�����Աչʾѧ��������Ϣ 
LRESULT CALLBACK ShowStutoAdmProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    int i=0;
    int NUMLINES=120;
    if(msg==WM_COMMAND)
    {
        if((LOWORD(wParam))==ID_BUTTON_ROOT_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("ShowStutoAdmWin", GetModuleHandle(NULL));
        }
        return 0;
    }
    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("ShowStutoAdmWin", GetModuleHandle(NULL));
        }
        else return 0;
    }
    if(msg==WM_DESTROY)
    {
        PostQuitMessage(0);
        return 0;
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
        return 0;
    }
    if(msg==WM_PAINT)
    {
        hdc = BeginPaint(hwnd, &ps); 
        stunode *pnow;
        pnow=stulih;
        wsprintf(szBuffer,TEXT("--------------------------------------------------------------------------------------"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
        
		while(pnow!=NULL)
		{
			student st=pnow->stu; 
            wsprintf(szBuffer,TEXT("ѧ��������%s"),st.name);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
            char gendernow[3];
            if(st.gender==1)strcpy(gendernow,"��");
            else  strcpy(gendernow,"Ů");
            wsprintf(szBuffer,TEXT("ѧ�ţ�%s �Ա�%s רҵ��%s"),st.id,gendernow,st.major);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
            wsprintf(szBuffer,TEXT("��Դ�أ�%s �༶�ţ�%d"),st.home,st.Class);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
            wsprintf(szBuffer,TEXT("--------------------------------------------------------------------------------------"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
            pnow=pnow->next;
        }
        i=0;
		EndPaint(hwnd, &ps);
		return 0;
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
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//����Ա¼��ͷ�
LRESULT CALLBACK AdmEntpunProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
                	if(MessageBox(NULL,TEXT("�Ƿ�Ϊ��ѧ��¼��ô���"),TEXT("��ʾ"),MB_YESNO)==IDYES)
                    {
                		MessageBox(NULL,TEXT("����¼��ɹ�"),TEXT("��ʾ"),MB_OK);
                    	FILE* fp=fopen(ORDER,"a+");
						fprintf(fp,"enterpunish;%s;%s;%d;\n",Astu->stu.name,eventnow,PunishTypeIndex+1);
						fclose(fp);
						enterpunish(Astu,stuname,PunishTypeIndex+1);
					}
                }
                else MessageBox(NULL,TEXT("ѧ�������ڣ�����������"),TEXT("����"),MB_ICONERROR);
                break;
			}
            else if(LOWORD(wParam)==ID_BUTTON_ROOT_EXIT_SYSTEM)
            {
                DestroyWindow(hwnd);
                UnregisterClass("AdmEntpunWin", GetModuleHandle(NULL));
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

            // �������������
            g_hEditStuname = CreateWindow(TEXT("EDIT"), TEXT(""),
                WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                200, 70, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

            // ���������������
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

            // �����޸İ�ť
            CreateWindow(TEXT("BUTTON"), TEXT("ȷ�����"),WS_VISIBLE | WS_CHILD,
                130, 225, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

            break;

        case  WM_CLOSE: 
	        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
		    {
		        DestroyWindow(hwnd);
		        UnregisterClass("AdmEntpunWin", GetModuleHandle(NULL));
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

//����Աչʾ��ʦ������Ϣ
LRESULT CALLBACK ShowTeatoAdmProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    int i=0;
    int NUMLINES=50;
    if(msg==WM_COMMAND)
    {
   		if((LOWORD(wParam))==ID_BUTTON_ROOT_EXIT_SYSTEM)
        {
			DestroyWindow(hwnd);
        	UnregisterClass("ShowTeatoAdmWin", GetModuleHandle(NULL));
        }
        return 0;
    }
    if(msg==WM_CLOSE)
	{
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
	    {
	        DestroyWindow(hwnd);
	        UnregisterClass("ShowTeatoAdmWin", GetModuleHandle(NULL));
	    }
	    else return 0;
	}
    if(msg==WM_DESTROY)
    {
    	PostQuitMessage(0);
        return 0;
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
	    return 0;
	}
    if(msg==WM_PAINT)
    {
    	hdc = BeginPaint(hwnd, &ps); 
        teanode *pnow;
		pnow=tealih;
        wsprintf(szBuffer,TEXT("--------------------------------------------------------------------------------------"));
    	iTarget=lstrlen(szBuffer);
    	TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
    	
		while(pnow!=NULL)
		{
	        wsprintf(szBuffer,TEXT("��ʦ������%s"),pnow->tea.name);
	        iTarget=lstrlen(szBuffer);
	        TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
	        wsprintf(szBuffer,TEXT("��ʦ�˻���%s"),pnow->tea.account);
	        iTarget=lstrlen(szBuffer);
	        TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
	        wsprintf(szBuffer,TEXT("��ʦ���룺%s"),pnow->tea.pwd);
	        iTarget=lstrlen(szBuffer);
	        TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
	        wsprintf(szBuffer,TEXT("--------------------------------------------------------------------------------------"));
    		iTarget=lstrlen(szBuffer);
    		TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
	        pnow=pnow->next;
		}
    	i=0;
		EndPaint(hwnd, &ps);
		return 0;
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
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//����Աչʾ�γ̻�����Ϣ
LRESULT CALLBACK ShowCostoAdmProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    int i=0;
    int NUMLINES=120;
    if(msg==WM_COMMAND)
    {
        if((LOWORD(wParam))==ID_BUTTON_ROOT_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("ShowCostoAdmWin", GetModuleHandle(NULL));
        }
        return 0;
    }
    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("ShowCostoAdmWin", GetModuleHandle(NULL));
        }
        else return 0;
    }
    if(msg==WM_DESTROY)
    {
        PostQuitMessage(0);
        return 0;
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
        return 0;
    }
    if(msg==WM_PAINT)
    {
        hdc = BeginPaint(hwnd, &ps); 
        clsnode *p=clslih;
        wsprintf(szBuffer,TEXT("--------------------------------------------------------------------------------------"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);

        while(p!=NULL)
        {
            cls st=p->clsif;
            wsprintf(szBuffer,TEXT("�γ����ƣ�%s  ��ʦ��%s"),st.name,st.teacher);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
            char naturenow[6];
            if(st.nature==0)strcpy(naturenow,"����");
            else  if(st.nature==1)strcpy(naturenow,"ѡ��");
            else  strcpy(naturenow,"��ѡ");
            wsprintf(szBuffer,TEXT("�γ����ʣ�%s �γ̱�ţ�%s"),naturenow,st.id);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
            sprintf(szBuffer,TEXT("ѧ�֣�%.1lf"),st.cdt);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
            wsprintf(szBuffer,TEXT("--------------------------------------------------------------------------------------"));
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,cxChar,cyChar*((i++)-iVscrollPos),szBuffer,iTarget);
            p=p->next;
        }
        i=0;
        EndPaint(hwnd, &ps);
        return 0;
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
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//����Ա¼��γ�
LRESULT CALLBACK AdmInCouProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if(msg==WM_COMMAND){
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            int nature=SendMessage(g_hEditUsergender,CB_GETCURSEL, 0, 0);
            char tea[20],name[50],id[20],credit[20];
            GetWindowTextA(g_hEditUseryear, credit, sizeof(credit));
            GetWindowTextA(g_hEditUsermajor, tea, sizeof(tea));
            GetWindowTextA(g_hEditUsername1, name, sizeof(name));
            GetWindowTextA(g_hEditUserid1, id, sizeof(id));
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
            
            if(MessageBox(NULL,TEXT("�Ƿ�¼��ÿγ�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
			{
                inputcourse(name,id,nature,tea,Acredit);
                FILE* fp=fopen(ORDER,"a+");
                fprintf(fp,"inputcourse;%s;%s;%d;%s;%lf;\n",name,id,nature,tea,Acredit);
                fclose(fp);
            	MessageBox(NULL,TEXT("�γ�¼��ɹ�"),TEXT("ͨ��"),MB_OK);
			}
        }
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AdmInCouWin", GetModuleHandle(NULL));
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

        g_hEditUserid1 = CreateWindow(TEXT("EDIT"), TEXT(""),
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
            UnregisterClass("AdmInCouWin", GetModuleHandle(NULL));
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

//����Ա¼��ѧ��
LRESULT CALLBACK AdmInStuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if(msg==WM_COMMAND){
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            int gender=SendMessage(g_hEditUsergender,CB_GETCURSEL, 0, 0);
            char year[20],classnow[20],name[20],id[20],major[50],pwd[20],home[20];
            int Ayear=0,Aclass=0;
            GetWindowTextA(g_hEditUseryear, year, sizeof(year));
            GetWindowTextA(g_hEditUserclass, classnow, sizeof(classnow));
            GetWindowTextA(g_hEditUsername1, name, sizeof(name));
            GetWindowTextA(g_hEditUserid1, id, sizeof(id));
            GetWindowTextA(g_hEditUsermajor, major, sizeof(major));
            GetWindowTextA(g_hEditUserpwd1, pwd, sizeof(pwd));
            GetWindowTextA(g_hEditUserhome, home, sizeof(home));
            
            if(strlen(year)==0||strlen(classnow)==0||strlen(name)==0||strlen(id)==0||strlen(major)==0||strlen(pwd)==0||strlen(home)==0||gender==-1)
            {
            	MessageBox(NULL,TEXT("�������ݲ�����"),TEXT("����"),MB_OK);
                return 0;
			}
            int len=strlen(year);
            int i; 
            for(i=0;i<len;++i)
    		{
    			
    			if(year[i]<'0'||year[i]>'9')
    			{
    				MessageBox(NULL,TEXT("��ѧ����쳣"),TEXT("����"),MB_OK);
					return 0; 
				}
				Ayear=Ayear*10+(year[i]-'0');
			}
			if(Ayear<1900||Ayear>2300)
    		{
    			MessageBox(NULL,TEXT("��ѧ����쳣���������ʵ����"),TEXT("��ʾ"),MB_OK);
				return 0; 
			}
			len=strlen(classnow);
			for(i=0;i<len;++i)
    		{
    			
    			if(classnow[i]<'0'||classnow[i]>'9')
    			{
    				MessageBox(NULL,TEXT("�༶�쳣"),TEXT("����"),MB_OK);
					return 0; 
				}
				Aclass=Aclass*10+(classnow[i]-'0');
			}
			stunode *stunow1=stulih;
			while(stunow1!=NULL)
			{
				if(strcmp(stunow1->stu.id,id)==0)
				{
					MessageBox(NULL,TEXT("������ͬѧ�ŵ�ͬѧ����ȷ��ѧ��"),TEXT("����"),MB_OK);
					return 0;
				}
				stunow1=stunow1->next;
			}
			if(MessageBox(NULL,TEXT("�Ƿ�¼���ѧ��"),TEXT("��ʾ"),MB_YESNO)==IDYES)
			{
				addstudentofroot(name,id,gender,major,Ayear,Aclass,pwd,home);
	            MessageBox(NULL,TEXT("ѧ��¼��ɹ�"),TEXT("ͨ��"),MB_OK);
			}
        }
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AdmInStuWin", GetModuleHandle(NULL));
            return 0;
        }
    }

    if(msg==WM_CREATE)
    {
        CreateWindow(TEXT("STATIC"), TEXT("������"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 75, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("ѧ�ţ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 120, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�Ա�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 165, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("רҵ��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 210, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("��ѧ��ݣ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            380, 75, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�༶��"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            380, 120, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("���룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            380, 165, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("��Դ�أ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            380, 210, 80, 20,hwnd, NULL, NULL, NULL);

        g_hEditUsername1 = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
            150, 75, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

        g_hEditUserid1 = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 120, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditUsermajor = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 210, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditUseryear = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            480, 75, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditUserclass = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            480, 120, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditUserpwd1 = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            480, 165, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditUserhome = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            480, 210, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("ִ�в���"),WS_VISIBLE | WS_CHILD,
            300, 250, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN  , NULL, NULL);

        g_hEditUsergender = CreateWindow(
        TEXT("COMBOBOX"), TEXT(""),
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        150, 165, 200, 200,
        hwnd, (HMENU)ID_COMBOBOX_LOGIN_TYPE, NULL, NULL);

        SendMessage(g_hEditUsergender, CB_ADDSTRING, 0, (LPARAM)TEXT("Ů"));
        SendMessage(g_hEditUsergender, CB_ADDSTRING, 0, (LPARAM)TEXT("��"));

    }

    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AdmInStuWin", GetModuleHandle(NULL));
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

//����Ա¼����ʦ
LRESULT CALLBACK AdmInTeaProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if(msg==WM_COMMAND){
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            char name[20],id[50],pwd[20];
            GetWindowTextA(g_hEditUsername1, name, sizeof(name));
            GetWindowTextA(g_hEditUserid1, id, sizeof(id));
            GetWindowTextA(g_hEditUserpwd1, pwd, sizeof(pwd));
            if(strlen(name)==0||strlen(id)==0||strlen(pwd)==0)
            {
            	MessageBox(NULL,TEXT("�������ݲ�����"),TEXT("����"),MB_OK);
                return 0;
			}
            teanode *teanow1=tealih;
			while(teanow1!=NULL)
			{
				if(strcmp(teanow1->tea.account,id)==0)
				{
					MessageBox(NULL,TEXT("������ͬ�˺ŵĽ�ʦ�������������˺�"),TEXT("����"),MB_OK);
					return 0;
				}
				teanow1=teanow1->next;
			}
            if(MessageBox(NULL,TEXT("�Ƿ�¼�����ʦ"),TEXT("��ʾ"),MB_YESNO)==IDYES)
		    {
				inputnewteacher(name,id,pwd);
            	MessageBox(NULL,TEXT("¼����ʦ�ɹ�"),TEXT("ͨ��"),MB_OK);
            	return 0;
        	}
        }
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AdmInTeaWin", GetModuleHandle(NULL));
            return 0;
        }
    }

    if(msg==WM_CREATE)
    {
        CreateWindow(TEXT("STATIC"), TEXT("������"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 75, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("�˺ţ�"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 120, 80, 20,hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("���룺"),WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 165, 80, 20,hwnd, NULL, NULL, NULL);

        g_hEditUsername1 = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
            150, 75, 200, 20,hwnd, (HMENU)IDC_EDIT_USERNAME, NULL, NULL);

        g_hEditUserid1 = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 120, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        g_hEditUserpwd1 = CreateWindow(TEXT("EDIT"), TEXT(""),
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL ,
            150, 165, 200, 20,hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("ִ�в���"),WS_VISIBLE | WS_CHILD,
            120, 210, 150, 45,hwnd, (HMENU)ID_BUTTON_LOGIN  , NULL, NULL);

    }

    if(msg==WM_CLOSE)
    {
        if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AdmInTeaWin", GetModuleHandle(NULL));
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

//����Աת��ѧ��
LRESULT CALLBACK AdmOutStuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if(msg==WM_COMMAND){
        if (LOWORD(wParam)==ID_BUTTON_LOGIN)
        {
            char name[20];
            GetWindowTextA(g_hEditUsername1, name, sizeof(name));
            deletestuofroot(name);
        }
        if(LOWORD(wParam)==ID_BUTTON_EXIT_SYSTEM)
        {
            DestroyWindow(hwnd);
            UnregisterClass("AdmOutStuWin", GetModuleHandle(NULL));
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
            UnregisterClass("AdmOutStuWin", GetModuleHandle(NULL));
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

//ѧ����ʾ�Լ���Ϣ
LRESULT CALLBACK ShowStuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    int i=0;
    switch (msg)
    {
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case ID_BUTTON_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("ShowStuWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("ShowStuWin", GetModuleHandle(NULL));
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
            return 0;

        case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps); 
        student st=stuuser->stu;
        wsprintf(szBuffer,TEXT("ѧ��������%s"),st.name);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*(i++),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("ѧ�ţ�%s"),st.id);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*(i++),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("�Ա�%d"),st.gender);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*(i++),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("רҵ��%s"),st.major);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*(i++),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("��Դ�أ�%s"),st.home);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*(i++),szBuffer,iTarget);
        wsprintf(szBuffer,TEXT("�༶��:%d"),st.Class);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,cxChar,cyChar*(i++),szBuffer,iTarget);
        EndPaint(hwnd, &ps);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//ѧ����ʾ�Լ��ܳɼ�
LRESULT CALLBACK StuAllScoreProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int NUMLINES=20; 
    switch (msg)
    {
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case ID_BUTTON_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("StuAllScoreWin", GetModuleHandle(NULL));
                break;
            }
            break;

        case WM_CLOSE: 
            if(MessageBox(NULL,TEXT("�Ƿ��˳�"),TEXT("��ʾ"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hwnd);
                UnregisterClass("StuAllScoreWin", GetModuleHandle(NULL));
            }
            else   
                return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
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
        cnty=0;
        hdc = BeginPaint(hwnd, &ps); 
        showhpofastu(stuuser);
        showgcofastu(stuuser);
        cnty=0;
        EndPaint(hwnd, &ps);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

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

//ѧ����ʾ���пγ̷���
LRESULT CALLBACK StuClassScoreProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    int NUMLINES=280;
    switch (msg)
    {
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case ID_BUTTON_EXIT_SYSTEM:
                DestroyWindow(hwnd);
                UnregisterClass("StuClassScoreWin", GetModuleHandle(NULL));
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
                UnregisterClass("StuClassScoreWin", GetModuleHandle(NULL));
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
        showscoresofastu(stuuser);
        cnty=0;
        EndPaint(hwnd, &ps);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

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

void ShowStuWindow()
{
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = ShowStuProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"ShowStuWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("ShowStuWin"), TEXT("ѧ��"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    500, 200, 700, 500, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    50, 350, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void StuAllScoreWindow()
{
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = StuAllScoreProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"StuAllScoreWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("StuAllScoreWin"), TEXT("ѧ��"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    500, 200, 700, 500, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    50, 350, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
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

void StuClassScoreWindow()
{
    cntx=0,cnty=0;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = StuClassScoreProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"StuClassScoreWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("StuClassScoreWin"), TEXT("ѧ��"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
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

void AdmInStuWindow()
{
    HWND hwnd;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdmInStuProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdmInStuWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdmInStuWin"), TEXT("ѧ��"), 
	(WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
    200, 200, 750, 450, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("ѧ�����ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        270, 320, 200, 30, hwndChange, (HMENU)ID_BUTTON_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void AdmOutStuWindow()
{
    HWND hwnd;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdmOutStuProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdmOutStuWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdmOutStuWin"), TEXT("ѧ��"), 
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

void AdmInTeaWindow()
{
    HWND hwnd;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdmInTeaProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdmInTeaWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdmInTeaWin"), TEXT("ѧ��"), 
	(WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
    600, 400, 400, 400, NULL, NULL, GetModuleHandle(NULL), NULL);

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

void AdmInCouWindow()
{
    HWND hwnd;
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdmInCouProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdmInCouWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdmInCouWin"), TEXT("ѧ��"), 
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

void ShowTeatoAdmWindow()
{
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = ShowTeatoAdmProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"ShowTeatoAdmWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("ShowTeatoAdmWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    200, 200, 700, 500, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    400, 200, 200, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void ShowCostoAdmWindow()
{
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = ShowCostoAdmProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"ShowCostoAdmWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("ShowCostoAdmWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    200, 200, 700, 500, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    400, 200, 200, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void AdmEntpunWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdmEntpunProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdmEntpunWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdmEntpunWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
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

void ShowStutoAdmWindow()
{
    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = ShowStutoAdmProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"ShowStutoAdmWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("ShowStutoAdmWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    200, 200, 700, 500, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
    400, 200, 200, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void AdmEnthorWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdmEnthorProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdmEnthorWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdmEnthorWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
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

void AdmChangeScoreWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdmChangeScoreProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdmChangeScoreWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdmChangeScoreWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
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

void AdmEntStuorScoWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AdmEntStuorScoProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AdmEntStuorScoWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AdmEntStuorScoWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 400, 400, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        100, 200, 200, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void AESorSSon1Window()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AESorSSon1Proc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AESorSSon1Win";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AESorSSon1Win"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 400, 400, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        50, 200, 250, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void AESorSSon2Window()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = AESorSSon2Proc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"AESorSSon2Win";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("AESorSSon2Win"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 400, 400, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        80, 220, 200, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void InputScoreWindow()
{
    HWND hwnd;

    WNDCLASSW wndclass = { 0 };
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = InputScoreProc;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = L"InputScoreWin";
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassW(&wndclass))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    HWND hwndChange = CreateWindow(TEXT("InputScoreWin"), TEXT("����Ա"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL, 
    650, 300, 400, 400, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChange == NULL)
    {
        MessageBox(NULL, TEXT("����Ա���ڴ���ʧ��"), TEXT("����"), MB_ICONERROR);
        return;
    }

    CreateWindow(TEXT("BUTTON"), TEXT("�˳�ϵͳ"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 
        90, 220, 200, 30, hwndChange, (HMENU)ID_BUTTON_ROOT_EXIT_SYSTEM, NULL, NULL);

    ShowWindow(hwndChange, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
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

#ifndef __INITIALIZATION
#define __INITIALIZATION

void Initialization()
{
    stulih=(stunode*)malloc(sizeof(stunode));
    stulih->pre=stulih->next=NULL;
    stulit=stulih;
    clslih=(clsnode*)malloc(sizeof(clsnode));
    clslih->pre=clslih->next=NULL;
    clslit=clslih;
	tealih=(teanode*)malloc(sizeof(teanode));
	tealih->pre=tealih->next=NULL;
	tealit=tealih;
	rootlih=(rootnode*)malloc(sizeof(rootnode));
	rootlih->pre=rootlih->next=NULL;
	rootlit=rootlih;

	InitializationOfSTU();
	InitializationOfCLS();
	InitializationOfSCORE();
	InitializationOfROOT();
	InitializationOfTEA();
	InitializationOfORDER();
	InitializationOfEA();

	stunode* p=stulih;
    while(p!=NULL)
    {
        cptsg(p);
        p=p->next;
    }
	return;
}

void InitializationOfEA()
{
	FILE *fp;
	if((fp=fopen(EA,"r"))!=NULL)
    {
        aptlih=NULL;
        apt* p=aptlih;
        while(fgets(str,MAXINPUT,fp))
        {
            if(str[0]=='\0'||str[0]=='\r'||str[0]=='\n')continue;
            if(aptlih==NULL)
            {
                p=(apt*)malloc(sizeof(apt));
                aptlih=p;
                strcpy(p->str,str);
                p->status=0;
                p->next=p->pre=NULL;
            }
            else
            {
                apt* newapt=(apt*)malloc(sizeof(apt));
                newapt->status=0;
                strcpy(newapt->str,str);
                newapt->next=NULL;
                newapt->pre=p;
                p->next=newapt;
                p=p->next;
            }
        }
    }
	fclose(fp);
	return;
}

void InitializationOfSTU()
{
	FILE *fp;
	if((fp=fopen(STU,"r"))!=NULL)
    {
        while(fgets(str,MAXINPUT,fp))
        {
            if(str[0]=='\n'||str[0]=='\r')continue;
            Tstu++;
            student astu;
            int j,p=0;
            for(j=0;str[p]!=';';j++)
            {
                astu.name[j]=str[p];
                p++;
            }
            astu.name[j]='\0';
            p++;
            for(j=0;str[p]!=';';j++)
            {
                astu.id[j]=str[p];
                p++;
            }
            astu.id[j]='\0';
            p++;
            astu.gender=0;
            for(j=0;str[p]!=';';j++)
            {
                if(str[p]>='0'&&str[p]<='9')
                    astu.gender=str[p]-'0';
                p++;
            }
            p++;
            for(j=0;str[p]!=';';j++)
            {
                astu.major[j]=str[p];
                p++;
            }
            astu.major[j]='\0';
            p++;
            astu.year=0;
            while(str[p]!=';')
            {
                if(str[p]>='0'&&str[p]<='9')
                    astu.year=astu.year*10+(str[p]-'0');
                p++;
            }
            p++;
            astu.Class=0;
            while(str[p]!=';')
            {
                if(str[p]>='0'&&str[p]<='9')
                    astu.Class=astu.Class*10+(str[p]-'0');
                p++;
            }
            p++;
            for(j=0;str[p]!=';';j++)
            {
                astu.pwd[j]=str[p];
                p++;
            }
            astu.pwd[j]='\0';
            p++;
            for(j=0;str[p]!='\n'&&str[p]!='\r';j++)
            {
                astu.home[j]=str[p];
                p++;
            }
            astu.home[j]='\0';
            astu.scoreh=(cosnode*)malloc(sizeof(cosnode));
            astu.scoreh->pre=astu.scoreh->next=NULL;
            astu.scoret=astu.scoreh;

            astu.honorh=(strnode*)malloc(sizeof(strnode));
            astu.honorh->pre=astu.honorh->next=NULL;
            astu.honorh->inf=0;
            astu.honort=astu.honorh;

            astu.punishh=(strnode*)malloc(sizeof(strnode));
            astu.punishh->pre=astu.punishh->next=NULL;
            astu.punishh->inf=0;
            astu.punisht=astu.punishh;

            stunode* anewnode=(stunode*)malloc(sizeof(stunode));
            anewnode->pre=stulit;
            anewnode->next=NULL;
            anewnode->stu=astu;
            stulit->next=anewnode;
            stulit=stulit->next;
        }
        stulih=stulih->next;
    }
	fclose(fp);
	return;
}

void InitializationOfTEA()
{
	FILE *fp;
	if((fp=fopen(TEA,"r"))!=NULL)
    {
        while(fgets(str,MAXINPUT,fp))
        {
			teanode *anewtea=(teanode*)malloc(sizeof(teanode));
            if(str[0]=='\n'||str[0]=='\r')continue;
            int j,p=0;
            for(j=0;str[p]!=';';j++)
            {
                anewtea->tea.name[j]=str[p];
                p++;
            }
            anewtea->tea.name[j]='\0';
            p++;
            for(j=0;str[p]!=';';j++)
            {
                anewtea->tea.account[j]=str[p];
                p++;
            }
            anewtea->tea.account[j]='\0';
            p++;
            for(j=0;str[p]!='\n'&&str[p]!='\r';j++)
            {
                anewtea->tea.pwd[j]=str[p];
                p++;
            }
            anewtea->tea.pwd[j]='\0';
			tealit->next=anewtea;
			anewtea->pre=tealit;
			tealit=tealit->next;
        }
		if(tealih->pre==NULL&&tealih->next!=NULL)tealih=tealih->next;
    }
	fclose(fp);
	return;
}

void InitializationOfCLS()
{
	FILE *fp;
	if((fp=fopen(CLS,"r"))!=NULL)
    {
        while(fgets(str,MAXINPUT,fp))
        {
            if(str[0]=='\n'||str[0]=='\r')continue;
            cls acls;
            int j,p=0;
            for(j=0;str[p]!=';';j++)
            {
                acls.name[j]=str[p];
                p++;
            }
            acls.name[j]='\0';
            p++;
            for(j=0;str[p]!=';';j++)
            {
                acls.id[j]=str[p];
                p++;
            }
            acls.id[j]='\0';
            p++;
            acls.nature=0;
            while(str[p]!=';')
            {
                if(str[p]>='0'&&str[p]<='9')
                    acls.nature=str[p]-'0';
                p++;
            }
            p++;
            for(j=0;str[p]!=';';j++)
            {
                acls.teacher[j]=str[p];
                p++;
            }
            acls.teacher[j]='\0';
            p++;
            acls.cdt=0.0;
            int pa=0;
            double w=1.0;
            while(str[p]!='\n'&&str[p]!='\r')
            {
                if(str[p]=='.')pa=1;
                else if(pa==0&&str[p]>='0'&&str[p]<='9')
                    acls.cdt=acls.cdt*10+str[p]-'0';
                else if(pa==1&&str[p]>='0'&&str[p]<='9')
                {
                    w*=0.1;
                    acls.cdt+=w*(str[p]-'0');
                }
                p++;
            }

            clsnode* anewnode=(clsnode*)malloc(sizeof(clsnode));
            anewnode->pre=clslit;
            anewnode->next=NULL;
            anewnode->clsif=acls;
            clslit->next=anewnode;
            clslit=clslit->next;
        }
        clslih=clslih->next;
    }
	fclose(fp);
	return;
}

//������һ��250�еĺ�������΢����
void InitializationOfORDER()
{
	FILE *fp;
	if((fp=fopen(ORDER,"r"))!=NULL)
    {
        while(fgets(str,MAXINPUT,fp))
        {
            int j,p=0;
            if(str[0]=='\n'||str[0]=='\r')continue;
            char ordername[100];
            for(j=0;str[p]!=';';j++)
            {
                ordername[j]=str[p];
                p++;
            }
            ordername[j]='\0';p++;
            if(strcmp(ordername,"deletestu")==0)
            {
                char astuname[100];
                for(j=0;str[p]!=';';j++)
                {
                    astuname[j]=str[p];
                    p++;
                }
                astuname[j]='\0';p++;
                deletestudent(searchstu(astuname));
            }
            else if(strcmp(ordername,"changescoreofastu")==0)
            {
                char astr[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr[j]=str[p];
                    p++;
                }
                astr[j]='\0';p++;
                stunode* astu=searchstu(astr);
                for(j=0;str[p]!=';';j++)
                {
                    astr[j]=str[p];
                    p++;
                }
                astr[j]='\0';p++;
                
                clsnode* acls=searchcls(astr);
                int anum=0;
                while(str[p]!=';')
                {
                    if(str[p]>='0'&&str[p]<='9')
                        anum=anum*10+str[p]-'0';
                    p++;
                }
                p++;
                int newscore=anum;
                anum=0;
                while(str[p]!=';')
                {
                    if(str[p]>='0'&&str[p]<='9')
                        anum=anum*10+str[p]-'0';
                    p++;
                }
                int isfirst=anum;
                changescoreofastu(astu,acls,newscore,isfirst);
            }
            else if(strcmp(ordername,"enterhonor")==0)
            {
                char astr[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr[j]=str[p];
                    p++;
                }
                astr[j]='\0';p++;
                stunode* astu=searchstu(astr);
                for(j=0;str[p]!=';';j++)
                {
                    astr[j]=str[p];
                    p++;
                }
                astr[j]='\0';p++;
                int flag=0;
                double zs=0.0,xs=0.0,adouble,m1=0.1;
                for(j=0;str[p]!=';';j++)
                {
                    if(str[p]=='.')
                    {
                        flag=1;p++;
                        continue;
                    }
                    if(flag==0)
                    {
                        zs=zs*10+str[p]-'0';
                    }
                    else
                    {
                        xs+=m1*(str[p]-'0');
                        m1*=0.1;
                    }
                    p++;
                }
                adouble=zs+xs;
                enterhonor(astu,astr,adouble);
            }
            else if(strcmp(ordername,"enterpunish")==0)
            {
                char astr[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr[j]=str[p];
                    p++;
                }
                astr[j]='\0';p++;
                stunode* astu=searchstu(astr);
                for(j=0;str[p]!=';';j++)
                {
                    astr[j]=str[p];
                    p++;
                }
                astr[j]='\0';p++;
                int flag=0;
                double zs=0.0,xs=0.0,adouble,m1=0.1;
                for(j=0;str[p]!=';';j++)
                {
                    if(str[p]=='.')
                    {
                        flag=1;p++;
                        continue;
                    }
                    if(flag==0)
                    {
                        zs=zs*10+str[p]-'0';
                    }
                    else
                    {
                        xs+=m1*(str[p]-'0');
                        m1*=0.1;
                    }
                    p++;
                }
                adouble=zs+xs;
                enterpunish(astu,astr,adouble);
            }
            else if(strcmp(ordername,"inputcourse")==0)
            {
                char astr1[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr1[j]=str[p];
                    p++;
                }
                astr1[j]='\0';p++;
                char astr2[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr2[j]=str[p];
                    p++;
                }
                astr2[j]='\0';p++;
                int anum=0;
                while(str[p]!=';')
                {
                    if(str[p]>='0'&&str[p]<='9')
                        anum=anum*10+str[p]-'0';
                    p++;
                }
                p++;
                char astr3[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr3[j]=str[p];
                    p++;
                }
                astr3[j]='\0';p++;
                int flag=0;
                double zs=0.0,xs=0.0,adouble,m1=0.1;
                for(j=0;str[p]!=';';j++)
                {
                    if(str[p]=='.')
                    {
                        flag=1;p++;
                        continue;
                    }
                    if(flag==0)
                    {
                        zs=zs*10+str[p]-'0';
                    }
                    else
                    {
                        xs+=m1*(str[p]-'0');
                        m1*=0.1;
                    }
                    p++;
                }
                adouble=zs+xs;
                inputcourse(astr1,astr2,anum,astr3,adouble);
            }
            else if(strcmp(ordername,"changepwdofstu")==0)
			{
				char astr1[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr1[j]=str[p];
                    p++;
                }
                astr1[j]='\0';p++;
                char astr2[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr2[j]=str[p];
                    p++;
                }
                astr2[j]='\0';p++;
				changepwdofstu(searchstu(astr1),astr2);
			}
			else if(strcmp(ordername,"changemajorofstu")==0)
			{
				char astr1[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr1[j]=str[p];
                    p++;
                }
                astr1[j]='\0';p++;
                char astr2[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr2[j]=str[p];
                    p++;
                }
                astr2[j]='\0';p++;
				changemajorofstu(searchstu(astr1),astr2);
			}
			else if(strcmp(ordername,"changepwdoftea")==0)
			{
				char astr1[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr1[j]=str[p];
                    p++;
                }
                astr1[j]='\0';p++;
                char astr2[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr2[j]=str[p];
                    p++;
                }
                astr2[j]='\0';p++;
				changepwdoftea(searchtea(astr1),astr2);
			}
			else if(strcmp(ordername,"changepwdofroot")==0)
			{
				char astr1[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr1[j]=str[p];
                    p++;
                }
                astr1[j]='\0';p++;
                char astr2[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr2[j]=str[p];
                    p++;
                }
                astr2[j]='\0';p++;
				changepwdofroot(searchroot(astr1),astr2);
			}
			else if(strcmp(ordername,"inputscore")==0)
            {
                char astr[100];
                for(j=0;str[p]!=';';j++)
                {
                    astr[j]=str[p];
                    p++;
                }
                astr[j]='\0';p++;
                stunode* astu=searchstu(astr);
                for(j=0;str[p]!=';';j++)
                {
                    astr[j]=str[p];
                    p++;
                }
                astr[j]='\0';p++;
                
                clsnode* acls=searchcls(astr);
                int anum=0,iffu=1;
                while(str[p]!=';')
                {
                    if(str[p]=='-')iffu=-1;
                    if(str[p]>='0'&&str[p]<='9')
                        anum=anum*10+str[p]-'0';
                    p++;
                }
                p++;
                int newscore=anum*iffu;
                anum=0;
                int flag=0;
                double zs=0.0,xs=0.0,adouble,m1=0.1,iffuf=1.0;
                for(j=0;str[p]!=';';j++)
                {
                    if(str[p]=='-')
					{
						iffuf=-1.0;p++;continue;
					}
                    if(str[p]=='.')
                    {
                        flag=1;p++;
                        continue;
                    }
                    if(flag==0)
                    {
                        zs=zs*10+str[p]-'0';
                    }
                    else
                    {
                        xs+=m1*(str[p]-'0');
                        m1*=0.1;
                    }
                    p++;
                }
                adouble=(zs+xs)*iffuf;p++;
                while(str[p]!=';')
                {
                    if(str[p]>='0'&&str[p]<='9')
                        anum=anum*10+str[p]-'0';
                    p++;
                }
                int isfirst=anum;
                inputscore(astu,acls,newscore,adouble,isfirst);
            }
			else
            {
                printf("ERROR:%s\n",ordername);
            }
        }
    }
	fclose(fp);
}

void InitializationOfROOT()
{
	FILE *fp;
	if((fp=fopen(ROOT,"r"))!=NULL)
    {
        while(fgets(str,MAXINPUT,fp))
        {
			rootnode *anewroot=(rootnode*)malloc(sizeof(rootnode));
            if(str[0]=='\n'||str[0]=='\r')continue;
            int j,p=0;
            for(j=0;str[p]!=';';j++)
            {
                anewroot->rt.name[j]=str[p];
                p++;
            }
            anewroot->rt.name[j]='\0';
            p++;
            for(j=0;str[p]!=';';j++)
            {
                anewroot->rt.account[j]=str[p];
                p++;
            }
            anewroot->rt.account[j]='\0';
            p++;
            for(j=0;str[p]!='\n'&&str[p]!='\r';j++)
            {
                anewroot->rt.pwd[j]=str[p];
                p++;
            }
            anewroot->rt.pwd[j]='\0';
			rootlit->next=anewroot;
			anewroot->pre=rootlit;
			rootlit=rootlit->next;
        }
		if(rootlih->pre==NULL&&rootlih->next!=NULL)rootlih=rootlih->next;
    }
	fclose(fp);
	return;
}

void InitializationOfSCORE()
{
	FILE *fp;
	if((fp=fopen(SCORE,"r"))!=NULL)
    {
        while(fgets(str,MAXINPUT,fp))
        {
            if(str[0]=='\n'||str[0]=='\r')continue;
            char stuname[100],clsname[100],fi,sco;
            int j,p=0;
            for(j=0;str[p]!=';';j++)
            {
                stuname[j]=str[p];
                p++;
            }
            stuname[j]='\0';
            p++;
            for(j=0;str[p]!=';';j++)
            {
                clsname[j]=str[p];
                p++;
            }
            clsname[j]='\0';
            p++;
            fi=0;
            while(str[p]!=';')
            {
                if(str[p]>='0'&&str[p]<='9')
                    fi=str[p]-'0';
                p++;
            }
            p++;
            sco=0;
            while(str[p]!='\n'&&str[p]!='\r')
            {
                if(str[p]>='0'&&str[p]<='9')
                    sco=sco*10+str[p]-'0';
                p++;
            }
            stunode* stup=searchstu(stuname);
            if(stup==NULL)printf("error");
            clsnode* clsp=searchcls(clsname);
			if(clsp==NULL)printf("error");
            double agp=cptgp(sco);
            inputscore(stup,clsp,sco,agp,fi);
            if(stup->stu.scoreh!=NULL&&stup->stu.scoreh->pre==NULL&&stup->stu.scoreh->next!=NULL)
				stup->stu.scoreh=stup->stu.scoreh->next;
        }
    }
	fclose(fp);
	return;
}

#endif

#ifndef OPERATIONFORSTU
#define OPERATIONFORSTU
void inputscore(stunode* pstu,clsnode* pcls,int sc,double GP,int isfirst)
{
    cosnode* newcos=(cosnode*)malloc(sizeof(cosnode));
    newcos->cos.c=&(pcls->clsif);
    newcos->cos.first=isfirst;
    newcos->cos.score=sc;
    newcos->cos.gp=GP;
    newcos->next=NULL;
    newcos->pre=pstu->stu.scoret;
    pstu->stu.scoret->next=newcos;
    pstu->stu.scoret=pstu->stu.scoret->next;
    if(pstu->stu.scoreh->pre==NULL&&pstu->stu.scoreh->next!=NULL)pstu->stu.scoreh=pstu->stu.scoreh->next;
	return;
}

//s
void changescoreofastu(stunode* astu,clsnode* acls,int newscore,int isfirst)
{
	if(astu->stu.scoreh->pre==NULL&&astu->stu.scoreh->next!=NULL)astu->stu.scoreh=astu->stu.scoreh->next;
	if(astu->stu.scoret->pre==NULL)
	{
		//printf("�޸�ʧ�ܣ�");
		return;
	}
    cosnode* p=astu->stu.scoret;
    while(p!=NULL&&p->pre!=NULL)
    {
        if(p->cos.c==&(acls->clsif))
        {
            p->cos.score=newscore;
            p->cos.gp=cptgp(newscore);
            p->cos.first=isfirst;
            cptsg(astu);
            return;
        }
        p=p->pre;
    }
//	printf("�޸�ʧ�ܣ�");
	return;
}

void createnewstu(char* aname,char* aid,int agender,char* amajor,int ayear,int aclass,char* apwd,char* ahome)
{
    stunode *newstunode;
    newstunode=(stunode*)malloc(sizeof(stunode));
    strcpy(newstunode->stu.name,aname);
    strcpy(newstunode->stu.id,aid);
    newstunode->stu.gender=agender;
    strcpy(newstunode->stu.major,amajor);
    newstunode->stu.year=ayear;
    newstunode->stu.Class=aclass;
    strcpy(newstunode->stu.pwd,apwd);
    strcpy(newstunode->stu.home,ahome);
	newstunode->stu.cgpa=newstunode->stu.csco=newstunode->stu.tgpa=newstunode->stu.tsco=newstunode->stu.sgpa=newstunode->stu.ssco=0;
    newstunode->stu.scoreh=(cosnode*)malloc(sizeof(cosnode));
    newstunode->stu.scoreh->next=newstunode->stu.scoreh->pre=NULL;
    newstunode->stu.scoret=newstunode->stu.scoreh;

    newstunode->stu.honorh=(strnode*)malloc(sizeof(strnode));
    newstunode->stu.honorh->inf=0;
    newstunode->stu.honorh->next=newstunode->stu.honorh->pre=NULL;
    newstunode->stu.honort=newstunode->stu.honorh;

    newstunode->stu.punishh=(strnode*)malloc(sizeof(strnode));
    newstunode->stu.punishh->inf=0;
    newstunode->stu.punishh->next=newstunode->stu.punishh->pre=NULL;
    newstunode->stu.punisht=newstunode->stu.punishh;
    stulit->next=newstunode;
    newstunode->next=NULL;
    newstunode->pre=stulit;
    stulit=stulit->next;
}

#endif

#ifndef __ORDEROFROOT
#define __ORDEROFROOT

void addstudentofroot(char aname[],char aid[],int agender,char amajor[],int ayear,int aclass,char apwd[],char ahome[])
{
	createnewstu(aname,aid,agender,amajor,ayear,aclass,apwd,ahome);
	FILE* fp=fopen(STU,"a+");
	fprintf(fp,"%s;%s;%d;%s;%d;%d;%s;%s\n",aname,aid,agender,amajor,ayear,aclass,apwd,ahome);
	fclose(fp);
	return;
}

void deletestuofroot(char str[])
{
		if(searchstu(str)!=NULL)
		{
			deletestudent(searchstu(str));
			FILE* fp=fopen(ORDER,"a+");
			fprintf(fp,"deletestu;%s;\n",str);
			fclose(fp);
            MessageBox(NULL,TEXT("ѧ����Ϣɾ���ɹ�!"),TEXT("ͨ��"),MB_OK);
		}
		else
            MessageBox(NULL,TEXT("��ѧ�������ڣ�ɾ��ʧ��!"),TEXT("����"),MB_ICONERROR);
	return;
}

void inputnewteacher(char tname[],char taccount[],char tpwd[])
{
	FILE* fp=fopen(TEA,"a+");
	fprintf(fp,"%s;%s;%s\n",tname,taccount,tpwd);
	fclose(fp);
	return;
}

#endif


#ifndef __ORDEROFTEA
#define __ORDEROFTEA

void deletestuoftea(char str[])
{
		if(searchstu(str)!=NULL)
		{
            MessageBox(NULL,TEXT("������Ϣ�Ѿ����沢�ϱ�����ȴ�����Ա������"),TEXT("ͨ��"),MB_OK);
			FILE* fp=fopen(EA,"a+");
			fprintf(fp,"deletestu;%s;%s;\n",str,teauser->tea.name);
			fclose(fp);
		}
		else
            MessageBox(NULL,TEXT("��ѧ�������ڣ�ɾ��ʧ��"),TEXT("ʧ��"),MB_ICONERROR);
	return;
}

#endif

#ifndef __SEARCH
#define __SEARCH

teanode* searchtea(char* str)
{
	teanode* p=tealih;

    while(p!=NULL)
    {
        if(strcmp(p->tea.account,str)==0)
            return p;
		p=p->next;
    }
    return NULL;
}

rootnode* searchroot(char* str)
{
	rootnode* p=rootlih;
    while(p!=NULL)
    {
        if(strcmp(p->rt.account,str)==0)
            return p;
		p=p->next;
    }
    return NULL;
}

stunode* searchstuid(char* str)
{
    stunode* p=stulih;
    while(p!=NULL)
    {
        if(strcmp(p->stu.id,str)==0)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

stunode* searchstu(char* str)
{
    stunode* p=stulih;
    while(p!=NULL)
    {
        if(strcmp(p->stu.name,str)==0)
        {
            return p;
        }
        p=p->next;
    }
	p=stulih;
	while(p!=NULL)
    {
        if(strcmp(p->stu.id,str)==0)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

clsnode* searchcls(char* str)
{
    clsnode* p=clslih;
    while(p!=NULL)
    {
        if(strcmp(p->clsif.name,str)==0)
        {
            return p;
        }
        p=p->next;
    }
	p=clslih;
    while(p!=NULL)
    {
        if(strcmp(p->clsif.id,str)==0)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int searchmajor(char* str)
{
    stunode* p=stulih;
    while(p!=NULL)
    {
        if(strcmp(p->stu.major,str)==0)return 1;
        p=p->next;
    }
    return 0;
}

#endif

void changepwdofstu(stunode* stuuser,char* astr)
{
	if(stuuser!=NULL)
	{
		strcpy(stuuser->stu.pwd,astr);
	}
}
void changemajorofstu(stunode* stuuser,char* astr)
{
	if(stuuser!=NULL)
	{
		strcpy(stuuser->stu.major,astr);
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

double cptgp(int sco)
{
    if(sco>=90)return 4.0;
    else if(sco>=87)return 3.7;
    else if(sco>=83)return 3.3;
    else if(sco>=80)return 3.0;
    else if(sco>=77)return 2.7;
    else if(sco>=73)return 2.3;
    else if(sco>=70)return 2.0;
    else if(sco>=67)return 1.7;
    else if(sco>=63)return 1.3;
    else if(sco>=60)return 1.0;
    else return 0.0;
}

void showoptionalscore(int sco)
{
	if(sco>=90)
    {
        wsprintf(szBuffer,TEXT("����"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,6*cxChar,cyChar*(cnty-iVscrollPos),szBuffer,iTarget);
    }
	else if(sco>=80)
    {
        wsprintf(szBuffer,TEXT("����"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,6*cxChar,cyChar*(cnty-iVscrollPos),szBuffer,iTarget);
    }
	else if(sco>=70)
    {
        wsprintf(szBuffer,TEXT("�е�"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,6*cxChar,cyChar*(cnty-iVscrollPos),szBuffer,iTarget);
    }
	else if(sco>=60)
    {
        wsprintf(szBuffer,TEXT("����"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,6*cxChar,cyChar*(cnty-iVscrollPos),szBuffer,iTarget);
    }
	else
    {
        wsprintf(szBuffer,TEXT("������"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,6*cxChar,cyChar*(cnty-iVscrollPos),szBuffer,iTarget);
    }
	return;
}


#ifndef __WORKOFXZL
#define __WORKOFXZL

void inputcourse(char Name[],char Id[],int Nature,char Teacher[],double Credit)
{
    clsnode *cnew=(clsnode*)malloc(sizeof(clsnode));
    strcpy(cnew->clsif.name,Name);
    strcpy(cnew->clsif.id,Id);
    strcpy(cnew->clsif.teacher,Teacher);
    cnew->clsif.nature=Nature;
    cnew->clsif.cdt=Credit;
    cnew->next=NULL;
    cnew->pre=clslit;
    clslit->next=cnew;
    clslit=clslit->next; 
}

void deletestudent(stunode* Stu)
{
    if(Stu->next!=NULL) Stu->next->pre=Stu->pre;
    Stu->pre->next=Stu->next;
	if(Stu==stulih)stulih=stulih->next;
    free(Stu);
}

void enterhonor(stunode *Stu,char S[],double Inf)
{
    strnode *cnew=(strnode*)malloc(sizeof(strnode));
    cnew->inf=Inf;
    strcpy(cnew->s,S);
    cnew->next=NULL;
    cnew->pre=Stu->stu.honort;
    Stu->stu.honort->next=cnew;
    Stu->stu.honort=Stu->stu.honort->next;
}

void enterpunish(stunode *Stu,char S[],double Inf)
{
    strnode *cnew=(strnode*)malloc(sizeof(strnode));
    cnew->inf=Inf;
    strcpy(cnew->s,S);
    cnew->next=NULL;
    cnew->pre=Stu->stu.punisht;
    Stu->stu.punisht->next=cnew;
    Stu->stu.punisht=Stu->stu.punisht->next;
}

#endif

#ifndef __WORKOFZZX
#define __WORKOFZZX

inline cosnode *sort_bycls(stunode *stunow)
{
	cosnode *cosnow=stunow->stu.scoreh;
	cosnode *coslist=NULL,*cosr=NULL,*ctmp=NULL,*coslast=NULL;
	while(cosnow!=NULL)
	{
		if(cosnow->cos.c==NULL)
		{
			cosnow=cosnow->next;
			continue;
		}
		
		if(cosnow->cos.score==-1)
		{
			cosnow=cosnow->next;
			continue;
		}
		
		
		ctmp=(cosnode*)malloc(sizeof(cosnode));
        ctmp->cos=cosnow->cos;
		if(coslist==NULL)
        {
            coslist=(cosnode*)malloc(sizeof(cosnode));
            coslist=ctmp;
            coslist->next=NULL;
            coslist->pre=NULL;
        }
        else
        {
            int flag=0;
            cosr=coslist;
            while(strcmp(cosr->cos.c->id,ctmp->cos.c->id)!=-1)
            {
                if(cosr->next!=NULL)
                cosr=cosr->next;
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                if(cosr==coslist)
                {
                    ctmp->next=cosr;
                    cosr->pre=ctmp;
                    coslist=ctmp;
                }
                else
                {
                    coslast=cosr->pre;
                    coslast->next=ctmp;
                    ctmp->pre=coslast;
                    cosr->pre=ctmp;
                    ctmp->next=cosr;
                }
            }
            else
            {
                cosr->next=ctmp;
                ctmp->pre=cosr;
                ctmp->next=NULL;
            }
		}
		cosnow=cosnow->next;
	}
	return ctmp;
}
double maxdouble(double x,double y)
{
	if(x<y)return y;
	return x;
}

void cptsg(stunode *Stu)
{
    stunode *studentnow=Stu;
	if(Stu->stu.scoreh->pre==NULL&&Stu->stu.scoreh->next!=NULL)Stu->stu.scoreh=Stu->stu.scoreh->next;
	cosnode *coursenow=sort_bycls(studentnow);
	cosnode *courselit=coursenow;
	double callcdt=0.0000,tallcdt=0.0000,sallcdt=0.0000,oallcdt=0.0000;
	double callscore=0.0000,tallscore=0.0000,sallscore=0.0000,oallscore=0.0000;
	double callgp=0.0000,tallgp=0.0000,sallgp=0.0000,oallgp=0.0000;
	double cdtnow,scorenow,hscore=-1.0000,gpnow,hgp=-1.0000;
	double scoreweid,gpweid;

	course cosnow;
	int naturenow;
	while(coursenow!=NULL)
	{
		cosnow=coursenow->cos;
		naturenow=cosnow.c->nature;
		cdtnow=cosnow.c->cdt;
		scorenow=cosnow.score;
		gpnow=cosnow.gp;
		hscore=maxdouble(hscore,scorenow);
		hgp=maxdouble(hgp,gpnow);
		
		if(coursenow->pre!=NULL)
		{
			if(strcmp(coursenow->pre->cos.c->id,coursenow->cos.c->id)==0)
			{
				coursenow=coursenow->pre;
				continue;
			}
		}
		
		scoreweid=scorenow*cdtnow;
		gpweid=gpnow*cdtnow;
		
		tallcdt+=cdtnow;
		tallscore+=scoreweid;
		tallgp+=gpweid;
		if(naturenow==0)
		{
			callcdt+=cdtnow;
			callscore+=scoreweid;
			callgp+=gpweid;

			sallcdt+=cdtnow;
			sallscore+=scoreweid;
			sallgp+=gpweid;
		}
		if(naturenow==2)
		{
			sallcdt+=cdtnow;
			sallscore+=scoreweid;
			sallgp+=gpweid;
		}
		
		oallcdt+=cdtnow;
		oallscore+=hscore*cdtnow;
		oallgp+=hgp*cdtnow;
		hscore=-1.0000;
		hgp=-1.0000;
		
		coursenow=coursenow->pre;
	}
	strnode* p;
	if(Stu->stu.honorh->pre==NULL&&Stu->stu.honorh->next!=NULL)Stu->stu.honorh=Stu->stu.honorh->next;
	p=Stu->stu.honorh;
	double addscore=0.0;
	while(p!=NULL)
	{
		addscore+=p->inf;
		p=p->next;
	}
	if(fabs(callcdt)<1e-5)
		studentnow->stu.cgpa=0;
	else	
		studentnow->stu.cgpa=callgp/callcdt;
	if(fabs(callcdt)<1e-5)
		studentnow->stu.csco=0;
	else	
		studentnow->stu.csco=callscore/callcdt;
	if(fabs(tallcdt)<1e-5) 
		studentnow->stu.tgpa=0;
	else	
		studentnow->stu.tgpa=tallgp/tallcdt;
	if(fabs(tallcdt)<1e-5)
		studentnow->stu.tsco=0;
	else	
		studentnow->stu.tsco=tallscore/tallcdt;
	if(fabs(sallcdt)<1e-5)
		studentnow->stu.sgpa=addscore;
	else    
		studentnow->stu.sgpa=sallgp/sallcdt+addscore;
	if(fabs(sallcdt)<1e-5)
		studentnow->stu.ssco=0;
	else
		studentnow->stu.ssco=sallscore/sallcdt;
	if(fabs(oallcdt)<1e-5)
		studentnow->stu.ogpa=addscore;
	else    
		studentnow->stu.ogpa=oallgp/oallcdt;
	if(fabs(oallcdt)<1e-5)
		studentnow->stu.osco=0;
	else
		studentnow->stu.osco=oallscore/oallcdt;
	
	while(courselit!=NULL)
	{
		cosnode *p=courselit;
		courselit=courselit->pre;
		free(p);
	}
    return;
}

int searchyear(int wheyear)
{
    stunode *p=stulih;
    while(p!=NULL)
    {
        if(p->stu.year==wheyear)return 1;
        p=p->next;
    }
    return 0;
}

inline int sort_three_cmp(int require,stunode *x,stunode *y,int ord)
{
	if(ord==2||ord==3)
	if(x->stu.Class!=y->stu.Class)
	return x->stu.Class<y->stu.Class;
    if(require<=4)return x->stu.cgpa>=y->stu.cgpa;
    return x->stu.csco>=y->stu.csco;
}

void sort_free(stunode *xxx,nstunode *yyy,nstunode *zzz)
{
	while(xxx!=NULL)
    {
        stunode *p=xxx;
        xxx=xxx->next;free(p);
    }
    while(yyy!=NULL)
    {
        nstunode *pp=yyy;
        yyy=yyy->next;free(pp);
        nstunode *ppp=zzz;
        zzz=zzz->next;free(ppp);
	}
	return;
}


void sort_print1(int req1,int req2)
{
    wsprintf(szBuffer,TEXT("-------------------------------------------------------------------------------------------------------------------"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,370,50+cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    wsprintf(szBuffer,TEXT("����    ѧ������    ѧ���Ա�     ��Դ��             ƽ���ɼ�          ƽ������"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,370,50+cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    return;
}

void sort_print2(stunode *stow,int studnum)
{
    wsprintf(szBuffer,TEXT("%d"),studnum);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,370 , 50+cyChar*(cnty-iVscrollPos) ,szBuffer,iTarget);
    wsprintf(szBuffer,TEXT("%s"),stow->stu.name);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,370+cxChar*7 , 50+cyChar*(cnty-iVscrollPos) ,szBuffer,iTarget);
    if(stow->stu.gender==1)
    {
    wsprintf(szBuffer,TEXT("��"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,370+cxChar*21,50+cyChar*(cnty-iVscrollPos),szBuffer,iTarget);
    }
    else 
    {
    wsprintf(szBuffer,TEXT("Ů"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,370+cxChar*21,50+cyChar*(cnty-iVscrollPos),szBuffer,iTarget);
    }
    wsprintf(szBuffer,TEXT("%s"),stow->stu.home);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,370+cxChar*29,50+cyChar*(cnty-iVscrollPos),szBuffer,iTarget);
    //printf("%.4lf\t\t%.4lf\n",stow->stu.csco,stow->stu.cgpa);
    sprintf(szBuffer,TEXT("%.4lf            %.4lf"),stow->stu.csco,stow->stu.cgpa);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,370+cxChar*43,50+cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    return;
}

void sort_three(int year,char majornow[],int ordern,int req_1,int req_2,int classre)
{
    
    int stunum=0,flag=0,wheright=0; 
    
    stunode *stur=NULL,*tmp=NULL,*stutail=NULL,*stulist=NULL;//������Ҫ�ŵ����ڻ����ͷ
    nstunode *nstulih=NULL,*nstulit=NULL;
    // �Լ����˳�ϵͳ��ʱ��Ҫ���һ��free���½�������
	//sort_free(stulist,nstulih,nstulit); �Ͱ����ŵ��˳�ϵͳ����һ��ִ�� 
    
    nstunode *nstunow1=NULL,*nstunow2=NULL,*ntmp=NULL;
    if(1)//��������ж����� ������ݻ���רҵ��û�иı� 
    {
        sort_free(stulist,nstulih,nstulit);
        
	    //��ʼ�Ƿ�
	    stunode *stunow=stulih,*p=stulih,*stulast=NULL;
		while(p!=NULL)
		{
			cptsg(p);
			p=p->next;
		}
		
        while(stunow!=NULL)
        {
            if(stunow->stu.year==year&&(strcmp(stunow->stu.major,majornow))==0)
            {
                stunum+=1;
                tmp=(stunode*)malloc(sizeof(stunode));
                tmp->stu=stunow->stu;
                if(req_2==2||req_2==6)
                {
                    tmp->stu.cgpa=tmp->stu.sgpa;
                    tmp->stu.csco=tmp->stu.ssco;
                }
                else if(req_2==3||req_2==7)
                    {
                        tmp->stu.cgpa=tmp->stu.tgpa;
                        tmp->stu.csco=tmp->stu.tsco;
                    }
                    else if(req_2==4||req_2==8)
                        {
                            tmp->stu.cgpa=tmp->stu.ogpa;
                            tmp->stu.csco=tmp->stu.osco;
                        }
                
                if(stulist==NULL)
                {
                    stulist=(stunode*)malloc(sizeof(stunode));
                    stulist=tmp;
                    stulist->next=NULL;
                    stulist->pre=NULL;
                    stutail=stulist;
                }
                else
                {
                    flag=0;
                    stur=stulist;
                    while(sort_three_cmp(req_2,stur,tmp,ordern)==1)
                    {
                        if(stur->next!=NULL)
                        stur=stur->next;
                        else
                        {
                            flag=1;
                            break;
                        }
                    }
                                
                    if(flag==0)
                    {
                        if(stur==stulist)
                        {
                            tmp->next=stur;
                            stur->pre=tmp;
                            stulist=tmp;
                        }
                        else
                        {
                            stulast=stur->pre;
                            stulast->next=tmp;
                            tmp->pre=stulast;
                            stur->pre=tmp;
                            tmp->next=stur;
                        }
                    }
                    else
                    {
                        stur->next=tmp;
                        tmp->pre=stur;
                        tmp->next=NULL;
                        stutail=tmp;
                    }
                }
            }
            stunow=stunow->next;
        }
        
        if(stulist==NULL)
        {
            MessageBox(NULL,TEXT("δ�鵽��ѧ����ѧ��ѧϰ��רҵ��ѧ��������������"),TEXT("��ʾ"),MB_OK);
			return;
		}
		
        int classn=0,numn=0;
		stunow=stulist;
		while(stunow!=NULL)
		{
			if(classn!=stunow->stu.Class)
			{
				classn=stunow->stu.Class;
				ntmp=(struct nstunode*)malloc(sizeof(struct nstunode));
				ntmp->Stu=stunow;ntmp->freenum=classn;ntmp->next=NULL;
				if(nstulih==NULL)
				{
					nstulih=(struct nstunode*)malloc(sizeof(struct nstunode));
					ntmp->pre=NULL;nstulih=ntmp;nstunow1=nstulih;
				}
				else
				{
					ntmp->pre=nstunow1;nstunow1->next=ntmp;nstunow1=ntmp;
					ntmp=(struct nstunode*)malloc(sizeof(struct nstunode));
					ntmp->Stu=stunow->pre;ntmp->next=NULL;ntmp->freenum=numn;
					if(nstulit==NULL)
					{
						nstulit=(struct nstunode*)malloc(sizeof(struct nstunode));
						ntmp->pre=NULL;nstulit=ntmp;nstunow2=nstulit;
					}
					else{ntmp->pre=nstunow2;nstunow2->next=ntmp;nstunow2=ntmp;}
				}
				numn=0;
			}
			numn+=1;
			stunow=stunow->next;
		}
		ntmp=(struct nstunode*)malloc(sizeof(struct nstunode));
		ntmp->Stu=stutail;ntmp->next=NULL;ntmp->freenum=numn;
		if(nstulit==NULL)
		{
			nstulit=(struct nstunode*)malloc(sizeof(struct nstunode));
			ntmp->pre=NULL;nstulit=ntmp;nstunow2=nstulit;
		}
		else{ntmp->pre=nstunow2;nstunow2->next=ntmp;nstunow2=ntmp;}
	}

	if(ordern==3)
	{
        wsprintf(szBuffer,TEXT("��ǰ�༶��:"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,0,0,szBuffer,iTarget);
		nstunow1=nstulih;
		while(nstunow1!=NULL)
		{
            wsprintf(szBuffer,TEXT("%d��  "),nstunow1->freenum);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,cxChar*(cntx++)*5,cyChar,szBuffer,iTarget);
			nstunow1=nstunow1->next;
		}
		cntx=0;
		do
		{
			nstunow1=nstulih;
			nstunow2=nstulit;
			while(nstunow1!=NULL)
			{
				if(nstunow1->freenum==classre)
				{
					sort_print1(req_1,req_2);
					if(req_1==0)
					stunum=1,stur=nstunow1->Stu;
					else stunum=nstunow2->freenum,stur=nstunow2->Stu;
	
					while(stur!=NULL)
					{
						if(stur->stu.Class!=classre)break;
						sort_print2(stur,stunum);
						if(req_1==0)
						{
							stur=stur->next;
							stunum+=1;
						}
						else
						{
							stur=stur->pre;
							stunum-=1;
						}
					}
							
					//ע������������ְ༶��Ϊ-1����� ��������
					wheright=1;
					break;
				}
				nstunow1=nstunow1->next;
				nstunow2=nstunow2->next;
			}
			if(wheright==0)
            {
                MessageBox(NULL,TEXT("�޸ð༶������������"),TEXT("��ʾ"),MB_OK);
                return;
            }
		}while(wheright==0);
	}
	else if(ordern==1)
	{
		sort_print1(req_1,req_2);
		if(req_1==0)
		stunum=1,stur=stulist;
		else stur=stutail;
		while(stur!=NULL)
		{
            sort_print2(stur,stunum);
            if(req_1==0)
            {stur=stur->next;stunum+=1;}
            else{stur=stur->pre;stunum-=1;}
        }
	}
	else
	{
		sort_print1(req_1,req_2);
		int classnow=0;
		nstunode *nstur=NULL;
        if(req_1==0)nstur=nstulih;
        else nstur=nstulit;
        while(nstur!=NULL)
        {
            stur=nstur->Stu;
            classnow=stur->stu.Class;
            wsprintf(szBuffer,TEXT("%d�ࣺ"),classnow);
            iTarget=lstrlen(szBuffer);
            TextOut(hdc,370,50+cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
            if(req_1==0)stunum=1;
            else stunum=nstur->freenum;
            while(stur!=NULL)
            {
                if(stur->stu.Class!=classnow)break;
                sort_print2(stur,stunum);
                if(req_1==0)
                {stur=stur->next;stunum+=1;}
                else{stur=stur->pre;stunum-=1;}
            }
			nstur=nstur->next;
		}
	}
    
    return;
}

void survey_subject(clsnode *Cls) //Cos:ָ��ǰ�γ̵�ָ�� Stu:ѧ��ͷָ��
{
    stunode *studentnow=stulih;
    cls *classnow=&(Cls->clsif);
    int studentnum=0;
    double allscore=0.0000,allgp=0.0000;
    double    failnum=0.0000,goodnum=0.0000,ecltnum=0.0000,fulgpnum=0.0000;
    double failrate,goodrate,ecltrate,fulgprate;
    double avgescore,avgegp;
    
    // allx ��x
    //xrate x��
    //xnum x����

    wsprintf(szBuffer,TEXT("��ʾ����ѧ��δ��ɸÿγ̵�ѧϰ����δ¼���������ɼ�Ϊ-1"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,0,cyChar*((cnty)-iVscrollPos),szBuffer,iTarget);
    
    wsprintf(szBuffer,TEXT("------------------------------------------------"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    wsprintf(szBuffer,TEXT("�������ѯ�Ŀγ�: %s"),classnow->id);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    wsprintf(szBuffer,TEXT("------------------------------------------------"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    wsprintf(szBuffer,TEXT("������Ϣ:"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    wsprintf(szBuffer,TEXT("ѧ������:"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty)-iVscrollPos),szBuffer,iTarget);
    if(classnow->nature==0)
    {
    wsprintf(szBuffer,TEXT("����"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450+cxChar*10,cyChar*((cnty)-iVscrollPos),szBuffer,iTarget);
    }
    else if(classnow->nature==0)
    {
    wsprintf(szBuffer,TEXT("ѡ��"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450+cxChar*10,cyChar*((cnty)-iVscrollPos),szBuffer,iTarget);
    }
    else
    {
    wsprintf(szBuffer,TEXT("��ѡ"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450+cxChar*10,cyChar*((cnty)-iVscrollPos),szBuffer,iTarget);
    }
    sprintf(szBuffer,TEXT("ѧ��:%.1lf"),classnow->cdt);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450+cxChar*16,cyChar*((cnty)-iVscrollPos),szBuffer,iTarget);
    wsprintf(szBuffer,TEXT("�ο���ʦ:%s"),classnow->teacher);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450+cxChar*26,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    wsprintf(szBuffer,TEXT("---------------------------------------------------------------------------"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    wsprintf(szBuffer,TEXT("ѧ��ѧϰ���:"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    
    studentnow=stulih;
    
    nstunode *newstulist=NULL,*newstunow=NULL,*tmp=NULL;
    //�½������ڵ�Ϊѡ���� �ÿγ̵�ѧ����newstulist �� ѧ���ÿγ̵���Ϣ��thecoslist
    
    while(studentnow!=NULL)             //Ѱ�����ѧ��
    {
        student stunow=studentnow->stu;
        if(stunow.scoreh->pre==NULL&&stunow.scoreh->next!=NULL)stunow.scoreh=stunow.scoreh->next;
        if(stunow.scoret->pre!=NULL)
		{
			cosnode *coursenow=stunow.scoret;
			while(coursenow!=NULL&&coursenow->pre!=NULL)
			{
				if(strcmp(coursenow->cos.c->id,Cls->clsif.id)==0)
				{
					tmp=(struct nstunode*)malloc(sizeof(struct nstunode));
					tmp->Stu=studentnow;
					tmp->Cos=coursenow;
					tmp->next=NULL;
					
					if(newstulist==NULL)
					{
						newstulist=(struct nstunode*)malloc(sizeof(struct nstunode));
						newstulist=tmp;
						newstulist->pre=NULL;
						newstunow=newstulist;
					}
					else
					{
						newstunow->next=tmp;
						tmp->pre=newstunow;
						newstunow=tmp;
					}
					double scorenow=coursenow->cos.score;
					double gpnow=coursenow->cos.gp;
					if(scorenow>=0)
					{
						studentnum+=1;
						allscore+=scorenow;
						allgp+=gpnow;
					}
					if(gpnow>=3.0000)
					{
						goodnum+=1;
						if(gpnow>=3.7000)
						{
							ecltnum+=1;
							if(gpnow==4.0000)
							fulgpnum+=1;
						}
					}
					else if(scorenow<60.0000&&scorenow>=0)
					failnum+=1;
					break;
				}
				coursenow=coursenow->pre;
			}
			studentnow=studentnow->next;
		}
	}
        
    
    if(newstulist==NULL)
    {
        wsprintf(szBuffer,TEXT("δ�鵽ѡ��ÿγ̵�ѧ�������޷���ʾѧ��������"));
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        return;
    }
    
    //�Ʒ� ����
    if(studentnum!=0)
    {
    	avgescore=allscore/studentnum;
	    avgegp=allgp/studentnum;
	    failrate=failnum/studentnum;
	    goodrate=goodnum/studentnum;
	    ecltrate=ecltnum/studentnum;
	    fulgprate=fulgpnum/studentnum;
	}
	else
	{
		avgescore=0.0000;
	    avgegp=0.0000;
	    failrate=0.0000;
	    goodrate=0.0000;
	    ecltrate=0.0000;
	    fulgprate=0.0000;
	}
	
    newstunow=newstulist;
    nstunode *newstulast=NULL,*newstux=NULL,*newstuy=NULL,*newstut=NULL;
    
    while(newstunow!=NULL)
    {
        newstux=newstulist;
        
        while(newstux->Cos->cos.score>=newstunow->Cos->cos.score&&newstux!=newstunow)
        {
            newstuy=newstux;
            newstux=newstux->next;
        }
        if(newstux!=newstunow)
        {
            newstut=newstunow;
            newstulast->next=newstunow->next;
            newstunow=newstulast;
            
            if(newstux==newstulist)
            {
                newstut->next=newstulist;
                newstulist=newstut;
            }
            else
            {
                newstuy->next=newstut;
                newstut->next=newstux;
            }
        }
        
        newstulast=newstunow;
        newstunow=newstunow->next;
    }
    
    sprintf(szBuffer,TEXT("����:%10.4lf  ����:%10.4lf"),avgescore,avgegp);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    sprintf(szBuffer,TEXT("�ҿ���:%.4lf%%   ������:%.4lf%%"),failrate*100.0000,goodrate*100.0000);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    sprintf(szBuffer,TEXT("������:%.4lf%%   ������:%.4lf%%"),ecltrate*100.0000,fulgprate*100.0000);
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    sprintf(szBuffer,TEXT("---------------------------------------------------------------------------"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    sprintf(szBuffer,TEXT("ѧ������              �ÿγɼ�         �ÿμ���"));
    iTarget=lstrlen(szBuffer);
    TextOut(hdc,450,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
    while(newstulist!=NULL)
    {
        sprintf(szBuffer,TEXT("%-20s"),newstulist->Stu->stu.name);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,450,cyChar*((cnty)-iVscrollPos),szBuffer,iTarget);
        sprintf(szBuffer,TEXT("%-10d"),newstulist->Cos->cos.score);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,450+cxChar*20,cyChar*((cnty)-iVscrollPos),szBuffer,iTarget);
        sprintf(szBuffer,TEXT("%-10.4lf"),newstulist->Cos->cos.gp);
        iTarget=lstrlen(szBuffer);
        TextOut(hdc,450+cxChar*30,cyChar*((cnty++)-iVscrollPos),szBuffer,iTarget);
        newstulist=newstulist->next;
    }
    while(newstulist!=NULL)
    {
        nstunode *p=newstulist;
        free(p);
        newstulist=newstulist->next;
    }
    return;
}

void inputstuascr(int choose)
{
    if(choose==0)
        AESorSSon1Window();
    if(choose==1)
    {
        char str[1000];
        stunode *stunow=stulih;
        nstulihh=NULL;
        emptynum=0;
        nstunode *tmp=NULL,*nstunow=NULL;
        strcpy(str,clstobe->clsif.name);
        while(stunow!=NULL)
        {
            if(stunow->stu.scoreh->pre==NULL&&stunow->stu.scoreh->next!=NULL)stunow->stu.scoreh=stunow->stu.scoreh->next;
            cosnode *cosn=stunow->stu.scoret;
            while(cosn!=NULL&&cosn->pre!=NULL)
            {
                if(strcmp(cosn->cos.c->name,str)==0)
                {
                    if(cosn->cos.score==-1)
                    {
                        emptynum+=1;
                        tmp=(struct nstunode*)malloc(sizeof(struct nstunode));
                        tmp->Stu=stunow;tmp->Cos=cosn;tmp->next=NULL;tmp->pre=NULL;
                        if(nstulihh==NULL)
                        {
                            nstulihh=(struct nstunode*)malloc(sizeof(struct nstunode));
                            nstulihh=tmp;nstunow=nstulihh;
                        }
                        else
                        {
                            nstunow->next=tmp;
                            tmp->pre=nstunow;
                            nstunow=tmp;
                        }
                    }
                break;
                }
                cosn=cosn->pre;
            }
            stunow=stunow->next;
        }
        
        if(nstulihh==NULL)
        {
            MessageBox(NULL,TEXT("��ǰ�γ�δ�鵽ѧ����Ҫ¼��ɼ�"),TEXT("��ʾ"),MB_OK);
            return;
        }
        
        nstuinall=nstulihh;
        AESorSSon2Window();
        while(nstulihh!=NULL)
        {
            nstunode *p=nstulihh;
            nstulihh=nstulihh->next;
            free(p);
        }
    }
    return;
}
#endif
