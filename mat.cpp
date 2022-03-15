
#include "mat.hpp"
#include <string>
#include <cmath>
#include <vector>
const int minChar=33;
const int maxChar=126;
const double half=2.0;
using namespace std;
namespace ariel {

    string mat(int col, int row, char sym1, char sym2) {
//        try {
        if (row % 2 == 0 || row <= 0 || col % 2 == 0 || col <= 0) {
            throw ("Illegal numbers of col an row");

        }
        if (sym1 <minChar || sym1 > maxChar || sym2<minChar || sym2 > maxChar) {
            throw ("Illegal chars");
        }
//        char a[row][col];
        vector<vector<char>> a(row,vector<char>(col));
        int minLen=0;
        int numOfChanges=0;
        string ans;
        char currSymbol=' ';
        if (row > col){
            minLen = col;}
        else{
            minLen = row;}
        double temp = minLen / half;
        numOfChanges = (int)round(temp);
        for (int j = 0; j < numOfChanges; j++) {
            if (j % 2 == 0){
                currSymbol = sym1;}
            else{
                currSymbol = sym2;}
            //init the beginning of columns
            for (int i = j; i < col - j; i++){
                a[j][i] = currSymbol;}
            //init the end of rows
            for (int i = j + 1; i < row - j; i++){
                a[i][col - 1 - j] = currSymbol;}
            //init the end of columns
            for (int i = j + 1; i < col - j; i++){
                a[row - 1 - j][col - 1 - i] = currSymbol;}
            //init the beginning of rows
            for (int i = j + 1; i < row - j - 1; i++){
                a[row - 1 - i][j] = currSymbol;}
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans += a[i][j];
            }
            if(i!=row-1){
                ans += '\n';
            }
        }
        return ans;
    }
}





//
//#include <string>
//#include <iostream>
//#include <vector>
//#include <stdexcept>
//#include "mat.hpp"
//
//using namespace std;
//const int lowRange = 33;
//const int highRange = 126;
//namespace ariel{
//    /*
//    this func return a string how represent a mat
//    prarmaters:
//    column and row - size of the mat
//    c1 and c2 - the mat made from those characters
//    */
//    string mat(int column, int row, char c1, char c2){
//        // take care on bad input - even numbers or negative numbers or iilegal char
//        if(column % 2 == 0 || row % 2 == 0){
//            throw("Mat size is always odd");
//        }
//        if (column < 0 || row < 0){
//            throw("Mat size is positive");
//        }
//        if (c1 < lowRange or c2 < lowRange or c1 > highRange or c2 > highRange){
//            throw("Bad char");
//        }
//        // take care on case that the at in one row or one column
//        if (row == 1){
//            string ans;
//            for(int i=0 ;i< column;i++){
//                ans += c1;
//            }
//            return ans;
//        }
//        if (column == 1){
//            string ans;
//            for(int i=0 ;i< row;i++){
//                ans += c1;
//                ans += '\n';
//            }
//            return ans;
//        }
//        vector< vector <char> > mat(row ,vector<char>(column)); //declaration on 2D vector
//        int i = 0;
//        int j = 0;
//        for ( i = 0; i <= row / 2; i++){
//            //change char in mat frame
//            if (i % 2 == 0){
//                mat = fillFrame(i, mat,c1);
//            }
//            else{
//                mat = fillFrame(i, mat,c2);
//            }
//        }
//        string ans;
//        for( i=0; i< row; i++){
//            for ( j = 0; j < mat.at(0).size(); j++){
//                ans += mat.at(i).at(j);
//            }
//            ans += '\n';
//        }
//        return ans;
//    }
//    /*
//    this func draw the mat frame in 4 for loop
//    each for loop take care on one side of the frame
//    paramaters:
//    index- is index that current frame start
//    a- 2D vector to fill his frame
//    c- char of the frame
//    return: 2D vector -mat- with new the frame
//    */
//    vector< vector <char> > fillFrame (int index ,vector<vector<char>> a , char c){
//        int row = a.size();
//        int column = a[0].size();
//        int i = 0;
//        for (i = index; i < column - index; i++){
//            a.at(index).at(i) = c ;
//        }
//        for (int i = index + 1; i < row - index; i++){
//            a.at(i).at(column - 1 - index) = c;
//        }
//        for (int i = index + 1; i < column - index; i++){
//            a.at(row - 1 - index).at(column - 1 - i) = c;
//        }
//        for (int i = index + 1; i < row - index - 1; i++){
//            a.at(row - 1 - i).at(index) = c;
//        }
//        return a;
//    }
//}
