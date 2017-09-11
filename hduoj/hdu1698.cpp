#include <cstdio>
#include <cmath>
using namespace std;

int hook[400000];
int pre[400000];
int n,q,s;

void maketree()
{
    int l,r,w,i,sr,t,f;

    for(i=0;i<400000;i++)
    {
        hook[i]=1;
        pre[i]=0;
    }

    //input
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d",&l,&r,&w);
        l+=s;r+=s;
        while(l<=r)
        {
            f=sr=l;
            t=1;
            while(f%2==0 && sr+t<=r)
            {
                sr+=t;
                t=t+t;
                f=f/2;
            }
            hook[f]=w;
            pre[f]=i;
            l=sr+1;
        }
    }
}

int slove( int k)
{
    if(k>s)
    {
        if(k<=s+n)
            return hook[k];
        else
            return 0;
    }
    int l=2*k;
    int r=l+1;
    if(pre[k]>pre[l])
        pre[l]=pre[k],hook[l]=hook[k];
    if(pre[k]>pre[r])
        pre[r]=pre[k],hook[r]=hook[k];
    return slove(l)+slove(r);
}

int main()
{
    int t,j;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d%d",&n,&q);
        if(n==1)
            s=0;
        else
            //s=(1 << ((int)log2((double)(n-1)) +1) ) - 1;
            {
                            int i=n-1;
            for(s=1;i;i=i>>1) s=s<<1;;
            s--;
            }
        maketree();
        printf("Case %d: The total value of the hook is %d.\n",j,slove(1));
    }
    return 0;
}
