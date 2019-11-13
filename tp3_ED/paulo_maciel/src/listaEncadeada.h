#ifndef __TP1_ED___
#define __TP1_ED___

#include <cstdio> // em C substituir por #include <stdio.h>

//Estrutura da minha lista encadeada
struct nodulo{
	char *palavra;//Armazena um valor
	int contador;//O contador da cabeça é o tamanho da lista, nos outros nodulos ele representa o número de operações necessarias para achar aquele valor
	nodulo *proximoNodulo;//Apontador para o proximo nodulo da lista
};

class listaEncadeada{
	private:
		nodulo *cabeca;
	public:

		listaEncadeada();
		~listaEncadeada();

		//Essa função retorna o primeio nodulo da lista, removendo ele da lista encadeada
		nodulo pop();
		//Retorna o tamanho da lista
		int size();
		//Adiciona um elemente no final da lista
		void push_back(int valor,int contador);
		//Adiciona um elemento no final da lista
		//void push_front(int valor,int contador);

		//Procura e remove a primeira ocorrencia de um valor
		void remover(int valor);
		//Imprime todo o conteudo da lista
		void imprimeLista();

		//Checa se a lista é vazia
		bool ehVazia();
		//Esvazia a lista
		void esvaziaLista();

};

#endif
