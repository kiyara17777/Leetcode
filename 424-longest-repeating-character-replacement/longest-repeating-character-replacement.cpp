class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0;
        int maxlen=0,maxcnt=0;
        vector<int> freq(26,0);
        while(right<s.size()){
            freq[s[right]-'A']++;
            maxcnt=max(maxcnt,freq[s[right]-'A']);

            while((right-left+1)-maxcnt>k){
                freq[s[left]-'A']--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;

        }
        return maxlen;
    }
};