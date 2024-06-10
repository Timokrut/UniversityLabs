// Напишите реализацию функции mergesort (merge уже есть)

void merge(int* arr, int left, int mid, int right)
{

}

void mergesort(int* arr, int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}