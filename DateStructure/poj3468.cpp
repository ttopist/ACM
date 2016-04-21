
//poj3468 线段树区间更新 区间查询
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
typedef long long int LL;
const int MAXN=100000+5;
struct node{
    int l,r;
    LL value;
    LL flag;
} ns[MAXN<<2];

void build(int x, int l, int r)
{
    ns[x].l=l;ns[x].r=r;ns[x].flag=0;
    if(l<r)
    {
        int m=l+((r-l)>>1);
        build(x<<1,l,m);
        build((x<<1)+1,m+1,r);
        ns[x].value=ns[x<<1].value+ns[(x<<1)+1].value;
    }else
        scanf("%I64d",&(ns[x].value));
}

void flagdown(int x)
{
    LL f=ns[x].flag;
    if(f!=0 && ns[x].l!=ns[x].r)
    {
        int xl=x<<1;
        int xr=(x<<1)+1;
        ns[xl].flag+=f;
        ns[xl].value+=f*(ns[xl].r-ns[xl].l+1);
        ns[xr].flag+=f;
        ns[xr].value+=f*(ns[xr].r-ns[xr].l+1);
        ns[x].flag=0;
        //ns[x].value不用更新，标记下移过程不变的
    }
}

void update(int x, int l, int r, int v)
{
    if(l<=ns[x].l && ns[x].r<=r)
    {
        ns[x].flag+=v;
        ns[x].value+=v*(ns[x].r-ns[x].l+1);
        //printf("update [%d,%d].value=%d\n",ns[x].l,ns[x].r,ns[x].value);
    }else{
        flagdown(x);
        int m=(ns[x].l+ns[x].r)>>1;
        if(l<=m) update(x<<1,l,r,v);
        if(r>m) update((x<<1)+1,l,r,v);
        ns[x].value=ns[x<<1].value+ns[(x<<1)+1].value;
        //printf("update [%d,%d].value=%d\n",ns[x].l,ns[x].r,ns[x].value);
    }
}

LL query(int x, int l, int r)
{
    if(l<=ns[x].l && ns[x].r<=r)
    {
        //printf("query [%d,%d].value=%d\n",ns[x].l,ns[x].r,ns[x].value);
        return ns[x].value;
    }

    flagdown(x);
    //printf("query by [%d,%d].value=%d\n",ns[x].l,ns[x].r,ns[x].value);
    LL c=0;
    int m=(ns[x].l+ns[x].r)>>1;
    if(l<=m) c+=query(x<<1,l,r);
    if(r>m) c+=query((x<<1)+1,l,r);
    return c;
}

int main(int argc, char* argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,q,b,c,v;
    char a[4];
    scanf("%d%d",&n,&q);
    build(1,1,n);
    while(q--)
    {
        scanf("%s %d %d",a,&b,&c);
        if(a[0]=='Q')
            printf("%I64d\n",query(1,b,c));
        else{
            scanf("%d",&v);
            update(1,b,c,v);
        }
    }
	return 0;
}