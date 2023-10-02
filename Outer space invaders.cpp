#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(vec) vec.begin(),vec.end()
ll vis[50000001];
ll x=0;
const ll N=1319;
struct p{
 ll a,b,d;
};
p attack[N];

ll dp[N][N];
const ll inf=0x3f3f3f;
vector<ll>Alliens;
unordered_map<ll,ll>uniq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   //x++;
   ll n,t,a,b,m,ans=0,q,i,j,k,l;
//   long long k=0;
   cin>>t;
   while(t--)
   {
       cin>>n;
       for(i=0;i<N;i++)
       {
           for(j=0;j<N;j++)
            dp[i][j]=inf;
       }
       Alliens.clear();
      // uniq.clear();
       for(i=1;i<=n;i++)
       {
           cin>>attack[i].a>>attack[i].b>>attack[i].d;

             Alliens.push_back(attack[i].a);

             Alliens.push_back(attack[i].b);
            // uniq[attack[i].a]=1;
            // uniq[attack[i].b]=1;
       }
       sort(all(Alliens));
       Alliens.erase(unique(all(Alliens)),Alliens.end());
       for(i=1;i<=n;i++)
       {
           attack[i].a=lower_bound(all(Alliens),attack[i].a)-Alliens.begin()+1;
           attack[i].b=lower_bound(all(Alliens),attack[i].b)-Alliens.begin()+1;
       }
    //   for(i=1;i<=n;i++)
       //{
         //  cout<<attack[i].a<<" "<<attack[i].b<<'\n';
      // }
       ll sz=Alliens.size();
     //  cout<<sz<<'\n';
    //   for(ll id:Alliens)
      //  cout<<id<<'\n';
       for(i=1;i<=sz;i++)
       {
           for(l=1;l<=sz;l++)
           {
               ll r=l+i-1;
               if(r>sz)
                break;
               ll new_id=0;
               for(k=1;k<=n;k++)
               {
                   if(attack[k].a>=l&&attack[k].b<=r)
                   {
                       if(attack[k].d>attack[new_id].d)
                        new_id=k;
                   }
               }
               if(new_id==0)
               {
                   dp[l][r]=0;
                   continue;
               }
               for(k=attack[new_id].a;k<=attack[new_id].b;k++)
               {
                    dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k+1][r]+attack[new_id].d);
               }
             //  cout<<new_id<<" "<<dp[l][r]<<" "<<l<<" "<<r<<'\n';
           }
       }
       cout<<dp[1][sz]<<'\n';
   }





}

