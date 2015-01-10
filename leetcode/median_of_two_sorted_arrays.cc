class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) & 0x1)
      return findKth((m + n + 1) / 2, A, m, B, n);
    else
      return (findKth((m + n) / 2, A, m, B, n) + findKth((m + n) / 2 + 1, A, m, B, n)) / 2;
  }
  double findKth(int k, int A[], int m, int B[], int n) {
    if (m > n)
      return findKth(k, B, n, A, m);
    if (0 == m)
      return B[k - 1];
    if (1 == k) {
      if (A[0] < B[0])
        return A[0];
      else
        return B[0];
    }
    int i = k / 2;
    i = (i > m) ? m : i;
    int j = k - i;
    int va = A[i - 1], vb = B[j - 1];
    if (va <= vb)
      return findKth(k - i, A + i, m - i, B, n);
    else
      return findKth(k - j, A, m, B + j, n - j);
  }
};
