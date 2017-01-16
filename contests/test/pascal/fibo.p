var
	n,i : longint;

function f(n: longint):longint;
begin
	if n < 2 then begin
			f:=n;
	end else begin
		f:= f(n-2) + f(n-1);
	end;
end;

begin;
	read(n);
	for i:=0 to n do begin
		write(f(i),', ');
	end;
end.
