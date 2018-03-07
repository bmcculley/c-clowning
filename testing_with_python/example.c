#include <stdio.h>
#include "example.h"

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int num = add(3,2);

    printf("3 + 2 = %d\n", num);
    return 0;
}
