#include "pattern_tester.hpp"

class Singleton
{
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
private:
    Singleton()
    {
        std::cout << "Singleton constructor call" << std::endl;
    }
    ~Singleton()
    {
        std::cout << "Singleton destructor call" << std::endl;
    }
};

void PatternTester::run()
{
    // Singleton a; // should fail to compile
    // Singleton b(a); // should fail to compile
    // Singleton c = a; // should fail to compile
    // Singleton d(std::move(a)); // should fail to compile
    Singleton& e = Singleton::getInstance();
    Singleton& f = Singleton::getInstance();

    if (&e == &f)
    {
        std::cout << "address of 'e' equals to address of 'f'" << std::endl;
        std::cout << "address: " << &e << std::endl;
    }
}