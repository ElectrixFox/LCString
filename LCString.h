#ifndef LCSTRING_H
#define LCSTRING_H

#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LCstring char*

#ifndef LCSTRING_HEADERONLY

#define out(str) printf("%s\n", str)
#define out_v(x) printf("%s: %d\n", #x, x)
#define out_s(x) printf("%s: %s\n", #x, x)
#define out_c(x) printf("%s: %c\n", #x, x)

// Just an append function. It appends str onto source.
void Append(LCstring str, LCstring* source);

// Preappend destination into source.
void Preappend(LCstring destination, LCstring* source);

// Replaces X in source with Y 
// NOTE: Only works with allocated (malloc) variables at the moment.
void Replace(LCstring X, LCstring* source, LCstring Y);

// Returns a substring from x to y in source 
LCstring SubString(int x, LCstring source, int y);

// Returns the first index of the word in source
int Find(LCstring word, LCstring source);

// Exactly the same as normal find but starting at index n
int Find_n(LCstring word, LCstring source, int n);

// Returns how many of word are in source. 
// NOTE: Could rename function to FindAll or How_Many
int FindAllOccurrences(LCstring word, LCstring source);

// Removes all characters from min to max
void Remove(LCstring* source, int min, int max);

// Gets all of the characters to the left of index
LCstring Left(LCstring source, int index);

// Gets all of the characters to the right of index
LCstring Right(LCstring source, int index);

// Inserts word at index in source
void Insert(LCstring word, int index, LCstring* source);

// Changes string to lowercase.
extern inline void Lower(LCstring string);

// Changes string to uppercase.
extern inline void Upper(LCstring string);

// Returns the strings length.
extern inline int Length(LCstring string);

// Replaces characters in range min to max within string source with character p.
void Replace_Range(LCstring source, int min, int max, char p);

// Sets the specified string(source) to another string(destination).
void SetSpecial(LCstring source, LCstring destination);

// Adds padding of thickness amount of character arround word
void AddPadding(LCstring* source, char* character, int thickness);


#else

// Preappend destination into source.
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

// Replaces X in source with Y
void Replace(string X, string source, string Y) 
{
    int x_len = strlen(X);

    // Find the location of X in source
    int location = Find(X, source);

    // Coppies Y into source from location onwards for x length
    memcpy(&source[location], Y, x_len);
}

// Returns a substring from x to y in source 
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

// Returns the first index of the word in source
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

// Exactly the same as normal find but starting at index n
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

#endif

#endif