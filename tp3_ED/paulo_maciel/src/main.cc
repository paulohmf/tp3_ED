#include <cstdio> // em C substituir por #include <stdio.h>
#include "lista.h"

struct myHashing{
  int range = 25;
  int chave = 97;
  listaEncadeada *hashing[26];
};

int main(){
  myHashing tabela;

  //Incializa as listasa encadeadas da tabela Hashing
  for(int i=0;i<=tabela.range;i++){
    listaEncadeada *lista = new listaEncadeada();
    tabela.hashing[i] = lista;
  }

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

      //Insere no hashing
      int chave = int(palavra[0])%tabela.chave;
      tabela.hashing[chave]->insert(palavra);

      posicao = 0;
      palavrasAtualmente++;
    }else{
      palavra[posicao] = letra;
      posicao++;
    }
  }
  //IMPRIME O HASHING
  for(int i=0;i<=tabela.range;i++){
    printf("%i---- \n",i);
    tabela.hashing[i]->imprimeLista();
  }

  //Deleta as listasa encadeadas da tabela Hashing
  for(int i=tabela.range;i>=0;i--){
    delete tabela.hashing[i];
  }

  return 0;
}