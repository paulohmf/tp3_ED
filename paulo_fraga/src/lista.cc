#include "lista.h"

//Construtor da lista vazia 
listaEncadeada::listaEncadeada(){
	this->cabeca = new nodulo;//Aloca dinamicamenteo nodulo Cabeca da lista

	this->cabeca->palavra = 0;
	this->cabeca->contador = -1; //Na cabeça o contador é o tamanho da lista
	this->cabeca->code = 0;
	this->cabeca->proximoNodulo = 0; //Lista criada é vazia

}
//O destrutor libera a memoria alocada para a cabeca da lista
listaEncadeada::~listaEncadeada(){
	this->esvaziaLista();//Desaloca toda a memoria que tinha sido alocada pela lista
	delete this->cabeca;
}

//Retorna o valor do contador da cabeça que representa o tamanho da lista
int listaEncadeada::size(){
	return this->cabeca->contador;
}

//Checa se a lista está vazia
bool listaEncadeada::ehVazia(){
	if(this->cabeca->proximoNodulo == 0){
		return true;
	}else{
		return false;
	}
}
//Percorre a lista inteira e imprime seu resultado
void listaEncadeada::imprimeLista(){

	//Caso a lista esteja vazia, imprime lista vazia
	if(this->ehVazia()){
		//printf("(lista vazia)\n");
	}else{
		nodulo *aux = this->cabeca->proximoNodulo;
		//Caso não seja vazia imprime os elementos no estipo "(posicao na lista) -> valor : valor"
		int i=0;
		while(aux->proximoNodulo != 0){
			printf("%i : %s/  CODE : %s\n",aux->contador,aux->palavra,aux->code);
			aux = aux->proximoNodulo;
			i++;
		}
		printf("%i : %s/  CODE : %s\n",aux->contador,aux->palavra,aux->code);
	}
}
//remove o primerio elemento da lista
nodulo listaEncadeada::pop(){
	nodulo *primeiro = this->cabeca->proximoNodulo;

	//A cabeca passa a apontar para o segundo elemento da lista que se tornara o novo primeiro elemento
	this->cabeca->proximoNodulo = primeiro->proximoNodulo;
	//O tamanho da lista é reduzido
	this->cabeca->contador--;

	//O nodulo retirado é salvo numa auxiliar e tem seu apontador zerado
	nodulo retorno;
	retorno.palavra = primeiro->palavra;
	retorno.contador = primeiro->contador;
	retorno.code = primeiro->code;
	retorno.proximoNodulo = 0;

	//A memoria ocupada pelo nodulo é desocupada
	delete primeiro;

	//O nodulo auxiliar é retornado
	return retorno;
}

//Esvazia a lista, desalocando cada espaço de memoria e depois imprime a lista
void listaEncadeada::esvaziaLista(){
	nodulo *NoduloAtual = this->cabeca->proximoNodulo;

	if(this->ehVazia()){
		//printf("(delete - lista vazia)\n");
	}else{
		//Percorre a lista desalocando todos os nodulos da memoria
		for(int i=0; i<=this->cabeca->contador;i++){

			this->cabeca->proximoNodulo = NoduloAtual->proximoNodulo;
			delete NoduloAtual;

			NoduloAtual = this->cabeca->proximoNodulo;
		}
		this->cabeca->contador = -1;
	}
	//Imprime a lista, como está vazia, imprimira "(Lista vazia)"
	//this->imprimeLista();
}

nodulo* listaEncadeada::pesquisa(char* palavra){
	//Percorre a lista, com um nodulo auxiliar, ate que chegue ao final da lista
	nodulo *aux = this->cabeca;
	for(int i=0;i<=this->size();i++){
		aux = aux->proximoNodulo;

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
	}
	return this->cabeca; //nao encontrado


}

//Adiciona um par de valores no final da lista, a função não aceita valores repetidos
void listaEncadeada::insert(char *palavra){
	nodulo *aux = this->pesquisa(palavra);
	//Caso a palavra seja encontrada na lista
	if(aux != this->cabeca){
		//o contador aumenta do nodulo com a palavra aumenta
		aux->contador++;
		return;
	}
	//SE NÃO FOI ENCONTRADO
	//descobro o tamanho da palavra
	int tamanhoPalavra = 1;
	for(int i=0; palavra[i] != '\0';i++){
		tamanhoPalavra++;
	}
	//aloca memoria para esse tamanho de palavra, evitar gastos desnecessários
	char *novaPalavra = new char[tamanhoPalavra+1];
	//copia a palavra recebida (que ocupa 63*tamanho de char na memoria) pro novo espaço alocado que usa o tamanho da palavra
	for(int i=0; i<tamanhoPalavra; i++){
		novaPalavra[i] = palavra[i];
	}

	//aloca um novo nodulo
	nodulo *novo = new nodulo;
	//salva as informações no nodulo
	novo->palavra = novaPalavra;
	novo->contador = 1;
	novo->code = 0;
	//ADICIONA O NOVO NODULO NA PRIMEIRA POSIÇÃO DA LISTA
	//caso a lista esteja vazia
	if(this->ehVazia()){

		this->cabeca->proximoNodulo = novo;
		novo->proximoNodulo = 0;
	//Caso exista algum elemento na lista
	}else{

		//O nodulo novo comeca a apontar pro antigo primeiro elemente (que se torna o segundo elemento)
		novo->proximoNodulo = this->cabeca->proximoNodulo;
		//E a cabeca começa a apontar para o novo nodulo
		this->cabeca->proximoNodulo = novo;
	}
	//o aumento do tamanho da lista é computado na cabeça
	this->cabeca->contador++;
	return;
	
}
