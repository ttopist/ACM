#include <iostream>
//#include <cstdio>
using namespace std;

struct color
{
    int r,g,b;
};

int main()
{
    //freopen("input.txt","r",stdin);
    color target[16],t;
    int i,mini,mind,td;
    for(i=0;i<16;i++)
    {
        cin>>t.r>>t.g>>t.b;
        target[i]=t;
    }
    cin>>t.r>>t.g>>t.b;
    while(t.r!=-1)
    {
        mind=2000000000;
        for(i=0;i<16;i++)
        {
            td=(t.r-target[i].r)*(t.r-target[i].r)+(t.g-target[i].g)*(t.g-target[i].g)+(t.b-target[i].b)*(t.b-target[i].b);
            if(td<mind) mind=td,mini=i;
        }
        cout<<"("<<t.r<<','<<t.g<<','<<t.b<<") maps to ("<<target[mini].r<<','<<target[mini].g<<','<<target[mini].b<<")"<<endl;
        cin>>t.r>>t.g>>t.b;
    }
    return 0;
}
