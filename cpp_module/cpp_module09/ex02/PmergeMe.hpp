#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>

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
        std::vector<std::pair<long, long>>  _vecPair;       // 역으로 정렬된 짝이 이뤄진 벡터로, mainChain과 pendingChain을 결정하기 위한 값(계속 갱신될 값)

        std::vector<long>                   _mainChain;     // 맴버 변수로는 적합하진 않은것 같은데 이들에 대해 다시 고민해보기
        std::vector<long>                   _pendingChain;  // clear 진행하고 하던가 아니면 아예 없애던가 하자

        std::vector<int>                    _jacobNum;      // dq까지는 만들 이유 없음

        // std::deque<int>     _dq;

        /* member function */
        void    _checkNPush(int count, char** args);
        void    _calculateJacobsthalArr(int count);       // 생성자 단계에서 진행

        void    _makePairNSortVec(void);
        void    _mergeSortRecursiveVec(int left, int right);
        void    _binarySearchInsertionVec(void);

        // void    _fordJohnsonAlDq(void);

    public:
        /* OCCF */
        PmergeMe(int ac, char** av);
        ~PmergeMe();

        /* member function */
        void    fordJohnsonAlVec(void);
        // print ?
};

#endif