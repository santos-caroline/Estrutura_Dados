#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  ItemType character; //guarda o caractere lido da string digitada
  Stack stack;  //é a pilha que vai guardar os símbolos de abertura
  ItemType stackItem; //usado para comparar quando encontramos um símbolo de fechamento.
  
  cout << "Insira uma string." << endl; //input do usuário
  cin.get(character); //lê um caractere por vez (inclusive espaços e quebras de linha).
  
  bool isMatched = true;  //ainda não foi detectado erro
  while (isMatched && character != '\n') //e não chegamos no fim da linha
    {
      if (character == '{' || character== '(' || character==  '['){  
	stack.push(character); //Se encontrar símbolo de abertura, coloca na pilha.
      }
      if(character == '}' || character== ')' || character==  ']'){    
	if (stack.isEmpty()) {
	  isMatched = false; //Se a pilha está vazia, mas aparece um fechamento → erro (mal formada).
	} else {
	  stackItem = stack.pop(); //Senão, tira o topo (pop()) e confere se fecha
	  isMatched = (
		       (character == '}' && stackItem== '{')
		       || (character== ')' && stackItem == '(')
		       || (character== ']' && stackItem == '[')
		       );
	}
      }
      cin.get(character);
    }
      

  if (isMatched && stack.isEmpty() ) { // Se todos os pares casaram e a pilha ficou vazia → expressão bem formada.
    cout << "Bem formada \n";
  } else {
    cout << "Mal formada \n"; // Senão → mal formada.
  }
}

