#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

/*
node *list = NULL;
node *n = malloc(sizeof(node));
*/
int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        //convert string to number: atoi (ascii to integer)
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        (*n).number = number;
        //新节点的next指针指向当前链表的头节点（为list）
        (*n).next = list;

        //更新头节点，指向新分配的节点n
        list = n;
    }


