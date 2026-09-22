#include <iostream>
using namespace std;
void last_occurence(string word, int index, char find, int &ans)
{
    // base case
    if (index < 0)
    {
        return;
    }
    // we solve one case
    if (word[index] == find)
    {
        ans = index;
        return;
    }
    // recursive call
    last_occurence(word, index - 1, find, ans);
}
int main()
{
    string word = "abcdeddfdgh";
    char find = 'b';
    int ans = -1;
    last_occurence(word, word.size() - 1, 'a', ans);
    cout << ans;
    return 0;
}