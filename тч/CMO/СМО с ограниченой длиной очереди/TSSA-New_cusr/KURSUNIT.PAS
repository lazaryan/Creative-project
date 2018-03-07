unit KursUnit;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls,Math, ComCtrls, Buttons, ExtCtrls, Menus, Grids;

type
//  Eps = ('0.80','0.85','0.90','0.96',0.97,0.98,0.99,0.995,0.999,0.9995,0.9999);
  Vec = array[0..100] of real;
  TMainForm = class(TForm)
    MainMenu: TMainMenu;
    TurningInitial: TMenuItem;
    PropertiesInitial: TMenuItem;
    ProcessInitial: TMenuItem;
    StepInitial: TMenuItem;
    RunInitial: TMenuItem;
    FileInitial: TMenuItem;
    ExitInitial: TMenuItem;
    Panel1: TPanel;
    StepSB: TSpeedButton;
    RunSB: TSpeedButton;
    ExitSB: TSpeedButton;
    StatusBar1: TStatusBar;
    ResetSpeedButton: TSpeedButton;
    N1: TMenuItem;
    N2: TMenuItem;
    PageControl: TPageControl;
    Teor: TTabSheet;
    Modal: TTabSheet;
    Panel2: TPanel;
    Bevel3: TBevel;
    Bevel2: TBevel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Lll: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    StaticText1: TStaticText;
    TeorSGrid: TStringGrid;
    NochEd: TEdit;
    PotkEd: TEdit;
    ZEd: TEdit;
    qEd: TEdit;
    AEd: TEdit;
    TochEd: TEdit;
    TsysEd: TEdit;
    Panell3: TPanel;
    Bevel4: TBevel;
    Bevel1: TBevel;
    Label1: TLabel;
    Label6: TLabel;
    Label11: TLabel;
    Label10: TLabel;
    OtkazLabel: TLabel;
    OcheredPBar: TProgressBar;
    KanalPBar: TProgressBar;
    TimeSGrid: TStringGrid;
    TauEd: TEdit;
    KanalSGrid: TStringGrid;
    OtkEdit: TEdit;
    Bevel7: TBevel;
    Label12: TLabel;
    Label13: TLabel;
    Label14: TLabel;
    Label15: TLabel;
    Label16: TLabel;
    Label17: TLabel;
    Label18: TLabel;
    Label19: TLabel;
    StaticText2: TStaticText;
    PraktSGrid: TStringGrid;
    PrNochEd: TEdit;
    PrPOtkEd: TEdit;
    PrZEd: TEdit;
    PrqEd: TEdit;
    PrAEd: TEdit;
    PrTochEd: TEdit;
    PrTsysEd: TEdit;
    CurTimeEd: TEdit;
    Label20: TLabel;
    N3: TMenuItem;
    ResetInitial: TMenuItem;
    NrEd: TEdit;
    Label21: TLabel;
    NZayavEd: TEdit;
    Label22: TLabel;
    Label23: TLabel;
    Label24: TLabel;
    Label25: TLabel;
    TRealizEd: TEdit;
    procedure Button2Click(Sender: TObject);
    procedure StepInitialClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure PropertiesInitialClick(Sender: TObject);
    procedure ExitInitialClick(Sender: TObject);
    procedure ExitSBClick(Sender: TObject);
    procedure StepSBClick(Sender: TObject);
    procedure ResetSpeedButtonClick(Sender: TObject);
    procedure StepSBMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure N2Click(Sender: TObject);
    procedure RunSBClick(Sender: TObject);
    procedure ResetInitialClick(Sender: TObject);
    procedure RunInitialClick(Sender: TObject);
  private
  procedure Ver_P0;
  procedure VecToGrid(Input:Vec;Grid:TStringGrid;MaxY:integer);

    { Private declarations }
  public

 L:real;                     //Интенсивность поступления заявок
 M:real;                     //Интенсивность обслуживания
 nKanal:integer;             //Колличество каналов
 DlinOch:integer;            //Длинна очереди

 NZayav:integer;             //Колличество заявок
 Psi:real;

 NoCh:real;                  //Среднее число заявок в очереди
 P_Otkaz:real;               //Вероятность отказа
 Sred_Ch_Zanyt_Kanal:real;   //Среднее число занятых каналов
 Q:real;                     //Относительная пропускная способность
 Ap_Prop_Sposob:real;        //Абсолютная пропускная способность
 T_OZh:real;                 //Среднее время ожидания
 T_System:real;              //Среднее время пребявания в системе

 N_Sv:integer;               //Номер свободного места в очереди
 N_Sv_Chanel:integer;        //Номер свободного канала
 Num_Zan_Chanel:Integer;     //Колличество занятых каналов
    P:Vec;                   //Массив теоритических вероятностей
    P_Pract:vec;             //Массив практических вероятностей
 Chanel:Vec;                 //Массив каналов
 Ochered:Vec;                //Массив очереди
 Time:Vec;                   //Масив времени обработки событий
  OtkFlag:boolean ;          //Флаг отказа
 MaxTime:real;               //Предел времени обслуживанея
 Epsilon:real;               //Точность
 TempTime:real;              //Текущее время
 Nr:real;                    //Число реализаций
 UrDov:real;                 // Уровень доверия в пределах 0.80..0.9999
 Ni,N0,Mu,Lam,mm,Number:integer;
