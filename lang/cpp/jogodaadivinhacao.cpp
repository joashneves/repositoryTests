#include<stdio.h>
#include<iostream>

using namespace std; // Faz que não precise declarar `std` antes das funções

int main(){

  std::cout << "***************************************" << std::endl;
  std::cout << "* Boas vindas ao Jogo da Adivinhação! *" << std::endl;
  std::cout << "***************************************" << std::endl;
  
  // Nunca vai mudar o valor no codigo
  const int NUMERO_SECRETO = 42;
  cout << "O numero secreto é " << NUMERO_SECRETO << ". Não conte a ninguem" << endl;

  bool nao_acertou = true;
  int chute;
  int tentativas = 0;
  while(nao_acertou){
    tentativas++;
    cout << "Qual valor do chute? ";
    cin >> chute;
    cout << "Valor do chute : " << chute << endl;

    bool acertou = chute == NUMERO_SECRETO;

    if (acertou){
      cout << "Parabens voce ganhou!";
      nao_acertou = false
    }else if (chute > NUMERO_SECRETO){
      cout << "Chute foi maior que numero secreto";
    }else if ( chute < NUMERO_SECRETO){
      cout << "Chute foi menor que numero secrevo";
    };
  };

}