// divide array in 2 stacks
```class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
            vector<string> x;
            int ind = 0;
            for(int i = 1; i<=n;i++){
                    x.push_back("Push");
                    if(i == target[ind])
                       ind++;
                       
                       else
                       x.push_back("Pop");
                       
                       if(ind == target.size())
                       break;
            }
                       return x;
        
    }
};
