#include <bits/stdc++.h>
using namespace std;

#define loop(i,s,n) for(int i=s;i<n;i++)

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int l,int h)
{
	int element=arr[l];
	int i=l;
	int j=h;
	do
	{
		cout<<"ibefore:"<<i;		
		do{i++;}while(arr[i]<=element);
		cout<<"iafter:"<<i;
		do{j--;}while(arr[j]>element);
		if(i<j)swap(arr+i,arr+j);
	}
	while(i<j);

	swap(arr+l,arr+j);
	return j;
}

void quicksort(int arr[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=partition(arr,l,h);
		quicksort(arr,l,mid);
		quicksort(arr,mid+1,h);
	}
}

int main()
{   
    int n;
    cin>>n;
    int arr[n];
    loop(i,0,n)
    	cin>>arr[i];

    quicksort(arr,0,n);
    loop(i,0,n)
    	cout<<arr[i]<<" ";
    
    
    
    return 0;
}