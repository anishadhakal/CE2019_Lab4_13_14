class Graph{
public:

    Graph(int MAX);
    Graph(){
        this->isDiagraph = false;
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }
    bool isEmpty();
    bool isDirected();
    void addVertex(int vertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int removeVertex);
    void removeEdge(int vertex1, int vertex2);
    int numVertices();
    int numEdges();
    int inDegree(int vertex);
    int outDegree(int vertex);
    int degree(int vertex);
    void neighbours(int getVertex);
    bool neighbour(int vertex1, int vertex2);
    void display();
    void randomGraph(int noofEdge, int noofVertex);
    ~Graph();


private:
    int vertices[20];
    int adjMatrix[20][20];
    int numVertex = 0;
    int MAX = 100;
    bool isDiagraph;
    bool checkVertex(int &index, int vertex);
};
