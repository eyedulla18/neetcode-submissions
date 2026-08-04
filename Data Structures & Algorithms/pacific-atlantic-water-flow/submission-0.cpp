class Solution {
public:

    bool isPacific(int row, int col, vector<vector<int>>& heights){
        //left and top assuming valid row and col
        if(row==0 || col==0){
            cout<<"Pacific discovered \n";
            return true;
        }
        return false;
    }

    bool isAtlantic(int row, int col, vector<vector<int>>& heights){
        int numRows = heights.size();
        int numCols = heights[0].size();
        if(numRows-1==row || numCols-1==col){
            cout<<"Atlantic discovered \n";
            return true;
        }
        return false;
    }

    bool search(int row, int col, vector<vector<int>>& heights){

        bool pacific = false;
        bool atlantic = false;
        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(), false));

        //row, col, prev
        queue<vector<int>> search;
        search.push({row, col, 1001});

        while(!search.empty()){
            int curRow = search.front()[0];
            int curCol = search.front()[1];
            int prevHeight = search.front()[2];
            search.pop();

            if(curRow<0 || curCol<0 || curRow>= heights.size()|| curCol>=heights[0].size()){
                continue;
            }
            if(visited[curRow][curCol]){
                continue;
            }
            if(heights[curRow][curCol]>prevHeight){
                continue;
            }

            pacific = pacific || isPacific(curRow, curCol, heights);
            atlantic = atlantic || isAtlantic(curRow, curCol, heights);
            if(pacific&&atlantic){
                return true;
            }
            visited[curRow][curCol] = true;
            //check if cur is less than previous 
            // if(heights[curRow][curCol]<=prevHeight){

            // }

            search.push({curRow-1, curCol, heights[curRow][curCol]});
            search.push({curRow+1, curCol, heights[curRow][curCol]});
            search.push({curRow, curCol-1, heights[curRow][curCol]});
            search.push({curRow, curCol+1, heights[curRow][curCol]});
        }

        return pacific && atlantic;


    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer;
        for(int row=0; row<heights.size(); ++row){
            for(int col=0; col<heights[0].size(); ++col){
                if(search(row,col,heights)){
                    answer.push_back({row,col});
                }
            }
        }
        return answer;


    }
};
