#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> tree;
    vector<long long> subtreeSum;
    vector<int> weights;
    long long totalSum = 0;
    long long minDiff = LLONG_MAX;

    void dfs(int node, int parent) {
        subtreeSum[node] = weights[node];
        for (int child : tree[node]) {
            if (child != parent) {
                dfs(child, node);
                subtreeSum[node] += subtreeSum[child];
            }
        }
        minDiff = min(minDiff, abs(totalSum - 2 * subtreeSum[node]));
    }

    long long findMinDiff(int N, vector<int>& A, vector<int>& B) {
        tree.resize(N + 1);
        subtreeSum.resize(N + 1, 0);
        weights.resize(N + 1);

        // Set weights and calculate total sum
        for (int i = 1; i <= N; i++) {
            weights[i] = i;
            totalSum += i;
        }

        // Build the tree
        for (int i = 0; i < N - 1; i++) {
            tree[A[i]].push_back(B[i]);
            tree[B[i]].push_back(A[i]);
        }

        dfs(1, 0);  // Start DFS from node 1 (assuming 1-indexed)

        return minDiff;
    }
};