/*
//HASHING SI FUDE
class myHashing{
	public:
		listaEncadeada **hashing;
		int range;
		int chave;

		myHashing();
		~myHashing();

		void imprimeTudo();
		//imprimeUm(int posicao);
};
*/
/*
//########################################################### HASHING SI FUDE
myHashing::myHashing(){
	this->range = 25;
	this->chave = 97;
	for(int i=0;i<=this->range;i++){
		listaEncadeada *novaLista = new listaEncadeada();
		//char palavra[3];
		//palavra[0]=97+i;
		//palavra[1]='\0';
		//novaLista->insert(palavra);
		//printf("%i\n",i);
		//novaLista->imprimeLista();
		this->hashing[i] = novaLista;
		//printf("%i",this->hashing[i]);


		//palavra[0]=65+i;
		//this->hashing[i]->insert(palavra);

		//this->hashing[i]->imprimeLista();

	}
	//printf("\n");
}
myHashing::~myHashing(){
	for(int i=0;i<=this->range;i++){
		delete hashing[i];
	}
}
void myHashing::imprimeTudo(){
	for(int i=0;i<=this->range;i++){
		this->hashing[i]->imprimeLista();
	}
	
}
*/


/* MAIN LISTAS ENCADEADAS
int main() {
  //listaEncadeada *teste = new listaEncadeada();

  long int numeroPalavras;

  scanf("%li ",&numeroPalavras);//OLHO NESSE SCANF

  long int palavrasAtualmente = 0;

  char palavra[63];
  int posicao = 0;
  char letra;
  while(palavrasAtualmente < numeroPalavras){
    scanf("%c",&letra);
    if(letra == ' ' || letra == '\n'){
      palavra[posicao] = '\0';
      printf("%li %s\n",palavrasAtualmente,palavra);//ADD PALAVRA NO HASHING
      //teste->insert(palavra); TESTE EM LISTA ENCADEADA UNICA
      posicao = 0;
      palavrasAtualmente++;
    }else{
      palavra[posicao] = letra;
      posicao++;
    }
  }

  //teste->imprimeLista();

  return 0;
}
*/
/* MAIN TESTE LISTA
int main(){
  listaEncadeada *teste = new listaEncadeada();

  printf("size = %i\n",teste->size());
  printf("vazia %i\n",teste->ehVazia());

  teste->imprimeLista();

  char str[63];

  str[0]='p';
  str[1]='a';
  str[2]='u';
  str[3]='\0';
  printf("%s\n",str);


  nodulo *aux = teste->pesquisa(str);
  printf("%i\n",aux->contador);

  printf("INSERIR O STR\n");
  teste->insert(str);  
  teste->insert(str);
  teste->insert(str);

  str[0]='b';
  str[1]='o';
  str[2]='m';
  teste->insert(str);
  //printf("size = %i\n",teste->size());
  teste->imprimeLista();

  //nodulo pop = teste->pop();
  //printf("%i : %s  CODE : %s\n",pop.contador,pop.palavra,pop.code);

  printf("PESQUISA O STR\n");
  aux = teste->pesquisa(str);
  printf("%s\n",aux->palavra);

  //teste->imprimeLista();

  delete teste;
  return 0;
}
*/
