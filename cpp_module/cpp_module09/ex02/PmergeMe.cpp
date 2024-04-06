#include "./PmergeMe.hpp"

/* OCCF: constructor */
PmergeMe::PmergeMe(int ac, char** av)
{
    if (ac < 3)
        throw std::logic_error("Error: arguments are more than 3");
    this->_checkNPush(ac, av);
    this->_calculateJacobsthalArr(ac / 2);
}

/* OCCF: destructor */
PmergeMe::~PmergeMe() {}


/* member function: public */
void PmergeMe::runFordJohnson(void)
{
    this->_mergeInsertionSort(this->_vec);
}

const std::vector<long>& PmergeMe::getVec(void)
{
    return this->_vec;
}


/* member function: private */
void PmergeMe::_mergeInsertionSort(std::vector<long>& vec)
{
    // step 1
    if (vec.size() < 2)
        return;

    size_t                                  halfSize = vec.size() / 2;
    std::vector<long>                       mainChain;
    std::vector<long>                       pendingChain;
    std::vector< std::pair<long, long> >    vecPair;
    for (size_t i = 0; i < halfSize; ++i) {
        if (vec[i] > vec[i + halfSize]) {
            mainChain.push_back(vec[i]);
            pendingChain.push_back(vec[i + halfSize]);
        } else {
            mainChain.push_back(vec[i + halfSize]);
            pendingChain.push_back(vec[i]);
        }
        vecPair.push_back(std::make_pair(mainChain[i], pendingChain[i]));
    }
    if (vec.size() % 2 == 1)
        pendingChain.push_back(vec.back());

    // step 2
    this->_mergeInsertionSort(mainChain);
    if (mainChain.size() != 1) {
        for (size_t i = 0; i < mainChain.size(); ++i) {
            size_t findIdx = 0;
            while (mainChain[i] != vecPair[findIdx].first) findIdx++;       // 아아아아ㅏ아아아아아아아아ㅏ아아아아아ㅏ아아아아아아앙아아각아가악아강가아악아가악
            pendingChain[i] = vecPair[findIdx].second;
        }
    }

    // step 3
    std::vector<long> sortedVec(mainChain);
    sortedVec.insert(sortedVec.begin(), pendingChain.front());
    size_t jacobIdx = 1;        // 0은 이미 삽입
    size_t prev = 0, curr = 1;
    while (curr <= pendingChain.size() - 1) {
        curr = this->_jacobNum[jacobIdx++] - 1;
        if (curr >= pendingChain.size())
            curr = pendingChain.size() - 1;
        for (size_t i = curr; i > prev; --i) {
            size_t range;
            if (vec.size() % 2 == 1 && i == pendingChain.size() - 1)
                range = sortedVec.size();
            else
                range = std::lower_bound(sortedVec.begin(), sortedVec.end(), mainChain[i]) - sortedVec.begin();
            size_t insertPos = this->_binarySearchForInsertion(sortedVec, range, pendingChain[i]);
            sortedVec.insert(sortedVec.begin() + insertPos, pendingChain[i]);
        }
        prev = curr++;
    }
    vec = sortedVec;
}

size_t PmergeMe::_binarySearchForInsertion(std::vector<long>& sortedVec, size_t right, long insertValue)
{
    size_t left = 0;

    while (left < right) {
        size_t mid = (left + right) / 2;
        if (sortedVec[mid] > insertValue)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

void PmergeMe::_checkNPush(int count, char** args)
{
    for (int i = 1; i < count; i++) {
        char* pos;
        long num = strtol(args[i], &pos, 10);
        if (*pos != '\0')
            throw std::logic_error("Error: arguments are must be integer");
        if (num <= 0)
            throw std::logic_error("Error: all numbers must be positive integer");
        this->_vec.push_back(num);
        // this->_dq.push_back(num);
    }
}

void PmergeMe::_calculateJacobsthalArr(size_t count)
{
    if (this->_jacobNum.empty() == false)
        this->_jacobNum.clear();
    this->_jacobNum.push_back(1);
    this->_jacobNum.push_back(3);
    size_t curr = 3, now = 2;
    while (curr <= count) {
        curr = this->_jacobNum[now - 1] + 2 * this->_jacobNum[now - 2];
        this->_jacobNum.push_back(curr);
        ++now;
    }
}


/* just for printing or debugging */
void PmergeMe::printContainer(const std::vector<long>& vec, const std::string& vecName)
{
    std::cout << "[ " << vecName << " ]: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << ">> size(" << vec.size() << ")" << std::endl;
}

void PmergeMe::printContainer(const std::vector< std::pair<long, long> >& vecPair, const std::string& pairName)
{
    std::cout << "[ " << pairName << " ]: ";
    for (size_t i = 0; i < vecPair.size(); ++i)
        std::cout << "(" << vecPair[i].first << ", " << vecPair[i].second << ") ";
    std::cout << ">> size(" << vecPair.size() << ")" << std::endl;
}

void PmergeMe::printContainer(const std::deque<long>& dq, const std::string& dqName)
{
    std::cout << "[ " << dqName << " ]: ";
    for (size_t i = 0; i < dq.size(); ++i)
        std::cout << dq[i] << " ";
    std::cout << ">> size(" << dq.size() << ")" << std::endl;
}

void PmergeMe::printContainer(const std::deque< std::pair<long, long> >& dqPair, const std::string& pairName)
{
    std::cout << "[ " << pairName << " ]: ";
    for (size_t i = 0; i < dqPair.size(); ++i)
        std::cout << "(" << dqPair[i].first << ", " << dqPair[i].second << ") ";
    std::cout << ">> size(" << dqPair.size() << ")" << std::endl;
}
