class Solution {
public:

    struct Search {
        vector<vector<char>> board;
        string word;
        int x;
        int y;
    };

    bool exist(vector<vector<char>>& board, string word) {
        //find all of the starting places 
        int numRows = board.size();
        int numCols = board[0].size();

        vector<Search> search;
        for(int row=0; row<numRows; ++row){
            for (int col=0; col<numCols; ++col){
                if(board[row][col]==word.back()){
                    auto boardCopy = board;
                    auto wordCopy = word;
                    boardCopy[row][col] = '.';
                    wordCopy.pop_back();

                    Search curState;
                    curState.board = boardCopy;
                    curState.word = wordCopy;
                    curState.x=row;
                    curState.y=col;
                    search.push_back(curState);
                }
            }
        }
        cout<<search.size()<<'\n';

        while(!search.empty()){
            auto curSearch = search.back();
            search.pop_back();

            auto curSearchBoard = curSearch.board;
            int curX = curSearch.x;
            int curY = curSearch.y;
            string curSearchWord = curSearch.word;
            if(curSearchWord.empty()){
                return true;
            }
            
            //search up 
            if(curY-1>=0 && curSearchBoard[curX][curY-1]==curSearchWord.back()){
                auto curSearchCopy = curSearch;
                curSearchCopy.y = curY-1;
                curSearchCopy.board[curX][curY-1] = '.';
                curSearchCopy.word.pop_back();
                search.push_back(curSearchCopy);
            }

            //search down 
            if(curY+1<numCols && curSearchBoard[curX][curY+1]==curSearchWord.back()){
                auto curSearchCopy = curSearch;
                curSearchCopy.y = curY+1;
                curSearchCopy.board[curX][curY+1] = '.';
                curSearchCopy.word.pop_back();
                search.push_back(curSearchCopy);
            }

            //search right 
            if(curX+1<numRows && curSearchBoard[curX+1][curY]==curSearchWord.back()){
                auto curSearchCopy = curSearch;
                curSearchCopy.x = curX+1;
                curSearchCopy.board[curX+1][curY] = '.';
                curSearchCopy.word.pop_back();
                search.push_back(curSearchCopy);
            }
            //search left 
            if(curX-1>=0 && curSearchBoard[curX-1][curY]==curSearchWord.back()){
                auto curSearchCopy = curSearch;
                curSearchCopy.x = curX-1;
                curSearchCopy.board[curX-1][curY] = '.';
                curSearchCopy.word.pop_back();
                search.push_back(curSearchCopy);
            }
        }


        return false;
    }
};
