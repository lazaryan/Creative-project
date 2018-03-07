unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, jpeg, ExtCtrls, Grids, Math;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    Image1: TImage;
    Label1: TLabel;
    Button1: TButton;
    LabeledEdit2: TLabeledEdit;
    LabeledEdit1: TLabeledEdit;
    StringGrid2: TStringGrid;
    procedure Button1Click(Sender: TObject);


  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;


implementation

{$R *.dfm}


procedure TForm1.Button1Click(Sender: TObject);
var
Tpos,Tobr1,Tosv1,T,L1,N,K1,K2,Tobr,Tosv2,Otk:integer;
K3,K4,L2,L3,L4,Tosv3,Tosv4:integer;
j,S,m,u,x,sum:integer;
V:real;
label met;
begin
randomize;
StringGrid1.Cells[0,0]:='Такт';
StringGrid1.Cells[1,0]:='Т пост';
StringGrid1.Cells[2,0]:='L очер1';
StringGrid1.Cells[3,0]:='Канал1';
StringGrid1.Cells[4,0]:='Т обр1';
StringGrid1.Cells[5,0]:='Т осв1';
StringGrid1.Cells[6,0]:='L очер2';
StringGrid1.Cells[7,0]:='Канал2';
StringGrid1.Cells[8,0]:='Т осв2';
StringGrid1.Cells[9,0]:='L очер3';
StringGrid1.Cells[10,0]:='Канал3';
StringGrid1.Cells[11,0]:='Т осв3';
StringGrid1.Cells[12,0]:='L очер4';
StringGrid1.Cells[13,0]:='Канал4';
StringGrid1.Cells[14,0]:='Т осв4';
StringGrid1.Cells[15,0]:='Т обр';
StringGrid1.Cells[16,0]:='N';
StringGrid1.Cells[17,0]:='Отказ';
Tpos:=0;
K1:=0;
K2:=0;
K3:=0;
K4:=0;
T:=0;
L1:=0;
L2:=0;
L3:=0;
L4:=0;
N:=0;
j:=1;
Otk:=0;
Tosv2:=0;
Tobr:=33;
Tosv1:=0;
Tobr1:=0;
Tosv3:=0;
Tosv4:=0;
S:=0;
m:=1;
u:=0;
StringGrid1.RowCount:=1;
  StringGrid2.Cells[0,0]:=IntToStr(0);
