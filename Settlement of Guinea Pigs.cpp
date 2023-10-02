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

	 }
	 vector<ll>los;
	 for(i=0;i<n;i++)
     {

         if(ac[i]==2)
         {
             los.push_back(s);
             s=0;

         }
         else{
            s++;
         }
     }
     los.push_back(s);
     ll nom=0,som=0,sz=los.size();
     for(i=0;i<sz;i++)
     {
         ll a=0,b=0,c=0,to=2;
         if(som>0)
            a=som-1;
         if(som>0)
            b=1;
        if(a%2==0)
        {

            c=a/to;
        }
        else
            c=a/to+1;
        if(b%2==0)
            c=c+b/to;
        else
            c=c+b/to+1;
        nom=max(nom,c+los[i]);
        som=som+los[i];

     }
     cout<<nom<<'\n';





	 }
}



