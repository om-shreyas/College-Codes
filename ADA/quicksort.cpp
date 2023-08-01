#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int sort_partition(int a[],int low,int high)
{
    int pivot = a[high];
    int i = low-1;
    for(int j = 0;j<high-1;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return(i+1);
}
void quick_sort(int a[],int low,int high)
{
    if(low<high)
    {
        int pivot = sort_partition(a,low,high);
        quick_sort(a, low, pivot-1);
        quick_sort(a, pivot+1, high-1);
    }
}
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr,0,N-1);
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}