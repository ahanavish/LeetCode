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
class Solution
{
public:
    int check(TreeNode *root, int &c)
    {
        if (root == NULL)
            return 1;
        int l = check(root->left, c);
        int r = check(root->right, c);
        if (l == -1 || r == -1)
        {
            c++;
            return 0;
        }
        if (l == 0 || r == 0)
            return 1;
        return -1;
    }
    int minCameraCover(TreeNode *root)
    {
        int c = 0;
        if (check(root, c) == -1)
            c++;
        return c;
    }
};