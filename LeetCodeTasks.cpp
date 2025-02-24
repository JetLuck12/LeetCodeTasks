
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Node
{
public:
    Node(int val) : val_(val){}
    std::vector<Node*> childs_{};
    Node* parent_ = nullptr;
    int val_;
    int bob_step = -1;
};

int alice_recursive(Node* root, int alice_step)
{
    int val = 0;
    if (root->bob_step == -1 || root->bob_step > alice_step)
    {
        val += root->val_;
    }
    else if (root->bob_step == alice_step)
    {
        val += root->val_ / 2;
    }
    int child_val = 0;
    bool is_changed = false;
    for (auto child : root->childs_)
    {
        int res = alice_recursive(child, alice_step + 1);
        if (child_val < res || !is_changed)
        {
            is_changed = true;
            child_val = res;
        }
    }
    return val + child_val;
}

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        std::vector<Node*> nodes;
        nodes.reserve(amount.size());
        for (int i : amount)
        {
            nodes.push_back(new Node(i));
        }
        std::map<int, set<int>> map_edges;
        for (auto& pair: edges)
        {
	        if (map_edges.contains(pair[0]))
	        {
                map_edges[pair[0]].insert(pair[1]);
	        }
            else
            {
                map_edges[pair[0]] = { pair[1] };
            }
            if (map_edges.contains(pair[1]))
            {
                map_edges[pair[1]].insert(pair[0]);
            }
            else
            {
                map_edges[pair[1]] = { pair[0] };
            }
        }
        std::queue<int> queue;
        queue.push(0);
        while (!queue.empty())
        {
            auto node = queue.front();
            queue.pop();
            while (!map_edges[node].empty())
            {
                auto child = *map_edges[node].begin();
                nodes[node]->childs_.push_back(nodes[child]);
                nodes[child]->parent_ = nodes[node];
                map_edges[node].erase(child);
                map_edges[child].erase(node);
                queue.push(child);
            }
        }
        int bob_step = 0;
        Node* cur = nodes[bob];
        while (cur != nodes[0])
        {
            cur->bob_step = bob_step;
            cur = cur->parent_;
            bob_step++;
        }
        cur->bob_step = bob_step;
        return alice_recursive(nodes[0], 0);
    }
};

int main()
{
    std::string edges_str{ "[[0,1],[1,2],[1,3],[3,4]]" };
    std::string amount_str{ "[-2,4,2,-4,6]" };
    std::vector<std::vector<int>> edges = Parser::process_vector_vector(edges_str);
    std::vector<int> amount = Parser::process_vector(amount_str);
    int bob = 1;

    Solution sol;
    sol.mostProfitablePath(edges, bob, amount);
}
