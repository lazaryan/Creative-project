uses crt,dos;
type
request = record
       time: Longint;
       Num: Integer;
end;
Channel = record
       timeBegin : LongInt;
       TimeToProcess:Real;
       Busy : Boolean;
       NumZapr: Integer;
end;

const lymda = 7;
      mu = 2;
      m=7;
      n = 7;
      eps = 0.03;
      al = 0.97;
      e = 2.718;
      ProcTime:array[1..n]of Real = (1/mu*700,1/mu*700,1/mu*700,1/mu*700,1/mu*700,1/mu*700,1/mu*700);
{      ProcTime:array[1..n]of Real = (1/mu,1/mu,1/mu,1/mu,1/mu,1/mu,
                                      1/mu,1/mu,1/mu,1/mu);}

      Scale = 10;

var i,m2,x_c:byte;p,k:array[0..n]of real;c:char;
    psi,p1,x,tob,potk,q,a,z,r,tog,tsis:real;
    ZaprArr:array[1..m] of request;
    ZaprInArray:Byte;
    ChanArray:array[1..n]of channel;
    LastRequestTime:LongInt;
    LastPuasVar:Byte;
    CurReqNum:Integer;
    RqTmp:request;
    dt:DateTime;
    res:Boolean;
    cycle:Integer;


{--------------------------------------}
Function stepen (a:real;b:byte):real;
var i:byte;s:real;
begin
i:=1;s:=a;
while i<=b-1 do
 begin
  s:=s*a;inc(i);
 end;
 stepen:=s;
end;

{---------------------------------------}
Function faktor(c:byte):integer;
var i:byte;f:integer;
begin
i:=1;f:=1;
while i<=c do begin f:=f*i;inc(i); end;
faktor:=f;
end;

Function GetLTime:LongInt;
var Hour, Minute, Second, Sec100: Word;
begin
    GetTime(Hour, Minute, Second, Sec100);
    GetLTime:=Hour*100*60*60+Minute*100*60+Second*100+Sec100;
end;


{---------------Генератор случайных чисел--------------------}
Function Puasson(y:byte):byte;
var i,n1,d:byte;s,n2,minus:real;
begin
n1:=random(10);
minus:=stepen(e,y);
minus:=1/minus;
n2:=n1*minus;
i:=1;s:=1;x:=0;
{while s<=n2 do begin  s:=s+stepen(y,i)/faktor(i);
                      inc(i);
                end;
d:=i;}
{writeln(n1);}
Puasson:=n1;
end;

Function GetRequest(var rq:Request):Boolean;
var f:Boolean;
    lT:LongInt;
begin
     f:=False;
     lT:=GetLTime;
     if (lT - LastRequestTime)>=LastPuasVar*Scale then
     begin
          LastPuasVar:=Puasson(LastPuasVar);
          rq.Num := CurReqNum;
          rq.time := lT;
          LastRequestTime:=lT;
          if ((CurReqNum>100) or (CurReqNum<0)) then CurReqNum:=1
          else CurReqNum:=CurReqNum+1;
          f:=True;
     end;
     GetRequest:=f;
end;



Procedure PrintInfo;
var i:Byte;
begin
     clrscr;
     WriteLn('╔═════════╤═══╦═══════╤═══════════╤═══════════╤═══════════╗');
     WriteLn('║         │ № ║ Занят │  Вр.Пост. │  Вр.Обр.  │ № запроса ║');
     WriteLn('╠═════════╪═══╬═══════╪═══════════╪═══════════╪═══════════╣');
       for i:=1 to n do
        begin
        if i<>1 then
          Write('║         │',i:3,'║')
        else
          Write('║ Каналы  │',i:3,'║');
        if ChanArray[i].Busy then
        WriteLn(' Да    │',ChanArray[i].timeBegin:11,'│',ChanArray[i].TimeToProcess:11:2,'│',ChanArray[i].NumZapr:11,'║')
        else
          WriteLn(' Нет   │           │           │           ║');
        end;
      WriteLn('╠═════════╪═══╬═══════╪═══════════╪═══════════╪═══════════╣');
       for i:=1 to zAPRiNaRRAY do
        begin
        if i<>1 then
          Write('║         │',i:3,'║')
        else
          Write('║ Очередь │',i:3,'║');
        if i<=ZaprInArray then
          WriteLn(' Да    │',ZaprArr[i].time:11,'│           │',ZaprArr[i].Num:11,'║')
          else
          WriteLn(' Нет   │           │           │           ║');
        end;
        WriteLn('╚═════════╧═══╩═══════╧═══════════╧═══════════╧═══════════╝');
end;


Procedure CheckChannels;
var i:Byte;lTime:LongInt;
begin
     lTime:=GetLTime;
     For i:=1 to n do
     begin
          if ChanArray[i].Busy then
             if lTime-ChanArray[i].timeBegin>=ChanArray[i].TimeToProcess then
                ChanArray[i].Busy:=False;
     end;
