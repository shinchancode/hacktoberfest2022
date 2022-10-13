class Solution {
public:
    vector<vector<int>>v;
    void path(TreeNode* root, int t, int sum, vector<int>&a){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(sum+root->val==t){
                a.push_back(root->val);
                v.push_back(a);
                a.pop_back();
                return;
            }
            return;
        }
        if(root->left){
            a.push_back(root->val);
            path(root->left,t,sum+root->val,a);
            a.pop_back();
        }
        if(root->right){
            a.push_back(root->val);
            path(root->right,t,sum+root->val,a);
            a.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>a;
        path(root,targetSum,0,a);
        return v;
    }
};
