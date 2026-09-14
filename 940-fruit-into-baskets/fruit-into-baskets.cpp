class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0,right=0;
        int maxlength=0;
        unordered_map<int,int> baskets;
        while(right<fruits.size()){
            baskets[fruits[right]]++;
            while(baskets.size()>2){
                baskets[fruits[left]]--;
                if(baskets[fruits[left]]==0){
                    baskets.erase(fruits[left]);
                }
                left++;

            }
            maxlength=max(maxlength,right-left+1);
            right++;
        }
        return maxlength;
        
    }
};