#include <stdio.h>
#include <time.h>

int g[10][10],n,s[10];
void dfs(int);

int main(){
	int i,j,src;
	clock_t startime,endtime;
	double clk;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(i=1;i<=n;i++)
		s[i]=0;
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	startime=clock();
	dfs(src);
	endtime=clock();
	clk=(double)(endtime-startime)/CLOCKS_PER_SEC;
	printf("The runtime is %f",clk);
	return 0;
}

void dfs(int i){
	int j;
	printf("%d\t",i);
	s[i]=1;

	for(j=1;j<=n;j++)
		if(s[j]==0 && g[i][j]==1)
			dfs(j);
}