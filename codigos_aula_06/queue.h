#include "item_type.h"

const int MAX_ITEMS = 100;

class Queue
{
 public :  
  Queue(); // Constructor
  ~Queue(); // Destrutor  
  bool isEmpty() const; //const indica que não altera o atributo da classe
  bool isFull() const;
  void print() const;

  void enqueue(ItemType); //add elemento na fila por parametro
  ItemType dequeue();  
 private:
  int front;
  int back;
  ItemType* structure; 
};
