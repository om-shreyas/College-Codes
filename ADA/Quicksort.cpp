#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int sort(int a[],int low,int high)
{
    int pivot = a[high];
    int i = -1;
    for(int j = 0;j<=high-1;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
void quick_sort(int a[],int low,int high)
{
    if(low<=high)
    {
        int pivot = sort(a,low,high);
        quick_sort(a, low, pivot-1);
        quick_sort(a, pivot+1, high);
    }
}
int main()
{
    int a[] = {1,4,9,2,5,8,3,6,7};
    int N = sizeof(a)/sizeof(int);
    for(int i = 0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    quick_sort(a,0,N-1);
    for(int i = 0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
}