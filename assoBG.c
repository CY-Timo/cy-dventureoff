#include "header.h"


badguy statsBGfile(const char *nomFichier) {//procédure qui va récuperer les stats d'un méchant ( badguyX.txt) et les associer a une structure badguy
    badguy p;
    FILE *fichier = fopen(nomFichier, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    fscanf(fichier, "%[^\n] %d %d %d %d %[^\n]", p.nameBG, &p.hp, &p.strength, &p.defense, &p.ms, p.dial);

    fclose(fichier);
    return p;
}