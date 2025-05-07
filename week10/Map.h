#include "Iterator.h"

template<class T1, class T2>
class Map{
    class iterator{
    public:
        public:
        T1 first;
        T2 second;
        size_t id;
        iterator(){}
        iterator(T1 _first, T2 _second, size_t _id) : first(_first),second(_second),id(_id){}
    }*__begin;
    size_t __size,__capacity;
    public:
    Map();
    size_t Count();
    iterator* begin(){return __begin;}
    iterator* end(){return __begin+__size;}
    void reserve(size_t);
    void Clear();
    bool Delete(const T1& key);
    void Set(const T1& key, const T2& val);
    bool Get(const T1& key, T2& value);
    T2& operator [] (const T1& key);
    bool Includes(const Map<T1,T2>&);
};
template<class T1, class T2>
Map<T1,T2>::Map(){
    __begin=new iterator[1];
    __size=0;
    __capacity=1;
}
template<class T1, class T2>
size_t Map<T1,T2>::Count(){
    return __size;
}
template<class T1, class T2>
void Map<T1,T2>::reserve(size_t new_capacity){
    iterator* __begin_new=new iterator [new_capacity];
    __capacity=new_capacity;
    if(__capacity<__size) __size=__capacity;
    for(size_t i=0;i<__size && i<new_capacity;i++)
        __begin_new[i]=__begin[i];
    delete [] __begin;
    __begin=__begin_new;
}
template<class T1, class T2>
void Map<T1,T2>::Clear(){
    delete [] __begin;
    __begin=new iterator[1];
    __size=0;
    __capacity=1;
}
template<class T1, class T2>
bool Map<T1,T2>::Delete(const T1& key){
    for(auto it=this->begin();it!=this->end();it++){
        if(it->first==key){
            while(it+1!=this->end()){
                *it=*(it+1);
                it->id--;
                it++;
            }
            __size--;
            return true;
        }
    }
    return false;
}
template<class T1, class T2>
void Map<T1,T2>::Set(const T1& key, const T2& val){
    for(auto it=this->begin();it!=this->end();it++){
        if(it->first==key){
            it->second=val;
            return;
        }
    }
    if(__size==__capacity) reserve(__capacity*2);
    __begin[__size].first=key;
    __begin[__size].second=val;
    __begin[__size].id=__size;
    __size++;
}

template<class T1, class T2>
bool Map<T1,T2>::Get(const T1& key, T2& value){
    for(auto it : *this){
        if(it.first==key){
            value=it.second;
            return true;
        }
    }
    return false;
}
template<class T1, class T2>
T2& Map<T1,T2>::operator [] (const T1& key){
    for(auto it=this->begin();it!=this->end();it++){
        if(it->first==key) return it->second;
    }
    if(__size==__capacity) this->reserve(__capacity*2);
    __begin[__size].first=key;
    __begin[__size].id=__size;
    return __begin[__size++].second;
}
template<class T1, class T2>
bool Map<T1,T2>::Includes(const Map<T1,T2>& oth){
    for(size_t i=0;i<oth.__size;i++){
        bool fnd=0;
        for(auto it : *this){
            if(it.first==oth.__begin[i].first){
                fnd=1;
                break;
            }
        }
        if(!fnd) return false;
    }
    return true;
}
