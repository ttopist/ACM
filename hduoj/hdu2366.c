#include <stdio.h>
#include <stdlib.h>
int main()
{
	int t,n,d,i;
	int *points,*p;
	points=(int *)malloc(sizeof(int)*200000);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		for(p=points;p<points+2*n;p=p+2)
			scanf("%d%d",p,p+1);
	}
	return 0;
}
