/* main.c */

/*
test de liste, piles et files 
 */



#include <stdio.h>
#include "debug.h"
#include "util.h" 
#include "contenu.h"
#include "liste.h"
#include <time.h>
#include <stdlib.h>



void test_pile() {    
    char rep[8];

    contenu *pc;
    pile *pp;
    pp=cree_pile();
    
    for(;;) {
        printf("\n\
1. Consultation du (S)ommet\n\
2. (E)mpiler\n\
3. (D)epiler\n\
\n\
0. (F)inir\n\
Choix : ");
        saisie_chaine(rep,2);
        switch(rep[0]) {
            case 'E' : case 'e' : case '2' :
                ajoute_pile(pp, cree_alea_contenu());

                printf("%-20s : ", "Ajout");
                affiche_contenu(sommet_pile(pp));
                printf("\n");

                printf("%-10s : \n", "Pile :");
                affiche_pile(pp, (void (*) (void *))affiche_contenu);
                printf("\n");

                break;

            case 'D' : case 'd' : case '3' :
                pc =  (contenu *)retire_pile(pp);

                printf("%-20s : ","Retrait" );
                if (pc) {
                    affiche_contenu(pc);
                    printf("\n");
                    libere_contenu(pc);
                }
                else {
                    printf(" Impossible"); printf("\n");
                }

                printf("%-10s : \n", "Pile :");
                affiche_pile(pp,(void (*) (void *))affiche_contenu);
                printf("\n");

                break;

            case 'S' : case 's' : case '1' :
                pc =(contenu *)sommet_pile(pp);

                printf("%-20s : ","Sommet pile");
                if (pc) {
                    affiche_contenu(pc);
                }
                else {
                    printf("Impossible");
                }
                printf("\n");

                break;

            case 'F' : case 'f' : case '0' :

                libere_pile(pp,(void(*)(void *))libere_contenu);
                printf("Fin de test pile \n");
                return ;
        }
    }
}


void test_liste() {
    char rep[8];
    int (*comp)(contenu *, contenu *); /* ptr sur fonction de comparaison */

    contenu *pc;
    liste *pl;

    pl=cree_liste();

    for(;;) {
        printf("\n\
1. (T)ete de liste\n\
2. (A)jout en tete\n\
3. (R)etirer tete\n\
4. (I)nserer dans l'ordre des noms\n\
5. Tri par (N)om\n\
6. Tri par (V)aleur\n\
\n\
0. (F)inir\n\
Choix : ");
        saisie_chaine(rep,2);
        switch(rep[0]) {
            case 'A' : case 'a' : case '2' :
                ajoute_en_tete_liste(pl,cree_alea_contenu());

                printf("%-20s : ","Ajout en tete : ");
                affiche_contenu(tete_de_liste(pl));
                printf("\n");

                printf("%-10s : \n", "Liste");
                affiche_liste(pl,(void(*)(void *))affiche_contenu);
                printf("\n");
                
                break;

            case 'I' : case 'i' : case '4' :
                pc = cree_alea_contenu();

                printf("%-20s : ","Insertion ordonnee sur nom : ");
                affiche_contenu(pc);
                printf("\n");

                insere_liste(pl,pc,(int(*)(void*,void*))compare_contenu);

                printf("%-10s : \n", "Liste");
                affiche_liste(pl,(void(*)(void *))affiche_contenu);
                printf("\n");

                break;

            case 'R' : case 'r' : case '3' :
                pc =  (contenu *)retire_en_tete_liste(pl);

                printf("%-20s : ","Retrait tete de liste" );
                if (pc) {
                    affiche_contenu(pc);
                    printf("\n");
                    libere_contenu(pc);
                }
                else {
                    printf(" Impossible"); 
                    printf("\n");
                }
                
                printf("%-10s : \n", "Liste");
                affiche_liste(pl, (void(*)(void *))affiche_contenu);
                printf("\n");
                
                break;

            case 'T' : case 't' : case '1' :
                printf("%-20s : ","Tete de liste");

                pc =(contenu *)tete_de_liste(pl);

                if (pc) {
                    affiche_contenu(pc);
                }
                else {
                    printf("Impossible");
                }
                printf("\n");

                break;

            case 'N' : case 'n' : case '5' :
                
            case 'V' : case 'v' : case '6' :
                if (rep[0]=='v' || rep[0]=='V' || rep[0]=='6' ) {
                    comp = compare_valeur;
                }
                else {
                    comp = compare_contenu;
                }
                    
                printf("Tri de liste : \n");
                tri_liste(pl,(int(*)(void*,void*))comp);

                printf("%-10s : \n", "Liste");
                affiche_liste(pl,(void(*)(void *))affiche_contenu);
                printf("\n");

                break;

            case 'F' : case 'f' : case '0' :
                libere_liste(pl,(void(*)(void *))libere_contenu);

                printf("Fin\n");

                return ;
        }
    }
}
    
   
void test_file() {
    printf("a faire");
}

      
int main() {
	char rep[5];
    int fin = 0;
    srand(time(NULL));
#ifdef DEBUG
init_debug();
#endif    
    
    
    while (! fin) {
        printf("1. test (L)iste \n");
        printf("2. test (P)ile \n");
        printf("3. test (F)ile \n");
        
        printf("\n0. fin \nChoix : ");
        
        saisie_chaine(rep,2);

        switch(rep[0]) {
            case '1' : case 'l' : case 'L' :
                test_liste();
                break;
            case '2' : case 'p' : case 'P' : 
                test_pile();
                break;
            case '3' :  case 'f' : case 'F' :
                test_file();
                break;

            case '0' : 
                fin = 1;
            default : 
                break;
        }
	}

#ifdef DEBUG
fin_debug();
#endif  
    return 0;
}

        
    
    



