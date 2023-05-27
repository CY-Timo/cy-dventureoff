#include "header.h"

Chara statsass(Chara f){ //procédure association des valeurs aux différentes stats du chara.
  srand(time(NULL));
  f.hp = rand() % 51 + 50;
	f.karma = 10;
  f.physique.strength = rand() % 51 + 50;
	int r = f.physique.strength;
	if ( f.physique.strength >= 60){
    f.physique.defense = rand() % 51 + 40 + (r / 10);
    f.physique.agility = rand() % 51 + 40 - (r / 10);
	}
	else {
    f.physique.defense = rand() % 51 + 40 - (r / 10);
    f.physique.agility = rand() % 51 + 40 + (r / 10);
	}
	f.magie.spells = rand() % 51 + 50;
	f.magie.fire = rand() % 51 + 50;
	f.magie.persuasion = rand() % 51 + 55;
  return f;
}

void charprint(Chara p){ //procédure pour afficher le stats du chara.
    printf("\n_ _ ' ' * * S-T-A-T-S * * ' ' _ _ \n");
  usleep(1111);//permet d'attendre entre les stats
    printf("Character name : ~%s~ \n", p.name);
  usleep(1111);
    printf("hit points : [%d]\n\n", p.hp);
  usleep(1111);
    printf("Magic stats :\nSpells : [%d] Fire : [%d] Persuasion : [%d]\n\n", p.magie.spells, p.magie.fire, p.magie.persuasion);
  usleep(1111);
    printf("Physical stats : \nStrength : [%d] Defense : [%d] Agility : [%d]\n\n", p.physique.strength, p.physique.defense, p.physique.agility);
  usleep(1111);
}