int solution(int X, vector<int> &A) {
    vector<bool> position;
    position.assign(X+1, false);
    int total = X*(X+1)/2;
    
    for(unsigned int i = 0; i<A.size(); i++){
        if(!position[A[i]]){
            position[A[i]] = true;
            total -= A[i];
            
            if(total == 0)
                return i;
        }
    }
    
    return -1;
}