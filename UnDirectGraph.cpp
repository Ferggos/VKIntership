#include "UnDirectGraph.h"

UnDirectGraph::UnDirectGraph(std::string filepath) {
    std::ifstream in(filepath);

    if (!in) {
        std::cerr << "Error reading file: check the path or file name" << std::endl;
        return;
    }

    if (in.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: File is empty" << std::endl;
        return;
    }

    if (!(in >> V) || V <= 0) {
        std::cerr << "Error: Incorrect number of vertices" << std::endl;
        return;
    }

    if (!(in >> E) || E < 0 || E >(V * (V - 1)) / 2) {
        std::cerr << "Error: Incorrect number of edges" << std::endl;
        return;
    }

    edges.resize(V);

    std::vector<std::pair<int, int>> edgeBuffer;
    std::set<std::pair<int, int>> uniqueEdges;

    int u, v;
    while (edgeBuffer.size() < static_cast<size_t>(E) && (in >> u >> v)) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            std::cerr << "Error: Invalid edge (" << u << ", " << v << ")" << std::endl;
            return;
        }

        if (u > v) std::swap(u, v);
        if (uniqueEdges.find({ u, v }) == uniqueEdges.end()) {
            edgeBuffer.emplace_back(u, v);
            uniqueEdges.insert({ u, v });
        }
        else {
            std::cerr << "Warning: Edge (" << u << ", " << v << ") has already been added" << std::endl;
        }
    }

    if (edgeBuffer.size() < static_cast<size_t>(E)) {
        std::cerr << "Error: File specifies " << E << " edges, but only " << edgeBuffer.size() << " were found" << std::endl;
        return;
    }

    for (const auto& edge : edgeBuffer) {
        addEdge(edge.first, edge.second);
    }

    int beginVertex;
    if (!(in >> beginVertex) || beginVertex < 0 || beginVertex >= V) {
        std::cerr << "Error: Invalid starting vertex: " << beginVertex << std::endl;
        return;
    }

    std::string temp_extra;
    if (in >> temp_extra) {
        std::cerr << "Error: File contains more data than expected (extra edges, numbers, or characters)" << std::endl;
        return;
    }

    findShortestPaths(beginVertex);
}

void UnDirectGraph::addEdge(int u, int v) {

    if (u == v) {
        std::cerr << "Warning: Self-loop at vertex " << u << " is ignored" << std::endl;
        return;
    }

    edges[u].push_back(std::make_pair(v, 1));
    edges[v].push_back(std::make_pair(u, 1));
}


void UnDirectGraph::findShortestPaths(int beginVertex){
    std::vector<int> dist(V, INF);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    pq.push(std::make_pair(0, beginVertex));
    dist[beginVertex] = 0;

    while (!pq.empty()){

        int u = pq.top().second;
        pq.pop();

        std::list<std::pair<int, int>>::iterator it;

        for (it = edges[u].begin(); it != edges[u].end(); ++it){
            int v = (*it).first;
            int weight = (*it).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));
            }
            
        }

    }

    for (const auto& e : dist){
        std::cout << e << std::endl;
    }
}