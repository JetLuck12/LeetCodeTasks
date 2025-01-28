#pragma once

class Parser final
{
public:
	static std::vector<int> process_vector(std::string& input);
	static std::vector<std::vector<int>> process_vector_vector(std::string& input);
};