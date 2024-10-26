#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    //if failed to malloc the sufficient memory, will return null
    int *list = malloc (3 * sizeof(int));
    if(list == NULL)
    {
        return 1;
    }

    list[0]=1;
    list[1]=2;
    list[2]=3;

    int *tmp = malloc (4 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    free(list);
    tmp[3]=4;
    list = tmp;

    for(int i = 0; i<4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
}
