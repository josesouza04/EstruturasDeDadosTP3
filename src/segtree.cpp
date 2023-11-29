// SegTree (Segment Tree) implementation
#include "../include/segtree.hpp"

SegTree::SegTree(int size_) {
    size = size_;
    treeArray = new Matrix[size_];
    tree = new Matrix[4 * size_];
    for (int i = 0; i < size_; i++) {
        treeArray[i] = Matrix(2, 2);
    }
}

SegTree::~SegTree() {
    delete[] treeArray;
    delete[] tree;
}

Matrix SegTree::build(int left_, int right_, int pos_) {
    if (left_ == right_) {
        tree[pos_] = treeArray[left_];
        return tree[pos_];
    }
    int mid = (left_ + right_) / 2;
    Matrix a = build(left_, mid, 2 * pos_);
    Matrix b = build(mid + 1, right_, 2 * pos_ + 1);
    tree[pos_] = a.multiply(a, b);
    return tree[pos_];
} // build(0, size - 1, 1)

Matrix SegTree::update(int index_, Matrix value_, int left_, int right_, int pos_) {
    if (index_ < left_ || index_ > right_) return tree[pos_];
    if (left_ == right_) {
        tree[pos_] = value_;
        return tree[pos_];
    }
    int mid = (left_ + right_) / 2;
    Matrix a = update(index_, value_, left_, mid, 2 * pos_);
    Matrix b = update(index_, value_, mid + 1, right_, 2 * pos_ + 1);
    tree[pos_] = a.multiply(a, b);
    return tree[pos_];
} // update(index_, value_, 0, size - 1, 1)
    
Matrix SegTree::query(int a_, int b_, int left_, int right_, int pos_) {
    if (b_ < left_ || a_ > right_) return {0, -1};
    if (a_ <= left_ && b_ >= right_) return tree[pos_];
    int mid = (left_ + right_) / 2;
    Matrix a = query(a_, b_, left_, mid, 2 * pos_);
    Matrix b = query(a_, b_, mid + 1, right_, 2 * pos_ + 1);
    return a.multiply(a, b);
} // query(a_, b_, 0, size - 1, 1)

void SegTree::print() {
    std::cout << "size: " << size << std::endl;
    std::cout << "treeArray: " << std::endl;
    for (int i = 0; i < size; i++) {
        treeArray[i].print();
    }
    std::cout << std::endl;
    std::cout << "tree: " << std::endl;
    for (int i = 0; i < 4 * size; i++) {
        tree[i].print();
    }
    std::cout << "--------------------" << std::endl;
}

// Path: src/segtree.cpp