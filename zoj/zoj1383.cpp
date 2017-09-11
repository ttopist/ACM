#include <iostream>
using namespace std;

int main()
{
    unsigned int i,x,c,n;
    cin>>n;
    while(n--)
    {
        cin>>x;
        c=1;
        i=0;
        while( (c&x)!=c ){c=c<<1;i++;}
        cout<<i;
        for(i++;i<sizeof(unsigned int)*8;i++)
        {
            c=c<<1;
            if((c&x)==c) cout<<' '<<i;
        }
        cout<<endl;
    }
    return 0;
}
