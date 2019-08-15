// 2 ways quick sort with random chosen first element
template <typename T>
int __partition2ways(T arr[], int l, int r) {
  swap(arr[rand() % (r - l + 1) + l], arr[l]);  // random choose
  T v = arr[l];
  // [l+1...j] < v, [j+1...i) > v
  int j = l;
  for (int i = l + 1; i <= r; ++i) {
    if (arr[i] < v) {
      swap(arr[++j], arr[i]);
    }
  }
  swap(arr[j], arr[l]);
  return j;
}

template <typename T>
void __quickSort2ways(T arr[], int l, int r) {
  if (l >= r) {
    return;
  }
  int p = __partition2ways(arr, l, r);
  __quickSort2ways(arr, l, p - 1);
  __quickSort2ways(arr, p + 1, r);
}

template <typename T>
void quickSort2ways(T arr[], int n) {
  srand(time(NULL));
  __quickSort2ways(arr, 0, n - 1);
}