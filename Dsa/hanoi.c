#include <stdio.h>
struct rod
{
    int discs;
    char name;
};

int source,aux,destination;

void hanoi(int n, struct rod source, struct rod aux, struct rod destination)
{
    if(n==1)
    {
        source.discs--;
        destination.discs++;
        printf("From %c to %c \n",source.name,destination.name);
    }
    else
    {
        hanoi(n-1,source,destination,aux);
        source.discs--;
        destination.discs++;
        printf("From %c to %c \n",source.name,destination.name);
        hanoi(n-1,aux,source,destination);
    }
}

int main()
{
    struct rod source,destination,aux;
    source.name='A';
    aux.name='B';
    destination.name='C';

    source.discs=4;
    aux.discs=0;
    destination.discs=0;

    hanoi(4,source,aux,destination);

    return(0);
}
