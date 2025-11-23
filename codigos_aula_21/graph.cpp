#include <iostream>     // Biblioteca padrão para entrada e saída
#include "graph.h"      // Cabeçalho que contém a declaração da classe Graph

// =========================
// Construtor da classe Graph
// =========================
Graph::Graph(int max, int null_edge) {
  NULL_EDGE   = null_edge;            // Valor usado para indicar ausência de aresta
  maxVertices = max;                  // Quantidade máxima de vértices que o grafo suporta
  numVertices = 0;                    // Número de vértices atualmente adicionados
  vertices = new Vertex[maxVertices]; // Array dinâmico de vértices
  marks = new bool[maxVertices];      // Array de marcações (visitado ou não em percursos)
  edges = new int*[maxVertices];      // Ponteiro para as linhas da matriz de adjacências
  
  // Aloca cada linha da matriz de adjacências
  for (int row = 0; row < maxVertices; row++)
    edges[row] = new int[maxVertices];  
  
  // Inicializa toda a matriz com NULL_EDGE (sem arestas)
  for (int row = 0; row < maxVertices; row++)
    for (int col = 0; col < maxVertices; col++)
      edges[row][col] = NULL_EDGE;
}

// =========================
// Destrutor
// =========================
Graph::~Graph() {
  delete [] vertices;   // Libera array de vértices
  delete [] marks;      // Libera array de marcações
  for (int row = 0; row < maxVertices; row++){
    delete [] edges[row]; // Libera cada linha da matriz
  }
  delete [] edges;        // Libera ponteiro principal da matriz
}

// =========================
// Retorna o índice de um vértice no array
// =========================
int Graph::getIndex(Vertex vertex) {
  int index = 0;
  // Procura o vértice pelo nome até encontrar
  while (!(vertex.getNome() == vertices[index].getNome())){
    index++;
  }
  return index;
}

// =========================
// Adiciona um vértice no grafo
// =========================
void Graph::addVertex(Vertex vertex){
  vertices[numVertices] = vertex; // Coloca no array
  numVertices++;                  // Incrementa a quantidade
}

// =========================
// Adiciona uma aresta com peso entre dois vértices
// =========================
void Graph::addEdge(Vertex fromVertex,
		    Vertex toVertex,
		    int weight){
  int row = getIndex(fromVertex); // Índice do vértice origem
  int col = getIndex(toVertex);   // Índice do vértice destino

  edges[row][col] = weight;       // Cria aresta dirigida com peso

  // Se fosse grafo não-direcionado, descomente a linha abaixo:
  // edges[col][row] = weight; 
}

// =========================
// Retorna o peso de uma aresta
// =========================
int Graph::getWeight(Vertex fromVertex,
		     Vertex toVertex){
  int row = getIndex(fromVertex);
  int col = getIndex(toVertex);
  return edges[row][col];
}

// =========================
// Retorna os vértices adjacentes a um vértice dado
// =========================
void Graph::getAdjacents(Vertex vertex,
			 Queue &adjVertices){
  int fromIndex = getIndex(vertex); // Índice do vértice atual
  for (int toIndex = 0; toIndex < numVertic
