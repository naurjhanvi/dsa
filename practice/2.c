#include<stdio.h>

int stringmatch(){
    while(str[c]!= "\0"){
        if(str[m]==pat[i]){
            m++;
            i++;
            flag =1;
            if(pat[i]== '\0'){
                for(int k=0; rep[k]!= '\0';k++,m++){
                    rep[k] = str[m];
                    c=m;
                    i=0;
                }
            }
            rep[j] = str[m];
            j++;
            m++;
            m=c;
            i=0;
        }
    }
    str[c]="\0";
    return str;
}

int main(){
    gets(pat);
    stringmatch();
    if(flag == 1){
        //founnd
    }
}