#include <stdio.h>

int foo(int i)
{
    i += 20;
    return i;
}

int main()
{
    int x = 10;
    int i = foo(x++);
    printf("x: %d\ni: %d", x, i);

    return 0;
}
