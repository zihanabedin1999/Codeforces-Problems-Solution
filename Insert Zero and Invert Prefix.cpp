
#include<bits/stdc++.h>
//#include <atcoder/dsu>
using namespace std;
#define ll long long int
#define inf 10000000000003
ll sts[229][229];
ll arra[600009];
map<pair<ll,ll>,ll>edge;
//vector<ll>graph[100009];
ll vis1[10009];
ll vis2[10009];
ll ve=0,ed=0;
ll A[400009];
ll B[400009];
ll C[400009];
ll D[400009];
ll DP[2009][2009];
ll ans=0;
map<ll,ll>MEMO;
//map<ll,ll>dp;
priority_queue<ll, vector<ll>, greater<ll> > pq[200009];
//priority_queue<ll, vector<ll>, greater<ll> > box[200009];
set<ll>box[200009];
deque<ll>dx;
vector<ll>graph[2509];
vector<ll>graph2[2509];
ll up[200009][35];
ll depth[200009];
bool visited[200000]{};
ll dist[200000];
ll pathlength[200000]{};
queue<ll> path;
struct edges{
    ll u;
    ll weight;
    ll v;
};
vector<edges>vecs;
bool cmp(edges as, edges bs)
{
    return as.weight <bs.weight;
}
ll par[200001];
ll finds(ll a){
	while(a!=par[a])
        a=par[a];
    return a;
}
bool merges(ll a , ll b){
	a = finds(a);
	b = finds(b);

	if(a == b) return false;

	par[a] = b;
	return true;
}
bool is_prime[3000009];
vector<ll> primes;
void ps(int n) {


    for (ll p = 2; p * p <= n; ++p) {
        if (is_prime[p]==false) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = true;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]==false) {
            primes.push_back(p);
        }
    }


}
unordered_map<ll,ll>mxl;
vector<ll>ansr;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
            ll n,i,j,k,l=0;
    cin>>n;
    mxl.clear();
    ansr.clear();
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    if(A[n-1]==1)
    {
        cout<<"NO"<<'\n';
        continue;
    }
    cout<<"YES"<<'\n';
    for(i=0;i<n;i++)
    {
       if(A[i]==1)
       {
           l++;
           continue;
       }
       else
       {
          mxl[i]=l;
          l=0;
       }
    }
    //cout<<mxl[n-1]<<'\n';
    for(i=n-1;i>=0;i--)
    {

        if(mxl[i])
        {
            ll cnt=mxl[i];
            //cout<<cnt<<'\n';
            for(j=0;j<mxl[i];j++)
            {
                ansr.push_back(0);
            }
            mxl[i]=0;
            ll sos=cnt;
            while(sos)
            {
                i--;
                sos--;
            }
            ansr.push_back(cnt);
           // i++;
        }
        else
        {
            ansr.push_back(0);
        }
    }
    for(ll asz:ansr)
        cout<<asz<<" ";
    cout<<'\n';

    }







    return 0;
}

