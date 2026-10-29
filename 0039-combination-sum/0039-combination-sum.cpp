
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int index) {
        // Base case: target becomes zero
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Explore all candidates starting from index
        for (int i = index; i < candidates.size(); i++) {

            // If candidate exceeds target, stop
            if (candidates[i] > target)
                break;

            // Include the current candidate
            temp.push_back(candidates[i]);

            // Same index allows unlimited reuse
            solve(candidates, target - candidates[i], i);

            // Backtrack: remove the candidate
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0);

        return ans;
    }
};
