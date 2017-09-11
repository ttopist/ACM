#include <iostream>
#include <cmath>
using namespace std;
const float PI=acos(-1);
int main()
{
    float x,y,s;
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        s=PI*(x*x+y*y)/2;
        cout<<"Property "<<i<<": This property will begin eroding in year "<<ceil(s/50)<<'.'<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
