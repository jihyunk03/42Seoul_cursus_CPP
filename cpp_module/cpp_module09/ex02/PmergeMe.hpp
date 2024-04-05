#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>

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
        std::vector<long>                   _vecSorted;     // 최종 sort 결과물

        std::vector<long>                   _vecArgs;       // input argumets(origin)
        std::vector< std::pair<long, long> >    _vecPair;       // 역으로 정렬된 짝이 이뤄진 벡터로, mainChain과 pendingChain을 결정하기 위한 값(merge sort)

        std::vector<long>                   _mainChain;     // 맴버 변수로는 적합하진 않은것 같은데 이들에 대해 다시 고민해보기
        std::vector<long>                   _pendingChain;  // clear 진행하고 하던가 아니면 아예 없애던가 하자

        std::vector<size_t>                 _jacobNum;// size_t로 바꾸기!!!!!!!!!!!!!!!!!!!!!1

        // std::deque<int>     _dq;

        /* member function */       // 그리고, function-overloading 이용할것!(이름을 달리하는 것이 아니라ㅡㅡ)
        void    _reserveContainer(int count);
        void    _checkNPush(int count, char** args);
        void    _calculateJacobsthalArr(size_t count);

        void    _mergeInsertionSort(std::vector<long>& vec, size_t size);
        // mergeInsertionSort -> needed
        size_t  _binarySearchForInsertion(std::vector<long>& sortedVec, size_t right, long insertValue);

        // for debug
        void    _printVector(const std::vector<long>& vec, const std::string& vecName) {
            std::cout << vecName << ": ";
            for (size_t i = 0; i < vec.size(); ++i)
                std::cout << vec[i] << " ";
            std::cout << "| size: " << vec.size() << std::endl;
        }


        // void    _makePairNSortVec(void);
        // void    _mergeSortRecursiveVec(int left, int right);
        // void    _divideMainPendingChain(void);
        // void    _binarySearchInsertionVec(void);

    public:
        /* OCCF */
        PmergeMe(int ac, char** av);
        ~PmergeMe();

        /* member function */
        void    runFordJohnson(void);
        const std::vector<long>& getSortedVec(void);
        // void    _fordJohnsonAlDq(void);

        // print ?
};

#endif