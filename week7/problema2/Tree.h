#include "List.h"
#include<cstddef>
#include<iostream>
template<class T>
class Tree{
    Tree* parent;
    List<Tree<T>*> children;
public:
    T val;
    Tree(const T&);
    Tree();
    Tree* add_node(const T&, Tree*);
    Tree* get_node(Tree*, size_t);
    void delete_node(Tree*);
    Tree* insert(const T&, Tree*, size_t);
    Tree* find(const T&, bool(*)(const T&,const T&)=nullptr);
    size_t count();
    void sort(Tree*,bool(*)(const T&,const T&)=nullptr);
    void __print();
};

template<class T>
Tree<T>::Tree(const T& oth){
    this->val=oth;
    this->parent=nullptr;
    this->children=List<Tree<T>*>();
}
template<typename T>
Tree<T>::Tree(){
    this->val=T();
    this->parent=nullptr;
    this->children=List<Tree<T>*>();
}
template<typename T>
Tree<T>* Tree<T>::add_node(const T& val, Tree<T>* parent){
    Tree<T>* u=new Tree(val);
    if(parent!=nullptr){
        parent->children.push_back(u);
        u->parent=parent;
    }
    return u;
}
template<typename T>
Tree<T>* Tree<T>::get_node(Tree<T>* parent, size_t pos){
    assert(pos>=0 && pos<parent->children.size());
    LItem<Tree<T>*>* it=parent->children.begin();
    for(size_t i=0;i<pos;i++) it=_next(it);
    return it->val;
}
template<typename T>
void Tree<T>::delete_node(Tree<T>* u){
    LItem<Tree<T>*>* it=u->children.begin();
    while(it!=u->children.end()){
        LItem<Tree<T>*>* nxt=_next(it); /// it va fi sters din lista din cauza apelului de mai jos
        delete_node(it->val);
        it=nxt;
    }
    if(u->parent!=nullptr){
        u->parent->children.erase(u->parent->children.find(u));
        u->parent=nullptr;
    }
    delete u;
}
template<typename T>
Tree<T>* Tree<T>::insert(const T& val, Tree<T>* parent, size_t pos){
    Tree<T>* u=new Tree(val);
    if(parent!=nullptr){
        parent->children.insert(u, pos);
        u->parent=parent;
    }
    return u;
}
template<typename T>
Tree<T>* Tree<T>::find(const T& val, bool (*__equal)(const T&,const T&)){
    if(__equal==nullptr && val==this->val) return this;
    if(__equal!=nullptr && __equal(val,this->val)) return this;
    auto it=this->children.begin();
    while(it!=this->children.end()){
        Tree<T>* cnd=it->val->find(val,__equal);
        if(cnd!=nullptr) return cnd;
        it=_next(it);
    }
    return nullptr;
}
template<typename T>
size_t Tree<T>::count(){
    size_t Size=1;
    LItem<Tree<T>*>* it=this->children.begin();
    while(it!=this->children.end()){
        Size+=it->val->count();
        it=_next(it);
    }
    return Size;
}
template<typename T>
void Tree<T>::sort(Tree<T>* u, bool (*cmp)(const T&, const T&)){
    LItem<Tree<T>*>* i=u->children.begin();
    while(i!=u->children.end()){
        LItem<Tree<T>*>* j=_next(i);
        while(j!=u->children.end()){
            if((cmp==nullptr && j->val->val<i->val->val) || cmp(j->val->val,i->val->val)){
                Tree<T>* aux=i->val;
                i->val=j->val;
                j->val=aux;
            }
            j=_next(j);
        }
        i=_next(i);
    }
}

template<typename T>
void Tree<T>::__print(){
    std::cout<<this->val;
    if(this->children.size()>0){
        std::cout<<"(";
         LItem<Tree<T>*>* it=this->children.begin();
        while(it!=this->children.end()){
            it->val->__print();
            it=_next(it);
            if(it!=this->children.end()) std::cout<<',';
        }
        std::cout<<")";
    }
}
