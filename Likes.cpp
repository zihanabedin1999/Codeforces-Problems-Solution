#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll ac[300009];
string stx="";
vector<ll>anxs;
bool compa(pair<ll,ll>p1,pair<ll,ll>p2)
{
        if(p1.first==p2.first)
		{
			 return p1.second<p2.second;
		}

		 return  p1.second<p2.second;
}
int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	 ll n,i,j,k,l=1,s=0,zr=0,t;
	 cin>>t;
	 while(t--){
	 cin>>n;
	 //vector<ll>ac(n);
	 s=0;
	 for(i=0;i<n;i++){
        cin>>ac[i];
        if(ac[i]>0)
            s++;
	 }
        ll nos=n-s;
        ll ct=0,tz=s,tb=nos;
        for ( i = 0; i < n; i++)
        {
            if (s)
            {
                ct++;
                s--;
            }
            else
            {
                ct--;
                nos--;
            }
            cout << ct << " ";
        }
        cout <<'\n';
        ll par=0;
        ct=0;
        for ( i = 0; i < n; i++)
        {
            if (par<=0)
            {
                if (tz)
                {
                    ct++;
                    cout << ct << " ";
                    tz--;
                }
                else
                {
                    ct--;
                    cout << ct << " ";
                    tb--;
                }
            }
            else
            {
                if (tb)
                {
                    ct--;
                    cout << ct << " ";
                    tb--;
                }
                else
                {
                    ct++;
                    cout << ct << " ";
                    tz--;
                }
            }
            par =1-par;
        }
        cout <<'\n';




	 }
}



