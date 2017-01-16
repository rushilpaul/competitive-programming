var t,m,l,i : longint;
    s : string;

begin
    read(t);
    while t>0 do
       begin
        t:=t-1;
        readln(s);
        l := length(s); m := (l div 2);
        i:=m-1;
        while i>=0 do
           begin
            write(s[i]);
            i:=i-1;
           end;
        i:=l-1;
        while i>=m do
           begin
            write(s[i]);
            i:=i-1;
     	   end;
		writeln();
      end;
end.
