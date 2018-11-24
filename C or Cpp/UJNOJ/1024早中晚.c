#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    if(x==1)
        printf("Good morning");
    else if(x==2)
        printf("Good afternoon");
    else if(x==3)
        printf("Good evening");
    else if(x==4)
        printf("Good night");
    else
    printf("Bye bye");

    return 0;
}
