#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
const int SN = 333;

char s[N];
bool a[N];
bool b[N][SN];

int main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    int n, m;
    
    scanf("%d%s%d",&n,&s,&m);
    
    int d;
    for(d=1;(d+1)*(d+1)<=n;++d);
    
    for(int i=0;i<n;++i) a[i] = s[i]-'0';
    
    gets(s);
    while(m--){
        gets(s);
        if(*s=='o'){
            for(int i=0;i<n;++i){
                for(int k=1;k<=d;++k) if(b[i][k]){
                    a[i]^=1;
                    b[i][k]=0;
                    if(i+k<n) b[i+k][k]^=1;
                }
                putchar(a[i]+'0');
            }
            puts("");
        }else{
            int i,j,k;
            sscanf(s,"%d%d%d",&i,&j,&k);
            --i;--j;
            if(k>d) for(int x=i;x<=j;x+=k) a[x]^=1;
            else{
                j = i + ((j-i)/k)*k;
                b[i][k]^=1;
                if(j+k<n) b[j+k][k]^=1;
            }
        }
    }
    
    
    return 0;
}

