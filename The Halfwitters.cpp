#include <iostream>
#include <fstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,A,B,C,QR,AB[29],i,j,k;
ll FAC[29],DP[29][213];
void solve()
{
    cin>>n>>A>>B>>C>>QR;
    ll mx=(n*(n-1))/2;
    vector<pair<ll,ll>>V;
    for(i=0;i<=mx;i++)
    {
        ll mn=min(A*i,B+A*(mx-i));
        V.push_back({mn,DP[n][i]});
    }
    sort(V.begin(),V.end());
    ll X=0,DS=0,a1=0,a2=0;
    for(i=0;i<=mx;i++)
    {
        a1+=V[i].first*V[i].second;
        a2=a2+V[i].second;
        ll up=a1+(FAC[n]-a2)*C;
        ll down=a2;
        ll D=__gcd(up,down);
        up=up/D;
        down=down/D;
        up+=down*C;
        if(i<mx&&up>V[i].first*down&&up<=V[i+1].first*down)
        {
            X=up;
            DS=down;
            break;
        }
    }
    while(QR--)
    {
        ll cs=0;
        for(i=1;i<=n;i++)
        {
            cin>>AB[i];
            for(j=1;j<i;j++)
            {
                if(AB[j]>AB[i])
                    cs++;
            }
        }
        ll cnt=min(A*cs,B+A*(mx-cs));
        if(DS*cnt<=X)
            cout<<cnt<<"/1"<<'\n';
        else
            cout<<X<<"/"<<DS<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FAC[0]=DP[1][0]=1;
    ll i,j,k,t;
    for(i=1;i<=16;i++)
    {

            FAC[i]=FAC[i-1]*i;


    }
    for(i=1;i<=16;i++)
    {
        for(j=0;j<=(i*(i-1))/2;j++)
        {
            for(k=0;k<=i;k++)
            {
                DP[i+1][j+k]+=DP[i][j];
            }
        }
    }
    cin>>t;
    while(t--)
    {
     solve();
    }

}


