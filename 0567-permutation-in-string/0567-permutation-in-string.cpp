class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> c1(26, 0), c2(26, 0);
        int i;

        for (i = 0; i < s1.size(); i++) {
            c1[s1[i] - 'a']++;
        }
        int wind = s1.size();
        for (i = 0; i < wind; i++) {
            c2[s2[i] - 'a']++;
        }
        for (i = wind; i < s2.size(); i++) {
            if (c1 == c2)
                return true;
            c2[s2[i] - 'a']++;
            c2[s2[i - wind] - 'a']--;
        }
        return c1 == c2;
    }
};