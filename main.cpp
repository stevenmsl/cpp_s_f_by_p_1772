#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1772;

string toString(vector<string> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += e;
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

/*
Input: features = ["cooler","lock","touch"],
responses = ["i like cooler cooler","lock touch cool","locker like touch"]
Output: ["touch","cooler","lock"]
*/
tuple<vector<string>, vector<string>, vector<string>> testFixture1()
{
  return make_tuple(
      vector<string>{"cooler", "lock", "touch"},
      vector<string>{"i like cooler cooler", "lock touch cool", "locker like touch"},
      vector<string>{"touch", "cooler", "lock"});
}

/*
Input: features = ["a","aa","b","c"], responses = ["a","a aa","a a a a a","b a"]
Output: ["a","aa","b","c"]
*/
tuple<vector<string>, vector<string>, vector<string>> testFixture2()
{
  return make_tuple(
      vector<string>{"a", "aa", "b", "c"},
      vector<string>{"a", "a aa", "a a a a a", "b a"},
      vector<string>{"a", "aa", "b", "c"});
}

void test1()
{
  auto f = testFixture1();
  auto result = Solution::sortByPopularity(get<0>(f), get<1>(f));
  cout << "Test 1 - exepct to see " << toString(get<2>(f)) << endl;
  cout << "result: " << toString(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  auto result = Solution::sortByPopularity(get<0>(f), get<1>(f));
  cout << "Test 2 - exepct to see " << toString(get<2>(f)) << endl;
  cout << "result: " << toString(result) << endl;
}

void testSplit()
{
  auto input = string("i like cooler cooler");
  auto result = Util::split(input);
  cout << "input: " << input << endl;
  cout << "result: " << toString(result) << endl;

  input = string("i,like,cooler,cooler");
  result = Util::split(input, ',');
  cout << "input: " << input << endl;
  cout << "result: " << toString(result) << endl;
}

main()
{
  test1();
  test2();
  // testSplit();
  return 0;
}