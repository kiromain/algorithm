#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketsort(int data[],int s)
{
     int minValue = data[0];
	int maxValue = data[0];

	for (int i = 1; i < s; i++)
	{
		if (data[i] > maxValue)
			maxValue = data[i];
		if (data[i] < minValue)
			minValue = data[i];
	}

     int bL = maxValue - minValue + 1;
	vector<int> bucket[bL];

	for (int i = 0; i < bL; i++) bucket[i] = vector<int>();

	for (int i = 0; i < s; i++)
	{
		bucket[data[i] - minValue].push_back(data[i]);
	}

	int k = 0;
	for (int i = 0; i < bL; i++)
	{
		int bucketSize = bucket[i].size();

		if (bucketSize > 0)
		{
			for (int j = 0; j < bucketSize; j++)
			{
				data[k] = bucket[i][j];
				k++;
			}
		}
	}
}

int main()
{
     int arr[20];

     int n;

     cout<<"How many numbers do you want to insert? "<<endl;
     cin>>n;

     for(int i=0;i<n;i++){
          cin>>arr[i];
     }
     cout<<endl;

     bucketsort(arr,n);
     cout<<"Array after bucket sorting "<<endl;
     for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
