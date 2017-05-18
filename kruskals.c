#include <stdio.h>
#include <time.h>

struct edge{
	int u,v,cost;
};

typedef struct edge edge;

int find(int v,int parent[]){
	while(parent[v]!=v)
		v=parent[v];
	return v;
}

void union_ij(int i,int j,int parent[]){
	if(i<j)
		parent[j]=i;
	else
		parent[i]=j;
}

void kruskals(int n,edge e[],int m){
	int count,k,sum,p,t[10][10],parent[10],u,v,i,j;
	edge temp;
	count=0;sum=0;k=0;
	for(i=0;i<m;i++){
		for(j=0;j<m-1;j++){
			if(e[j].cost>e[j+1].cost){
				temp.u=e[j].u;
				temp.v=e[j].v;
				temp.cost=e[j].cost;
				e[j].u=e[j+1].u;
				e[j].v=e[j+1].v;
				e[j].cost=e[j+1].cost;
				e[j+1].u=temp.u;
				e[j+1].v=temp.v;
				e[j+1].cost=temp.cost;
			}
		}
	}
	for(i=0;i<n;i++)
		parent[i]=i;
	p=0;
	while(count!=n-1){
		u=e[p].u;
		v=e[p].v;
		i=find(u,parent);
		j=find(v,parent);
		if(i!=j){
			t[k][0]=u;
			t[k][1]=v;
			count++;
			k++;
			sum+=e[p].cost;
			union_ij(i,j,parent);
		}
		p++;
	}
	if(count==n-1){
		printf("Minimum spanning tree exist and Minimum Spanning tree is \n");
		for(i=0;i<n-1;i++){
			printf("%d %d\n",t[i][0],t[i][1]);
		}
		printf("\nCost is %d\n",sum);
	}	
}

int main(){
	edge e[20];
	int n,m,i,j,a,b,cost;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the no. of edges\n");
	scanf("%d",&m);
	printf("Enter adjacency list u v cost\n");
		for(i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&cost);
			e[i].u=a;
			e[i].v=b;
			e[i].cost=cost;
		}
	double clk;
	clock_t startime,endtime;
	startime=clock();
	kruskals(n,e,m);
	endtime=clock();
	clk=(double)(endtime-startime)/CLOCKS_PER_SEC;
	printf("The run time is %f\n",clk);	
	return 0;
}

