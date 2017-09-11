#include <cstdio>
#include <cstdlib>
using namespace std;

char x[1001];
int i;
int getnum()
{
    int y=0;

    while(x[i]!='5'&&x[i]!=0)
    {
        y=y*10+x[i]-'0';
        i++;
    }
    return y;
}

int cmp(const void *a,const void *b)
{return *(int *)a-*(int *)b;}

int main()
{
    int n,a[1000];
    while(~scanf("%s",x))
    {
        n=0;i=0;
        loop:
        while(x[i]=='5') i++;
        if(x[i]!=0)
        {
            a[n++]=getnum();
            goto loop;
        }
        qsort(a,n,sizeof(int),cmp);
        if(n>0) printf("%d",a[0]);
        for(i=1;i<n;i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}
