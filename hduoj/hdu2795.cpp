//hdu 2795 线段树 单点更新 区间取大
#include <cstdio>
using namespace std;
int w;
int max(int a,int b){return a>b?a:b;}
int value[200005<<2],index[200005];

void build(int l,int r,int rt)
{
    if(l==r)
    {
        value[rt]=w;
        index[l]=rt;
        return;
    }
    int m=l+((r-l)>>1);
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    value[rt]=max(value[rt<<1],value[rt<<1|1]);
}

void update(int rt, int x)
{
    if(rt<0) return;
    rt=index[rt];
    value[rt]-=x;
    while(rt>1)
    {
        rt=rt>>1;
        value[rt]=max(value[rt<<1],value[rt<<1|1]);
    }
}

int query(int k, int l, int r, int rt)
{
    if(value[rt]<k)
        return -1;
    if(l==r)
        return l;
    int m=l+((r-l)>>1);
    if(value[rt<<1]>=k)
        return query(k,l,m,rt<<1);
    else
        return query(k,m+1,r,rt<<1|1);
}

int main()
{
    int h,n;
    while(~scanf("%d%d%d",&h,&w,&n))
    {
        h=h<200005?h:200005;
        build(1,h,1);
        while(n--)
        {
            int x;
            scanf("%d",&x);
            int y=query(x,1,h,1);
            printf("%d\n",y);
            update(y,x);
        }
    }
    return 0;
}
