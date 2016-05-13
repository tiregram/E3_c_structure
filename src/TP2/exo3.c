#include "fifo.h"
#include "contenu.h"
#include <string.h>

typedef struct _n {
  int n;
  struct _m *svt;
}maillon, *liste;


void scission( liste lst, liste *p_list1, liste *p_list2)
{

  for(maillon *i = pull_at_begin(lst); lst !=NULL; i = pull_at_begin(lst))
    {
      push_at_begin(*p_list1,i);

      // xor swap :-)
      *p_list1 = *p_list1 ^ *p_list2;
      *p_list2 = *p_list1 ^ *p_list2;
      *p_list1 = *p_list1 ^ *p_list2;
    }
}


void fusion(liste lst1,liste lst2 , liste *lst)
{
  
  while(!est_vide(*list1) && !est_vide(*list2))
    {
      if( peek_begin(list1) < peek_begin(list2) )
        {
          push_at_begin(lst,pull_at_begin(list1));
        }
      else
        {
          push_at_begin(lst,pull_at_begin(list2));
        }
    }

  while(!est_vide(*list1))
    {
      push_at_begin(lst,pull_at_begin(list1));
    }

  while(!est_vide(*list2))
    {
      push_at_begin(lst,pull_at_begin(list2));
    }
}

// trie par eclatement
int main(void)
{
  contenu conte;


}
