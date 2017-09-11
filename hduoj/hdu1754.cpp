#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int f[200002];
    int n,m,i,j,k,maxs;
    char c;
    while(~scanf("%d %d\n",&n,&m))
    {
        for(i=1;i<n;i++)
            scanf("%d ",f+i);
        scanf("%d\n",f+i);
        while(m--)
        {
            scanf("%c %d %d\n",&c,&i,&j);
            if(c=='U')
                f[i]=j;
            else
            {
                maxs=f[i];
                for(k=i+1;k<=j;k++)
                    if(f[k]>maxs) maxs=f[k];
                printf("%d\n",maxs);
            }
        }
    }
    return 0;
}
