#include "header.h"

void inventory(Chara *j) {
  Inventaire inventaire;
  Equipement equipement;
  FILE *fichier;
  char nom[NAME];

  fichier = fopen("inventory.bin", "rb");
  fread(&inventaire, sizeof(Inventaire), 1, fichier);
  fclose(fichier);
  printf("inventory\n");

  for (int i = 0; i != inventaire.taille; i++) {
    equipement = inventaire.equipements[i];
    printf("-%s:", equipement.nom);

    if (equipement.bonus_hp != 0) {
      printf(" +%d hp", equipement.bonus_hp);
    }

    if (equipement.bonus_magie.persuasion != 0) {
      printf(" +%d magie of persuasion", equipement.bonus_magie.persuasion);
    }

    if (equipement.bonus_magie.fire != 0) {
      printf(" +%d magie of fire", equipement.bonus_magie.fire);
    }

    if (equipement.bonus_magie.spells != 0) {
      printf(" +%d magie of spells", equipement.bonus_magie.spells);
    }

    if (equipement.bonus_physique.strength != 0) {
      printf(" +%d physical force", equipement.bonus_physique.strength);
    }

    if (equipement.bonus_physique.defense != 0) {
      printf(" +%d physical defense", equipement.bonus_physique.defense);
    }

    if (equipement.bonus_physique.agility != 0) {
      printf(" +%d agility", equipement.bonus_physique.agility);
    }

    if (equipement.bonus_karma != 0) {
      printf(" +%d karma", equipement.bonus_karma);
    }

    printf("\n");
  }

  int i;
  char c;

  do {
    printf("Choose your equipment : ");
    scanf("%s", nom);

    for (c = getchar(); c != '\n' && c != EOF; c = getchar())
      ;

    i = 0;

    do {
      equipement = inventaire.equipements[i];
      i++;
    } while (strcmp(nom, equipement.nom) != 0 && i != inventaire.taille);

    if (i == inventaire.taille) {
      printf("You don't have this equipment.\n");
    }
  } while (i == inventaire.taille);

  j->hp += equipement.bonus_hp;
  j->magie.fire += equipement.bonus_magie.fire;
  j->magie.persuasion += equipement.bonus_magie.persuasion;
  j->magie.spells += equipement.bonus_magie.spells;
  j->physique.strength += equipement.bonus_physique.strength;
  j->physique.defense += equipement.bonus_physique.defense;
  j->physique.agility += equipement.bonus_physique.agility;
  j->karma += equipement.bonus_karma;
}
