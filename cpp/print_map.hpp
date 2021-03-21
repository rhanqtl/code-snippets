#include <iostream>
#include <map>

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<T> &m) {
    out << '{';
    int i = 0;
    for (auto it = m.cbegin(); it != m.cend(); it++, i++) {
        out << it->first << " => " << it->second;
        if (i != m.size() - 1) {
            out << ", ";
        }
    }
    return (out << '}');
}