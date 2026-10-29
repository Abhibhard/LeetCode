
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int index) {

        // Target achieved
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicate candidates at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to explore further
            if (candidates[i] > target)
                break;

            // Choose current candidate
            temp.push_back(candidates[i]);

            // Move to next index because each element is used once
            solve(candidates, target - candidates[i], i + 1);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0);

        return ans;
    }
};
