#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll ac[300009];
string stx="";
vector<ll>anxs;
ll sof[500009];
int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	 ll n,i,j,k,l=1,s=0,zr=0,t;
	 cin>>t;
	 while(t--){
	 cin>>n;
	 //vector<ll>ac(n);
	 vector<pair<ll,ll>>vx(n);
	 s=0;
	 set<ll>sot;
	 for(i=0;i<n;i++)
     {
        ll a,b;
        cin>>a>>b;
        vx[i].first=a;
        vx[i].second=b;

     }
     for(i=0;i<=n+2;i++)
     {
         sof[i]=-1;
     }
    sort(vx.begin(),vx.end());
      sof[n - 1] = vx[n - 1].second;
    for ( i = n - 2; i >= 0; i--){
        ll u=sof[i+1];
        ll v=vx[i].second;
       // cout<<u<<" "<<v<<'\n';
        sof[i] = max(u,v);

    }
    ll an=100000000000000007;

    for(i=0;i<n;i++)
    {
        ll tol=sof[i+1];
        ll toz=vx[i].first;
        ll zol=vx[i].second;
        if(i!=n-1)
        {
            ll mon=abs(tol-toz);
            an=min(an,mon);
        }
        if (tol < toz && !sot.empty())
        {
            auto jani_no = sot.upper_bound(toz);

           if (jani_no!=sot.end())
            {
                an = min(an, abs(*jani_no- toz));
                if (jani_no != sot.begin())
                {
                    jani_no--;
                    an = min(an, abs(*jani_no - toz));
                }
            }
            if (jani_no == sot.end())
            {
                 jani_no--;
                an = min(an, abs(*jani_no-toz));
            }
        }
        sot.insert(zol);

    }
    cout<<an<<'\n';





	 }
}



