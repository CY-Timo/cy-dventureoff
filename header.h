#ifndef HEADER_H
// tout les bibliotheques utilisees
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 50000
#define NAME 100
#define NAMEBG 10
#define MAX_EQUIPEMENT 100
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

// toutes les structures pour les stats
typedef struct {
  int persuasion;
  int fire;
  int spells;
} Magichara; // stats de magies, (en pointeur pour pouvoir les manipuler plus
             // facilement)

typedef struct {
  int strength;
  int defense;
  int agility;
} Phychara; // stats de physique, (en pointeur pour pouvoir les manipuler plus
            // facilement)

typedef struct {
  char name[NAME];
  int hp;
  Magichara magie;
  Phychara physique;
  int karma;
} Chara; // structure principale du personnage

typedef struct {
  int etape;
  Chara perso;
} Sauvegarde; // structure stocker dans le fichier sauvegarde.bin

typedef struct {
  char nameBG[NAMEBG];
  int hp;
  int strength;
  int defense;
  int ms;
  char dial[100];
} badguy; // structure stock les mechants de l'histoire

typedef struct {
  char nom[NAME];
  int bonus_hp;
  Magichara bonus_magie;
  Phychara bonus_physique;
  int bonus_karma;
} Equipement;

typedef struct {
  int taille;
  Equipement equipements[MAX_EQUIPEMENT];
} Inventaire;

// les fichiers a parcourir pour l'histoire.
int numbercheck(Chara c);
Chara askname(Chara g);
void charprint(Chara p);
void afficheMotLpL(char *mot);
Chara swortutor(Chara g);
Chara tutormagic(Chara g);
Chara statsass(Chara f);
void lire_fichier(FILE *file, const char *startHeader, const char *endHeader);
int lirechoix(FILE *file);
int leschoix(int hok);
FILE *readnextfile(int choix, FILE *file1, const char *startHeader, const char *endHeader, int curor);
badguy statsbg(const char *nomFichier);
Chara fight(Chara i, badguy p);
int lire_sauvegarde_etape();
Chara lire_sauvegarde_perso();
void ecrire_sauvegarde(int partie, Chara perso);
badguy statsBGfile(const char *nomFichier);
void inventory(Chara *j);
int checkCombatInFile(FILE *filename, const char *startHeader, const char *endHeader);
int menu();

#endif
