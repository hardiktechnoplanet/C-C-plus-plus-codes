//see leetcode solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total_tank=0, curr_tank=0, starting_station=0;
        
        /*start from the first gas station and keep track of total tank so far
        and curr tank. If at any station the curr tank <0 it means that we can not
        reach here. So, change the starting station to next of that station and make
        curr tank to 0 again*/
        for(size_t i=0;i<gas.size();++i)
        {
            total_tank +=gas[i]-cost[i];
            curr_tank +=gas[i]-cost[i];
            
            //if the current tank is empty=>we can not get here,so update
            //the starting station to next station
            if(curr_tank<0)
            {
                starting_station=i+1;
                //start with the empty tank
                curr_tank=0;
            }
        }
        if(total_tank<0)
            return -1;
        return starting_station;
    }
};
