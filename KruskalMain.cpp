#include "Kruskal.hpp"
#include "Graph.hpp"

/*
 * prints minimum spanning tree
 */
void printMST(const std::vector<algo::Edge> &MST)
{
    std::cout << std::endl;
    std::cout << "[After]" << std::endl;
    std::cout << std::endl;
    for(const auto &edge : MST)
    {
        std::cout << edge.src << " " << edge.dest << " " << edge.weight << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    algo::MatrixGraph<10> G;

    G.addEdge(0, 3, 13);
    G.addEdge(0, 1, 24);
    G.addEdge(0, 2, 13);
    G.addEdge(0, 4, 22);

    G.addEdge(1, 2, 22);
    G.addEdge(1, 3, 13);
    G.addEdge(1, 4, 13);

    G.addEdge(2, 3, 19);
    G.addEdge(2, 4, 14);

    G.addEdge(3, 4, 19);

    G.print();

    printMST(G.kurskal());

    printMST(G.prims());

    G.print();
}
