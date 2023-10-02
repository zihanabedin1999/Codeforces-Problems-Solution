#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll const maxn=300009;
ll P[maxn],Q[maxn],A[maxn],B[maxn],C[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   //x++;
   ll n,t,a,b,m,ans=0,q,i,j,k,l;
//   long long k=0;
  cin>>n>>k;
  for(i=1;i<=n;i++)
  {
      cin>>P[i];
      A[P[i]]=i-n-1;
      B[i]=n;
  }
  for(i=1;i<=n;i++)
  {
      cin>>Q[i];
      if(k>=Q[i]-1)
      {
          B[Q[i]]=0;
          k=k-Q[i]+1;
      }
      else
      {
          for(j=1;j<Q[i];j++)
          {
              C[j]=A[j];
          }
          sort(C+1,C+Q[i]);
          ll x=C[k+1];
          B[Q[i]]=-x;
          break;
      }
  }
  cout<<"Yes"<<'\n';
  for(i=1;i<=n;i++)
  {
      cout<<A[i]<<" ";
  }
  cout<<'\n';
  for(i=1;i<=n;i++)
    cout<<B[i]<<" ";




}

