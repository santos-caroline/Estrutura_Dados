#include <iostream>   // biblioteca padrão para entrada e saída
#include "graph.h"    // implementação da classe Graph (grafo)
#include "stack.h"    // implementação da classe Stack (pilha)
#include "queue.h"    // implementação da classe Queue (fila)

using namespace std;

// =============================================================
// Função para busca em profundidade (DFS)
// =============================================================
void depthFirstSearch(Graph& graph, Vertex origem, Vertex destino) {
  Stack  vertexStack;   // pilha para armazenar vértices a visitar
  bool found = false;   // indica se o destino foi encontrado
  Vertex vertex;        // variável auxiliar para o vértice atual

  graph.clearMarks();   // limpa marcações de vértices visitados
  vertexStack.push(origem); // empilha o vértice inicial

  do {
    vertex = vertexStack.pop(); // pega o próximo vértice da pilha

    // se o vértice atual é o destino, encontrou o caminho
    if (vertex.getNome() == destino.getNome())  {
      cout << "Encontrado: " << vertex.getNome() << ";" << endl;
      found = true;
    } else {
      // se ainda não foi visitado
      if (!graph.isMarked(vertex)) {
        graph.markVertex(vertex); // marca como visitado
        cout << "Visitando: " << vertex.getNome() << endl;

        Queue adjacents;              // fila auxiliar para adjacentes
        graph.getAdjacents(vertex, adjacents); // pega vizinhos

        // percorre todos os adjacentes
        while (!adjacents.isEmpty()) {
          Vertex adjacent = adjacents.dequeue();

          // só empilha se ainda não foi visitado
          if (!graph.isMarked(adjacent)) {
            cout << "Empilhando: " << adjacent.getNome() << endl;             
            vertexStack.push(adjacent);
          }
        }
      }
    }
  } while (!vertexStack.isEmpty() && !found); // continua até achar ou esvaziar a pilha

  if (!found) {
    cout << "Caminho não encontrado." << endl;
  }
}

// =============================================================
// Função para busca em largura (BFS)
// =============================================================
void breadthFirstSearch(Graph& graph, Vertex origem, Vertex destino) {
  Queue vertexQueue;   // fila para armazenar vértices a visitar
  bool found = false;  // indica se encontrou o destino
  Vertex vertex;

  graph.clearMarks();          // limpa marcações de vértices
  vertexQueue.enqueue(origem); // insere o vértice inicial na fila

  do {
    vertex  = vertexQueue.dequeue(); // retira o próximo da fila

    // se achou o destino
    if (vertex.getNome() == destino.getNome()) {
      cout << "Encontrado: " << vertex.getNome() << ";" << endl;
      found = true;
    } else {
      // se ainda não foi visitado
      if (!graph.isMarked(vertex)) {
        graph.markVertex(vertex); // marca como visitado
        cout << "Visitando: " << vertex.getNome() << endl;

        Queue adjacents; 
        graph.getAdjacents(vertex, adjacents); // obtém vizinhos

        // percorre adjacentes
        while (!adjacents.isEmpty()) {
          Vertex adjacent = adjacents.dequeue();

          // só enfileira se ainda não foi visitado
          if (!graph.isMarked(adjacent)) {
            cout << "Enfileirando: " << adjacent.getNome() << endl;               
            vertexQueue.enqueue(adjacent);
          }	    
        }
      }
    }
  } while (!vertexQueue.isEmpty() && !found); // continua até achar ou fila esvaziar

  if (!found)
    cout << "Caminho não encontrado." << endl;
}

// =============================================================
// Função principal
// =============================================================
int main() {
  Graph graph;  // cria o grafo

  // Criação dos vértices
  Vertex a = Vertex("a");
  Vertex b = Vertex("b");
  Vertex c = Vertex("c");
  Vertex d = Vertex("d");
  Vertex e = Vertex("e");
  Vertex f = Vertex("f");
  Vertex g = Vertex("g");
  Vertex h = Vertex("h");
  Vertex i = Vertex("i");

  // Adiciona vértices ao grafo
  graph.addVertex(a);
  graph.addVertex(b);
  graph.addVertex(c);
  graph.addVertex(d);
  graph.addVertex(e);
  graph.addVertex(f);
  graph.addVertex(g);
  graph.addVertex(h);
  graph.addVertex(i);
  
  // Adiciona arestas (com peso) entre os vértices
  graph.addEdge(a, b, 2);
  graph.addEdge(a, g, 4);
  graph.addEdge(b, c, 4);
  graph.addEdge(b, d, 2);
  graph.addEdge(b, g, 6);
  graph.addEdge(c, d, 3);
  graph.addEdge(d, e, 5);
  graph.addEdge(d, f, 3);
  graph.addEdge(e, f, 3);
  graph.addEdge(e, h, 4);
  graph.addEdge(f, g, 5);
  graph.addEdge(f, h, 4);
  graph.addEdge(g, i, 2);
  graph.addEdge(h, i, 3);

  // imprime a matriz de adjacência do grafo
  graph.printMatrix(); 

  /******************************************************************
    Obtendo os vértices adjacentes a um dado nó (exemplo com 'a')
  *******************************************************************/
  Queue adjacents;
  graph.getAdjacents(a, adjacents);
  while (!adjacents.isEmpty()) {
    cout << adjacents.dequeue().getNome() << ", ";
  }
  cout << endl;

  /******************************************************************
    Chamada de DepthFirstSearch (DFS) procurando caminho de a -> h
  *******************************************************************/
  depthFirstSearch(graph, a, h);

  /******************************************************************
    Chamada de BreadthFirstSearch (BFS) procurando caminho de a -> h
  *******************************************************************/
  breadthFirstSearch(graph, a, h);

  std::cout << "Saindo" << std::endl;
}
