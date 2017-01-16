#include <iostream>
#include <map>
using namespace std;

 map<long,long> dp;

#define abs(x) x<0 ? (-x):x

int m_fn(long number);
long fox(long n);

	int m_fn(long number)
	{
        long n = number, t=0;
		int c=0;

        for (int i = 2; i <= n; i++)
		 {
            while (n % i == 0)
			{
                if(t==i)
                    return 0;
				c++;
                t=i;
                n /= i;
            }
        }
        if(c % 2 == 0)
            return 1;
        else
            return -1;
    }
    
	long fox(long n)
    {
		if(dp[n])
			return dp[n];
         else
         { 
             if(n==1)
                 return 1;
				                 
             long i=0;
             for(i=n/2; i>0; i--)
			 {
                if(n%i==0)
                break;
 			}
             long temp=fox(i)+n*m_fn(n);
			 dp[n] = temp;
             return temp;
            }
        }
        
	int main()
      {
	     int tc,x;
		 cin >> tc;
	 
        while(tc--)
		{
		cin >> x;
        
           for(long i=2*x;;i++)
           {
		   if(abs(fox(i)) > x)
		   {
				cout << i << endl;
				break;
           }
           }
      	}

		return 0;
      }

