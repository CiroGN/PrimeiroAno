#include <iostream>
#include <cmath>

class Ponto {
private:
    int x, y;

public:
    Ponto(int x, int y) : x(x), y(y) {}

    int distancia(const Ponto* outroPonto) const {
        int dx = outroPonto->x - x;
        int dy = outroPonto->y - y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    Ponto ptoA(1, 1);
    Ponto ptoB(5, 5);

    int d1 = ptoA.distancia(&ptoB);
    int d2 = ptoB.distancia(&ptoA);

    std::cout << "d1: " << d1 << std::endl;
    std::cout << "d2: " << d2 << std::endl;

    return 0;
}
