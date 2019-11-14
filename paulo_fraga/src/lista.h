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

		int size();
		bool ehVazia();
		void imprimeLista();//DEPENDE DE EHVAZIA()

		nodulo pop();

		void esvaziaLista();//DEPENDE DE EHVAZIA()

		nodulo* pesquisa(char *palavra);//DEPENDE DE SIZE()

		void insert(char *palavra);//DEPENDE DE PESQUISA() E EHVAZIA()

};
#endif
