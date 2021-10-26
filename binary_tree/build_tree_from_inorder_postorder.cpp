/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);   //making the root
        
        //we create inorder for left half of tree
        int i = 0;
        vector<int> Linorder;
        while(inorder[i] != root->val)
        {
            Linorder.push_back(inorder[i]);
            i++;
        }
        int rootIndexInorder = i ;
        //creating the preorder for the left half
        int Lsize = Linorder.size();
        vector <int> Lpreorder;
        int j = 1;
        while( j <= Lsize)
        {
            Lpreorder.push_back(preorder[j]);
            j++;
        }
        int rightStartPreorder = j;
        root->left = buildTree(Lpreorder,Linorder);
        
        
        //we do the same for the right half
        //create inorder for Right half
        vector <int> Rinorder;
        for(int c = rootIndexInorder + 1; c < inorder.size(); c++)
        {
            Rinorder.push_back(inorder[c]);
        }
        //creat preorder for Right Half
        vector <int> Rpreorder;
        int k = rightStartPreorder;
        while( k < preorder.size())
        {
            Rpreorder.push_back(preorder[k]);
            k++;
        }
        
        root->right = buildTree(Rpreorder,Rinorder);
        
        return root;        
        
    }
};
