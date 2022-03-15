
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
        if (row % 2 == 0 || row <= 0 || col % 2 == 0 || col <= 0) {
            throw ("Illegal numbers of col an row");

        }
        if (sym1 <minChar || sym1 > maxChar || sym2<minChar || sym2 > maxChar) {
            throw ("Illegal chars");
        }
        //init a 2D vector hols the matrix
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