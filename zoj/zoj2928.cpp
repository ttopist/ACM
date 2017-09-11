#include <cstdio>
#include <cmath>
using namespace std;

double a[101],b[101],c[101];
double x,y,z;
double step,rate=0.992;
int n;

double sqrtdist(double tx,double ty,double tz)
{
    double sum=0;
    for(int i=0; i<n; i++)
        sum+=sqrt((tx-a[i])*(tx-a[i])+(ty-b[i])*(ty-b[i])+(tz-c[i])*(tz-c[i]));
    //printf("tx %f ty %f tz %f sum %f\n",tx,ty,tz,sum);
    return sum;
}

void getans1()
{
    step=1000;
    while(step>1e-12)
    {
        double newx,newy,newz;
        double infd=1e100,dist;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                for(int k=0; k<3; k++)
                {
                    double tx=x+(i-1)*step;
                    double ty=y+(j-1)*step;
                    double tz=z+(k-1)*step;
                    if(tx<0 || ty<0 || tz<0) continue;
                    dist=sqrtdist(tx,ty,tz);
                    if(dist<infd)
                    {
                        x=tx,y=ty,z=tz;
                        infd=dist;
                    }
                }
          step*=rate;
    }
}

void getans2()
{
    step=0.00001;
    //x=int(x*1000)/1000.0;
    //y=int(y*1000)/1000.0;
    //z=int(z*1000)/1000.0;
    int li=0,lj,lk;
    while(!(li==1 && lj==1 && lk==1))
    {
        double infd=1e100,dist;
        double newx,newy,newz;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                for(int k=0; k<3; k++)
                {
                    double tx=x+(i-1)*step;
                    double ty=y+(j-1)*step;
                    double tz=z+(k-1)*step;
                    if(tx<0 || ty<0 || tz<0) continue;
                    dist=sqrtdist(tx,ty,tz);
                    if(dist<infd)
                    {
                        newx=tx,newy=ty,newz=tz;
                        li=i,lj=j,lk=k;
                        infd=dist;
                    }
                }
        x=newx,y=newy,z=newz;
    }
}

double correct(double x)
{
    if(x<0.0005)
        return 0;
    else
        return x;
}

int main()
{
    freopen("input.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%lf %lf %lf",a+i,b+i,c+i);
            //printf("%f %f %f\n",a[i],b[i],c[i]);
        }
        getans1();
        getans2();
        printf("%.3f %.3f %.3f\n",correct(x),correct(y),correct(z));
    }
    return 0;
}
