PROGRAM CAN_SMO;


TYPE
 CHANNAL = (FREE, CLAIM1, CLAIM2);
 TIME = word;
 INTENSITY = word;
 STATISTICS = word;

VAR
 CHANNAL1, CHANNAL2 : CHANNAL;{Каналы        }
 _T_, t, tc1, tc2 : TIME;     {Время}
 l1, l2, n1, n2 : INTENSITY;  {Интенсивности }
 served1, not_served1,
 served2, not_served2,
 S : STATISTICS; {Статистика}
 M,N:INTEGER;{число реализаций}
FUNCTION W(t : TIME; l : INTENSITY) : boolean;{Определяет появилась ли заявка}
 Begin                                        {по интенсивности потока l}
  if random < l/60 then W := TRUE else W := FALSE;
 End;

FUNCTION F(t : TIME; n : INTENSITY) : TIME;{Определяет сколько будет обрабатываться заявка}
 Begin                                     {по интенсивности обслуживания заявок n}
  F := t +round(60/(n));
 End;

BEGIN
M:=0;
WRITELN('ВВЕДИТЕ ЧИСЛО РЕАЛИЗАЦИЙ РАБОТЫ СМО');
READLN(N);
REPEAT
M:=M+1;
writeln(M, '-ая реализация');
 randomize;
 CHANNAL1 := FREE; CHANNAL2 := FREE;
 l1 := 3; l2 := 1; n1 := 2; n2 := 1;
 served1 := 0; not_served1 := 0;
 served2 := 0; not_served2 := 0;
  write('Введите время исследования СМО - Т: '); readln(_T_);

 repeat

  if  tc1 = t then
   begin
    if CHANNAL1 = CLAIM1 then inc(served1) else inc(served2);
    CHANNAL1 := FREE;
    writeln('Канал1 выполнил заявку');
   end;
  if tc2 = t then
   begin
    if CHANNAL2 = CLAIM1 then inc(served1) else inc(served2);
    CHANNAL2 := FREE;
    writeln('Канал2 выполнил заявку');
   end;
  if W(t,l1) then
   begin
    writeln('Поступила заявка1');
    if CHANNAL1 = FREE then
     begin CHANNAL1 := CLAIM1; tc1 := F(t,n1); writeln('Канал1 принял заявку1'); end
    else if  CHANNAL2 = FREE then
     begin CHANNAL2 := CLAIM1; tc2 := F(t,n1); writeln('Канал2 принял заявку1'); end
    else if CHANNAL1 = CLAIM2 then
     begin CHANNAL1 := CLAIM1; tc1 := F(t,n1); inc(not_served2); writeln('Канал1 принял заявку1 вместо заявки2'); end
    else if CHANNAL2 = CLAIM2 then
     begin CHANNAL2 := CLAIM1; tc2 := F(t,n1); inc(not_served2); writeln('Канал2 принял заявку1 вместо заявки2'); end
    else begin inc(not_served1); writeln('заявка1 не обслужена'); end;
   end;

  if W(t,l2) then
   begin
    writeln('Поступила заявка2');
    if CHANNAL1 = FREE then
     begin CHANNAL1 := CLAIM2; tc1 := F(t,n2); writeln('Канал1 принял заявку2');end
    else if CHANNAL2 = FREE then
     begin CHANNAL2 := CLAIM2; tc2 := F(t,n2); writeln('Канал2 принял заявку2');end
    else begin inc(not_served2);  writeln('заявка2 не обслужена'); end;
   end;
  inc(t);
 until _T_ = t;
 S := served1 + not_served1 + served2 + not_served2;
 writeln('время работы СМО  ',_T_);
 writeln('обслужено каналом1: ' ,served1);
 writeln('обслужено каналом2: ',served2);
 writeln('Поступило заявок : ',S);
 writeln('Обслужено заявок : ',served1+served2);
 writeln('Не обслужено заявок : ',not_served1+not_served2);
 writeln('Интенсивность поступления заявок в систему : ',(served1+served2)/_T_:2:3);
 writeln('Абсолютная пропускная способность системы : ',(served1+served2)/T:2:3);
 writeln('Вероятность отказа : ',(not_served1+not_served2)/S*100:2:1,'%');
 writeln('Относительная пропускная способность системы: ',(served1+served2)/S:2:3);
 readln;
 UNTIL M>=N;
 writeln('моделирование закончено');
END.

