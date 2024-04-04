#include "./PmergeMe.hpp"

/* OCCF: constructor */
PmergeMe::PmergeMe(int ac, char** av)
{
    if (ac < 3)
        throw std::logic_error("Error: arguments are more than 3");
    this->_vecArgs.clear();
    // this->_dq.clear();
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
    // this->_mainChain.clear();
    // this->_pendingChain.clear();
    this->_makePairNSortVec();
    this->_mergeSortRecursiveVec(0, this->_vecPair.size() - 1);
    this->_divideMainPendingChain();
    this->_binarySearchInsertionVec();
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

void PmergeMe::_makePairNSortVec(void)
{
    for (int i = 0; i < this->_vecArgs.size(); ++(++i)) {
        if (i == this->_vecArgs.size() - 1)
            break;
        if (this->_vecArgs[i] > this->_vecArgs[i + 1])
            this->_vecPair.push_back(std::make_pair(this->_vecArgs[i], this->_vecArgs[i + 1]));
        else
            this->_vecPair.push_back(std::make_pair(this->_vecArgs[i + 1], this->_vecArgs[i]));
    }
}

void PmergeMe::_mergeSortRecursiveVec(int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    this->_mergeSortRecursiveVec(left, mid);
    this->_mergeSortRecursiveVec(mid + 1, right);
    std::vector<std::pair<long, long>> temp(this->_vecPair);
    int l = left, r = mid + 1, now = left;
    while (l <= mid && r <= right) {
        if (this->_vecPair[l].first <= this->_vecPair[r].first)
            temp[now++] = this->_vecPair[l++];
        else
            temp[now++] = this->_vecPair[r++];
    }
    int remain = l;
    if (l == mid)
        remain = r;
    while (now <= right)
        temp[now++] = this->_vecPair[remain++];
    this->_vecPair = temp;
}

void PmergeMe::_divideMainPendingChain(void)
{
    // if (this->_vecPair.empty() == false)
    //     this->_vecPair.clear();
    std::vector<std::pair<long, long>>::iterator it = this->_vecPair.begin();
    for (; it != this->_vecPair.end(); ++it) {
        this->_mainChain.push_back((*it).first);
        this->_pendingChain.push_back((*it).second);
    }
    if (this->_vecArgs.size() % 2 == 1)
        this->_pendingChain.push_back(this->_vecArgs.back());
}

void PmergeMe::_binarySearchInsertionVec(void)
{

}