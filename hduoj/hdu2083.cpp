#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int cmp(const void *a,const void *b)
{return *(int *)a-*(int *)b;}

int main()
{
    int i,x,t,n,a[500];
    long long int sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        qsort(a,n,sizeof(int),cmp);
        x=a[n/2];
        for(i=0;i<n;i++)
            sum=sum+abs(x-a[i]);
        printf("%I64d\n",sum);
    }
    return 0;
}
