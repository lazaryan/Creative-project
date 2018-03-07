//**********************‘ ง ฎกฌฅฆฅญฎ๎ คฎขฆจญฎ๎ ็ฅเฃจ*********************
#include <conio.h>
#include <iostream.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>
#define size  10
#define DOWN  80
#define UP    72
#define ENTER 13

float lam=7;
float mu=2;
int n=5;
int m=7;
float Q=0.97;
float eps=0.03;

struct Request
{
	int Num;
	unsigned long Time;
	unsigned long Time_format;
};

struct Channel
{
	int Busy;
	int NumReq;
	unsigned long TimeBegin;
	unsigned long TimeBegin_format;
	float TimeToProcess;
};

Channel ChanArray[size];
Request ReqArray[size];
float ProcTime[size];
int ReqInArray;
long unsigned LastRequestTime;
float LastRivnVar;
int CurReqNum=1;

void Phon(void);
//-------------------------------‘โฅฏiญ์ ็จแซ ------------------------------
unsigned long Stepen(int a,int b)
{
	unsigned long s=a;
	for(int i=1;i<b;i++)
		s*=a;
	return s;
}
//--------------------------------------------------------------------------

//------------------------------” ชโฎเi ซ ็จแซ -----------------------------
int Faktor(int c)
{
	int i=1;
	int f=1;
	do
		f*=i++;
	while (i<=c);
	return f;
}
//--------------------------------------------------------------------------

//------------------------------‘จแโฅฌญจฉ ็ แ-------------------------------
unsigned long GetSTime(int format)
{
	struct time t;
	gettime(&t);
	if (!format)
		return ((unsigned long)t.ti_hour*1000000+(unsigned long)t.ti_min*10000+(unsigned long)t.ti_sec*100+(unsigned long)t.ti_hund);
	else
		return ((unsigned long)t.ti_hour*100*60*60+(unsigned long)t.ti_min*100*60+(unsigned long)t.ti_sec*100+(unsigned long)t.ti_hund);
}
//--------------------------------------------------------------------------

//-----ฅญฅเ โฎเ ฏแฅขคฎ-ขจฏฎคชฎขจๅ ็จแฅซ ง เiขญฎฌiเญจฌ เฎงฏฎคiซฎฌ-----------
float RivnRoz()
{
	int i;
	unsigned long n;
	float nn;
	i=random(100);
	const int  M=1236;
	const int  L=3;
	const int n0=225;
	const int  m=300;
	n=Stepen(L,i)*n0+((M*(Stepen(L,i)-1)/(L-1)))%m;
	nn=(n-(n/1000)*1000)/1000.0;
	return (nn*2*lam);
}
//--------------------------------------------------------------------------

//--------------------------”ฎเฌใข ญญ๏ ง ๏ขฎช-------------------------------
int GetRequest(Request &rq)
{
	int f=0;
	unsigned long SystemTime;
	SystemTime=GetSTime(1);
	if ((SystemTime-LastRequestTime)>=LastRivnVar)
	{
		delay(1);
		LastRivnVar=RivnRoz();
		rq.Num=CurReqNum;
		rq.Time=SystemTime;
		rq.Time_format=GetSTime(0);
		LastRequestTime=SystemTime;
		if (CurReqNum>=100) CurReqNum=1;
		else CurReqNum++;
		f=1;
	}
//	else cout<<"\n????";
//	getch();
	return f;
//--------------------------------------------------------------------------

//--------------------------ขiซ์ญฅญญ๏ ช ญ ซiข------------------------------
}
void CheckChannels(int &SumBusyChan)
{
	unsigned long SystemTime;
	unsigned long t;
	int th,tx,ts,tm;
	SystemTime=GetSTime(1);
	for(int i=0;i<n;i++)
		if  (ChanArray[i].Busy)
		{
			SumBusyChan++;
			if (SystemTime-ChanArray[i].TimeBegin>=ChanArray[i].TimeToProcess)
			{
				ChanArray[i].Busy=0;
				t=GetSTime(0);
				tm=t%100;
				ts=(t%10000)/100;
				tx=(t%1000000)/10000;
				th=(t%100000000)/1000000;
				gotoxy(16,22);
				cprintf(" ๏ขช  ü%d ฏฎชจญใซ  แจแโฅฌใ ฎ %d:%d:%d.%d   ",ChanArray[i].NumReq,th,tx,ts,tm);
			}
		}
}
//--------------------------------------------------------------------------

