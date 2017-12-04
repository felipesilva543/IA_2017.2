#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <ctime>
#include "grafo.h"
#include "dfs.h"
#include "bfs.h"
#include "ucs.h"
#include "tranf_entrada.h"
using namespace std;

void InitGrafo(Grafo& grafo){
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            grafo.addPonto(i, j, 0);

    grafo.addPonto(ORADEA, ZERIND, 71);
    grafo.addPonto(ORADEA, SIBIU, 151);
    grafo.addPonto(ZERIND, ARAD, 75);
    grafo.addPonto(ARAD, SIBIU, 140);
    grafo.addPonto(ARAD, TIMISOARA, 118);
    grafo.addPonto(TIMISOARA, LUGOJ, 111);
    grafo.addPonto(LUGOJ, MEHADIA, 70);
    grafo.addPonto(MEHADIA, DROBETA, 75);
    grafo.addPonto(DROBETA, CRAIOVA, 120);
    grafo.addPonto(SIBIU, FAGARAS, 99);
    grafo.addPonto(SIBIU, RVILCEA, 80);
    grafo.addPonto(RVILCEA, PITESTI, 97);
    grafo.addPonto(RVILCEA, CRAIOVA, 146);
    grafo.addPonto(CRAIOVA, PITESTI, 138);
    grafo.addPonto(FAGARAS, BUCHAREST, 211);
    grafo.addPonto(PITESTI, BUCHAREST, 101);
    grafo.addPonto(BUCHAREST, GIURGIU, 90);
    grafo.addPonto(BUCHAREST, URZICENI, 85);
    grafo.addPonto(URZICENI, HIRSOVA, 98);
    grafo.addPonto(URZICENI, VASLUI, 142);
    grafo.addPonto(HIRSOVA, EFORIE, 86);
    grafo.addPonto(VASLUI, IASI, 92);
    grafo.addPonto(IASI, NEAMT, 87);
}

int main(int argc, char *argv[ ]){

    Grafo grafo;
    InitGrafo(grafo);
    Deep_Search dfs;
    Breadth_Search bfs;
    Uniform_Cost_Search ucs;
    vector<Node> solucao;
    clock_t start, end;
    float time = 0;
    int cmd = -1;

    //CONVERSÃO PELA ENTRADA DO TERMINAL
    cmd = atoi(argv[1]);
    int argOrigem = trans_entrada(argv[2]);
    int argDestino = trans_entrada(argv[3]);

    //ENTRADA DO MAPA PELO TERMINAL
    State origem = State(argOrigem);
    State destido = State(argDestino);
    //Estrada MAP
    //State origem = State(ARAD);
    //State destido = State(BUCHAREST);
    //fim Entrada Mapda

//    while(cmd != 0){
//        cout << "BUSCAS:                         \n"
//                "  1 - Busca em Profundidade     \n"
//                "  2 - Busca em Largura          \n"
//                "  3 - Busca por custo uniforme  \n"
//                "  0 - exit                      \n"
//             << "(opção): ";

//            cin >> cmd;

        try{
            if(cmd == 1){
                cout << endl << "Busca em profundidade:" << endl;
                start = clock();
                solucao = dfs.DFS(origem, destido, grafo);
                end = clock();
                time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);
            }

            if(cmd == 2){
                cout << endl << "Busca em largura:" << endl;
                start = clock();
                solucao = bfs.BFS(origem, destido, grafo);
                end = clock();
                time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);
            }

            if(cmd == 3){
                cout << endl << "Busca por Custo Uniforme:" << endl;
                start = clock();
                solucao = ucs.UCS(origem, destido, grafo);
                end = clock();
                time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);
            }
            if(cmd != 0){
                string cidades[20] = {  "ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                                        "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                                        "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                                        "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE"};
                cout << "Solução: " << "[ ";
                for(auto elemento : solucao){
                    cout << cidades[elemento.getStateNode().getState()] << " ";
                }
                cout << "]" << endl;
                cout << "Tempo de execução: " << time << endl << endl;
            }

        }catch(string e){
                cout << e << endl;
        }
   // }
    return 0;
}




