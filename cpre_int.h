// --- CPRE_INT.H - Cola con prioridad para enteros(num prioridades fijo) ---

#ifndef CPRE_int_H
#define CPRE_int_H

#define MAXpri 5   //Tamanio max del array de prioridades

struct cprie_int_typo {   //Tipo base de la cola con prioridad
  int info;
};


typedef struct cprie_int_rep *cprie_int;

cprie_int cprie_int_nuev(void);
int cprie_int_vacia(cprie_int cprie);
void cprie_int_mete(cprie_int cprie,struct cprie_int_typo *e,int prior);
void cprie_int_saca(cprie_int cprie,struct cprie_int_typo *e);
void cprie_int_dest(cprie_int *cprie);

#endif


// Fin de CPRE_INT.H ----------------------------------------
