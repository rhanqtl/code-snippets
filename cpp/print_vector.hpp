#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
    out << '[';
    for (int i = 0; i < vec.size(); i++) {
        out << vec[i];
        if (i != vec.size() - 1) {
            out << ", ";
        }
    }
    return (out << ']');
}