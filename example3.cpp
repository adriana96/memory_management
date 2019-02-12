#include <iostream>
#include <stdexcept>
#include <memory>

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

    try
    {
        auto rsc = make_unique<Resource>();
        rsc->use(N);

    }
    catch (ProhibitedParameterError & e)
    {
        cout << e.what() << endl;

    }

    return 0;
}

