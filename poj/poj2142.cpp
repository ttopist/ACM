#include <iostream>
using namespace std;

typedef long long int LL;

void extend_Euclid(LL a, LL b, LL &x, LL &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    extend_Euclid(b, a % b, x, y);
    LL tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}

LL gcd(LL a,LL b)
{
    LL t;
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    while(t=a%b)
    {
        a=b;
        b=t;
    }
    return b;
}

int main()
{
    LL a,b,n,x,y,d;
    while(cin>>a>>b>>n && (a+b+n))
    {
        d=gcd(a,b);
        a=a/d;
        b=b/d;
        extend_Euclid(a,b,x,y);
        x=x*(n/d);
        y=y*(n/d);
        cout<<x<<' '<<y<<' '<<(x%b+b)%b<<' '<<(y%a+a)%a<<endl;

    }
    return 0;
}
