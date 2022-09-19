#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text;
    int letters, words, sentences, index;
    double L, S;

    text = get_string("Text:");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

    L = letters/(float)words * 100;
    S = sentences/(float)words * 100;

    index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 16)
        printf("Grade 16+\n");
    else if (index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %i\n", index);
}

int count_letters(string text)
{
    int length, counter = 0;

    length = strlen(text);

    for (int i = 0; i< length; i++)
    {
        if (isalpha(text[i]) != 0)
            counter ++;
    }
    //printf("%i letters\n", counter);
    return counter;
}

int count_words(string text)
{
    int length, counter = 0;

    length = strlen(text);

    for (int i = 0; i< length; i++)
    {
        if (text[i] == ' ')
            counter ++;
    }
    counter ++;

    //printf("%i words\n", counter);
    return counter;
}

int count_sentences(string text)
{
    int length, counter = 0;

    length = strlen(text);

    for (int i = 0; i< length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            counter ++;
    }

    //printf("%i sentences\n", counter);
    return counter;
}
