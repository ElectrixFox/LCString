#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <LCString.h>

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