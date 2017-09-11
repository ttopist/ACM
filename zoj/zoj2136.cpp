#include <cstdio>
using namespace std;

int ans[1001][2];

int main()
{
    int n,i,j,t,maxi;
    //ans[0][0]=-1;ans[0][1]=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        for(i=1;i<=t;i++)
        {
            scanf("%d",&(ans[i][0]) );
            maxi=0;
            for(j=1;j<i;j++)
                if(ans[j][0]<ans[i][0] && ans[j][1]>ans[maxi][1])
                    maxi=j;
            ans[i][1]=ans[maxi][1]+1;
        }
        maxi=-1;
        for(i=1;i<=t;i++)
            if(maxi<ans[i][1])
                maxi=ans[i][1];
        printf("%d\n",maxi);
        if(n) printf("\n");
    }
    return 0;
}
