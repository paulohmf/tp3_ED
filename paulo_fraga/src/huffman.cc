#include "huffman.h"

huffman::huffman(){
	this->raiz = new noduloArvore;
	this->raiz->palavra = 0;
	this->raiz->contador = 0;
	this->raiz->code = 0;
	this->raiz->esq = 0;
	this->raiz->dir = 0;

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

	noduloArvore **nodulosAtualizados = new noduloArvore*[tam];

	bool novoNoduloInserido = false;
	int posicao = 0;

	//PERCORRE O VETOR ORIGINAL (tam -1) ATE ENCONTRAR A POSICAO
	for(int i=0;i<=(tam-1);i++){
		//printf("%i i\n",i);
		//printf("%i nod->contador < %i this->vetorNodulos[i]->contador \n",nod->contador,this->vetorNodulos[i]->contador);
		//Caso o contador seja maior do que o do nodulo, encontramos a posicao
		if(nod->contador < this->vetorNodulos[i]->contador){
			//printf("SIM %i i\n",i);
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
		//printf("nodulo inserido\n");
		//printf("%i posicao+1\n",posicao+1);
		for(int i=posicao+1;i<=tam;i++){
			nodulosAtualizados[i] = this->vetorNodulos[i-1];
		}
	}
	//caso a posicao tenha sido encontrada


	//imprime vetor aux
	//printf("imprime nodulosAtualizados\n");
	/*
	for(int i=0;i<=tam;i++){
		printf("%i %s\n",nodulosAtualizados[i]->contador,nodulosAtualizados[i]->palavra);
	}
	*/
	if(this->vetorNodulos != 0){
		delete this->vetorNodulos;
	}
	this->vetorNodulos = nodulosAtualizados;
	/*
	//imprime vetor de nodulos
	printf("imprime vetorNodulos\n");
	for(int i=0;i<=tam;i++){
		printf("%i %s\n",this->vetorNodulos[i]->contador,this->vetorNodulos[i]->palavra);
	}
	*/

}

/*
		if(aux->palavra[0] == palavra[0]){
			int ultimaLetra;
			for(int x=0;palavra[x] != '\0' && aux->palavra[x] != '\0';x++){
				if(aux->palavra[x] != palavra[x]){
					break;
				}
				ultimaLetra = x+1;
			}
			if(aux->palavra[ultimaLetra] == '\0' && palavra[ultimaLetra] == '\0'){
				return aux;//Encontrou
			}
		}
*/

void huffman::imprimeGerador(){
	int tam = this->tamanhoVetor;
	for(int i=0;i<=tam;i++){
		printf("%i %s\n",this->vetorNodulos[i]->contador,this->vetorNodulos[i]->palavra);
	}
}