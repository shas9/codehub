#include <primesieve.hpp>
#include <iostream>

int main()
{
    primesieve::iterator it;
    uint64_t prime = it.next_prime();

    // iterate over the primes below 10^6
    for (; prime < 1000000; prime = it.next_prime())
        std::cout << prime << std::endl;

    return 0;
}
