// Trabalho Prático 3 - Estrutura de Dados
// Autor: José Gabriel Vieira de Souza

// Main file

#include "../include/segtree.hpp"

class invalidInputException: public std::exception {
    virtual const char* what() const throw() {
        return "Invalid input";
    }
};

void invalidInput() {
    throw invalidInputException();
}

int main() { 
    try {
        char op;
        int numInst = 0, numOps = 0;

        std::cin >> numInst >> numOps;

        Matrix matrixA; // 2x2 identity matrix
        MatrixL matrixB, result; // 2x1 matrix used for linear transformation
        SegTree segTree = SegTree(numInst); // Segment Tree O(n)

        for (int i = 0; i < numOps; i++) {
            std::cin >> op;

            switch (op) {
                case 'u': // update
                    int time; // index of the update
                    std::cin >> time;
                    if (time < 0 || time >= numInst) invalidInput();
                    segTree.update(time, 0, numInst - 1, 1); // O(log n)
                    break;
                case 'q': // query
                    int birthTime, deathTime;
                    std::cin >> birthTime >> deathTime >> matrixB.x1 >> matrixB.x2;
                    if (birthTime < 0 || birthTime >= numInst || 
                        deathTime < 0 || deathTime >= numInst) invalidInput();
                    matrixA = segTree.query(birthTime, deathTime, 0, numInst - 1, 1); // O(log n)
                    result.x1 = (matrixA.x1 * matrixB.x1 + matrixA.y1 * matrixB.x2);
                    result.x2 = (matrixA.x2 * matrixB.x1 + matrixA.y2 * matrixB.x2);
                    std::cout << result.x1 % 100000000 << 
                        " " << result.x2 % 100000000 << std::endl;
                    break;
                default:
                    std::cerr << "Invalid operation" << std::endl;
                    i--; // ignore invalid operation
                    break;
            }
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}