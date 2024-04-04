#include "./PmergeMe.hpp"

/* OCCF: constructor */
PmergeMe::PmergeMe(int ac, char** av)
{
    if (ac < 3)
        throw std::logic_error("Error: arguments are more than 3");
    this->_reserveContainer(ac);
    this->_checkNPush(ac, av);
    this->_calculateJacobsthalArr(ac / 2);
}

/* OCCF: destructor */
PmergeMe::~PmergeMe()
{}

/* member function: public */
void PmergeMe::fordJohnsonAlVec(void)
{
    this->_mergeInsertionSortVec(this->_vecArgs, this->_vecArgs.size());
}

void PmergeMe::_mergeInsertionSortVec(std::vector<long>& vec, size_t size)
{
    // step 1
    if (vec.size() < 2)
        return;
    std::vector<long>                   mainChain;
    std::vector<long>                   pendingChain;
    std::vector<std::pair<long, long>>  vecPair;
    for (size_t i = 0; i < size / 2; ++i) {
        if (vec[i] > vec[i + size / 2]) {
            mainChain.push_back(vec[i]);
            pendingChain.push_back(vec[i + size / 2]);
        } else {
            mainChain.push_back(vec[i + size / 2]);
            pendingChain.push_back(vec[i]);
        }
        vecPair.push_back(std::make_pair(mainChain[i], pendingChain[i]));
    }
    if (size % 2 == 1)
        pendingChain.push_back(vec.back());

    // step 2
    this->_mergeInsertionSortVec(mainChain, mainChain.size());
    std::vector<long> tmpPending(pendingChain);
    for (size_t i = 0; i < size / 2; ++i) {
        size_t findIdx = 0;
        while (vecPair[findIdx].first == mainChain[i]) findIdx++;
        pendingChain[i] = tmpPending[findIdx];
    }

    // step 3
    std::vector<long> sortedVec(mainChain);
    mainChain.insert(mainChain.begin(), pendingChain.front());
    size_t prev = 0, curr = this->_jacobNum[0] - 1;
    while (true) {
        // if (curr <= prev)

    }

}



/* member function: private */
void PmergeMe::_reserveContainer(int count)
{
    // vector
    this->_vecSorted.reserve(count);
    this->_vecArgs.reserve(count);
    this->_vecPair.reserve(count / 2);
    this->_mainChain.reserve(count);
    this->_pendingChain.reserve(count / 2);
    // deque
}

void PmergeMe::_checkNPush(int count, char** args)
{
    for (int i = 1; i < count; i++) {
        char* pos;
        long num = strtol(args[i], &pos, 10);
        if (*pos != '\0')               // string에 넣어서 empty 검사하는 형식 아니어도 됨 ㅇㅇ
            throw std::logic_error("Error: arguments are must be integer");
        if (std::find(this->_vecArgs.begin(), this->_vecArgs.end(), num) != this->_vecArgs.end())
            throw std::logic_error("Error: all numbers must be different from each other");
        if (num <= 0)
            throw std::logic_error("Error: all numbers must be positive integer");
        this->_vecArgs.push_back(num);
        // this->_dq.push_back(num);
    }
}

void PmergeMe::_calculateJacobsthalArr(int count)
{
    if (this->_jacobNum.empty() == false)
        this->_jacobNum.clear();
    this->_jacobNum.push_back(1);       // hard-coding
    this->_jacobNum.push_back(3);       // hard-coding

    int curr = 3, now = 2;              // hard-coding
    while (curr <= count) {
        curr = this->_jacobNum[now - 1] + 2 * this->_jacobNum[now - 2];
        this->_jacobNum.push_back(curr);
        ++now;
    }
}
