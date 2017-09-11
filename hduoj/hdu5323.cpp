//hdu5323 给出线段树一个线段树节点的区间，求包含该节点的线段树的根节点的区间[0,n] 要求n最小
//叶子节点只有三种父节点的情况，其他节点有4种

#include <cstdio>
using namespace std;

int minn;

void dfs(int l, int r)
{
    if(l<0 || l>r) return;
    if(l==0)
    {
        if(minn<0) minn=r;
        else minn=r<minn?r:minn;
        return;
    }
    int len=r-l+1;
    if(len > l ) return;
    dfs( ((l-1)<<1)-r, r);
    dfs( ((l-1)<<1)+1-r, r );
    dfs( l, (r<<1)+1-l );
    if(len>1)
        dfs( l, (r<<1)-l );
}

int main()
{
    int l,r;
    while(~scanf("%d%d",&l,&r))
    {
        minn=-1;
        dfs(l,r);
        printf("%d\n",minn);
    }
    return 0;
}
