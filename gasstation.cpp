class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot_fuel_have=0,tot_fuel_needed=0;
        for(int i=0;i<gas.size();i++)
            tot_fuel_have+=gas[i];
        for(int i=0;i<cost.size();i++)
            tot_fuel_needed+=cost[i];
        if(tot_fuel_have<tot_fuel_needed)
            return -1;
        int cur_fuel=0,start=0;
        for(int i=0;i<gas.size();i++)
        {
            cur_fuel+=gas[i]-cost[i];
            if(cur_fuel<0)
                start=i+1,cur_fuel=0;
        }return (start>=gas.size()?0:start);
    }
};
