#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const string PALAVRA_SECRETA = "Melancia";

map<char, bool> chutou;
vector<char> chutes_errados;
bool letra_existe(char chute){

  for (char letra : PALAVRA_SECRETA){
    if(chute == letra){
      return true;
    }
  }
  return false;
}

bool nao_acertou(){
  for(char letra : PALAVRA_SECRETA){
    if(!chutou[letra]) return true;
  }
  return false;
}
bool nao_enforcou(){
  return chutes_errados.size() < 5;
}

void le_arquivo(){
  

}

int main(){
  le_arquivo();
  while (nao_acertou() && nao_enforcou())
  {

    cout << "Chutes errados : ";
    for(char letras : chutes_errados){
      cout << letras << " ";
    }
    cout << endl;

    for(char letra : PALAVRA_SECRETA){
      if(chutou[letra]){ 
        cout << letra << " ";
      }else{
        cout << " _ ";
      }
    }
    cout << endl;
    char chute;
    cout << "Seu chute : ";
    cin >> chute;

    cout << "Seu chute foi : " << chute << endl;

    if(letra_existe(chute)){
      cout << "Voce acertou" << endl;
      chutou[chute] = true;
    }else 
    {
      cout << "Voce errou!" << endl;
      chutes_errados.push_back(chute);
    }
    cout << endl;
  }
  
}

