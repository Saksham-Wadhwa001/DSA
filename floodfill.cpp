//Flood Fill
//problem link;- https://leetcode.com/problems/flood-fill/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool func(int i, int j, const vector<vector<int>>& image, int in) {
        return (i >= 0 && j >= 0 && i < image.size() && j < image[0].size() && image[i][j] == in);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int in = image[sr][sc];
        if (in == color) {
            return image; // No changes needed
        }

        queue<pair<int,int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (func(i + 1, j, image, in)) q.push({i + 1, j});
            if (func(i - 1, j, image, in)) q.push({i - 1, j});
            if (func(i, j + 1, image, in)) q.push({i, j + 1});
            if (func(i, j - 1, image, in)) q.push({i, j - 1});

            image[i][j] = color;
        }

        return image;
    }
};

//Approach:- Using BFS Traversal
//TC=O(n*m)
//SC=O(n*m)
