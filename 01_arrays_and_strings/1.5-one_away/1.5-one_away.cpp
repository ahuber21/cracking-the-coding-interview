#include <string>

// allowed one-away operations
// remove a character
// replace a character
// insert a character

// time: O(n), where n is the length of the shorter string
// space: O(1), but it changes the input (pass by reference) - O(n) if we would have to pass the string by value

bool one_away(std::string s1, std::string s2)
{
    std::string &shorter = s1.length() < s2.length() ? s1 : s2;
    std::string &longer = s1.length() < s2.length() ? s2 : s1;

    if ((longer.length() - shorter.length()) > 1)
        return false;

    // pop all chars in shorter from longer and if at most one char remains
    // this is the one operation we have to do
    for (const auto &c : shorter)
    {
        size_t found_at = longer.find(c);
        if (found_at != std::string::npos)
        {
            longer.erase(found_at, 1);
        }
    }

    return longer.length() == 0 || longer.length() == 1;
}

void wrapper(std::string s1, std::string s2)
{
    printf("%s and %s %s one away\n", s1.c_str(), s2.c_str(), one_away(s1, s2) ? "are" : "are not");
}

int main()
{
    wrapper("test", "tst");
    wrapper("tst", "test");

    wrapper("some string", "another string");
    wrapper("aaa", "bbb");

    return 0;
}