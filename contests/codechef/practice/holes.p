var 
    ar: array [1..26] of byte = (1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0);
    s1: string;
    ans,t,tt,i,len: integer;

begin
    readln(t);
    for tt:= 1 to t do
    begin
		ans:=0;
        readln(s1);
		len:= length(s1);
        for i:= 1 to len do			
            ans:= ans + ar[ord(s1[i])-64];
        writeln(ans);
    end;
end.
