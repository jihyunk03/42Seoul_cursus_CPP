#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <ctime>

# define PRINTALL   1
# define PRINTTIME  0

class PmergeMe
{
    private:
        /* OCCF */
        PmergeMe();
        PmergeMe(const PmergeMe& origin);
        PmergeMe& operator=(const PmergeMe& origin);

        /* member variable */
        std::vector<long>   _vec;
        std::deque<int>     _dq;
        std::vector<size_t> _jacobNum;


        /* member function */
        void    _checkNPush(int count, char** args);
        void    _calculateJacobsthalArr(size_t count);

        void    _mergeInsertionSort(std::vector<long>& vec);
        void    _mergeInsertionSort(std::deque<long>& dq);

        size_t  _binarySearchForInsertion(std::vector<long>& sortedVec, size_t right, long insertValue);
        size_t  _binarySearchForInsertion(std::deque<long>& sortedDq, size_t right, long insertValue);

    public:
        /* OCCF */
        PmergeMe(int ac, char** av);
        ~PmergeMe();

        /* member function */
        void                        runFordJohnson(void);
        const std::vector<long>&    getVec(void);
        const std::deque<long>&     getDq(void);

        void                        printContainer(const std::vector<long>& vec, const std::string& vecName);
        void                        printContainer(const std::vector< std::pair<long, long> >& vecPair, const std::string& pairName);
        void                        printContainer(const std::deque<long>& dq, const std::string& dqName);
        void                        printContainer(const std::deque< std::pair<long, long> >& dqPair, const std::string& pairName);

        void                        printIsSorted(const std::vector<long>& vec);
        void                        printIsSorted(const std::deque<long>& dq);
};

#endif