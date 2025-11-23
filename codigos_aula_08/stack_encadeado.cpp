#include "stack.h"
#include <cstddef> // Para funcionar o NULL
#include <new>

#include <iostream>
using namespace std;

Stack::Stack(){
  structure = NULL; //não aponta para nada no momento
}

Stack::~Stack(){
  NodeType* tempPtr; //variavel tempPtr = ponteiro temporario; 
  while (structure != NULL) { 
    tempPtr = structure; //salvo quem eu vou deletar
    structure  = structure -> next; //structure vai apontar para o próximo elemento 
    delete tempPtr; //agr podemos deletar o tempPtr (já estoubapontando para o próximo elemento)
  } //de stackaté aqui é só o *destrutor*
}

bool Stack::isEmpty() const {
  return (structure == NULL); //se o ponteiro inicial aponta para nulo(null) = a pilha está vazia
}

/*
  Aqui eu simplesmente verifico se o usuário possui memória
  disponível para alocar um novo elemento.
*/
bool Stack::isFull() const {
  NodeType* location;
  try { //verificação de memória cheia
    location = new NodeType; //tentativa de alocar um novo nodetype (ponteiro)
    delete location; //tentativa de  deletar nodetype ~~verificando se dá erro
    return false; //indica que posso alocar mais um na memória
  } catch(std::bad_alloc exception){ //erro
    return true; // avisa o erro
  }  
}

/*
  Adicionar um novo item no topo da pilha. O nó que acabamos de criar
  deve apontar para quem estava no topo da pilha e o ponteiro
  structure deverá apontar para o novo nó.
 */
void Stack::push(ItemType item){ //ponteiro no topo da pilha ~~push insere novo elemento
  if (!isFull()){
    NodeType* location; //inicializando location ~~ colocar nodetype em qq lugar da memória
    location = new NodeType;
    location->info = item; //no campo info coloca-se a inf para o usuario 
    location->next = structure; //vai apontar para o topo da pilha
    structure = location; // pq agr o topo da pilha é o location
  } else {
    throw "Stack is already full!"; // erro se a memória estiver cheia
  }
}

/*
  Devolve o objeto que está no topo da pilha. 
 */
ItemType Stack::pop(){
  if (!isEmpty()) {
    NodeType* tempPtr; //ponteiro temporário
    tempPtr = structure; //aponta para o topo da pilha
    ItemType item = structure->info; 
    structure        = structure->next; //ponteiro vai apontar para o segundo elemento
    delete tempPtr; //desaloco memória
    return item; //retorno o item salvo 'que estava no topo'
  } else {
    throw "Stack is empty!"; //caso erro
  }
}

void Stack::print() const //const == structure não pode ser mexido
{
  NodeType* tempPtr = structure; //structure é o topo da pilha
  while (tempPtr != NULL) {
    cout << tempPtr->info; //imprimo a info
    tempPtr  = tempPtr->next; //faço tempPtr apontar para o próximo
  }  
  cout << endl;
}

