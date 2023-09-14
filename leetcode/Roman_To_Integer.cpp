class Solution {
public:
    int romanToInt(string s) {
        int sum = 0, i, carryC = 0, carryX = 0, carryI = 0, M = 1000, d = 500, c = 100, l = 50, x = 10, v = 5, I = 1;

        for(i = 0; i < s.size(); i++) {
            if (s[i] == 'M'){
                if(carryC > 0){
                    sum = sum + M - carryC; //without carry
                    carryC = 0;
                }else{
                    sum = sum + M; //M for 1000
                }
            }else if(s[i] == 'D'){
                if(carryC > 0){
                    sum = sum + d - carryC; //without carry
                    carryC = 0;
                }else{
                    sum = sum + d; //M for 1000
                }

            }else if(s[i] == 'C'){
                if(carryX > 0){
                    sum += c - carryX;
                    carryX = 0;
                }else{
                    if(carryC == 0)
                        carryC = c;
                    else{
                        sum += c + carryC;
                        carryC = 0;
                    }      
                    
                }

            }else if(s[i] == 'L'){
                if(carryX > 0){
                    sum += l - carryX;
                    carryX = 0;
                }else{
                    sum += l;
                }
            }else if(s[i] == 'X'){
                 if(carryI > 0){
                    sum += x - carryI;
                    carryI = 0;
                }else{
                    if(carryX == 0)
                        carryX = x;
                    else{
                        sum += x + carryX;
                        carryX = 0;
                    }
                }
            }else if(s[i] == 'V'){
                if(carryI > 0){
                    sum += v - carryI;
                    carryI = 0;
                }else{
                    sum += v;
                }
            }else if(s[i] == 'I'){
                if(carryI == 0)
                        carryI = I;
                    else{
                        sum += I + carryI;
                        carryI = 0;
                }
            }

        }
        sum += carryI + carryX + carryC;
        return sum;

    }
};  
