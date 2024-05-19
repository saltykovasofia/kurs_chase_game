#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "Point2D.h"
#include "Character.h"
#include "Prey.h"
#include "Predator.h"
#include "Arena.h"

const int delay = 200000; // микросекунды

// Функция, проверяющая нажатие клавиши
int kbhit() {
    return _kbhit() != 0;
}

// Функция для задержки выполнения программы в миллисекундах
void sleep(int microseconds) {
    Sleep(microseconds / 1000); // Конвертируем микросекунды в миллисекунды
}

// Функция для проверки столкновения между жертвой и хищником
int check(Prey prey, Predator predator, int rad, Arena arena, int ans) {
    std::pair<Point2D, Point2D> prey_cor = prey.getCoordinates();
    std::pair<Point2D, Point2D> predator_cor = predator.getCoordinates();
    Point2D left_prey_cor = prey_cor.first;
    Point2D right_prey_cor = prey_cor.second;
    Point2D left_predator_cor = predator_cor.first;
    Point2D right_predator_cor = predator_cor.second;

    // Проверка, находятся ли жертва и хищник в радиусе друг от друга
    if (abs(left_predator_cor.y - left_prey_cor.y) <= rad && abs(left_predator_cor.x - right_prey_cor.x) <= rad) {
        if (ans == 1)return 1;
        if (ans == 2)return -1;
    }
    if (abs(left_predator_cor.y - left_prey_cor.y) <= rad && abs(right_predator_cor.x - left_prey_cor.x) <= rad) {
        if (ans == 1)return 1;
        if (ans == 2)return -1;
    }

    // Проверка, выходит ли жертва за границы арены
    if (left_prey_cor.x < 0 || right_prey_cor.x >= arena.width || left_prey_cor.y < 0 || left_prey_cor.y >= arena.height) {
        if (ans == 1)return 1;
        if (ans == 2)return -1;
    }

    // Проверка, выходит ли хищник за границы арены
    if (left_predator_cor.x < 0 || right_predator_cor.x >= arena.width || left_predator_cor.y < 0 || left_predator_cor.y >= arena.height) {
        if (ans == 1)return -1;
        if (ans == 2)return 1;
    }

    // Если столкновения не произошло, вернуть 0
    return 0;
}

int main() {

    Arena arena(30, 30);
    std::cout << "Choose a side?" << std::endl;
    std::cout << "1 - Predator, 2 - Victim" << std::endl;
    int ans, st, condition = 0;
    std::cin >> ans;
    std::cout << "Choose the predator's step" << std::endl;
    std::cin >> st;
    Point2D left1, right1;
    Point2D left2, right2;

    // Инициализация начальных координат хищника
    left1.x = (arena.width) / 3 + rand() % ((arena.width) / 3);
    left1.y = (arena.height) / 3 + rand() % ((arena.height) / 3);
    right1.x = left1.x + 1;
    right1.y = left1.y;
    Predator predator(left1, right1, rand() % 4, st);

    // Инициализация начальных координат жертвы
    left2.x = (arena.width) / 3 + rand() % ((arena.width) / 3);
    left2.y = (arena.height) / 3 + rand() % ((arena.height) / 3);
    right2.x = left2.x + 1;
    right2.y = left2.y;
    Prey prey(left2, right2, rand() % 8);

    // Убедиться, что жертва и хищник не стартуют слишком близко друг к другу
    while (check(prey, predator, 4, arena, ans) != 0) {
        left2.x = (arena.width) / 3 + rand() % ((arena.width) / 3);
        left2.y = (arena.height) / 3 + rand() % ((arena.height) / 3);
        right2.x = left2.x + 1;
        right2.y = left2.y;
        prey.setCoordinates(left2, right2);
    }

    while (condition == 0) {
        system("cls"); // Очистка экрана

        // Рисование арены
        for (int j = 0; j < arena.width; j++) {
            std::cout << "-";
        }
        std::cout << std::endl;
        for (int i = 0; i < arena.height; i++) {
            for (int j = 0; j < arena.width; j++) {
                if (j == left1.x && i == left1.y)std::cout << "*";
                else if (j == right1.x && i == right1.y)std::cout << "*";
                else if (j == left2.x && i == left2.y)std::cout << "(";
                else if (j == right2.x && i == right2.y)std::cout << ")";
                else std::cout << " ";
            }
            std::cout << "|";
            std::cout << std::endl;
        }
        for (int j = 0; j < arena.width; j++) {
            std::cout << "-";
        }
        std::cout << std::endl;

        // Проверка на столкновение между жертвой и хищником
        condition = check(prey, predator, 1, arena, ans);

        // Обработка ввода с клавиатуры
        if (kbhit()) {
            char c = _getch();
            if (ans == 1) {
                switch (c) {
                    case '0': predator.UpdateDirection(0); break;
                    case '1': predator.UpdateDirection(1); break;
                    case '2': predator.UpdateDirection(2); break;
                    case '3': predator.UpdateDirection(3); break;
                }
            }
            else if (ans == 2) {
                switch (c) {
                    case '0': prey.UpdateDirection(0); break;
                    case '1': prey.UpdateDirection(1); break;
                    case '2': prey.UpdateDirection(2); break;
                    case '3': prey.UpdateDirection(3); break;
                    case '4': prey.UpdateDirection(4); break;
                    case '5': prey.UpdateDirection(5); break;
                    case '6': prey.UpdateDirection(6); break;
                    case '7': prey.UpdateDirection(7); break;
                }
            }
        }


        // Обновление позиции npc
        if (ans == 1) {
            prey.UpdateDirection(rand() % 8);
        }
        else if (ans == 2) {
            int dx = right1.x - right2.x;
            int dy = right1.y - right2.y;
            int dir;

            if (abs(dx) > abs(dy)) {
                if (dx > 0)dir = 3;
                else    dir = 1;
            }
            else {
                if (dy > 0)dir = 0;
                else    dir = 2;
            }
            predator.UpdateDirection(dir);
        }

        prey.UpdateCoordinates();
        predator.UpdateCoordinates();

        std::pair<Point2D, Point2D> prey_cor = prey.getCoordinates();
        std::pair<Point2D, Point2D> predator_cor = predator.getCoordinates();
        left2 = prey_cor.first;
        right2 = prey_cor.second;
        left1 = predator_cor.first;
        right1 = predator_cor.second;
    // Обновление координаат 

        sleep(delay);
    // Задержка до следующего хода
    }

    if(condition==1)std::cout<<"You've won!"<<std::endl;
    if(condition==-1)std::cout<<"You've lost!"<<std::endl;
}

