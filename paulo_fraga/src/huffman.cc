#include "huffman.h"

huffman::huffman(){
	this->raiz = new noduloArvore;
	this->raiz->palavra = 0;
	this->raiz->contador = 0;
	this->raiz->folhas = 0;
	this->raiz->code = 0;
	this->raiz->esq = 0;
	this->raiz->dir = 0;

	this->vetorNodulos = 0;
	this->tamanhoVetor = -1;

}

void huffman::esvaziaArvore(noduloArvore *no){
	if(no != 0){
		delete no->palavra;
		delete no->code;
		esvaziaArvore(no->esq);
		esvaziaArvore(no->dir);
		delete no;
	}

}

huffman::~huffman(){
	this->esvaziaArvore(this->raiz);
	delete this->raiz;
	delete this->vetorNodulos;
}

//Imprime todos os vetores presentes no vetor que sera usado para gerar a arvore
void huffman::imprimeGerador(){
	int tam = this->tamanhoVetor;
	for(int i=0;i<=tam;i++){
		printf("%i %i %s\n",this->vetorNodulos[i]->contador,this->vetorNodulos[i]->folhas,this->vetorNodulos[i]->palavra);
	}
}

//Essa funcao insere um nodulo no --->VETOR GERADOR<---
//Para realizar a insercao a funcao respeita a ordem de contadores, em seguida de folhas e por fim lexical
void huffman::inserirElemento(noduloArvore *nod){
	this->tamanhoVetor++;
	int tam = this->tamanhoVetor;

	noduloArvore **nodulosAtualizados = new noduloArvore*[tam+5];

	bool novoNoduloInserido = false;
	int posicao = 0;

	//PERCORRE O VETOR ORIGINAL (tam -1) ATE ENCONTRAR A POSICAO
	for(int i=0;i<=(tam-1);i++){

		//Caso o contador seja maior do que o do nodulo, encontramos a posicao
		if(nod->contador < this->vetorNodulos[i]->contador){
			nodulosAtualizados[i] = nod;
			posicao = i;
			novoNoduloInserido = true;
		}

		//caso o contador seja igual, temos que checar pela palavra
		if(nod->contador == this->vetorNodulos[i]->contador){

			//se o contador for igual, primerio eu olho o numero de folhas
			if(nod->folhas == this->vetorNodulos[i]->folhas){

				//se a primeira letra da palavra for menor que a primeira letra comparada encontramos a posicao a posicao
				if(nod->palavra[0] < this->vetorNodulos[i]->palavra[0]){
					nodulosAtualizados[i] = nod;
					posicao = i;
					novoNoduloInserido = true;
					break;
				}
				//se a primeira letra for igual, temos que pecorrer a palavra inteira para encontrar a posicao certa
				if(nod->palavra[0] == this->vetorNodulos[i]->palavra[0]){

					//percorre a palavra inteira
					int ultimaLetra;
					for(int x=0;nod->palavra[x] != '\0' && this->vetorNodulos[i]->palavra[x] != '\0';x++){
						//se a letra for menor achamos a posição
						if(nod->palavra[x] < this->vetorNodulos[i]->palavra[x]){
							nodulosAtualizados[i] = nod;
							posicao = i;
							novoNoduloInserido = true;
							break;
						}
						//se a letra for paior saimos do loop
						if(nod->palavra[x] > this->vetorNodulos[i]->palavra[x]){
							break;
						}
						//se for igual continuamos comparando
						ultimaLetra = x+1;
					}
					//se todas as letras ate agora eram iguais e a palavra 
					if(nod->palavra[ultimaLetra] == '\0' && this->vetorNodulos[i]->palavra[ultimaLetra] != '\0'){
						nodulosAtualizados[i] = nod;
						posicao = i;
						novoNoduloInserido = true;
					}
				}
			}
			//se as folhas passarem as do vetor, encontrei a posicao
			if(nod->folhas < this->vetorNodulos[i]->folhas){
				nodulosAtualizados[i] = nod;
				posicao = i;
				novoNoduloInserido = true;
				break;
			}
		}
		if(novoNoduloInserido){
			break;
		}
		//caso o nodulo nao tenha encontrado sua posicao, o novo vetor e atualizado com o valor do antigo
		nodulosAtualizados[i] = this->vetorNodulos[i];
	}
	//Caso todos os elementos tenham sido percorridos a posicao do nodulo eh no final do novo vetor
	if(!novoNoduloInserido){
		nodulosAtualizados[tam] = nod;
		posicao = tam;
	}else{
		//caso a posicao tenha sido encontrada
		for(int i=posicao+1;i<=tam;i++){
			//copia o restante dos nodulos no vetor atualizado
			nodulosAtualizados[i] = this->vetorNodulos[i-1];
		}
	}

	//deleta o vetor antigo
	if(this->vetorNodulos != 0){
		delete this->vetorNodulos;
	}
	//salva o vetor novo
	this->vetorNodulos = nodulosAtualizados;
}
//Essa funcao meramente determina se a palavra 0 é menor que a palavra 1 (usada para gerar a arvore)
int menorPalavra(char *palavra_0,char *palavra_1){
	if(palavra_0[0] < palavra_1[0]){
		return 0;
	}
	if(palavra_1[0] < palavra_0[0]){
		return 1;
	}

	if(palavra_0[0] == palavra_1[0]){
		//percorre a palavra inteira
		int ultimaLetra;
		for(int x=0;palavra_0[x] != '\0' && palavra_1[x] != '\0';x++){
			//se a letra for menor achamos a posição
			if(palavra_0[x] < palavra_1[x]){
				return 0;
			}
			if(palavra_1[x] < palavra_0[x]){
				return 1;
			}
			//se for igual continuamos comparando
			ultimaLetra = x+1;
		}
		//se todas as letras ate agora eram iguais e a palavra 
		if(palavra_0[ultimaLetra] != '\0' && palavra_1[ultimaLetra] == '\0'){
			return 1;
		}
		return 0;
	}
	return 0;
}

