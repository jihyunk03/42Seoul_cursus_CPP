#include "./Replace.hpp"

/* constructor */
Replace::Replace(char **arg, std::string replace_file)
	: _ifs(arg[1]), _ofs(replace_file), _origin(arg[2]), _replace(arg[3])
{}

/* destructor */
Replace::~Replace()
{}

/* member functions */
void	Replace::replace()
{
	std::string	buffer;
	size_t		pos = 0;
	size_t		origin_len = this->_origin.length();
	size_t		replace_len = this->_replace.length();

	if (this->_ifs.is_open() == false || this->_ofs.is_open() == false)
	{
		std::cout << "Fail to open file" << std::endl;
		return ;
	}

	std::getline(this->_ifs, buffer, '\0');
	while (true)
	{
		pos = buffer.find(this->_origin, pos);
		if (pos == std::string::npos)
			break ;
		buffer.erase(pos, origin_len);
		buffer.insert(pos, this->_replace);
		pos += replace_len;
	}
	this->_ofs << buffer;
}
