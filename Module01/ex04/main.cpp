#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

void file_replace(const std::string &file, const std::string &needle, const std::string &replace);

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Invalid usage\nCorrect usage: " << av[0] << " <path/to/file> <string_to_find> <string_to_replace>" << std::endl;
		return (1);
	}
	else
	{
		std::string file(av[1]);
		std::string needle(av[2]);
		std::string replace(av[3]);
		file_replace(file, needle, replace);
	}
}

void file_replace(const std::string &file, const std::string &needle, const std::string &replace)
{
	if (needle.empty())
	{
		std::cerr << "Needle is empty" << std::endl;
		return;
	}
	std::ifstream fileIn(file.c_str());
	if (!fileIn)
	{
		std::cerr << "Unable to open input file" << std::endl;
		return;
	}
	std::string fileOutName = file + ".replace";
	std::ofstream fileOut(fileOutName.c_str());
	if (!fileOut)
	{
		fileIn.close();
		std::cerr << "Unable to open output file" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(fileIn, line))
	{
		size_t pos = 0;
		while ((pos = line.find(needle, pos)) != std::string::npos)
		{
			line.erase(pos, needle.length());
			line.insert(pos, replace);
			pos += replace.length();
		}
		fileOut << line << std::endl;
	}
	fileIn.close();
	fileOut.close();
}