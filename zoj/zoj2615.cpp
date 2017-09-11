#include <cstdio>
#include <algorithm>
using namespace std;

int num[300001];
int skip[300001];

int main()
{
    //freopen("input.txt","r",stdin);
    int t,ti,n,m,i,a,b;
    scanf("%d",&t);
    for(ti=1;ti<=t;ti++)
    {
        printf("Case %d:\n",ti);
        scanf("%d",&n);
        scanf("%d",&num[0]);
        skip[0]=0;
        for(i=1;i<n;i++)
        {
            scanf("%d",num+i);
            skip[i]=num[i-1]+skip[i-1];
        }
        //for(i=0;i<n;i++)
        //    printf("%d %d\n",num[i],skip[i]);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d %d",&a,&b);
            if(b==0) printf("No\n");
            else if(a==0) printf("Yes\n");
            else{
                bool flag=0;i=n;
                do{
                    i=(lower_bound(skip,skip+i,b)-skip)-1;
                    if(i==a)
                    {flag=1;break;}
                    else b=i;
                }while(i>a);
                if(flag) printf("Yes\n");
                else printf("No\n");
            }
        }
        if(ti!=t) printf("\n");
    }
    return 0;
}
