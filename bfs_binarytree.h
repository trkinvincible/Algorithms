#ifndef BFS_BINARYTREE_H
#define BFS_BINARYTREE_H

#include "command.h"
#include "build_binary_tree.h"
#include <queue>

class doBFS
{
private:
    std::queue<std::shared_ptr<Node>> q;
public:
    void operator()(std::shared_ptr<Node> &graph){

        std::cout << graph->data << " ";

        if(graph->lefftNode != nullptr)
            q.push(graph->lefftNode);
        if(graph->rightNode != nullptr)
            q.push(graph->rightNode);

        if(!q.empty()){

            std::shared_ptr<Node> temp = q.front();
            q.pop();
            this->operator ()(temp);
        }
    }
};
//          5
//        /   \
//       4     6
//      / \   / \
//     3   7 2   8
//    /           \
//   1             9

class bfs_binarytree : public Command{

    void execute()
    {
        std::shared_ptr<Node> graph = getTree();
        //do bfs
        doBFS bfs;
        bfs(graph);

        std::cout << "\n\n" << "Printed in BFS order" << endl;
    }
};

#endif // BFS_BINARYTREE_H
