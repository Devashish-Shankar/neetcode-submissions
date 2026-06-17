class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>last_seen(128,-1);
        int maxlen = 0;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            char curr = s[right];
            if(last_seen[curr]>=left){
                left = last_seen[curr] + 1;
            }
            last_seen[curr] = right;
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};
