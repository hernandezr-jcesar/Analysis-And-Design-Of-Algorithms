#include <iostream>
using namespace std;

void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int a[], int l,int h){
	int pivot=a[l];
	int i=l,j=h;
	do{
		do{i++;}while(a[i]<=pivot);
		do{j--;}while(a[j]>pivot);
		if(i<j){
			swap(&a[i],&a[j]);
		}
	}while(i<j);
	swap(&a[l],&a[j]);
	return j;
}

void QuickSort(int a[], int l,int h){
	int j;
 	if(l<h){
		j=partition(a,l,h);
		QuickSort(a,l,j);
		QuickSort(a,j+1,h);
	}
	return;
}

int main(){
	int a[]={8,7,4,1,2,3,9,5,6,10};
	QuickSort(a,0,9);
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
