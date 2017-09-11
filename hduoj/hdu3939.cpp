#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LL;
const int maxn=1e6+5;
int phi[maxn];
int pf[maxn][7];
int pn[maxn];

void init()
{
    for(int i=2;i<maxn;i++)
        if(phi[i]==0)
            for(int j=i;j<maxn;j+=i)
                pf[j][pn[j]++]=i,phi[j]=j;
    phi[1]=1;
    for(int i=2;i<maxn;i=i+2)
        phi[i]>>=1;
    for(int i=3;i<maxn;i=i+2)
        if(phi[i]==i)
            for(int j=i;j<maxn;j=j+i)
                phi[j]=phi[j]-phi[j]/i;
}

LL dfs(int xth, int r, int n)
{
    LL ans=0;
    for(int i=xth;i<pn[n];i++)
        ans+= r/pf[n][i] - dfs(i+1, r/pf[n][i], n);
    return ans;
}

/*
LL dans,di;
void dfs(int xth, int t, int s, int n)
{
    if(xth==pn[di])
    {
        if(t&1) dans-=n/s;
        else dans+=n/s;
        return;
    }
    dfs(xth+1,t,s,n);
    dfs(xth+1,t+1,s*pf[di][xth],n);
}
*/
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        LL L;
        cin>>L;
        LL ans=0;
        for(LL i=sqrt(L-1.0);i>0;i--)
        {
            //dans=0,di=i;
            LL j=sqrt((double)L-i*i);
            if(i%2==0)
            {
                if(j>=i)
                    ans+=phi[i];
                else
                    ans+=j-dfs(0,j,i);
                    //dfs(0,0,1,j);
            }else{
                if(j>=i)
                    ans+=(i>>1)-dfs(0,i>>1,i);
                    //dfs(0,0,1,i>>1);
                else
                    ans+=(j>>1)-dfs(0,j>>1,i);
                    //dfs(0,0,1,j>>1);
            }
            //ans+=dans;
        }
        cout<<ans<<endl;
    }
    return 0;
}
