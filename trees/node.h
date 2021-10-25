#include <vector>
template <typename T>
class TreeNode
{
    public:
    T data;
    std::vector <TreeNode<T>*> children;
    TreeNode(T element)
    {
        data = element;
    }
    ~TreeNode ()                //before destrorying , for loops delete the children of the root
    {
        for (int i = 0; i < children.size(); i ++)
        {
            delete children[i];
        }
        
    }
};
