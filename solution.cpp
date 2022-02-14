#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>
using namespace sol1772;
using namespace std;

/* takeaways
   - this is a good exercise for picking up the right
     data structures to implement the requirements
   - use a map to record the index of the features
     as we need to order the output by their
     original index for features that have the
     same popularity
   - use a set to help eliminating duplications
     when we scan through a response - we only
     want to count a feature once even if it
     is mentioned many times in a response
   - define a compare lambda expression to first
     sort the features by counts in descending
     order and use a tiebreaker that would
     sort the features in descending order by
     their original index
*/

vector<string> Solution::sortByPopularity(vector<string> &features, vector<string> &resps)
{
  /* maintain the index of each feature */
  auto ind = unordered_map<string, int>();
  /*
    - count the occurrences of each features
      appeared in the responses
  */
  auto counts = unordered_map<string, int>();

  for (auto i = 0; i < features.size(); i++)
    ind[features[i]] = i;

  /*
     - check each response to count
       the occurrences of each feature
  */
  for (auto r : resps)
  {
    /* avoid duplicate features in a response */
    auto fset = unordered_set<string>();

    auto ss = stringstream(r);
    string token;
    /*
      - split the words by space
      - add the token to a set only
        if it's a feature
    */
    while (ss >> token)
      if (ind.count(token))
        fset.insert(token);
    for (auto &f : fset)
      counts[f]++;
  }

  /* C++ notes
     - check how the types can all be inferred
       properly
  */
  auto compare = [&](auto const &f1, auto const &f2)
  {
    if (counts[f1] != counts[f2])
      /* descending by counts (occurrences) */
      return counts[f1] > counts[f2];
    /* tiebreaker - ascending by index of the feature */
    return ind[f1] < ind[f2];
  };

  sort(features.begin(), features.end(), compare);

  return features;
}