#include<bits/stdc++.h>
using namespace std;
#define MAX 1e6+10
#define MOD 1000000007
#define ll long long int
#define PI acos(-1)
#define R 510
#define makefast__  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gt greater<ll>
#define vc vector<ll>
map<ll,ll>mp;
ll arra[3000009];
ll arrb[1000009];
map<ll,ll>chk;
ll cns=100000;
vector<vc>adv(cns);
ll po_(ll n)
{
    ll to=2,i=1;
    ll an=1;
    for(i=1;i<=n;i++)
    {
       an=an*to;
    }
    return an;
}
vector<ll>min_,max_,alas;
priority_queue<ll>ab;
vc graph[100009];
 
 
ll ZS;
vector<string>sts(ZS+2);
ll visits[2000009];
ll dist[100009];
vector<ll>ev;
vector<ll>odd;
ll cnt=0;
ll mn=10000000001;
ll mx=0;
ll sus=0;
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,j,k,l;
    cin>>k;
    cout<<"0 ";
   for(i=1;i<=k;i++)
    visits[i]=-1;
    for(i=1;i<k;i++)
    {
        visits[(i*i)%k]=i;
    }
    for(i=1;i<=k-1;i++)
    {
        cout<<visits[i]<<" ";
    }
 
 
 //  }
 
 
 
}