
class Sort
{
    int n;
    int v[100001];
public:
    Sort(int n, int Min, int Max);
    Sort(int n, int* v);
    Sort(int n, ...);
    Sort(const char* s);
    Sort(const Sort& oth);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
private:
    void __quicksort(int l, int r, long long Seed);
};
