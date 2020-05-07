//-------- Prueba para cola con prioridades de enteros ------------------

#include "CPRE_INT.H"

int main(void) {

  cprie_int a;
  struct cprie_int_typo x;

  clrscr();

  printf("\nCreando cola con prioridad");
  a=cprie_int_nuev();
  if (cprie_int_vacia(a)) printf("\ncola VACIA");
  else printf("\ncola NO VACIA");

  x.info=2;
  cprie_int_mete(a,&x,1);
  x.info=5;
  cprie_int_mete(a,&x,1);
  x.info=3;
  cprie_int_mete(a,&x,0);

  cprie_int_saca(a,&x);
  printf("\nElemento sacado: %d",x.info);

  cprie_int_saca(a,&x);
  printf("\nElemento sacado: %d",x.info);

  cprie_int_saca(a,&x);
  printf("\nElemento sacado: %d",x.info);

  if (cprie_int_vacia(a)) printf("\ncola VACIA");
  else printf("\ncola NO VACIA");
  cprie_int_dest(&a);

}

//Fin: PRUEBA3.C -------------------------------------------------
