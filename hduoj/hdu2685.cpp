#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(!a || !b)
        return 0;
    while(a%b)
    {
        int t=a%b;
        a=b;b=t;
    }
    return b;
}

int qm(int a, int k)
{
    if(k==1)
        return a;
    int t;
    if(k%2==0)
    {
        t=qm(a,k/2);
        return (t*t);
    }else{
        t=qm(a,k/2);
        return (t*t*a);
    }
}

int main()
{
    int a,m,n,k,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>m>>n>>k;
        int t=qm(a,gcd(m,n));
        cout<<(t-1)%k<<endl;
    }
    return 0;
}
