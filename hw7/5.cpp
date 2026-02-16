#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool compareIntervals(Interval a, Interval b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end > b.end;
}

bool compareOutput(Interval a, Interval b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    int target_start, target_end;
    cin >> target_start >> target_end;

    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<Interval> result;
    int current_reach = target_start;
    int idx = 0;
    bool possible = true;

    while (current_reach < target_end) {
        int max_reach = -1;
        int best_index = -1;

        while (idx < n && intervals[idx].start <= current_reach) {
            if (intervals[idx].end > max_reach) {
                max_reach = intervals[idx].end;
                best_index = idx;
            }
            idx++;
        }

        if (best_index != -1 && max_reach > current_reach) {
            result.push_back(intervals[best_index]);
            current_reach = max_reach;
        } else {
            possible = false;
            break;
        }
    }

    if (possible) {
        sort(result.begin(), result.end(), compareOutput);
        cout << result.size() << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i].start << " " << result[i].end << endl;
        }
    }

    return 0;
}