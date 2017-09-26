#include <iostream>
#include <vector>
#include <string>
//#include <utility> // Pra usar o make pair
#include <stack> // Pilha para Busca por profundidade (DFS)
using namespace std;

enum {Oradea, Zerind, Arad, Timisoara, Lugoj, Mehadia, Drobeta, Sibiu, RVilcea, Craiova,
     Fagaras, Pitesti, Bucharest, Giurgiu, Neamt, Iasi, Vaslui, Urziceni, Hirsova, Eforie
};
int numV = 20; // Número de vertices

class Grafo{
    int grafo[20][20];
  public:
    Grafo(){}

    void addPonto(int _linha, int _coluna, int _peso){
        grafo[_linha][_coluna] = _peso;
    }
    int getPeso(int _linha, int _coluna){
        if(grafo[_linha][_coluna]){
            return grafo[_linha][_coluna];
        }else if (grafo[_coluna][_linha]) {
            return grafo[_coluna][_linha];
        }
        return 0;
    }

};

void IniGrafo(Grafo& grafo){
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            grafo.addPonto(i, j, 0);

    grafo.addPonto(Oradea, Zerind, 71);
    grafo.addPonto(Oradea, Sibiu, 151);
    grafo.addPonto(Zerind, Arad, 75);
    grafo.addPonto(Arad, Sibiu, 140);
    grafo.addPonto(Arad, Timisoara, 118);
    grafo.addPonto(Timisoara, Lugoj, 111);
    grafo.addPonto(Lugoj, Mehadia, 70);
    grafo.addPonto(Mehadia, Drobeta, 75);
    grafo.addPonto(Drobeta, Craiova, 120);
    grafo.addPonto(Sibiu, Fagaras, 99);
    grafo.addPonto(Sibiu, RVilcea, 80);
    grafo.addPonto(RVilcea, Pitesti, 97);
    grafo.addPonto(RVilcea, Craiova, 146);
    grafo.addPonto(Craiova, Pitesti, 138);
    grafo.addPonto(Fagaras, Bucharest, 211);
    grafo.addPonto(Pitesti, Bucharest, 101);
    grafo.addPonto(Bucharest, Giurgiu, 90);
    grafo.addPonto(Bucharest, Urziceni, 85);
    grafo.addPonto(Urziceni, Hirsova, 98);
    grafo.addPonto(Urziceni, Vaslui, 142);
    grafo.addPonto(Hirsova, Eforie, 86);
    grafo.addPonto(Vaslui, Iasi, 92);
    grafo.addPonto(Iasi, Neamt, 87);
}

class State{
    int state;
  public:

    int getState(){
        return state;
    }
    void setState(int value){
        state = value;
    }
};

class Action{
    int origem; // Arad
    int destino; // Bucarest

};

class Node{
    State state;
    float custoDeCaminho;
    Action acao;

};

//Busca em profundidade.
void DFS(int _v){
        stack<int> pilha;
        bool visitados[numV];

        for(int i = 0; i <  numV; i++){
            visitados[i] = false;
        }

        while (true) {
            if(!visitados[_v]){
                visitados[_v] = true;
                pilha.push(_v);
            }


        }
}



int main(){
    Grafo grafo;
    IniGrafo(grafo);
    //DFS(0);



    return 0;
}




