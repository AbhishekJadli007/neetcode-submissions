class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mpp;

        for(auto itr : nums){
            mpp[itr]++;
        }
        int n = nums.size();

        int longest = 0 ;
        for(int i=0 ; i<n ; i++){
            if(mpp.find(nums[i]-1)==mpp.end()){
                int currlongest = 1 ;
                int curr = nums[i];
                while(mpp.find(curr+1)!=mpp.end()){
                    currlongest++;
                    curr++;
                }
                longest = max(longest,currlongest);
            }
        }
        return longest;
    }
};
