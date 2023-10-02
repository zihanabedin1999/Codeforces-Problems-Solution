
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
vector<pair<ll,ll>>pxs[300009];
ll idx[200009];
ll dp_s[200009];
void dfs(ll u)
{
    for(auto al:pxs[u])
    {
        if(dp_s[al.first]==0)
        {

            dp_s[al.first]=dp_s[u]+(al.second<=idx[u]);
            idx[al.first]=al.second;
          //  cout<<dp_s[al.first]<<'\n';
            dfs(al.first);
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
            ll n,i,j,k,l=0;
    cin>>n;
    for(i=0;i<=n;i++)
    {
        idx[i]=0;
        dp_s[i]=0;
        pxs[i].clear();
    }
    dp_s[1]=1;
    for(i=1;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        pxs[u].push_back({v,i});
        pxs[v].push_back({u,i});
    }
    dfs(1);
    ll ans=0;
    for(i=1;i<=n;i++)
    {
        ans=max(ans,dp_s[i]);
    }
    cout<<ans<<'\n';



    }







    return 0;
}

