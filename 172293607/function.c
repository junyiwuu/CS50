#include <cs50.h>
#include <stdio.h>
/*
int main(void){
    printf("meow\n");
}
*/

/*
int main(void){
    int i=3;
    while(i>0){
        printf("meow\n");
        i--;
    }
}
*/


/*
int main(void){
    int i=0;
    while(i<=2){
        printf("woof\n");
        i++;
    }
}
*/

/*
int main(void){
    for(int i=0; i<=2; i++){
        printf("meow again\n");
    }
}
*/

/*
void meow(void)
{
    printf("meow\n");
}
int main(void)
{
    for (int i=0 ; i<=2 ;i++){
        meow();
    }
}
*/

//prototype
/*
void meow(void);

int main(void)
{
    for (int i=0 ;i<=2;i++){
        meow();
    }
}

void meow(void){
    printf("meow\n");
}
*/

void meow(int n);

int main(void){
    meow(3);
}

void meow(int n){
    for(int i=0;i<=n;i++){
        printf("meowiii\n");
    }
}
