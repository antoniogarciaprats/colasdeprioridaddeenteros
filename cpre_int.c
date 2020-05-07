// --- CPRE_INT.H - Cola con prioridad para enteros(num prioridades fijo) ---

#include <stdio.h>
#include <stdlib.h>
#include "CPRE_INT.H"


struct cprie_int_nodo {
  struct cprie_int_typo val;
  struct cprie_int_nodo *sig;
};

struct cprie_int_cab {
  struct cprie_int_nodo *p;
  struct cprie_int_nodo *u;
};

struct cprie_int_rep {
  struct cprie_int_cab arrpri[MAXpri];
};


//---------------------------- PRIMITIVAS PUBLICAS --------------------

cprie_int cprie_int_nuev(void) {

  cprie_int cprie;
  int i;

  cprie=(struct cprie_int_rep *) malloc (sizeof (struct cprie_int_rep));
  if (!cprie) {
     fprintf(stderr,"cprie_int_nuev : no hay memoria.\n");
     exit(1);
  }
  for (i=0;i<MAXpri;i++){
     cprie->arrpri[i].p=cprie->arrpri[i].u=NULL;
  }

}

//----------------------------------------------------------------------

int cprie_int_vacia(cprie_int cprie) {

  int i;
  int vacia;

  if (!cprie) {
     fprintf(stderr,"cprie_int_vacia : la cola con prioridad no existe.\n");
     exit(2);
  }
  vacia=1;
  i=0;
  while ((i<MAXpri) && (vacia)) {
     if (cprie->arrpri[i].p) vacia=0;
     else i++;
  }
  return(vacia);

}

//----------------------------------------------------------------------

void cprie_int_mete(cprie_int cprie,struct cprie_int_typo *e,int prior) {

  struct cprie_int_nodo *nuevo;

  if (!cprie) {
     fprintf(stderr,"cprie_int_mete : la cola con prioridad no existe.\n");
     exit(2);
  }
  if ((prior<0) || (prior>=MAXpri)) {
     fprintf(stderr,"cprie_int_mete : prioridad fuera de rango.\n");
     exit(3);
  }

  nuevo=(struct cprie_int_nodo *) malloc(sizeof(struct cprie_int_nodo));
  if(!nuevo){
     fprintf(stderr,"cprie_int_mete : no hay memoria.\n");
     exit(1);
  }
  nuevo->val=*e;
  nuevo->sig=NULL;
  //Si no vacia
  if (cprie->arrpri[prior].p)
     cprie->arrpri[prior].u=cprie->arrpri[prior].u->sig=nuevo;
  else
     cprie->arrpri[prior].u=cprie->arrpri[prior].p=nuevo;

}

//----------------------------------------------------------------------

void cprie_int_saca(cprie_int cprie,struct cprie_int_typo *e) {

  struct cprie_int_nodo *viejo;
  int i;
  int vacia;


  if (!cprie) {
     fprintf(stderr,"cprie_int_saca : la cola con prioridad no existe.\n");
     exit(2);
  }
  vacia=1;
  i=0;
  while ((i<MAXpri) && (vacia)) {
     if (cprie->arrpri[i].p) {
        vacia=0;
        viejo=cprie->arrpri[i].p;
        *e=cprie->arrpri[i].p->val;
        //Solo hay un elemento
        if(cprie->arrpri[i].p==cprie->arrpri[i].u)
           cprie->arrpri[i].p=cprie->arrpri[i].u=NULL;
        //Hay mas de uno
        else cprie->arrpri[i].p=viejo->sig;
        free (viejo);
     }
     else i++;
  }
  if (vacia) {
     fprintf(stderr,"cprie_int_saca : la cola con prioridad esta vacia.\n");
     exit(4);
  }

}

//----------------------------------------------------------------------

void cprie_int_dest(cprie_int *cprie) {

  struct cprie_int_nodo *aux,*viejo;
  int i;

  if (!cprie) {
     fprintf(stderr,"cprie_int_dest : la cola con prioridad no existe.\n");
     exit(2);
  }
  for (i=0;i<MAXpri;i++) {
     aux=(*cprie)->arrpri[i].p;
     while(aux) {
         viejo=aux;
         aux=aux->sig;
         free(viejo);
     }
  }
  free(*cprie);
  *cprie=NULL;

}

// Fin: CPRE_INT.C ----------------------------------------------------