#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <assert.h>

std::string FlipQuadTree(std::string &quadtree) {
    std::string new_tree;

    if (quadtree.size() == 1) {
        if (quadtree[0] == 'w') {
            return "w";
        } else if (quadtree[0] == 'b') {
            return "b";
        } else {
            assert(false) << "wrong input";
        }
    }

    return quadtree;
}

int main() {
    int no_of_test_cases = 1;
    std::cin >> no_of_test_cases;
    std::vector<std::string> answers;

    for (int i=0; i < no_of_test_cases; ++i) {
        std::string quadtree;
        std::cin >> quadtree;
        answers.push_back(FlipQuadTree(quadtree));
    }

    for (int i=0; i < no_of_test_cases; ++i) {
        std::cout << answers[i] <<std::endl;
    }

    return 0;
}