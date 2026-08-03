class Solution {
public:

    //this is passing a ref
    void search(vector<vector<int>>& grid, int row, int col){
        cout<<"start search "<<row<<"  "<<col<<"\n";

        //find a treasure 
        int numRows = grid.size();
        int numCols = grid[0].size();
        vector<bool> dummy(numCols, false);
        vector<vector<bool>> visited(numRows, dummy);

        queue<vector<int>> search;
        search.push({row, col, 0});
        while(!search.empty()){

            auto top = search.front();
            auto r = top[0];
            auto c = top[1];
            auto distance = top[2];
            search.pop();

            if(r>=numRows || r<0 || c>=numCols || c<0){
                continue;
            }

            if(visited[r][c]){
                continue;
            }
            visited[r][c] = true;

            if(grid[r][c]==-1){
                continue;
            }

            if(grid[r][c]==0){
                grid[row][col] = distance;
                cout<<"closest treasure to "<<row<<"  "<<col<<" is"<<distance<<'\n';
                return;
            }

            search.push({r-1, c, distance+1});
            search.push({r+1, c, distance+1});
            search.push({r, c-1, distance+1});
            search.push({r, c+1, distance+1});

        }

    }

    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //start from the treasure and explore out 
        for(int row=0; row<grid.size(); ++row){
            for(int col=0; col<grid[0].size(); ++col){
                //land found
                if(grid[row][col]==INF){
                    search(grid, row, col);
                }

            }
        }

    }
};
