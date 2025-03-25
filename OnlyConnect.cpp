#include "OnlyConnect.h"
#include "strlib.h"     // For toUpperCase
#include "cctype"       // For isalpha
using namespace std;

bool isConsonant(char ch) {
    ch = toUpperCase(string(1, ch))[0]; // Convert to uppercase
    return isalpha(ch) && !(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

string onlyConnectize(string phrase) {
    if (phrase.empty()) return "";

    char first = toUpperCase(string(1, phrase[0]))[0];

    if (isConsonant(phrase[0])) {
        return string(1, first) + onlyConnectize(phrase.substr(1));
    } else {
        return onlyConnectize(phrase.substr(1));
    }
}




/* * * * * * Provided Test Cases * * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}
STUDENT_TEST("Handles mixed input with numbers and punctuation") {
    EXPECT_EQUAL(onlyConnectize("CS106B: C++ > Python?"), "CSBCPYTHN");
}

STUDENT_TEST("Handles string with only vowels") {
    EXPECT_EQUAL(onlyConnectize("AEIOUaeiou"), "");
}

STUDENT_TEST("Handles empty string") {
    EXPECT_EQUAL(onlyConnectize(""), "");
}
STUDENT_TEST("Handles empty string") {
    EXPECT_EQUAL(onlyConnectize("123212"), "");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */






