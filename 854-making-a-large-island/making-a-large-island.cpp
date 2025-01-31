class Solution {
private:
    int drow[4] = {0, 0, -1, 1};
    int dcol[4] = {-1, 1, 0, 0};

    int bfs(int srow, int scol, vector<vector<int>>& grid, vector<vector<int>>& islandId, unordered_map<int, int>& islandSize, int id) {
        int n = grid.size();
        int area = 0;
        queue<pair<int, int>> q;
        q.push({srow, scol});
        islandId[srow][scol] = id;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            area++;

            for (int i = 0; i < 4; i++) {
                int r = row + drow[i];
                int c = col + dcol[i];
                if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 1 && islandId[r][c] == 0) {
                    islandId[r][c] = id;
                    q.push({r, c});
                }
            }
        }

        return area;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> islandId(n, vector<int>(n, 0));
        unordered_map<int, int> islandSize;
        int id = 2;  // Start from 2 to differentiate from water (0) and land (1)
        int maxIsland = 0;

        // Step 1: Find all islands and assign them unique IDs
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && islandId[i][j] == 0) {
                    islandSize[id] = bfs(i, j, grid, islandId, islandSize, id);
                    maxIsland = max(maxIsland, islandSize[id]);
                    id++;
                }
            }
        }

        // Step 2: Try converting each 0 to 1 and check the possible island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIslands;
                    int newSize = 1;  // The new land itself

                    for (int k = 0; k < 4; k++) {
                        int r = i + drow[k];
                        int c = j + dcol[k];
                        if (r >= 0 && r < n && c >= 0 && c < n && islandId[r][c] > 0) {
                            uniqueIslands.insert(islandId[r][c]);
                        }
                    }

                    for (int island : uniqueIslands) {
                        newSize += islandSize[island];
                    }

                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};