while N+Otk<500 do
  begin
  StringGrid1.RowCount:=StringGrid1.RowCount+1;
    if (T=Tosv2)and (K2=1) then
    begin
       K2:=0;
       N:=N+1;
       StringGrid2.Cells[u,1]:=IntToStr(T);
        u:=u+1;
        if L2>0 then
        begin
        K2:=1;
        L2:=L2-1;
        if L2+L3+L4>=25 then
         Tobr:=25
         else Tobr:=33;
         Tosv2:=T+Tobr;
         end;
         end;

         if (T=Tosv3)and (K3=1) then
    begin
       K3:=0;
       N:=N+1;
       StringGrid2.Cells[u,1]:=IntToStr(T);
        u:=u+1;
        if L3>0 then
        begin
        K3:=1;
        L3:=L3-1;
        if L2+L3+L4>=25 then
         Tobr:=25
         else Tobr:=33;
         Tosv3:=T+Tobr;
         end;
         end;

         if (T=Tosv4)and (K4=1) then
    begin
       K4:=0;
       N:=N+1;
       StringGrid2.Cells[u,1]:=IntToStr(T);
        u:=u+1;
        if L4>0 then
        begin
        K4:=1;
        L4:=L4-1;
        if L2+L3+L4>=25 then
         Tobr:=25
         else Tobr:=33;
         Tosv4:=T+Tobr;
         end;
         end;

        if (T=Tosv1)and (K1=1) then
    begin
       K1:=0;
       if  (L2=10) and (L3=10) and (L4=10) then
       begin
       Otk:=Otk+1;
       StringGrid2.Cells[u,1]:=IntToStr(T);
        u:=u+1;
       goto met;
       end;
       if (L2<=L3) and (L2<=L4) then
       begin
       L2:=L2+1;
       if K2=0 then
         begin
         K2:=1;
         L2:=L2-1;
        if L2+L3+L4>=25 then
         Tobr:=25
         else Tobr:=33;
         Tosv2:=T+Tobr
         end;
       goto met
       end;
       if (L3<=L2) and (L3<=L4) then
       begin
       L3:=L3+1;
        if K3=0 then
        begin
        K3:=1;
        L3:=L3-1;
        if L2+L3+L4>=25 then
         Tobr:=25
         else Tobr:=33;
         Tosv3:=T+Tobr;
         end;
       goto met
       end;
       if (L4<=L2) and (L4<=L3) then
        begin
       L4:=L4+1;
        if K4=0 then
        begin
        K4:=1;
        L4:=L4-1;
        if L2+L3+L4>=25 then
         Tobr:=25
         else Tobr:=33;
         Tosv4:=T+Tobr;
         end;
       goto met
       end;
  met: if L1>0 then
        begin
        K1:=1;
        L1:=L1-1;
         Tobr1:=random(7)+7;
         Tosv1:=T+Tobr1;
         end;
         end;

     if T=Tpos then
       begin
       L1:=L1+1;
      if K1=0 then
         begin
         K1:=1;
         L1:=L1-1;
         Tobr1:=random(7)+7;
         Tosv1:=T+Tobr1
         end;
        S:=random(11)+5;
         Tpos:=T+S;
         if m<500 then
         StringGrid2.Cells[m,0]:=IntToStr(Tpos);
         m:=m+1;
         end;

          StringGrid1.Cells[0,j]:=IntToStr(T);
         StringGrid1.Cells[1,j]:=IntToStr(Tpos-S)+'+'+IntToStr(S);
          StringGrid1.Cells[2,j]:=IntToStr(L1);
          StringGrid1.Cells[3,j]:=IntToStr(K1);
          StringGrid1.Cells[4,j]:=IntToStr(Tobr1);
          StringGrid1.Cells[5,j]:=IntToStr(Tosv1);
          StringGrid1.Cells[6,j]:=IntToStr(L2);
          StringGrid1.Cells[7,j]:=IntToStr(K2);
          StringGrid1.Cells[8,j]:=IntToStr(Tosv2);
          StringGrid1.Cells[9,j]:=IntToStr(L3);
          StringGrid1.Cells[10,j]:=IntToStr(K3);
          StringGrid1.Cells[11,j]:=IntToStr(Tosv3);
          StringGrid1.Cells[12,j]:=IntToStr(L4);
          StringGrid1.Cells[13,j]:=IntToStr(K4);
          StringGrid1.Cells[14,j]:=IntToStr(Tosv4);
          StringGrid1.Cells[15,j]:=IntToStr(Tobr);
          StringGrid1.Cells[16,j]:=IntToStr(N);
          StringGrid1.Cells[17,j]:=IntToStr(Otk);

    j:=j+1;
    T:=Tpos;
    if (Tosv1<T) and (K1=1) then
    T:=Tosv1;
    if (Tosv2<T) and (K2=1) then
    T:=Tosv2;
    if (Tosv3<T) and (K3=1) then
    T:=Tosv3;
    if (Tosv4<T) and (K4=1) then
    T:=Tosv4;
    end;
     V:=Otk/500;
     LabeledEdit1.Text:=FloatToStr(V);
     sum:=0;
     for x:=0 to 499 do
     begin
     StringGrid2.Cells[x,2]:=IntToStr(StrToInt(StringGrid2.Cells[x,1])-StrToInt(StringGrid2.Cells[x,0]));
     sum:=sum+StrToInt(StringGrid2.Cells[x,2]);
     end;
     LabeledEdit2.Text:=FloatToStr(sum/500);
    end;
end.
