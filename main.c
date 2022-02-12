#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <LCString.h>

int main(int argc, char* argv[])
{
    printf("%s\n", "Hello World!");
    
    string x = "World!";
    string y = "Hello ";
    string hw = "Hello World!";

    Insert(x, 8, &hw);

    printf("\n%s", hw);

    return 0;
}