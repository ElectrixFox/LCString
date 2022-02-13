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
    LCstring source = "The time, the light, the end, there is no end.";

    LCstring word = "the";
    out_s(hw);

    int count = FindAllOccurrences(word, source);

    printf("There are %d %s's", count, word);
    return 0;
}