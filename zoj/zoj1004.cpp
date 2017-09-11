#include <cstdio>
#include <stack>
using namespace std;

char x[300],y[300],z[600];
stack<char> s;
void dfs(int i,int j,int k)
{
    if(x[i]==0 && y[j]==0)
    {
        z[k]=0;
        printf("%s\n",z);
        return;
    }
    if(x[i]!=0)
    {
        s.push(x[i]);
        z[k]='i';z[k+1]=' ';
        dfs(i+1,j,k+2);
        s.pop();
    }
    if(!s.empty() && s.top()==y[j])
    {
        s.pop();
        z[k]='o';z[k+1]=' ';
        dfs(i,j+1,k+2);
        s.push(y[j]);
    }
}

int main()
{
    while(~scanf("%s%s",x,y))
    {
        while(!s.empty()) s.pop();
        printf("[\n");
        dfs(0,0,0);
        printf("]\n");
    }
    return 0;
}
