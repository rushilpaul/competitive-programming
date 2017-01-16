var
    ans,len,a,t : longint;
    s : string;
begin
    readln(t);
    while t > 0 do begin
        readln(s);
        len := length(s);
		ans:=0;
        for a:=1 to len do
            if (s[a] <> '4') and (s[a] <> '7') then ans:= ans+1;
		writeln(ans);
		t:= t-1;
    end;
end.

