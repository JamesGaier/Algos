#pragma once
#include <vector>
#include <iostream>
#include "Printable.hpp"


namespace algo
{

class DisjointSet : public Printable
{
public:
    explicit DisjointSet(int N)
    {
        for(auto i = 0; i < N; ++i)
        {
            m_forest.push_back(i);
        }

        for(auto i = 0; i < N; ++i)
        {
            m_weight.push_back(1);
        }
    }

    bool find(int p, int q)
    {
        return root(p) == root(q);
    }

    void unite(int p, int q)
    {
        auto i = root(p);
        auto j = root(q);

        if(m_weight[i] < m_weight[j])
        {
            m_forest[i] = j;
            m_weight[j] += m_weight[i];
        }
        else
        {
            m_forest[j] = i;
            m_weight[i] += m_weight[j];
        }
    }

    // for testing purposes only
    void print() override
    {
        for(const auto &el : m_forest)
        {
            std::cout << el <<  " ";
        }
        std::cout << std::endl;
    }

private:

    int root(int i)
    {
        while(i != m_forest[i])
        {
            m_forest[i] = m_forest[m_forest[i]];
            i = m_forest[i]; 
        }

        return i;
    }

    std::vector<int> m_forest;
    std::vector<int> m_weight;
};

}
