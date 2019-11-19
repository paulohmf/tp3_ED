#ifndef __HUFFMAN___
#define __HUFFMAN___

#include <cstdio> // em C substituir por #include <stdio.h>
#include "lista.h"

/* apenas para visualização
struct nodulo{
	char *palavra;
	int contador;
	char *code;
	nodulo *proximoNodulo;
};
*/
struct noduloArvore{
	char *palavra;
	int contador;
	char *code;
	int folhas;
	noduloArvore *esq;
	noduloArvore *dir;
};

class huffman{
	private:
		noduloArvore **vetorNodulos;
		int tamanhoVetor;


		noduloArvore *raiz;
	public:

		huffman();
		~huffman();

		//bool ehVazia();
		void esvaziaLista(){};

		void inserirElemento(noduloArvore *nod);

		void imprimeGerador();

		//###########
		void gerarArvore();


		//nodulo pop();



		//nodulo* pesquisa(char *palavra);//DEPENDE DE SIZE()




};
#endif
