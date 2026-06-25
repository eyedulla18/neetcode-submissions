class Solution {
public:

    bool helper(vector<int>& piles, int h, int speed) {
        int numHours = 0;
        for(auto pile: piles){
            cout<<pile<<"/"<<speed<<'\n';
            auto tmp = pile/speed;
            if(pile%speed){
                ++tmp;
            }
            cout<<"adding hours: "<<tmp<<'\n';
            numHours += tmp;
        }
        cout<<numHours;
        if(numHours<=h){
            cout<<" true \n";
            return true;
        }
        cout<<" false \n";
        return false;
    }

    int search(vector<int>& piles, int maxPile, int h) {
        //the answer will be one of the values in the piles 
        int l=1;
        int r=maxPile;

        int count = 0;
        while(l<r && count<maxPile){
            ++count;
            int m = (l+r)/2;
            //if the mid point can support that speed
            if(helper(piles,h, m)){
                r=m;
            }
            //if the mid point can't support that speed
            else{
                l=m+1;
            }
            cout<<l<<"   "<<r<<'\n';
        }
        return l;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = piles[0];
        for(auto pile: piles){
            maxPile = max(maxPile, pile);
        }

        return search(piles, maxPile,h);
    }
};
//[1,2,3,4,5,6,7,8,9,10,11]




