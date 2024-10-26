#include <cs50.h>
#include <stdio.h>

/*
void meow(void){
    printf("meow\n");
}

int main(void){
    for (int i = 0; i<3; i++){
    meow();
    }
}
*/

int main(void)
{

    char c = get_char("do you agree?");

//string is "", the char type is ''

    if (c == 'y' || c== 'Y')
    {
        printf("agreed.\n");
    }
    else if(c=='n'|| c =='N')
    {
        printf("disagree.\n");
    }
}
