// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> operators;
    std::string postfix;

    for (size_t i = 0; i < inf.length(); ++i) {
        char c = inf[i];

        if (c == ' ') continue;

        if (std::isdigit(c)) {
            if (!postfix.empty() && postfix.back() != ' ') {
                postfix += ' ';
            }
            while (i < inf.length() && std::isdigit(inf[i])) {
                postfix += inf[i++];
            }
            postfix += ' ';
            --i;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.isEmpty() && operators.top() != '(') {
                postfix += operators.pop();
                postfix += ' ';
            }
            operators.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.isEmpty() &&
                   operators.top() != '(' &&
                   prioritet(operators.top()) >= prioritet(c)) {
                postfix += operators.pop();
                postfix += ' ';
            }
            operators.push(c);
        }
    }

    while (!operators.isEmpty()) {
        postfix += operators.pop();
        postfix += ' ';
    }

    if (!postfix.empty() && postfix.back() == ' ') {
        postfix.pop_back();
    }

    return postfix;
}

int eval(const std::string& post) {
    TStack<int, 100> value;
    std::string nums;

    for (size_t i = 0; i <= post.length(); ++i) {
        char c = (i < post.length()) ? post[i] : ' ';

        if (std::isdigit(c)) {
            nums += c;
        } else if (c == ' ' && !nums.empty()) {
            value.push(std::stoi(nums));
            nums.clear();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = value.pop();
            int a = value.pop();

            switch (c) {
                case '+': value.push(a + b); break;
                case '-': value.push(a - b); break;
                case '*': value.push(a * b); break;
                case '/': value.push(a / b); break;
            }
        }
    }

    return value.pop();
}
