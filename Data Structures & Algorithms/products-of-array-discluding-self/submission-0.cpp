class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // [1,2,4,6]. [1,1,2,8]
        // [1,2,4,6]. [48,24,6,1]

        int n = arr.size();
        vector<int>ans(n);
        int leftprod = 1 ;
        for(int i=0 ; i<n ; i++){
            ans[i] = leftprod;
            leftprod*=arr[i]; 
        }
        int rightprod = 1;
        for(int i=n-1 ; i>=0 ; i--){
            ans[i] *= rightprod;
            rightprod*=arr[i]; 
        }
        return ans;
    }
};
