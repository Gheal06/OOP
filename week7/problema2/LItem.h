template<class T>
class LItem{
public:
    LItem* nxt, *prv; /// intr-o lume ideala ar trebui sa fie private, dar nu am vrut sa schimb restul codului + facut gettere
    T val;
    LItem() : nxt(nullptr), prv(nullptr), val(T()){};
    LItem(const T& oth) : nxt(nullptr), prv(nullptr), val(oth){};
    template<class T2>
    friend LItem<T2>* _next(LItem<T2>*);
    template<class T2>
    friend LItem<T2>* _prev(LItem<T2>*);
};
template<class T>
LItem<T>* _next(LItem<T>* u){
    return u->nxt;
}
template<class T>
LItem<T>* _prev(LItem<T>* u){
    return u->prv;
}
