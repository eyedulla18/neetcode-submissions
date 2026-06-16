class Solution {
public:

    const int rowSize=9;
    const int colSize=9;

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<int>> rowSets, colSets;
        unordered_map<int, unordered_map<int, set<int>>> smallSquareSets;
        for(int row=0; row<rowSize; ++row){
            for(int col=0; col<colSize; ++col){
                char curNum = board[row][col];
                if(curNum=='.'){
                    continue;
                }
                if(colSets[col].find(curNum)!=colSets[col].end()){
                    return false;
                }
                if(rowSets[row].find(curNum)!=rowSets[row].end()){
                    return false;
                }
                if(smallSquareSets[row/3][col/3].find(curNum)!=smallSquareSets[row/3][col/3].end()){
                    return false;
                }
                smallSquareSets[row/3][col/3].insert(curNum);
                colSets[col].insert(curNum);
                rowSets[row].insert(curNum);
            }
        }
        return true;
    }
};
