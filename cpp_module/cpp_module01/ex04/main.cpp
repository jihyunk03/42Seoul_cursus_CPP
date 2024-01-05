#include <iostream>
#include <fstream>
#include <string>

static void	_replace(char **arg);

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "The number of arguments is not 4" << std::endl;
		return 1;
	}

	_replace(av);

	return 0;
}

static void	_replace(char **arg)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		outfile = arg[1];
	std::string		origin = arg[2];
	std::string		replace = arg[3];
	size_t			pos = 0;
	size_t			origin_len = origin.length();
	size_t			replace_len = replace.length();

	/* check argument error */
	if (origin_len == 0)
	{
		std::cout << "The argument is not valid" << std::endl;
		return ;
	}

	/* check file open */
	ifs.open(arg[1]);
	if (ifs.is_open() == false)
	{
		std::cout << "Fail to open input-file" << std::endl;
		return ;
	}
	ofs.open(outfile.append(".replace").c_str());
	if (ofs.is_open() == false)
	{
		std::cout << "Fail to open output-file" << std::endl;
		return ;
	}

	/* replace */
	std::string	buffer;
	std::getline(ifs, buffer, '\0');
	while (true)
	{
		pos = buffer.find(origin, pos);
		if (pos == std::string::npos)
			break ;
		buffer.erase(pos, origin_len);
		buffer.insert(pos, replace);
		pos += replace_len;
	}
	ofs << buffer;
}
