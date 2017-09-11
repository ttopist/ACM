#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct people{
    int id;
    int level;
    friend bool operator<(people n1,people n2)
    {
        if(n1.level==n2.level)  return n2.id<n1.id;
        else                    return n1.level<n2.level;
    }
}one;

int main()
{
    int n,d,ids;
    string io;
    while(cin>>n)
    {
        priority_queue<people> doc[4];
        ids=1;
        while(n--)
        {
            cin>>io>>d;
            if(io=="IN")
            {
                cin>>one.level;
                one.id=ids++;
                doc[d].push(one);
            }else{
                if(doc[d].empty())
                    cout<<"EMPTY\n";
                else
                {   cout<<doc[d].top().id<<endl;
                    doc[d].pop();}
            }
        }
    }
    return 0;
}
