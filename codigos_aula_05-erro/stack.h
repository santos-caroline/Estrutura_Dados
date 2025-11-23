#ifndef STACK_H
#define STACK_H

#include "item_type.h"

const int MAX_ITEMS = 100; // Definindo o tamanho máximo da pilha

class Stack {
 public:
  Stack();   // Construtor  (new)
  ~Stack();   // Destrutor (delete) ~desalocar memória
  bool isEmpty() const;
  bool isFull() const;
  void print() const;
  
  void push(ItemType); //ItemType é o tipo de dado que a pilha vai armazenar
  // Exemplo: void push(int item) ou void push(char item)
  // No caso do exemplo, a pilha armazena inteiros ou caracteres.

  ItemType pop();
 private: // escondido na classe
  int length; // mostra o tamanho da pilha atual
  ItemType* structure;
};

inline Stack::Stack() : length(0), structure(new ItemType[MAX_ITEMS]) {}

inline Stack::~Stack() { delete[] structure; }

#endif // STACK_H
