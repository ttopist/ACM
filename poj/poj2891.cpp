#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int LL;

LL gcd(LL a, LL b)
{
    LL t;
    if(a<b) { t=a;a=b;b=t;}
    while(t=a%b){a=b;b=t;}
    return b;
}

void extend_Euclid(LL a, LL b, LL &x, LL &y)
{
    if(b==0){x=1;y=0;return;}
    extend_Euclid(b,a%b,x,y);
    LL t=x;x=y;y=t-(a/b)*y;
}

LL solve(LL &a1, LL &r1, LL a2, LL r2)
{
    int d=gcd(a1,a2);
    if((r2-r1)%d!=0)
        return -1;
    LL x,y;
    extend_Euclid(a1,a2,x,y);
    x*=(r2-r1)/d;
    x=(a2+x%a2)%a2;
    //y=((r2-r1)-a1*x)/a2;
    //while(y>=0) x+=a2,y-=a1;
    r1=r1+x*a1;
    a1=d*(a1/d)*(a2/d);
    r1=(r1%a1+a1)%a1;
    return r1;
}

int main()
{
    LL t;
    while(cin>>t)
    {
        LL m,a1,r1,a2,r2;
        cin>>a1>>r1;
        m=r1+a1;
        while(--t)
        {
            cin>>a2>>r2;
            if(m!=-1)
                m=solve(a1,r1,a2,r2);
        }
        cout<<m<<endl;
    }
    return 0;
}
