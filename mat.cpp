
#include "mat.hpp"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
namespace ariel {

class MyException
//        public std::exception
{
    //https://stackoverflow.com/questions/59518468/terminate-called-after-throwing-an-instance-of-char-const-in-string-function
public:
    int num;
    explicit MyException(int n)  {
        num= n;
    }
    virtual const char* what() const {
        if(num==1)
            return "Illegal number!";
        else
            return "Illegal char!";
    }
//    string what(){
//        if(num==1)
//            return "Illegal number!";
//        else
//            return "Illegal char!";
//    }
};
    string mat(int row, int col, char sym1, char sym2) {
        try {
            if (row % 2 == 0 || row <= 0 || col % 2 == 0 || col <= 0) {
                throw MyException(1);

            }
            if (sym1 > 127 || sym2 > 127) {
                throw MyException(-1);
            }
            char a[row][col];
            int minLen, numOfChanges;
            string ans;
            char currSymbol;
            if (row > col)
                minLen = col;
            else
                minLen = row;
            double half = minLen / 2.0;
            numOfChanges = round(half);
            for (int j = 0; j < numOfChanges; j++) {
                if (j % 2 == 0)
                    currSymbol = sym1;
                else
                    currSymbol = sym2;
                //init the beginning of columns
                for (int i = j; i < col - j; i++)
                    a[j][i] = currSymbol;
                //init the end of rows
                for (int i = j + 1; i < row - j; i++)
                    a[i][col - 1 - j] = currSymbol;
                //init the end of columns
                for (int i = j + 1; i < col - j; i++)
                    a[row - 1 - j][col - 1 - i] = currSymbol;
                //init the beginning of rows
                for (int i = j + 1; i < row - j - 1; i++)
                    a[row - 1 - i][j] = currSymbol;
            }
            ans = "";
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    ans += a[i][j];
                }
                ans += "\n";
            }
            return ans;
        }
        catch(const MyException& ex){
            cout << "caught exception: " << ex.what() << endl;
            return "";
        }
    }



//    string printStr(int depth, int mat[][] , char symbol) {
//    }




}


