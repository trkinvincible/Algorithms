#ifndef BUILD_BINARY_TREE_H
#define BUILD_BINARY_TREE_H

#include <iostream>
#include <array>
#include "boost/variant.hpp"

struct Node{
public:

    Node(int d):data(d)
    {
        lefftNode = nullptr;
        rightNode = nullptr;
    }
    int data;
    std::shared_ptr<Node> lefftNode;
    std::shared_ptr<Node> rightNode;
};

enum class type{
    IN_ORDER=1,
    PRE_ORDER,
    POST_ORDER,
};

void doInorder(std::shared_ptr<Node> root)
{
    //L-Root-R
    if(root == nullptr)
        return;
    doInorder(root->lefftNode);
    std::cout << root->data << endl;
    doInorder(root->rightNode);
}
void doPreOrder(std::shared_ptr<Node> root)
{
    //Root-L-R
    if(root == nullptr)
        return;
    std::cout << root->data << endl;
    doInorder(root->lefftNode);
    doInorder(root->rightNode);
}

void printTree(std::shared_ptr<Node> root,type t)
{
    switch(t){

    case type::IN_ORDER:
        doInorder(root);
        break;
    case type::PRE_ORDER:
        doPreOrder(root);
        break;
    default:
        break;
    }
}

void insert(std::shared_ptr<Node> &root,int i)
{
    if(root == nullptr)
        root = std::make_shared<Node>(i);
    else if (i <= root->data) {
        insert(root->lefftNode,i);
    }else{
        insert(root->rightNode,i);
    }
}

std::shared_ptr<Node> getTree()
{
    std::shared_ptr<Node> root = nullptr;
    std::array<int,9> tree_elements = {5,4,6,3,7,2,8,1,9};

    for(int i : tree_elements){
        insert(std::ref(root),i);
    }
    printTree(root,type::IN_ORDER);

    return root;
}
#endif // BUILD_BINARY_TREE_H
