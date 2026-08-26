class Solution {
    void docalc(vector<string>& res, string& s, string ds, int i, int k) {

        if (k == 0) {
            res.push_back(ds);
            return;
        }

        if (i >= s.length()) {
            return;
        }

        ds.push_back(s[i]);

        if (s[i] == '1')
            docalc(res, s, ds, i + 1, k - 1);
        else
            docalc(res, s, ds, i + 1, k);
    }

public:
    string shortestBeautifulSubstring(string s, int k) {

        vector<string> res;

        for (int i = 0; i < s.length(); i++) {
            docalc(res, s, "", i, k);
        }

        if (res.empty())
            return "";

        sort(res.begin(), res.end());

        string ans = res[0];

        for (string& x : res) {
            if (x.length() < ans.length() ||
                (x.length() == ans.length() && x < ans)) {
                ans = x;
            }
        }

        return ans;
    }
};