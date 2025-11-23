#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
  front = 0;
  back  = 0;
  structure = new ItemType[MAX_ITEMS]; //aloca memória para a fila
}

Queue::~Queue()
{
  delete [] structure; //libera a memória alocada para a fila
}


bool Queue::isEmpty() const
{
  return (front == back); //se frente e trás forem iguais, a fila está vazia
}

bool Queue::isFull() const
{
  return (back - front == MAX_ITEMS); //moastra o número de elementos na fila
  //se o número de elementos for igual ao máximo, a fila está cheia
}

void Queue::enqueue(ItemType item)
{
  if (!isFull()){
    structure[back % MAX_ITEMS] = item; //como a fila é circular, usamos o operador módulo
    //para garantir que o índice não ultrapasse o tamanho máximo
    back++; //incrementa para apontar para o próximo elemento
  } else {
    throw "Queue is already full!";
  }
}

ItemType Queue::dequeue()
{
  if (!isEmpty()){
    front++; //frente da fila
    return structure[(front-1) % MAX_ITEMS]; // retorna o elemento na frente da fila
    //usando o operador módulo para garantir que o índice não ultrapasse o tamanho máximo
  } else {
    throw "Queue is empty!";
  }
}

void Queue::print() const
{
  cout << "Fila = ";
  for (int i = front; i < back; i++) {
    cout << structure[i % MAX_ITEMS];
  }
  cout << endl;
}
