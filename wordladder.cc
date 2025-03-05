#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()); // Store words in set
        queue<pair<string, int>> q; // Store {word, steps}
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) return steps; // Found endWord

            for (int i = 0; i < word.length(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c; // Change one letter at a time
                    if (dict.find(word) != dict.end()) { // Word exists in list
                        q.push({word, steps + 1});
                        dict.erase(word); // Remove from set to avoid revisiting
                    }
                }
                word[i] = original; // Restore original character
            }
        }
        return 0; // No transformation found
    }
};
