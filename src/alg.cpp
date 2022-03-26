// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int otvet = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int summ = arr[i] + arr[j];
            if (summ == value) {
                otvet += 1;
            }
            summ = 0;
        }
    }
    return otvet;
}
int countPairs2(int* arr, int len, int value) {
    int o;
    int gran;
    int otvet = 0;
    int porog = (value - arr[0]);
    for (int i = 0; i < len; i++) {
    }
    for (o = 0; o < len; o++) {
        if (arr[o] > porog) {
            break;
        }
    }
    for (int i = 0; i < o; i++) {
        for (int j = o; j > i; j--) {
            int summ = arr[i] + arr[j];
            if (summ == value) {
                otvet += 1;
            }
        }
    }
    return otvet;
}

int cbinsearch(int* arr, int size, int porog, int adress) {
    int cnt = 0;
    int i = adress;
    int j = size;
    while (i < j - 1) {
        int mid = (i + j) / 2;
        if (arr[mid] > porog) {
            j = mid;
        } else if (arr[mid] < porog) {
            i = mid;
        } else {
            cnt += 1;
            int temp = mid + 1;
            while ((arr[temp] == porog) && (temp < j)) {
                cnt += 1;
                temp += 1;
            }
            temp = mid - 1;
            while ((arr[temp] == porog) && (temp > i)) {
                cnt += 1;
                temp -= 1;
            }
            break;
        }
    }
    return cnt;
}

int countPairs3(int* arr, int len, int value) {
    int porog;
    int otvet = 0;
    int o = 0;
    int porog_2 = (value - arr[0]);
    for (o = 0; o < len; o++) {
        if (arr[o] > porog_2) {
            break;
        }
    }
    for (int i = 0; i < o; i++) {
        int porog = value - arr[i];
        otvet += cbinsearch(arr, len, porog, i);
    }
    return otvet;
}
