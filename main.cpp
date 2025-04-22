#include "microwave.h"
#include <Windows.h>
#include <iostream>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        // Создание объектов
        Microwave mw1("Samsung", 23.5f, 9999.99f);
        Microwave mw2 = mw1; // Копирование

        // Вывод информации
        std::cout << "Первоначальные данные:\n";
        mw1.print();
        mw2.print();

        // Обновление полей
        std::cout << "\nПосле обновления:\n";
        mw1.setManufacturer("Dexp");
        mw1.setVolume(10.4f);
        mw1.setPrice(3999.00f);
        mw1.print();
        mw2.print();

        // Создание динамических объектов
        Microwave* mw3 = new Microwave("LG", 40.00f, 11129.99f);
        Microwave* mw4 = new Microwave(*mw3); // Копирование

        std::cout << "\nДинамические объекты:\n";
        mw3->print();
        mw4->print();

        // Попытка установить некорректные значения
        try {
            mw3->setManufacturer("Intel");
            mw3->setVolume(1.2f);
            mw3->setPrice(550000.00f);

            std::cout << "\nПосле обновления динамических объектов:\n";
            mw3->print();
            mw4->print();
        }
        catch (const Microwave::InvalidVolume& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
        catch (const Microwave::InvalidPrice& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
        catch (const Microwave::InvalidManufacturer& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }

        // Освобождение памяти
        delete mw3;
        delete mw4;
    }
    catch (const Microwave::InvalidVolume& e) {
        std::cerr << "Ошибка при создании объекта: " << e.what() << std::endl;
    }
    catch (const Microwave::InvalidPrice& e) {
        std::cerr << "Ошибка при создании объекта: " << e.what() << std::endl;
    }
    catch (const Microwave::InvalidManufacturer& e) {
        std::cerr << "Ошибка при создании объекта: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Неизвестная ошибка" << std::endl;
    }

    return 0;
}