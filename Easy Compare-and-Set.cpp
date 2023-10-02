#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(vec) vec.begin(),vec.end()
const ll MAXN=300009;
vector<pair<ll,ll>>Graph[MAXN];
vector<ll>V,ANS,PRE,FAIL;
ll n,s,total,IN[MAXN],OUT[MAXN],IND[MAXN];
bool chk=true;
bool pairCompare(const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
    return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
}
void dfs(ll src)
{
    for(ll i=IND[src];i<Graph[src].size();i=IND[src])
    {
        auto [sr,id]=Graph[src][i];
       // cout<<sr<<" "<<id<<'\n';
        ++IND[src];
        dfs(sr);
        ANS.push_back(id);
        total--;
    }
    if(src!=s)
    {
        for(auto element:FAIL)
        {
            ANS.push_back(element);

        }
        FAIL.clear();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // cout.tie(NULL);
   //x++;
    ll i,j;
    cin>>n>>s;
    vector<tuple<ll,ll,ll>>Q(n);
    V.push_back(s);
    for(auto &[u,v,weight]:Q)
    {
        cin>>u>>v>>weight;
        V.push_back(u); V.push_back(v);
    }
    sort(all(V));
   V.erase(unique(all(V)), V.end());
    s=lower_bound(all(V),s)-V.begin();
    for(i=1;i<=n;i++)
    {
        auto [u,v,weight]=Q[i-1];
        u=lower_bound(all(V),u)-V.begin();
        v=lower_bound(all(V),v)-V.begin();
        if(weight==0)
        {
            if(u!=s)
            {
                PRE.push_back(i);
            }
            else
                FAIL.push_back(i);
        }
        else
        {
            Graph[u].emplace_back(v,i);
            total++;
            IN[v]++; OUT[u]++;
        }
    }
    ll Src=-1,Dest=-1, val=0;
    for(i=0;i<V.size();i++)
    {
        if(IN[i]+OUT[i]==0)
            continue;
        if(IN[i]+1==OUT[i])
        {
           if(Src==-1)
             Src=i;
             else
             chk=false;

        }
        else if(OUT[i]+1==IN[i])
        {
            if(Dest==-1)

                Dest=i;
                else
                chk=false;

        }
        else if(IN[i]!=OUT[i])
        {
            chk=false;
        }
    }
    if(!(Src==-1&&Dest==-1||Src==s))
        chk=false;
    dfs(s);
    if(FAIL.size()||total)
        chk=false;
    if(chk==false)
        cout<<"No"<<'\n';
    else
    {
        cout<<"Yes\n";
        reverse(all(ANS));
        for(ll ans:PRE)
            cout<<ans<<" ";
        for(ll ans: ANS)
            cout<<ans<<" ";
    }





}

