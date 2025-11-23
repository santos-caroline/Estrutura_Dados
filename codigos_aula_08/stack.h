#include "node_type.h" //importando o arquivo já definido. Assim a classe Stack já sabe o que é ItemType e o que é NodeType.

class Stack
{
 public:
  Stack();  // Construtor      (inicializa a pilha vazia).  
  ~Stack(); // Destrutor		(libera memória usada pelos nós)
  bool isEmpty() const;			//retorna true se a pilha está vazia.
  bool isFull() const;			//em listas encadeadas, normalmente nunca está cheia (a não ser que acabe a memória)
  void print() const;			

  void push(ItemType);		//insere um elemento no topo da pilha
  ItemType pop();  			//remove e retorna o elemento do topo da pilha.
 private:	
  NodeType* structure; //ponteiro sempre vai apontar para o nó que está no topo
};
