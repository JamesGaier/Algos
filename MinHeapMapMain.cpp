#include <cassert>
#include <array>
#include "MinHeapMap.hpp"

int main()
{
    constexpr static auto N = 11;
    std::vector<int> arr;
    for(int i = N - 1; i >= 0; --i)
    {
        arr.push_back(i);
    }

    algo::MinHeapMap minHeapMap(arr);

    for(int i = 0; i < N; ++i)
    {
        minHeapMap.print();
        assert(minHeapMap.extractMin() == i);

        minHeapMap.popMin();
    }

    try
    {
       minHeapMap.popMin(); 
       assert(false);
    }
    catch(const char *msg)
    {
        std::cout << msg << std::endl;
    }

}
