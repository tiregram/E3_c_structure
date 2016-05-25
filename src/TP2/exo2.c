#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "fifo.h"
#include "contenu.h"

int main () {
  contenu txt;
    fifo * pf = creer_fifo () ;
    for (; ; ) {
          printf (" Ajouter un texte a la file (! pour retirer , * pour finir ) : ") ;
          saisir_contenu (& txt ) ;
          if ( comparer_chaine (& txt , "*") == 0)
               break ;
          if ( comparer_chaine (& txt , "!") == 0) {
               if ( est_vide_file ( pf ) ) {
                  printf (" Retrait imposible . File vide ") ;
               }
             else {
                 defiler_file ( pf , & txt ) ;
               }
               afficher_file ( pf ) ;
               printf ("\n ") ;
        }
          else {
            enfiler_file ( pf , & txt ) ;
               afficher_file ( pf ) ;
               printf ("\n ") ;
          }
    }

    delete_file ( pf ) ;
    getchar () ;
    return 0;
}
