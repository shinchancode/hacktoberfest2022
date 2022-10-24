// Number of Islands

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all
// four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

//SOLUTION:

int rows,cols;

int fun(vector<vector<char>>&grid,int r,int c) {
  if(r<0 || c<0 || r>=rows ||c>=cols)
      return 0;
  if(grid[r][c]=='0')
      return 0;
  grid[r][c]='0';
  int x,y,z,w;
  x=fun(grid,r-1,c);
  y=fun(grid,r+1,c);
  z=fun(grid,r,c+1);
  w=fun(grid,r,c-1);

  return x+y+z+w+1;
}

int numIslands(vector<vector<char>>& grid) {
  rows=grid.size();
  cols=grid[0].size();
  int c=0;
  for(int i=0;i<grid.size();i++){
      for(int j=0;j<grid[0].size();j++){
          if(fun(grid,i,j))
              c++;
      }
  }
  return c;
}

// TIME COMPLEXITY: O(N**2)
// AUXILIARY SPACE: O(N**2)
