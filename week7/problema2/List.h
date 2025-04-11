#include "LItem.h"
#include<cstddef>
#include<cassert>
template<class T>
class List{
    size_t __size=0;
    LItem<T> *__begin, *__end;
public:
    List();
    size_t size();
    LItem<T>* begin();
    LItem<T>* end();
    void push_back(const T&);
    void push_front(const T&);
    void insert(const T&, size_t);
    LItem<T>* find(const T&);
    LItem<T>* erase(LItem<T>*);
};
template<class T>
List<T>::List(){
    __begin=__end=new LItem<T>();
    __size=0;
}
template<class T>
size_t List<T>::size(){
    return __size;
}
template<class T>
LItem<T>* List<T>::begin(){
    return __begin;
}
template<class T>
LItem<T>* List<T>::end(){
    return __end;
}
template<class T>
void List<T>::push_back(const T& val){
    __size++;
    __end->val=val;
    LItem<T>* newend=new LItem<T>();
    __end->nxt=newend;
    newend->prv=__end;
    __end=newend;
}
template<class T>
void List<T>::push_front(const T& val){
    __size++;
    LItem<T>* newbegin=new LItem<T>();
    newbegin->val=val;
    newbegin->nxt=__begin;
    __begin->prv=newbegin;
    __begin=newbegin;
}
template<class T>
void List<T>::insert(const T& val, size_t pos){
    assert(pos>=0 && pos<=__size);
    if(pos==__size){
        this->push_back(val);
        return;
    }
    if(pos==0){
        this->push_front(val);
        return;
    }
    LItem<T>* it;
    if(pos*2<__size){
        it=begin();
        for(size_t i=0;i<pos;i++) it=_next(it);
    }
    else{
        it=end();
        for(size_t i=0;i<__size-pos+1;i++) it=_prev(it);
    }
    LItem<T>* newnode = new LItem<T>(val);
    newnode->prv=it;
    newnode->nxt=_next(it);
    _next(it)->prv=newnode;
    it->nxt=newnode;
    __size++;
}
template<class T>
LItem<T>* List<T>::find(const T& val){
    LItem<T>* it=__begin;
    while(it!=__end)
        if(it->val==val)
            return it;
    return __end;
}
template<class T>
LItem<T>* List<T>::erase(LItem<T>* it){
    LItem<T>* prv=_prev(it), *nxt=_next(it);
    assert(nxt!=nullptr);
    if(prv==nullptr){
        __begin=_next(__begin);
        __begin->prv=nullptr;
        delete it;
        return __begin;
    }
    prv->nxt=nxt;
    nxt->prv=prv;
    delete it;
    return nxt;
}

