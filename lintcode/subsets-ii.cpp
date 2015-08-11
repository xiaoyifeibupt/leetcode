/**
*Given a list of numbers that may has duplicate numbers, return all possible subsets
*Example*
*If *S* = *[1,2,2]*, a solution is:*
*
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]*

*Note*
*Each element in a subset must be in *non-descending *order.*
*The ordering between two subsets is free.*
*The solution set must not contain duplicate subsets.*
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<int> sorted_S(S);
        sort(sorted_S.begin(), sorted_S.end());
        vector<vector<int>> result(1);
        size_t previous_size = 0;
        for (size_t i = 0; i < sorted_S.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                // only union non-duplicate element or new union set
                if (i == 0 || sorted_S[i] != sorted_S[i - 1] || j >= previous_size) {
                    result.emplace_back(result[j]);
                    result.back().emplace_back(sorted_S[i]);
                }
            }
            previous_size = size;
        }
        return result;
    }
};

