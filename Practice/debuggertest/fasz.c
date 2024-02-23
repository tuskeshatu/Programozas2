#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("I'm C! Normal C!!");

    int *fasz = malloc(sizeof(int));

    free(fasz);
    
    return 0;
}