//--------------------------กแซใฃฎขใข ญญ๏ ง ๏ขฎช---------------------------
int ProcessRequest(Request &rq)
{
	int f=0;
	for(int i=0;i<n;i++)
		if (!ChanArray[i].Busy)
		{
			ChanArray[i].TimeBegin=GetSTime(1);
			ChanArray[i].TimeBegin_format=GetSTime(0);
			ChanArray[i].TimeToProcess=ProcTime[i];
			ChanArray[i].Busy=1;
			ChanArray[i].NumReq=rq.Num;
			f=1;
			break;
		}
	return f;
}
//--------------------------------------------------------------------------

//--------------------------”ฎเฌใข ญญ๏ ็ฅเฃจ--------------------------------
int InsertIntoOchered(Request &rq,long &vid)
{
	int f=0;
	if (ReqInArray<m)
	{
		ReqArray[ReqInArray++]=rq;
		f=1;
	}
	else
	{
	 gotoxy(16,22);
	 cout<<" ๏ขๆi กใซฎ ขiคฌฎขจซ  ข ฎกแซใฃฎขใข ญญi  ";
	 vid++;
	}
	return f;
}
//--------------------------------------------------------------------------

//------------------------จคiซฅญญ๏ ง ๏ขฎช ง ็ฅเฃจ--------------------------
int GetFromOchered(Request &rq)
{
	int f=0;
	if (ReqInArray>0)
	{
		rq=ReqArray[0];
		for(int i=0;i<ReqInArray-1;i++)
		{
			ReqArray[i].Time=ReqArray[i+1].Time;
			ReqArray[i].Time_format=ReqArray[i+1].Time_format;
			ReqArray[i].Num=ReqArray[i+1].Num;
		}
		ReqInArray--;
		f=1;
	}
	return f;
}
//--------------------------------------------------------------------------

//----------------------------’ฅฎเฅโจ็ญi ฎกเ ๅใญชจ--------------------------

void TeoretObrahynok(void)
{
	float Tobsl,Toch,Tsystem,psi,P0,P1,x;
	float Pvid,q,a,z;
	float r=0;
	Tobsl=1/mu;
	psi=lam/mu;
	P0=0;
	x=psi/n;
	for(int i=0;i<=n;i++)
		P0+=pow(psi,i)/Faktor(i);
	for(i=1;i<=m;i++)
		P0+=pow(psi,n+i)/(Faktor(n)*pow(n,i));
	P0=1/P0;
	Pvid=(pow(psi,(n+m))/(pow(n,m)*Faktor(n)))*P0;
	q=1-Pvid;
	a=lam*q;
	z=a/mu;
	for(i=0;i<m;i++)
		r+=(i+1)*pow(x,i);
	r*=((pow(psi,(n+1))*P0)/(Faktor(n)))/n;
	Toch=r/lam;
	Tsystem=Toch+q*Tobsl;

	//ขจขฎค เฅงใซ์โ โiข
	Phon();
	textcolor(BLACK);
	textbackground(BLACK);
	gotoxy(14,22);
	cprintf("                                                      ");
	for(i=4;i<22;i++)
	{
		gotoxy(67,i);
		putch(' ');
	}
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(13,3);
	cprintf("ษออออออออออออออออ’ฅฎเฅโจ็ญi เฎงเ ๅใญชจอออออออออออออออป");
	gotoxy(13,4);
	cprintf("บ  lam=%.2f  mu=%.2f  n=%d  m=%d  Q=%.2f  eps=%.4f   บ",lam,mu,n,m,Q,eps);
	gotoxy(13,5);
	cprintf("ฬอออออออออออออออออออออออออออออออออออออออออออออหออออออน");
	gotoxy(13,6);
	cprintf("บ Iฌฎขiเญiแโ์ ฏเฎแโฎ๎ ช ญ ซใ ฎกแซใฃฎขใข ญญ๏ Poบ%.4fบ",P0);
	gotoxy(13,7);
	cprintf("ฬอออออออออออออออออออออออออออออออออออออออออออออฮออออออน");
	gotoxy(13,8);
	cprintf("บ Iฌฎขiเญiแโ์ ขiคฌฎขจ Pvid                    บ%.4fบ",Pvid);
	gotoxy(13,9);
	cprintf("ฬอออออออออออออออออออออออออออออออออออออออออออออฮออออออน");
	gotoxy(13,10);
	cprintf("บ iคญฎแญ  ฏเฎฏใแชญ  งค โญiแโ์ q              บ%.4fบ",q);
	gotoxy(13,11);
	cprintf("ฬอออออออออออออออออออออออออออออออออออออออออออออฮออออออน");
	gotoxy(13,12);
	cprintf("บ €กแฎซ๎โญ  ฏเฎฏใแชญ  งค โญiแโ์ a             บ%.4fบ",a);
	gotoxy(13,13);
	cprintf("ฬอออออออออออออออออออออออออออออออออออออออออออออฮออออออน");
	gotoxy(13,14);
	cprintf("บ ‘ฅเฅคญ๓ ็จแซฎ ง ฉญ๏โจๅ ช ญ ซiข  z           บ%.4fบ",z);
	gotoxy(13,15);
	cprintf("ฬอออออออออออออออออออออออออออออออออออออออออออออฮออออออน");
	gotoxy(13,16);
	cprintf("บ ‘ฅเฅคญ๓ ็จแซฎ ง ๏ขฎช ใ ็ฅเงi  r             บ%.4fบ",r);
	gotoxy(13,17);
	cprintf("ฬอออออออออออออออออออออออออออออออออออออออออออออฮออออออน");
	gotoxy(13,18);
	cprintf("บ ‘ฅเฅคญiฉ ็ แ ็ฅช ญญ๏ ข ็ฅเงi Toch           บ%.4fบ",Toch);
	gotoxy(13,19);
	cprintf("ฬอออออออออออออออออออออออออออออออออออออออออออออฮออออออน");
	gotoxy(13,20);
	cprintf("บ ‘ฅเฅคญiฉ ็ แ ฏฅเฅกใข ญญ๏  ข แจแโฅฌi Tsystem บ%.4fบ",Tsystem);
	gotoxy(13,21);
	cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออสออออออผ");

}
//--------------------------------------------------------------------------

