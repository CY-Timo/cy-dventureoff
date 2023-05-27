#include "header.h"

int lire_sauvegarde_etape() {
  Sauvegarde info;
  FILE *fichier;
  info.etape=0;
  fichier = fopen("les_fichiers_texte/sauvegarde.bin", "rb");

  fread(&info, sizeof(info), 1, fichier);
  fclose(fichier);

  return info.etape;
}

Chara lire_sauvegarde_perso() {
  Sauvegarde info;
  FILE *fichier;

  fichier = fopen("les_fichiers_texte/sauvegarde.bin", "rb");

  fread(&info, sizeof(info), 1, fichier);
  fclose(fichier);

  return info.perso;
}

void ecrire_sauvegarde(int etape, Chara perso) {
  Sauvegarde info;
  FILE *fichier;

  info.etape = etape;
  info.perso = perso;

  fichier = fopen("les_fichiers_texte/sauvegarde.bin", "wb");

  fwrite(&info, sizeof(info), 1, fichier);
  fclose(fichier);
}

  /*
  si il continue:
  j = lire_sauvegarde_perso();
  */