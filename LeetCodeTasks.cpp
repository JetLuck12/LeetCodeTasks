
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

bool cook_recipe(string& recipe, set<string>& chain, map<string, set<string>>& recs, set<string>& sups, set<string>& bad_recs) {
    if (chain.contains(recipe)) {
        return false;
    }
    chain.insert(recipe);
    if (bad_recs.contains(recipe)) {
        return false;
    }
    for (auto ingr : recs[recipe]) {
        if (sups.contains(ingr)) {
            continue;
        }
        else {
            if (recs.contains(ingr)) {
                if (cook_recipe(ingr, chain, recs, sups, bad_recs)) {
                    continue;
                }
                else {
                    bad_recs.insert(recipe);
                    return false;
                }
            }
            else {
                bad_recs.insert(recipe);
                return false;
            }
        }
    }
    sups.insert(recipe);
    return true;
}

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string> sups;
        for (auto sup : supplies) {
            sups.insert(sup);
        }
        map<string, set<string>> recs;
        for (int i = 0; i < recipes.size(); i++) {
            recs[recipes[i]] = set<string>(ingredients[i].begin(), ingredients[i].end());
        }
        set<string> bad_recs;

        vector<string> ans;
        for (auto& rec : recipes) {
            set<string> chain;
            if (cook_recipe(rec, chain, recs, sups, bad_recs)) {
                ans.push_back(rec);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<std::string> recs{ "bread" };
    vector<vector<std::string>> ingr = { {"yeast", "flour"} };
    vector<string> sups = { "yeast", "flour", "corn" };
    vector<string> ans = sol.findAllRecipes(recs, ingr, sups);
}
