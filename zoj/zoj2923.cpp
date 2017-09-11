#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct node
{
    int id;
    int insect;
    int step;
    node(int _id, int _insect, int _step):id(_id),insect(_insect),step(_step){}
};

int main()
{
    int m,n,k;
    while(cin>>m>>n>>k)
    {
        short *insect=new short[n+1];
        bool *came=new bool[n+1];
        memset(insect,0,sizeof(short)*(n+1));
        memset(came,0,sizeof(bool)*(n+1));
        for(int i=0;i<n;i++)
        {
            int t;
            cin>>t;
            cin>>insect[t];
        }
        vector<int> *vec=new vector<int>[n+1];
        for(int i=0;i<m;i++)
        {
            int p,q;
            cin>>p>>q;
            vec[p].push_back(q);
            vec[q].push_back(p);
        }
        queue<node> que;
        int ans=0,endstep;
        que.push(node(1,insect[1],1));
        while(!que.empty())
        {
            node x=que.front();
            que.pop();
            if(ans && x.step>endstep)
                break;
            if(x.insect<=k)
            {
                if(x.id==n)
                {
                    if(!ans)
                        endstep=x.step;
                    ans++;
                }else{
                    for(vector<int>::iterator it=vec[x.id].begin();it!=vec[x.id].end();++it)
                    {
                        if(!came[*it])
                        {
                            que.push(node(*it,x.insect+insect[*it],x.step+1));
                        }
                    }
                }
            }
            came[x.id]=1;
        }
        if(ans)
            cout<<ans<<endl;
        else
            cout<<"Impossible!"<<endl;
    }
    return 0;
}
