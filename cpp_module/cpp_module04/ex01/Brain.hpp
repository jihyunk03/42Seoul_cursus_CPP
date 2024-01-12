#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    private:
        std::string _ideas[100];

    public:
        /* OCCF */
        Brain();
        Brain(const Brain& origin);
        Brain& operator=(const Brain& origin);
        ~Brain();

        /* member functions */
        void                setIdeas(int idx, const std::string& ideas);
        const std::string&  getIdeas(int idx) const;
};

#endif
