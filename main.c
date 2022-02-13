#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <LCString.h>

#define out(x) printf("\n%s", x)
#define out_I(x) printf("\n%d", x)

int main(int argc, char* argv[])
{
    printf("%s\n", "Hello World!");
    
    LCstring x = "World!";
    LCstring y = "Hello ";
    LCstring hw = "Hello World!";

    Insert(x, 8, &hw);

    printf("\n%s", hw);

    return 0;
}