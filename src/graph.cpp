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
void Graph::neighbours(int getVertex)
{
    int counter = 0;
    int vert;
    if (checkVertex(vert, getVertex))
    {
        std::cout<<"The neighbours of vertex " << getVertex << " is/are: ";
        for (int i = 0; i <= numVertex; i++)
        {
         if (this->adjMatrix[vert][i] == 1)
        {
                std::cout << vertices[i] << ',';
                counter++;
            }
        }
        std::cout << std::endl;
    }
    if(counter == 0){
        std::cout << "Neighbours does not exist." << std::endl;
    }
}

void Graph::removeEdge(int vertex1, int vertex2)
{
    int index1,index2;
    
    if(checkVertex(index1,vertex1) && checkVertex(index2,vertex2)){
        if(!isDirected())
        {
            this->adjMatrix[index1][index2]=0;
            this->adjMatrix[index2][index1]=0;
            std::cout << "Edge deleted successfully. (" << vertex1 << "," << vertex2 << ")" << std::endl;
        }
        else{
            this->adjMatrix[index1][index2]=0;
            std::cout << "Edge deleted successfully. (" << vertex1 << "," << vertex2 << ")" << std::endl;
        }
    }
    else{
        std::cout << "Edge between vetrex " << vertex1 << " and vertex " << vertex2 << " does not exists." << std::endl;
    }
    
}

int Graph::numEdges(){
    int edges = 0;
        for (int i = 0; i < numVertex; i++)
        {
            for (int j = 0; j < numVertex; j++)
            {
                if (this->adjMatrix[i][j] == 1)
                {
                    edges++;
                }
            }
        }
        return edges;
}

int Graph::numVertices(){
    return this->numVertex;
}
void Graph::randomGraph(int noofEdge, int noofVertex)
{
   int i, j, edge[noofEdge][2], count;
   i = 0;
   
   while(i < noofEdge)
   {
      edge[i][0] = rand()%noofVertex+1;
      edge[i][1] = rand()%noofVertex+1;
     
      if(edge[i][0] == edge[i][1])
         continue;
      else
      {
         for(j = 0; j < i; j++)
         {
            if((edge[i][0] == edge[j][0] &&
            edge[i][1] == edge[j][1]) || (edge[i][0] == edge[j][1] &&
            edge[i][1] == edge[j][0]))
            i--;
         }
      }i
      ++;
   }
   std::cout<<"\nThe generated random graph is: ";
   for(i = 0; i <noofVertex; i++)
   {
      count = 0;
      std::cout<<"\n\t"<<i+1<<"-> { ";
      for(j = 0; j < noofEdge; j++)
      {
         if(edge[j][0] == i+1)
         {
            std::cout<<edge[j][1]<<" ";
            count++;
         } else if(edge[j][1] == i+1)
         {
            std::cout<<edge[j][0]<<" ";
            count++;
         } else if(j== noofEdge-1 && count == 0)
         std::cout<<"Vertex not"; 
      }
      std::cout<<" }";
   }
}
