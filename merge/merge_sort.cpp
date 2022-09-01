#include <iostream>

using namespace std;

void merge(int arr[],int l,int mid, int r)
{
     int a = mid-l+1;
     int b = r-mid;

     int c[a];
     int d[b];

     for(int i=0;i<a;i++){
          c[i]=arr[l+i];
     }

     for(int i=0;i<b;i++){
          d[i]=arr[mid+1+i];
     }

     int i=0;
     int j=0;
     int k=l;

     while(i<a && j<b){
          if(c[i]<d[j]){
               arr[k]=c[i];
               k++;
               i++;
          }else{
               arr[k]=d[j];
               k++;
               j++;
          }
     }

     while(i<a){
          arr[k]=c[i];
          k++;
          i++;
     }

     while(j<b){
          arr[k]=d[j];
          k++;
          j++;
     }
}


void merge_sort(int arr[],int l, int r)
{
     if(l<r){
          int mid = (l+r)/2;
          merge_sort(arr,l,mid);
          merge_sort(arr,mid+1,r);

          merge(arr,l,mid,r);
     }
}

int main()
{
     int arr[]={23,3,6,8,3,7};
     merge_sort(arr,0,5);

     for(int i=0;i<6;i++){
          cout<<arr[i]<<" ";
     }

     return 0;

}
