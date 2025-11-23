#include "node_type.h"

class Queue
{ 
 public:
  Queue(); // Constructor
  ~Queue(); // Destrutor  
  bool isEmpty() const;
  bool isFull() const;
  void print() const;
  
  void enqueue(ItemType);
  ItemType dequeue();
 private:
  NodeType* front; //ponteiro da frente
  NodeType* rear;  //ponteiro de trás
};
