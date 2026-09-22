#include <iostream>
using namespace std;
void print_digits(int number){

    if(number==0){
        return ;
    }
    int newNum=number/10;
    print_digits(newNum);
    cout<<number%10<<" ";
}

int main()
{
    int number=389;
    print_digits(389);
    return 0;
}