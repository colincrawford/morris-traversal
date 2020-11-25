#include <iostream>

#include "src/sample_node.h"
#include "src/morris_traversal.h"

template<typename T>
using SampleNode = morris_traversal::SampleNode<T>;

int main()
{
    auto root = SampleNode<int>(10);
    auto left1 = SampleNode<int>(5);
    auto left2 = SampleNode<int>(2);
    auto left3 = SampleNode<int>(7);
    auto right1 = SampleNode<int>(15);
    auto right2 = SampleNode<int>(12);
    auto right3 = SampleNode<int>(17);
    root.SetLeft(&left1);
    left1.SetLeft(&left2);
    left1.SetRight(&left3);
    root.SetRight(&right1);
    right1.SetLeft(&right2);
    right1.SetRight(&right3);

    morris_traversal::MorrisTraversal(&root, [](int i) {
        std::cout << i << std::endl;
    });

    return 0;
}
