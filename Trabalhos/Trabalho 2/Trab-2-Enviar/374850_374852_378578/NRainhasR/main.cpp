#include <iostream>

#include "nrainhas.h"
using namespace std;

int main(int argc, char *argv[ ]){
    string cmd = "";
    cmd = argv[1];
    NRainhas nR = NRainhas(cmd);
    nR.gegarArquivo();
    return 0;
}

