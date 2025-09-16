#include <stdio.h>
#include <stdlib.h>

int linhas;
int colunas;
char** mapa; // matrix de 5x10

int main(){
  
  FILE* f;
  f = fopen('mapa.txt', 'r');
  if(f == 0){
    printf("Erro na leitura do mapa");
    exit(1);
  }

  fscanf(f, "%d %d", &linhas, &colunas );

  // exemplo pratico de alocação de memoria de char de matriz
  mapa = malloc(sizeof(char*) * linhas);
  for(int i = 0; i < linhas; i++){
    mapa[i] = malloc(sizeof(char) * (colunas + 1));
  }

  
  for(int i = 0; i < linhas; i++){
    free(mapa[i]);
    // libera memoria alocado
  }
  free(mapa);


  /*
  // exemplo de alocação de memoria dinamica
  int** v = malloc(sizeof(int*) * 5); // aloca quantos bites o int precisa
  for(int i = 0; i <5; i++){nt** v = malloc(sizeof(int*) * 5); // aloca quantos bites o int precisa
  for(int i = 0; i <5; i++){
    v[i] = malloc(sizeof(int)*10);
  }
  *v = 10; // coloca 10
  printf("inteiro alocado %d\n", *v); // printa o tamanho alocado
  
  for(int i = 0; i <5; i++){
    free(v[i]);
    // libera memoria alocado
  }
  f
    v[i] = malloc(sizeof(int)*10);
  }
  *v = 10; // coloca 10
  printf("inteiro alocado %d\n", *v); // printa o tamanho alocado
  
  for(int i = 0; i <5; i++){
    free(v[i]);
    // libera memoria alocado
  }
  free(v);
  */
  //

  for(int i = 0; i < 5; i++){
    fscanf(f, "%s", mapa[i]);
  }

  
  for(int i = 0; i < 5; i++){
    printf("%d\n", mapa[i]);
  }

  fclose(f);
}