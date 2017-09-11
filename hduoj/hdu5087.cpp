/* hdu5087 求所有递增子序列按长度从大到小排序后，第二个的长度
输入 T n n个数
lis_n2 动态规划时，多建一个数组，记录以第i个位结尾的最长子序列的个数。
最长的个数==1时，输出第二长，最长的个数！=1时输出第一长
注意点，记录个数要用LL型，用int型最好用！=1来判断，或者直接用bool型表示是否唯一。
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
typedef long long int LL;
int n;
int num[40005]={0};
int dp[40005];
int dps[40005];


int lis_n2()
{
    memset(dp,0,sizeof(int)*1001);
    memset(dps,0,sizeof(LL)*1001);
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(num[j]<num[i] && dp[j]>=dp[i])
                dp[i]=dp[j]+1;
        }
        if(dp[i]==1) dps[i]=1;
        else
        {
            dps[i]=0;
            for(int j=0;j<i;j++)
            {
                if(num[j]<num[i] && dp[j]+1==dp[i])
                    dps[i]+=dps[j];
            }
        }
    }
    /*
    for(int i=0;i<n;i++)
        printf("%d ",dp[i]);
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%d ",dps[i]);
    printf("\n");
    */
    int maxi=-1;
    int maxdps=0;
    for(int i=0;i<n;i++)
        maxi=dp[i]>maxi?dp[i]:maxi;
    for(int i=0;i<n;i++)
        if(dp[i]==maxi)
            maxdps+=dps[i];
    if(maxdps>1)
        return maxi;
    else
        return maxi-1;
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
        printf("%d\n",lis_n2());
    }
    return 0;
}
