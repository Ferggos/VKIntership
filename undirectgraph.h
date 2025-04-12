#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>
#include <stdexcept>

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
        void findShortestPaths();
    
    private:
        //Count of vertices
        size_t V = 0;

        //Count of edges
        size_t E = 0;

        int beginVertex; 

        //List of edges
        std::vector<std::list<std::pair<int, int>>> edges;
};
