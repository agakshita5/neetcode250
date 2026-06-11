class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i=0;
        int minlen = min(strs.front().size(), strs.back().size());
        while(i<minlen && strs.front()[i] == strs.back()[i]) i++;

        return strs.front().substr(0,i);
    }
};

// When we sort the strings, the first and last strings 
// in the sorted list will be the most different from each other 
// in terms of their characters. 
// So, the longest common prefix for all the strings must be a prefix of both the first and the last strings in the sorted list.