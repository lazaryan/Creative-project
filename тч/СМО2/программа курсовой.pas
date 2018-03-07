PROGRAM CAN_SMO;


TYPE
 CHANNAL = (FREE, CLAIM1, CLAIM2);
 TIME = word;
 INTENSITY = word;
 STATISTICS = word;

VAR
 CHANNAL1, CHANNAL2 : CHANNAL;{������        }
 _T_, t, tc1, tc2 : TIME;     {�����}
 l1, l2, n1, n2 : INTENSITY;  {������������� }
 served1, not_served1,
 served2, not_served2,
 S : STATISTICS; {����������}
 M,N:INTEGER;{����� ����������}
FUNCTION W(t : TIME; l : INTENSITY) : boolean;{���������� ��������� �� ������}
 Begin                                        {�� ������������� ������ l}
  if random < l/60 then W := TRUE else W := FALSE;
 End;

FUNCTION F(t : TIME; n : INTENSITY) : TIME;{���������� ������� ����� �������������� ������}
 Begin                                     {�� ������������� ������������ ������ n}
  F := t +round(60/(n));
 End;

BEGIN
M:=0;
WRITELN('������� ����� ���������� ������ ���');
READLN(N);
REPEAT
M:=M+1;
writeln(M, '-�� ����������');
 randomize;
 CHANNAL1 := FREE; CHANNAL2 := FREE;
 l1 := 3; l2 := 1; n1 := 2; n2 := 1;
 served1 := 0; not_served1 := 0;
 served2 := 0; not_served2 := 0;
  write('������� ����� ������������ ��� - �: '); readln(_T_);

 repeat

  if  tc1 = t then
   begin
    if CHANNAL1 = CLAIM1 then inc(served1) else inc(served2);
    CHANNAL1 := FREE;
    writeln('�����1 �������� ������');
   end;
  if tc2 = t then
   begin
    if CHANNAL2 = CLAIM1 then inc(served1) else inc(served2);
    CHANNAL2 := FREE;
    writeln('�����2 �������� ������');
   end;
  if W(t,l1) then
   begin
    writeln('��������� ������1');
    if CHANNAL1 = FREE then
     begin CHANNAL1 := CLAIM1; tc1 := F(t,n1); writeln('�����1 ������ ������1'); end
    else if  CHANNAL2 = FREE then
     begin CHANNAL2 := CLAIM1; tc2 := F(t,n1); writeln('�����2 ������ ������1'); end
    else if CHANNAL1 = CLAIM2 then
     begin CHANNAL1 := CLAIM1; tc1 := F(t,n1); inc(not_served2); writeln('�����1 ������ ������1 ������ ������2'); end
    else if CHANNAL2 = CLAIM2 then
     begin CHANNAL2 := CLAIM1; tc2 := F(t,n1); inc(not_served2); writeln('�����2 ������ ������1 ������ ������2'); end
    else begin inc(not_served1); writeln('������1 �� ���������'); end;
   end;

  if W(t,l2) then
   begin
    writeln('��������� ������2');
    if CHANNAL1 = FREE then
     begin CHANNAL1 := CLAIM2; tc1 := F(t,n2); writeln('�����1 ������ ������2');end
    else if CHANNAL2 = FREE then
     begin CHANNAL2 := CLAIM2; tc2 := F(t,n2); writeln('�����2 ������ ������2');end
    else begin inc(not_served2);  writeln('������2 �� ���������'); end;
   end;
  inc(t);
 until _T_ = t;
 S := served1 + not_served1 + served2 + not_served2;
 writeln('����� ������ ���  ',_T_);
 writeln('��������� �������1: ' ,served1);
 writeln('��������� �������2: ',served2);
 writeln('��������� ������ : ',S);
 writeln('��������� ������ : ',served1+served2);
 writeln('�� ��������� ������ : ',not_served1+not_served2);
 writeln('������������� ����������� ������ � ������� : ',(served1+served2)/_T_:2:3);
 writeln('���������� ���������� ����������� ������� : ',(served1+served2)/T:2:3);
 writeln('����������� ������ : ',(not_served1+not_served2)/S*100:2:1,'%');
 writeln('������������� ���������� ����������� �������: ',(served1+served2)/S:2:3);
 readln;
 UNTIL M>=N;
 writeln('������������� ���������');
END.

