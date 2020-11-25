#include <iostream>
#include <vector>

#include <assert.h>

#include "src/sample_node.h"
#include "src/morris_traversal.h"

template<typename T>
using SampleNode = morris_traversal::SampleNode<T>;

// some test helpers
#define ASSERT_EQUALS(expected, actual, description) \
{ \
    if (expected != actual) { \
        std::cout << "Failed Assertion: " << __FILE__ << "(" << __LINE__ << \
        ") " << __func__ << "() - " << description << " - Expected: " << \
        expected << ", Got: " << actual << std::endl; \
        return false; \
    } \
}

#define PASS() \
    std::cout << "passed " << __func__ << "()" << std::endl; \
    return true;

void PrintTestResults(int total_tests, int total_passed)
{
    int total_failed = total_tests - total_passed;
    std::string seperator = "====================";
    std::cout << seperator << std::endl;
    std::cout << "|| Tests Finished ||" << std::endl;
    std::cout << seperator << std::endl;
    std::cout << "|| Passed: " << total_passed << "      ||"<< std::endl;
    std::cout << "|| Failed: " << total_failed << "      ||"<< std::endl;
    std::cout << seperator << std::endl;
}

// the tests
bool TestEmptyTree() {
    SampleNode<int>* root = nullptr;

    std::vector<int> v;
    morris_traversal::MorrisTraversal(root, [&v](int i) {
        v.push_back(i);
    });

    ASSERT_EQUALS(0, v.size(), "It doesn't iterate over anything for a null tree root");
    PASS()
}

bool TestBalancedTree()
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
    int tree_size = 7;

    std::vector<int> v;
    morris_traversal::MorrisTraversal(&root, [&v](int i) {
        v.push_back(i);
    });

    ASSERT_EQUALS(tree_size, v.size(), "It iterates over each item");
    std::vector<int> expected_order = { 2, 5, 7, 10, 12, 15, 17 };
    bool is_expected_order = expected_order == v;
    ASSERT_EQUALS(true, is_expected_order, "It iterates in order");
    PASS()
}


int main()
{
    std::cout << "Running Tests..." << std::endl;

    std::vector<bool> results = {
        TestEmptyTree(), TestBalancedTree()
    };

    int total_passed = 0;
    for (bool result : results)
    {
        if (result) total_passed++;
    }

    PrintTestResults(results.size(), total_passed);

    if (total_passed != results.size())
    {
        return 1;
    }
    return 0;
}
