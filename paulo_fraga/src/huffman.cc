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
			//printf("SIM %i i\n",i);
			nodulosAtualizados[i] = nod;
			posicao = i;
			novoNoduloInserido = true;
		}
		//printf("%i nod->contador == %i this->vetorNodulos[i]->contador \n",nod->contador,this->vetorNodulos[i]->contador);
		//caso o contador seja igual, temos que checar pela palavra
		if(nod->contador == this->vetorNodulos[i]->contador){
			//printf("SIM\n");

			//se o contador for igual, primerio eu olho o numero de folhas
			if(nod->folhas == this->vetorNodulos[i]->folhas){

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

	//printf("%i this->tamanhoVetor++ \n",tamanho);

	while(tamanho > 0){
		noduloArvore *novo = new noduloArvore;

		//printf("%i %i %s - %x\n",this->vetorNodulos[0]->contador,this->vetorNodulos[0]->folhas,this->vetorNodulos[0]->palavra,this->vetorNodulos[0]);
		//printf("%i %i %s - %x\n",this->vetorNodulos[1]->contador,this->vetorNodulos[1]->folhas,this->vetorNodulos[1]->palavra,this->vetorNodulos[1]);

		novo->contador = this->vetorNodulos[0]->contador + this->vetorNodulos[1]->contador; 
		novo->folhas = this->vetorNodulos[0]->folhas + this->vetorNodulos[1]->folhas;

		//funcao determina a menor palavra
		int menor = menorPalavra(this->vetorNodulos[0]->palavra,this->vetorNodulos[1]->palavra);
		novo->palavra = this->vetorNodulos[menor]->palavra;


		novo->esq = this->vetorNodulos[0];
		novo->dir = this->vetorNodulos[1];

		//printf("NOVO\n%i %i %s\n%x %x\n",novo->contador,novo->folhas,novo->palavra,novo->esq,novo->dir);

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

		//this->imprimeGerador();

		//printf("\nENTRANDO NO INSERT ########################################################################################\n");
		this->inserirElemento(novo);
		//printf("\nSAINDO DO INSERT ########################################################################################\n\n");

		//printf(" ############ IMPRIMIR GERADOR ###########\n");
		//this->imprimeGerador();
		//printf(" #########################################\n");
		tamanho = this->tamanhoVetor;
		//printf("%i this->tamanhoVetor++ \n",tamanho);
	}

	this->raiz = this->vetorNodulos[0];

	//GERAR CODIGOS
  	char code[0];
  	code[0] = '\0';
  	this->gerarCodigos(this->raiz,code);
}

void huffman::imprimeGerador(){
	printf("%i this->tamanhoVetor \n",this->tamanhoVetor);
	int tam = this->tamanhoVetor;
	for(int i=0;i<=tam;i++){
		printf("%i %i %s\n",this->vetorNodulos[i]->contador,this->vetorNodulos[i]->folhas,this->vetorNodulos[i]->palavra);
	}
}

void huffman::gerarCodigos(noduloArvore *nodulo,char *code){
	if(nodulo != 0){
		if(nodulo->folhas == 1){
			nodulo->code = code;
			printf("%i %i %s %s\n",nodulo->contador,nodulo->folhas,nodulo->palavra,nodulo->code);
			/*;
			int chave = int(nodulo->palavra[0])%tabela.chave;
			listaEncadeada *noduloLista = tabela.myHashing[chave]->pesquisa(nodulo->palavra);
			noduloLista->code = code;
			*/
			return;
		}
		int tamanho = 0;
		for(int i=0;code[i] != '\0';i++){
			tamanho++;
		}
		char *novoCodigoEsq = new char[tamanho+2];
		char *novoCodigoDir = new char[tamanho+2];

		for(int i=0;i<tamanho;i++){
			novoCodigoEsq[i] = code[i];
			novoCodigoDir[i] = code[i];			
		}

		tamanho++;

		novoCodigoEsq[tamanho] = '\0';
		novoCodigoEsq[tamanho-1] = '0';

		novoCodigoDir[tamanho] = '\0';
		novoCodigoDir[tamanho-1] = '1';

		gerarCodigos(nodulo->esq,novoCodigoEsq);
		gerarCodigos(nodulo->dir,novoCodigoDir);
	}
}
/*
char* huffman::pesquisaCodigo(noduloArvore *nodulo, char *palavra){
	if(nodulo != 0){
		if(nodulo->folhas == 1){
			printf("EH FOLHA\n");
			printf("%s %s NODULO\n",nodulo->palavra,nodulo->code);
			if(nodulo->palavra[0] == palavra[0]){
				int ultimaLetra = 0;
				for(int x=0;palavra[x] != '\0' && nodulo->palavra[x] != '\0';x++){
					printf("%i - %c %c\n",x,nodulo->palavra[x],palavra[x]);
					if(nodulo->palavra[x] != palavra[x]){
						break;
					}
					ultimaLetra = x+1;
				}
				printf("%i - %i %i\n",ultimaLetra,nodulo->palavra[ultimaLetra],palavra[ultimaLetra]);
				if(nodulo->palavra[ultimaLetra] == '\0' && palavra[ultimaLetra] == '\0'){
					return nodulo->code;
				}
				return 0;
			}
		}
		printf("NAO FOLHA\n");
		return pesquisaCodigo(nodulo->esq,palavra);
		return pesquisaCodigo(nodulo->dir,palavra);
	}
}
*/