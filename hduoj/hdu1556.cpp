#include <cstdio>
#include <string.h>
using namespace std;
int ball[100000+2];
int main()
{
    int n,a,b;
    while(scanf("%d",&n) && n)
    {
        memset(ball,0,sizeof(ball));
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&a,&b);
            ball[a]++;
            ball[b+1]--;
        }
        a=0;
        for(int i=1;i<n;i++)
        {
            a+=ball[i];
            printf("%d ",a);
        }
        printf("%d\n",a+ball[n]);

    }

    return 0;
}
