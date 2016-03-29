/* hdu5087 �����е��������а����ȴӴ�С����󣬵ڶ����ĳ���
���� T n n����
lis_n2 ��̬�滮ʱ���ཨһ�����飬��¼�Ե�i��λ��β��������еĸ�����
��ĸ���==1ʱ������ڶ�������ĸ�����=1ʱ�����һ��
ע��㣬��¼����Ҫ��LL�ͣ���int������ã�=1���жϣ�����ֱ����bool�ͱ�ʾ�Ƿ�Ψһ��
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
