#define BUFSIZE 10000
 
 char inputbuffer[BUFSIZE];
 char *ioptr=inputbuffer+BUFSIZE,*ioend=inputbuffer+BUFSIZE;
 int input_eof=0;
  
#define getchar() ({if (ioptr >= ioend) init_input(); *ioptr++;})
#define eof() (ioptr>=ioend && input_eof)
#define eoln() ({if(ioptr >= ioend) init_input(); *ioptr == '\n';})
   
void init_input()
{
   if (input_eof)
	   return;
   int existing = BUFSIZE - (ioend - inputbuffer);
   memcpy(inputbuffer, ioend, existing);
   int wanted = ioend - inputbuffer;
   int count=fread(inputbuffer + existing, 1, wanted, stdin);
   if (count < wanted)
	   input_eof = 1;
   ioend = inputbuffer + BUFSIZE - (wanted - count);
   while (*--ioend > ' ');
	   ioend++;
   ioptr=inputbuffer;
}
  
inline void non_whitespace()
{
	for(;;)
	{
		if(ioptr>=ioend)
			init_input();
		if(*ioptr>' ')
			return;
		ioptr++;
	}
}
	 
 inline int getint()
 {
	 non_whitespace();
	 int n=0;
	 while(*ioptr>' ')
		 n=(n<<3)+(n<<1)+*ioptr++-'0';
	 ioptr++;
	 return n;
 }
