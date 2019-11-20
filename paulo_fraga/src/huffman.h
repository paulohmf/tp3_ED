#ifndef __HUFFMAN___
#define __HUFFMAN___

#include <cstdio> // em C substituir por #include <stdio.h>
#include "lista.h"
#include "hashing.h"

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

	public:
		noduloArvore *raiz;

		//###########
		huffman();
		~huffman();

		void esvaziaArvore(noduloArvore *raiz);//TO-DO

		void inserirElemento(noduloArvore *nod);//Insere um elemento no vetor gerador
		void imprimeGerador();//Imprime o vetor gerador


		void gerarArvore();//Gera a arvore a partir do vetor de nodulos
		void gerarCodigos(noduloArvore *no,char *code,myHashing *tabela);//Gera os codigos na arvores esalva em um hashing
};
#endif
