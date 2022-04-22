#include <string>

// time: O(n) - where n is the length of the input string
// space: O(n), since the length of the converted string follows O(n)

std::string compress(std::string s)
{
    bool init = true;
    char current_char;
    int current_count;
    std::string converted;

    for (size_t i = 0; i < s.length(); ++i)
    {
        const char &c = s.at(i);
        if (init)
        {
            init = false;
            current_char = c;
            current_count = 1;
            continue;
        }
        if (c != current_char)
        {
            converted += current_char;
            converted += std::to_string(current_count);
            current_char = c;
            current_count = 1;
        }
        else
        {
            current_count++;
        }
        if (i == s.length() - 1)
        {
            converted += c;
            converted += std::to_string(current_count);
        }
    }

    return converted.length() < s.length() ? converted : s;
}

void wrapper(std::string s)
{
    printf("%s -> %s\n", s.c_str(), compress(s).c_str());
}

int main()
{
    wrapper("aabcccccaaa");
    wrapper("aabccccca");
    wrapper("aabcccccccccba");
    wrapper("abcd");

    return 0;
}