#include <stdio.h>
#include <time.h>
int ar[1000000];

int partition(int low,int high){
	int i,j,pivot,temp;
	pivot=ar[high];
	i=low-1;
	for(j=low;j<=high-1;j++){
		if(ar[j]<pivot){
			i=i+1;
			temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
		}
	}

	temp=ar[i+1];
	ar[i+1]=ar[high];
	ar[high]=temp;
	return i+1;
}

void quicksort(int low,int high){
	if(low<high){
		int q;
		q=partition(low,high);
		quicksort(low,q-1);
		quicksort(q+1,high);
	}
}

int main(){
	int n,i;
	clock_t startime,endtime;
	double clk;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		ar[i]=rand()%100;
	printf("Before sorting\n");
	for(i=0;i<n;i++)
		printf("%d\t",ar[i]);
	startime=clock();
	quicksort(0,n-1);
	endtime=clock();
	printf("\nThe sorted array is : \n");
	for(i=0;i<n;i++)
		printf("%d\t",ar[i]);
	clk=(double)(endtime-startime)/CLOCKS_PER_SEC;
	printf("\nThe run time is %f",clk);
	return 0;
}