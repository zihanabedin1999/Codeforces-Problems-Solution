#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(vec) vec.begin(),vec.end()
struct node{
 ll val;
 ll left,right;
};
node node_tree[257];
ll ind=0;
void insert_(ll &a,ll val)
{
    if(a==-1)
    {
        node_tree[ind].val=val;
        node_tree[ind].left=-1;
        node_tree[ind].right=-1;
        a=ind;
        ind++;
        return;
    }
    if(val<node_tree[a].val)
        insert_(node_tree[a].left,val);
    else
        insert_(node_tree[a].right,val);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // cout.tie(NULL);
   //x++;
   ll n,t,a,b,m,ans=0,q,i,j,k,l;
//   long long k=0;
   cin>>n>>k;
   set<string>tree;
   for(i=0;i<n;i++)
   {
       ind=0;
       ll source=-1;
       for(j=0;j<k;j++)
       {
           ll value;
           cin>>value;
           insert_(source,value);
       }

   string tree1;
   queue<ll>qs;
   qs.push(source);

   while(!qs.empty())
   {
       ll u=qs.front();
       qs.pop();
       if(node_tree[u].left!=-1)
       {
           tree1+='1';
           qs.push(node_tree[u].left);
       }
       else
       tree1+='0';
       if(node_tree[u].right!=-1)
       {
           tree1+='1';
           qs.push(node_tree[u].right);
       }
       else
       tree1+='0';

   }
   tree.insert(tree1);

   }
   cout<<tree.size()<<'\n';




}

