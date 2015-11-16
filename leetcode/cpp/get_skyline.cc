struct MyPoint {
    int x;
    int h;
    bool is_start;
    MyPoint(int xx, int hh, bool start) : x(xx), h(hh), is_start(start) {}
};

bool ComparePoint(const MyPoint &lhs, const MyPoint &rhs) {
    if (lhs.x != rhs.x)
        return lhs.x < rhs.x;
    if (lhs.is_start && rhs.is_start)
        return lhs.h > rhs.h;
    if (!lhs.is_start && !rhs.is_start)
        return lhs.h < rhs.h;
    return lhs.is_start;
}

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<MyPoint> points;
        for (auto &building : buildings) {
            points.emplace_back(building[0], building[2], true);
            points.emplace_back(building[1], building[2], false);
        }
        sort(points.begin(), points.end(), ComparePoint);
        map<int, int> table;
        vector<pair<int, int>> ret;
        for (auto &point : points) {
            if (point.is_start) {
                if (table.empty() || point.h > table.rbegin()->first)
                    ret.push_back(make_pair(point.x, point.h));
                table[point.h]++;
            } else {
                table[point.h]--;
                if (table[point.h] == 0)
                    table.erase(point.h);
                if (table.empty())
                    ret.push_back(make_pair(point.x, 0));
                else if (point.h > table.rbegin()->first)
                    ret.push_back(make_pair(point.x, table.rbegin()->first));
            }
        }
        return ret;
    }
};