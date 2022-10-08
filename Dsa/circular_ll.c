#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    int value;
    struct linked_list * next;
};
typedef struct linked_list node;

node * head = NULL;

void insert(int v, int p)
{
    node * current = head;
    node * new = (node *)malloc(sizeof(node));
    

}