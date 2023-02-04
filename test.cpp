#include <iostream>
#include <bitset>
 
using std::cout; using std::endl;
using std::string; using std::bitset;
 
int main() {
    int number = 15;
 
    bitset<32> bs1(number);
    cout << "binary:  " << bs1 << endl;
    cout<< bs1[0]==1<<endl;
    cout<< bs1[0]==0<<endl;
    cout<< bs1[0]==0<<endl;
    cout<< bs1[0]==0<<endl;
    cout<< bs1[0]==0<<endl;
    cout<< bs1[0]==0<<endl;
    bitset<16> bs2(number);
    cout << "binary:  " << bs2 << endl;
    bitset<8> bs3(number);
    cout << "binary:  " << bs3 << endl;
    bitset<5> bs4(number);
    cout << "binary:  " << bs4 << endl;
    cout << endl;
 
    return EXIT_SUCCESS;
}