/*
题意 poj1631 求最长递增队列
输入 t n n个数，输出最长递增队列的元素数目

lis_n2 动态规划解法，O(n^2) tle
dp[i]表示以i结尾的递增子序列中最长那个的元素个数
dp[i]=max(dp[x] && 0<=x<=i-1 && num[x]<num[i])

lis_nlog
先模拟一下 1 2 3 4
显然，一次输入1 2 3 4 构造的最长子序列是 root |-> 1 -> 2 ->3 ->4
再模拟 1 30 20 15
输入1 root -> 1
输入30 root -> 1 -> 30
输入20 这时候出现分歧
root -> 1|-> 30
         |-> 20
输入15时，出现了3条递增子序列
root -> 1|-> 30
         |-> 20
         |-> 15
输入40时，40可以插在所有链后面
root -> 1|-> 15-> 40
         |-> 20
         |-> 30
当我们不输入40，输入17是，发现17只能插在15后面，
显然，相同长度的子序列，只要保留一条末端最小的就行了了，
root -> 1|-> 15-> 17
         |-> 20 x
         |-> 30 x
再插入40
root -> 1|-> 15-> 17 -> 40
         |-> 20 x
         |-> 30 x
再插入14
root -> 1|-> 14
         |-> 15-> 17 -> 40
         |-> 20 x
         |-> 30 x
再插入16
root -> 1|-> 14-> 16
         |-> 15-> 17 -> 40
         |-> 20 x
         |-> 30 x
再插入40， 短链竞争过长链
root -> 1|-> 14-> 16 -> 40
         |-> 15-> 17 -> 40 x
         |-> 20 x
         |-> 30 x
每次插入，其实只有两个操作，可以加在最长链后，就加在最长链后
不能加在最长链后，就往前加
dps数组是每一层最小的数，方便元素往前加时找到，并取代相应元素

*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int num[40005]={0};
int dp[40005],dps[40005];

int lis_vector()
{
    vector<int> vec;
    vec.push_back(num[0]);
    for(int i=1;i<n;i++)
    {
        if(vec[vec.size()-1]<num[i])
        {
            vec.push_back(num[i]);
        }else{
            vector<int>::iterator it=lower_bound(vec.begin(),vec.end(),num[i]);
            *it=num[i];
        }
    }
    return vec.size();
}

int lis_nlogn()
{
    int dpslen=1;
    dps[1]=num[0];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        if(num[i]>dps[dpslen])
        {
            dps[++dpslen]=num[i];
            dp[i]=dpslen;
        }else{
            int k=(int *)lower_bound(dps+1,dps+dpslen+1,num[i])-dps;
            dps[k]=num[i];
            dp[i]=k;
        }
    }
    return dpslen;
}

int lis_n2()
{
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(num[j]<num[i] && dp[j]>=dp[i])
                dp[i]=dp[j]+1;
        }
    }
    int ret=0;
    for(int i=0;i<n;i++)
        ret=dp[i]>ret?dp[i]:ret;
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
        printf("%d\n",lis_vector());
    }
    return 0;
}
