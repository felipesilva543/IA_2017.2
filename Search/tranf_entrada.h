#ifndef TRANF_ENTRADA
#define TRANF_ENTRADA

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int trans_entrada(string valor){
    string str = valor;
    for(int i=0; i< (int) str.size(); i++)
        {                            // Converte cada caracter de Str
         str[i] = toupper (str[i]);  // para maiusculas
        }

    string entrada[20] = {  "ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                            "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                            "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                            "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE"};
    for(int i = 0; i < 20; i++){
        if(entrada[i] == str)
            return i;

    }
    return 0;
}


#endif // TRANF_ENTRADA

