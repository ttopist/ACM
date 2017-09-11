#include <cstdio>
using namespace std;

int main()
{
    int i,t,a,b,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        n=b-a+1;
        a--;b--;
        while(a%3!=0) a++;
        if(a<=b)
            printf("Case %d: %d\n",i,n-((b-a)/3+1));
        else
            printf("Case %d: %d\n",i,n);
    }
    return 0;
}
