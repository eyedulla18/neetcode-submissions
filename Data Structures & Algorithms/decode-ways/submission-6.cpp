class Solution {
public:

    unordered_map<string, bool> cache;
    bool validate(string s){

        if(cache.find(s)!=cache.end()){
            return cache[s];
        }

        //check for leading 0
        if(s.size()==2 && s[0]=='0'){
            cache[s] = false;
            return false;
        }
        //convert s to int 
        //check if int is between 1 and 26
        int num = stoi(s);
        if(num<=26 && num>0){
            cache[s] = true;
            return true;
        }
        cache[s] = false;
        return false;
    }


    int numDecodings(string s) {
        vector<int> memo(s.size(), 0);
        if(s[0]=='0'){
            return 0;
        }
        if(s.size()==1){
            return 1;
        }

        {
            string init{s[0]};
            if(validate(init)){
                memo[0] = 1;
            }
            init+=s[1];
            if(validate(init) && s[1]=='0'){
                memo[1] = 1;
            }
            else if(validate(init)){
                memo[1] = 2;
            }
            else if(s[1]=='0'){
                memo[1] = 0;
            }
            else{
                memo[1] = 1;
            }
        }
        // "226"
        //  1,1,
        for(int i=2; i<memo.size(); ++i){
            // memo[i] = memo[i-1] + memo[i-2];

            //can current stand alone?
            if(s[i]!='0'){
                memo[i] = memo[i-1];
            }
            else{
                cout<<"is zero \n";
            }
            //if current can be combined with the previous 
            string combined{s[i-1]};
            combined+=s[i];
            if(validate(combined)){
                memo[i]+=memo[i-2];
            }
        }
        for(auto m: memo){
            cout<<m<<" ";
        }
        cout<<'\n';
        return memo.back();

        

    }
};
