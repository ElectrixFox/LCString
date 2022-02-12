#pragma once
#include <LCString.h>

void Preappend(string destination, string* source)
{
    {
        // New temp string to store the origional source safely during allocation.
        string temp = *source;
        *source = malloc(sizeof(string) * 128);

        // Coppies the origional source into the new allocted source.
        strcpy(*source, temp);
    }

    // A separate variable just for derefferenced source so that I don't have to dereff it every time.
    string n_source = *source;
    
    // String to preappend
    const string n_str = destination;
    
    // Move the origional string that many moves to the right so something can be moved before it.
    int str_len = strlen(n_str);

    // Add one because for some reason it stops corruption.
    memmove(n_source + str_len, n_source, strlen(n_source) + 1);

    // Coppies the new string into the begining of the old one.
    memcpy(n_source, n_str, str_len);
}

void Replace(string X, string source, string Y) 
{
    int x_len = strlen(X);

    // Find the location of X in source
    int location = Find(X, source);

    // Coppies Y into source from location onwards for x length
    memcpy(&source[location], Y, x_len);
}

string SubString(int x, string source, int y) 
{
    int n_len = y - x;
    string Substr = malloc(sizeof(string) * n_len);

    // Coppies from x in source to the length of the substring determined by y - x 
    memcpy(Substr, &source[x], y-x);

    // Null terminator to stop corruption
    Substr[y-x] = '\0';

    return Substr;
}

int Find(string word, string source) 
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

int Find_n(string word, string source, int n) 
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

void Remove(string* source, int min, int max) 
{
    int n_len = max - min;

    // Litterally just a little thing that I've found to work for fixing strings.
    {
        // New temp string to store the origional source safely during allocation.
        string temp = *source;
        *source = malloc(sizeof(string) * 128);

        // Coppies the origional source into the new allocted source.
        strcpy(*source, temp);
    }

    string n_source = *source;
    
    // This starts the source at min and then inserts maximum for the length of the source - the length add one
    // Even this kind of confuses me
    memmove(&n_source[min], &n_source[max], strlen(n_source) - n_len + 1);
}

string Left(string source, int index) 
{
    return SubString(0, source, index);
}

string Right(string source, int index) 
{
    return SubString(index, source, strlen(source));
}

void Insert(string word, int index, string* source) 
{
    string temp = *source;
    *source = malloc(sizeof(string) * 128);
    strcpy(*source, temp);
}