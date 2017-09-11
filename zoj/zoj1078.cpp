#include <iostream>
#include <queue>
using namespace std;

char str[16];
bool ifpalindrom(int l)
{
    bool yes=1;
    int endi=int(l/2.0);
    for(int i=0;i<endi;i++) if(str[i]!=str[l-i-1]) yes=0;
    return yes;
}

int main()
{
    int x,i,t,l;
    queue<int> q;
    while(cin>>x && x)
    {
        for(i=2;i<=16;i++)
        {
            t=x;l=0;
            while(t)
            {
                str[l++]=t%i;
                t=t/i;
            }
            if(ifpalindrom(l)) q.push(i);
        }
        if(q.empty()) cout<<"Number "<<x<<" is not a palindrom"<<endl;
        else
        {
            cout<<"Number "<<x<<" is palindrom in basis";
            while(!q.empty()){ cout<<' '<<q.front(); q.pop(); }
            cout<<endl;
        }
    }
    return 0;
}
