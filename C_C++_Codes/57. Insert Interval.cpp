/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/*First, put all intervals that are to the left of the inserted interval.
Second, merge all intervals that intersect with the inserted interval.
Finally, put all intervals that are to the right of the inserted interval.*/

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
{
	int index=0;
	vector<Interval> result;
	
	//put all intervals that are to the left of the inserted interval
	while(index<intervals.size() && intervals[index].end < newInterval.start)
	{
		result.push_back(intervals[index++]);
	}
	
	//merge all intervals that intersect with the inserted interval
	while(index<intervals.size() && intervals[index].start <= newInterval.end)
	{
		newInterval.start=min(intervals[index].start, newInterval.start);
		newInterval.end=max(intervals[index].end, newInterval.end);
		index++;
	}
	result.push_back(newInterval);
	
	//put all intervals that are to the right of the inserted interval
	while(index<intervals.size())
	{
		result.push_back(intervals[index++]);
	}
	return result;
}
