#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int LL;
const int MOD=1000000007;

int an[100009],bn[100009];
int JieCheng[200009];
int Femat[200009];
/*
int multi(int a,int b)
{
    LL A=a%MOD,B=b%MOD;
    LL ans=A*B;
    ans%=MOD;
    return (int)ans;
}
*/
int multi(int a, int b)
{
    int ans=0; a%=MOD;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%MOD;
            b--;
        }
        b>>=1;
        a=(a+a)%MOD;
    }
    return ans;
}

int quick_mod(int a, int b)
{
    int ans=1; a%=MOD;
    while(b)
    {
        if(b&1)
        {
            ans=multi(ans,a);
            b--;
        }
        b>>=1;
        a=multi(a,a);
    }
    return ans;
}

int getFemat(int n)
{
    if(!Femat[n])
        Femat[n]=quick_mod(JieCheng[n],MOD-2);
    return Femat[n];
}

int C(int n, int m)
{
    LL ans=JieCheng[n];
    ans=multi(ans,getFemat(m));
    ans=multi(ans,getFemat(n-m));
    return (int)ans;
}


int main()
{
    JieCheng[0]=1;
    for(int i=1;i<200009;i++)
        JieCheng[i]=multi(JieCheng[i-1],i);

    int t,b1,q,a1,d,n,m;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%d%d%d%d%d%d",&b1,&q,&a1,&d,&n,&m);
        LL ans=0;
        //bn
        bn[1]=b1;
        for(int i=2;i<=m;i++)
            {bn[i]=multi(bn[i-1],q);}
        for(int i=1;i<=m;i++)
        {
            //printf("b%d c[%d][%d]*%d=%d C=%d\n",i,n-1+m-i,n-1,bn[i],multi(C(n-1+m-i,n-1),bn[i]),C(n-1+m-i,n-1));
            ans+=multi(C(n-1+m-i,n-1),bn[i]);
            ans%=MOD;
        }
        //an
        an[1]=a1;
        for(int i=2;i<=n;i++)
            {an[i]=(an[i-1]+d)%MOD;}
        for(int i=1;i<=n;i++)
        {
            //printf("a%d c[%d][%d]*%d=%d C=%d\n",i,n-i+m-1,m-1,an[i],multi(C(n-i+m-1,m-1),an[i]),C(n-i+m-1,m-1));
            ans+=multi(C(n-i+m-1,m-1),an[i]);
            ans%=MOD;
        }
        printf("Case #%d: %I64d\n",cases,ans);
    }
    return 0;
}
