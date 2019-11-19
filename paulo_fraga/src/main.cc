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

  for(int i=0;i<=tabela.range;i++){
    if(!tabela.hashing[i]->ehVazia()){
      printf("%i---- \n",i);
    }
   tabela.hashing[i]->imprimeLista();
  }

  printf("\nHUFFMAN\n");
  //inicio do huffmann
  huffman *arvore = new huffman();

  for(int i=0;i<=tabela.range;i++){
    //printf("vazio (%i): %i\n",i,tabela.hashing[i]->ehVazia());
    if(!tabela.hashing[i]->ehVazia()){

      int tamanhoLista = tabela.hashing[i]->size();
      //printf("tamanhoLista %i\n",tamanhoLista);
      for(int x=0;x<=tamanhoLista;x++){
        nodulo tirado = tabela.hashing[i]->pop();
        //printf("tirado %s (%i)\n",tirado.palavra,tirado.contador);

        noduloArvore *novo = new noduloArvore;

        novo->palavra = tirado.palavra;
        novo->contador = tirado.contador;
        novo->code = 0;
        novo->esq = 0;
        novo->dir = 0;

        //printf("INSERIR\nnovo %s (%i)\n",novo->palavra,novo->contador);
        arvore->inserirElemento(novo);
        //printf("INSERIDO\n\n");

        //printf("PALAVRA TIRADA %s\n",tirado.palavra);
        tabela.hashing[i]->insert(tirado.palavra);

      }
    }
    //tabela.hashing[i]->imprimeLista();
  }
  printf("IMPRIME GERADOR\n");
  arvore->imprimeGerador();



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

  //Deleta as listasa encadeadas da tabela Hashing
  for(int i=tabela.range;i>=0;i--){
    delete tabela.hashing[i];
  }
  return 0;

}


/* MAIN TEST FUNCAO DE INSERÇÃO
int main(){
  huffman *arvore = new huffman();

  //CRIANDO UM NODULO A MAO
  noduloArvore *nod = new noduloArvore;
  nod->contador = 2;
  char palavra[10];
  palavra[0] = 'c';
  palavra[1] = 'b';

  palavra[2] = '\0';
  nod->palavra = palavra;
  nod->code = 0;
  nod->esq = 0;
  nod->dir = 0;  

  printf("INSERIR 1\n");
  arvore->inserirElemento(nod);
  printf("CABOU 1\n");

  //CRIANDO UM NODULO A MAO
  noduloArvore *nod1 = new noduloArvore;
  nod1->contador = 2;
  char palavra1[10];
  palavra1[0] = 'c';
  palavra1[1] = 'a';

  palavra1[2] = '\0';

  nod1->palavra = palavra1;
  nod1->code = 0;
  nod->esq = 0;
  nod->dir = 0;  

  printf("INSERIR 2\n");

  arvore->inserirElemento(nod1);
  printf("CABOU 2\n");

  //CRIANDO UM NODULO A MAO
  noduloArvore *nod2 = new noduloArvore;
  nod2->contador = 1;
  char palavra2[10];
  palavra2[0] = 'a';
  palavra2[1] = 'c';

  palavra2[2] = '\0';

  nod2->palavra = palavra2;
  nod2->code = 0;
  nod->esq = 0;
  nod->dir = 0;  

  printf("INSERIR 3\n");

  arvore->inserirElemento(nod2);
  printf("CABOU 3\n");


  delete arvore;
  return 0;
}
*/