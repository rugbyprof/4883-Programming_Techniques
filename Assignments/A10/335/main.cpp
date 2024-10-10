#include <iostream>
#include <utility>
#include <vector>

using namespace std;

using Point           = std::pair<int, int>;
using Line            = std::pair<Point, Point>;
using PointCollection = std::vector<Point>;
using LineCollection  = std::vector<Line>;

class Solution {
   public:
    bool isSelfCrossing(vector<int> &distance) {
        int x1, y1, x2, y2, i, t;

        PointCollection points;
        LineCollection segments;

        // check if vector is too short
        if (distance.size() < 4) {
            return false;
        }

        // check if all values are the same
        t            = distance[0];
        bool allSame = true;
        for (auto &d : distance) {
            if (t != d) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            return true;
        }

        x1 = y1 = x2 = y2 = i = 0;
        for (auto &d : distance) {
            if (i % 4 == 0)
                y2 += d;
            else if (i % 4 == 1)
                x2 -= d;
            else if (i % 4 == 2)
                y2 -= d;
            else
                x2 += d;

            points.push_back(Point(x1, y1));
            points.push_back(Point(x2, y2));
            segments.push_back(Line(Point(x1, y1), Point(x2, y2)));
            i++;
            x1 = x2;
            y1 = y2;
        }
        for (auto &l : segments) {
            x1 = l.first.first;
            y1 = l.first.second;
            x2 = l.second.first;
            y2 = l.second.second;
            cout << x1 << "," << y1 << " : " << x2 << "," << y2 << endl;
        }

        return false;
    }
};