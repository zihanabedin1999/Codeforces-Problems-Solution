#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int vis[50000001];
int main() {
    //ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   ll n,t,a,b,m,ans=0,q,i,j;
   long long k=0;
    scanf("%lld%lld%lld%lld%lld%lld",&n,&t,&q,&a,&b,&m);
    if(n<=7000)
    {

        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
               vis[n*(i+j)-2*i*j]=1;
            }

        }
        while(t--)
        {
            q=(q*a+b)%m;
            k=q%(n*n+1);
            if(vis[k])
                ans++;
        }
        printf("%d",ans);
    }
    else
    {
        while(t--)
        {
            q=(q*a+b)%m;
            k=q%(n*n+1);
            k=n*n-2*k;
            if(n%2!=0||k!=0)
            {
                for(i=0;i<=n;i++)
                {
                    if(2*i!=n && k%(2*i-n)==0&&k/(2*i-n)<=n&&k/(2*i-n)>=-n &&(k/(2*i-n)%2+2)%2==n%2 )
                    {
                        ans++;
                        break;
                    }

                }
            }
            else
                ans++;
        }
        printf("%d",ans);
    }







}

