class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums2.begin(), nums2.end());
        vector<int> ans;

        for (int x : nums1) {
            if (st.find(x) != st.end()) {
                ans.push_back(x);
                st.erase(x); 
            }
        }

        return ans;
    }
};