//-----------------------------------ฎคฅซ์---------------------------------
void Model(void)
{
	LastRequestTime=0;
	LastRivnVar=0;
	ReqInArray=0;
	for(int i=0;i<n;i++)
		ChanArray[i].Busy=0;
	for(i=0;i<n;i++)
		ProcTime[i]=lam/mu*50;//*5.5;
	Request rq,rqTmp;
	float Tobsl,Toch,Tsystem;
	float q,a,z;
	float r=0;
	long shet=0;
	long vid=0;
	long schetReq=0;
	float p,NumRealiz,TimeRealiz;
	int SumBusyChan=0;
	int SumReqInOcher=0;
	unsigned long t;
	int th,tx,ts,tm;

	Phon();
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(3,2);
	cprintf("ษออออออออัอออหอออออออัอออออออออออัอออออออออัออออออออป");
	gotoxy(3,3);
	cprintf("บ        ณ ü บ  ญ๏โ.ณ — แ ฏฎแโ. ณ— แ ฎกแซ.ณü ง ๏ขชจบ");
	gotoxy(3,4);
	cprintf("ฬออออออออุอออฮอออออออุอออออออออออุอออออออออุออออออออน");
	gotoxy(3,5);
	cprintf("บ  ญ ซจ ณ 1 บ       ณ           ณ         ณ        บ");
	for(i=2;i<=n;i++)
	{
		gotoxy(3,4+i);
		cprintf("บ        ณ %d บ       ณ           ณ         ณ        บ",i);
	}
	gotoxy(3,5+n);
	cprintf("ฬออออออออุอออฮอออออออุอออออออออออุอออออออออุออออออออน");
	gotoxy(3,6+n);
	cprintf("บ —ฅเฃ   ณ 1 บ       ณ           ณ         ณ        บ");
	for(i=2;i<=m;i++)
	{
		gotoxy(3,5+n+i);
		cprintf("บ        ณ %d บ       ณ           ณ         ณ        บ",i);
	}
	gotoxy(3,6+n+m);
	cprintf("ศออออออออฯอออสอออออออฯอออออออออออฯอออออออออฯออออออออผ");
	textcolor(BLACK);
	textbackground(BLACK);
	gotoxy(4,7+n+m);
	cprintf("                                                     ");
	for(i=3;i<7+n+m;i++)
	{
		gotoxy(56,i);
		putch(' ');
	}

	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(59,4);
	cprintf("ษอออออออออออออออออป");
	gotoxy(59,5);
	cprintf("บ  ฎช งญจชจ ‘  บ");
	gotoxy(59,6);
	cprintf("ฬออออออหออออออออออน");
	gotoxy(59,7);
	cprintf("บ Pvid บ          บ");
	gotoxy(59,8);
	cprintf("บ q    บ          บ");
	gotoxy(59,9);
	cprintf("บ a    บ          บ");
	gotoxy(59,10);
	cprintf("บ z    บ          บ");
	gotoxy(59,11);
	cprintf("บ r    บ          บ");
	gotoxy(59,12);
	cprintf("บ Tche บ          บ");
	gotoxy(59,13);
	cprintf("บ Tsys บ          บ");
	gotoxy(59,14);
	cprintf("บ Nrel บ          บ");
	gotoxy(59,15);
	cprintf("บ Trel บ          บ");
	gotoxy(59,16);
	cprintf("ศออออออสออออออออออผ");
	textcolor(BLACK);
	textbackground(BLACK);
	gotoxy(60,17);
	cprintf("                   ");
	for(i=4;i<17;i++)
	{
		gotoxy(78,i);
		putch(' ');
	}

	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(15,21);
	cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออออป");
	gotoxy(15,22);
	cprintf("บ                                                  บ");
	gotoxy(15,23);
	cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออออผ");
	textcolor(BLACK);
	textbackground(BLACK);
	gotoxy(16,24);
	cprintf("                                                    ");
	for(i=22;i<25;i++)
	{
		gotoxy(67,i);
		putch(' ');
	}

	textcolor(WHITE);
	textbackground(BLUE);
	do
	{

		CheckChannels(SumBusyChan);
		if (GetRequest(rqTmp))
		{
			schetReq++;
			if (!ProcessRequest(rqTmp))
				InsertIntoOchered(rqTmp,vid);
		}
		for(int i=0;i<n;i++)
			if (!ChanArray[i].Busy)
				if (GetFromOchered(rqTmp))
				{
					ChanArray[i].TimeBegin=GetSTime(1);
					ChanArray[i].TimeBegin_format=GetSTime(0);
					ChanArray[i].TimeToProcess=ProcTime[i];
					ChanArray[i].Busy=1;
					ChanArray[i].NumReq=rqTmp.Num;
				}
		shet++;
		SumReqInOcher+=ReqInArray;
	//	p=(float)vid/schetReq;
		z=(float)SumBusyChan/shet;
		r=(float)SumReqInOcher/shet;
		a=z*mu;
		q=a/lam;
		p=1-q;
		Toch=r/lam;
		Tobsl=1/mu;
		Tsystem=Toch+q*Tobsl;
		NumRealiz=p*(1-p)*Q*Q/(4*eps*eps);
		TimeRealiz=NumRealiz*Tsystem;

		for(i=0;i<n;i++)
		if (ChanArray[i].Busy)
		{
			gotoxy(19,5+i);
			cprintf("’ ช");
			gotoxy(25,5+i);
			t=ChanArray[i].TimeBegin_format;
			tm=t%100;
			ts=(t%10000)/100;
			tx=(t%1000000)/10000;
			th=(t%100000000)/1000000;
			cout<<"           ";
			gotoxy(25,5+i);
			cprintf("%0d:%0d:%0d.%0d",th,tx,ts,tm);
			gotoxy(40,5+i);
			cprintf("%.0f",lam/mu*100);
			gotoxy(51,5+i);
			cprintf("%d",ChanArray[i].NumReq);
		}
		else
		{
			gotoxy(19,5+i);
			cprintf("i ");
			gotoxy(25,5+i);
			cprintf("           ");
			gotoxy(40,5+i);
			cprintf("      ");
			gotoxy(51,5+i);
			cprintf("    ");
		}
		for(int j=0;j<m;j++)
		if (j<ReqInArray)
		{
			gotoxy(19,6+n+j);
			cprintf("’ ช");
			gotoxy(25,6+n+j);
			t=ReqArray[j].Time_format;
			tm=t%100;
			ts=(t%10000)/100;
			tx=(t%1000000)/10000;
			th=(t%100000000)/1000000;
			cout<<"           ";
			gotoxy(25,6+n+j);
			cprintf("%0d:%0d:%0d.%0d",th,tx,ts,tm);
			gotoxy(51,6+n+j);
			cprintf("%d",ReqArray[j].Num);
		}
		else
		{
			gotoxy(19,6+n+j);
			cprintf("i ");
			gotoxy(25,6+n+j);
			cprintf("           ");
			gotoxy(51,6+n+j);
			cprintf("    ");
		}
		gotoxy(67,7);
		cprintf("%.4f",p);
		gotoxy(67,8);
		cprintf("%.4f",q);
		gotoxy(67,9);
		cprintf("%.4f",a);
		gotoxy(67,10);
		cprintf("%.4f",z);
		gotoxy(67,11);
		cprintf("%.4f",r);
		gotoxy(67,12);
		cprintf("%.4f",Toch);
		gotoxy(67,13);
		cprintf("%.4f",Tsystem);
		gotoxy(67,14);
		cprintf("%.4f",NumRealiz);
		gotoxy(67,15);
		cprintf("%.4f",TimeRealiz);
	}
	while (getch()!=ENTER);
}
//--------------------------------------------------------------------------

