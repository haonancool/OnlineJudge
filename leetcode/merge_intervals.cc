bool comp(const Interval &lhs, const Interval &rhs) {
	if (lhs.start < rhs.start)
		return true;
	return false;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> ret;
		sort(intervals.begin(), intervals.end(), comp);
		int i = 0;
		while (i < intervals.size()) {
			if (i < intervals.size() - 1 && intervals[i].end >= intervals[i + 1].start) {
				int start = intervals[i].start, end = intervals[i].end;
				i++;
				while (i < intervals.size() && end >= intervals[i].start) {
					end = (intervals[i].end > end) ? intervals[i].end : end;
					i++;
				}
				ret.push_back(Interval(start, end));
			} else {
				ret.push_back(intervals[i]);
				i++;
			}
		}
		return ret;
	}
};
