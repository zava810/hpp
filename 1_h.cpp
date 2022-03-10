#include <cplong.h>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
   int WJ1 = 0xFF; cplong v1 = cplong("5.75") ; 
   v1 = v1 + cplong("5.75") ;
   cout <<WJ1<<endl;
   cout <<v1<<endl;
   cout << "WJ1 * v1 * cplong("5.75") is: " << WJ1 * v1 * cplong("5.75") << endl;
    return 0;
}
