#include "./Span.hpp"

/* OCCF: constructor */
Span::Span(unsigned int maxSize)
    : _maxSize(maxSize)
{}

/* OCCF: copy constructor */
Span::Span(const Span& origin)
    : _maxSize(origin._maxSize)
{
    for (std::vector<int>::const_iterator it = origin._vec.begin(); it != origin._vec.end(); ++it)
        this->_vec.push_back(*it);
}

/* OCCF: copy assignment operator overloading */
Span& Span::operator=(const Span& origin)
{
    if (this != &origin)
        return *this;
    this->_maxSize = origin._maxSize;
    this->_vec.clear();
    for (std::vector<int>::const_iterator it = origin._vec.begin(); it != origin._vec.end(); ++it)
        this->_vec.push_back(*it);
    return *this;
}

/* OCCF: destructor */
Span::~Span()
{
    this->_vec.clear();
}


/* member functions */
void Span::addNumber(int value)
{
    if (this->_vec.size() == static_cast<size_t>(this->_maxSize))
        throw std::out_of_range("❌ cannot add numbers: out of range of this Span");
    this->_vec.push_back(value);
}

void Span::addManyNumber(int size)
{
    if (this->_vec.size() + size > static_cast<size_t>(this->_maxSize))
        throw std::out_of_range("❌ cannot add numbers: out of range of this Span");
    srand(time(NULL));
    for (size_t s = 0; s < size; ++s)
        this->_vec.push_back(rand() % 10000000);
}

int Span::shortestSpan(void)
{
    // size가 1이하면 throw(login_error)
    std::vector<int> temp;
    for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); ++it)
        temp.push_back(*it);
    std::sort(temp.begin(), temp.end());
    // int minimum = temp[1] - temp[0]; 로 시작해서 진행
    // for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); ++it)

}

int Span::longestSpan(void)
{
}
