//hdu 1754 线段树 单点更新 区间取大
#include <cstdio>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int value[200000<<2],index[200000+1];

void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&value[rt]);
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
    rt=index[rt];
    value[rt]=x;
    while(rt>1)
    {
        rt=rt>>1;
        value[rt]=max(value[rt<<1],value[rt<<1|1]);
    }
}

int query(int L, int R, int l, int r, int rt)
{
    if(L<=l && r<=R)
        return value[rt];
    int m=l+((r-l)>>1);
    int ret=0;
    if(L<=m) ret=max(ret,query(L,R,l,m,rt<<1));
    if(R>m) ret=max(ret,query(L,R,m+1,r,rt<<1|1));
    return ret;
}

int main()
{
    int n,m,a,b;
    char s[2];
    while(~scanf("%d%d",&n,&m))
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%s %d %d",s,&a,&b);
            if(s[0]=='Q')
                printf("%d\n",query(a,b,1,n,1));
            else
                update(a,b);
        }
    }
    return 0;
}
