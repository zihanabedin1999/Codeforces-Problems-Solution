
#include<bits/stdc++.h>
//#include <atcoder/dsu>
using namespace std;
#define ll long long int
map<ll,map<string,ll>>version;
vector<string>features;
vector<string>answer;
ll dp[20000009];
vector<ll>vsc;
int main() {

   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,j,k,l,n,a,b=1,to=2,sum=0,fiv=5,m=0;
    string str,queries;
    cin>>t;
    while(t--){
    cin>>n>>m;
    ll dp[n+1][m+1];
    sum=0;
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=m;j++)
         {
             sum++;
             dp[i][j]=sum;
         }
     }
     for(i=2;i<=n;i=i+2)
     {
         for(j=1;j<=m;j++)
         {
             cout<<dp[i][j]<<" ";
         }
         cout<<'\n';
     }
      for(i=1;i<=n;i=i+2)
     {
         for(j=1;j<=m;j++)
         {
             cout<<dp[i][j]<<" ";
         }
         cout<<'\n';
     }

    }




}

