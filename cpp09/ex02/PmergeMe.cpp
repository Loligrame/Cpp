#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj)
    : _vector(obj._vector), _deque(obj._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
    if (this != &obj) {
        _vector = obj._vector;
        _deque = obj._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

const vector_t& PmergeMe::getVector() const {
    return _vector;
}

void PmergeMe::setVector(const vector_t& vec) {
    _vector = vec;
}

const deque_t& PmergeMe::getDeque() const {
    return _deque;
}

void PmergeMe::setDeque(const deque_t& deq) {
    _deque = deq;
}

void PmergeMe::printAfter() const {
    std::cout << BOLD_GREEN << "\nAfter: " << RESET;
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << BOLD << _vector[i] << " ";
    std::cout << RESET << std::endl;
}

void PmergeMe::printTime(int containerType, double time) const {
    std::string container = (containerType == VECTOR) ? "vector" : "deque";
    size_t size = (containerType == VECTOR) ? _vector.size() : _deque.size();
    std::cout << "\nTime to process a range of " << size
              << " elements with std::" << container
              << ": " << std::fixed << std::setprecision(4)
              << BOLD << time << "ms." << RESET << std::endl;
}

template <typename Container>
void PmergeMe::binaryInsert(Container& sorted, int value) {
    typename Container::iterator low = sorted.begin();
    typename Container::iterator high = sorted.end();

    while (low < high) {
        typename Container::iterator mid = low + (high - low) / 2;
        if (value < *mid)
            high = mid;
        else
            low = mid + 1;
    }
    sorted.insert(low, value);
}

std::vector<int> generateJohnsthalSequence(int n) {
    std::vector<int> johnsthal;
    johnsthal.push_back(0);
    johnsthal.push_back(1);
    size_t i = 2;
    while (true) {
        int next = johnsthal[i - 1] + 2 * johnsthal[i - 2];
        if (next >= n)
            break;
        johnsthal.push_back(next);
        i++;
    }
    std::reverse(johnsthal.begin(), johnsthal.end());
    return johnsthal;
}

template <typename Container>
Container PmergeMe::mergeInsertionSort(const Container& input) {
    if (input.size() <= 1)
        return input;

    Container tempInput = input;
    typename Container::value_type leftover;
    bool hasLeftover = false;

    if (tempInput.size() % 2 != 0) {
        leftover = tempInput.back();
        tempInput.pop_back();
        hasLeftover = true;
    }

    std::vector<std::pair<int, int> > pairs;
    if (pairs.empty())  // protection contre erreur
        return input;
    for (size_t i = 0; i < tempInput.size(); i += 2) {
        int first = tempInput[i];
        int second = tempInput[i + 1];
        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }

    Container mainSequence;
    // 1. Ajouter b1
    int b1 = pairs[0].second;
    mainSequence.push_back(b1);

    // 2. Ajouter tous les a_i
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainSequence.push_back(pairs[i].first);
    }

    // 3. Trier mainSequence
    mainSequence = mergeInsertionSort(mainSequence);

    // 4. Construire pendSequence avec tous les b_i sauf b1
    Container pendSequence;
    for (size_t i = 1; i < pairs.size(); ++i) {
        pendSequence.push_back(pairs[i].second);
    }

    // 5. Insérer chaque élément de pendSequence dans mainSequence
    for (typename Container::iterator it = pendSequence.begin(); it != pendSequence.end(); ++it) {
        binaryInsert(mainSequence, *it);
    }

    // 6. Insérer leftover si présent
    if (hasLeftover)
        binaryInsert(mainSequence, leftover);

    return mainSequence;
}

double getTime() {
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == -1)
        throw ErrorTimeException();
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

void PmergeMe::printBefore() const {
    std::cout << BOLD_YELLOW << "\nBefore: " << RESET;
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << BOLD << _vector[i] << " ";
    std::cout << RESET << std::endl;
}

void PmergeMe::fillContainers(int ac, char** av) {
    for (int i = 1; i < ac; ++i) {
        int value = atoi(av[i]);
        _vector.push_back(value);
        _deque.push_back(value);
    }
}

void PmergeMe::checkInput(int ac, char** av) {
    for (int i = 1; i < ac; ++i) {
        std::string input = av[i];
        for (size_t j = 0; j < input.length(); ++j) {
            if (!isdigit(input[j]))
                throw WrongInputException();
        }
        double val = atof(av[i]);
        if (val < 0 || val > INT_MAX)
            throw WrongInputException();
    }
}

template vector_t PmergeMe::mergeInsertionSort<vector_t>(const vector_t&);
template deque_t  PmergeMe::mergeInsertionSort<deque_t >(const deque_t&);
