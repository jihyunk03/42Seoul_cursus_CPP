// #include "./PmergeMe.hpp"

// /* OCCF: constructor */
// PmergeMe::PmergeMe(int ac, char** av)
// {
//     if (ac < 3)
//         throw std::logic_error("Error: arguments are more than 3");
//     this->_checkNPush(ac, av);
//     this->_calculateJacobsthalArr(ac / 2);
// }

// /* OCCF: destructor */
// PmergeMe::~PmergeMe()
// {}

// /* member function: public */
// void PmergeMe::runFordJohnson(void)
// {
//     // clock으로 시간재서 프린트하는 형식으로 진행
//     this->_mergeInsertionSort(this->_vec);
// }

// const std::vector<long>& PmergeMe::getVec(void)
// {
//     return this->_vec;
// }


// /* member function: private */
// void PmergeMe::_mergeInsertionSort(std::vector<long>& vec)
// {
//     // step 1
//     // std::cout << "============IN==============" << std::endl;
//     if (vec.size() < 2) {
//         // std::cout << "============return!!!==============" << std::endl << std::endl;
//         return;
//     }
//     size_t                                  halfSize = vec.size() / 2;
//     std::vector<long>                       mainChain;
//     std::vector<long>                       pendingChain;
//     std::vector< std::pair<long, long> >    vecPair;
//     for (size_t i = 0; i < halfSize; ++i) {
//         if (vec[i] > vec[i + halfSize]) {
//             mainChain.push_back(vec[i]);
//             pendingChain.push_back(vec[i + halfSize]);
//         } else {
//             mainChain.push_back(vec[i + halfSize]);
//             pendingChain.push_back(vec[i]);
//         }
//         vecPair.push_back(std::make_pair(mainChain[i], pendingChain[i]));
//     }
//     if (vec.size() % 2 == 1)
//         pendingChain.push_back(vec.back());

//     std::cout << "before recursive: vecsize(" << vec.size() << ")[";
//     for (size_t i = 0; i < mainChain.size(); ++i)
//         std::cout << mainChain[i] << " ";
//     std::cout << ", size: " << mainChain.size() << "], [";
//     for (size_t i = 0; i < pendingChain.size(); ++i)
//         std::cout << pendingChain[i] << " ";
//     std::cout << ", size: " << pendingChain.size() << "]" << std::endl;

//     // step 2
//     this->_mergeInsertionSort(mainChain);
//     this->_printVector(mainChain, "mainChain(1)");
//     this->_printVector(pendingChain, "pendingChain(1)");
//     std::cout << "vecPair: ";
//     for (size_t i = 0; i < vecPair.size(); ++i) {
//         std::cout << "(" << vecPair[i].first << ", " << vecPair[i].second << ") ";
//     }
//     std::cout << std::endl;

//     if (mainChain.size() != 1) {
//         for (size_t i = 0; i < mainChain.size(); ++i) {
//             size_t findIdx = 0;
//             while (mainChain[i] != vecPair[findIdx].first) findIdx++;       // 아아아아ㅏ아아아아아아아아ㅏ아아아아아ㅏ아아아아아아앙아아각아가악아강가아악아가악
//             std::cout << "[mainchain: " << mainChain[i] << ", find idx: " << findIdx << "]" << std::endl;
//             pendingChain[i] = vecPair[findIdx].second;
//         }
//     }

//     // step 3
//     std::vector<long> sortedVec(mainChain);
//     this->_printVector(sortedVec, "mainChain(2)");
//     this->_printVector(pendingChain, "pendingChain(2)");
//     sortedVec.insert(sortedVec.begin(), pendingChain.front());
//     size_t jacobIdx = 1;        // 0은 이미 삽입
//     size_t prev = 0, curr = 1;
//     while (curr <= pendingChain.size() - 1) {
//         curr = this->_jacobNum[jacobIdx++] - 1;
//         if (curr >= pendingChain.size())
//             curr = pendingChain.size() - 1;
//         for (size_t i = curr; i > prev; --i) {
//             size_t range = 0;
//             while (sortedVec[range] != mainChain[i]) range++;
//             size_t insertPos = this->_binarySearchForInsertion(sortedVec, range, pendingChain[i]);
//             sortedVec.insert(sortedVec.begin() + insertPos, pendingChain[i]);
//             // debug
//             std::cout << "insertPos: " << insertPos << ", insert-pending: " << pendingChain[i] << std::endl;
//             this->_printVector(sortedVec, "sorting vector");
//         }
//         prev = curr++;
//     }
//     // vec = sortedVec;
//     std::copy(sortedVec.begin(), sortedVec.end(), vec.begin());
//     std::cout << "============sort: ";
//     for (size_t i = 0; i < sortedVec.size(); ++i)
//         std::cout << sortedVec[i] << " ";
//     std::cout << "============" << std::endl << std::endl;

// }

// size_t PmergeMe::_binarySearchForInsertion(std::vector<long>& sortedVec, size_t right, long insertValue)
// {
//     size_t left = 0;

//     while (left < right) {
//         size_t mid = (left + right) / 2;
//         if (sortedVec[mid] > insertValue)
//             right = mid;
//         else
//             left = mid + 1;
//     }
//     return left;
// }

// void PmergeMe::_checkNPush(int count, char** args)
// {
//     for (int i = 1; i < count; i++) {
//         char* pos;
//         long num = strtol(args[i], &pos, 10);
//         if (*pos != '\0')               // string에 넣어서 empty 검사하는 형식 아니어도 됨 ㅇㅇ
//             throw std::logic_error("Error: arguments are must be integer");
//         if (std::find(this->_vec.begin(), this->_vec.end(), num) != this->_vec.end())
//             throw std::logic_error("Error: all numbers must be different from each other");
//         if (num <= 0)
//             throw std::logic_error("Error: all numbers must be positive integer");
//         this->_vec.push_back(num);
//         // this->_dq.push_back(num);
//     }
// }

// void PmergeMe::_calculateJacobsthalArr(size_t count)
// {   // 1  3  5  11  21  43  ...
//     if (this->_jacobNum.empty() == false)
//         this->_jacobNum.clear();
//     this->_jacobNum.push_back(1);       // hard-coding
//     this->_jacobNum.push_back(3);       // hard-coding

//     size_t curr = 3, now = 2;              // hard-coding
//     while (curr <= count) {
//         curr = this->_jacobNum[now - 1] + 2 * this->_jacobNum[now - 2];
//         this->_jacobNum.push_back(curr);
//         ++now;
//     }
// }
