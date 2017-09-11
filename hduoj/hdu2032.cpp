#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int n,i,j,a[33][33]={{1},{1},{1,1}};
    for(i=2;i<=30;i++)
    {
        a[i][1]=1;
        for(j=2;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        a[i][i]=1;
    }
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            printf("1");
            for(j=2;j<=i;j++)
                printf(" %d",a[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
