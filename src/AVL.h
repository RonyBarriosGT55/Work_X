#ifndef AVL_H
#define AVL_H

#include "Student.h"

class AVL {
private:
    struct Node {
        Student data;
        Node* left;
        Node* right;
        int height;

        explicit Node(const Student& student);
    };

    Node* root;

    int height(Node* node) const;
    int getBalance(Node* node) const;
    int max(int a, int b) const;

    bool isLess(const Student& a, const Student& b) const;

    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);

    Node* insert(Node* node, const Student& student);

    void showRankingDescending(Node* node) const;
    void searchBySkillScore(Node* node, int skillScore, bool& found) const;

    int countNodes(Node* node) const;
    int countLeaves(Node* node) const;

    void destroy(Node* node);

    void printStudent(const Student& student) const;

public:
    AVL();
    ~AVL();

    void insertStudent(const Student& student);
    void showRanking() const;
    void findBySkillScore(int skillScore) const;
    void showStats() const;
    bool isEmpty() const;
};

#endif