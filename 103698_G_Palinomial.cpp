#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1019260817,N=100010,M=500010;
int ksm(int a,int b=mod-2)
{
    int r=1;
    for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) r=1ll*r*a%mod;
    return r;
}
const int B=2333,iB=ksm(B);int bs[M];
void init(int n=M-10)
{
    for(int i=bs[0]=1;i<=n;i++) bs[i]=1ll*bs[i-1]*B%mod;
}
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
}t[N<<2],a[N];
node operator *(const node a,const node b){return node(1ll*a.x*b.x%mod,1ll*a.y*b.y%mod);}
void build(int u,int l,int r)
{
    if(l==r){t[u]=a[l];return;}
    int mid=(l+r)>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    t[u]=t[u<<1]*t[u<<1|1];
}
node qry(int u,int l,int r,int L,int R)
{
    if(L<=l && r<=R) return t[u];
    int mid=(l+r)>>1;
    if(R<=mid) return qry(u<<1,l,mid,L,R);
    if(L>mid) return qry(u<<1|1,mid+1,r,L,R);
    return qry(u<<1,l,mid,L,R)*qry(u<<1|1,mid+1,r,L,R);
}
int tmp[N];
int main()
{
    int n,q;scanf("%d%d",&n,&q);
    init();
    for(int i=1;i<=n;i++)
    {
        int k;scanf("%d",&k);
        for(int j=0;j<=k;j++) scanf("%d",&tmp[j]);
        int x=0;for(int j=k;j>=0;j--) x=(1ll*x*B+tmp[j])%mod;
        a[i].x=x;
        x=0;for(int j=k;j>=0;j--) x=(1ll*x*iB+tmp[j])%mod;
        a[i].y=1ll*x*bs[k]%mod;
    }
    build(1,1,n);
    while(q --> 0)
    {
        int l,r;scanf("%d%d",&l,&r);
        node v=qry(1,1,n,l,r);
        printf("%d\n",v.x==v.y);
    }
    return 0;
}

