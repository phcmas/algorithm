#include <iostream>
#include <vector>

std::vector<std::vector<int>> cache;

int max (int fst, int snd) {
    if (fst <= snd) return snd;
    else return fst;
}

void InitializeCache() {
    for (int i=0; i<100; ++i) {
        cache[i].clear();
    }
}

std::vector<int> LIS (std::vector<int> &sequence, int start_index) {
    std::vector<int> &ret = cache[start_index];
    if (ret.size() !=0) return ret;
        
        
    ret.push_back(sequence[start_index]);
    for (int i=start_index+1; i<sequence.size(); ++i) {
        if (sequence[start_index]< sequence[i]) {
            std::vector<int> lis = LIS(sequence,i);
            if (1+lis.size() > ret.size()) {
                ret.clear();
                ret.push_back(sequence[start_index]);
                for (int j=0; j<lis.size(); ++j) {
                    ret.push_back(lis[j]);
                }
            }
        }
    }

    return ret;
}

std::vector<int> MergeSequence (std::vector<int> &first_sequence, std::vector<int> &second_sequence) {
    int i=0,j=0;
    std::vector<int> merged_sequence;

    while (i<first_sequence.size()|| j< second_sequence.size()) {
        if (i == first_sequence.size()) {
            for (int k=j; k<second_sequence.size(); ++k) {
                merged_sequence.push_back(second_sequence[k]);
            }
            break;
        } else if (j == second_sequence.size()) {
            for (int k=i; k<first_sequence.size(); ++k) {
                merged_sequence.push_back(first_sequence[k]);
            }
            break;
        }

        if (first_sequence[i] == second_sequence[j]) {
            merged_sequence.push_back(first_sequence[i]);
            i++,j++;
        } else if (first_sequence[i] < second_sequence[j]) {
            merged_sequence.push_back(first_sequence[i]);
            i++;
        } else {
            merged_sequence.push_back(second_sequence[j]);
            j++;
        }
    }

    return merged_sequence;
}

int JLIS (std::vector<int> &first_sequence, std::vector<int> &second_sequence) {
    int answer = 0;
    
    for (int i=0; i<first_sequence.size(); ++i) {
        InitializeCache();
        std::vector<int> lis_from_first_sequence = LIS(first_sequence,i);
        std::vector<int> merged_sequence = MergeSequence(second_sequence, lis_from_first_sequence);
        InitializeCache();

        for (int j=0; j<merged_sequence.size(); ++j) {
            std::vector<int> lis_from_merged_sequence = LIS(merged_sequence,j);
            answer = max(answer, lis_from_merged_sequence.size());
        }
    }

    for (int i=0; i<second_sequence.size(); ++i) {
        InitializeCache();
        std::vector<int> lis_from_second_sequence = LIS(second_sequence,i);
        std::vector<int> merged_sequence = MergeSequence(first_sequence, lis_from_second_sequence);
        InitializeCache();

        for (int j=0; j<merged_sequence.size(); ++j) {
            std::vector<int> lis_from_merged_sequence = LIS(merged_sequence,j);
            answer = max(answer, lis_from_merged_sequence.size());
        }
    }

    return answer;

}

int main() {
    int number_of_test_cases = 1;
    std::vector<int> answers;
    cache.resize(120);
    std::cin >>number_of_test_cases;

    for (int i=0; i< number_of_test_cases; ++i) {
        int first_sequence_length = 0;
        int second_sequence_length = 0;
        std::vector<int> first_sequence; 
        std::vector<int> second_sequence;
        std::cin >> first_sequence_length;
        std::cin >> second_sequence_length;

          for (int j=0; j<first_sequence_length; ++j) {
              int element = 0;
              std::cin >> element;
              first_sequence.push_back(element);
          }

         for (int j=0; j<second_sequence_length; ++j) {
             int element = 0;
             std::cin >> element;
             second_sequence.push_back(element);
         }
        answers.push_back(JLIS(first_sequence,second_sequence));
    }

    for (int i=0; i<number_of_test_cases; ++i) {
        std::cout << answers[i]<< std::endl;
    }

    return 0;
}