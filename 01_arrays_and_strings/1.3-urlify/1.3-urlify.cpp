#include <string>

std::string urlify(std::string in, size_t size)
{
    std::string converted = "";

    for (size_t i = 0; i < size; ++i)
    {
        const char &c = in.at(i);
        if (c == ' ')
        {
            converted += "%20";
        }
        else
        {
            converted += c;
        }
    }

    return converted;
}

int main()
{
    printf("%s\n", urlify("Mr John Smith     ", 13).c_str());
}