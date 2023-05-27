#include "header.h"
// lire le fichier txt puis lire les choix et on fait des if pour chaque choix.
// Dependant du choix on return l'etape.
int menu() {
  FILE *menu = NULL;
  int choix;
  int cursor;
  int on_a_plus_de_nMoinsUn_sauvez_nous, t;

  menu = fopen("les_fichiers_texte/menu.txt", "r");

  if (menu == NULL) {
    printf("UNABLE TO OPEN BRUH!\n");
    exit(122);
  }

  lire_fichier(menu, "DESCRIPTION:\n", "COMMANDE:\n");

  fclose(menu);

  choix = leschoix(3);

  if (choix == 1) {
    return 0;
  } else if (choix == 2) {
    return lire_sauvegarde_etape();
  }

  return -1;
}
