//hdu5323 �����߶���һ���߶����ڵ�����䣬������ýڵ���߶����ĸ��ڵ������[0,n] Ҫ��n��С
//Ҷ�ӽڵ�ֻ�����ָ��ڵ������������ڵ���4��

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
