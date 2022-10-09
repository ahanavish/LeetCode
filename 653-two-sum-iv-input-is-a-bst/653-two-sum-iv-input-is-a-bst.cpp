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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        return findTargetInSortedArray(nums, k);
    }

private:
    void inorder(TreeNode* node, vector<int>& nums) {
        if (!node) return;
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }

    bool findTargetInSortedArray(vector<int> a, int target) {
        for (int i = 0, j = a.size() - 1; i < j;) {
            int sum = a[i] + a[j];
            if (sum == target) {
                return true;
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return false;
    }
};