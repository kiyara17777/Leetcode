class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int left=0;
        int maxlen=0;
        for(int right=0;right<s.length();right++){
            if(hash[s[right]]!=-1){
                left=max(left,hash[s[right]]+1);
            }
            maxlen=max(maxlen,right-left+1);
            hash[s[right]]=right;
        }
        return maxlen;
        
    }
};