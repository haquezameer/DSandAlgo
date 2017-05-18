#include <stdio.h>
#include <time.h>

void merge(int a[],int low,int mid,int high){
	int p,q,k,i;
	int ar[high-low+1];
	p=low;q=mid+1;k=0;
	for(i=low;i<=high;i++){
		if(p>mid)
			ar[k++]=a[q++];
		else if(q>high)
			ar[k++]=a[p++];
		else if(a[p]<a[q])
			ar[k++]=a[p++];
		else
			ar[k++]=a[q++];
	}

	for(i=0;i<k;i++)
		a[low++]=ar[i];
}

void mergesort(int ar[],int low,int high){
	if(low<high){
		int mid = (low+high)/2;
		mergesort(ar,low,mid);
		mergesort(ar,mid+1,high);
		merge(ar,low,mid,high);
	}
}

int main(){
	int n,a[100000],i;
	double clk;
	clock_t startime,endtime;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i]=rand()%100;
	printf("Before sorting\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	startime=clock();
	mergesort(a,0,n-1);
	endtime=clock();
	printf("\nAfter sorting\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	clk=(double)(endtime-startime)/CLOCKS_PER_SEC;
	printf("The runtime is %f",clk);
	return 0;
}