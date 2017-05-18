#include <stdio.h>

#define MAX 10

int min(int dist[],int s[],int n){
	int w,j=1,min=100;
	for(w=1;w<=n;w++){
		if(dist[w]<min && s[w]==0){
			min=dist[w];
			j=w;
		}
	}
	return j;
}

int spath(int cost[][MAX],int n,int v,int dist[MAX]){
	int s[MAX];
	int i,w,num,u;
	for(i=1;i<=n;i++){
		dist[i]=cost[v][i];
		s[i]=0;
	}
	for(num=2;num<=n;num++)
	{
		u=min(dist,s,n);
		s[u]=1;
		for(w=1;w<=n;w++){
			if(dist[u]+cost[u][w] < dist[w] && s[w]==0){
				dist[w]=dist[u] + cost[u][w];
			}
		}
	}
}

int main(){
	int cost[MAX][MAX],v,n,i,j,dist[MAX];
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	printf("Enter source vertex\n");
	scanf("%d",&v);
	spath(cost,n,v,dist);
	for(i=1;i<=n;i++)
		printf("%d--->%d = %d\n",v,i,dist[i]);
	return 0;
}