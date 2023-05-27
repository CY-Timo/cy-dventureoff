#include "header.h"

int leschoix(int hok){
  int choice1;
    do {
    if (scanf("%d", &choice1) != 1) {
      printf("Invalid input. Please enter a number.\n");
      scanf("%*[^\n]"); //lire chaque caractere sauf le retour en arriere
      scanf("%*c"); //lire un caractere dans le scanf du personnage
      choice1 = -1;
    }
    else if (choice1 < 1 || choice1 > (hok)) {
      printf("Invalid input. Please enter a number.\n");
      scanf("%*[^\n]"); //lire chaque caractere sauf le retour en arriere
      scanf("%*c"); //lire un caractere dans le scanf du personnage
      choice1 = -1;
    }
  }while (choice1 < 1 || choice1 > (hok));
  //system("clear");
  return choice1;
}

FILE* readnextfile(int choix, FILE* file1, const char* startHeader, const char* endHeader, int curor) {
    if (file1 == NULL) {
        printf("Error: Unable to open the file.\n");
        return NULL;
    }

    char line[NAME];
    int currentLine = 1;
    int print = 0;
    char* desiredLine = NULL;

    while (fgets(line, NAME, file1) != NULL) {
        //printf("%d/%s\n", currentLine, line);

        if (currentLine == (choix + 3)) {
            printf("Matched choice: %s", line);
            print = 1;
            desiredLine = malloc(strlen(line));
            strncpy(desiredLine, line, strlen(line) - 1);  // Copy the line without the last character
            desiredLine[strlen(line) - 1] = '\0';
            break;
        }

        currentLine++;
    }

    if (print) {
        fseek(file1, curor, SEEK_SET);
        // Read lines until endHeader is found
        if (fgets(line, NAME, file1) != NULL) {
            if (print) {
                printf("the desired line is %s\n", desiredLine);
                // Open and return the next file
                FILE* nextFile = fopen(desiredLine, "r");
                if (nextFile == NULL) {
                    printf("Error: Unable to open the file '%s'.\n", desiredLine);
                } 
                else {
                    //lire_fichier(nextFile, "DESCRIPTION:", "ASCII:");
                    return nextFile;
                }
            }
        }
    }
    free(desiredLine);  // Free the allocated memory for desiredLine
    return NULL;
}