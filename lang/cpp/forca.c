#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h" // declara as funções pelo header 

// VARIAVEL GLOBAL
char palavraSecreta[] = "palavra";

// cria função abertura para ser chamado
void abertura(){
  printf("**********\n");
  printf("    Bem vindos ao jogo da força \n");
   printf("**********\n");

}

void escolhePalavra(){
  FILE* file; // devolve um ponteiro de arquivo
  file = fopen("palavras.txt", "r"); // fopen abre o arquivo como readonly

  int quantidadelinha;
  fscanf(file, "%d", &quantidadelinha);

  srand(time(0));
  int randomico = rand() % quantidadelinha;

  for(int i = 0; i <= randomico; i++){
    fscanf(file, "%s", palavrasecreta);
  }

  fclose(file); // fecha o arquivo

}

int main(){

  int notas[] = {1, 2, 3, 4, 5, 6, 7,  8, 9, 10};

  char mundo[] = "mundo, so que é um texto muito longo para testar quantoas caracters minha array vai aguentar ja que eu não lembro muito bem quantos cabe aqui\0"; // Cria variavel com char

  //sprintf(mundo, "mundo"); // Caso não tivesse criado colocava a palavra mundo dentro do char

  int acertou = 0;
  int enforcou = 0;

  char chutes[26];

  abertura(); // chama função criada
  int tentativas = 0;
  printf("Digite uma letra: \n");
  do{

    for(int _i = 0; _i < strlen(palavraSecreta); _i++){
      int achou = 0;
      for (int j = 0; j < tentativas; j++){
        if(chutes[j] == palavraSecreta[_i]){
          achou = 1;
          break;
        };
      }
      if(achou){
        printf("%c ", palavraSecreta[_i]);
      }else{
        printf("_ ");
      }
    }
    printf("\n");

    char chute;
    scanf(" %c", &chute); // espaço para poder não pegar o enter e guardar ele no buffer e bugar a porra toda

    chutes[tentativas] = chute;
    tentativas++;

  for (int i = 0; i < strlen(palavraSecreta); i++){
    if(palavraSecreta[i] == chute){
      printf("Possição %d tem essa letra \n", i);
    }
  }

  }while(!acertou && !enforcou);

  printf("Ola %s ! \n", mundo);

  printf("notas : %d %d %d \n", notas[1], notas[2], notas[3]);
  return 0;
}