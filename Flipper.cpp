#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
//#include <atcoder/dsu>
using namespace std;
#define ll long long int
//ll sts[229][229];
ll arra[600009];
typedef pair<ll,ll> edge;
//map<pair<ll,ll>,ll>edge;
vector<ll>graph[300009];
//map<ll,ll>vis;
ll ve=0,ed=0;
ll vx[400009];
ll B[400009];
ll C[400009];
ll D[400009];
ll DP[2009][2009];
ll ans=0;
ll infs=1000000000001;
map<ll,ll>MEMO;
map<ll,ll>dp,pd;
ll grid[309][309];
ll vis[309];
ll not_vis[309];
//set<ll>sts,stk;
deque<ll>dq;
priority_queue<ll>pq;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>qs;
vector<pair<ll,ll>>gps[3009];
ll ar_ans[1000009];
char az[509][509];
map<pair<string,ll>,ll>mps;
string sts[1009];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,j,k,l,p=0,q=0,r,s,t,inf=10000000001,n,sum=0,m,ans=1;
    string S,ss,T;
   cin>>t;
   while(t--)
   {
      // vector<ll>vx,px,cx,dx;
       cin>>n;
       for(i=0;i<n;i++)
       {
           cin>>s;
           vx[i]=s;
       }
       ll idx=0;
       ll mx=0;
       for( i=0;i<n;i++)if(vx[min(n-1,i+1)]>=vx[min(n-1,idx+1)])idx=i;
   //   cout<<idx<<'\n';
       for(i=idx+1;i<n;i++)
       {
           cout<<vx[i]<<" ";
       }
       cout<<vx[idx]<<" ";
       for(i=idx-1;i>=0;i--)
       {
           if(vx[i]>vx[0])
           {
               cout<<vx[i]<<" ";
               continue;
           }
           else
           {
               for(ll j=0;j<=i;j++)
               {
                   cout<<vx[j]<<" ";
               }

               break;
           }
       }
       cout<<'\n';
   }












}



