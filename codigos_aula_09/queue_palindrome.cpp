#include "queue.h"
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
  bool palindrome = true; //guarda se a string ainda é palíndromo ~~começa verdadeiro
  
  char character;
  char stackChar; //pilha para armazenar caracteres.
  char queueChar; //fila para armazenar os mesmos caracteres.
  
  Stack stack;
  Queue queue;    
  cout << "Adicione uma string." << endl;    //Lê cada caractere digitado.
  cin.get(character); //Insere o caractere na pilha e na fila.
  
  while (character != '\n') { //A leitura para quando o usuário aperta Enter (\n).
      stack.push(character);  //Remove um caractere do topo da pilha (último inserido).
      queue.enqueue(character); //Remove um caractere da frente da fila (primeiro inserido).
      cin.get(character);
    }
  while (palindrome && !queue.isEmpty()) //para fila e pilha não vazias
    {
      stackChar = stack.pop();
      queueChar = queue.dequeue();
      if (stackChar != queueChar) //e forem diferentes → não é palíndromo.
	palindrome = false;
    }
  if (palindrome) //Se iguais → continua.
    cout << "String é Palindrome" << endl;
  else
    cout << "String não é palindrome" << endl;
  return 0; 
}
