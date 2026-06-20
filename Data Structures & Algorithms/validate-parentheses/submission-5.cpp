class Solution {
public:
    bool isValid(string s) {
        //add all of the openings to a stack 
        //when you see a closing pop off the top of the stack and see if it is corresponding 
        //make sure stack is empty at the end 
        stack<char> parens;
        for(char character: s){
            cout<<character;
            if(character =='(' || character =='{' || character =='['){
                parens.push(character);
            }
            if(character==')' && !parens.empty() && parens.top()!='('){
                return false;
            }
            if(character==')' && parens.empty()){
                return false;
            }
            if(character=='}' && !parens.empty() && parens.top()!='{'){
                return false;
            }
            if(character=='}' && parens.empty()){
                return false;
            }
            if(character==']' && !parens.empty() && parens.top()!='['){
                return false;
            }
            if(character==']' && parens.empty()){
                return false;
            }
            if(character ==')' || character =='}' || character ==']'){
                parens.pop();
            }
            cout<<character<<'\n';
        } 
        if(!parens.empty()){
            return false;
        }
        return true;
    }
};
