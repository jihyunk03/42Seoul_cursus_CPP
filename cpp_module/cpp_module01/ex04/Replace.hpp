#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replace
{
	private:
		std::ifstream	_ifs;
		std::ofstream	_ofs;
		std::string		_origin;
		std::string		_replace;

	public:
		Replace(char **, std::string);
		~Replace();

		void	replace();
};

#endif
