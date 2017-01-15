#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include<cctype>

#define ll unsigned long long int
#define pll pair<long long, long long>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define getchar_unlocked getchar
#define F first
#define S second

using namespace std;

int getint();
long long getlint();

bool ispossible(map<char, int> m, string a);

int main() {
    int testcases = getint();
    for(int t = 1; t<=testcases;t++) {
        string a, b;
        cin>>a>>b;
        ll anum=0, bnum=0;
        int sz = (int)a.size();
        string aans, bans;
        aans = bans = "";
        for(int i=0;i<sz;i++) {
        	if(isdigit(a[i]) && isdigit(b[i])) {
        		anum*=10;
        		bnum*=10;
        		anum+=a[i]-'0';
        		bnum+=b[i]-'0';
        		aans+=a[i];
        		bans+=b[i];
        	}
        	else if(!isdigit(a[i]) && !isdigit(b[i])) {
        		anum*=10;
        		bnum*=10;
        		if(anum>bnum) {
        			bnum+=9;
        			aans+="0";
        			bans+="9";
        		}
        		else if(anum<bnum){
        			anum+=9;
        			aans+="9";
        			bans+="0";
        		}
        		else {
        			aans+="0";
        			bans+="0";
        		}
        	}
        	else if(!isdigit(a[i])){
        		anum*=10;
        		bnum*=10;
        		if(anum<bnum) {
        			anum+=9;
        			aans+="9";
        		}
        		else if(anum == bnum){
        			anum+=b[i]-'0';
        			aans+=b[i];
        		}
        		else {
        			aans+="0";
        		}
        		bnum+=b[i]-'0';
        		bans+=b[i];
        	}
        	else if(!isdigit(b[i])){
        		anum*=10;
        		bnum*=10;
        		if(bnum<anum) {
        			bnum+=9;
        			bans+="9";
        		}
        		else if(anum == bnum){
        			bnum+=a[i]-'0';
        			bans+=a[i];
        		}
        		else {
        			bans+="0";
        		}
        		anum+=a[i]-'0';
        		aans+=a[i];
        	}
        }
        printf("Case #%d: ", t);
        cout<<aans<<" "<<bans<<"\n";
    }
	return 0;
}

bool ispossible(map<char, int> m, string a) {
	for(int i=0;i<a.size();i++) {
		if(m[a[i]]==0)
		return false;
	}
	return true;
}

int getint()
{
    int c,num=0;
    while((c=getchar_unlocked())==' ' || c=='\n')
    ;
    int sign;
    if(c=='-'){
        sign=-1;
    }
    else{
        sign=+1;
    }
    if(c=='-' || c=='+'){
        c=getchar_unlocked();
    }
    while(c!=' ' && c!='\n' && c!=EOF){
        num=(num<<1)+(num<<3)+(c-'0');
        c=getchar_unlocked();
    }
    return num*sign;
}

long long int getlint()
{
    int c;
    long long num=0;
    while((c=getchar_unlocked())==' ' || c=='\n')
    ;
    long long int sign;
    if(c=='-'){
        sign=-1;
    }
    else{
        sign=+1;
    }
    if(c=='-' || c=='+'){
        c=getchar_unlocked();
    }
    while(c!=' ' && c!='\n' && c!=EOF){
        num=(num<<1)+(num<<3)+(c-'0');
        c=getchar_unlocked();
    }
    return num*sign;
}

