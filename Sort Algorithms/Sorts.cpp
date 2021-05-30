#include <iostream>
using namespace std;
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
void selection_sort(int arr[], int n)
{
  int i,j,min;
  for(int i = 0; i < n-1; i++)
  {
    min = i;
    for(int j = i+1; j < n; j++)
    {
      if(arr[j] < arr[min])
        min = j;
    }
    swap(&arr[min], &arr[i]);
  }
}

void insertion_sort(int arr[], int n)
{
  int key = 0, i = 0, j = 0;
  for(i = 1; i < n; i++)
  {
    key  = arr[i];
    j = i - 1;
    for (;j >= 0 && arr[j]>key;)
    {
      arr[j+1] = arr[j];
      j = j -1;
    }
    arr[j+1] = key;
  }
}

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if(left<n && (arr[left] > arr[largest]))
  {
    largest = left;
  }

  if(right<n && (arr[right] > arr[largest]))
  {
    largest = right;
  }

  if(largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heap_sort(int arr[], int n)
{
  //find the last node cha
  for(int i = n/2-1; i>=0; i--)
  {
    heapify(arr, n, i); // 
  }

  for(int i = n-1; i>0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

void bubble_sort(int arr[], int n)
{
  for(int i = 0; i < n; i ++)
  {
    for(int j = i + 1; j < n; j ++)
    {
      if(arr[j] < arr[i])
        swap(arr[j], arr[i]);
    }
  }
}
int partition(int arr[], int s, int e)
{
  int pivot = arr[e];
  int pIndex = s;
  for(int i = s; i < e; i ++)
  {
    if(arr[i]<=pivot)
    {
      swap(arr[i],arr[pIndex]);
      pIndex++;
    }
  }
  swap(arr[e],arr[pIndex]);
  return pIndex;
}
void quicksort(int arr[], int s, int e)
{
  if (s<e)
  {
    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
  }
}

void merge(int arr[], int l, int m, int r)
{
  int temp[r];
  int i = l, k = l, j = m+1;
  while(i<=m && j <= r)
  {
    if(arr[i]<arr[j])
    {
      temp[k]=arr[i];
      i++; k++;
    }
    else
    {
      temp[k]=arr[j];
      j++; k++;
    }
  }
  while(i<=m)
  {
    temp[k]=arr[i];
    i++; k++;
  }
  while(j<=r)
  {
    temp[k]=arr[j];
    k++; j++;
  }
  for(int p = l; p<=r; p++)
  {
    arr[p] = temp[p];
  }
}
void mergesort(int arr[], int l, int r)
{
  if(l<r)
  {
    int m = (r+l)/2;
    mergesort(arr,l,m-1);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}
void print(int arr[], int n)
{
  for(int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}
void shellsort(int arr[], int n)
{
  int gap, temp, i;
  for(gap = n/2; gap>0; gap/=2)
  {
    for(int j = gap; j<n; j++)
    {
      temp = arr[j];
      for(i=j; i>=gap && arr[i-gap]>temp; i-=gap)
      {
        arr[i]=arr[i-gap];
      }
      arr[i]= temp;
    }
  }
}
int main()
{
int a [5] = {14,12,55,26,7};
cout <<"array before: ";print(a,5);
selection_sort(a,5);
//insertion_sort(a,5);
//heap_sort(a,5);
//bubble_sort(a,5);
//quicksort(a,0,5-1);
// mergesort(a,0,5-1);
//shellsort(a,5);
cout << "array after: "; print(a,5);
return 0; 
}