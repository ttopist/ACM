/* hdu5086
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
typedef long long int LL;
int n,MOD=1000000007;
int num[447005]={0};

int add(int a, int b){ return ((a%MOD)+(b%MOD))%MOD;}

int mul(int a, int b)
{
    long long int temp=(a%MOD);
    temp=temp*(b%MOD);
    return temp%MOD;
}

int sum()
{
    int ret=0;
    for(int i=0;i<n;i++)
    {
        ret=add(ret,mul(mul(i+1,n-i),num[i]));
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",num+i);
        printf("%d\n",sum());
    }
    return 0;
}
