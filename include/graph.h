class Graph{
public:
    
    Graph(int MAX);
    Graph(){
        isDiagraph = false;
    }
    bool isEmpty();
    bool isDirected();
    void addVertex(int vertex);
    void addEdge(int vertex1, int vertex2, int weight);
    void removeVertex(int removeVertex);
    void removeEdge(int vertex1, int vertex2);
    int numVertices();
    int numEdges();
    int inDegree(int vertex);
    int outDegree(int vertex);
    int degree(int vertex);
    int neighbours(int getVertex);
    bool neighbour(int vertex1, int vertex2);
    void display();
    ~Graph();


private:
    int vertices[20];
    int adjMatrix[20][20];
    int endVertex = 0;
    int MAX = 100;
    bool isDiagraph;
    int numEdge;
};
