#include "./Span.hpp"

/* OCCF: constructor */
Span::Span(unsigned int maxSize)
    : _maxSize(maxSize)
{}

/* OCCF: copy constructor */
Span::Span(const Span& origin)
    : _maxSize(origin._maxSize)
{
    std::vector<int>::const_iterator it;
    for (it = origin._vec.begin(); it != origin._vec.end(); ++it)
        this->_vec.push_back(*it);
}

/* OCCF: copy assignment operator overloading */
Span& Span::operator=(const Span& origin)
{
    if (this != &origin)
        return *this;

    this->_maxSize = origin._maxSize;
    this->_vec.clear();
    std::vector<int>::const_iterator it;
    for (it = origin._vec.begin(); it != origin._vec.end(); ++it)
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
        throw std::out_of_range("❌ cannot add number: out of range of this Span");

    this->_vec.push_back(value);
}

unsigned int Span::shortestSpan(void)
{
    if (this->_vec.size() <= 1)
        throw std::logic_error("❌ cannot find shortest distance: Span size is too small");

    std::vector<int> temp(this->_vec);
    std::sort(temp.begin(), temp.end());
    unsigned int minimum = temp[1] - temp[0];
    std::vector<int>::iterator  it;
    for (it = temp.begin() + 1; it != temp.end(); ++it)
    {
        unsigned int dist = *it - *(it - 1);
        if (dist < minimum)
            minimum = dist;
    }
    return minimum;
}

unsigned int Span::longestSpan(void)
{
    if (this->_vec.size() <= 1)
        throw std::logic_error("❌ cannot find longest distance: Span size is too small");

    int maxElement = *std::max_element(this->_vec.begin(), this->_vec.end());
    int minElement = *std::min_element(this->_vec.begin(), this->_vec.end());
    return maxElement - minElement;
}

void Span::printNumber(void)
{
    std::cout << std::endl << "-------------[elements]-------------" << std::endl;
    std::vector<int>::iterator it;
    for (it = this->_vec.begin(); it != this->_vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "------------------------------------" << std::endl << std::endl;
}
