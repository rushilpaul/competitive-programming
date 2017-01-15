var n,k,ti,ans : longint;

begin
    ans:=0;
    read(n,k);
    while n>0 do
        begin
        read(ti);
        if ti mod k = 0 then ans:=ans+1;
		n:=n-1;
        end;
	writeln(ans);
end.
