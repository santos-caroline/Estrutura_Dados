#ifndef VERTEX_H 
#define VERTEX_H 

#include <iostream>

class Vertex {
 public:
  Vertex(){
    this->nome = ""; //usaremos matrizes de adjacência
  }
  Vertex(std::string nome){
    this->nome  = nome;
  }
  std::string getNome() const { //retorna o nome do vértice
    return nome;    
  }  
 private :
  std::string nome; //essa classe tem somente esse atributo
};

#endif
