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

    Append(word, &hw);
    out_s(hw);
    //AddPadding(&word, "0", 8);

    //int count = 0;//FindAllOccurrences(word, source);

    //printf("There are %d %s's", count, word);
    return 0;
}