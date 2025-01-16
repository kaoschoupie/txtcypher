#include "Cypher.h"
#include "Decypher.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *toread = fopen("./tocypher.txt", "r");
    FILE *towrite = fopen("cyphered.txt", "w");
    char line[256];
    while (fgets(line, sizeof(line), toread))
    {
        char *str = cypher(line, sizeof(line), 1);
        fprintf(towrite, str);
        free(str);
    }
    fclose(toread);
    fclose(towrite);
    toread = fopen("cyphered.txt", "r");
    towrite = fopen("decyphered.txt", "w");
    while (fgets(line, sizeof(line), toread))
    {
        char *str = decypher(line, sizeof(line), 1);
        fprintf(towrite, str);
        free(str);
    }
    fclose(toread);
    fclose(towrite);
}