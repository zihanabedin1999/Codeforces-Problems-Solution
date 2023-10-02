#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
using namespace std;

template <typename T> void read(T &value) {
	value=0;char ch=getchar();int negativeSign=1;
	while (ch<'0'||ch>'9') {if (ch=='-') negativeSign=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') value=value*10+ch-'0',ch=getchar();
	value*=negativeSign;
}

template <typename T> void write(T value) {
	if (value<0) value=-value,putchar('-');
	if (value>9) write(value/10);
	putchar(value%10+'0');
}

template <typename T> void writeln(T value) {
	write(value);
	puts("");
}

int numRow,numColumn;
long long target;
char direction[15];
__int128_t result;
int pre[35],suf[35];

long long get(long long x,long long y) {
	int a=x/(1<<numRow),b=x%(1<<numRow),c=y/(1<<numColumn),d=y%(1<<numColumn);
	return (a^d)+(1ll<<numColumn)*(b^c);
}

long long calc(int y,int x) {
	if(x<0) return 0;
	for(int i=29;i>=0;--i)
		pre[i]=pre[i+1]*2+(x>>(i+1)&1);
	for(int i=1;i<=29;++i)
		suf[i]=suf[i-1]+((x>>(i-1)&1)<<(i-1));
	long long res=0;
	for(int i=29;i>=0;--i)
	{
		int countZero=(x>>i&1?(pre[i]+1)*(1<<i):pre[i]*(1<<i)+suf[i]+1);
		res+=1ll*countZero*((y>>i&1)<<i);
		int countOne=(x>>i&1?pre[i]*(1<<i)+suf[i]+1:pre[i]*(1<<i));
		res+=1ll*countOne*((y>>i&1^1)<<i);
	}
	return res;
}

signed main()
{
	int testCases; read(testCases);
	while(testCases--)
	{
		read(numRow); read(numColumn); scanf("%s",direction); read(target);
		result=0;
		if(direction[0]=='l')
		{
			long long cnt=get(target-1,0)+1;
			int round=cnt/(1<<numColumn),remainder=cnt%(1<<numColumn);
			result+=(__int128_t)round*calc((target-1)/(1<<numRow),(1<<numColumn)-1);
			if(remainder) result+=calc((target-1)/(1<<numRow),remainder-1);
			__int128_t sum=0;
			if(round) sum+=(__int128_t)(1<<numColumn)*calc((target-1)%(1<<numRow),round-1);
			sum+=(__int128_t)remainder*(((target-1)%(1<<numRow))^round);
			result+=sum*(1<<numColumn); result+=cnt;
			writeln(result);
		}
		if(direction[0]=='r')
		{
			long long cnt=get(target-1,(1ll<<numRow+numColumn)-1)+1;
			int round=cnt/(1<<numColumn),remainder=cnt%(1<<numColumn);
			result+=(__int128_t)round*calc((target-1)/(1<<numRow),(1<<numColumn)-1);
			result+=calc((target-1)/(1<<numRow),(1<<numColumn)-1)-calc((target-1)/(1<<numRow),(1<<numColumn)-1-remainder);
			__int128_t sum=0;
			if(round) sum+=(__int128_t)(1<<numColumn)*(calc((target-1)%(1<<numRow),(1<<numRow)-1)-calc((target-1)%(1<<numRow),(1<<numRow)-1-round));
			sum+=(__int128_t)remainder*(((target-1)%(1<<numRow))^((1<<numRow)-1-round));
			result+=sum*(1<<numColumn); result+=cnt;
			writeln(result);
		}
		if(direction[0]=='t')
		{
			long long cnt=get(0,target-1)+1;
			int round=cnt/(1<<numRow),remainder=cnt%(1<<numRow);
			__int128_t sum=0;
			sum+=(__int128_t)round*calc((target-1)/(1<<numColumn),(1<<numRow)-1);
			if(remainder) sum+=calc((target-1)/(1<<numColumn),remainder-1);
			result+=sum*(1<<numColumn); result+=cnt;
			if(round) result+=(__int128_t)(1<<numRow)*calc((target-1)%(1<<numColumn),round-1);
			result+=(__int128_t)remainder*(((target-1)%(1<<numColumn))^round);
			writeln(result);
		}
		if(direction[0]=='b')
		{
			long long cnt=get((1ll<<numRow+numColumn)-1,target-1)+1;
			int round=cnt/(1<<numRow),remainder=cnt%(1<<numRow);
			__int128_t sum=0;
			sum+=(__int128_t)round*calc((target-1)/(1<<numColumn),(1<<numRow)-1);
			sum+=calc((target-1)/(1<<numColumn),(1<<numRow)-1)-calc((target-1)/(1<<numColumn),(1<<numRow)-1-remainder);
			result+=sum*(1<<numColumn); result+=cnt;
			if(round) result+=(__int128_t)(1<<numRow)*(calc((target-1)%(1<<numColumn),(1<<numColumn)-1)-calc((target-1)%(1<<numColumn),(1<<numColumn)-1-round));
			result+=(__int128_t)remainder*(((target-1)%(1<<numColumn))^((1<<numColumn)-1-round));
			writeln(result);
		}
	}
	return 0;
}


