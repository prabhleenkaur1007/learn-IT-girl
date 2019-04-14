#include<iostream>
using namespace std;

/* main
 * params : argc ( No. of command line arguments )
 * argv[] : array of strings ( arguments )
 */
int main(int argc, char *argv[]) {
   cout << "No. of arguments : " << argc << endl;
   int i;
   for ( i = 0; i < argc; i++ ) {
      cout << "argv[" << i << "] = " << argv[i] << endl;
   }
   return 0;
}