function Step(arg:real;st:integer):real;  //Возведение в степень
function Factorial(Arg:integer):integer;  //Расчет факториала
function Search(Index:real):integer;      //Поиск в таблице доверия
function MyRandom:real;                   //Генератор случайных чисел

procedure Ver;                            //Подсчет теоритических вероятностей
procedure SrChislZayav(P_0:real);         //Подсчет среднего числа заявок
procedure SysModal;                       //Моделирование СМО
procedure Rotate;                         //Сдвиг очеркди
procedure TeorRasch;                      //Рачет теоритеческих параметров системы
procedure Rasch(P_Array:Vec);
procedure PraktRasch;                     //Рачет практических параметров системы

procedure Reset;                          //Сброс расчетов
procedure NumRealiz(Index:real);          //Подсчет числа реализаций
procedure Zan_Kanal(tau:real);            //Подсчет занятых каналов


    { Public declarations }
  end;

var
  MainForm: TMainForm;
const
 //Значения функщии обратной функции Лапласа
 QQ:array[1..2,1..12] of real = ((0.80,0.85,0.90,0.95,0.96,0.97,0.98,
              0.99,0.995,0.999,0.9995,0.9999),(1.64,
              2.08,2.71,3.84,4.21,4.49,5.43,6.61,7.9,10.9,12.25,15.2));
implementation

uses PropertDlg, About;

{$R *.DFM}
//----------------------------------------------------------------------------//
function TMainForm.Factorial;
 var
  i:integer;
  Temp:integer;
begin
  Temp:=1;
  for i:=1 to Arg do
     Temp:=Temp*i;
 Factorial:=Temp;
end;
//----------------------------------------------------------------------------//
function TMainForm.Step;
 var
   i:integer;
   Temp:real;
begin
Temp:= 1;
  for i:=1 to st do
    Temp:=Temp*arg;
//  Step:=exp(st*Ln(arg));
 Step:=Temp;
end;
//----------------------------------------------------------------------------//
function TMainForm.Search;
 var
  i:integer;
begin
  Search:=-1;
   for i:=1 to 12 do
    begin
     if QQ[1,i]=Index then
        Search := i;
     end;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.VecToGrid;
 var
 i:integer;
begin
 for i:=0 to MaxY do
   begin
     Grid.Cells[1,i+1]:=FloatToStrF(Input[i],ffFixed,10,6);
     Grid.Cells[0,i+1]:= IntToStr(i);
   end;
   Grid.Repaint;
 Grid.RowCount :=MaxY+1;

end;
//----------------------------------------------------------------------------//
procedure TMainForm.SrChislZayav;
 var
  i:integer;
begin
NoCh:=0;
  for i:=1 to DlinOch do
   begin
     NoCh := NoCh+i*Step((psi/nKanal),i-1);
   end;
  NoCh:=NoCh*(Step(psi,nKanal+1)*P_0)/(nKanal*Factorial(NKanal));
  //NoCh среднее число заявок в очереди
end;
//----------------------------------------------------------------------------//
procedure TMainForm.Ver_P0;
 var
  i,k:integer;
begin
   k:=1;
   p[0]:=0;
   for i:=0 to nKanal+DlinOch do
     begin
       if i<= nKanal then
         P[0]:=P[0]+(Step(psi,i)/Factorial(i))
       else
        begin
         P[0]:=P[0]+Step(psi,i)/(Factorial(nKanal)*Step(nKanal,k));
         k:=k+1;
        end;
     end;
  P[0]:=1/P[0];
end;
//----------------------------------------------------------------------------//
procedure TMainForm.Ver;
 var
  i,k:integer;
