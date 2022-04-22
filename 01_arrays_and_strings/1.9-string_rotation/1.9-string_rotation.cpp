#include <string>

// Big O is given by std::string::find()

bool is_rotation(std::string s1, std::string s2)
{
    if (s1.length() > 0 && s1.length() != s2.length())
        return false;

    std::string tmp = s2 + s2;
    return tmp.find(s1) != std::string::npos;
}

void wrapper(std::string s1, std::string s2)
{
    printf(
        "%s %s a rotation of %s\n",
        s2.c_str(),
        is_rotation(s1, s2) ? "is" : "is not",
        s1.c_str());
}

int main()
{
    wrapper("waterbottle", "erbottlewat");
    wrapper("something", "another_thing");
    wrapper("one_thing", "also_one_thing");
    wrapper("athing", "thinga");

    return 0;
}