#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct Rectangle {
    long long x1, x2, y1, y2;
    Rectangle(long long _x1, long long _x2, long long _y1, long long _y2) : x1(_x1), x2(_x2), y1(_y1), y2(_y2) {}
    bool operator<(const Rectangle& rhs) const {
        return x1 < rhs.x1;
    }
};
 
long long unionArea(const vector<Rectangle>& rects);
 
int main() {
 
    long long t; cin >> t;
    while(t--){
    long long n; cin >> n;
    vector<Rectangle> rects;
    while (n--) {
        long long x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        rects.push_back(Rectangle(x1, x2, y1, y2));
    }
 
    cout << unionArea(rects) << endl;
    }
    return 0;
}
 
long long unionArea(const vector<Rectangle>& rects) {
    if (rects.empty()) return 0;
 
    typedef pair<long long, pair<long long, long long> > Event;
    vector<long long> ys;
    vector<Event> events;
    for (long long i = 0; i < rects.size(); i++) {
        ys.push_back(rects[i].y1);
        ys.push_back(rects[i].y2);
        events.push_back(Event(rects[i].x1, make_pair(1, i)));
        events.push_back(Event(rects[i].x2, make_pair(-1, i)));
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    sort(events.begin(), events.end());
 
    long long ret = 0;
    vector<long long> count(ys.size() - 1, 0);
    for (long long i = 0; i < events.size(); i++) {
        long long x = events[i].first, delta = events[i].second.first;
        long long rectangle = events[i].second.second;
 
        long long y1 = rects[rectangle].y1, y2 = rects[rectangle].y2;
        for (long long j = 0; j < ys.size(); j++) {
            if (y1 <= ys[j] && ys[j] < y2) {
                count[j] += delta;
            }
        }
        long long cutLength = 0;
        for (long long j = 0; j< ys.size() - 1; j++)
            if (count[j]>0) cutLength += ys[j + 1] - ys[j];
        if (i + 1 < events.size()) ret += cutLength*(events[i + 1].first - x);
    }
    return ret;
}
