var
	t,tt,a,ch : integer;
     len : longint;
     s : string;

begin
    read(t);
    for tt:=1 to t do
    begin
        read(s);
        len:=length(s);
        for a:=1 to len do
        begin
        	if s[a] = '3' then begin write(' '); a:=a+1; continue; end;
			if s[a] = '9' then
				begin
				if s[a+1] = '0' then begin write('Z'); a:=a+1; continue; end;

				if s[a+1] = '7' then write('a');
				else if s[a+1] = '8' then write('b');
				else if s[a+1] = '9' then write('c');
				a:=a+1; continue;
				end;
			if s[a] >= '6' and s[a] <= '8' then
				begin
				ch := (ord(s[a])-48) * 10 + ord(s[a+1])-48;
				write(ch); a:=a+1;
				end;
			if s[a] = '1' then
				begin
				ch = 100 + (ord(s[a+1])-48)*10 + ord(s[a+2])-48;
				write(ch);
				a:=a+2;
				end;
        end;
    write('\n');
end.

