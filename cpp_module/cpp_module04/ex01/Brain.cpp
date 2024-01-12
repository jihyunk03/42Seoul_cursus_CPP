#include "./Brain.hpp"

/* OCCF: constructor */
Brain::Brain()
{
    std::cout << "🧠 [Brain]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
Brain::Brain(const Brain& origin)
{
    std::cout << "🧠 [Brain]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
Brain& Brain::operator=(const Brain& origin)
{
    std::cout << "🧠 [Brain]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = origin._ideas[i];
    return *this;
}

/* OCCF: Destructor */
Brain::~Brain()
{
    std::cout << "🧠 [Brain]: destructor" << std::endl;
}

/* member functions */
