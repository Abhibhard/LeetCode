
class Solution {
    bool isRotation(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> lps(n, 0);

        for (int i = 1, len = 0; i < n; ) {
            if (b[i] == b[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int i = 0, j = 0;

        while (i < 2 * n - 1) {
            int x = a[i % n];

            if (x == b[j]) {
                i++;
                j++;

                if (j == n) return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int i = 0; i < n; i += k) {
                vector<int> a(nums.begin() + i,
                              nums.begin() + i + k);
                vector<int> b(sorted.begin() + i,
                              sorted.begin() + i + k);

                if (!isRotation(a, b)) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
};
