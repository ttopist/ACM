#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int t,n,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int num[30000+2]={0},sum[30000+2]={0};
        vector<int> index,pre;
        map<int,int> dn;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",num+i);
            if(dn.find(num[i])!=dn.end())
            {
                sum[i]=num[i];
                index.push_back(i);
                pre.push_back(dn[num[i]]);
            }else{
                sum[i]=sum[i-1]+num[i];
            }
            dn[num[i]]=i;
        }
        index.push_back(n+1);
        /*
        for(int i=1;i<=n;i++)
        {
            printf("%d %d\n",num[i],sum[i]);
        }
        for(int i=0;i<index.size();i++)
        {
            printf("%d %d\n",index[i],pre[i]);
        }
        */
        scanf("%d",&q);
        while(q--)
        {
            int a,b,ans=0;
            scanf("%d %d",&a,&b);
            int i=lower_bound(index.begin(),index.end(),a)-index.begin();
            if(index[i]>b)
                ans+=sum[b]-sum[a-1];
            else{
                int t=index[i];
                ans-=sum[a-1];
                while(t<=b)
                {
                    ans+=sum[t-1];
                    if(pre[i]>=a)
                        ans-=num[i];
                    t=index[++i];
                }
                ans+=sum[b];
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}
