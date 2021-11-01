#include <vector>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
template <typename T>

// A TREE WHOSE NODES HAS MAXIMUM CHILDREN OF 2
class binaryTreeNode
{
    public:
    T data;
    binaryTreeNode<int>* left;
    binaryTreeNode<int>* right;

    binaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};


class BST
{
    binaryTreeNode<int>* root;
    private:
    bool helper(int data, binaryTreeNode<int>* root)
    {
        if (root == NULL ) return false;
        if(root->data == data) return true; 
        else if (root->data > data) return helper(data, root->left);
        else if (root->data < data) return helper(data, root->right);
        return false;
    }
   
    binaryTreeNode<int>* helperInsert(int data, binaryTreeNode<int>* node)      //insert at the null child of a node
    {
        if (node == NULL)           // BASE CASE: if null create a new node with the data , and return that
        {
            binaryTreeNode<int>* ans = new binaryTreeNode<int> (data);
            return ans;
        }
        else if(node->data > data)  //if data is less than root data, go to left
        {
            binaryTreeNode<int>* ans = helperInsert(data, node->left);
            node->left = ans;
            return node;
        }
        else if(node->data < data)  //if data is more than root data, go to right
        {
            binaryTreeNode <int>* ans = helperInsert(data, node->right);
            node->right = ans;
            return node;
        }
    }
    int findMax(binaryTreeNode<int>* root)
    {
        if(root == NULL)
        {
            return INT_MIN;
        }
        return std::max(root->data,findMax(root->right));
    }
    
    binaryTreeNode<int>* deleteNode(binaryTreeNode<int>* root, int key) {
        if (root == NULL) return NULL;
        else if (root->data == key)
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                return root->left;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                return root->right;
            }
            else if ( root->left != NULL && root->right != NULL)
            {
                int lmax = findMax(root->left);
                root->data = lmax;
                root->left = deleteNode(root->left,lmax);
                return root;
            }
        }
        else if(root->data < key)
        {
            binaryTreeNode<int>* ans = deleteNode(root->right,key);
            root->right = ans;
            return root;
        }
        else if(root->data > key)
        {
            binaryTreeNode<int>* ans = deleteNode(root->left, key);
            root->left = ans;
            return root;
        }
        return root;
    }
    public:
    bool hasData(int data)
    {
        return helper(data, root);
    }
    void insertData(int data)
    {
        binaryTreeNode<int>* x = helperInsert(data, root);
        this->root = x;
        return;
    }
    void deleteData(int data)
    {
        deleteNode(root, data);
    }

};


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

vector <int>* returnPath(binaryTreeNode <int>* root, int node)

{
    if(root == NULL)
    {
        return NULL;
    }
    else if (root->data == node)
    {
        vector<int>* ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    vector <int>* l = returnPath(root->left,node);
    if (l != NULL)
    {
        l->push_back(root->data);
        return l;
    } 
    vector<int>* r = returnPath(root->right, node);
    if(r != NULL)
    {
        r->push_back(root->data);
        return r;
    }
    
    return NULL;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1


int main()
{
    binaryTreeNode<int>* root = takeInputLevelwise();
    vector <int>* x = returnPath(root,4);
    for (int i = 0; i < x->size(); i++)
    {
        cout << x->at(i) << " ";
    }
    delete x;
    delete root;
    return 0;
}
