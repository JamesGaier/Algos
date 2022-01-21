#include "DisjointSet.hpp"
#include <iostream>

int main()
{
    constexpr auto FOREST_SIZE = 10;
    algo::DisjointSet disjointSet(FOREST_SIZE);

    /*
     *
     * 
        Weighted quick-union with path compression from princeton slides
        3-4 0 1 2 3 3 5 6 7 8 9
        4-9 0 1 2 3 3 5 6 7 8 3
        8-0 8 1 2 3 3 5 6 7 8 3
        2-3 8 1 3 3 3 5 6 7 8 3
        5-6 8 1 3 3 3 5 5 7 8 3
        5-9 8 1 3 3 3 3 5 7 8 3
        7-3 8 1 3 3 3 3 5 3 8 3
        4-8 8 1 3 3 3 3 5 3 3 3
        6-1 8 3 3 3 3 3 3 3 3 3
    */

    disjointSet.unite(3, 4);
    disjointSet.print();
    disjointSet.unite(4, 9);
    disjointSet.print();
    disjointSet.unite(8, 0);
    disjointSet.print();
    disjointSet.unite(2, 3);
    disjointSet.print();
    disjointSet.unite(5, 6);
    disjointSet.print();
    disjointSet.unite(5, 9);
    disjointSet.print();
    disjointSet.unite(7, 3);
    disjointSet.print();
    disjointSet.unite(4, 8);
    disjointSet.print();
    disjointSet.unite(6, 1);
    disjointSet.print();
}

