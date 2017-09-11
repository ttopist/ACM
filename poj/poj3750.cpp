#include <iostream>
#include <queue>
#include <string>
//#include <cstdio>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    int i,n,x,y;
    char tmp;
    queue<string> q;
    string name;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>name;
        q.push(name);
    }
    cin>>x>>tmp>>y;
    while(--x)
    {
        q.push(q.front());
        q.pop();
    }
    while(!q.empty())
    {
        x=y;
        while(--x)
        {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
