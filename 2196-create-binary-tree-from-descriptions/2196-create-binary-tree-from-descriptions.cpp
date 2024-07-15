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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map;
        unordered_set<int> childrenSet;

        for(const auto& arr : descriptions){
            int parentInt = arr[0];
            int childInt = arr[1];
            int isLeft = arr[2];
            childrenSet.insert(childInt);

            TreeNode* parentNode;
            if (map.find(parentInt) != map.end()) {
                parentNode = map[parentInt];
            } else {
                parentNode = new TreeNode(parentInt);
                map[parentInt] = parentNode;
            }

            TreeNode* childNode;
            if (map.find(childInt) != map.end()) {
                childNode = map[childInt];
            } else {
                childNode = new TreeNode(childInt);
                map[childInt] = childNode;
            }

            if (isLeft == 1) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
        }

        int root = -1;
        for(const auto& arr: descriptions){
            if(childrenSet.find(arr[0]) == childrenSet.end()){
                root = arr[0];
                break;
            }
        }
        return map.find(root) != map.end() ? map[root] : nullptr;
    }
};