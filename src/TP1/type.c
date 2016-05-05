
#include "math.h"
#include "stdio.h"
#include "stdbool.h"
// int BD;
// char[] numtel;
// char[] numdep;
// double TVA;
// int fileSize;


#define ZERO 1e-100
#define EPSILON 1e-10
 
int proche(double a, double b)
{
  return  (!fabs(a)<=ZERO && fabs(b) <= ZERO)  || (fabs(a-b) <= EPSILON) ;
}

double moyenne(double t[], int n)
{
  double somme = 0.0;
  for(int i = 0; i<n; i++)
    somme += t[i];

  return somme / n;
}

double moyenne_positifs(double t[])
{
  if(proche(t[0],-1))return -1.0;
  int i =0;
  double somme = 0.0;
 
  while(!proche(t[i],-1.0))
    {
      somme += t[i];
      i++;
    }
  
  return somme / (i);

}

int chaine_longueur_rec(char*s)
{
  if (s[0] != '\0')
    return 1 + chaine_longueur_rec(s+1);
  return 1;
}

int chaine_debute_par(char *s1,char*s2)
{
  
  if(s2[0] == '\0')
    return true;
  
  if(s1[0] == '\0')
    return false;

  if (s1[0] == s2[0]){
    return chaine_debute_par(s1+1,s2+1);
  }
  else
    return false;
    
}

int chaine_index(char*s1,char*s2)
{
  int i = 0;
  
  while(s1[i] != '\0')
    {

      if(chaine_debute_par(s1+i,s2))
        {
          return i;
        }
      i++;
    }

  return -1;
  
}

double test_moyenne () {
  double v [] = {1.0 , 2.0 , 3.0 , 4.0 , 5.0 , 6.0 , -1.0};
  double d , attendu ;
  attendu = 1;
  /* test moyenne */
  if (! proche (( d = moyenne (v , 1) ) , attendu ) ) {
    printf ("Pb moyenne . Attendu : %f Obtenu :%f \n" , attendu , d ) ;
  }
  attendu = 2.0;
  if (! proche (( d = moyenne (v , 3) ) , attendu ) ) {
    printf ("Pb moyenne . Attendu : %f Obtenu :%f \n" , attendu , d ) ;
  }
  attendu = 3.5;
  if (! proche (( d = moyenne (v , 6) ) , attendu ) ) {
    printf ("Pb moyenne . Attendu : %f Obtenu :%f \n" , attendu , d ) ;
  }
  /* test moyenne positifs */
  attendu = 3.5;
  if (! proche (( d = moyenne_positifs ( v ) ) , attendu ) ) {
    printf ("Pb moyenne_positifs . Attendu : %f Obtenu :%f \n" , attendu , d ) ;
  }
  attendu = 5.0;
  if (! proche (( d = moyenne_positifs ( v + 3) ) , attendu ) ) {
    printf ("Pb moyenne_positifs . Attendu : %f Obtenu :%f \n" , attendu , d ) ;
  }
  attendu = -1.0;
  if (! proche ( d = moyenne_positifs (v + 6) , -1.0) ) {
    printf ("Pb moyenne_positifs . Attendu : %f Obtenu :%f \n" , attendu , d ) ;
  }
}

void aff_bin(double d)
{
  unsigned char * a = (unsigned char*) &d;
  
  for(unsigned int i = 0;
      i < sizeof(double)/sizeof(unsigned char);
      i++){
    for(unsigned char y = 0x1 << (sizeof(unsigned char)*8-1);
        y != 0;
        y = y >> 1)
      printf("%c",(y & a[i])?'1':'0');
  }
}

void carre(int *p )
{
  *p=(*p)*(*p);
}


int main()
{
  //printf("%d\n",chaine_index("lapin","aa"));
  //printf("%d\n",chaine_index("lapin","lap"));
  //printf("%d\n",chaine_index("lapin","pin"));

  aff_bin(2.0);
  printf("\n");
  aff_bin(3.55);
  printf("\n");
  aff_bin(5.33);
  printf("\n");
  // printf("proche(0.0,0.0) == %d\n",proche(0.0,0.0));
  // printf("proche(2.0,3.0) == %d\n",proche(2.0,3.0));
  // printf("proche(2.0,2.0+Epsi-) == %d\n",proche(2.0,2.0+EPSILON-EPSILON*0.1));
  // printf("proche(2.0,2.0+(Epsi+)) == %d\n",proche(2.0,2.0+EPSILON+EPSILON*0.1));

  test_moyenne();

}