BEGIN
   Ver_P0;
   k:=1;
   for i:=1 to nKanal+DlinOch do
     begin
       if i<= nKanal then
         P[i]:=(Step(psi,i)/Factorial(i))*P[0]
       else
        begin
         P[i]:=(Step(psi,i)/(Factorial(nKanal)*Step(nKanal,k)))*P[0];
         k:=k+1;
        end;
     end;
END;
//----------------------------------------------------------------------------//
procedure TMainForm.Rotate; //Сдвиг очереди
  var
   i:integer;
begin
  for i:=0 to N_Sv-1 do
   Ochered [i]:=Ochered [i+1];
  Ochered [N_Sv]:=0;
  N_Sv:=N_Sv-1;

end;
//----------------------------------------------------------------------------//
function TMainForm.MyRandom;
  var
   TempReal:real;
begin
{  Ni:= Round(Mu*Step(Lam,Number-1)/Lam-1);
  Ni:= Ni mod mm;
  Ni:=Round(Step(Lam,Number))*N0+Ni;
  N0:=Ni;
  Number:=Number+1;
  TempReal:=Ni-(Ni div 1000)*1000;
  MyRandom:=Abs(TempReal/1000);
 // MyRandom:= Abs((Ni*pi-Int(Ni*pi))*2*L);}
 MyRandom:=random(Round(2*L));
end;
//----------------------------------------------------------------------------//
procedure TMainForm.SysModal;
 var
  i:integer;
 // NTemp:integer;
  tau:real;
  LTemp:real;
  flag :boolean;
  Dtau:real;
  TempTau:real;
 begin
 flag:=true;
// NTemp:=0;
 Dtau:=0.002*1/M;
 tau:=0.01;//*1/L;
LTemp := MyRandom;
  if LTemp<> 0 then
   tau := 1/LTemp;

  Dtau:=0.1*1/M;
  if 0.1*tau < Dtau then
      Dtau:=0.05*tau;
 TempTau:=0;
  if Time[0]=0 then Time[0]:= tau;

 TempTime:=TempTime+tau;
//!!!!!!
 TauEd.Text:= FloatToStrF(tau,ffFixed,10,6);//tau
 TauEd.Repaint;
 CurTimeEd.Text:=FloatToStrF(TempTime,ffFixed,10,6);//TempTime
 CurTimeEd.Repaint;
 while TempTau <= tau do
  begin
   for i:=0 to N_Sv_Chanel-1 do         //Проверка занятых каналов
    begin
     Chanel[i]:=Chanel[i] - Dtau;
     if(Chanel[i] <=0) then        //Канал Свободен?
      begin
        if  (N_Sv > 0 ) then       //Есть очередь?
          begin
           Chanel[i]:= 1/M; //+Chanel[i];
            Rotate;               //сдвиг очереди
            if (N_Sv < DlinOch) and flag then  //есть место в очереди?
              begin
               Ochered [N_Sv]:=L;
               N_Sv:=N_Sv+1;
               flag:=false;
              end;
          end
         else
         if flag then
          begin
            Chanel[i]:= 1/M;
            flag:=false;
          end;
       end;
     end;
    if (N_Sv_Chanel < nKanal) and flag then
      begin
         Chanel[N_Sv_Chanel]:= 1/M;
         N_Sv_Chanel:=N_Sv_Chanel+1;
         flag:=false;
      end;
   if (N_Sv < DlinOch) and flag then  //есть место в очереди?
     begin
       Ochered [N_Sv]:=L;
       N_Sv:=N_Sv+1;
       flag:=false;
     end;
    OtkFlag:= flag;
    Num_Zan_Chanel:=0;
//   N_Zan_Och:=0;

    TempTau:=TempTau+Dtau;
    Zan_Kanal(Dtau);

     KanalPBar.Position:=0;
     KanalPBar.Step:=  Num_Zan_Chanel;
     KanalPBar.Stepit;

     OcheredPBar.Position:=0;
     OcheredPBar.Step:= N_Sv;
     OcheredPBar.Stepit;

     VecToGrid(Chanel,KanalSGrid,nKanal);
     VecToGrid(Time,TimeSGrid,nKanal+DlinOch+1);

 end;
    if OtkFlag then
     begin
      OtkazLabel.Visible:=true;
      OtkEdit.Text:=IntToStr(StrToInt(OtkEdit.Text)+1);
      OtkEdit.Repaint;
     end;
     NZayavEd.Text:=IntToStr(StrToInt(NZayavEd.Text)+1);
     NZayavEd.Repaint;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.Zan_Kanal;
 var
 i:integer;
begin
 Num_Zan_Chanel:=0;
   for i:=0 to nKanal do     //N_SV_Chanel-1
    if Chanel[i] >0 then
      Num_Zan_Chanel:=Num_Zan_Chanel+1;

   if  (N_Sv = 0) //and (Num_Zan_Chanel > 0)
    then
     Time[Num_Zan_Chanel]:=Time[Num_Zan_Chanel]+tau
    else
     Time[Num_Zan_Chanel+N_Sv]:=Time[Num_Zan_Chanel+N_Sv]+tau;

end;
//----------------------------------------------------------------------------//
procedure TMainForm.Rasch;
begin


   Q:=1-P_Otkaz;
   Ap_Prop_Sposob:=L*Q;


//   if Noch =10 then L:=2;
   T_OZh := Noch/L;
   T_System:= T_OZh+Q*1/M;


end;
//----------------------------------------------------------------------------//
procedure TMainForm.TeorRasch;
begin
   N_Sv:=0;
   Psi:=L/M;
   Ver;
   SrChislZayav(P[0]);
   P_Otkaz:= P[nKanal+DlinOch];
   Sred_Ch_Zanyt_Kanal:= psi*(1-(Step(Psi,nKanal+DlinOch)/(
       Step(nKanal,DlinOch)*Factorial(nKanal)))*P[0]);


   Rasch(P);

   VecToGrid(P,TeorSGrid,nKanal+DlinOch+1);
   NochEd.Text:= FloatToStrF(NoCh,ffFixed,10,6);
   PotkEd.Text:= FloatToStrF(P_Otkaz,ffFixed,10,6);
   ZEd.Text:= FloatToStrF(Sred_Ch_Zanyt_Kanal,ffFixed,10,6);
   qEd.Text:= FloatToStrF(Q,ffFixed,10,6);
   AEd.Text:= FloatToStrF(Ap_Prop_Sposob,ffFixed,10,6);
   TochEd.Text:= FloatToStrF(T_OZh,ffFixed,10,6);
   TsysEd.Text:= FloatToStrF(T_System,ffFixed,10,6);

end;
//----------------------------------------------------------------------------//
procedure TMainForm.Button2Click(Sender: TObject);
 var i:integer;
begin
 N_Sv_Chanel:=0;
 for i:=1 to 10 do
 begin
  SysModal;
   KanalPBar.Position:=0;
   KanalPBar.Step:= N_Sv_Chanel-1;
   KanalPBar.Stepit;
 end;
   N_Sv_Chanel:=0;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.NumRealiz;
 var
  TReal:real;
begin
  Nr:= P_Otkaz*(1-P_Otkaz)*QQ[2,Search(Index)]/(Epsilon*Epsilon);
   TReal:= Nr*StrToFloat(PrTsysEd.Text);
   TRealizEd.Text:=FloatToStrF(TReal,ffFixed,10,6);
  NrEd.Text:=FloatToStrF(Nr,ffFixed,10,6);

end;
//----------------------------------------------------------------------------//
procedure TMainForm.StepInitialClick(Sender: TObject);
begin
 StepSBClick(Sender);
end;
//----------------------------------------------------------------------------//
procedure TMainForm.FormCreate(Sender: TObject);
begin

  TeorSGrid.Cells[0,0]:= 'N';
  TeorSGrid.Cells[1,0]:='P';

  PraktSGrid.Cells[0,0]:= 'N';
  PraKtSGrid.Cells[1,0]:='P';

  KanalSGrid.Cells[0,0]:= 'N';
  KanalSGrid.Cells[1,0]:='T';

  TimeSGrid.Cells[0,0]:= 'N';
  TimeSGrid.Cells[1,0]:='T';

                   //Параметры системы

   L:= 12;
   M:=4;
   nKanal:=4;
   DlinOch:=0;
   NZayav:=DlinOch+nKanal;

   TempTime:=0;
   MaxTime:= 100;  //Предел времени обслуживания
   Epsilon:=0.02; //Точность
   UrDov:=0.97;
   TeorRasch;
   //N0,Mu,Lam,mm
   N0:=5;
   Mu:=7;
   Lam:=24;
   mm:=3;
   Number:=0;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.PropertiesInitialClick(Sender: TObject);
begin
   if PropertiasDlg.ShowModal = mrOk then
     begin
       L:=StrToFloat(PropertiasDlg.LambEd.Text);
       M:=StrToFloat(PropertiasDlg.MuEd.Text);
       nKanal:= StrToInt(PropertiasDlg.nEd.Text);
       DlinOch:=StrToInt(PropertiasDlg.mEd.Text);
       MaxTime:=StrToFloat(PropertiasDlg.TMaxEd.Text);
       Epsilon:=StrToFloat(PropertiasDlg.EpsEd.Text);
       UrDov:=StrToFloat(PropertiasDlg.DoverEd.Text);
       Reset;
       TeorRasch;

     end;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.ExitInitialClick(Sender: TObject);
begin
  Close;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.ExitSBClick(Sender: TObject);
begin
  Close;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.StepSBClick(Sender: TObject);
begin
 if TempTime <=MaxTime then
   begin
     SysModal;
 end
   else
    begin
     StepSb.Enabled:=false;
     RunSb.Enabled:=false;
     StepInitial.Enabled:=false;
     RunInitial.Enabled:=false;
     PraktRasch;
     NumRealiz(UrDov);
   end;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.ResetSpeedButtonClick(Sender: TObject);
begin
 Reset;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.Reset;
  var
   i:integer;
begin
 StepSb.Enabled:=true;
 RunSb.Enabled:=true;
 StepInitial.Enabled:=true;
 RunInitial.Enabled:=true;
   N_Sv_Chanel:=0;
   N_Sv:=0;
   TempTime:=0;
    for i:=0 to 100 do
     begin
      Chanel[i]:=0;
      Ochered[i]:=0;
      Time[i]:=0;
      P_Pract[i]:=0;
     end;
  NrEd.Text:='0';
  TRealizEd.Text:='0';
  NZayavEd.Text:='0';
  CurTimeEd.Text:='0';
  TauEd.Text:='0';
  OtkEdit.Text:='0';
  OtkazLabel.Visible:= false;
  KanalPBar.Position:=0;
  KanalPBar.Step:= 0;
  KanalPBar.Stepit;

  OcheredPBar.Position:=0;
  OcheredPBar.Step:= 0;
  OcheredPBar.Stepit;
     VecToGrid(Chanel,KanalSGrid,nKanal);
     VecToGrid(Time,TimeSGrid,nKanal+DlinOch+1);
end;
//----------------------------------------------------------------------------//
procedure TMainForm.StepSBMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);

