#pragma once 


#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <sys/time.h>
#include <iomanip>
#include <algorithm>


# define RESET  "\033[0m" 
# define RED  "\033[31m"  
# define BOLD_GREEN  "\033[1m\033[32m"    
# define BOLD_YELLOW  "\033[1m\033[33m"     
# define BOLD_BLUE  "\033[1m\033[34m"     
# define BOLD  "\033[1m\033[37m"   

#define VECTOR 1
#define DEQUE 0

typedef std::vector<int> vector_t;
typedef std::deque<int> deque_t;

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void checkInput(int argc, char** argv);
    void fillContainers(int argc, char** argv);
    void printBefore() const;
    void printAfter() const;
    void printTime(int containerType, double time) const;

    template <typename Container>
    Container mergeInsertionSort(const Container& input);

    template <typename Container>
    void binaryInsert(Container& sorted, int value);
    const vector_t& getVector() const;
    void setVector(const vector_t& vec);
    const deque_t& getDeque() const;
    void setDeque(const deque_t& deq);

private:
    vector_t _vector;
    deque_t _deque;
};

double getTime();

class ErrorTimeException : public std::exception {
public:
    virtual const char* what() const throw() {
        return RED "Error: an error occurred using gettimeofday()" RESET;
    }
};

class WrongInputException : public std::exception {
public:
    virtual const char* what() const throw() {
        return RED "Error: please enter unsigned ints only" RESET;
    }
};

