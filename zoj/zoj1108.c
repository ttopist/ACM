#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int w;
	int s;
	int next;
	int n;
} mouse;

int cmp(const void *a ,const void *b)
{
	mouse *c=(mouse *)a,*d=(mouse *)b;
	return c->w - d->w ;
}

mouse m[1002];

int main()
{
/*
freopen("input.txt","r",stdin);
*/

	int i=0,j,N,maxn,t;
	while(scanf("%d %d\n",&(m[i].w),&(m[i].s))!=EOF)
		m[i].id=i+1,i++;
	N=i;
	m[N].w=10010;m[N].s=-10;m[N].id=0;m[N].id=N+1;
	qsort( m , N , sizeof(mouse), cmp);
	for(i=N-1;i>=0;i--)
	{
		maxn=-1;
		for(j=i+1;j<=N;j++)
			if( m[j].s < m[i].s && m[j].n > maxn)
				{t=j;maxn=m[t].n;}
		m[i].next=t;
		m[i].n=m[t].n+1;
	}
	maxn=0;
	for(i=0;i<N;i++)
		if(m[i].n > maxn)
		{
			t=i;
			maxn=m[t].n;
		}
	printf("%d\n",maxn);
	while(t!=N)
	{
		printf("%d\n",m[t].id);
		t=m[t].next;
	}
	return 0;
}