end;


Function ProcessRequest(rq:request):Boolean;
var i:Byte; f:Boolean; t:LongInt;
Label Break;
begin
f:=False;
     for i:=1 to n do
     begin
          if not ChanArray[i].Busy then
          begin
               ChanArray[i].timeBegin:=GetLTime;
               ChanArray[i].TimeToProcess:=ProcTime[i];
               ChanArray[i].Busy:=True;
               ChanArray[i].NumZapr:=rq.Num;
               f:=True;
               goto Break;
          end;
     end;
Break:
     ProcessRequest:=f;
end;

Function InsertIntoOchered(rq:request):Boolean;
var f:Boolean;
begin
     f:=False;
     if ZaprInArray<m then
     begin
          ZaprArr[ZaprInArray+1]:=rq;
          ZaprInArray:=ZaprInArray+1;
          f:=True;
     end;
     InsertIntoOchered:=f;
end;

Function GetFromOchered(rq:request):Boolean;
var i:Byte;f:Boolean;
begin
     f:=False;
     if ZaprInArray>0 then
     begin
          rq:=ZaprArr[1];
          For i:=1 to ZaprInArray-1 do
          begin
               ZaprArr[i].time:=ZaprArr[i+1].time;
               ZaprArr[i].Num:=zaprArr[i+1].Num;
          end;
          ZaprInArray:=ZaprInArray-1;
          f:=true;
     end;
     GetFromOchered:=f;
end;

BEGIN
randomize;
clrscr;
{textcolor(lightblue);
writeln('Многоканальная СМО с ограниченной длиной очереди');writeln;writeln;}
textcolor(white);
writeln('Входной поток требований: Пуассона');
writeln('Его характеристика: интенсивность входного потока заявок ',lymda);
writeln('Параметры: среднее число заявок, обслуженных в единицу времени - ',mu);
writeln('           число каналов обслуживания - ',n);
writeln('Характеристика очереди: ');
writeln('           допустимое число заявок в очереди на обслуживание системы ',m);
writeln('Точность = ',eps:3:2);
writeln('Достоверность = ',al:3:2);
readln;
     {****************88}
clrscr;
tob:=1/mu;
writeln('Среднее время обслуживания одного требования:',tob:4:3,' minut');
psi:=lymda/mu;
writeln('psi = ',psi:4:5);p[0]:=1;
x:=psi/n;
if (psi/n)< 1 then
for i:=1 to n-1 do p[0]:=p[0]+stepen(psi,i)/faktor(i);
p1:=stepen(psi,n)/faktor(n)*((x)-stepen((x),(m+1)))/(1-x);
p[0]:=p[0]+p1;
p[0]:=1/p[0];
writeln('Вероятность простоя канала обслуживания po = ',p[0]:4:5);
writeln;writeln;textcolor(cyan);
writeln('Характеристики эффективности обслуживания:');writeln;textcolor(lightgray);
potk:=(stepen(psi,(n+m))/(stepen(n,m)*faktor(n)))*p[0];
writeln('Вероятность отказа                         potk = ',potk:4:5);
q:=1-potk;
writeln('Относительная пропускная способность СМО:  q = ',q:4:6);
a:=lymda*q;
writeln('Абсолютная пропускная способность СМО:     a = ',a:4:6);
z:=a/mu;
writeln('Среднее число занятых каналов:             z =',z:4:6);
r:=stepen(psi,(n+1))*p[0]*(1-(m+1)*stepen(x,m)+m*stepen(x,(m+1)))/(stepen((1-x),2)*n*faktor(n));
writeln('Среднее число машин в очереди:             r =',r:4:6);
tog:=r/lymda;
writeln('Среднее время ожидания:                    tog = ',tog:4:5);
tsis:=tog+q*tob;
writeln('Среднее время пребывания заявки в системе  tsis = ',tsis:4:2);
readln;
       {******************}
clrscr;
LastRequestTime:=0;
LastPuasVar:=1;
ZaprInArray:=0;
For i:=1 to n do
    ChanArray[i].Busy:=False;
cycle:=0;

repeat
      CheckChannels;
      if GetRequest(rqTmp) then
           if not ProcessRequest(rqTmp) then
            res:=  InsertIntoOchered(rqTmp);
          for i:=1 to n do
          begin
               if not ChanArray[i].Busy then
               begin
                    if GetFromOchered(RqTmp) then
                    begin
                     ChanArray[i].timeBegin:=GetLTime;
                     ChanArray[i].TimeToProcess:=ProcTime[i];
                     ChanArray[i].Busy:=True;
                     ChanArray[i].NumZapr:=RqTmp.Num;
                    end;
               end;
          end;
      cycle:=cycle+1;
      if cycle>200 then
      begin
       PrintInfo;
       cycle:=0;
      end;
until keypressed;
readln;
END.
