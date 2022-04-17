#ifndef NUM_RANGE_H
#define NUM_RANGE_H

#include "num_iterator.h"

template <class T>
class num_range {
    T _from, _to;

public:
    num_range(T from, T to) : _from(from), _to(to) { }

    num_iterator<T> begin() const { return num_iterator<T>{_from}; }
    num_iterator<T> end()   const { return num_iterator<T>{_to};   }
};

#endif
