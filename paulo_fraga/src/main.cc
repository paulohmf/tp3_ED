#include <cstdio> // em C substituir por #include <stdio.h>
#include "lista.h"
#include "huffman.h"
#include "hashing.h"

int main(){
  //################# Inicialização do hashing ##################################
  myHashing *tabela = new myHashing;

  //Incializa as listas encadeadas da tabela Hashing
  for(int i=0;i<=tabela->range;i++){
    listaEncadeada *lista = new listaEncadeada();
    tabela->hashing[i] = lista;
  }
  //################ Hashing inicializado #######################################


  //################ Recebendo as 'n' palavras ##################################
  //Recebe o tamanho da entrada
  long int numeroPalavras;
  scanf("%li ",&numeroPalavras);

  //Recebe as entradas
  long int palavrasAtualmente = 0;
  char palavra[64];
  int posicao = 0;
  char letra;
  while(palavrasAtualmente < numeroPalavras){
    scanf("%c",&letra);
    //Se chegou ao fim de uma palavra
    if(letra == ' ' || letra == '\n'){
      palavra[posicao] = '\0';

      //Insere a entrada no hashing
      int chave = int(palavra[0])%tabela->chave;
      tabela->hashing[chave]->insert(palavra);

      posicao = 0;
      palavrasAtualmente++;
    }else{
      //Se nao, continua recebendo a palavra
      palavra[posicao] = letra;
      posicao++;
    }
  }
  //############### Palavras recebidas ##########################################


  //############### Inicio do Huffman ###########################################
  huffman *arvore = new huffman();

  //Carrega o vetor gerador da arvore de Huffman (a floresta de arvores unicas)
  for(int i=0;i<=tabela->range;i++){
    //Percorre todas as listas existentes no hashing
    if(!tabela->hashing[i]->ehVazia()){

      int tamanhoLista = tabela->hashing[i]->size();
      //Percorre todos os elementos de cada lista
      for(int x=0;x<=tamanhoLista;x++){
        //Retira o elemento e o insere no final da litas
        nodulo tirado = tabela->hashing[i]->pop();
        tabela->hashing[i]->inserirNodulo(tirado);

        //Adapta os nodulos da lista para os nodulos de arvore
        noduloArvore *novo = new noduloArvore;
        novo->palavra = tirado.palavra;
        novo->contador = tirado.contador;
        novo->code = 0;
        novo->folhas = 1;
        novo->esq = 0;
        novo->dir = 0;

        //Insere o nodulo na lista de vetores geradores do Huffman
        arvore->inserirElemento(novo);
      }
    }
  }
  //Gera a arvore de Huffman
  arvore->gerarArvore();

  //Gera os codigos na arvore e salva no hashing
  char code[0];
  code[0] = '\0';
  arvore->gerarCodigos(arvore->raiz,code,tabela);//Receve a raiz da arvore, um code zerado "", e o hashing em que os codigos serao salvos
  //############# Fim do Huffman ################################################


  //############# ENTRADAS DO USUARIO e saidas ##################################
  char op;
  while (scanf(" %c %s", &op, palavra) != EOF) {
    if (op == 'q'){
      int chave = int(palavra[0])%tabela->chave;
      nodulo *resposta;
      resposta = tabela->hashing[chave]->pesquisa(palavra);
      printf("%i\n",resposta->contador);
    }
    if (op == 'c'){
      int chave = int(palavra[0])%tabela->chave;
      nodulo *resposta;
      resposta = tabela->hashing[chave]->pesquisa(palavra);
      printf("%s\n",resposta->code);
    } 
  }
  //############# FIM DAS ENTRADAS e saidas #####################################


  //############# Free de tudo que foi gerado ###################################
  //Deleta a arvore
  delete arvore;//o destrutor tem funcao que desacola cada no da arvore e seu conteudo

  //Deleta as listas encadeadas da tabela Hashing
  for(int i=tabela->range;i>=0;i--){
    delete tabela->hashing[i]; //o destrutor tem funcao que desacola cada nodulo e seu conteudo
  }

  //Deleta o Hashing
  delete tabela;
  //############# fim do free ###################################################
  return 0;

}
