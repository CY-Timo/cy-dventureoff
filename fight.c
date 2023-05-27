#include "header.h"


Chara fight(Chara i, badguy p) {
  char choiceAT;    
	printf("OH NO, a %s is in front of you, you must go through it yet...\n\n", p.nameBG);
	fflush(stdout);
    usleep(11111);
	//inventory("les_fichiers_texte/chara/inventory.txt", i);
	printf("Here are your stats for this fight:\n");
	charprint(i);
    while (i.hp > 0 && p.hp > 0) {
			
        int degatsi;
        int degatsbg;
			  printf("\n_ _ ' ' * * S-T-A-T-S * * ' ' _ _ \n");
				printf("Here are the stats of %s,\nhp: %d,\nattack: %d,\ndefense: %d.\n\nWhat do you want to do next?\n\nType:\n[1] to attack\n\n[2] to cast a spell\n\n[3] to negotiate:\n\n", p.nameBG, p.hp, p.strength, p.defense);
        scanf("%1s", &choiceAT);
			while (choiceAT != '1' && choiceAT != '2' && choiceAT != '3') {//demande l'attaque que le joueur veut utiliser
            printf("Type 1, 2, or 3, idiot.\n");
            scanf("%s", &choiceAT);
				    while(getchar() != '\n');
				}
        
        if (choiceAT == '1') {
            printf("Close combat\n");
            degatsi = i.physique.strength - p.defense;
            
            if (degatsi > 0) {
                p.hp -= degatsi;
                printf("You deal %d damages to %s.\n", degatsi, p.nameBG);
            } else {
                printf("You don't inflict any damage to it.\n");
            }
            
            if (p.hp <= 0) {
                printf("You have defeated %s!\n", p.nameBG);
								charprint(i);
                break;
            }
        } else if (choiceAT == '2') {
            printf("Magical damages, let's burn his butt!\n");
            degatsi = i.physique.strength - p.defense;
            
            if (degatsi > 0) {
                p.hp -= degatsi;
							  p.ms -= degatsi;
                printf("You deal %d damage to it.\n", degatsi);
            } else {
                printf("You don't inflict any damage to it.\n");
            }
            
            if (p.hp <= 0) {
                printf("You have defeated %s!\n", p.nameBG);
								charprint(i);
                break;
            }
        } else if (choiceAT == '3') {
					 
            printf("Negotiation\n");
            if (i.magie.persuasion >= p.ms) {
                printf("Congratulations! You have successfully persuaded it, it lets you pass without any obstacles.\n");
							 	printf("%s\n", p.dial);
								charprint(i);
                i.karma = i.karma + 5;
                return i;
            } else {
                printf("Darn, it doesn't seem to want to negotiate. You must fight.\n");
                //break;
            }
        } else {
            printf("OOOOOOO \n");
        }
        //l'ennemi t'attaque
        degatsbg = p.strength - i.physique.defense;
        
        if (degatsbg > 0) {
            i.hp -= degatsbg;
            printf("%s deals %d damage to you.\n", p.nameBG, degatsbg);
        } else {
            printf("The enemy doesn't deal any damage to you, you are too strong.\n");
        }
        
        if (i.hp <= 0) {
            printf("You have been defeated!\n");
						exit(69);
        }
    }
    
    return i;
}

int checkCombatInFile(FILE* filename, const char* startHeader, const char* endHeader) {
    if (filename == NULL) {
        printf("Failed to open the file.\n");
        return -1;
    }

    char line[TAILLE];
    int isInCombat = 0;

    while (fgets(line, TAILLE, filename) != NULL) {
        if (strcmp(line, startHeader) == 0) {
            break;
        }
    }

    while (fgets(line, TAILLE, filename) != NULL) {
        if (strcmp(line, endHeader) == 0) {
            break;
        }
        if (strstr(line, "COMBAT!!!") != NULL) {
            isInCombat = 1;
            break;
        }
    }
    return isInCombat;
}