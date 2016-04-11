/*
hdu5089 从n道题里选k道题，另做对k-1道题的概率最大
输入： t n k n1 n2 n3..nn (n1 n2 n3 ..nn 表示1-n题的做对概率，且难度递减）
输出： 字典序最小的挑题情况
解： 假如已经挑了k-1道题，全做对概率为allin，做错一题概率为butone，挑最后一道题，做对概率为p
那个k道题做对k-1道题的概率为: allin*(1-p)+butone*p=p(butone-allin)+allin
对于最后一题来说，总是在左右两边挑选 
-> 假如有一个解存在一题在中间的，一定有一个全是左右两边的解比它更优 
-> 只需要枚举所有左右两边的情况

不同于动态规划，动态规划是确实记录挑选前几道题的情况，有明确的递推式。
这道题似乎不能得出：只要挑k-1题做对k-2题概率最大时，那么按某些条件选第k题，就会做对k-1题概率最大的推论

*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
typedef long long int LL;

int N,K;
double probrem[50];
int callcal[50];
int maxcal[50];

double cal()
{
    double ret=0;
    for(int i=1;i<=K;i++)
    {
        double tmp=1;
        for(int j=1;j<=K;j++)
        {
            tmp*=((i==j)?1.0-probrem[callcal[j]]:probrem[callcal[j]]);
        }
        ret+=tmp;
    }
    //for(int i=1;i<=K;i++)
    //    printf("%d ",callcal[i]);
    //printf("%f end c\n",ret);
    return ret;
}

void solve()
{
    for(int i=1,j=N-K+1;i<=K;i++)
        callcal[i]=j++;
    double ret=-1;
    for(int i=0;i<=K;i++)
    {
        callcal[i]=i;
        double x=cal();
        if(x>=ret)
        {
            ret=x;
            for(int j=1;j<=K;j++)
                maxcal[j]=callcal[j];
            if(i<K)
            {
                int re=i+1,rb=i+1;
                double samep=probrem[maxcal[rb]];
                while(re+1<=K && samep==probrem[maxcal[re+1]])
                    re++;
                int x=maxcal[rb],k=0;
                while(x-k-1>=1 && probrem[x-k-1]==samep) k++;
                for(int j=rb;j<=re;j++)
                    maxcal[j]-=k;
            }
            //for(int i=1;i<=K;i++)
            //    printf("%d ",maxcal[i]);
            //printf("end change\n");
        }
    }
    printf("%d",maxcal[1]);
    for(int i=2;i<=K;i++)
        printf(" %d",maxcal[i]);
    printf("\n");
}

int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&K);
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&x);
            probrem[i]=(double)x/100.0;
        }
        solve();
    }
    return 0;
}
