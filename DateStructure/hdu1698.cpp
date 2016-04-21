//hdu 1698 区间重置某值，区间求和
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN=100000;


struct node{
    int l,r;
    int value;
    int flag;
} nodes[MAXN<<2];

void build(int x, int l, int r)
{
    nodes[x].l=l;nodes[x].r=r;nodes[x].flag=0;
    if(l<r)
    {
        int m=l+((r-l)>>1);
        build(x<<1,l,m);
        build((x<<1)+1,m+1,r);
        nodes[x].value=nodes[x<<1].value+nodes[(x<<1)+1].value;
    }else
        nodes[x].value=1;
}

void update(int x, int l, int r, int v)
{
    if(l>r || l>nodes[x].r || r<nodes[x].l)
        return;
    if(l<=nodes[x].l && nodes[x].r<=r)
    {
        nodes[x].flag=v;
        nodes[x].value=v*(nodes[x].r-nodes[x].l+1);
    }else{
        if(nodes[x].flag!=0)
        {
            update(x<<1,nodes[x].l,nodes[x].r,nodes[x].flag);
            update((x<<1)+1,nodes[x].l,nodes[x].r,nodes[x].flag);
            nodes[x].flag=0;
        }
        update(x<<1,l,r,v);
        update((x<<1)+1,l,r,v);
        nodes[x].value=nodes[x<<1].value+nodes[(x<<1)+1].value;
    }
}

int query(int x, int l, int r)
{
    if(l>r || l>nodes[x].r || r<nodes[x].l)
        return 0;
    if(l<=nodes[x].l && nodes[x].r<=r)
        return nodes[x].value;
    return query(x<<1,l,r)+query((x<<1)+1,l,r);
}

int main(int argc, char* argv[])
{
    int t,n,q,a,b,c;
    scanf("%d",&t);
    for(int casei=1;casei<=t;casei++)
    {
        scanf("%d%d",&n,&q);
        build(1,1,n);
        while(q--)
        {
            scanf("%d%d%d",&a,&b,&c);
            update(1,a,b,c);
        }
        printf("Case %d: The total value of the hook is %d.\n",casei,query(1,1,n));
    }
	return 0;
}

