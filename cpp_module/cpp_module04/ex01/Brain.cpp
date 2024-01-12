#include "./Brain.hpp"

/* OCCF: constructor */
Brain::Brain()
{
    std::cout << "🧠 [Brain]: default constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "(default)";
}

/* OCCF: copy constructor */
Brain::Brain(const Brain& origin)
{
    std::cout << "🧠 [Brain]: copy constructor" << std::endl;
    // *this = origin;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = origin._ideas[i];
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
void Brain::setIdeas(int idx, const std::string& ideas)
{
    if (idx >= 100 || idx < 0)
        std::cout << "❌ Wrong index for ideas!!" << std::endl;
    else
        this->_ideas[idx] = ideas;
}

const std::string& Brain::getIdeas(int idx) const
{
    if (idx >= 100 || idx < 0)
    {
        std::cout << "❌ Wrong index for ideas!!" << std::endl;
        return "(null)";
    }
    return this->_ideas[idx];
}
