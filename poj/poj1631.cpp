/*
���� poj1631 �����������
���� t n n�����������������е�Ԫ����Ŀ

lis_n2 ��̬�滮�ⷨ��O(n^2) tle
dp[i]��ʾ��i��β�ĵ�������������Ǹ���Ԫ�ظ���
dp[i]=max(dp[x] && 0<=x<=i-1 && num[x]<num[i])

lis_nlog
��ģ��һ�� 1 2 3 4
��Ȼ��һ������1 2 3 4 �������������� root |-> 1 -> 2 ->3 ->4
��ģ�� 1 30 20 15
����1 root -> 1
����30 root -> 1 -> 30
����20 ��ʱ����ַ���
root -> 1|-> 30
         |-> 20
����15ʱ��������3������������
root -> 1|-> 30
         |-> 20
         |-> 15
����40ʱ��40���Բ�������������
root -> 1|-> 15-> 40
         |-> 20
         |-> 30
�����ǲ�����40������17�ǣ�����17ֻ�ܲ���15���棬
��Ȼ����ͬ���ȵ������У�ֻҪ����һ��ĩ����С�ľ������ˣ�
root -> 1|-> 15-> 17
         |-> 20 x
         |-> 30 x
�ٲ���40
root -> 1|-> 15-> 17 -> 40
         |-> 20 x
         |-> 30 x
�ٲ���14
root -> 1|-> 14
         |-> 15-> 17 -> 40
         |-> 20 x
         |-> 30 x
�ٲ���16
root -> 1|-> 14-> 16
         |-> 15-> 17 -> 40
         |-> 20 x
         |-> 30 x
�ٲ���40�� ��������������
root -> 1|-> 14-> 16 -> 40
         |-> 15-> 17 -> 40 x
         |-> 20 x
         |-> 30 x
ÿ�β��룬��ʵֻ���������������Լ�������󣬾ͼ��������
���ܼ�������󣬾���ǰ��
dps������ÿһ����С����������Ԫ����ǰ��ʱ�ҵ�����ȡ����ӦԪ��

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
