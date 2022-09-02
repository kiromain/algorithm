#include <iostream>
#include <algorithm>

using namespace std;

int partitions(int arr[], int low, int high, int pivot)
{
     int p = low;

     for(int i=low;i<=high;i++){
          if(arr[i]<=pivot){
               swap(arr[p],arr[i]);
               p++;
          }
     }
     p--;

     return p;

}

void quicksort(int arr[], int low, int high)
{
     if(low<high){
          int pivot = arr[high];

          int p = partitions(arr,low,high,pivot);

          quicksort(arr,low,p-1);
          quicksort(arr,p+1,high);
     }
}

int main()
{
     int arr[]={4,5,2,1,24,5};

     quicksort(arr,0,5);

     for(int i=0;i<6;i++){
          cout<<arr[i]<<" ";
     }

     return 0;
}
