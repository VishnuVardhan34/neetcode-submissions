#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> res(temps.size(), 0);
        stack<int> stack;
        for(int i=0;i<temps.size();i++) {
            while(!stack.empty() && temps[stack.top()] < temps[i]) {
                res[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return res;
    }
};