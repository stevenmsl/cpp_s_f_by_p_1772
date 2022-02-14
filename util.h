#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
namespace sol1772
{
    class Util
    {
    public:
        static vector<string> split(string input);
        static vector<string> split(string input, char delimiter);
    };
}
#endif