#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> numbers;

void push(int num) {
    numbers.push(num);
}

int pop() {
    int num = numbers.top();
    numbers.pop();
    return num;
}

int top() {
    return numbers.top();
}

int operate(char op) {
    int num1, num2;
    num2 = pop();
    num1 = pop();
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            cout << "Erreur: opérateur inconnu" << endl;
            return 0;
    }
}

int eval(string expr) {
    int number = 0;
    bool reading_number = false;
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == ' ') {
            if (reading_number) {
                push(number);
                number = 0;
                reading_number = false;
            }
        } else if (isdigit(c)) {
            reading_number = true;
            number = number * 10 + c - '0';
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (reading_number) {
                push(number);
                number = 0;
                reading_number = false;
            }
            push(operate(c));
        } else {
            cout << "Erreur: caractère inconnu" << endl;
            return 0;
        }
    }
    if (reading_number) {
        push(number);
    }
    return top();
}

int main() {
    string expr;
    cout << "Entrez une expression en notation polonaise inversée: ";
    getline(cin, expr);
    cout << "Résultat: " << eval(expr) << endl;
    return 0;
}
