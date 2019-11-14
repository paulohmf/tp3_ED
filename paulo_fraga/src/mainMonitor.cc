#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  char word[64];
  for (int i = 0; i < n; ++i) {
    scanf("%s", word);
    // insira/atualize o contador de `word` na estrutura de busca aqui
  }
  char op;  // CUIDADO para não ler o '\n' ao invés da operação
            // o espaço antes do %c está lá pra isso
  while (scanf(" %c %s", &op, word) != EOF) {
    if (op == 'q')
      printf("%d\n", 2);
  }
  return 0;
}
