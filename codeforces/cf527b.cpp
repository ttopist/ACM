#include <iostream>
using namespace std;

const int ar='z'-'a'+1;
char S[200000+5],T[200000+5];
int D[ar+1][ar+1];
int n;

int main()
{
    cin>>n>>(S+1)>>(T+1);
    int n1=-1,n2=-1,sum=0;
    bool d1=0,d2=0;

    for(int i=1;i<=n;i++)
       if(S[i]!=T[i])
       {
            sum++;
            int s=S[i]-'a'+1;
            int t=T[i]-'a'+1;

            if(!d2 && D[t][s])
                d2=1,d1=1,n1=i,n2=D[t][s];
            if(!d1 && (D[t][0] || D[0][s]))
                d1=1,n1=i,n2=(D[t][0]?D[t][0]:D[0][s]);
            D[s][t]=i;
            D[s][0]=i;
            D[0][t]=i;
       }

    if(d2) sum-=2;
    else if(d1) sum--;

    cout<<sum<<endl<<n1<<' '<<n2<<endl;

    return 0;
}
