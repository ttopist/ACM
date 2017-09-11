    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstdlib>
    #include <iostream>
    #include <algorithm>
    #include <queue>
    #include <map>
    #include <vector>
    using namespace std;

    #define LL __int64
    const int maxn=1e6+10;
    int prime[maxn],check[maxn],tot;
    int phi[maxn];
    int f[maxn][7];
    int tt[maxn];
    LL ans;
    void get_prime_factor(int n)
    {
        int i=0,m,k=n;
        tt[n]=0;
        if(!check[n])
        {
            f[n][tt[n]]=n;
            tt[n]++;
            return ;
        }
        while(n!=1)
        {
            if(n%prime[i]==0)
            {
                f[k][tt[k]]=prime[i];
                tt[k]++;
                while(n%prime[i]==0)n=n/prime[i];
                if(!check[n])
                {
                    if(n!=1)
                    f[k][tt[k]++]=n;
                    return ;
                }
            }
            i++;
        }
    }
    void init()//预处理，找出所有1e7以内的素数，以减少查找1e14范围数的因子的时间
    {           //现行筛素数的方法，时间复杂度为O(n)
        memset(check,false,sizeof(check));
        int i,j;
        tot=0;
        for(i=2;i<maxn;i++)
        {
            if(!check[i])prime[tot++]=i;
            for(j=0;j<tot;j++)
            {
                int c=i*prime[j];
                if(c>=maxn)break;
                check[c]=true;
                if(c==0)break;
            }
        }

        //获得所有数的质因子
        for(i=1;i<maxn;i++)
        {
            get_prime_factor(i);
        }
    }
    void euler_phi()
    {
        int i,j,k;
        //欧拉函数，phi[i]表示不超过i的与i互质的整数个数
        for(i=2;i<maxn;i++)phi[i]=0;
        phi[1]=1;
        for(i=2;i<maxn;i++)
            if(!phi[i])
            for(j=i;j<=maxn;j+=i){
                if(!phi[j])phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
    }
    void dfs(int t,int num,int n,int sum,int k)
    {
        if(t==tt[k])
        {
            if(num&1)ans-=n/sum;
            else ans+=n/sum;
            return ;
        }
        dfs(t+1,num,n,sum,k);
        dfs(t+1,num+1,n,sum*f[k][t],k);
    }
    int main()
    {
        init();
        euler_phi();
        int T;
        scanf("%d",&T);
        while(T--)
        {
            int i,j,k,n,m;
            LL l;
            ans=0;
            scanf("%I64d",&l);
            n=(int)sqrt(l+0.5);
            for(i=1;i<=n;i++)
            {
                m=(int)sqrt(l-(LL)i*i+0.5);
                if(i&1)
                {
                    if(i<=m)dfs(0,0,i>>1,1,i);
                    else dfs(0,0,m>>1,1,i);
                }
                else
                {
                    if(i<=m)ans+=phi[i];
                    else dfs(0,0,m,1,i);
                }
            }
            printf("%I64d\n",ans);
        }
        return 0;
    }
