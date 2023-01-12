#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> nombres;

void push(int num) {
    nombres.push(num);
}

int pop() {
    int num = nombres.top();
    nombres.pop();
    return num;
}

int top() {
    return nombres.top();
}

int calcul(char operateur) {
    int num1, num2;
    num2 = pop();
    num1 = pop();
    switch (operateur) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0){
                cout << "Erreur de calcul : impossible de diviser par 0"<< endl;
            }
            else
            return num1 / num2;
        default:
            cout << "Erreur: opérateur inconnu" << endl;
            return 0;
    }
}

int eval(string chaine) {
    int nombre = 0;
    bool lecture_nombre = false;
    for (int i = 0; i < chaine.length(); i++) {
        char c = chaine[i];
        if (c == ' ') {
            if (lecture_nombre) {
                push(nombre);
                nombre = 0;
                lecture_nombre = false;
            }
        } else if (isdigit(c)) {
            lecture_nombre = true;
            nombre = nombre * 10 + c - '0';
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (lecture_nombre) {
                push(nombre);
                nombre = 0;
                lecture_nombre = false;
            }
            push(calcul(c));
        } else {
            cout << "Erreur: caractère inconnu" << endl;
            return 0;
        }
    }
    if (lecture_nombre) {
        push(nombre);
    }
    return top();
}

int main() {
    string chaine;
    cout << "Entrez une expression en notation polonaise inversée, mettre des espaces entre les opérateurs et les opérandes sinon ça ne marche pas : ";
    getline(cin, chaine);
    cout << "Résultat: " << eval(chaine) << endl;
    return 0;
}