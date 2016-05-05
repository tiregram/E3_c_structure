#include <stdio.h>
#include <limits.h>



int factorielle_iteractive(int n)
{
  
    
  int i, p = 1;
  for(i= 1 ;i<=n;++i){
    if(INT_MAX / n < p )
      return -1;
    
    p *= i;
  }

  return p;
}

int factorielle_recursive(int n)
{
  int num;
  if(n<=0)
    return 1;
  else{
    num = factorielle_recursive(n-1);
    if(num == -1 || INT_MAX / n < num)
      return -1;   
    else
      return n * num;
  }
}


int main(void)
{
int n;
do {

printf("Entrez un nombre entier (0 pour terminer):");
scanf("%d",&n);
printf("factorielle_iteractive(%2d) = %15d\n",n,factorielle_iteractive(n));
printf("factorielle_recursive(%2d) = %15d\n",n,factorielle_recursive(n));

}while(n != 0);

return 0;


}
