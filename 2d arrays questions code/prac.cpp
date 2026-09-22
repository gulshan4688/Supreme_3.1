#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v{1,2,3,4};
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    std::erase(v,2);
    return 0;
}