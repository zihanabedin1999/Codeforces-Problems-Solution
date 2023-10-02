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
	 ll n,i,j,k,l=1,s=0,zr=2,t,m;
	 cin>>t;
	 while(t--){
	 cin>>n>>m;
	 ll a,d;
	 a=n*m;
	 d=1;
	 ll c=10;
	 cout<<a<<'\n';
	 for(i=1;i<=n;i++)
     {
        ll sko=d;
        for(j=0;j<c;j++)
            sko=sko*zr;
        for(j=0;j<m;j++)
        {
            ll sots=j+sko;
            cout<<sots+1<<" ";
            }
           d++;
           cout<<'\n';
     }
     cout<<'\n';





	 }
}



