class Solution {
private:
    void solve(vector<vector<int>>&ans , vector<int>&ds , vector<int>&nums,int ind , int n,int target){
        if(ind == n){
            if(target == 0){
            ans.push_back(ds);
        }
        return ;
        }

        if(target-nums[ind]>=0){
        ds.push_back(nums[ind]);
        solve(ans,ds,nums,ind,n,target-nums[ind]);
        ds.pop_back();
        }
        solve(ans,ds,nums,ind+1,n,target);
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        solve(ans,ds,nums,0,nums.size(),target);
        return ans;
    }
};
