#include "header.h"

int numbercheck(Chara c) { /*ca check si l'utilisateur a ecrit un chiffre dans son prenom*/
  for (int i = 0; i < strlen(c.name) && c.name[i] != '\0'; i++) {
    
    if (c.name[i] < 97 && c.name[i]> 90) {
      printf("Write it in letters goddamit\n");
      return 1;
    }
      
    else if (c.name[i] > 122 || c.name[i] < 65){
      printf("Write it in letters goddamit\n");
      return 2;
    }
  }
  return 0;
}


int capitalcheck(Chara o) { /*ca check si l'utilisateur a ecrit les majuscules dans les bons endroits*/
  for (int i = 1; i < strlen(o.name) && o.name[i] != '\0'; i++) {
    if (o.name[i] >= 65 && o.name[i] <= 90){
      return 1;
    }
  }
  if (o.name[0]<65 || o.name[0]>90){
    return 2;
  }
  return 0;
}


Chara correctcapital(Chara f){ /*ca corrige si l'utilisateur n'a pas ecrit les majuscules dans les bons endroits*/
  f.name[0]=toupper(f.name[0]);
  
  for (int i = 1; i < strlen(f.name) && f.name[i] != '\0'; i++){
    f.name[i]=tolower(f.name[i]);
  }
  
  return f;
}


Chara askname(Chara g){ //demander d'entrer le prénom du chara
  
  int d, v;
  int s;
  int choice;
	char input[NAME];
  
  do{
    printf("Welcome adventurer!! tell us the name of your hero : \n\nname : ");
    
    scanf("%s", g.name);
    
    d = numbercheck(g);
  } while (d!=0);
      
  s = capitalcheck(g);
  if (s!=0){
    do {
      printf("You didn't put the capital letters in their place. Do you want us to:\n");
      printf("(1) Change them\n");
      printf("(2) Keep the name\n");
      printf("Enter your choice: ");

    // pour empecher le joueur decrire des caracteres (pcq c tres drole)
      if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        // pour pas faire des loops infiniment
        scanf("%*[^\n]");
        scanf("%*c");
        choice = -1;
      }
    } while (choice < 1 || choice > 2);

      if (choice == 1) {
        // corriger les capital letters.
        g = correctcapital(g);
      }
  }

  return g;
}
