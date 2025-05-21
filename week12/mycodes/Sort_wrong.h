template<class T>
bool Less(T a, T b){
    return a<b;
}
template<class T>
void Sort(T* begin, T* end, bool (*smaller)(T,T)){ /// ar trebui sa functioneze la fel ca sort-ul din STL
    if(end-begin<=0) return;
    size_t n=end-begin;
    Sort(begin,begin+n/2,smaller);
    Sort(begin+n/2+1,begin+n,smaller);
    size_t i=0,j=n/2,k=0;
    T* buff=new T[n];
    while(i<n/2 && j<n){ /// merge-ul
        if(smaller(begin[i],begin[j])) buff[k]=begin[j++];
        else buff[k]=begin[i++];
        k++;
    }
    while(i<n/2){
        buff[k]=begin[i];
        k++;
        i++;
    }
    while(j<n/2){
        buff[k]=begin[j];
        k++;
        j++;
    }
    for(i=1;i<n;i++)
        begin[i]=buff[i];
    delete [] buff;
}

template<class T>
void Sort(T* begin, T* end){
    Sort(begin,end,Less<T>);
}
```