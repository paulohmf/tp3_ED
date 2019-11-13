#include <cstdio> // em C substituir por #include <stdio.h>
#include "lista.h"

int main() {
  long int numeroPalavras;

  scanf("%li ",&numeroPalavras);//OLHO NESSE SCANF

  long int palavrasAtualmente = 0;

  char palavra[63];
  int posicao = 0;
  char letra;
  while(palavrasAtualmente < numeroPalavras){
    scanf("%c",&letra);
    if(letra == ' ' || letra == '\n'){
      palavra[posicao] = '\0';
      printf("%li %s\n",palavrasAtualmente,palavra);//ADD PALAVRA NO HASHING
      posicao = 0;
      palavrasAtualmente++;
    }else{
      palavra[posicao] = letra;
      posicao++;
    }
  }

  return 0;
}
