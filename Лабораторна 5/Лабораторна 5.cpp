#include <iostream>


class ArithmeticOperation {
public:
    virtual double perform(double operand1, double operand2) const = 0;
};


class AdditionOperation : public ArithmeticOperation {
public:
    double perform(double operand1, double operand2) const override {
        return operand1 + operand2;
    }
};

class SubtractionOperation : public ArithmeticOperation {
public:
    double perform(double operand1, double operand2) const override {
        return operand1 - operand2;
    }
};

class MultiplicationOperation : public ArithmeticOperation {
public:
    double perform(double operand1, double operand2) const override {
        return operand1 * operand2;
    }
};

class DivisionOperation : public ArithmeticOperation {
public:
    double perform(double operand1, double operand2) const override {
        if (operand2 != 0) {
            return operand1 / operand2;
        }
        else {
            std::cerr << "Error: Division by zero." << std::endl;
            return 0.0;
        }
    }
};

int main() {
    AdditionOperation additionOp;

    SubtractionOperation subtractionOp;
    MultiplicationOperation multiplicationOp;
    DivisionOperation divisionOp;

    char exxitkey;
    while (true) {
        ArithmeticOperation* operation = nullptr;

        
        char operationType;
        std::cout << "Enter the operation type (+, -, *, /): ";
        std::cin >> operationType;



        switch (operationType) {
        case '+':
            operation = &additionOp;
            break;
        case '-':
            operation = &subtractionOp;
            break;
        case '*':
            operation = &multiplicationOp;
            break;
        case '/':
            operation = &divisionOp;
            break;
        default:
            std::cerr << "Error: Invalid operation type." << std::endl;
            return 1;
        }

        double operand1, operand2;
        std::cout << "Enter the first operand: ";
        std::cin >> operand1;

        std::cout << "Enter the second operand: ";
        std::cin >> operand2;

        
        std::cout << "Result: " << operation->perform(operand1, operand2) << std::endl;

        std::cout << "Press to exit 'q': ";
        std::cin >> exxitkey;
        if (exxitkey == 'q') {
            break;
        }
    }

    return 0;
}
