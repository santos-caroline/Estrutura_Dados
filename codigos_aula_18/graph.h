#ifndef GRAPH_H 
#define GRAPH_H 

#include "queue.h"

class Graph {  //colocaremos as arrestas em matriz de adjacência 
 private:  
  int NULL_EDGE; // Constante para aresta nula.
  int maxVertices; // Número máximo de vértices.  
  int numVertices; // Número de vértices adicionados.
  Vertex* vertices; // Array com todos os vértices que foram alocados (é um vetor(
  int** edges; // Matriz de adjacências ** indica que edges é um ponteiro para ponteiro de inteiros
  bool* marks; // marks[i] marca se vertices[i] foi usado.
  int getIndex(Vertex); 
 public:
  Graph(int max = 50, int null = 0);  // construtor
  ~Graph(); // destrutor

  void addVertex(Vertex);
  void addEdge(Vertex, Vertex, int); //int indica o peso da arresta

  int getWeight(Vertex, Vertex); //retorna o peso
  void getAdjacents(Vertex, Queue&); // retorna os vértices de adjacência
  void clearMarks(); //remove as marcações
  void markVertex(Vertex); //marca os vértices
  bool isMarked(Vertex); //
  void printMatrix();
};

#endif
