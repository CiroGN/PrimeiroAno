#include <iostream>
using namespace std;

class Pessoa{
   int meu_id = 0;
public:
   Pessoa(int myid){
       meu_id = myid;
       cout << "constructor: " << meu_id << endl;
   };
   ~Pessoa(){
       cout<<"destrutor: " << meu_id << endl;
   };
   void teste(){
       cout<<"teste.. " << meu_id << endl;
   };
};

void funcao(){
   Pessoa p2(22);
   p2.teste();
};

int main() {
   funcao();
   Pessoa p1(11);
   p1.teste();
   return 0;
}
