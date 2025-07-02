/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

 class Solution {
    public:
        /**
         * @param intervals: an array of meeting time intervals
         * @return: the minimum number of conference rooms required
         */
        int minMeetingRooms(vector<Interval> &intervals) {
            vector<int> starts;
            vector<int> ends;
            for (auto& interval : intervals) {
                starts.push_back(interval.start);
                ends.push_back(interval.end);
            }
            sort(starts.begin(), starts.end());
            sort(ends.begin(), ends.end());
            int s_ptr = 0, e_ptr = 0;
            int cnt = 0, maxCnt = 0;
            int n = intervals.size();
            while (s_ptr < n && e_ptr < n) {
                if (starts[s_ptr] < ends[e_ptr]) {
                    cnt++;
                    s_ptr++;
                } else {
                    cnt--;
                    e_ptr++;
                }
                maxCnt = max(maxCnt, cnt);
            }
            return maxCnt;
        }
    };