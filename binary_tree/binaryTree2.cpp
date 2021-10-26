#include "treeNode.h"
#include <iostream>

binaryTreeNode<int>* buildTreeHelper(int* in,int* pre,int inS,int inE,int preS, int preE)
{
    if (inE < inS) return NULL;

    int rootdata = pre[preS];
    int i = 0;
    while(in[i] != rootdata)
    {
        i++;
    }
    int rootindex = i;

    int LpreS = preS + 1;           
    int LinS = inS;                     //for the left node
    int LinE = rootindex - 1;
    int LpreE = LinE - LinS + LpreS;

    int RpreS = LpreE + 1;
    int RpreE = preE;                   //this is for the right node
    int RinS = rootindex + 1;
    int RinE = inE;

    binaryTreeNode<int>* root = new binaryTreeNode<int> (rootdata);
    root ->left = buildTreeHelper(in, pre, LinS,LinE,LpreS,LpreE);
    root ->right = buildTreeHelper(in , pre, RinS, RinE,RpreS,RpreE);

    return root;
}


binaryTreeNode<int>* buildTree(int* inorder, int* preorder, int size)
{
    return buildTreeHelper(inorder, preorder, 0, size - 1, 0, size -1 );
}

int main()
{
    return 0;
}