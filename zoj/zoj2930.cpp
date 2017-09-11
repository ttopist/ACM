#include <cstdio>
#include <string.h>
using namespace std;

int a[201],d[201];
bool depend[201];
int n,m;

void dependmax(int x,int y,int &sum, int &advnum)
{
    int i=a[x]+a[y],j=a[x]+d[y],k=d[x]+d[y];
    if(i<=j && i<=k)
        sum+=i,advnum+=2;
    else if(j<=i && j<=k)
        sum+=j,advnum++;
    else
        sum+=k;
    depend[x]=depend[y]=1;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            scanf("%d",a+i);
        for(int i=1; i<=n; i++)
            scanf("%d",d+i);

        memset(depend,0,sizeof(depend));
        scanf("%d",&m);
        int t1,t2;
        int sum=0,advnum=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&t1,&t2);
            dependmax(t1,t2,sum,advnum);
        }
        for(int i=1; i<=n; i++)
            if(!depend[i])
            {
                if(a[i] <= d[i])
                    sum+=a[i],advnum++;
                else
                    sum+=d[i];
            }
        printf("%d %d\n",sum,advnum);
    }
    return 0;
}
