#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <assert.h>


int Divide (std::string &quadtree, int start_index) {
    int count = 0;
    int i = start_index+1;

    if (quadtree[start_index] == 'w' || quadtree[start_index] == 'b')
        return start_index+1;

    while (true) {
        if (quadtree[i] == 'x') {
            i = Divide(quadtree, i);
        } else {
            i++;
        }
        count++;

        if (count == 4) return i;
    }
}

std::string FlipQuadTree(std::string &quadtree) {
    int current_index = 0;
    int start_index = 0;
    int end_index = 0;
    std::vector<std::string> quadtree_pieces;
    std::string new_pieces[4];
    std::string new_tree;

    if (quadtree.size() == 1) {
        if (quadtree[0] == 'w') {
            return "w";
        } else if (quadtree[0] == 'b') {
            return "b";
        }
    }
    
    std::string sstring = quadtree.substr(1,quadtree.size()-1);
    while (true) {
        end_index = Divide(sstring, start_index);
        quadtree_pieces.push_back(sstring.substr(start_index, end_index-start_index));
        start_index = end_index;
        if (end_index == sstring.size()) break;
    }

    for (int i=0; i<4; ++i) {
        new_pieces[i] = FlipQuadTree(quadtree_pieces[i]);
    }

    return 'x'+ new_pieces[2] + new_pieces[3]+ new_pieces[0]+ new_pieces[1];
}

int main() {
    int no_of_test_cases = 1;
    std::cin >> no_of_test_cases;
    std::vector<std::string> answers;

    for (int i=0; i < no_of_test_cases; ++i) {
        std::string quadtree ("xbwxwbbwb");
        std::cin >> quadtree;
        answers.push_back(FlipQuadTree(quadtree));
    }

    for (int i=0; i < no_of_test_cases; ++i) {
        std::cout << answers[i] <<std::endl;
    }

    return 0;
}