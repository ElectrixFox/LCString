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
    LCstring source = "According to all known laws of aviation, there is no way that a bee should be able to fly. \
    Its wings are too small to get its fat little body off the ground.\
    The bee, of course, flies anyway because bees don't care what humans think is impossible.";

    LCstring word = "be";

    AddPadding(&word, "0", 8);

    if(1 == 2)
    {
        char* test_W = "Hellow people";
        char* temp = test_W;
        test_W = malloc(sizeof(char*) * 128);
        strcpy(test_W, temp);

        out_s(test_W);

        memmove(test_W + strlen(word), test_W, strlen(test_W));
        out_s(test_W);
    }

    int count = 0;//FindAllOccurrences(word, source);

    printf("There are %d %s's", count, word);
    return 0;
}