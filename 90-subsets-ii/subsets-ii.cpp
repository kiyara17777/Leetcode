class Solution {
public:
    void findSub(int ind,vector<int> &curr,vector <int>&arr,vector<vector<int>>&ans){
        ans.push_back(curr);

        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;

            curr.push_back(arr[i]);
            findSub(i+1,curr,arr,ans);

            curr.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        findSub(0,curr,nums,ans);
        return ans;
    }
};