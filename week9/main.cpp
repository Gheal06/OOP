#include<bits/stdc++.h>

struct cmp{
    bool operator () (std::pair<std::string,int> a, std::pair<std::string,int> b) const {
        if(a.second<b.second) return true;
        if(a.second>b.second) return false;
        return a.first>b.first;
    }
};
int main(){
    std::ifstream fin("in.txt");
    std::string line;
    getline(fin,line);
    const std::string sep=" ,?!.";
    std::string word;
    std::map<std::string,int> fr;
    for(auto it : line){
        if(sep.find(it)==sep.npos) word.push_back(tolower(it));
        else if(!word.empty()){
            fr[word]++;
            word.clear();
        }
    }
    if(!word.empty()){
        fr[word]++;
        word.clear();
    }
    std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,cmp> pq;
    for(auto it : fr) pq.push(it);
    while(!pq.empty()){
        std::cout<<pq.top().first<<" => "<<pq.top().second<<'\n';
        pq.pop();
    }
    return 0;
}

