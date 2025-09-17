#include <stdio.h>
#include <stdlib.h>
#include "main.h";
#include "mapa.h";

MAPA m;

int acabou(){
  return 0;
}

void move(char direcao){
  int x;
  int y;

  for(int i = 0; i < m.linhas; i++){
    for(int j = 0; j < m.colunas; j++){
      if(m.matriz[i][j] == '@'){
        x = i;
        y = j;
        break;
      }
    }
  }

  switch (direcao)
  {
  case 'a':
    m.matriz[x][y-1] = '@';
    break;
    case 'w':
    m.matriz[x-1][y] = '@';
    break;
  case 'd':
    m.matriz[x][y+1] = '@';
  break;
  case 's':
    m.matriz[x+1][y] = '@';/* code */
  break;
  default:
  return;
    break;

    m.matriz[x][y] = '.';

  }

}

int main(){
  
  do{

    char diracao;

    scanf(" %c", &diracao);
    move(diracao);
    lemapa(&m);

    imprimemapa(&m);
  }while (!acabou());
  
  

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

  liberamapa(&m);

}