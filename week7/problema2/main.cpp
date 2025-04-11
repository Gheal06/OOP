#include "Tree.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool almost_equal(const int& a, const int& b){
    return a==b+1 || a==b-1;
}
bool cmp(const int& a, const int& b){
    return a>b;
}
int main() {
    Tree<int> root(1);
    cout<<"Empty tree size: "<<root.count()<<'\n';
    root.add_node(-7,&root);
    Tree<int>* u=root.add_node(6,&root);
    root.add_node(5,u);
    root.add_node(4,u);
    root.add_node(2,u);
    root.add_node(3,u);
    std::cout<<"Tree Structure: ";
    root.__print();
    std::cout<<"\nFinding -6 with custom comparator: "<<root.find(-6,almost_equal)<<", value="<<root.find(-6,almost_equal)->val;
    std::cout<<"\nFinding -6 without custom comparator: "<<root.find(-6);
    root.insert(0,&root,2);
    root.add_node(3,root.insert(4,&root,0));
    root.insert(1,u,2);
    std::cout<<"\nTree Structure: ";
    root.__print();
    std::cout<<"\nFinding 4th child of node 6: "<<root.get_node(u,1)<<", value="<<root.get_node(u,3)->val;
    root.delete_node(root.find(4));
    std::cout<<"\nTree Structure: ";
    root.__print();
    cout<<"\nTree size: "<<root.count();
    std::cout<<"\nSorting children of root in descending order:";
    root.sort(&root,cmp);
    std::cout<<"\nTree Structure: ";
    root.__print();
    std::cout<<"\nSorting children of root using the default order:";
    root.sort(&root);
    std::cout<<"\nTree Structure: ";
    root.__print();
    return 0;
}

