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

huffman::~huffman(){
	delete this->raiz;
}

//Essa funcao insere um nodulo NO --->VETOR GERADOR<---
void huffman::inserirElemento(noduloArvore *nod){
	this->tamanhoVetor++;
	int tam = this->tamanhoVetor;

	//printf("%i this->tamanhoVetor++ \n",tam);

	noduloArvore **nodulosAtualizados = new noduloArvore*[tam+5];

	bool novoNoduloInserido = false;
	int posicao = 0;

	//PERCORRE O VETOR ORIGINAL (tam -1) ATE ENCONTRAR A POSICAO
	for(int i=0;i<=(tam-1);i++){
		//printf("%i i\n",i);
		//printf("%i nod->contador < %i this->vetorNodulos[i]->contador \n",nod->contador,this->vetorNodulos[i]->contador);
		//Caso o contador seja maior do que o do nodulo, encontramos a posicao
		if(nod->contador < this->vetorNodulos[i]->contador){
			printf("SIM %i i\n",i);
			nodulosAtualizados[i] = nod;
			posicao = i;
			novoNoduloInserido = true;
		}
		//printf("%i nod->contador == %i this->vetorNodulos[i]->contador \n",nod->contador,this->vetorNodulos[i]->contador);
		//caso o contador seja igual, temos que checar pela palavra
		if(nod->contador == this->vetorNodulos[i]->contador){
			//printf("SIM\n");
			//printf("%c nod->palavra[0] < %c this->vetorNodulos[i]->palavra[0] \n",nod->palavra[0], this->vetorNodulos[i]->palavra[0]);
			//se a primeira letra da palavra for menor que a primeira letra comparada encontramos a posicao a posicao
			if(nod->palavra[0] < this->vetorNodulos[i]->palavra[0]){
				//printf("SIM %i i\n",i);
				nodulosAtualizados[i] = nod;
				posicao = i;
				novoNoduloInserido = true;
				break;
			}
			//se a primeira letra for igual, temos que pecorrer a palavra inteira para encontrar a posicao certa
			//printf("%c nod->palavra[0] < %c this->vetorNodulos[i]->palavra[0] \n",nod->palavra[0], this->vetorNodulos[i]->palavra[0]);
			if(nod->palavra[0] == this->vetorNodulos[i]->palavra[0]){
				//printf("SIM\n");
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
						//SAI
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
		if(novoNoduloInserido){
			break;
		}
		//caso o nodulo nao tenha encontrado sua posicao, o novo vetor e atualizado com o valor antigo
		nodulosAtualizados[i] = this->vetorNodulos[i];
	}
	//Caso todos os elementos tenham sido percorridos a posicao do nodulo eh no final do novo vetor
	if(!novoNoduloInserido){
		//printf("nodulo nao inserido\n");
		//printf("%i tam\n",tam);
		//printf("%s nod\n",nod->palavra);
		nodulosAtualizados[tam] = nod;
		posicao = tam;
	}else{
		//caso a posicao tenha sido encontrada
		//printf("nodulo inserido\n");
		//printf("%i posicao+1\n",posicao+1);
		for(int i=posicao+1;i<=tam;i++){
			nodulosAtualizados[i] = this->vetorNodulos[i-1];
		}
	}

	//imprime vetor aux
	//printf("imprime nodulosAtualizados\n");
	//for(int i=0;i<=tam;i++){
	//printf("%i %s\n",nodulosAtualizados[i]->contador,nodulosAtualizados[i]->palavra);
	//}
	
	if(this->vetorNodulos != 0){
		delete this->vetorNodulos;
	}
	this->vetorNodulos = nodulosAtualizados;
	
	//imprime vetor de nodulos
	//printf("imprime vetorNodulos\n");
	//for(int i=0;i<=tam;i++){
	//	printf("%i %s\n",this->vetorNodulos[i]->contador,this->vetorNodulos[i]->palavra);
	//}

}
void huffman::gerarArvore(){

	int tamanho = this->tamanhoVetor;

	printf("%i this->tamanhoVetor++ \n",tamanho);

	while(tamanho > 0){
		noduloArvore *novo = new noduloArvore;

		printf("%i %i %s - %x\n",this->vetorNodulos[0]->contador,this->vetorNodulos[0]->folhas,this->vetorNodulos[0]->palavra,this->vetorNodulos[0]);
		printf("%i %i %s - %x\n",this->vetorNodulos[1]->contador,this->vetorNodulos[1]->folhas,this->vetorNodulos[1]->palavra,this->vetorNodulos[1]);

		novo->contador = this->vetorNodulos[0]->contador + this->vetorNodulos[1]->contador; 
		novo->folhas = this->vetorNodulos[0]->folhas + this->vetorNodulos[1]->folhas; 
		novo->palavra = this->vetorNodulos[0]->palavra;
		novo->esq = this->vetorNodulos[0];
		novo->dir = this->vetorNodulos[1];

		printf("NOVO\n%i %i %s\n%x %x\n",novo->contador,novo->folhas,novo->palavra,novo->esq,novo->dir);

		noduloArvore **nodulosAtualizados = new noduloArvore*[tamanho];
		for(int i=0;i<=tamanho-2;i++){
			nodulosAtualizados[i] = this->vetorNodulos[i+2];
		}
		/*
		printf("IMPRIMIR GERADOR POS REMOÇÃO DE 0/1\n");
		for(int i=0;i<=tamanho-2;i++){
			printf("%i %i %s\n",nodulosAtualizados[i]->contador,nodulosAtualizados[i]->folhas,nodulosAtualizados[i]->palavra);
		}
		*/
		if(this->vetorNodulos != 0){
			delete this->vetorNodulos;
		}
		this->tamanhoVetor--;
		this->tamanhoVetor--;
		this->vetorNodulos = nodulosAtualizados;

		this->imprimeGerador();

		printf("\nENTRANDO NO INSERT ########################################################################################\n");
		this->inserirElemento(novo);
		printf("\nSAINDO DO INSERT ########################################################################################\n\n");

		printf("IMPRIMIR GERADOR\n");
		this->imprimeGerador();

		tamanho = this->tamanhoVetor;
		printf("%i this->tamanhoVetor++ \n",tamanho);
	}

	this->raiz = this->vetorNodulos[0];
}

void huffman::imprimeGerador(){
	printf("%i this->tamanhoVetor \n",this->tamanhoVetor);
	int tam = this->tamanhoVetor;
	for(int i=0;i<=tam;i++){
		printf("%i %i %s\n",this->vetorNodulos[i]->contador,this->vetorNodulos[i]->folhas,this->vetorNodulos[i]->palavra);
	}
}