begin
 if OtkFlag then
      OtkazLabel.Visible:= false;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.N2Click(Sender: TObject);
begin
  AboutBox.Show;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.PraktRasch;
 var
  i:integer;
  TTime:real;
begin
 TTime:=0;
   for i:=0 to nKanal+DlinOch do
     TTime:=TTime+Time[i];
   for i:=0 to nKanal+DlinOch do
     P_Pract[i]:=Time[i]/TTime;

  NOch:=0;
    for i:=nKanal+1 to DlinOch + nKanal+1 do
      NOch:=NOch + P_Pract[i]*(i-nKanal);
   P_Otkaz:= StrToInt(OtkEdit.Text)/StrToInt(NZayavEd.Text);
   Sred_Ch_Zanyt_Kanal:= psi*(1-P_Otkaz);
   Rasch(P_Pract);


   VecToGrid(P_Pract,PraktSGrid,nKanal+DlinOch+1);
   PrNochEd.Text:= FloatToStrF(NoCh,ffFixed,10,6);
   PrPotkEd.Text:= FloatToStrF(P_Otkaz,ffFixed,10,6);
   PrZEd.Text:= FloatToStrF(Sred_Ch_Zanyt_Kanal,ffFixed,10,6);
   PrqEd.Text:= FloatToStrF(Q,ffFixed,10,6);
   PrAEd.Text:= FloatToStrF(Ap_Prop_Sposob,ffFixed,10,6);
   PrTochEd.Text:= FloatToStrF(T_OZh,ffFixed,10,6);
   PrTsysEd.Text:= FloatToStrF(T_System,ffFixed,10,6);

end;
//----------------------------------------------------------------------------//
procedure TMainForm.RunSBClick(Sender: TObject);
begin
 OtkazLabel.Visible:= true;
 OtkazLabel.Repaint;
  while  (TempTime <=MaxTime) do
   begin
     SysModal;
   end;
 StepSb.Enabled:=false;
 RunSb.Enabled:=false;
 StepInitial.Enabled:=false;
 RunInitial.Enabled:=false;

 PraktRasch;
 NumRealiz(UrDov);
end;
//----------------------------------------------------------------------------//
procedure TMainForm.ResetInitialClick(Sender: TObject);
begin
 Reset;
end;
//----------------------------------------------------------------------------//
procedure TMainForm.RunInitialClick(Sender: TObject);
begin
 RunSBClick(Sender);
end;
end.
//----------------------------------------------------------------------------//

