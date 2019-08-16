template <typename T>
void __merge(T arr[], int l, int m, int r) {
  T aux[r - l + 1];
  for (int i = l; i <= r; ++i) {
    aux[i - l] = arr[i];
  }
  int i = l, j = m + 1;
  for (int k = l; k <= r; ++k) {
    if (i > m) {
      arr[k] = aux[j - l];
      ++j;
    } else if (j > r) {
      arr[k] = aux[i - l];
      ++i;
    } else if (aux[i - l] < aux[j - l]) {
      arr[k] = aux[i - l];
      ++i;
    } else {
      arr[k] = aux[j - l];
      ++j;
    }
  }
}

// could be used for sort for linked list
template <typename T>
void mergeSortBottomUp(T arr[], int n) {
  for (int sz = 1; sz <= n; sz += sz) {
    for (int i = 0; i + sz < n; i += 2 * sz) {
      // if not in order, merge
      if (arr[i + sz - 1] > arr[i + sz]) {
        __merge(arr, i, i + sz - 1, min(n - 1, i + 2 * sz - 1));
      }
    }
  }
}