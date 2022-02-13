#pragma once
#include <LCString.h>

void Preappend(LCstring destination, LCstring* source)
{
    {
        // New temp string to store the origional source safely during allocation.
        LCstring temp = *source;
        *source = malloc(sizeof(LCstring) * 128);

        // Coppies the origional source into the new allocted source.
        strcpy(*source, temp);
    }

    // A separate variable just for derefferenced source so that I don't have to dereff it every time.
    LCstring n_source = *source;
    
    // String to preappend
    const LCstring n_str = destination;
    
    // Move the origional string that many moves to the right so something can be moved before it.
    int str_len = strlen(n_str);

    // Add one because for some reason it stops corruption.
    memmove(n_source + str_len, n_source, strlen(n_source) + 1);

    // Coppies the new string into the begining of the old one.
    memcpy(n_source, n_str, str_len);
}

void Replace(LCstring X, LCstring* source, LCstring Y) 
{
    {
        // Creates a new temp variable to that source can be allocated memory.
        LCstring temp = *source;
        *source = malloc(sizeof(char*) * 128);

        // Coppies temp into the new allocated source.
        strcpy(*source, temp);

        // Clears temp as it is no longer needed.
        free(temp);
    }

    // Allocates a new variable for using
    LCstring t_str = malloc(sizeof(char*) * 128);

    // Coppies source into it so that t_str can act like source.
    strcpy(t_str, *source);

    int x_len = strlen(X);

    // Find the location of X in source
    int location = Find(X, t_str);

    // Coppies Y into source from location onwards for x length
    memcpy(&t_str[location], Y, x_len);

    // Sets source to t_str.
    *source = t_str;
}

LCstring SubString(int x, LCstring source, int y) 
{
    int n_len = y - x;
    LCstring Substr = malloc(sizeof(LCstring) * n_len);

    // Coppies from x in source to the length of the substring determined by y - x 
    memcpy(Substr, &source[x], y-x);

    // Null terminator to stop corruption
    Substr[y-x] = '\0';

    return Substr;
}

int Find(LCstring word, LCstring source) 
{
    int Length = strlen(word);

    int index = 0;
    // Through the length of the source checking
    for (int i = 0; i < strlen(source); i++)
    {
        // Compares a substring from i to the words length in source to the actual word.
        if(!strcmp(SubString(i, source, i+Length), word))
        {
            index = i;
            break;
        }
    }

    return index;
}

int Find_n(LCstring word, LCstring source, int n) 
{
    int Length = strlen(word);
    int index = 0;

    for (int i = n; i < strlen(source); i++)
    {
        if(!strcmp(SubString(i, source, i+Length), word))
        {
            index = i;
            break;
        }
    }

    return index;
}

int FindAllOccurrences(LCstring word, LCstring source)
{
    int count = 0;

    int len = Length(source);
    int w_len = Length(word);

    out_v(len);

    int index = 0;

    for (int i = 0; i < len; i++)
    {
        if(Find_n(word, source, index))
        {
            out_v(Find_n(word, source, index));
            index = Find_n(word, source, index);
            out_s(source[index]);

            count++;
            index += w_len;

        }
    }
    
    

    return count;
}

void Remove(LCstring* source, int min, int max) 
{
    int n_len = max - min;

    // Litterally just a little thing that I've found to work for fixing strings.
    {
        // New temp string to store the origional source safely during allocation.
        LCstring temp = *source;
        *source = malloc(sizeof(LCstring) * 128);

        // Coppies the origional source into the new allocted source.
        strcpy(*source, temp);
    }

    LCstring n_source = *source;
    
    // This starts the source at min and then inserts maximum for the length of the source - the length add one
    // Even this kind of confuses me
    memmove(&n_source[min], &n_source[max], strlen(n_source) - n_len + 1);
}

LCstring Left(LCstring source, int index) 
{
    return SubString(0, source, index);
}

LCstring Right(LCstring source, int index) 
{
    return SubString(index, source, strlen(source));
}

void Insert(LCstring word, int index, LCstring* source) 
{
    LCstring temp = *source;
    *source = malloc(sizeof(LCstring) * 128);
    strcpy(*source, temp);
}

extern inline void Lower(LCstring string) 
{
    strlwr(string);
}

extern inline void Upper(LCstring string) 
{
    strupr(string);
}

extern inline int Length(LCstring string) 
{
    return strlen(string);
}

void Replace_Range(LCstring source, int min, int max, char p) 
{
    for (int i = min; i < max; i++)
        source[i] = p;
}

void SetSpecial(LCstring source, LCstring destination) 
{
    LCstring n_source = source;
    source = malloc(sizeof(char*) * Length(destination));
    strcpy(source, destination);
}

void Issolated(char* word)
{
        char* test_W = "Hellow people";
        char* temp = test_W;
        test_W = malloc(sizeof(char*) * 128);
        strcpy(test_W, temp);

        out_s(test_W);

        memmove(test_W + strlen(word), test_W, strlen(test_W));
        out_s(test_W);
}

void AddPadding(LCstring* source, char* character, int thickness) 
{
    LCstring temp = *source;
    *source = malloc(sizeof(char*) * 128 * thickness);
    strcpy(*source, temp);

    out_s(*source);

    LCstring n_word = *source;

    LCstring s_str = character;

    out_s(n_word);

    memmove(n_word + 2, n_word, strlen(n_word) + 1);

    //memmove(n_word + thickness, n_word, strlen(n_word) + 1);
    out(n_word);
}