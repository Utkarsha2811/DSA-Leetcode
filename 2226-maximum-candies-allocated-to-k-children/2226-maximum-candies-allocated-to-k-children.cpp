class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, int mid) {
        long long count = 0;

        for (int c : candies) {
            count += (c / mid);
        }

        return count >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAllocate(candies, k, mid)) {
                ans = mid;
                low = mid + 1; // try bigger
            } else {
                high = mid - 1; // try smaller
            }
        }

        return ans;
    }
};