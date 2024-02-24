#include <stdio.h>

void fasz(int& a)
{
    a += 3;

    return;
}

int main(int argc, char const *argv[])
{

    int a = 2;

    fasz(a);
    

    return 0;
}
