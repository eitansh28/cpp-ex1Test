#include<iostream>
#include <string>
#include <stdexcept>
using namespace std;

// #include "namespace.hpp"

namespace ariel {
	string mat(int col, int row, char s1, char s2){
        if (col%2 == 0 || row%2 ==0){
            throw invalid_argument{"Mat size is always odd"};
        }if(col<0 || row<0){
            throw invalid_argument{"col and row must be a positive numbers"};
        }if(s1=='\n' || s1 == '\r' || s1 == '\t' || s1 == ' '){
            throw invalid_argument{"Bad design. It is impossible to design such a mat"};
        }if(s2=='\n' || s2 == '\r' || s2 == '\t' || s2 == ' '){
            throw invalid_argument{"Bad design. It is impossible to design such a mat"};
        }
        char arr[row][col];
        char sym;
        int k=0,z=0;
        while(k<=row/2 && z<=col/2){
            if(k%2==0){
                sym=s1;
            }else{
                sym=s2;
            }for(int i=k;i<col-z;i++){
                arr[k][i]=sym;
                arr[row-1-k][i]=sym;
            }for(int j=k;j<row-k;j++){
                arr[j][col-1-z]=sym;
                arr[j][k]=sym;
            }
            k++;
            z++;
        }
                
        string design="";
        for(int i=0;i<row;i++){
             for(int j=0;j<col;j++){
                 design+=arr[i][j];
             }design+='\n';
        }
        return design;
    }
}
