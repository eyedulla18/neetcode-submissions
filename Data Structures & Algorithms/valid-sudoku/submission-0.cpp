class Solution {
public:

    bool checkRow(vector<vector<char>>& board) {
        for(size_t i=0; i<9; ++i){
            set<char> rowSet;
            for(size_t j=0; j<9; ++j){
                char num = board[i][j];
                if(num=='.'){
                    continue;
                }
                if(rowSet.find(num)!=rowSet.end()){
                    cout<<"check row duplicate: "<<"row: "<<i<<"  col: "<< j;
                    return false;
                }
                rowSet.insert(num);
            }
        }
        return true;
        
    }

    bool checkCol(vector<vector<char>>& board) {
        for(size_t i=0; i<9; ++i){
            set<char> colSet;
            for(size_t j=0; j<9; ++j){
                char num = board[j][i];
                if(num=='.'){
                    continue;
                }
                if(colSet.find(num)!=colSet.end()){
                    cout<<"check col duplicate: "<<"row: "<<j<<"  col: "<< i;
                    return false;
                }
                colSet.insert(num);
            }
        }
        return true;
        
    }
    bool checkSubSquare(vector<vector<char>>& board){
        for(int rowStart=0; rowStart<8; rowStart+=3){
            for(int colStart=0; colStart<8; colStart+=3){

                set<char> gridSet;
                for(int i=rowStart; i<rowStart+3; ++i){
                    for(int j=colStart; j<colStart+3; ++j){
                        char num = board[i][j];
                        if(num=='.'){
                            continue;
                        }
                        if(gridSet.find(num)!=gridSet.end()){
                            cout<<"check grid duplicate: "<<"row: "<<j<<"  col: "<< i;
                            return false;
                        }
                        gridSet.insert(num);

                    }
                }


            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRow(board) && checkCol(board) && checkSubSquare(board);

    }
};
