/* debug.h */
/* pour le debugage */

#include <stdio.h> /* pour FILE */

#ifndef DEBUG_H
#define DEBUG_H

/* a commenter pour un mode sans debug d'alloc memoire */
#define DEBUG

 
#ifdef DEBUG
FILE *f_malloc;
FILE *f_free;

void init_debug();
void fin_debug();
 
    

#endif 



void * mon_malloc(size_t t);
void mon_free (void *p);
#endif


/*


sort malloc.dbg > malloc.srt
sort free.dbg > free.srt
FC malloc.srt free.srt
    Comparaison des fichiers malloc.srt et free.SRT
    FC : aucune difference trouvee
*/
