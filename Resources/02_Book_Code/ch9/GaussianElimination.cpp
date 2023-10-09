#include <cmath>
#include <cstdio>
using namespace std;

#define MAX_N 3                              // adjust this value as needed
struct AugmentedMatrix { double mat[MAX_N][MAX_N + 1]; };
struct ColumnVector { double vec[MAX_N]; };

ColumnVector GaussianElimination(int N, AugmentedMatrix Aug) {
  // input: N, Augmented Matrix Aug, output: Column vector X, the answer
  int i, j, k, l; double t;

  for (i = 0; i < N - 1; i++) {            // the forward elimination phase
    l = i;
    for (j = i + 1; j < N; j++)       // which row has largest column value
      if (fabs(Aug.mat[j][i]) > fabs(Aug.mat[l][i]))
        l = j;                                       // remember this row l
    // swap this pivot row, reason: minimize floating point error
    for (k = i; k <= N; k++)            // t is a temporary double variable
      t = Aug.mat[i][k], Aug.mat[i][k] = Aug.mat[l][k], Aug.mat[l][k] = t;
    for (j = i + 1; j < N; j++)     // the actual forward elimination phase
      for (k = N; k >= i; k--)
        Aug.mat[j][k] -= Aug.mat[i][k] * Aug.mat[j][i] / Aug.mat[i][i];
  }

  ColumnVector Ans;                          // the back substitution phase
  for (j = N - 1; j >= 0; j--) {                         // start from back
    for (t = 0.0, k = j + 1; k < N; k++) t += Aug.mat[j][k] * Ans.vec[k];
    Ans.vec[j] = (Aug.mat[j][N] - t) / Aug.mat[j][j]; // the answer is here
  }
  return Ans;
}

int main() {
  AugmentedMatrix Aug;
  Aug.mat[0][0] = 1; Aug.mat[0][1] = 1; Aug.mat[0][2] = 2; Aug.mat[0][3] = 9;
  Aug.mat[1][0] = 2; Aug.mat[1][1] = 4; Aug.mat[1][2] = -3; Aug.mat[1][3] = 1;
  Aug.mat[2][0] = 3; Aug.mat[2][1] = 6; Aug.mat[2][2] = -5; Aug.mat[2][3] = 0;

  ColumnVector X = GaussianElimination(3, Aug);
  printf("X = %.1lf, Y = %.1lf, Z = %.1lf\n", X.vec[0], X.vec[1], X.vec[2]);

  return 0;
}
