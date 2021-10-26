#include "treeNode.h"
#include <iostream>
#include <queue>
using namespace std;

binaryTreeNode<int>* takeInputLevelwise()
{
    cout << "enter root data" ;
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }

    binaryTreeNode <int>* root = new binaryTreeNode<int> (rootdata);
    queue <binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size() != 0)
    {
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int leftdata;
        cout << "enter the left of " << front->data << endl;
        cin >> leftdata;
        if(leftdata != -1)
        {
            binaryTreeNode<int>* leftchild = new binaryTreeNode<int> (leftdata);
            front->left = leftchild;
            pendingNodes.push(leftchild);
        }

        int rightdata;
        cout << "enter the right of" << front->data << endl;
        cin >> rightdata;
        if(rightdata != -1)
        {
            binaryTreeNode<int>* rightchild = new binaryTreeNode<int> (rightdata);
            front->right = rightchild;
            pendingNodes.push(rightchild);
        }

    }
    return root;
}

void printBtreeLevelwise(binaryTreeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    
    queue <binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
    
}

void printBtree(binaryTreeNode <int>* root)
{
    if (root == NULL)
    {
        return;
    }
    std::cout << root->data << " : ";
    if (root->left != NULL)
    {
        std::cout << "L" << root->left->data ;
    }
    if (root->right != NULL)
    {
        std::cout << "R" << root->right->data;
    }
    std::cout << std::endl;
    printBtreeLevelwise(root->left);
    printBtreeLevelwise(root->right);
}

int countNode(binaryTreeNode <int>* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

void inorderTraversal(binaryTreeNode <int>* root)
{
    if (root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);

}

// PASTE TO CONSOLE: 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main()
{
    // binaryTreeNode<int>* root = new binaryTreeNode<int>(1);
    // binaryTreeNode<int>* node1 = new binaryTreeNode<int>(2);
    // binaryTreeNode<int>* node2 = new binaryTreeNode<int>(3);

    // root->left = node1;
    // root->right = node2;

    binaryTreeNode<int>* root = takeInputLevelwise();
    printBtreeLevelwise(root);
    cout << "\nNumber of nodes : " << countNode(root);
    cout << "inorder Traversal printing: " ;
    inorderTraversal(root);

    delete root;
    
}