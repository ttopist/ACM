#include <iostream>
using namespace std;

int main()
{
    int i;
    double x;
    double z[301]={0};
    for(i=1;i<=300;i++)
        z[i]=z[i-1]+1.0/(i+1);
    cin>>x;
    while(x!=0)
    {
        for(i=0;x>z[i];i++) ;
        cout<<i<<" card(s)"<<endl;
        cin>>x;
    }
    return 0;
}
