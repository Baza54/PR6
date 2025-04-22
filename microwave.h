#ifndef MICROWAVE_H
#define MICROWAVE_H

#include <string>
#include <stdexcept>
#include <iostream>

class Microwave {
private:
    std::string manufacturer; // Название фирмы
    float volume;             // Объем (литры)
    float price;             // Цена (рубли)

    void validate() const;

public:
    // Исключения
    class InvalidVolume : public std::invalid_argument {
    public:
        InvalidVolume() : std::invalid_argument("Неверный объем. Допустимый диапазон: 0 < volume ≤ 50") {}
    };

    class InvalidPrice : public std::invalid_argument {
    public:
        InvalidPrice() : std::invalid_argument("Цена не может быть отрицательной") {}
    };

    class InvalidManufacturer : public std::invalid_argument {
    public:
        InvalidManufacturer() : std::invalid_argument("Производитель не может быть пустым") {}
    };

    // Конструкторы
    Microwave();
    Microwave(const std::string& manufacturer, float volume, float price);

    // Методы доступа
    std::string getManufacturer() const;
    float getVolume() const;
    float getPrice() const;

    // Методы изменения
    void setManufacturer(const std::string& manufacturer);
    void setVolume(float volume);
    void setPrice(float price);

    // Другие методы
    void print() const;
};

#endif