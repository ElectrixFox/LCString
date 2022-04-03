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
    LCstring source = "The time, the light, the end, there is no end. The";

    LCstring word = "The";
    out_s(hw);

    char* all = SubString(0, source, 5);
    printf("All: %s\n", all);

    //Remove(&source, 2, 5);

    Replace("light", &source, "ti");
    //AppendAt(&source, 20, "helll");
    printf("Source: %s", source);


    //int count = FindAllOccurrences(word, source);

    //printf("There are %d %s's", count, word);
    return 0;
}