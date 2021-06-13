#include <iostream>
#include<cmath>
using namespace std;

int partition(int arr[], int s, int e)
{
  int pivot = arr[e];
  int pIndex = s;
  for(int i = s; i < e; i++)
  {
    if(arr[i]<=pivot)
    {
      swap(arr[i], arr[pIndex]);
      pIndex ++;
    }
  }
  swap(arr[e],arr[pIndex]);
  return pIndex;
}

void quicksort(int arr[],int s, int e)
{
  if(s<e)
  {
    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
  }
}

int jumpsearch(int arr[], int length, int key)
{
  int left = 0;
  int right = sqrt(length);
  while(arr[right] <= key && right < length)
  {
    left = right;
    right = right + sqrt(length);
    if(right >= length -1)
      right = length;
  }
  for(int i = left; i <= right; i++)
  {
    if(arr[i] == key)
      return arr[i];
  }
  return -1;
}
void print(int arr[], int n)
{
  for(int i = 0; i < n; i++)
  {
    cout <<arr[i] <<" ";
  }
}
int binarysearch(int arr[], int left, int right, int key)
{
  if(left<=right)
  {
  int mid = left+(right-left)/2;
  if(arr[mid] == key)
    return arr[mid];
  else if(arr[mid]>key)
      return binarysearch(arr,left,mid-1,key);
  else
    return binarysearch(arr,mid+1,right,key);
  }
  return -1;
}
int main()
{
  int arr[]={0,25,38,44,12,22,17,34,53,66,89,72,67,20,14,30};
  int length = sizeof(arr)/sizeof(int);
  int key = 44;
  quicksort(arr,0,length-1);
  print(arr,length);
  cout << endl;
  if(jumpsearch(arr,length,key) == key)
  {
    cout <<"found";
  }
  else
  {
    cout <<"NotFound";
  }
  cout << endl;
    if(binarysearch(arr,0,length-1,key) == key)
  {
    cout <<"found";
  }
  else
  {
    cout <<"NotFound";
  }

  return 0;
}