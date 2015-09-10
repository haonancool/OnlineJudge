class Solution {
public:
	int maxPoints(vector<Point> &points) {
		if (points.size() <= 2)
			return points.size();
		int ret = 0;
		unordered_map<double, int> table;
		for (int i = 0; i < points.size(); i++) {
			int duplicate = 1, vertical = 0;
			for (int j = i + 1; j < points.size(); j++) {
				if (points[i].x == points[j].x) {
					if (points[i].y == points[j].y)
						duplicate++;
					else
						vertical++;
				} else {
					double slope = 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
					table[slope]++;
				}
			}
			for (auto &j : table) {
				if (ret < j.second + duplicate)
					ret = j.second + duplicate;
			}
			if (ret < vertical + duplicate)
				ret = vertical + duplicate;
			table.clear();
		}
		return ret;
	}
};
