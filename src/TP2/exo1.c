#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLEMAX 10

typedef struct {
  char tab[TAILLEMAX];
} contenu;

void print_contenu(contenu * contenu_to_print)
{
  char * f = contenu_to_print->tab;
  while(*f != '\0' && contenu_to_print->tab+TAILLEMAX != f )
    {
      printf("%c",*f);
      f++;
    }
}


void saisir_contenu(contenu * contenu_to_remplir)
{
  char * c =  contenu_to_remplir->tab;

  do
    {
      *c = getc(stdin);
      c++;
    } while (*c != '\n' && c < contenu_to_remplir->tab + TAILLEMAX);

  *c = '\0';
}

int main(void)
{
  contenu a ;
  saisir_contenu(&a);
  print_contenu(&a);
  return 0;
}

