class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int right=0;
        int n=s.length();
        int res=0;
        vector<int> freq(3,0);
        while(right<n){
            freq[s[right]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                res+=(n-right);

                freq[s[left]-'a']--;
                left++;

            }
            right++;
        }
        return res;
    }
};