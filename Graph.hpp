#pragma once
#include <array>
#include <functional>
#include <set>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
#include "Printable.hpp"
#include "DisjointSet.hpp"

namespace algo
{

class Graph
{
public:
    virtual void addEdge(int src, int dest, int weight) = 0;
    virtual void removeEdge(int src, int dest) = 0;
};

struct Edge
{
    int src, dest, weight;
};

template <int N>
class MatrixGraph : public Graph, public Printable
{
public:
    MatrixGraph()
    {
        for(auto i = 0; i < N; ++i)
        {
            for(auto j = 0; j < N; ++j)
            {
                m_matrix[i][j] = -1;
            }
        }

    }

    void addEdge(int src, int dest, int weight) override
    {
        m_matrix[src][dest] = weight; 
        m_matrix[dest][src] = weight; 

        Edge edge;
        edge.weight = weight;
        edge.src = src;
        edge.dest = dest;
        m_edges.push_back(edge);
    }

    void removeEdge(int src, int dest) override
    {
       m_matrix[src][dest] = -1; 
       m_matrix[dest][src] = -1; 

       for(auto &edge : m_edges)
       {
            if(edge.src == src && edge.dest == dest)
            {
               edge.weight = -1; 
            }
       }
    }

    std::vector<Edge> kurskal()
    {
       DisjointSet set(N);
       std::vector<Edge> result(m_edges.begin(), m_edges.end());
       std::sort(result.begin(), result.end(),
        [] (const Edge &lhs, const Edge &rhs)
        {
            return lhs.weight < rhs.weight;
        });

       std::vector<Edge> toDel;
       for(const auto &edge : result)
       {
            if(!set.find(edge.src, edge.dest))
            {
                set.unite(edge.src, edge.dest);
            }
            else
            {
                std::cout << "[Remove]" << std::endl;
                std::cout << edge.src << " " << edge.dest << std::endl;
                std::cout << std::endl;
                toDel.push_back(edge);
            }
       }

       std::cout << std::endl;
       std::cout << "[Before]" << std::endl;
       std::cout << std::endl;
       for(const auto &edge : result)
       {
            std::cout << edge.src << " " << edge.dest << std::endl;
       }

       for(const auto &edge : toDel)
       {
           auto itr = std::find_if(result.begin(), result.end(), [&](const Edge &e)
           {
               if(e.src == edge.src
               && e.dest == edge.dest
               && e.weight == edge.weight)
               {
                   return true;
               }
               return false;
           });
           result.erase(itr);
       }

       return result;
    }

    void print() override
    {
        for(size_t i = 0; i < m_matrix.size(); ++i)
        {
            std::cout << "Node: " << i << " Neighbors: " << std::endl;
            for(const auto &node : m_matrix[i])
            {
                std::cout << node << " "; 
            }
            std::cout << std::endl;
        }
    }

private:
    std::array<std::array<int, N>, N> m_matrix;
    std::vector<Edge> m_edges;
};

class ListGraph : public Graph, public Printable
{

};

}
