#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator begin = container.begin();
    typename T::iterator end = container.end();
    typename T::iterator pos = std::find(begin, end, n);
    if (pos == end)
        throw NoOccuranceFound();
    return (pos);
}
