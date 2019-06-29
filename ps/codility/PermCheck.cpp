#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    
    for(unsigned int i = 0; i < A.size(); i++){
        if(i == 0){
            if(A[i] != 1)
                return false;
        }
        else {
            if(A[i-1] + 1 != A[i])
                return false;
        }
        
    }
    
    return true;
}