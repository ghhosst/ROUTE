#include "isVowel.h"

bool isVowel(char ch) {
    ch = std::tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}