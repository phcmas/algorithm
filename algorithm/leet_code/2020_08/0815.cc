 #include <vector>
 #include <map>
 #include <cstring>

 using namespace std;
 

// 아직 풀지 못한 문제

 bool isOverlapped(vector<int> &fst, vector<int> &snd) {
    int fstart = fst.front();
    int fend = fst.back();
    int sstart = snd.front();
    int send = snd.back();

    if (fstart == send  || sstart == fend) return false;
    if ((sstart <= fstart && fstart <= send) || (sstart <= fend && fend <= send)) return true;
    if ((fstart <= sstart && sstart <= fend) || (fstart <= send && send <= fend)) return true;  
    return false;
}

 int eraseOverlapIntervals(vector<vector<int>>& intervals) {
     int countOfIntervals = intervals.size();
     int totalCount = 0;
     int answer = 0;
     vector<int> numOfOverlap;
     numOfOverlap.resize(countOfIntervals);
     for (int i=0; i< countOfIntervals; ++i) numOfOverlap[i] = 0;
     bool overlap[countOfIntervals][countOfIntervals];
     bool erased[countOfIntervals];

     memset(overlap, false, sizeof(overlap));
     memset(erased, false, sizeof(erased));
     
     for (int i=0; i< countOfIntervals; ++i) {
        for (int j=i+1; j< countOfIntervals; ++j) {
            if (isOverlapped(intervals[i], intervals[j])) {
                numOfOverlap[i]++;
                numOfOverlap[j]++;
                totalCount++;
                overlap[i][j] = true;
            }
        }
    }

    while (totalCount > 0) {
        int maxIndex = 0;
        for (int i=0; i< countOfIntervals; ++i) {
            if (erased[i]) continue;
            else {
                maxIndex = i;
                break;
            }
        }

        for (int i=0; i<countOfIntervals; ++i) {
            if (!erased[i] && numOfOverlap[i] > numOfOverlap[maxIndex]) { 
                maxIndex = i;
            }
        }

        erased[maxIndex] = true;
        totalCount -= numOfOverlap[maxIndex];

        for (int i=0; i< maxIndex; ++i) {
            if (overlap[i][maxIndex]) numOfOverlap[i]--;
        }

        for (int i=maxIndex+1; i<countOfIntervals; ++i) {
            if (overlap[maxIndex][i]) numOfOverlap[i]--;
        }
        answer++;
    }

    return answer;
}
    




int main() {
    vector<int> fst {0,1};
    vector<int> snd {3,4};
    vector<int> thd {1,2};
    vector<vector<int>> intervals{fst,snd,thd};

    int answer = eraseOverlapIntervals(intervals);

    
    return 0;
}