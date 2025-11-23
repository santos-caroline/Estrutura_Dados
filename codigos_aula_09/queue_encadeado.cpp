#include <cstddef>         // Para NULL.
#include <new>             // Para bad_alloc.
#include "queue.h"  
#include <iostream>
using namespace std;


Queue::Queue()
{
  front = NULL; //inicializando ponteiros como nulo
  rear = NULL; 
}

Queue::~Queue()
{
  NodeType* tempPtr; 
  while (front != NULL) {
      tempPtr = front; //ponteiro temporário salva o front (frente)
      front = front->next;   //atualizo o front para apontar para o próximo elemento 
      delete tempPtr; //desaloco o ponteiro temporário
    }
  rear = NULL; 
}


bool Queue::isFull() const //m uma fila encadeada, só fica cheia se acabar a memória.
{
  NodeType* location; //o código tenta alocar um novo nó:
  try {
      location = new NodeType; //Se conseguir → não está cheia.
      delete location;
      return false;
  } catch(std::bad_alloc exception) {   //memória acabou → cheia.
    return true;
  }
}

bool Queue::isEmpty() const
{
  return (front == NULL); //fila vazia já que não tem o primeiro elemento
}

void Queue::enqueue(ItemType newItem)
{
  if (!isFull()) {
    NodeType* newNode; 
    newNode = new NodeType;
    newNode->info = newItem;
    newNode->next = NULL;
    if (rear == NULL)  		// fila estava vazia
      front = newNode;
    else					// liga o antigo último com o novo
      rear->next = newNode;
    rear = newNode;			// atualiza o ponteiro para o novo último
  } else {
    throw "Queue is already full!";           
  }
}

ItemType Queue::dequeue()
{
  if (!isEmpty()) {
    NodeType* tempPtr;
    tempPtr = front;
    ItemType item = front->info;     
    front = front->next;
    if (front == NULL) 	// fila ficou vazia após remover
      rear = NULL;
    delete tempPtr;		// libera memória
    return item;		// devolve o valor
  } else {
    throw "Queue is empty!";
  }    
}

void Queue::print() const
{
  NodeType* tempPtr = front;
  while (tempPtr != NULL) //fila não vazia
    {
      cout << tempPtr->info; //imprime a info
      tempPtr = tempPtr->next;	//aponta para o próximo
    }
  cout << endl;
}
