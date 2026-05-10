#include "AVL.h"

#include <iostream>
#include <iomanip>

using namespace std;

AVL::Node::Node(const Student& student)
    : data(student), left(nullptr), right(nullptr), height(1) {}

AVL::AVL() : root(nullptr) {}

AVL::~AVL() {
    destroy(root);
}

int AVL::height(Node* node) const {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}

int AVL::getBalance(Node* node) const {
    if (node == nullptr) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

int AVL::max(int a, int b) const {
    return (a > b) ? a : b;
}

bool AVL::isLess(const Student& a, const Student& b) const {
    if (a.skill_score != b.skill_score) {
        return a.skill_score < b.skill_score;
    }

    return a.id < b.id;
}

AVL::Node* AVL::rotateRight(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

AVL::Node* AVL::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

AVL::Node* AVL::insert(Node* node, const Student& student) {
    if (node == nullptr) {
        return new Node(student);
    }

    if (isLess(student, node->data)) {
        node->left = insert(node->left, student);
    } else if (isLess(node->data, student)) {
        node->right = insert(node->right, student);
    } else {
        node->data = student;
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Caso izquierda izquierda
    if (balance > 1 && isLess(student, node->left->data)) {
        return rotateRight(node);
    }

    // Caso derecha derecha
    if (balance < -1 && isLess(node->right->data, student)) {
        return rotateLeft(node);
    }

    // Caso izquierda derecha
    if (balance > 1 && isLess(node->left->data, student)) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso derecha izquierda
    if (balance < -1 && isLess(student, node->right->data)) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVL::insertStudent(const Student& student) {
    root = insert(root, student);
}

void AVL::printStudent(const Student& student) const {
    cout << left
         << setw(8) << student.id
         << setw(30) << student.full_name
         << setw(30) << student.career
         << setw(10) << student.semester
         << setw(10) << fixed << setprecision(2) << student.gpa
         << setw(12) << student.skill_score
         << endl;
}

void AVL::showRankingDescending(Node* node) const {
    if (node == nullptr) {
        return;
    }

    showRankingDescending(node->right);
    printStudent(node->data);
    showRankingDescending(node->left);
}

void AVL::showRanking() const {
    if (isEmpty()) {
        cout << "\nNo hay estudiantes registrados.\n";
        return;
    }

    cout << "\n================ RANKING ACADEMICO ================\n";
    cout << left
         << setw(8) << "ID"
         << setw(30) << "Nombre"
         << setw(30) << "Carrera"
         << setw(10) << "Semestre"
         << setw(10) << "GPA"
         << setw(12) << "Skill"
         << endl;

    cout << string(100, '-') << endl;

    showRankingDescending(root);
}

void AVL::searchBySkillScore(Node* node, int skillScore, bool& found) const {
    if (node == nullptr) {
        return;
    }

    searchBySkillScore(node->left, skillScore, found);

    if (node->data.skill_score == skillScore) {
        if (!found) {
            cout << "\nEstudiante(s) encontrado(s):\n";
            cout << left
                 << setw(8) << "ID"
                 << setw(30) << "Nombre"
                 << setw(30) << "Carrera"
                 << setw(10) << "Semestre"
                 << setw(10) << "GPA"
                 << setw(12) << "Skill"
                 << endl;

            cout << string(100, '-') << endl;
        }

        printStudent(node->data);
        found = true;
    }

    searchBySkillScore(node->right, skillScore, found);
}

void AVL::findBySkillScore(int skillScore) const {
    bool found = false;
    searchBySkillScore(root, skillScore, found);

    if (!found) {
        cout << "\nNo se encontro ningun estudiante con skill_score "
             << skillScore << ".\n";
    }
}

int AVL::countNodes(Node* node) const {
    if (node == nullptr) {
        return 0;
    }

    return 1 + countNodes(node->left) + countNodes(node->right);
}

int AVL::countLeaves(Node* node) const {
    if (node == nullptr) {
        return 0;
    }

    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }

    return countLeaves(node->left) + countLeaves(node->right);
}

void AVL::showStats() const {
    cout << "\n=========== ESTADISTICAS AVL ===========\n";
    cout << "Total de estudiantes: " << countNodes(root) << endl;
    cout << "Altura del arbol: " << height(root) << endl;
    cout << "Cantidad de hojas: " << countLeaves(root) << endl;
}

bool AVL::isEmpty() const {
    return root == nullptr;
}

void AVL::destroy(Node* node) {
    if (node == nullptr) {
        return;
    }

    destroy(node->left);
    destroy(node->right);
    delete node;
}