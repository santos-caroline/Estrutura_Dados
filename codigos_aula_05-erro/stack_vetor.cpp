#include "stack.h"
#include <iostream>
using namespace std;

// Defina o tipo de item e o tamanho máximo da pilha
typedef int ItemType;
const int MAX_ITEMS = 100;

// Implemente o construtor da Stack
Stack::Stack() {
  structure = new ItemType[MAX_ITEMS];
  length = 0;
}


Stack::~Stack() // Destrutor
// Destrutor desaloca a memória alocada dinamicamente
// quando a pilha é destruída, o vetor também é desalocado
{
  delete [] structure;
}

bool  Stack::isEmpty() const
{
  return (length == 0); //verifica se a pilha está vazia
}

bool Stack::isFull() const
{
  return (length == MAX_ITEMS); //verifica se a pilha está cheia
}

void Stack::push(ItemType item)
{
  if (!isFull()){ //verifica se a pilha não está cheia 
    structure[length] = item; // se não estiver cheia, adiciona o item no topo da pilha
    length++;  // e incrementa o tamanho da pilha
  } else {
    throw "Stack is already full!"; //throw lança uma exceção("erro") se a pilha já estiver cheia
  }
}

ItemType Stack::pop()
{
  if (!isEmpty()){ //verifica se a pilha não está vazia
    ItemType aux = structure[length - 1]; //pega o item do topo da pilha e armazene em aux
    length--; //remove um elemento da pilha
    return aux; //retorna o item removido
  } else {
    throw "Stack is empty!";
  }
}

void Stack::print() const
{
  cout << "Pilha = ";
  for (int i = 0; i < length; i++) { //intera os elementos do vetor de 0 até o tamanho atual da pilha
    cout << structure[i]; //imprime os elementos da pilha
  }
  cout << endl; //endl adiciona uma quebra de linha
}
