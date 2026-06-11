class Solution {
public:
    int removeElement(vector<int>& v, int x) {
        // v.erase(remove(v.begin(), v.end(), x), v.end());
        erase(v, x);
        return v.size();
    }
};