/* util.c */
/* utilitaires de saisie */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void purge_clavier() {
    
    while (getchar()!='\n');
}

char *saisie_chaine(char *chaine, int taille) {
    char *p;
    fgets(chaine, taille, stdin);
    if ((p=(char *)memchr(chaine,'\n',taille))!=NULL) {
        *p = '\0';
    }
    else {
        purge_clavier();
    }
    chaine[taille]='\0';
    return chaine;
}

char *alea_chaine(char *chaine, int taille) {
    int i;
    for (i=0;i<taille;++i) {
        chaine[i]=rand()%26+'A';
    }
    chaine[taille]='\0';
    return chaine;
}
    
int saisie_int(int *pn) {
	long int n;
    static char buffer[256];
    char c,*p;
    p=&c;
    c='A';
    saisie_chaine(buffer,256);
    n = strtol(buffer,&p,10);
    if (*p=='\0') {
        *pn = (int)n;
        return 1;
    }
    return 0;
}
    
void alea_int(int *pn, int a, int b) {
    /* aleatoire entre a (inclus) et b(exclu) */
    *pn = a+rand()%(b-a);
}
