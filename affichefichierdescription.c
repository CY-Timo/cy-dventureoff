#include "header.h"

void lire_fichier(FILE* file, const char* startHeader, const char* endHeader){ //pour lire les fichiers .txt
    char liner[TAILLE];
    int print = 0;

    while (fgets(liner, TAILLE, file) != NULL) {
        if (strcmp(liner, startHeader) == 0) {
            print = 1;
            continue;
        }
        if (strcmp(liner, endHeader) == 0) {
            print = 0;
            break;
        }
        if (print) {
            afficheMotLpL(liner);
        }
    }
}

void afficheMotLpL(char* mot) { //pour afficher lettre par lettre
    int longueur = strlen(mot);
    
    for (int i = 0; i < longueur; i++) {
        printf("%c", mot[i]);
        //fflush(stdout);
        //usleep(1111);
    }
    
    printf("\n");
}