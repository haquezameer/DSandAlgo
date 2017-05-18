#include <stdio.h>
#include <limits.h>
#include <time.h> 
int minKey(int key[], int mstSet[], int V)
{
  	int min = INT_MAX, min_index;
 	for (int v = 0; v < V; v++)
     if (mstSet[v] == 0 && key[v] < min)
         min = key[v], min_index = v;
 	return min_index;
}
 
int printMST(int parent[], int V, int graph[10][10])
{
	int cost=0;
   	for (int i = 1; i < V; i++){
      printf("%d - %d\n", parent[i], i);
   	  cost+=graph[i][parent[i]];
   	}
	printf("The cost is %d\n",cost);
}
 
void primMST(int graph[][10],int V)
{
     int parent[10]; 
     int key[10];   
     int mstSet[10];  
     
    for (int i = 0; i < V; i++)
       key[i] = INT_MAX, mstSet[i] = 0;
 
     
     key[0] = 0;    
     parent[0] = -1;  
 
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
 			if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
     printMST(parent, V, graph);
}

int main()
{
    int graph[10][10],v,i,j;
   	clock_t startime,endtime;
   	double clk;
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    printf("Enter the weight matrix\n");
    for(i=0;i<v;i++)
      for(j=0;j<v;j++)
        scanf("%d",&graph[i][j]);
    startime=clock();
    primMST(graph,v);
    endtime=clock();
    clk=(double)(endtime-startime)/CLOCKS_PER_SEC;
    printf("The run time is %lf\n",clk);
    return 0;
  }
