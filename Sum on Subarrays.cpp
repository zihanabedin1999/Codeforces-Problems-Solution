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
    ll t,i,j,k,l,n;
    t=1;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>n>>k;
        if(k==0)
        {
            for(i=0;i<n;i++)
                cout<<"-1 ";
            cout<<'\n';
            continue;
        }
        else
        {
            vector<ll>asz(n);
            for(i=1;i<=n;i++)
            {
                asz[i-1]=-i;
            }
            for(i=0;i<n;i++)
            {
                 for(j=i;j<n;j++)
                 {
                     if(k>0){
                        asz[i]=asz[i]+abs(asz[j]);
                        k--;
                     }
                     if(k<=0)
                        break;
                 }

                 asz[i]=asz[i]+1;
                 if(k<=0)
                    break;
            }
            for(i=0;i<n;i++)
                cout<<asz[i]<<" ";
            cout<<'\n';
        }








    }


    return 0;
}

