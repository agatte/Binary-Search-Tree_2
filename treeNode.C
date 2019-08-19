#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

/*
 * treeNode class for storing the data in nodes of
 * BST. Data is First Name, Last Name of survivor, left and
 * right nodes to current node.
 */
class treeNode {
public:
    treeNode *left;
    treeNode *right;
    string last;
    string first;
    treeNode(string first,string last)
            : first(first)
            , last(last)
            , left(nullptr)
            , right(nullptr) {
    }
};
