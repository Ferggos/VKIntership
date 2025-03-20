#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>

#define INF 0x3f3f3f3f

class UnDirectGraph{
    public:
        /*
        Constructor
        Initialized count of Vertices and list of edges
        */
        UnDirectGraph(std::string filepath);

        /* Add edge with vertices {u, v} to list */
        void addEdge(int u, int v);

        /* Realization of Dijkstra Algorithm */
        void findShortestPaths(int beginVertex);
    
    private:
        //Count of vertices
        int V = 0;

        //Count of edges
        int E = 0;

        //List of edges
        std::vector<std::list<std::pair<int, int>>> edges;
};