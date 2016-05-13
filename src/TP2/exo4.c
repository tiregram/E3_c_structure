#include <stdlib.h>
#include <stdio.h>


typedef struct {
  unsigned char c;
  unsigned long int freq;
} contenu;

void quickSort( contenu *a, int l, int r);
int partitionner(contenu *tableau, int p, int r);


void calculfrequence(FILE * f , unsigned long int t[])
{
  char a;
  while(!feof(f))
    {
      t[(unsigned char)fgetc(f)]++;
    }
}

void main(void)
{
  unsigned long int t[256];

  for(int i=0;i<255;i++)
    {
      t[i] = 0;
    }

  FILE * f = fopen("dico.txt","r");

  calculfrequence( f ,  t);

  fclose(f);
  
  //  for(int i=0;i<255;i++)
  // printf("%c freq %d \n",(char)i,t[i]);

  contenu data[256];

  for(int i=0;i<255;i++)
    {
      data[i].c  = i;
      data[i].freq = t[i];
    }

  quickSort(data,0,255);
  for(int i=0;i<255;i++)
    printf("%c\t freq %d\n",data[i].c,data[i].freq);



}





void quickSort( contenu tableau[], int p, int r)
{
  int q;
  if (p < r)
    {
      q = partitionner(tableau, p, r);
      quickSort(tableau, p, q);
      quickSort(tableau, q+1, r);
    }
}


int partitionner(contenu tableau[], int p, int r) {
  int pivot = tableau[p].freq, i = p-1, j = r+1;
  contenu temp;
  while (1) {
    do
      j--;
    while (tableau[j].freq > pivot);

    do
      i++;
    while (tableau[i].freq < pivot);

    if (i < j) {
      temp.c = tableau[i].c;
      temp.freq = tableau[i].freq;

      tableau[i].c = tableau[j].c;
      tableau[i].freq = tableau[j].freq;

      tableau[j].c = temp.c;
      tableau[j].freq = temp.freq;
    }
    else
      return j;
  }
}

