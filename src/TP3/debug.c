/* debug.c */

#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

void * mon_malloc(size_t t) {
    void *p=malloc(t);
#ifdef DEBUG
    fprintf(f_malloc, "%p\n",p);
    fprintf(stdout, "%40s %p\n","mode DEBUG malloc",p);
#endif
    return p;
}


void mon_free(void *p) {
#ifdef DEBUG
    fprintf(f_free, "%p\n",p);
    fprintf(stdout, "%50s %p\n","mode DEBUG free",p);
#endif
    free(p);
}



#ifdef DEBUG
void init_debug() {
f_malloc = fopen("__malloc.dbg","wb");
f_free   = fopen("__free.dbg","wb");
}

void fin_debug() {
    fclose(f_free);
    fclose(f_malloc);
    system("sort __malloc.dbg > __malloc.srt");
    system("sort __free.dbg > __free.srt");
    if (system("diff __malloc.srt __free.srt")== 0) 
      fprintf(stderr,"mode DEBUG : fichiers d'alloc et free identiques\n");
    else 
      fprintf(stderr,"mode DEBUG problem : fichiers d'alloc et free differents\n");
}

/*
sort __malloc.dbg > __malloc.srt
sort __free.dbg > __free.srt
FC __malloc.srt __free.srt
*/
#endif
