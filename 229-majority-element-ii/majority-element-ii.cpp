#define pb push_back

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int el1 = INT_MIN, el2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;

        for (int x : nums) {
            if (el1 == x) cnt1++;
            else if (el2 == x) cnt2++;
            else if (cnt1 == 0) {
                el1 = x;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                el2 = x;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int x : nums) {
            if (x == el1) cnt1++;
            else if (x == el2) cnt2++;
        }

        vector<int> ans;

        if (cnt1 > n / 3) ans.pb(el1);
        if (cnt2 > n / 3) ans.pb(el2);

        return ans;
    }
};