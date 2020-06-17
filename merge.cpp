#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define loop(i,s,n) for(int i=s;i<n;i++)

int countSwap=0;

void merge(int arr[],int low,int mid,int high)
{
	int sorted[high-low +1];
	int i=low,j=mid+1,k=0;
	
	while(i<mid+1 && j<high+1)
	{
		if(arr[i]<=arr[j])sorted[k++]=arr[i++];
		else 
		{
			sorted[k++]=arr[j++];
			countSwap+=mid-i+1;
		}
	}

	while(i<mid+1)sorted[k++]=arr[i++];
	while(j<high+1)sorted[k++]=arr[j++];
	while(k--)arr[high--]=sorted[k];

}

void mergeSort(int arr[],int low,int high)
{
	if(low>=high)return;
	int mid=(low+high)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);

	merge(arr,low,mid,high);
}

int main()
{   
	fastio;
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    loop(i,0,n)
	    	cin>>arr[i];
	    mergeSort(arr,0,n-1);
	    cout<<endl;
	    cout<<countSwap;
	}	 
    return 0;
}