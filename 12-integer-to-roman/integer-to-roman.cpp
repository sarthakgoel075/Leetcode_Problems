class Solution {
public:
    string intToRoman(int num) {
        int t=num;
        string s;
        while(t>=1000){
           s=s+"M";
            t=t-1000;
        }
        if(t>=900){
            s=s+ "CM";
            t=t-900;
        }
        else if(t>=500){
             s=s+'D';
            t=t-500;
        }
        if(t>=400){
              s=s+"CD";
            t=t-400;
        }
        while(t>=100){
            s=s+"C";
            t=t-100;
        }
        if(t>=90){
            s=s+"XC";
            t=t-90;
        }
        else if(t>=50){
            s=s+"L";
            t=t-50;
        }
        else if(t>=40){
            s=s+"XL";
            t=t-40;
        }
        while(t>=10){
            s=s+"X";
            t=t-10;
        }
        if(t==9){
            s=s+"IX";
            t=t-9;
        }
       else if(t>=5){
           s=s+"V";
           t=t-5;
       }
        if(t==4){
            s=s+"IV";
                t=t-4;
        }
        while(t>0){
            s=s+"I";
            t=t-1;
        }
        
       return s; 
    }
};