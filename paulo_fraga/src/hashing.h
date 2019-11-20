#ifndef __HASHING___
#define __HASHING___

#include <cstdio> // em C substituir por #include <stdio.h>
#include "lista.h"


struct myHashing{
  int range = 25; //Hashing de 0('a') até 25('z')
  int chave = 97; //A posição é encontrada pelo resto da divisão por 'a' ou 97
  listaEncadeada *hashing[26];
};

#endif
