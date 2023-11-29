// SegTree (Segment Tree) header
#ifndef SEGTREE_HPP 
#define SEGTREE_HPP

#include "../include/matrix.hpp"

class SegTree {
    public:
        SegTree() {size = 0; treeArray = nullptr; tree = nullptr;};
        SegTree(int size_);
        ~SegTree();
        
        Matrix build(int left_, int right_, int pos_);
        Matrix update(int index_, Matrix value_, int left_, int right_, int pos_);
        Matrix query(int a_, int b_, int left_, int right_, int pos_);

        int getSize() {return size;};
        void setTreeArrayPos(int pos_, Matrix value_) {treeArray[pos_] = value_;};
        void print();

    private:
        int size;
        Matrix *treeArray;
        Matrix *tree;
};

#endif // SEGTREE_HPP
// Path: include/segtree.hpp