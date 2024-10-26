#include <cs50.h>
#include <stdio.h>
#include <string.h>

//search numbers

int main(void)
{
    int numbers[] = {20,500,10,5 ,100, 1, 50};

    int n = get_int("numbers: ");
    for(int i = 0; i < 7; i++)
    {
        if(numbers[i] == n)
        {
            printf("found\n");
            return 0; //0 shows this program end here success
            //make you exit out
        }

    }
    printf("not found\n");
    return 1;
}


//--------------------------


//search strings
int main(void)
{
    string strings[] = {"battleship" , "boot" , "cannon" , "iron", "thimble" , "top hat" };
    string s = get_string("string: ");
    for(int i = 0; i< 6; i++ )
    {
        if(strcmp(strings[i] , s ) == 0)
        {
            printf("found\n");
            return 0;
        }
    }
    printf("not found\n");
    return 0;

}




//----------------------------

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    //the new datatype is person, and the array name is people
    person people[3];
    //name and number is the attrinutes
    people[0].name = "carter";
    people[0].number = "1-248-877394";

    people[1].name = "david";
    people[1].number = "71-239-72342";

    people[2].name = "john";
    people[2].number = "1242837-21387";

    string name = get_string("name: ");
    for ( int i = 0 ; i <3; i++)
    {
        if(strcmp(people[i].name , name )==0)
        {
            printf("found: %s\n", people[i].number);
            return 0;
        }
    }
    printf("not found\n");
    return 1;

}
*/

//recursive

void draw(int n);


int main(void)
{
    int height = get_int("height: ");
    draw(height);
}


void draw(int n)
{
    if(n<=0)
    {
        return;
    }
    //inside loop loop
    draw(n-1);

    for(int i=0 ;i<n ; i++)
    {
        printf("#");
    }
    printf("\n");
}
