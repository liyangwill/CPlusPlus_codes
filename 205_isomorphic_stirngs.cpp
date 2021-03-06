// "egg", "add", return true.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // size = 256: m1, m2, initial all 0s;
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            // s[i] is regarded as number in m[]
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};