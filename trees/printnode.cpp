#include "nodetree.h"
#include <iostream>
#include <vector>
#include <queue>
int countTreeNodes(TreeNode <int>* root)
{
    int nodes = 1;
    for(int i = 0; i < root->children.size();i++)
    {
        nodes += countTreeNodes(root->children[i]);
    }
    return nodes;
}

TreeNode<int>* takeinput()              
{
    int rootdata;
    std::cout << "enter the data: ";
    std::cin >> rootdata;
    TreeNode<int>* root = new TreeNode<int> (rootdata);         //making a root with data enterd
    int children_amt;
    std::cout << "enter the children of " << rootdata << ": ";
    std::cin >> children_amt;                                   //asking no. of children
    for (int i = 0; i < children_amt; i++)
    {
        TreeNode<int>* child = takeinput();                     //use recursion to take the input for each child
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int>* takeinputlevelwise()                             //makes use of queues to get a levelwise input
{
    int rootdata;
    std::cout << "enter rootdata : " << std::endl;
    std::cin >> rootdata;
    TreeNode <int>* root = new TreeNode<int> (rootdata); 
    std::queue <TreeNode <int>*> pendingNode;                   //created the node
    pendingNode.push(root);

    while(pendingNode.size() != 0)                              //iterate until queue empty, store children of front
    {
        TreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        std::cout << "enter the no. of children of " << front->data << std::endl;
        int children_number;
        std::cin >> children_number;
        for(int i = 0; i < children_number; i++)                //taking data for each child and connecting child with root
        {
            std::cout << "enter the data of " << i <<"th child : \n";
            int childdata;
            std::cin >> childdata; 
            TreeNode<int>* child = new TreeNode<int> (childdata);
            front->children.push_back(child);
            pendingNode.push(child);
        }

    }
    return root;
}

void printTree(TreeNode <int> *root)
{
    if (root == NULL)
    {
        return;
    }
    std::cout << root->data << " : ";
    for (int i = 0 ; i < root->children.size();i++)             //print the all childrean of root
    {
        std::cout << root->children[i]->data << ",";
    }
    std::cout << std::endl;
    for ( int i = 0; i < root->children.size();i++)             //using recursion to go a level deeper
    {
        printTree(root->children[i]);
    }
}

void printTreelevelwise(TreeNode <int> *root)
{
    if (root == NULL)
    {
       return; 
    }
    std::queue <TreeNode <int>* > pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        TreeNode <int>* front = pendingNodes.front();
        pendingNodes.pop();
        std::cout << front->data << " : ";
        int i = 0;
        while(i < front->children.size())
        {
            std::cout << front->children[i]->data << ", ";
            pendingNodes.push(front->children[i]);
            i++;
        }
        std::cout << std::endl;
        
    }
}

int treeheight(TreeNode <int>* root)
{
    int height = 0;
    int maxdepth = 0; 
    if (root->children.size() == 0)
    {
        return 1;
    }
    else 
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            int depth = treeheight(root->children[i]);
            if (depth > maxdepth)
            {
                maxdepth = depth;
            }
        }
        height = maxdepth + 1;
    }
    return height;
}

void printatLevel(TreeNode <int>* root, int level)      //consider root to be depth 0
{
    if (root == NULL)
    {
        return;
    }
    if (level == 0)
    {
        std::cout << root->data << ", ";                //when reached the lvl 0, print data
    }
    else
    {
        for (int i = 0; i < root->children.size(); i ++)
        {
            printatLevel(root->children[i],level-1);
        }
    }
}

// PASTE TO CONSOLE: 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    /*
    TreeNode <int> *root = new TreeNode<int>(10);
    TreeNode <int> *node1 = new TreeNode<int>(20);
    TreeNode <int> *node2 = new TreeNode<int>(30);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int>* root = takeinputlevelwise();
    printTreelevelwise(root);
    std::cout << "the no. of nodes : " << countTreeNodes(root) << std::endl;
    std::cout << "the height of tree is : " << treeheight(root) << std::endl;
    std::cout << "the nodes at depth 2 are: " ;
    printatLevel(root,2);
    

    delete root;
    return 0;
}