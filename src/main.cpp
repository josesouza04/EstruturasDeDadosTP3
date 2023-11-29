// Trabalho Prático 3 - Estrutura de Dados
// Autor: José Gabriel Vieira de Souza

// Main file

#include "../include/segtree.hpp"

int main() { /* 
    char op;
    int numInst = 0, numOps = 0;

    std::cin >> numInst >> numOps;

    Matrix matrixOrig = Matrix(2, 1);
    Matrix matrixA = Matrix(2, 2);
    Matrix result = Matrix(2, 1);
    SegTree segTree = SegTree(numInst);
    segTree.build(0, numInst - 1, 1);


    for(int i = 0; i < numOps; i++) {
        std::cin >> op;
        switch (op) {
            case 'u': // update
                int time, value;
                std::cin >> time;

                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        std::cin >> value;
                        matrixA.update(i, j, value);
                    }
                }
                segTree.setTreeArrayPos(time, matrixA); 
                segTree.update(time, matrixA, 0, numInst - 1, 1);

                break;
            case 'q': // query
                int birthTime, deathTime, coordX, coordY;
                std::cin >> birthTime >> deathTime >> coordX >> coordY;

                matrixOrig.update(0, 0, coordX);
                matrixOrig.update(1, 0, coordY);

                matrixA = segTree.query(birthTime, deathTime, 0, numInst - 1, 1);
                result = segTree.multiply(matrixA, matrixOrig);

                std::cout << result.getElement(0, 0) % 100000000 << 
                      " " << result.getElement(1, 0) % 100000000 << std::endl;

                break;
            default:
                break;
        }
    }
    
    matrixA.~Matrix();
    matrixOrig.~Matrix();
    segTree.~SegTree();
    result.~Matrix();
    */

    Matrix matrixA = Matrix(2, 3);
    Matrix matrixB = Matrix(3, 2);
    Matrix matrixC = Matrix(2, 2);
    SegTree segTree = SegTree(3);

    matrixA.update(0, 0, 2);
    matrixA.update(0, 1, 6);
    matrixA.update(0, 2, 4);
    matrixA.update(1, 0, 1);
    matrixA.update(1, 1, 9);
    matrixA.update(1, 2, 7);

    matrixA.print();
    matrixB.update(0, 0, 3);
    matrixB.update(0, 1, 2);
    matrixB.update(1, 0, 4);
    matrixB.update(1, 1, 10);
    matrixB.update(2, 0, 11);
    matrixB.update(2, 1, 8);
    matrixB.print();
    matrixC = matrixA.multiply(matrixA, matrixB);
    matrixC.print();



    return 0;
}