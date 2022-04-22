#include <string>

bool isUnique(std::string s) {
    uint32_t seen = 0;

    for (char c : s) {
        c = std::tolower(c);
        if (c > 'a') {
            uint32_t mask = (0x1 << (c - 'a'));
            if (seen & mask) {
                printf("'%s' contains duplicate characters (e.g. '%c')\n", s.c_str(), c);
                return false;
            }
            seen |= mask;
        }
    }

    printf("'%s' contains only unique characters\n", s.c_str());
    return true;
}

int main() {
    isUnique("uniq");
    isUnique("not unique");

    return 0;
}