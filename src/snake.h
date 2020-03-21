#include <iostream>
#include <cstdlib>
using namespace std;

class Snake{
public:
    char* x, *y;
    int tamanho, maximo, m_x, m_y;
    int comida_x, comida_y;
    int dir;    //0: Direita    1: Baixo    2: Esquerda     3: Cima
    Snake(int a = 51, int b = 11);
    ~Snake();
    void Desenha();
    void Inicia();
};
