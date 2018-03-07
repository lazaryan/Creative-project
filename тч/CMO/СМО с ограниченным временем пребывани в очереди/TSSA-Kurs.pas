program mazdai;
uses crt;
VAR que:array[1..100] of integer;
    chan:array[1..100] of integer;
    tsk:array[1..100] of real;
    tq,ts:real;
    nq,ns:integer;
    m,a,b:integer;
    niu,lambda,qua,i,tnext:real;
    time:integer;
    j:integer;
    flg:boolean;
    tm:integer;

procedure compressque(ind:integer);
var i:integer;

begin
  i:=ind;
  while (i<100) do
  begin
    que[i]:=que[i+1];
    i:=1+i;
  end;
  writeln('query compressed');
end;

function add2chan(ind:integer):boolean;
var flag:boolean;
    i:integer;
begin
  flag:=true;
  i:=1;
  while ((i<=m)and flag) do
  begin
    if chan[i]=0 then
    begin
      tsk[ind]:=0;
      chan[i]:=ind;
      flag:=false;
      writeln('task ',ind,' added to channel ',i);
    end;
    i:=i+1;
  end;
  add2chan:=not(flag);
end;

function canstop(t:real;par:real):boolean;
var x:real;
    y:real;
begin
  x:=1-exp(-par*t);
  y:=random;
  if y<x then canstop:=true
  else canstop:=false;
end;

function add2sys(ind:integer):boolean;
var flag:boolean;
    i:integer;
begin
  flag:=true;
  i:=1;
  while ((i<=m)and flag) do
  begin
    if chan[i]=0 then
    begin
      tsk[ind]:=0;
      chan[i]:=ind;
      flag:=false;
      ns:=ns+1;
      writeln('task ',ind ,' added to channel ',i);
    end;
    i:=i+1;
  end;
  if flag then
  begin
    i:=1;
    while ((i<=100)and flag) do
    begin
      if que[i]=0 then
      begin
        que[i]:=ind;
        flag:=false;
        nq:=nq+1;
        ns:=ns+1;
        writeln('task ',ind,' added to query');
      end;
      i:=i+1;
    end;
  end;
  if flag then
  begin
    writeln('query overflow!!!');
    halt(0);
  end;
end;

procedure processchan;
var i:integer;
begin
  for i:=1 to m do
  begin
    if chan[i]<>0 then
     if canstop(tsk[chan[i]],lambda) then
     begin
       writeln('task ',chan[i],' left the channel ',i);
       tsk[chan[i]]:=-1;
       chan[i]:=0;
     end
     else
     begin
       ts:=ts+qua;
       tsk[chan[i]]:=tsk[chan[i]]+qua;
     end;
  end;
end;

procedure processque;
var i:integer;
begin
  for i:=1 to 100 do
  begin
   if que[i]<>0 then
    if add2chan(que[i]) then compressque(i);
  end;

  for i:=1 to 100 do
  begin
    if que[i]<>0 then
     if canstop(tsk[que[i]],niu) then
     begin
       writeln('task ',que[i],' left the query');
       tsk[que[i]]:=-1;
       que[i]:=0;
       compressque(i);

     end
     else
     begin
       tq:=tq+qua;
       tsk[que[i]]:=tsk[que[i]]+qua;
     end;
  end;
end;

begin
  randomize;
  writeln('enter a and b');
  readln(a,b);
  writeln('enter niu and lambda');
  readln(niu,lambda);
  writeln('enter number of channels');
  readln(m);
  writeln('enter quanting time');
  readln(qua);
  writeln('enter time of examining');
  readln(time);
  for j:=1 to 100 do
   tsk[j]:=-1;

  i:=0;
  while(i<time) do       {main time cycle}
  begin
  writeln(' > time ',i:3:4,' of ',time);
  delay(500);

  {readkey;}

  if i=0 then            {first time}
  begin
    tsk[1]:=0;
    add2sys(1);
    tnext:=random*(b-a)+a;
    writeln('next task should appear at ',tnext:4:4);
  end

  else
  begin
    if i>tnext then {add new task}
    begin
      tnext:=i+random*(b-a)+a;
      writeln('next task should appear at ',tnext:4:4);
      flg:=true;
      j:=1;
      while((j<=100) and flg) do
      begin
        if tsk[j]=-1 then
        begin
          tsk[j]:=0;
          add2sys(j);
          flg:=false;
        end;
        j:=j+1;
      end;
      if flg then
      begin
        writeln('system overflow!!!');
        halt(0);
      end;
    end;

    processchan;
    processque;
  end;
  i:=i+qua;
  end;
  if nq<>0 then
   writeln('average time query ',tq/nq:4:4)
  else
   writeln('no tasks were in query');
   writeln('average time system ',ts/ns:4:4);
end.