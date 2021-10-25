#include "nodetree.h"
#include <iostream>
#include <vector>
#include <queue>

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

int leafNodes(TreeNode<int>* root)
{
    int leafnodes =0 ;
    if (root == NULL)
    {
        return 0;
    }
    else if (root->children.size() == 0)
    {
        return 1;
    }

    else 
    {
        
        for(int i = 0 ; i < root->children.size(); i++)
        {
            leafnodes += leafNodes(root->children[i]);
        }
        
    }
    return leafnodes;
}

void preorderPrinting(TreeNode<int>* root)                      //print root then their children
{
    if (root == NULL)
    {
        return;
    }
    else 
    {
        std::cout << root->data << " ";
        for(int i=0; i < root->children.size(); i ++)
        {
            preorderPrinting(root->children[i]);
        }
    }
}

void postorderPrinting(TreeNode <int>* root)                    //print children then its root
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        for(int i = 0; i < root->children.size(); i++)
        {
            postorderPrinting(root->children[i]);
        }
        std::cout << root->data << " ";
    }
}
// PASTE TO CONSOLE: 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    TreeNode<int>* root = takeinputlevelwise();
    std::cout << "preorder : ";
    preorderPrinting(root);
    std::cout << "\n postorder : " ;
    postorderPrinting(root);
    std::cout <<"\nthe no. of leafnodes : " << leafNodes(root) << std::endl;

    delete root;
    return 0;
}