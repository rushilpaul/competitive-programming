var
    s : string;
    c,k,len : integer;
    ch : char;
    

begin
    readln(s);
    c:=0; k:=1;
    len := length(s);
    while (true) do begin
        ch:=s[k+c];
        write(ch);
        if (ch = 'a') or (ch = 'e') or (ch = 'i') or (ch = 'o') or (ch = 'u') then c:=c+2;
        k:=k+1;
		if k+c > len then break;
    end;
end.
    
