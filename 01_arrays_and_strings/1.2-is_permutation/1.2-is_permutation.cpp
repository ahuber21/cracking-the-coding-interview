#include <string>
#include <iostream>

static const int n_chars = 52;

bool isPermutation(const std::string &s1, const std::string &s2) {
    int n_occurences[n_chars] = { 0 };

    if (s1.length != s2.length)
    {
        return false
    }

    for (const auto& c : s1)
    {
        int idx = c - 'a';
        n_occurences[idx]++;
    }

    for (const auto& c : s2)
    {
        int idx = c - 'a';
        n_occurences[idx]--;

        if (n_occurences[idx] < 0)
        {
            return false;
        }
    }

    for (int i = 0; i < n_chars; ++i) {
        if (n_occurences[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::cout << isPermutation("onestring", "anotherstring") << std::endl;
    std::cout << isPermutation("abba", "baab") << std::endl;

    return 0;
}