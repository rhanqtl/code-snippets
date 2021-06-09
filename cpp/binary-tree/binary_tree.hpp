#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

namespace hq {
    template <typename T>
    struct TreeNode {
        T data;
        TreeNode *left, *right;

        explicit TreeNode(const T &data): TreeNode(data, nullptr, nullptr) {}
        TreeNode(const T &data, TreeNode<T> *left, TreeNode<T> *right)
            : data(data), left(left), right(right) {}
    };

    template <typename T>
    struct BinaryTree {
        TreeNode<T> *root;

        BinaryTree(): root(nullptr) {}
        BinaryTree(const T &data): root(new TreeNode<T>(data)) {}
    };
}

#endif  // __BINARY_TREE_H__