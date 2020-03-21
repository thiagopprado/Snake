#include "snake.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

Snake::Snake(int a, int b){
    m_x = a-1; //Ultima posicao em x
    m_y = b-1; //Ultima posicao em y
    dir = 0;   //Direita
    maximo = (a-2)*(b-2); //Tamanho maximo
    tamanho = 1;
    x = new char [maximo];
    y = new char [maximo];
    for (int i = 0; i< maximo; i++){
        x[i] = 0;
        y[i] = 0;
    }
    x[0] = a/2;
    y[0] = b/2;
    srand(time(NULL));
    comida_x = rand() % (m_x-1)+1;
    comida_y = rand() % (m_y-1)+1;
}
Snake::~Snake(){
    delete [] x;
    delete [] y;
}
void Snake::Desenha(){
    for (int j = 0; j<m_y; j++){
        for (int i = 0; i<m_x; i++){
            if (!i || !j){
                cout << (char) 176;
            }
            else{
                if (i == comida_x && j == comida_y){
                    if (i == x[0] && j == y[0]){
                        tamanho++;
                        comida_x = rand() % (m_x-1)+1;
                        comida_y = rand() % (m_y-1)+1;
                        cout << "o";
                    }
                    else{
                        cout << "*";
                    }
                }
                else{
                    bool flag = true;
                    for (int k = 0; k < tamanho; k++){
                        if (x[k] == i && y[k] == j){
                            if (k==0){
                                cout << "o";
                            }
                            else{
                                cout << ".";
                            }
                            flag = false;
                        }
                    }
                    if (flag)
                        cout << " ";
                }
            }
        }
        cout << (char)176 << "\n";
    }
    for (int i = 0; i<=m_x; i++){
        cout << (char) 176;
    }
}
void Snake::Inicia(){
    Desenha();
    cout << endl;
    system ("pause");
    for (;;){//ever
        if (!x[0] || !y[0] || (x[0]==m_x) || (y[0]==m_y)){
            cout << "\nEle morreu!\n";
            system ("pause");
            return;
        }
        if (tamanho == maximo){
            cout << "\nEle ganhou!\n";
            system ("pause");
            return;
        }
        Sleep(5);
        system ("cls");
        cout << "Seu tamanho: " << tamanho << "\tTamanho maximo: " << maximo << endl;
        Desenha();
        if (kbhit()){
            switch (getch()){
            case 77: //Direita
                if (dir != 2)
                    dir = 0;
                break;
            case 80: //Baixo
                if (dir != 3)
                    dir = 1;
                break;
            case 75: //Esquerda
                if (dir != 0)
                    dir = 2;
                break;
            case 72: //Cima
                if (dir != 1)
                    dir = 3;
                break;
            }
        }
        switch (dir){
        case 0:
            for (int i = tamanho -1; i>0; i--){
                x[i] = x[i-1];
                y[i] = y[i-1];
            }
            x[0]++;
            break;
        case 1:
            for (int i = tamanho -1; i>0; i--){
                x[i] = x[i-1];
                y[i] = y[i-1];
            }
            y[0]++;
            break;
        case 2:
            for (int i = tamanho -1; i>0; i--){
                x[i] = x[i-1];
                y[i] = y[i-1];
            }
            x[0]--;
            break;
        case 3:
            for (int i = tamanho -1; i>0; i--){
                x[i] = x[i-1];
                y[i] = y[i-1];
            }
            y[0]--;
            break;
        }
        for (int i = 1; i<tamanho; i++){
            if (x[0] == x[i] && y[0] == y[i]){
                cout << "\nEle morreu!\n";
                system ("pause");
                return;
            }
        }

    }
}
