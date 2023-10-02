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
ll A[400009];
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
         cin>>A[i];
         ll ans=1;
       if(n==1)
       {
           cout<<"1"<<'\n';
           continue;
       }
       ll co=-1;
       for(i=1;i<n;i++)
       {
           m=co;
           if(A[i]>A[i-1])
           {
               m=0;
           }
           else if(A[i]<A[i-1])
           {
               m=1;
           }
           if(m!=co)
            ans++;
           co=m;
       }
       cout<<ans<<'\n';

   }












}



