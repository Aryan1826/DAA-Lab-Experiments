#include <stddef.h>
             
using namespace std;

int main(){
   cout<<"Enter the Value of X:";
   cin >> x;
   cout << "Enter the value of n:";
   cin >> n;
   int result = 1;
   for(int i =1;i<=n; i++, result=result*x);
   cout<<x<<"^"<<n<<":"<<result;
   return 0;
}

