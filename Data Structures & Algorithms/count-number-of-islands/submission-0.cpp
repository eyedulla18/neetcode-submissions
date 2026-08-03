class Solution {
public:

    void search(vector<vector<char>>& grid, int row, int col){
        cout<<"start search: "<<row<<"  "<<col<<"\n\n";
        vector<pair<int, int>> s;
        s.push_back({row,col});
        while(!s.empty()){
            int r = s.back().first;
            int c = s.back().second;
            // cout<<"current: "<<r<<"  "<<c<<" value: "<<grid[r][c]<<'\n';
            s.pop_back();

            //validate r and c
            if(r>=grid.size() || r<0 || c>=grid[0].size() || c<0){
                cout<<"validation failed: "<<r<<"  "<<c<<'\n';
                continue;
            }

            if(grid[r][c]=='0'){
                continue;
            }
            if(grid[r][c]=='1'){
                grid[r][c] = '0';
                cout<<"updated: "<<grid[r][c]<<"\n";
            }

            s.push_back({r-1, c});
            s.push_back({r+1, c});
            s.push_back({r, c-1});
            s.push_back({r, c+1});
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        for(int row=0; row<grid.size(); ++row){
            for(int col=0; col<grid[0].size(); ++col){

                if(grid[row][col]=='1'){
                    ++answer;
                    //mark nearby as visited
                    search(grid, row, col);
                }
            }
        }
        return answer;

    }
};
