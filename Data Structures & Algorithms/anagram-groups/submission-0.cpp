#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string word: strs) {
            string key = word;
            sort(key.begin(), key.end());
            mp[key].push_back(word);
        }
        vector<vector<string>> ans;
        for (auto& [key, group] : mp) {
            ans.push_back(group);
        }
        return ans;
    }
};
