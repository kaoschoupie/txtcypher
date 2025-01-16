#include <stdio.h>
#include <stdlib.h>
#include "Decypher.h"
char *decypher(char *str, int size, int key)
{
    char *output = (char *)malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size - 1; i++)
    {
        if (str[i] == '\n')
        {
            output[i] = '\n';
            break;
        }
        char value = str[i] - key - i % 3;

        output[i] = value;
    }
    return output;
}