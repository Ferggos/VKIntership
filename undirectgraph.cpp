#include "undirectgraph.h"

UnDirectGraph::UnDirectGraph(std::string filepath) {
    std::ifstream in(filepath);

    if (!in) {
        throw std::ios_base::failure("Failed to open file: " + filepath);
    }

    if (in.peek() == std::ifstream::traits_type::eof()) {
        throw std::ios_base::failure("Error: File is empty");
    }

    if (!(in >> V) || V <= 0) {
        throw std::invalid_argument("Error: Invalid number of vertices: must be > 0");
    }

    if (!(in >> E) || E < 0 || E > (V * (V - 1)) / 2) {
        throw std::invalid_argument("Error: Invalid number of edges: must be between 0 and V*(V-1)/2");
    }

    edges.resize(V);

    std::vector<std::pair<int, int>> edgeBuffer;
    std::set<std::pair<int, int>> uniqueEdges;

    int u, v;
    while (edgeBuffer.size() < E && (in >> u >> v)) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            throw std::out_of_range("Error: Invalid edge (" + std::to_string(u) + ", " + std::to_string(v) + ")");
        }

        if (u > v) std::swap(u, v);
        if (uniqueEdges.find({ u, v }) == uniqueEdges.end()) {
            edgeBuffer.emplace_back(u, v);
            uniqueEdges.insert({ u, v });
        } else {
            std::cerr << "Warning: Edge (" << u << ", " << v << ") has already been added" << std::endl;
        }
    }

    if (edgeBuffer.size() < E) {
        throw std::length_error(
            "Error: File specifies " + std::to_string(E) + 
            " edges, but only " + std::to_string(edgeBuffer.size()) + " were found"
        );
    }

    for (const auto& edge : edgeBuffer) {
        addEdge(edge.first, edge.second);
    }

    if (!(in >> beginVertex)) {
        throw std::invalid_argument("Error: Could not read starting vertex");
    }
    if (beginVertex < 0 || beginVertex >= V) {
        throw std::out_of_range("Error: Invalid starting vertex: " + std::to_string(beginVertex));
    }

    std::string temp_extra;
    if (in >> temp_extra) {
        throw std::logic_error("Error: File contains more data than expected (extra edges, numbers, or characters)");
    }

}


void UnDirectGraph::addEdge(int u, int v) {

    if (u == v) {
        std::cerr << "Warning: Self-loop at vertex " << u << " is ignored" << std::endl;
        return;
    }

    edges[u].push_back(std::make_pair(v, 1));
    edges[v].push_back(std::make_pair(u, 1));
}


void UnDirectGraph::findShortestPaths(){
    std::vector<int> dist(V, INF);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    pq.push(std::make_pair(0, beginVertex));
    dist[beginVertex] = 0;

    while (!pq.empty()){

        int u = pq.top().second;
        pq.pop();

        for (auto it = edges[u].begin(); it != edges[u].end(); ++it){
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
