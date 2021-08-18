#include "../include/graph.h"
#include <iostream>

int main(){
    Graph g(5);
    std::cout << "Is Empty? Yes(1), No(0): " << g.isEmpty() << std::endl;
    g.addVertex(9);
    g.addVertex(12);
    g.addVertex(15);
    g.addVertex(8);
    g.addVertex(16);
    std::cout << "Is Empty? Yes(1), No(0): " << g.isEmpty() << std::endl;
    g.addEdge(9,12,1);
    g.addEdge(12,8,1);
    g.addEdge(15,8,1);
    std::cout << "Is Directed? Yes(1), No(0): " << g.isDirected() << std::endl;


    g.display();
}