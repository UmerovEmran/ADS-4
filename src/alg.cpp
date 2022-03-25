// Copyright 2021 NNTU-CS
int sch;
int countPairs1(int *arr, int len, int value) {
  int otvet;
  for ( int i = 0; i < len; i++ ) {
    for ( int j = 0; j < len - i - 1; j++ ) {
      if ( arr[j] > arr[j + 1] ) {
        int per = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = per;
      }
    }
  }
  for ( int i = 0; i < len ; i++ ) {
    for ( int j = i + 1; j < len; j++ ) {
      int summ = arr[i] + arr[j];
      if (summ == value) {
        otvet += 1;
      }
      summ = 0;
    }
  }
  return otvet;
}
int countPairs2(int *arr, int len, int value) {
  int o;
  int gran;
  int otvet;
  for ( int i = 0; i < len; i++ ) {
    for ( int j = 0; j < len - i - 1; j++ ) {
      if ( arr[j] > arr[j + 1] ) {
        int per = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = per;
      }
    }
  }
  int porog = (value - arr[0]);
  for ( o = 1; o < len; o++ ) {
    if (arr[o] == porog) {
      break;
    }
  }
  for ( int i = 0; i < len; i++ ) {
    for ( int j = o; j > i; j-- ) {
      int summ = arr[i] + arr[j];
      if (summ == value) {
        otvet += 1;
      }
    }
  }
  return otvet;
}
int cbinsearch(int *arr, int k, int value);
int countPairs3(int *arr, int len, int value) {
  int porog;
  int otvet = 0;
  for ( int i = 0; i < len; i++ ) {
    for ( int j = 0; j < len - i - 1; j++ ) {
      if ( arr[j] > arr[j + 1] ) {
        int per = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = per;
      }
    }
  }
  for ( int i = 0; i < len; i++ ) {
    int porog = value - arr[i];
    cbinsearch(arr, len, porog);
    otvet += sch;
  }
  otvet = otvet / 2;
  return otvet;
}
int cbinsearch(int *arr, int k, int value) {
  int irr[k];
  for ( int i = 0; i  < k; i++ ) {
    irr[i] = arr[i];
  }
  bool cr;
  sch = 0;
  while (true) {
    int last = k - 1;
    int start = 0;
    cr = true;
    while (start < last) {
      int pol = (last - start) / 2 + start;
      if (irr[pol] == value) {
        for ( int i = pol; i < k; i++ ) {
          irr[i] = irr[i + 1];
        }
        sch += 1;
        k -= 1;
        cr = false;
        break;
      } else if (irr[pol] > value) {
          last = pol;
      } else {
          start = pol;
          start += 1;
      }
    }
    if (irr[start] == value && start == last) {
      sch += 1;
    }
    if (cr) {
      break;
    }
  }
  return sch;
  return 0;
}
