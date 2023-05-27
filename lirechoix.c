#include "header.h"

int lirechoix(FILE* file){//lire le nombre de choix possible
    char line[100];
    int numLines = 0;
    int betweenChoicesAndEnd = 0;

    if (file == NULL) {//check si ya un probleme avec le fichier ou s'il n'existe pas.
        printf("Unable to open the file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (betweenChoicesAndEnd) {
            if (strstr(line, "END")) {
                break;
            }
            numLines++;
        } else if (strstr(line, "CHOICES:")) {
            betweenChoicesAndEnd = 1;
        }
    }
  return numLines-1;
}
