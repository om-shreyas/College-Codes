#include <stdio.h>
#include <stdlib.h>

int * create_array(int n)
{
    int * A;
    A = (int *)malloc(100*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Enter elemet %d: ",i);
        scanf("%d",&A[i]);
    }
    return A;
}

void traversal(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}

int * insertion(int A[], int N)
{
    for(int i=1;i<N;i++)
    {
        int key = A[i];
        int j = i-1;
        while(j>=0 && key<A[j])
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;

    }

    return A;
}

int * bubble(int A[], int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    return A;
}

int * selection(int A[], int N)
{
    for(int i=0;i<N;i++)
    {
        int s = i;
        for(int j=i;j<N;j++)
        {
            if(A[j]<A[s])
            {
                s = j;
            }
        }
        int temp = A[s];
        A[s] = A[i];
        A[i] = temp;
    }

    return A;
}

int main()
{
    int * A;
    int N;
    printf("Enter the number of elements: ");
    scanf("%d",&N);
    A = create_array(N);
    traversal(A,N);

    int c;
    printf("Enter the choice(0:Insertion, 1:Bubble, 2:Selection): ");
    scanf("%d",&c);
    switch(c)
    {
    case 0:
        A = insertion(A,N);
        traversal(A,N);
        break;
    case 1:
        A = bubble(A,N);
        traversal(A,N);
        break;
    case 2:
        A = selection(A,N);
        traversal(A,N);
        break;
    }

    return 0;
}
