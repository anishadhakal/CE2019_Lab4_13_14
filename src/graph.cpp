#include "../include/graph.h"
#include <iostream>

Graph::Graph(int MAX) : MAX(MAX) {
    this->isDiagraph = false;
    std::cout << "Want to make graph directed? Press(1). Press(0) to make undirected." << std::endl;
    std::cin >> isDiagraph;
    this->numVertex = 0;
    for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++){
                adjMatrix[i][j] = 0;
            }
        }
}

bool Graph::isEmpty(){
    return this->numVertex == 0;
}

bool Graph::isDirected(){
    return isDiagraph;
}

void Graph::addVertex(int vertex){
    int index;
    bool found = checkVertex(index, vertex);
    if(!found){
        vertices[this->numVertex] = vertex;
       
       for(int i = 0 ; i <= numVertex ; i++){
            adjMatrix[this->numVertex][i] = 0;
            adjMatrix[i][this->numVertex] = 0;
        }
        this->numVertex++;
        std::cout << "Added Vertex sucessfully " << vertex << std::endl;
    }
    else{
        std::cout <<"Vertex already present in the graph" << std::endl;
    }
}

void Graph::display(){
    std::cout << "no. of Vertices: " << numVertex << std::endl;
    for(int i = 0; i < numVertex; i++) {
        std::cout << vertices[i] << ": " << "\t";
        for(int j = 0; j < numVertex; j++) {
            std::cout << adjMatrix[i][j] << "\t";
      }
      std::cout << std::endl;
   }
}

int Graph::inDegree(int vertex){
    int index, counter=0;
    bool found = checkVertex(index, vertex);
    if(found){
        for(int i = 0 ;i < numVertex; i++){
        if(adjMatrix[i][index] != 0 && i != index){
            counter++;
        }
    }
    return counter;
    }
    else{
        std::cout << "vertex not found" << std::endl;
    }
}

int Graph::outDegree(int vertex){
    int index, counter=0;
    bool found = checkVertex(index, vertex);
    if(found){
        if(!isDirected()){
            counter = inDegree(vertex);
        }
        else{ 
            for(int i = 0 ;i < numVertex; i++){
            if(this->adjMatrix[index][i] != 0  && i != index){
                counter++;
            }
        }
    }
    return counter;
    }
     else{
        std::cout << "vertex not found" << std::endl;
    }
}

int Graph::degree(int vertex){
     if(!isDirected()){
       return outDegree(vertex);
    }
    else{
        return inDegree(vertex) + outDegree(vertex);
    }
}


void Graph::addEdge(int vertex1, int vertex2){
    int index1, index2;
    if(checkVertex(index1, vertex1) && checkVertex(index2, vertex2)){
        if(!isDirected())
        {
            this->adjMatrix[index1][index2]=1;
            this->adjMatrix[index2][index1]=1;
            std::cout << "Edge added successfully. (" << vertex1 << "," << vertex2 << ")" << std::endl;
        }
        else{
            this->adjMatrix[index1][index2]=1;
            std::cout << "Edge added successfully. (" << vertex1 << "," << vertex2 << ")" << std::endl;
        }
    }
    else{
        std::cout << "Cannot add edge. Either of the provided vertex is not in the graph." << std::endl;
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

// helper function to check if vertexExists
bool Graph::checkVertex(int &vertexIndex, int vertex){
    for (int i = 0; i < numVertex; i++)
	{
		if (this->vertices[i] == vertex)
		{
            vertexIndex = i;
			return true;
		}
	}
	return false;
}

bool Graph::neighbour(int vertex1, int vertex2)
{
    int index1, index2;
    if(checkVertex(index1,vertex1) && checkVertex(index2,vertex2)){
        if(!isDirected()){
            return (adjMatrix[index1][index2] != 0)  && (adjMatrix[index2][index1] != 0);
        }
        else{
            return (adjMatrix[index1][index2] != 0);
        }
    }
    else{
        return (adjMatrix[index1][index2] == 0);
    }
}

void Graph::removeVertex(int removeVertex){
    int index;
    bool found = checkVertex(index, removeVertex);
    if(found){
        for(int i=0;i<numVertex;i++)
        {
            this->adjMatrix[i][index]=0;
            this->adjMatrix[index][i]=0;
        }
        vertices[index]=0;
        for( int j=index;j<numVertex;j++)
        {
            this->vertices[j]=this->vertices[j+1];
            for(int i = 0; i< numVertex; i++) {
                this->adjMatrix[j][i] = adjMatrix[j+1][i];
            }
        }
        numVertex--;
        std::cout << "Vertex deleted successfully. : " << removeVertex << std::endl;
    }
    else{
        std::cout << "Given vertex not found in graph" << std::endl;
    }
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

Graph::~Graph(){
}
