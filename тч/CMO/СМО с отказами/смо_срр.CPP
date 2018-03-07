#define SPEED 3
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<string.h>
#include<time.h>
#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class TimeClass
{
		struct time sTime;
	public:
		TimeClass& SetTime (double=0);
		TimeClass& SetCurrentTime();
		TimeClass& operator+=(TimeClass);
		TimeClass  operator+(TimeClass);
		char IsMore(TimeClass);
		int get_hour()const {return sTime.ti_hour;};
		int get_min ()const {return sTime.ti_min ;};
		int get_sec ()const {return sTime.ti_sec ;};
		int get_hund()const {return sTime.ti_hund;};
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TimeClass&TimeClass::SetTime(double t)
{
	t*=SPEED;
	sTime.ti_hour=0;
	sTime.ti_min =0;
	sTime.ti_sec =0;
	sTime.ti_hund=0;
	if(t>=3600)
	{
		sTime.ti_hour = t/3600;
		t-=3600*sTime.ti_hour;
	}
	if(t>=60)
	{
		sTime.ti_min = t/60;
		t-=60*sTime.ti_min;
	}
	if(t>=1)
	{
		sTime.ti_sec = t;
		t-=sTime.ti_sec;
	}
	sTime.ti_hund =t*100;
	return *this;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
char TimeClass::IsMore(TimeClass t)
{
	if(sTime.ti_hour==t.sTime.ti_hour)
	{
		if(sTime.ti_min==t.sTime.ti_min)
		{
			if(sTime.ti_sec==t.sTime.ti_sec)
			{
				if(sTime.ti_hund==t.sTime.ti_hund)
					return 1;
				else
					return (sTime.ti_hund>t.sTime.ti_hund);
			}
			else
				return (sTime.ti_sec>t.sTime.ti_sec);
		}
		else
			return (sTime.ti_min>t.sTime.ti_min);
	}
	else
		return (sTime.ti_hour>t.sTime.ti_hour);
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TimeClass& TimeClass::operator+=(TimeClass t2)
{
	char over=0;
	if((sTime.ti_hund+=t2.get_hund())>=100)
	{
		sTime.ti_hund-=100;
		over = 1;
	}
	if((sTime.ti_sec+=t2.get_sec()+over)>=60)
	{
		sTime.ti_sec-=60;
		over = 1;
	}
	else
		over = 0;
	if((sTime.ti_min+=t2.get_min()+over)>=60)
	{
		sTime.ti_min-=60;
		over = 1;
	}
	else
		over = 0;
	if((sTime.ti_hour+=t2.get_hour()+over)>=60)
		sTime.ti_hour-=60;
	return *this;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ostream& operator<<(ostream& s,TimeClass t)
{
	return s	<<((t.get_hour()<10)?("0"):(""))<<t.get_hour()
				<<"h "<<((t.get_min()<10)?("0"):(""))<<t.get_min()
				<<"m "<<((t.get_sec()<10)?("0"):(""))<<t.get_sec()
				<<"."<<((t.get_hund()<10)?("0"):(""))<<t.get_hund()<<"s";
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TimeClass TimeClass::operator+(TimeClass t2)
{
	TimeClass t=*this;
	char over=0;
	if((t.sTime.ti_hund+=t2.get_hund())>100)
	{
		t.sTime.ti_hund-=100;
		over = 1;
	}
	if((t.sTime.ti_sec+=t2.get_sec()+over)>60)
	{
		t.sTime.ti_sec-=60;
		over = 1;
	}
	else
		over = 0;
	if((t.sTime.ti_min+=t2.get_min()+over)>60)
	{
		t.sTime.ti_min-=60;
		over = 1;
	}
	else
		over = 0;
	if((t.sTime.ti_hour+=t2.get_hour()+over)>60)
		sTime.ti_hour-=60;
	return t;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TimeClass& TimeClass::SetCurrentTime()
{
	gettime(&sTime);
	return *this;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//*************ChanalClass**********************************
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
struct OutPutKanalStrukt
{
	int Changed;
	int Query;
	TimeClass End;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class ChanalClass
{
	public://private:
		void OutPutKanal(int);
		double dMiu;
		TimeClass EndTime;
		TimeClass ProcesTime;
		TimeClass CurrentTime;
		OutPutKanalStrukt Out;
	public:
		void Init();
		int GetStatus();
		void Process();
		int SetStatus(int);
};
void ChanalClass::Init()
{
	Out.Query = 0;
	dMiu=3;
	CurrentTime.SetCurrentTime();
	ProcesTime.SetTime(1./dMiu);

};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int ChanalClass::GetStatus()
{
	if(Out.Query==0)
		return 0;
	else
		return 1;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void ChanalClass::Process()
{
	Out.Changed = 0;
	CurrentTime.SetCurrentTime();
	if(GetStatus()&&(CurrentTime.IsMore(EndTime)))
		SetStatus(0);
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int ChanalClass::SetStatus(int n)
{
	Out.Changed = 0;
	int st=!GetStatus();
	if(st)
	{
		EndTime.SetCurrentTime();
		EndTime += ProcesTime;
		Out.Changed = 1;
		Out.Query = n;
	}
	if(!n)
	{
		Out.Changed = 1;
		Out.Query = n;
	};
	return st;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void ChanalClass::OutPutKanal(int i)
{
	if(Out.Changed)
	{
		gotoxy(45,8+i*2);
		cout<<CurrentTime;
		gotoxy(37,8+i*2);
		if(!Out.Query)
		{
			cout<<"    ";
			gotoxy(62,8+i*2);
			cout<<"              ";
		}
		else
		{
			cout<<Out.Query;
			gotoxy(62,8+i*2);
			cout<<EndTime;
		};
	};
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//**********************************************************
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
struct OutPutSmoStruct
{
	int ChangedSmo;
	int Loses;
	int Status;
	TimeClass Delta;
	double P5;
	double MStat;

};
class SmoClass
{
	public:
		float Puasson[10000];
		double Lamda;
		ChanalClass kanal[5];
		int QueryNum;
		void ProcessChanals();
		int LoadQuery();
		int GetStatus();
		void OutPutSmo();
		void OutPutConst();
		TimeClass TimeNextQuery;
		TimeClass CurrentTime;
		TimeClass GetNextTime();
		OutPutSmoStruct SmoPr;
	public:
		SmoClass();
		void Run();
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
long double factorial(int f)
{
	long double sum=1;
	for(int i=1;i<=f;i++)
		sum*=i;
	return sum;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
long float MyPow(float a,int b)
{
	long float s=a;
	for(int i=1;i<b;i++)
		s*=a;
	return s;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
SmoClass::SmoClass()
{
	Lamda=15;
   SmoPr.P5=0;
	SmoPr.Loses=0;
	randomize();
	textcolor(10);
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	cout<<"  \t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
	cout<<"\n\t\t\t³          WAIT!           ³";
	cout<<"\n\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	QueryNum=0;
	for(int i=1;i<10000;i++)
		Puasson[i]=-1./15.*log(float(i)/10000);
	CurrentTime.SetCurrentTime();
	TimeNextQuery.SetCurrentTime();
	OutPutConst();
	for(i=0;i<5;i++)
	{
		kanal[i].Init();
		kanal[i].OutPutKanal(i);
	}
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TimeClass SmoClass::GetNextTime()
{
	int 	t	= random(10000);
	double y	= Puasson[t];
	TimeClass q;
	q.SetTime(y);
	SmoPr.Delta=q;
	q+=TimeNextQuery;
	return q;
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SmoClass::Run()
{
	do
		ProcessChanals();
	while (!kbhit());
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SmoClass::ProcessChanals()
{
		static double st=0;
		static  double num=0;
		st+=GetStatus()/10000.;
		num+=1/10000.;
      SmoPr.MStat=st/num;
		for(int i=0;i<5;i++)
		{
			kanal[i].Process();
			kanal[i].OutPutKanal(i);
		};
		SmoPr.Status=GetStatus();
		OutPutSmo();
		CurrentTime.SetCurrentTime();
		if(CurrentTime.IsMore(TimeNextQuery))
		{
			i = LoadQuery();
			kanal[i].OutPutKanal(i);

		};
		SmoPr.Status=GetStatus();
		OutPutSmo();
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int SmoClass::LoadQuery()
{
	static double s=0;
	static  double n=0;
	s+=(GetStatus()==5)?0.0001:0;
	n+=1/10000.;
	SmoPr.P5=s/n;
	TimeNextQuery=GetNextTime();
	QueryNum++;
	CurrentTime.SetCurrentTime();
	int i,b;
	for(i=0;i<5;i++)
	{
		b=kanal[i].SetStatus(QueryNum);
		if(b)	break;
	}
	if(!b)
		SmoPr.Loses++;
	SmoPr.ChangedSmo=1;
	return (b)?i:0;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int SmoClass::GetStatus()
{
	char j=0;
	for(int i=0;i<5;i++)
		j+=kanal[i].GetStatus();
	if(SmoPr.Status!=j)
		SmoPr.ChangedSmo=2;
	return j;
};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SmoClass::OutPutConst()
{
	clrscr();
	gotoxy(0,0);
	cout<<"\n\n\n\n";
	cout<<    "   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
	cout<<  "\n   ³ Time                ³  All           ³    Time In     ³    Time Out    ³";
	cout<<  "\n   ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
	cout<<  "\n   ³ canal       1       ³ Query          ³                ³                ³";
	cout<<  "\n   ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
	cout<<  "\n   ³ canal       2       ³ Query          ³                ³                ³";
	cout<<  "\n   ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
	cout<<  "\n   ³ canal       3       ³ Query          ³                ³                ³";
	cout<<  "\n   ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
	cout<<  "\n   ³ canal       4       ³ Query          ³                ³                ³";
	cout<<  "\n   ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
	cout<<  "\n   ³ canal       5       ³ Query          ³                ³                ³";
	cout<<  "\n   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	cout<<"\n\n   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
	cout<<  "\n   ³ Next                ³ Loses          ³ Status         ³                ³";
	cout<<  "\n   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	cout<<endl;
	gotoxy(1,2);
	cout<<"M(Status)     P(5)";

};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void SmoClass::OutPutSmo()
{
	gotoxy(11,6);
	cout<<CurrentTime;
	if(SmoPr.ChangedSmo>1)
	{
		if(SmoPr.ChangedSmo==2)
		{
			gotoxy(58,20);
			cout<<SmoPr.Status;
		};
	};
	gotoxy(11,20);
	cout<<TimeNextQuery;
	gotoxy(37,6);
	cout<<QueryNum;
	gotoxy(62,20);
	cout<<SmoPr.Delta;
	gotoxy(37,20);

	cout<<SmoPr.Loses;
	SmoPr.ChangedSmo = 0;
	gotoxy(1,1);
	cout<<SmoPr.MStat;
	gotoxy(15,1);
	cout<<SmoPr.P5;

};
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//**********************************************************
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void main(void)
{
	textcolor(10);
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	cout<<"  \t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
	cout<<"\n\t\t\t³     ªãàá®¢ ï à ¡®â       ³";
	cout<<"\n\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	getch();

	SmoClass smo;
	smo.Run();
}
