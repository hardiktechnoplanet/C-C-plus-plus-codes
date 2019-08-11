class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // we will use 2 pointers, one pointing at the starting (i) of the 
        //vector and other at the end (j). We will find the area of the rectangle
        //and it will be limited by the smaller line. If i points to smaller line,
        //increment it otherwise decrement j
        
        int i=0,j=height.size()-1;
        int maxArea=INT_MIN;
        
        while(i<j)
        {
            int minLen=min(height[i],height[j]);
            maxArea=max(maxArea,minLen*(j-i));
            
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxArea;
        
    }
};
