void hash(int a);

int main(void){
    int n = get_int("number of biggest bricks: ");

    for(int j=0; j<n ;j++)
    {
        hash(j);
        printf("\n");
    }
}

void hash(int a)
{
    for(int i=0; i<=a; i++)
    {
        printf("#");
    }
}