void huffman::gerarArvore(){
	int tamanho = this->tamanhoVetor;

	//Enquanto nao restar apenas um no raiz a construção da arvore segue
	while(tamanho > 0){
		//nova raiz e criada e os dois primeros noduloArvore do vetor gerador sao juntados
		noduloArvore *novo = new noduloArvore;
		novo->contador = this->vetorNodulos[0]->contador + this->vetorNodulos[1]->contador; 
		novo->folhas = this->vetorNodulos[0]->folhas + this->vetorNodulos[1]->folhas;
		int menor = menorPalavra(this->vetorNodulos[0]->palavra,this->vetorNodulos[1]->palavra);//funcao determina a menor palavra
		novo->palavra = this->vetorNodulos[menor]->palavra;
		novo->esq = this->vetorNodulos[0];
		novo->dir = this->vetorNodulos[1];

		//o vetor de nodulos geradores é atualizado para remover os dois primerio elementos
		noduloArvore **nodulosAtualizados = new noduloArvore*[tamanho];
		for(int i=0;i<=tamanho-2;i++){
			nodulosAtualizados[i] = this->vetorNodulos[i+2];
		}
		//o vetor de nodulso e apagado e o vetor atualizado é salvo
		if(this->vetorNodulos != 0){
			delete this->vetorNodulos;
		}
		this->tamanhoVetor--;
		this->tamanhoVetor--;
		this->vetorNodulos = nodulosAtualizados;

		//O novo nodulo gerado é adicionado no vetor
		this->inserirElemento(novo);

		//tamanho do vetor é salvo para se continuar o looping
		tamanho = this->tamanhoVetor;
	}
	//ao sair do looping apenas havera a raiz da arvore na lista de vetores geradores
	//ela é salva na raiz da arvore
	this->raiz = this->vetorNodulos[0];
}

//Função recursiva que percorre a arvore incrementando o codigo ate que encontre uma folha, alem disso salva os codigos num hashing
void huffman::gerarCodigos(noduloArvore *nod,char *code,myHashing *tabela){
	//tem como condição de parada um nodulo vazio
	if(nod != 0){
		//Caso o nodulo seja uma folha
		if(nod->folhas == 1){
			//atribui o codigo gerado ate agora no nodulo
			nod->code = code;
			//acessa o hashing na posicao desejada
			int chave = int(nod->palavra[0])%tabela->chave;
			//encontra na lista encadeada a palavra e salva seu codigo
			nodulo *noduloLista = tabela->hashing[chave]->pesquisa(nod->palavra);
			noduloLista->code = code;
			return;
		}
		//caso o nodulo nao seja uma folha
		//determina o tamanho atual do codigo
		int tamanho = 0;
		for(int i=0;code[i] != '\0';i++){
			tamanho++;
		}
		//gera novos codigos
		char *novoCodigoEsq = new char[tamanho+2];
		char *novoCodigoDir = new char[tamanho+2];
		//copia o inicio dos codigos antigos nos codigos novos
		for(int i=0;i<tamanho;i++){
			novoCodigoEsq[i] = code[i];
			novoCodigoDir[i] = code[i];			
		}
		tamanho++;
		//Adiciona o valor nas posicoes finais do codigo
		novoCodigoEsq[tamanho] = '\0';
		novoCodigoEsq[tamanho-1] = '0';

		novoCodigoDir[tamanho] = '\0';
		novoCodigoDir[tamanho-1] = '1';

		//chama a funcao pros nodulso filhos, agora com o codigo atualizado
		gerarCodigos(nod->esq,novoCodigoEsq,tabela);
		gerarCodigos(nod->dir,novoCodigoDir,tabela);
	}
}