// SegTree (Segment Tree) implementation
#include "../include/segtree.hpp"

SegTree::SegTree() {
    size = 0;
    tree = nullptr;
}

SegTree::SegTree(int size_) {
    try {
        size = size_;
        tree = new Matrix[4 * size];
        build(0, size - 1, 1);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

SegTree::~SegTree() {
    delete[] tree;
}

Matrix SegTree::multiply(Matrix *matrixA_, Matrix *matrixB_) { // O(1)
    try {
        Matrix result;
        result.x1 = (((matrixA_->x1 * matrixB_->x1) % 100000000) + 
                    ((matrixA_->y1 * matrixB_->x2) % 100000000)) % 100000000;
        result.y1 = (((matrixA_->x1 * matrixB_->y1) % 100000000) + 
                    ((matrixA_->y1 * matrixB_->y2) % 100000000)) % 100000000;
        result.x2 = (((matrixA_->x2 * matrixB_->x1) % 100000000) + 
                    ((matrixA_->y2 * matrixB_->x2) % 100000000)) % 100000000;
        result.y2 = (((matrixA_->x2 * matrixB_->y1) % 100000000) + 
                    ((matrixA_->y2 * matrixB_->y2) % 100000000)) % 100000000;
        return result;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

int SegTree::getSize() {
    return size;
}

void SegTree::build(int left_, int right_, int pos_) { // O(n)
    try {
        if (left_ == right_) {
            tree[pos_] = Matrix();
            return;
        }
        int mid = (left_ + right_) / 2;
        build(left_, mid, 2 * pos_);
        build(mid + 1, right_, 2 * pos_ + 1);
        tree[pos_] = multiply(&(tree[2 * pos_]), &(tree[2 * pos_ + 1]));
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void SegTree::update(int index_, int left_, int right_, int pos_) { // O(log n)
    try {
        if (index_ < left_ || index_ > right_) return;
        if (left_ == right_) {
            std::cin >> tree[pos_].x1 >> tree[pos_].y1 >> tree[pos_].x2 >> tree[pos_].y2;
            return;
        }
        int mid = (left_ + right_) / 2;
        if (index_ <= mid) update(index_, left_, mid, 2 * pos_);
        if (index_ > mid) update(index_, mid + 1, right_, 2 * pos_ + 1);
        tree[pos_] = multiply(&(tree[2 * pos_]), &(tree[2 * pos_ + 1]));
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

Matrix SegTree::query(int a_, int b_, int left_, int right_, int pos_) { // O(log n)
    try {
        if (b_ < left_ || a_ > right_) return Matrix();
        if (a_ <= left_ && b_ >= right_) return tree[pos_];
        int mid = (left_ + right_) / 2;
        Matrix leftMatrix = query(a_, b_, left_, mid, 2 * pos_);
        Matrix rightMatrix = query(a_, b_, mid + 1, right_, 2 * pos_ + 1);
        return multiply(&leftMatrix, &rightMatrix);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
// Path: src/segtree.cpp