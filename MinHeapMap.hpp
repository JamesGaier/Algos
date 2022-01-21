#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
#include "Graph.hpp"
#include "Printable.hpp"


namespace algo
{

class MinHeapMap : public Printable
{
public:
    MinHeapMap(const std::vector<int> &arr)
        : N{arr.size()}
    {
        m_heap.resize(arr.size() + 1);
        size_t j = 0;
        for(size_t i = 1; i < arr.size(); ++i)
        {
            m_heap[i] = arr[j++];
        }
        buildHeap();
    }

    int extractMin()
    {
        return m_heap.at(1);
    }

    void popMin()
    {
        if(m_heap.size() != 1)
        {
            m_heap.erase(m_heap.begin() + 1);
            buildHeap();
        }
        else
        {
            throw "Pop called on empty heap.";
        }
    }

    void print() override
    {
        std::cout << std::endl;
        for(const auto &el : m_heap)
        {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

private:
    void heapify(int i)
    {
        size_t left = 2 * i;
        size_t right = 2 * i + 1;
        int smallest;

        if(left <= N && m_heap[left] < m_heap[i])
        {
            smallest = left;
        }
        else
        {
            smallest = i;
        }

        if(right <= N && m_heap[right] < m_heap[smallest])
        {
            smallest = right;
        }

        if(smallest != i)
        {
            std::swap(m_heap[i], m_heap[smallest]);
            heapify(smallest);
        }
    }

    void buildHeap()
    {
        for(auto i = N / 2; i >= 1; --i)
        {
            heapify(i);
        }
    }


    size_t N;
    std::vector<int> m_heap;
    std::map<int, Edge> m_vertexToEdge;
};

}
