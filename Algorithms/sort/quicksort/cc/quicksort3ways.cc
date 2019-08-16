template <typename T>
void __quickSort3ways(T arr[], int l, int r) {
  if (l >= r) {
    return;
  }
  swap(arr[rand() % (r - l + 1) + l], arr[l]);
  T v = arr[l];

  int lt = l;      // [l+1...lt] < v
  int gt = r + 1;  // [gt...r] > v
  int i = l + 1;   // [lt+1...gt-1] == v
  while (i < gt) {
    if (arr[i] < v) {
      swap(arr[++lt], arr[i]);
      ++i;
    } else if (arr[i] > v) {
      swap(arr[--gt], arr[i]);
    } else {
      ++i;
    }
  }
  swap(arr[l], arr[lt]);
  __quickSort3ways(arr, l, lt - 1);
  __quickSort3ways(arr, gt, r);
}

template <typename T>
void quickSort3ways(T arr[], int n) {
  srand(time(nullptr));
  __quickSort3ways(arr, 0, n - 1);
}