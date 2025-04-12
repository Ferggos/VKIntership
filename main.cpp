#include <iostream>
#include <exception>
#include "undirectgraph.h"

int main() {
    try {
        UnDirectGraph graph("graph.txt");
        graph.findShortestPaths();
    } 
    catch (const std::ios_base::failure& e) {
        std::cerr << "I/O error: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
    catch (const std::length_error& e) {
        std::cerr << "Length error: " << e.what() << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}
