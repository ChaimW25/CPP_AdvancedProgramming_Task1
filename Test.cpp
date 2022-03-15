

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <list>

using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good input") {
            CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                            "@-------@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-@---@-@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-------@\n"
                                                            "@@@@@@@@@"));

                CHECK(nospaces(mat(1,1,'^','%')) == nospaces("^"));

                CHECK(nospaces(mat(1,3,'!','?')) == nospaces("!!!"));

                CHECK(nospaces(mat(3,1,'?','!')) == nospaces("???"));

                CHECK(nospaces(mat(3,3,'$','#')) == nospaces("$$$\n"
                                                             "$#$\n"
                                                             "$$$"));

                CHECK(nospaces(mat(3,3,'#','$')) == nospaces("###\n"
                                                            "#$#\n"
                                                            "###"));

                CHECK(nospaces(mat(3,3,'*','&')) == nospaces("***\n"
                                                             "*&*\n"
                                                             "***"));

}

TEST_CASE("Bad input") {
            CHECK_THROWS(mat(10, 5, '$', '%'));

            CHECK_THROWS(mat(-1,4,'#','^'));

            CHECK_THROWS(mat(0,8,'%','@'));

            CHECK_THROWS(mat(0,0,'#','^'));

            CHECK_THROWS(mat(0,-3,'#','%'));

            CHECK_THROWS(mat(-4,-3,'$','$'));

            CHECK_THROWS(mat(4,4,'@','@'));

            CHECK_THROWS(mat(-2,-2,'!','@'));

            CHECK_THROWS(mat(0,10,'%','*'));

            CHECK_THROWS(mat(2,-4,'>','@'));

            CHECK_THROWS(mat(5,25,'<','@'));

            CHECK_THROWS(mat(1,1,'%','^'));

            CHECK_THROWS(mat(-10,10,'&','@'));

            CHECK_THROWS(mat(0,8,'%','?'));




}
