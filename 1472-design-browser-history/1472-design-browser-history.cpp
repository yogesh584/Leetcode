class BrowserHistory {
public:
    pair<string,pair<int,int>> his[101];
    int iter = 0;

    BrowserHistory(string homepage) {
        his[iter] = {homepage,{true,true}};
    }
    
    void visit(string url) {
        his[iter].second.second = false;
        iter++;
        his[iter] = {url,{false,true}};
    }
    
    string back(int steps) {
        for(int i = 0;i < steps;i++){
            if(his[iter].second.first == true){
                return his[iter].first;
            }
            iter--;
        }
        return his[iter].first;
    }
    
    string forward(int steps) {
        for(int i = 0;i < steps;i++){
            if(his[iter].second.second == true){
                return his[iter].first;
            }
            iter = iter+1;
        }        
        return his[iter].first;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */