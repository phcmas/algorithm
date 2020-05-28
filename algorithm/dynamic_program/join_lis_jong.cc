#include <iostream>
#include <list>
#include <cstring>
#include <limits>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];
int answers[50];

int jlis(int indexA, int indexB) {
  int ret = cache[indexA + 1][indexB + 1];
  if(ret != -1) return ret;
  ret = 2;

  long long a = (indexA == -1 ? NEGINF : A[indexA]);
  long long b = (indexB == -1 ? NEGINF : B[indexB]);
  long long maxElement = max(a, b);

  for(int nextA = indexA + 1; nextA < n; ++nextA) {
    if (maxElement < A[nextA]) {
      ret = max(ret, jlis(nextA, indexB) + 1);
    }
  }

  for(int nextB = indexB + 1; nextB < m; ++nextB) {
    if (maxElement < B[nextB]) {
      ret = max(ret, jlis(indexA, nextB) + 1);
    }
  }
  return ret;
}

int main() {
  int testCaseCount;
  scanf("%d", &testCaseCount);
  
  for (int i=0;i<testCaseCount; ++i) {
    scanf("%d", &n);
    scanf("%d", &m);
    memset(cache, -1, sizeof(int) * 101 * 101);

    for (int i=0; i < n; i++) {
      scanf("%d", &A[i]);
    }
    for (int i=0; i < m; i++) {
        scanf("%d",&B[i]);
    }
    
    answers[i]= jlis(-1, -1) - 2;
  }

  for (int i=0;i<testCaseCount;++i) {
      printf("%d\n", answers[i]);
  }
}