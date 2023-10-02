#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N=2000010;
const ll INF=1e18;
int X[N],E[N],IND,H[N],EN[N],VAL[N],D[N];
ll n,M,K,ST[N],ENd[N];
ll i,j;
void add(ll A,ll B,ll C)
{
    E[IND]=B;
    EN[IND]=H[A]; VAL[IND]=C; H[A]=IND++;
}
struct node{
    ll SRC,DIST;
    bool operator<(const node & ASL)const{
        return DIST>ASL.DIST;
    }
};
void solve()
{
    ll i,j;
    for(i=0;i<=n;i++)
    {
        D[i]=IND;
    }
    D[1]=0;
    priority_queue<node>QS;
    node value;
    value.SRC=1,value.DIST=D[1];
    QS.push(value);
    ENd[1]=1;
    while(!QS.empty())
    {
        node u=QS.top();
        QS.pop();
        ll a=u.SRC;
        ll dis=u.DIST;
        if(ST[a])
            continue;
        ST[a]=1;
        for(i=H[a];i!=-1;i=EN[i])
        {
            ll b=E[i];
            if(D[b]>dis+VAL[i])
            {
                D[b]=dis+VAL[i];
                ENd[b]=ENd[a];
                node new_val;
                new_val.SRC=b; new_val.DIST=D[b];
                QS.push(new_val);

            }
            else if(D[b]==dis+VAL[i])
            {
                ENd[b]++;
            }
        }
    }
   // cout<<ENd[n]<<'\n';
    if(ENd[n]>=2)
        cout<<"yes"<<'\n';
    else
        cout<<"no"<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>M>>K;
    for(i=1;i<=K;i++)
    {
        cin>>X[i];
    }
    for(i=0;i<=n;i++)
    {
        H[i]=-1;
    }
    for(i=1;i<=M;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    solve();
}

