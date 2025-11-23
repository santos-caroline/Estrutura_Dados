#include "stack.h"
#include "item_type.h" // Ensure this header is included for ItemType definition
#include "stack_vetor.cpp" // Include the implementation of the Stack class
#include <iostream>

using namespace std;


int main() {
  ItemType character;
  Stack stack; // Cria uma pilha do tipo Stack
  ItemType stackItem;
  
  cout << "Adicione uma String." << endl;     
  cin.get(character);
  while (character != '\n') //vefifica se o caracter lido é diferente de '\n' (quebra de linha)
    {
      stack.push(character); //adiciona o caracter lido na pilha
      cin.get(character);
    }
  
  while (!stack.isEmpty()) //enquanto a pilha não estiver vazia 
    {
      stackItem = stack.pop(); //remove o item do topo da pilha e armazena em stackItem
      cout << stackItem; //imprime o item removido
    }
  
  cout << endl;
}
