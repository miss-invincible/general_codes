int Solution::Mod(int A, int B, int C) {
    long long negMod = C-abs(A)%C;
    
    if(A==0){
        return 0;
    }
    if(B==0){
        return 1;
    }
    
    if(B==1){
        if(A<0){
            return negMod%C;
        }else{
            return A%C;
        }
    }
    
    long long power = Mod(A,B/2,C)%C;
    return ((power*power)%C*Mod(A,B%2,C))%C;
    
}
