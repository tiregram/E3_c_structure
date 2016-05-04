#include <stdio.h>

#define TMAX 10

typedef struct {
  int data[TMAX];
  int sommet;
} t_pile;

void init_pile(t_pile * pp)
{
  pp->sommet = 0;
  
}

int est_pleine_pile(t_pile * pp)
{
  return TMAX == pp->sommet;
}

void empile(t_pile * pp, int x )
{
  pp->data[pp->sommet++] = x;
}
 
int depile(t_pile *pp)
{
  return pp->data[--pp->sommet];
}


int depile_securit(t_pile *pp)
{
  if (pp->sommet != 0)
    return depile(pp);
}

void empile_securit(t_pile * pp, int x )
{
  if (!est_pleine_pile(pp))
    empile(pp,x);
  
}


void print_pile(t_pile * pp)
{
  printf("Pile:%d/%d\n",pp->sommet,TMAX);
  for(int i = 0; i<pp->sommet;i++)
    printf("%d,",pp->data[i]);
  printf("\n");

  return;
}

int list_sommet_pile(t_pile * pp)
{
  return pp->data[pp->sommet-1];
}

int main(void)
{
  t_pile a;

  empile_securit(&a,1);
  empile_securit(&a,2);
  empile_securit(&a,3);
  empile_securit(&a,4);
  print_pile(&a);
  
  empile_securit(&a,1);
  empile_securit(&a,2);
  empile_securit(&a,3);
  empile_securit(&a,4);
  print_pile(&a);
  
  empile_securit(&a,1);
  empile_securit(&a,2);
  empile_securit(&a,3);
  empile_securit(&a,4);
  print_pile(&a);

  depile_securit(&a);
  depile_securit(&a);
  depile_securit(&a);
  depile_securit(&a);
  print_pile(&a);

  depile_securit(&a);
  depile_securit(&a);
  depile_securit(&a);
  depile_securit(&a);
  print_pile(&a);
  
  depile_securit(&a);
  depile_securit(&a);
  depile_securit(&a);
  depile_securit(&a);
  print_pile(&a);
  
}