//--------------------------------- เ ฌฅโเจ--------------------------------

void Parametr(void)
{
	Phon();
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(10,8);
	cprintf("ษออออออออออออออออออออออออออออออออออออออออป");
	gotoxy(10,9);
	cprintf("บ lam - iญโฅญแจขญiแโ์ ญ คๅฎคฆฅญญ๏ ง ๏ขฎช บ");
	gotoxy(10,10);
	cprintf("บ mu  - iญโฅญแจขญiแโ์ ฎกแซใฃฎขใข ญญ๏     บ");
	gotoxy(10,11);
	cprintf("บ n   - ็จแซฎ ช ญ ซiข ฎกแซใฃฎขใข ญญ๏     บ");
	gotoxy(10,12);
	cprintf("บ m   - ็จแซฎ ฌiแๆ์ ใ ็ฅเงi              บ");
	gotoxy(10,13);
	cprintf("บ Q   - เiขฅญ์ คฎขiเจ                    บ");
	gotoxy(10,14);
	cprintf("บ eps - โฎ็ญiแโ์                         บ");
	gotoxy(10,15);
	cprintf("ศออออออออออออออออออออออออออออออออออออออออผ");
	textcolor(BLACK);
	textbackground(BLACK);
	gotoxy(11,16);
	cprintf("                                          ");
	for(int i=9;i<16;i++)
	{
		gotoxy(52,i);
		putch(' ');
	}

	textcolor(BLACK);
	textbackground(BLACK);
	gotoxy(59,22);
	cprintf("                 ");
	for(i=4;i<22;i++)
	{
		gotoxy(75,i);
		putch(' ');
	}
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(58,3);
	cprintf("ษอออออออออออออออป");
	gotoxy(58,4);
	cprintf("บ   ฏฎฏฅเฅคญi:  บ");
	gotoxy(58,5);
	cprintf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	gotoxy(58,6);
	cprintf("บ lam = %.2f    บ",lam);
	gotoxy(58,7);
	cprintf("บ mu  = %.2f    บ",mu);
	gotoxy(58,8);
	cprintf("บ n   = %d       บ",n);
	gotoxy(58,9);
	cprintf("บ m   = %d       บ",m);
	gotoxy(58,10);
	cprintf("บ Q   = %.2f    บ",Q);
	gotoxy(58,11);
	cprintf("บ eps = %.3f   บ",eps);
	gotoxy(58,12);
	cprintf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	gotoxy(58,13);
	cprintf("บ     ญฎขi:     บ");
	gotoxy(58,14);
	cprintf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	gotoxy(58,15);
	cprintf("บ lam =         บ");
	gotoxy(58,16);
	cprintf("บ mu  =         บ");
	gotoxy(58,17);
	cprintf("บ n   =         บ");
	gotoxy(58,18);
	cprintf("บ m   =         บ");
	gotoxy(58,19);
	cprintf("บ Q   =         บ");
	gotoxy(58,20);
	cprintf("บ eps =         บ");
	gotoxy(58,21);
	cprintf("ศอออออออออออออออผ");
	_setcursortype(2);
	gotoxy(66,15);
	cin>>lam;
	gotoxy(66,16);
	cin>>mu;
	gotoxy(66,17);
	cin>>n;
	gotoxy(66,18);
	cin>>m;
	gotoxy(66,19);
	cin>>Q;
	gotoxy(66,20);
	cin>>eps;
	_setcursortype(0);
}
//--------------------------------------------------------------------------

