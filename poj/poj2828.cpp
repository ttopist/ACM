//poj 2828 线段树 单点更新 特殊查询
#include <cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

int value[200005<<2],index[200005];
int qpos[200005],qval[200005];

void build(int l,int r,int rt)
{
    if(l==r)
    {
        value[rt]=1;
        return;
    }
    int m=l+((r-l)>>1);
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    value[rt]=r-l+1;
}

int query(int k, int l,int r, int rt)
{
    if(l==r)
    {
        value[rt]=0;
        return l;
    }
    int ret;
    int m=l+((r-l)>>1);
    if(k<value[rt<<1])
        ret=query(k,lson);
    else
        ret=query(k-value[rt<<1],rson);
    value[rt]=value[rt<<1]+value[rt<<1|1];
    return ret;
}

int main()
{
    int n,x;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",qpos+i,qval+i);
        build(1,n ,1);
        for(int i=n-1;i>=0;i--)
        {
            x=query(qpos[i],1,n,1);
            index[x]=qval[i];
        }
        printf("%d",index[1]);
        for(int i=2;i<=n;i++)
            printf(" %d",index[i]);
        printf("\n");
    }
    return 0;
}
