#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>

class PmergeMe
{
    private:
        /* OCCF */
        PmergeMe(const PmergeMe& origin);
        PmergeMe& operator=(const PmergeMe& origin);

    public:
        /* OCCF */
        PmergeMe();
        ~PmergeMe();
};

#endif