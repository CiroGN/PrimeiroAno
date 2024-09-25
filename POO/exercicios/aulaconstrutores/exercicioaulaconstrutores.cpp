#include <iostream>
using std::cout;

class Pessoa{
   int meu_id = 0;
public:
   Pessoa(){cout<<"construtor\n";};
   ~Pessoa(){cout<<"destrutor\n";};
   void teste(){cout<<"teste..\n";};
};

void funcao(){
   Pessoa p2;
   p2.teste();
};

int main() {
   funcao();
   Pessoa p1;
   p1.teste();
   return 0;
}
