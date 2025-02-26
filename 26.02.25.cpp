//problem link:- https://leetcode.com/problems/number-of-provinces/description/

//problem name:- Number of provinces

#include <vector>
using namespace std;
class Solution {
    private:
        void dfs(int n, vector<int>& v, vector<vector<int>>& isConnected) {
            v[n] = 1;
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[n][j] == 1 && !v[j]) {
                    dfs(j, v, isConnected);
                }
            }
        }
    
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<int> visit(n, 0);
            int count = 0;
    
            for (int i = 0; i < n; i++) {
                if (visit[i] == 0) {
                    count++;
                    dfs(i, visit, isConnected);
                }
            }
            return count;
        }
    };

//approach;- Using Graph Tracersal(DFS)

//TC=O(n^2)
//SC=O(n) because of recursive stack worst case
