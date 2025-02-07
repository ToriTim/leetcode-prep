class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&  visited, int& cumulated) {
		int m = grid.size();
        int n = grid[0].size();

	    if (i < 0 || j < 0 || i > m-1 || j > n-1 || visited[i][j]){
            return;
        }
	        
	    if (grid[i][j] == 0) {
            return;
        }

        cumulated += grid[i][j];	    
	    grid[i][j] = 0;
	    visited[i][j] = true;
	    dfs(grid, i-1, j, visited, cumulated); //left
	    dfs(grid, i+1, j, visited, cumulated); //right
	    dfs(grid, i, j-1, visited, cumulated); //upper
	    dfs(grid, i, j+1, visited, cumulated); //lower
	}

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
	    if (grid.empty() || m == 0 || n == 0) {
	    	return 0;
        }
	       

	    vector<vector<bool>> visited(m, vector<bool>(n, false));

        int result = 0;
	    for (int i = 0; i < m; i++) {
	        for (int j = 0; j < n; j++) {
	            if (grid[i][j] > 0) {
                    int count = 0;
	                dfs(grid, i, j, visited, count);
                    if(count > result){
                        result = count;
                    }
	            }
	        }
	    }
	    return result;
    }
};