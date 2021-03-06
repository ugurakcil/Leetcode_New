/*
The max optimization in space one can do is O(n) without changing the grid matrices
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        if (!r || !c)
            return 0;
        
        vector<int> compr(c, 0);
        compr[0] = grid[0][0];
        for(int i=1; i<c; i++)
            compr[i] = grid[0][i] + compr[i-1];
        
        for(int i=1; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if (j==0)
                    compr[j] += grid[i][j];
                else
                    compr[j] = grid[i][j] + min(compr[j], compr[j-1]);
            }
        }
        
        return compr[c-1];
    }
};

//---------------------------------------------------------------------------------------

//Very simple DP solution.One optimization you can do is use O(m+n) space ,i.e. use two 1-D array,right and down
//array.In this u just need to update down array once and the right array all through the loop

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m= grid.size();
        if(!m)
            return 0;
        int n= grid[0].size();
        
        if(m==1 && n==1)
            return grid[0][0];
        
        vector<int> right(n);
        vector<int> down(m);
        
        right[0] = grid[0][0];
        down[0] = grid[0][0];
        
        for(int i=1; i<n; i++)
            right[i] = grid[0][i] + right[i-1]; 
        
        for(int i=1; i<m; i++)
            down[i] = grid[i][0] + down[i-1]; 
            
        for(int i=1; i<m; i++)
        {
            //down[i] = min( down[i] , down[i-1]);
            int flag=1;
            for(int j=1; j<n; j++)
            {
                if(flag)
                {
                    right[j] = min( right[j] , down[i]) + grid[i][j];
                    flag=0;
                }
                else
                    right[j] = min( right[j] , right[j-1]) + grid[i][j];
            }
        }
        
        if(n == 1)
            return down[m-1];
        else
            return right[n-1];
        
    }
};
