#include <iostream>
#include <stdexcept>

using namespace std;

class ProhibitedParameterError : public logic_error {
public:
    ProhibitedParameterError() : logic_error("Passed d. d is prohibited") {}
};

class Resource
{ 
public:
    void use(const char* N)
    {
        cout << "Using resource. Passed " << *N << endl;
        if (*N == 'd')
        {
            throw ProhibitedParameterError();
        }
    };
};

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cerr << "You need to pass 1 argument" << endl;
        exit(-1);
    }
    const char* N = argv[1];
    Resource* rsc = nullptr;
    try
    {
        rsc = new Resource();
        rsc->use(N);
        delete rsc;
    }
    catch (ProhibitedParameterError & e)
    {
        cout << e.what() << endl;
        delete rsc;
    }

    return 0;
}

