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
    g.addEdge(9,12);
    g.addEdge(12,8);
    g.addEdge(15,8);
    g.addEdge(12,16);
    g.addEdge(9,15);
    g.addEdge(8,9);
    g.addEdge(16,9);
    g.addEdge(5,8);
    g.display();

    std::cout << "no of vertices is : " << g.numVertices() << std::endl;
    std::cout << "no of edges is : " << g.numEdges() << std::endl;
    std::cout << "Is Directed? Yes(1), No(0): " << g.isDirected() << std::endl;
    std::cout << "Is Neighbour? Yes(1), No(0): " << g.neighbour(9,12) << std::endl;
    std::cout << "Is Neighbour? Yes(1), No(0): " << g.neighbour(9,16) << std::endl;
    std::cout << "Indegree of 9: " << g.inDegree(9) << std::endl;
    std::cout << "Outdegree of 9: " << g.outDegree(9) << std::endl;
    std::cout << "Degree of 9: " << g.degree(9) << std::endl;
    std::cout << "Indegree of 12: " << g.inDegree(12) << std::endl;
    std::cout << "Outdegree of 12: " << g.outDegree(12) << std::endl;
    std::cout << "Degree of 12: " << g.degree(12) << std::endl;
    std::cout << std::endl;
    g.removeVertex(1);
    g.removeVertex(15);
    g.display();
   
    std::cout << "removing vertex and then adding the edges" << std::endl;
    g.addVertex(233);
    g.addEdge(233,8);
    g.display();
    std::cout << "no of edges is : " << g.numEdges() << std::endl;
    std::cout << "no of vertices is : " << g.numVertices() << std::endl;
    g.removeEdge(9,12);
    
    g.display();
    std::cout << "no of edges is : " << g.numEdges() << std::endl;
    std::cout << "no of vertices is : " << g.numVertices() << std::endl;

    g.neighbours(9);
    g.neighbours(12);
    g.neighbours(233);
    g.neighbours(8);

    int i, e, v;

    std::cout << "Enter the number of the vertex in the graph\n" ;
    std::cin >> v;
    std::cout << "Enter the number of the edges in the graph\n" ;
    std::cin >> e;
	  std::cout<<"The graph has "<< v <<" vertexes." << std::endl;
	  std::cout<<"The graph has "<< e <<" edges." << std::endl;
    
    g.randomGraph(e, v);
}