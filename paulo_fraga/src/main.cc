#include <cstdio> // em C substituir por #include <stdio.h>
#include "lista.h"
#include "huffman.h"

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

  //Recebe o tamanho da entrada
  long int numeroPalavras;
  scanf("%li ",&numeroPalavras);//OLHO NESSE SCANF

  long int palavrasAtualmente = 0;

  char palavra[64];
  int posicao = 0;
  char letra;
  //Recebe as entradas
  while(palavrasAtualmente < numeroPalavras){
    scanf("%c",&letra);
    if(letra == ' ' || letra == '\n'){
      palavra[posicao] = '\0';

      //Insere a entrada no hashing
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
    if(!tabela.hashing[i]->ehVazia()){
      printf("%i---- \n",i);
    }
   tabela.hashing[i]->imprimeLista();
  }

  //inicio do huffmann
  printf("\nHUFFMAN\n\n");
  huffman *arvore = new huffman();

  //Carrega o vetor gerador da arvore de Huffman (a floresta de arvores unicas)
  for(int i=0;i<=tabela.range;i++){

    //printf("vazio (%i): %i\n",i,tabela.hashing[i]->ehVazia());
    if(!tabela.hashing[i]->ehVazia()){

      int tamanhoLista = tabela.hashing[i]->size();
     // printf("tamanhoLista %i\n",tamanhoLista);
      for(int x=0;x<=tamanhoLista;x++){
        nodulo tirado = tabela.hashing[i]->pop();
        tabela.hashing[i]->inserirNodulo(tirado);
        //printf("tirado %s (%i)\n",tirado.palavra,tirado.contador);

        noduloArvore *novo = new noduloArvore;

        novo->palavra = tirado.palavra;
        novo->contador = tirado.contador;
        novo->code = 0;
        novo->folhas = 1;
        novo->esq = 0;
        novo->dir = 0;

        //printf("INSERIR\nnovo %s (%i)\n",novo->palavra,novo->contador);
        arvore->inserirElemento(novo);
        //printf("INSERIDO\n\n");

        //printf("PALAVRA TIRADA %s\n",tirado.palavra);
        //tabela.hashing[i]->insert(tirado.palavra);

      }
      //printf("IMPRIME LISTA\n");
      //tabela.hashing[i]->imprimeLista();
    }
    //tabela.hashing[i]->imprimeLista();
  }
  printf("VETOR GERADOR PRONTO\n");
  //arvore->imprimeGerador();

  //Gera a arvore de Huffman
  printf("GERADOR ARVORE COM OS CODIGOS\n");
  arvore->gerarArvore();
  printf("ARVORE GERADA\n");

  /*
  //GERAR CODIGOS
  char code[0];
  code[0] = '\0';
  this->gerarCodigos(this->raiz,code,tabela);
  */

  /*ERRO POSSIVEL
  //SALVAR CODIGOS NO HASHING
  for(int i=0;i<=tabela.range;i++){
    if(!tabela.hashing[i]->ehVazia()){
      int tamanhoLista = tabela.hashing[i]->size();
      for(int x=0;x<=tamanhoLista;x++){
        nodulo tirado = tabela.hashing[i]->pop();

        printf("######################### PESQUISA N: () ####################\n");
        printf("%i : %s/  CODE : %s\n",tirado.contador,tirado.palavra,tirado.code);

        tirado.code = arvore->pesquisaCodigo(arvore->raiz,tirado.palavra);
        printf("CODE : %s\n",tirado.code);

        tabela.hashing[i]->inserirNodulo(tirado);
        printf("IMPRIME LISTA DO HASHING\n");
        tabela.hashing[i]->imprimeLista();
      }
    }
  }
  */
  /*
  //IMPRIME O HASHING
  for(int i=0;i<=tabela.range;i++){
    if(!tabela.hashing[i]->ehVazia()){
      printf("%i---- \n",i);
    }
   tabela.hashing[i]->imprimeLista();
  }
  */
  /* ENTRADAS DO USUARIO
  char op;
  while (scanf(" %c %s", &op, palavra) != EOF) {//voltar com o espaço antes de %c
    if (op == 'q'){
      int chave = int(palavra[0])%tabela.chave;
      nodulo *resposta;
      resposta = tabela.hashing[chave]->pesquisa(palavra);
      printf("%i\n",resposta->contador);
    } 
  }
  */

  //Deleta a arvore
  delete arvore;
  //Deleta as listas encadeadas da tabela Hashing
  for(int i=tabela.range;i>=0;i--){
    delete tabela.hashing[i];
  }
  return 0;

}
