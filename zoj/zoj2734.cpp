#include <iostream>
#include <cstdio>
using namespace std;

int card[10][2];
int M,sum;
void dfs(int n,int ith)
{
    if(n<0) return;
    for(int i=ith;i<M;i++)
    {
        if(n==card[i][0] && card[i][1]>0){
            sum++;
            continue;
        }else if(card[i][1]>0 && n>card[i][0] ){
            card[i][1]--;
            dfs(n-card[i][0],i);
            card[i][1]++;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    cin>>n>>M;
    goto first;
    loop:
        cout<<endl;
    first:
        sum=0;
        for(int i=0;i<M;i++)
            cin>>card[i][0]>>card[i][1];
        dfs(n,0);
        cout<<sum<<endl;;
    if(cin>>n>>M) goto loop;
    return 0;
}
