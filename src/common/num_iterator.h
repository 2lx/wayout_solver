#include <iterator>

template <class T>
class num_iterator {
    T i;

public:
    explicit num_iterator(T position = 0) : i{position} {}

    T operator*() const { return i; }
    num_iterator & operator++() {
        ++i;
        return *this;
    }
    bool operator!=(const num_iterator & other) const {
        return i != other.i;
    }
    bool operator==(const num_iterator & other) const {
        return !(*this != other);
    }
};

namespace std {
template <class T>
struct iterator_traits<num_iterator<T>> {
    using iterator_category = std::forward_iterator_tag;
    using value_type        = T;
};
}
