#include <string>

bool is_palindrome(std::string input)
{
    // convert to lowercase
    for (char &c : input)
        c = std::tolower(c);

    // count the number of letters
    // in case the input length is even, all letter must be in the string an even number of times
    // in case the input length is odd, one letter can have an odd number of occurences

    int counter[26] = { 0 };
    size_t length_without_spaces = 0;

    for (const char &c : input)
    {
        int idx = c - 'a';
        counter[idx]++;
        if (c != ' ')
            length_without_spaces++;
    }

    bool odd_length = length_without_spaces % 2 != 0;
    int n_odd_chars = 0;
    for (int i = 0; i < 26; ++i)
    {
        // printf("counter[%d] = %d\n", i, counter[i]);
        if (counter[i] % 2 != 0)
        {
            n_odd_chars++;
            if (odd_length && n_odd_chars > 1)
                return false;
            if (!odd_length && n_odd_chars > 0)
                return false;
        }
    }

    return true;
}

void wrapper(std::string input)
{
    printf("%s %s be a palindrome permutation\n", input.c_str(), is_palindrome(input) ? "can" : "can not");
}

int main()
{
    wrapper("Tact Coa");
    wrapper("blaaaaaaa");
    wrapper("aaabbbaaa");
    wrapper("abababab");
    wrapper("aa bb cc dd ee ff abcd abcd abcd abcd");

    return 0;
}