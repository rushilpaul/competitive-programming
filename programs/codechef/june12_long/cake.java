//Program question at: http://www.codechef.com/JUNE12/problems/CAKEDOOM
import java.util.*;
class cake
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            int a=0,k=sc.nextInt(),len;
            char s[] = sc.next().toCharArray();
            len = s.length;
            if(len == 1 && s[0] != '?')
			{
                System.out.println(new String(s));
                continue;
            }
            if(k==2 && s[0] == '?')
            {
                while(s[++a] == '?');
                if(a < len && ((a%2 == 0 && s[a] == 49) || (a%2 == 1 && s[a] == 48))) s[0] = 49;
            }
            int l,r,p;
			boolean done = false;
            for(a=0; a<len; a++)
            {
                l = a==0 ? len-1 : a-1;
                r = a==len-1 ? 0 : a+1;
                p=0;
                if(s[a] == '?')
                {
                    while(s[l]-48 == p || s[r]-48 == p) p++;
                    if(p >= k)
					{
                        System.out.println("NO");
                        done = true;
                        break;
                    }
                    s[a] = (char)(p+48);
                }
                else
                {
                    if(s[a] == s[l] || s[a] == s[r] || s[a] >= k+48)
					{
                        System.out.println("NO");
                        done = true;
						break;
                    }
                }
            }
            if(done) continue;
            System.out.println(new String(s));
        }
    }
}
