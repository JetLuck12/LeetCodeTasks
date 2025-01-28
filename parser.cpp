#include <string>
#include <vector>

class Parser final
{
public:
	static std::vector<int> process_vector(std::string& input)
    {
        std::vector<int> res;
        res.push_back(atoi(&input[1]));
        for (int i = 1; i < input.size() - 1; i++)
        {
            while (i < input.size() - 1 && input[i] != ',')
            {
                i++;
            }
            if (i >= input.size() - 1)
            {
                break;
            }
            res.push_back(atoi(&input[i + 1]));
        }
        return res;
    }
};
