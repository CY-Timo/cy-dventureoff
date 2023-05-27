#include "header.h"

int main() {

  // tout les variables utiles
  // fichier
  FILE *file = NULL;
  FILE *tutorfile1 = NULL;
  FILE *postDoll = NULL;
  FILE *tutorfile = NULL;
  FILE *preBossBattle1 = NULL;
  FILE *bossBattle = NULL;
  FILE *postbossBattle = NULL;
  FILE *secondbossBattle = NULL;
  FILE *lastchapter = NULL;
  FILE *badEnding = NULL;
  FILE *goodEnding = NULL;
  FILE *goodEnding1 = NULL;

  // les integer en rapport avec les choix
  int numChoices;
  int choice1;

  // les personages
  Chara j;
  badguy p;
  badguy ks;
  badguy pHd;
  badguy mDo;

  p = statsBGfile("les_fichiers_texte/badguys/badguy1.txt");
  ks = statsBGfile("les_fichiers_texte/badguys/badguy3.txt");
  pHd = statsBGfile("les_fichiers_texte/badguys/badguy4.txt");
  mDo = statsBGfile("les_fichiers_texte/badguys/badguy2.txt");
  // associer des variables contenues dans les fichier  badguy a une structure
  // de méchant

  // autres variables

  int t;      // t pour lire la ligne de choix et attribuer un fichier
  int cursor; // pour initialiser la position du curseur dans les fichiers
  int etape;  // etape
  int c;      // check si ya un combat

  etape = menu();

  if (etape < 0) {
    printf("we are so sad you dont wanna play the game\n");
    exit(1234);
  }
  // ETAPE 1 DE LHISTOIRE

  if (etape == 0) {
    j = statsass(j); // initialiser des valeurs aléatoire pour le héro

    file = fopen("les_fichiers_texte/startstory.txt",
                 "r"); // aller dans le premier fichier de l'aventure FORMIDABLE
                       // qu'est CYd'ventureOFFICIEL-Hero's Quest
    if (file == NULL) {
      printf("Failed to open the file.\n");
      return 1;
    }
    j = askname(j);

    lire_fichier(file, "DESCRIPTION:\n", "COMMANDE:\n");

    // variable pour sauvergarder ou on est ftell
    cursor = ftell(file);

    // Code pour lire choix
    numChoices = lirechoix(file);

    // fseek pour se remettre dans la ligne quon veut
    t = leschoix(numChoices);

    fseek(file, cursor, SEEK_SET);
    tutorfile = readnextfile(t, file, "CHOICES:\n", "END", cursor);
    fclose(file);

    if (tutorfile == NULL) {
      printf("Failed to open the file.\n");
      return 1;
    }

    lire_fichier(tutorfile, "DESCRIPTION:\n", "COMMANDE:\n");

    cursor = ftell(tutorfile);
    numChoices = lirechoix(tutorfile);
    t = leschoix(numChoices);

    fseek(tutorfile, cursor, SEEK_SET);
    tutorfile1 = readnextfile(t, tutorfile, "CHOICES:\n", "END", cursor);
    if (tutorfile1 == NULL) {
      printf("Failed to open the fileeeeee.\n");
      return 1;
    }
    cursor = ftell(tutorfile1);
    // printf("%d\n", cursor);
    c = checkCombatInFile(tutorfile1, "COMMANDE:\n", "END\n");
    if (c == 1) {
      fight(j, p);
    }
    fseek(tutorfile1, cursor, SEEK_SET);
    lire_fichier(tutorfile1, "DESCRIPTION:\n", "COMMANDE:\n");

    cursor = ftell(tutorfile1);

    numChoices = lirechoix(tutorfile1);
    t = leschoix(numChoices);

    fclose(tutorfile);

    etape = 1; // on passe a la prochaine etape
    ecrire_sauvegarde(etape, j);
  }

  // ETAPE 2 DE LHISTOIRE

  if (etape == 1) {
    j = lire_sauvegarde_perso();

    do {
      fseek(tutorfile1, cursor, SEEK_SET);
      postDoll = readnextfile(t, tutorfile1, "CHOICES:\n", "END", cursor);

      if (postDoll == NULL) {
        printf("Failed to open the fimdlsaeeeeee.\n");
        return 1;
      }

      cursor = ftell(postDoll);
      c = checkCombatInFile(postDoll, "COMMANDE:\n", "END\n");
      if (c == 1) {
        fight(j, p);
      }
      fseek(postDoll, cursor, SEEK_SET);
      lire_fichier(postDoll, "DESCRIPTION:\n", "COMMANDE:\n");

      cursor = ftell(postDoll);

      numChoices = lirechoix(postDoll);
      t = leschoix(numChoices);

    } while (t == 2);

    fclose(tutorfile1);

    fseek(postDoll, cursor, SEEK_SET);

    preBossBattle1 = readnextfile(t, postDoll, "CHOICES:\n", "END", cursor);

    if (preBossBattle1 == NULL) {
      printf("Failed to open the fimdlsaeeeeee.\n");
      return 1;
    }

    cursor = ftell(preBossBattle1);
    c = checkCombatInFile(preBossBattle1, "COMMANDE:\n", "END\n");
    if (c == 1) {
      fight(j, p);
    }
    fseek(preBossBattle1, cursor, SEEK_SET);
    lire_fichier(preBossBattle1, "DESCRIPTION:\n", "COMMANDE:\n");

    cursor = ftell(preBossBattle1);

    numChoices = lirechoix(preBossBattle1);
    t = leschoix(numChoices);

    fclose(postDoll);
    etape = 2;
    ecrire_sauvegarde(etape, j);
  }

  // ETAPE 3 DE LHISTOIRE

  if (etape == 2) {
    j = lire_sauvegarde_perso();

    do {
      fseek(preBossBattle1, cursor, SEEK_SET);
      bossBattle = readnextfile(t, preBossBattle1, "CHOICES:\n", "END", cursor);

      printf("%d\n\n", cursor);

      if (bossBattle == NULL) {
        printf("Failed to open the file.\n");
        return 189;
      }

      cursor = ftell(bossBattle);

      c = checkCombatInFile(bossBattle, "COMMANDE:\n", "END\n");
      if (c == 1) {
        fight(j, ks);
      }

      fseek(bossBattle, cursor, SEEK_SET);

      lire_fichier(bossBattle, "DESCRIPTION:\n", "COMMANDE:\n");

      cursor = ftell(bossBattle);

      numChoices = lirechoix(bossBattle);
      t = leschoix(numChoices);

    } while (t == 3);

    fseek(bossBattle, cursor, SEEK_SET);

    postbossBattle = readnextfile(t, bossBattle, "CHOICES:\n", "END", cursor);

    if (postbossBattle == NULL) {
      printf("Failed to open the fimdlsaeee LOLLLLLies.\n");
      return 1;
    }

    cursor = ftell(postbossBattle);

    c = checkCombatInFile(postbossBattle, "COMMANDE:\n", "END\n");
    if (c == 1) {
      fight(j, ks);
    }

    fseek(postbossBattle, cursor, SEEK_SET);

    lire_fichier(postbossBattle, "DESCRIPTION:\n", "COMMANDE:\n");

    cursor = ftell(postbossBattle);

    numChoices = lirechoix(postbossBattle);
    t = leschoix(numChoices);

    etape = 3;
    ecrire_sauvegarde(etape, j);
  }

  // ETAPE 4 DE LHISTOIRE

  if (etape == 3) {
    j = lire_sauvegarde_perso();

    fseek(postbossBattle, cursor, SEEK_SET);

    secondbossBattle =
        readnextfile(t, postbossBattle, "CHOICES:\n", "END", cursor);

    if (secondbossBattle == NULL) {
      printf("Failed to open the fimdlsaeee LOLLLLLies.\n");
      return 1456;
    }

    cursor = ftell(secondbossBattle);

    c = checkCombatInFile(secondbossBattle, "COMMANDE:\n", "END\n");
    if (c == 1) {
      fight(j, mDo);
    }

    fseek(secondbossBattle, cursor, SEEK_SET);

    lire_fichier(secondbossBattle, "DESCRIPTION:\n", "COMMANDE:\n");

    cursor = ftell(secondbossBattle);

    numChoices = lirechoix(secondbossBattle);
    t = leschoix(numChoices);

    fclose(bossBattle);

    fseek(secondbossBattle, cursor, SEEK_SET);

    lastchapter =
        readnextfile(t, secondbossBattle, "CHOICES:\n", "END", cursor);

    if (lastchapter == NULL) {
      printf("Failed to open the fimdlsaeee LOLLLLLies.\n");
      return 187000;
    }

    cursor = ftell(lastchapter);

    c = checkCombatInFile(lastchapter, "COMMANDE:\n", "END\n");
    if (c == 1) {
      fight(j, mDo);
    }

    fseek(lastchapter, cursor, SEEK_SET);

    lire_fichier(lastchapter, "DESCRIPTION:\n", "COMMANDE:\n");

    cursor = ftell(lastchapter);

    numChoices = lirechoix(lastchapter);
    t = leschoix(numChoices);

    fclose(postbossBattle);
    fclose(secondbossBattle);
    etape = 4;
    ecrire_sauvegarde(etape, j);
  }

  // ETAPE FINALE

  if (etape == 4) {
    j = lire_sauvegarde_perso();
    fseek(lastchapter, cursor, SEEK_SET);

    if (j.karma < 20) {

      badEnding =   fopen("les_fichiers_texte/end/secondone.txt", "r");

      if (badEnding == NULL) {
        printf("yo problem with the file?\n");
        return 2;
      }

      cursor = ftell(badEnding);

      c = checkCombatInFile(badEnding, "COMMANDE:\n", "END\n");
      if (c == 1) {
        fight(j, pHd);
      }

      fseek(badEnding, cursor, SEEK_SET);

      lire_fichier(badEnding, "DESCRIPTION:\n", "COMMANDE:\n");

      numChoices = lirechoix(badEnding);

      if (numChoices == 0) {
        afficheMotLpL("Fin.\n");
        return (1009);
      }

      else {
        printf("uh this isn't supposed to happen\n");
        return (1007);
      }

    }

    else {
      goodEnding = fopen("les_fichiers_texte/end/firstending.txt", "r");

      if (goodEnding == NULL) {
        printf("yo problem with the file?\n");
        return 2;
      }

      cursor = ftell(goodEnding);

      fseek(goodEnding, cursor, SEEK_SET);

      lire_fichier(goodEnding, "DESCRIPTION:\n", "COMMANDE:\n");

      cursor = ftell(goodEnding);

      numChoices = lirechoix(goodEnding);
      t = leschoix(numChoices);

      fseek(goodEnding, cursor, SEEK_SET);

      goodEnding1 = readnextfile(t, goodEnding, "CHOICES:\n", "END", cursor);

      if (postbossBattle == NULL) {
        printf("Failed to open the fimdlsaeee LOLLLLLies.\n");
        return 1;
      }

      cursor = ftell(goodEnding1);

      c = checkCombatInFile(goodEnding1, "COMMANDE:\n", "END\n");
      if (c == 1) {
        fight(j, pHd);
      }

      fseek(goodEnding1, cursor, SEEK_SET);

      lire_fichier(goodEnding1, "DESCRIPTION:\n", "COMMANDE:\n");

      numChoices = lirechoix(goodEnding1);

      if (numChoices == 0) {
        afficheMotLpL("Fin.\n");
        return (10809);
      }

      else {
        printf("uh this isn't supposed to happen\n");
      }
    }

    etape = 0;
    ecrire_sauvegarde(etape, j);
  }
  fclose(badEnding);
  fclose(goodEnding);
  fclose(goodEnding1);
  fclose(preBossBattle1);
  return 0;
}