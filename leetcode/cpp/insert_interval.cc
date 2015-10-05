class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		int flag = false;
		vector<Interval> ret;
		int i = 0;
		while (i < intervals.size()) {
			if (intervals[i].end < newInterval.start) {
				ret.push_back(intervals[i]);
				i++;
			} else if (intervals[i].start > newInterval.end) {
				if (!flag && (i == 0 || i > 0 && intervals[i - 1].end < newInterval.start)) {
					ret.push_back(newInterval);
					flag = true;
				}
				ret.push_back(intervals[i]);
				i++;
			} else {
				int start = (intervals[i].start < newInterval.start) ? intervals[i].start : newInterval.start,
					end = (intervals[i].end > newInterval.end) ? intervals[i].end : newInterval.end;
				i++;
				while (i < intervals.size() && intervals[i].start <= end) {
					end = (end < intervals[i].end) ? intervals[i].end : end;
					i++;
				}
				ret.push_back(Interval(start, end));
				flag = true;
			}
		}
		if (!flag)
			ret.push_back(newInterval);
		return ret;
	}
};
