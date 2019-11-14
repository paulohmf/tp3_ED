#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {
  int n = (argc < 2) ? 5 : atoi(argv[1]);
  printf("%d\n", n);
  srand(time(NULL));
  int p = n/5 + rand()%(3*n/5); // numero de palavras unicas eh aleatorio
                                // entre 20% e 80% de N
  char words[p][64];
  for (int i = 0; i < p; ++i) {
    int len = 1 + rand()%62;
    for (int j = 0; j < len; ++j)
      words[i][j] = 'a' + rand()%('z' - 'a');
    words[i][len] = '\0';
  }
  printf("%s", words[rand()%p]);
  for (int i = 0; i < n; ++i)
    printf(" %s", words[rand()%p]);
  for (int i = 0; i < p; ++i)
    printf("\nq %s", words[i]);
  return 0;
}
