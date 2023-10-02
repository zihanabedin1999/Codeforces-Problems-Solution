#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,j,k,l;
    t=1;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        map<ll,ll>mp;
        ll sz=0;
        for(i=0;i<4;i++)
        {
            mp[str[i]-'0']++;
           // sz=max(sz,mp[str[i]-'0']);
        }
        sz=mp.size();
        l=4;
        if(sz==3||sz==4)
        {
            cout<<l<<'\n';
            continue;
        }
        if(sz==1)
        {
            cout<<"-1"<<'\n';
            continue;
        }
        ll ps=4;
        for(auto aol:mp)
        {
            ll pp=aol.second;
            if(pp==3)
                ps=6;
        }
        cout<<ps<<'\n';







    }


    return 0;
}

