// Trabalho Prático 3 - Estrutura de Dados
// Autor: José Gabriel Vieira de Souza

// Main file

#include "../include/segtree.hpp"

int main() { 
    char op;
    int numInst = 0, numOps = 0;

    std::cin >> numInst >> numOps;

    Matrix matrixA;
    MatrixL matrixB, result;
    SegTree segTree = SegTree(numInst);

    for (int i = 0; i < numOps; i++) {
        std::cin >> op;

        switch (op) {
            case 'u': // update
                int time;
                std::cin >> time;
                segTree.update(time, 0, numInst - 1, 1);
                break;
            case 'q': // query
                int birthTime, deathTime;
                std::cin >> birthTime >> deathTime >> matrixB.x1 >> matrixB.x2;
                matrixA = segTree.query(birthTime, deathTime, 0, numInst - 1, 1);
                for (int i = 0; i < 2; i++) {
                    result.x1 = (matrixA.x1 * matrixB.x1 + matrixA.y1 * matrixB.x2);
                    result.x2 = (matrixA.x2 * matrixB.x1 + matrixA.y2 * matrixB.x2);
                }
                std::cout << result.x1 % 100000000 << 
                      " " << result.x2 % 100000000 << std::endl;
                break;
            default:
                i--;
                break;
        }
    }

    return 0;
}