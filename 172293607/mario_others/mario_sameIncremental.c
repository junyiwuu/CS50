#include <cs50.h>
#include <stdio.h>



/*
int main(void){
    int n = get_int("number of biggest bricks: ");
    while(n<1){
        n = get_int("require value bigger than 0: ");
    }

    for(int j=0; j<n ;j++)
    {
        for (int i=0; i<n; i++){
            printf("#");
        }
        printf("\n");
    }
}

*/




int main(void){
    int n ;
    do{
        n = get_int("number of biggest bricks: ");
    }
    while(n<1);

    for(int j=0; j<n ;j++)
    {
        for (int i=0; i<n; i++){
            printf("#");
        }
        printf("\n");
    }
}


