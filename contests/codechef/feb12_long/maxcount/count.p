var
    num, a, t, n, m : integer;
    ar : array[1..10000] of integer;

begin
    read(t);
    while t>0 do begin
		for a:=1 to 10000 do
			ar[a]:=0;
        read(n);
        for a:=1 to n do begin
            read(num);
            ar[num]:= ar[num]+1
        end;
        num:=0;
		m:=0;
        for a:=1 to 10000 do begin
            if ar[a] > num then begin
                num:= ar[a];
                m:= a;
            end
        end;
        writeln(m,' ',num);
		t:=t-1
    end
end.

