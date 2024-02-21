#include <stdio.h>

int main(int argc, char const *argv[])
{

    int b = 10;

    int &a = b;

    printf("%d", a);

    

    return 0;
}
