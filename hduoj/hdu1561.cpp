#include <cstdio>
#include <vector>
using namespace std;
typedef long long int LL;

struct node
{
    LL sum[201];
    vector<int> son;
} city[201];

void dfs(int x,int k)
{
    if(k<=0) return;
    vector<int>* pson=&(city[x].son);
    int i,j,t,sn=pson->size();
    for(i=0;i<sn;++i)
        dfs(*pson[i], k-1);
    for(i=0;i<sn;++i)   //for echo son
    {
        for(j=k;j>0;--j)//for echo sum[k]
        {
            LL maxs=0,temp;
            for(t=0;t<k;t++)
            {
                if(j>t)
                {
                    temp=sum[j]
                }
                else
                    break;
            }
            sum[j]=maxs;
        }
    }
}


int main()
{
    int n,k,i,j,f;
    LL v;
    while(~scanf("%d%d",&n,&k))
    {
        for(i=0;i<=n;i++){
            city[i].son.clear();
            city[i].sum=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d%I64d",&f,&v);
            city[f].son.push_back(i);
            for(j=1;j<=k;++j)
                city[i].son[j]=v;
        }
        dfs(0,k+1);
        printf("%I64d\n",city[0].sum);
    }
    return 0;
}
