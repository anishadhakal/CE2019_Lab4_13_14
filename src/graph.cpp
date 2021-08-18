#include "../include/graph.h"
#include <iostream>

Graph::Graph(int MAX) : MAX(MAX) {
    this->isDiagraph = false;
    std::cout << "Want to make graph directed? Press(1). Press(0) to make undirected." << std::endl;
    std::cin >> isDiagraph;
    this->endVertex = 0;
    for (int i = 0; i < MAX; i++)
      for (int j = 0; j < MAX; j++)
        adjMatrix[i][j] = 0;
}

bool Graph::isEmpty(){
    return endVertex == 0;
}

bool Graph::isDirected(){
    return isDiagraph;
}

void Graph::addVertex(int vertex){
    vertices[this->endVertex] = vertex;
    this->endVertex++;
    std::cout << "Added Vertex sucessfully " << vertex << std::endl;
}

void Graph::display(){
    int i, j;
   for(i = 0; i < endVertex; i++) {
      for(j = 0; j < endVertex; j++) {
            std::cout << adjMatrix[i][j] << " ";
      }
      std::cout << std::endl;
   }
}

int Graph::inDegree(int vertex){
    int counter=0;
    for(int i = 0 ;i < MAX; i++){
        if(adjMatrix[i][vertex] != 0 && i != vertex){
            counter++;
        }
    }
    return counter;
}

int Graph::outDegree(int vertex){
    int counter=0;
    for(int i = 0 ;i < MAX; i++){
        if(adjMatrix[i][vertex] != 0 && i != vertex){
            counter++;
        }
    }
    return counter;
}

// TODO:: add edge, neighbour, neighbours, degree, remove vertex, removeEdge etc/
void Graph::addEdge(int vertex1, int vertex2, int weight){
    
}

Graph::~Graph(){

}