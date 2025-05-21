
template<class T>
bool Less(T a, T b){
    return a<b;
}
template<class T>
void Sort(T* begin, T* end, bool (*smaller)(T,T)){ /// ar trebui sa functioneze la fel ca sort-ul din STL
    if(end-begin<=1) return; // bug 1
    size_t n=end-begin;
    Sort(begin,begin+n/2,smaller);
    Sort(begin+n/2,begin+n,smaller); // bug 2
    size_t i=0,j=n/2,k=0;
    T* buff=new T[n];
    while(i<n/2 && j<n){ /// merge-ul
        if(smaller(begin[i],begin[j])) buff[k]=begin[i++]; // bug 3 (trebuie dat swap la i si j)
        else buff[k]=begin[j++];
        k++;
    }
    while(i<n/2){
        buff[k]=begin[i];
        k++;
        i++;
    }
    while(j<n){ // bug 4
        buff[k]=begin[j];
        k++;
        j++;
    }
    for(i=0;i<n;i++) // bug 5
        begin[i]=buff[i];
    delete [] buff;
}

template<class T>
void Sort(T* begin, T* end){
    Sort(begin,end,Less<T>);
}

