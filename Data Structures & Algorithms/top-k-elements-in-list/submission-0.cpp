class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;

        for(auto itr : nums){
            mpp[itr]++;
        }

        vector<pair<int,int>>arr;

        for(auto itr: mpp){
            arr.push_back({itr.first,itr.second});
        }

        auto lambda =[](pair<int,int>&a , pair<int,int>&b){
            return a.second>b.second;
        };

        sort(arr.begin(),arr.end(),lambda);

        vector<int>ans;

        for(int i=0 ; i<k ; i++){
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};