//--------------------------------ฎขiคช -----------------------------------
void About(void)
{
	Phon();
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(19,8);
	cprintf("ษออออออออออออออออออออออออออออออออออออออออป");
	gotoxy(19,9);
	cprintf("บ             ใเแฎข  เฎกฎโ              บ");
	gotoxy(19,10);
	cprintf("บ                ญ  โฅฌใ:                บ");
	gotoxy(19,11);
	cprintf("บ            ฃ โฎช ญ ซ์ญ  ‘ ง         บ");
	gotoxy(19,12);
	cprintf("บ         ฎกฌฅฆฅญฎ๎ คฎขฆจญฎ๎ ็ฅเฃจ       บ");
	gotoxy(19,13);
	cprintf("บ                ฏฎ ชใเแใ:               บ");
	gotoxy(19,14);
	cprintf("บ         ฎฌฏ'๎โฅเญฅ ฌฎคฅซ๎ข ญญ๏        บ");
	gotoxy(19,15);
	cprintf("ศออออออออออออออออออออออออออออออออออออออออผ");
	textcolor(BLACK);
	textbackground(BLACK);
	gotoxy(20,16);
	cprintf("                                          ");
	for(int i=9;i<16;i++)
	{
		gotoxy(61,i);
		putch(' ');
	}
}
//--------------------------------------------------------------------------

