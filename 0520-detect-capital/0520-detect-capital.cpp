class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;

        for (char ch : word) {
            if (ch >= 'A' && ch <= 'Z') {
                capitalCount++;
            }
        }

        int n = word.length();

        // All letters capital
        if (capitalCount == n)
            return true;

        // All letters lowercase
        if (capitalCount == 0)
            return true;

        // Only first letter capital
        if (capitalCount == 1 && word[0] >= 'A' && word[0] <= 'Z')
            return true;

        return false;
    }
};