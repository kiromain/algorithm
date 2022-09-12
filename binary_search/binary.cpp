#include <iostream>
#include <vector>

using namespace std;

int binaryS(vector<int> n,int l,int r,int t)
{

     if(r>=l){


     int middle=(l+r)/2;

     if(t == n[middle]) return middle;
     else if(t<n[middle]) return binaryS(n,l,middle-1,t);
     else return binaryS(n,middle+1,r,t);

     }
     return -1;
}

int main()
{
     vector<int> n{1 ,2, 4, 5, 7, 9, 25};

     int target;
     cout<<"Insert a number you are looking for: "<<endl;
     cin>>target;

     int index = binaryS(n,0,n.size(),target);

     if(index!=-1) cout<<index;
     else cout<<"Element is not in an array"<<endl;
}