//-------------------------------จงญ ็ฅญญ๏ ไฎญใ----------------------------
void Phon(void)
{
 textbackground(BLACK);
 clrscr();
 textcolor(BLUE);
 for(int i=1; i<2080; i++)
	putch('ฑ');
}
//--------------------------------------------------------------------------

//------------------------------ฎกใคฎข  เ ฌชจ------------------------------
void Ramka(int x)
{
	gotoxy(28,x);
	cprintf("ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ");
	gotoxy(28,x+1);
	cprintf("ณ");
	gotoxy(52,x+1);
	cprintf("ณ");
	gotoxy(28,x+2);
	cprintf("ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู");
}
//--------------------------------------------------------------------------

//-------------------------------ฎซฎขญฅ ฌฅญ๎--- ---------------------------
void Menu(void)
{
	textcolor(WHITE);
	textbackground(BLUE);
	for(int i=28;i<53;i++)
		for(int j=5;j<22;j++)
		{
			gotoxy(i,j);
			putch(' ');
		}
	gotoxy(27,4);
	cprintf("ษออออออออออ ‘ ออออออออออป");
	gotoxy(27,7);
	cprintf("  ’ฅฎเฅโจ็ญi เฎงเ ๅใญชจ   ");
	gotoxy(27,10);
	cprintf("  ฎคฅซ์***************   ");
	gotoxy(27,13);
	cprintf("   เ ฌฅโเจ************   ");
	gotoxy(27,16);
	cprintf("  ฎขiคช **************   ");
	gotoxy(27,19);
	cprintf("  จๅiค****************   ");
	gotoxy(27,22);
	cprintf("ศอออออออออออออออออออออออออผ ");
	for(i=5;i<22;i++)
	{
		gotoxy(27,i);
		putch('บ');
		gotoxy(53,i);
		putch('บ');
	}

	textcolor(BLACK);
	textbackground(BLACK);
	gotoxy(29,23);
	cprintf("                          ");
	for(i=5;i<24;i++)
	{
		gotoxy(54,i);
		putch(' ');
	}
}

void main()
{
	clrscr();
	randomize();
	int s=1;
	int ch;
	_setcursortype(0);
	Phon();
	for(;;)
	{
		Menu();
		textcolor(RED);
		textbackground(BLUE);
		switch (s)
		{
			case 1:
			Ramka(6);
			if (getch()==ENTER)
			{
				TeoretObrahynok();
				getch();
				Phon();
			}
			break;
			case 2:
			Ramka(9);
			if (getch()==ENTER)
			{
				Model();
				getch();
				Phon();
			}
			break;
			case 3:
			Ramka(12);
			if (getch()==ENTER)
			{
				Parametr();
				getch();
				Phon();
			}
			break;
			case 4:
			Ramka(15);
			if (getch()==ENTER)
			{
				About();
				getch();
				Phon();
			}
			break;
			case 5:
			Ramka(18);
			if (getch()==ENTER) exit(1);
		}
		ch=getch();
		if (ch==DOWN) if (s==5) s=1; else s++;
		if (ch==UP)   if (s==1) s=5; else s--;
	}
	_setcursortype(2);
}