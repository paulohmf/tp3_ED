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

  char palavra[64];
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
  /*
  for(int i=0;i<=tabela.range;i++){
    if(!tabela.hashing[i]->ehVazia()){
      printf("%i---- \n",i);
    }
    tabela.hashing[i]->imprimeLista();
  }
  */
  char op;
  while (scanf(" %c %s", &op, palavra) != EOF) {//voltar com o espaço antes de %c
    if (op == 'q'){
      int chave = int(palavra[0])%tabela.chave;
      nodulo *resposta;
      resposta = tabela.hashing[chave]->pesquisa(palavra);
      printf("%i\n",resposta->contador);
    } 
  }
  //Deleta as listasa encadeadas da tabela Hashing
  for(int i=tabela.range;i>=0;i--){
    delete tabela.hashing[i];
  }
  return 0;

}