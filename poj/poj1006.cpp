#include <iostream>
using namespace std;

void extend_Euclid(int a, int b, int &x, int &y)
{
    if(b==0){x=1;y=0;return;}
    extend_Euclid(b,a%b,x,y);
    int t=x;x=y;y=t-(a/b)*y;
}

int CRT(int *a, int *m, int n)
{
    int M=1,ans=0;
    for(int i=0;i<n;i++)
        M*=m[i];
    for(int i=0;i<n;i++)
    {
        int x,y,Mi=M/m[i];
        extend_Euclid(Mi,m[i],x,y);
        ans=(ans+Mi*a[i]*x)%M;
    }
    if(ans<0) ans+=M;
    return ans;
}

int P=23,E=28,I=33;
int p,e,i,d;

int main()
{
    int T=1;
    while(cin>>p>>e>>i>>d && d!=-1)
    {
        int x;
        x=CRT(&p,&P,3);
        while(x<=d)
            x += 21252;
        cout<<"Case "<<T++<<": the next triple peak occurs in "<<x - d<<" days."<<endl;
    }
    return 0;
}
