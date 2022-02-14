
#include "util.h"
#include <cstring>
#include <vector>
#include <string>
#include <sstream>

using namespace sol1772;

/* delimiter is the sapce */
vector<string> Util::split(string input)
{
    auto ss = stringstream(input);
    auto result = vector<string>();
    string token;
    while (ss >> token)
    {
        result.push_back(token);
    }
    return result;
}
vector<string> Util::split(string input, char delimiter)
{
    auto ss = stringstream(input);
    auto result = vector<string>();
    string token;
    while (getline(ss, token, delimiter))
    {
        result.push_back(token);
    }
    return result;
}