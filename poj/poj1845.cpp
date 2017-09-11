#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int LL;

LL multi(LL a, LL b, LL m)
{
    LL ans=0; a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%m;
            b--;
        }
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}

LL quick_mod(LL a, LL b, LL m)
{
    LL ans=1; a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}

int main()
{
    LL a,b;
    while(cin>>a>>b)
    {
        if(a==1 || b==0)
        {cout<<1<<endl;continue;}
        if(a==0)
        {
            cout<<0<<endl;continue;
        }
        vector<LL> primeDiv,primeDivIth;
        LL n=a;
        for(LL i=2; i*i<=a; i++)
        {
            LL count=0;
            while(n%i==0) n/=i,count++;
            if(count)
                primeDiv.push_back(i),primeDivIth.push_back(count);
        }
        if(n>1) primeDiv.push_back(n),primeDivIth.push_back(1);

        LL ans=1;
        for(LL i=primeDiv.size()-1;i>=0;i--)
        {
            LL p=primeDiv[i],th=primeDivIth[i];
            LL s= (quick_mod(p,th*b+1,9901*(p-1))-1)/(p-1);
            ans=multi(ans,s,9901);
        }
        cout<<((ans+9901)%9901)<<endl;
    }
    return 0;
}
