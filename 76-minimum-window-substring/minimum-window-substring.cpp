class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();

        unordered_map<char,int> need;
        unordered_map<char,int> window;
        for(char c:t){
            need[c]++;
        }
        int left=0;
        int matched=0;
        int mini=INT_MAX;
        int start=0;

        for(int right=0;right<m;right++){
            window[s[right]]++;
            if(need.find(s[right])!=need.end() && window[s[right]]<=need[s[right]]){
                matched++;
            }
            while(matched==n){
                if(right-left+1<mini){
                    mini=min(mini,right-left+1);
                    start=left;
                }
                window[s[left]]--;

                if(need.find(s[left])!=need.end() && window[s[left]]<need[s[left]]){
                    matched--;
                }
                left++;
            }
        }
        if(mini==INT_MAX){
            return "";
        }
        return s.substr(start,mini);
        
    }
};