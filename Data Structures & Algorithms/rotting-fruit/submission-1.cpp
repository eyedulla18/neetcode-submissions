class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        vector<bool> dummy(numCols, false);
        vector<vector<bool>> visited(numRows, dummy);
        queue<vector<int>> search;

        //put the position of all rotting fruits in a queue 
        for(int row=0; row<numRows; ++row){
            for(int col=0; col<numCols; ++col){
                if(grid[row][col]==2){
                    search.push({row, col, 0});
                    // visited[row][col] = true;
                }
            }
        }

        int answer = 0;
        while(!search.empty()){
            int row = search.front()[0];
            int col = search.front()[1];
            int time = search.front()[2];
            cout<<"search: "<<row<<"  "<<col<<"  "<<time<<'\n';
            search.pop();

            if(row<0 || col<0 || row>=numRows || col>=numCols){
                continue;
            }

            if(visited[row][col]){
                continue;
            }

            visited[row][col]=true;
            if(grid[row][col]==0){
                continue;
            }
            
            answer = max(answer, time);
            grid[row][col] = 2;
            search.push({row-1,col, time+1});
            search.push({row+1,col, time+1});
            search.push({row,col-1, time+1});
            search.push({row,col+1, time+1});
        }

        //validate if all the fruits are rotten

        for(int row=0; row<numRows; ++row){
            for(int col=0; col<numCols; ++col){
                if(grid[row][col]==1){
                    return -1;
                }
            }
        }


        return answer;

    }
};
