/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    queue<int> q;
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        //traverse through the vector
        for(size_t i=0;i<nestedList.size();++i)
        {
            //if the current element is an int
            if(nestedList[i].isInteger())
            {
                q.push(nestedList[i].getInteger());
            }
            //current element is a list
            else
            {
                helper(nestedList[i].getList());
            }
        }
        
    }
    void helper(vector<NestedInteger>& nestedList)
    {
        for(size_t i=0;i<nestedList.size();++i)
        {
            //if the list contains int
            if(nestedList[i].isInteger())
            {
                q.push(nestedList[i].getInteger());
            }
            //list contains list
            else
            {
                helper(nestedList[i].getList());
            }
        }
        
    }

    int next() 
    {
        int res=0;;
        if(hasNext())
        {
            res=q.front();
            q.pop();
        }
        return res;
        
    }

    bool hasNext() 
    {
        if(q.size()>0)
            return true;
        return false;
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
