#include "validate.hpp"
using namespace std;
int main(){
    Board a=Board();
    a.display();
    cout<<"\n";

    cout<<validate(a,7,4,6,4)<<endl;
    cout<<validate(a,7,1,5,0)<<endl;
    cout<<validate(a,7,0,7,5)<<endl;
    cout<<validate(a,4,0,4,7)<<endl;
}