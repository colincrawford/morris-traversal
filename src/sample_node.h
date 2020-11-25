#pragma once

namespace morris_traversal {

template<typename T>
class SampleNode {
    T data_;
    SampleNode* left_;
    SampleNode* right_;

    public:
    SampleNode(T data) : data_(data), left_(nullptr), right_(nullptr) {}

    SampleNode* Right() {
        return right_;
    }

    void SetRight(SampleNode* node) {
        this->right_ = node;
    }

    SampleNode* Left() {
        return left_;
    }

    void SetLeft(SampleNode* node) {
        this->left_ = node;
    }

    T Data() {
        return data_;
    }
};

} // namespace morris_traversal
