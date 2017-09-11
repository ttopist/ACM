#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int x,y;
    char f;
    node(int _x,int _y,char _f):x(_x),y(_y),f(_f){}
};

char room[502][502];
int n,m;
queue<node> que;

void push(int x,int y,char force)
{
    if(x<1 || x>n || y<1 || y>m || room[x][y]!='X') return;
    room[x][y]=force;
    switch(force)
    {
    case 'W':
        que.push(node(x,y-1,'W'));
        que.push(node(x+1,y-1,'J'));
        que.push(node(x-1,y-1,'V'));
        break;
    case 'E':
        que.push(node(x,y+1,'E'));
        que.push(node(x+1,y+1,'Q'));
        que.push(node(x-1,y+1,'Y'));
        break;
    case 'N':
        que.push(node(x-1,y-1,'V'));
        que.push(node(x-1,y,'N'));
        que.push(node(x-1,y+1,'Y'));
        break;
    case 'S':
        que.push(node(x+1,y-1,'J'));
        que.push(node(x+1,y,'S'));
        que.push(node(x+1,y+1,'Q'));
        break;
    case 'V':
        que.push(node(x-1,y-1,'V'));
        que.push(node(x-1,y,'N'));
        que.push(node(x,y-1,'W'));
        break;
    case 'J':
        que.push(node(x+1,y-1,'J'));
        que.push(node(x,y-1,'W'));
        que.push(node(x+1,y,'S'));
        break;
    case 'Y':
        que.push(node(x-1,y+1,'Y'));
        que.push(node(x,y+1,'E'));
        que.push(node(x-1,y,'N'));
        break;
    case 'Q':
        que.push(node(x+1,y+1,'Q'));
        que.push(node(x+1,y,'S'));
        que.push(node(x,y+1,'E'));
        break;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    bool first=1;
    while(cin>>n>>m)
    {
        if(first)
            first=0;
        else
            cout<<endl;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>room[i][j];

        while(!que.empty()) que.pop();
        int x,y;
        char force;
        cin>>x>>y>>force;
        que.push(node(x,y,force));
        while(!que.empty())
        {
            node t=que.front();
            que.pop();
            push(t.x,t.y,t.f);
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<m;j++)
                cout<<room[i][j];
            cout<<room[i][m]<<endl;
        }
    }
    return 0;
}
