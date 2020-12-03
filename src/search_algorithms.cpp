bool isSorted(const char* vector, int n) {
    int i = 0;
    char prev = vector[i];
    while (i < n && prev <= vector[i]) {
        prev = vector[i];
        ++i;
    }
    return i == n;
}

int findUsingLinearSearchWithABarrier(const char* vector, int n, char key) {
    int i = 0;
    while (i < n && vector[i] != key) {
        ++i;
    }
    return (i < n ? i : -1);
}

/*
 * -2 - вектор не отсортирован
 * -1 - ключ не найден
 * иначе - индекс ключа в векторе
 */
int findUsingInterpolationSearch(const char* vector, int n, char key) {
    if (!isSorted(vector, n)) {
        return -2;
    }
    int low = 0;
    int mid;
    int high = n - 1;
    while (vector[low] < key && vector[high] >= key) {
        mid = low + ((key - vector[low]) * (high - low)) / (vector[high] - vector[low]);
        if (vector[mid] < key) {
            low = mid + 1;
        } else if (vector[mid] > key) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    if (vector[low] == key)
        return low;
    return -1;
}