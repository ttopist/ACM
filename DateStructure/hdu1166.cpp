//hdu1166 线段树单点更新 区间求和
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN=50004;
int ith2node[MAXN];
struct node{
    int l,r;
    int value;
} nodes[MAXN<<2];

void build(int x, int l, int r)
{
    nodes[x].l=l;nodes[x].r=r;
    if(l<r)
    {
        int m=l+((r-l)>>1);
        build(x<<1,l,m);
        build((x<<1)+1,m+1,r);
        nodes[x].value=nodes[x<<1].value+nodes[(x<<1)+1].value;
    }else{
        scanf("%d",&nodes[x].value);
        ith2node[l]=x;
    }
}

void update(int x, int v)
{
    x=ith2node[x];
    while(x>0)
    {
        nodes[x].value+=v;
        x=x/2;
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
    int t,n,a,b;
    char op[10];
    scanf("%d",&t);
    for(int casei=1;casei<=t;casei++)
    {
        printf("Case %d:\n",casei);
        scanf("%d",&n);
        build(1,1,n);
        while(1)
        {
            scanf("%s",op);
            if(op[0]=='E')
                break;
            scanf("%d %d",&a,&b);
            switch(op[0])
            {
            case 'Q':
                printf("%d\n",query(1,a,b));
                break;
            case 'A':
                update(a,b);
                break;
            case 'S':
                update(a,-b);
            }
        }
    }
	return 0;
}
