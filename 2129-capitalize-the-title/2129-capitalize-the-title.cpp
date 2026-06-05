class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.length();
        int start = 0;

        for (int i = 0; i <= n; i++) {
            if (i == n || title[i] == ' ') {
                int len = i - start;

                if (len <= 2) {
                    for (int j = start; j < i; j++) {
                        title[j] = tolower(title[j]);
                    }
                } else {
                    title[start] = toupper(title[start]);

                    for (int j = start + 1; j < i; j++) {
                        title[j] = tolower(title[j]);
                    }
                }

                start = i + 1;
            }
        }

        return title;
    }
};