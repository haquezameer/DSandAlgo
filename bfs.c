#include <stdio.h>
#include <time.h>

void bfs(int a[][10],int n,int source){
	int q[10],s[10],f=0,r=-1,t,v;
	for(v=0;v<n;v++)
		s[v]=0;
	q[++r]=source;
	s[source]=1;
	while(f<=r){
		t=q[f++];
		for(v=0;v<n;v++){
			if(s[v]==0 && a[t][v]==1)
			{
				q[++r]=v;
				printf("(%d %d)\t",t,v);
				s[v]=1;
			}
		}
	}
}

int main()
{
	int a[10][10],n,i,j,src;
	clock_t endtime,startime;
	double clk;
	printf("Enter no. of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("Enter source vertex\n");
	scanf("%d",&src);
	startime=clock();
	bfs(a,n,src);
	endtime=clock();
	clk=(double)(endtime-startime)/CLOCKS_PER_SEC;
	printf("The run time is %f",clk);
	return 0;
}