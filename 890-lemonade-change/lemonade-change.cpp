class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int tw = 0;


        if(bills[0] == 10 || bills[0] == 20)
        {
            return false;
        }

        for(int i = 0; i<bills.size(); i++)
        {
            if(bills[i] == 5)
            {
                five++;
            }
            else if(bills[i] == 10)
            {
                if(five > 0)
                {
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(ten>0 && five > 0)
                {
                    ten--;
                    five--;
                    tw++;
                }
                else if(ten == 0 && five > 2)
                {
                    five -= 3;

                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};