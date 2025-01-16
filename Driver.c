#include "Cypher.h"
#include "Decypher.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("%d", CHAR_MIN);
    printf("\n");
    printf("%d", CHAR_MAX);
    printf("\n");
    FILE *toread = fopen("./tocypher.txt", "r");
    FILE *towrite = fopen("cyphered.txt", "w");
    char line[50];
    fgets(line, sizeof(line), toread);
    printf(line);
    char *str = cypher(line, sizeof(line), 1);
    printf("%s", str);
    printf("\n\n\n\n");
    fprintf(towrite, "%s", str);
    fprintf(towrite, "%c", '\n');
    free(str);
    /*while (fgets(line, sizeof(line), toread))
    {
        char *str = cypher(line, 21);
        fprintf(towrite, str);
        fprintf(towrite, "\n");
    }*/
    fclose(toread);
    fclose(towrite);
    toread = fopen("cyphered.txt", "r");
    towrite = fopen("decyphered.txt", "w");
    fgets(line, sizeof(line), toread);
    printf("%s", line);
    char *str2 = decypher(line, sizeof(line), 1);
    printf("%s", str2);
    fprintf(towrite, "%s", str2);
    fprintf(towrite, "%c", '\n');
    free(str2);
    fclose(toread);
    fclose(towrite);
}