#include "vertex.h"

class Graph{
public:
    // Returns true if the graph is empty, and false otherwise
    bool isEmpty();

    // Returns true if the graph is directed, and false otherwise
    bool isDirected();

    // Inserts a new vertex to the graph
    void addVertex(int vertex);

    //  Adds an edge from vertex1 to vertex2
    void addEdge(int vertex1, int vertex2);

    // Remove a vertex from the graph
    void removeVertex(int removeVertex);

    // Remove an edge from the graph
    void removeEdge(int vertex1, int vertex2);

    // Returns the number of vertices in the graph
    int numVertices();

    // Returns the number of edges in the graph
    int numEdges();

    //  Returns the indegree of a vertex
    int inDegree(int vertex);

    // Returns the outdegree of a vertex
    int outDegree(int vertex);

    // Returns the total degree of a vertex
    int degree(int vertex);

    // Returns the neighbours of a vertex
    Vertex* neighbours(int getVertex);

    // Returns true if vertex2 is a neighbour of vertex1
    bool neighbour(int vertex1, int vertex2);

    void display();

    Graph(bool is_Directed);
    Graph();
    ~Graph();


private:
    Vertex *Head;
    Vertex *Tail;
    bool is_Directed;
};
