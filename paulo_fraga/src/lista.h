#ifndef __TP1_ED___
#define __TP1_ED___

#include <cstdio> // em C substituir por #include <stdio.h>

struct nodulo{
	char *palavra;
	int contador;
	char *code;
	nodulo *proximoNodulo;//Apontador para o proximo nodulo da lista
};

class listaEncadeada{
	private:
		nodulo *cabeca;
	public:

		//###############
		listaEncadeada();
		~listaEncadeada();

		int size();//Retorna o tamanho da lista
		bool ehVazia();//Retorna se a lista é vazia
		void imprimeLista();//Imprime a Lista
		void esvaziaLista();//Esvazia a lista

		nodulo pop();//Remove e retorna o primerio nodulo da lista
		void inserirNodulo(nodulo nod);//Insere um ->NODULO<- no final da lista

		nodulo* pesquisa(char *palavra);//Pesquisa um palavra na lista
		void insert(char *palavra);//Insere uma palavra na lista, se ja existir aumentar seu contador

};
#endif
