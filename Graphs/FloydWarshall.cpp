// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
class Solution {
	public:
	// Update distance matrix in-place
	void floydWarshall(vector<vector<int>> &dist) {
		int n = dist.size();
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				if (dist[i][k] == 1e8) continue;
				for (int j = 0; j < n; j++) {
					if (dist[k][j] == 1e8) continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		
		// Checking of negative edge cycles
		bool neg = false;
		for (int i = 0; i < n; i++) {
			if (dist[i][i] < 0)	neg = true;
		}
	}
};
