#include "microwave.h"

void Microwave::validate() const {
    if (manufacturer.empty()) {
        throw InvalidManufacturer();
    }
    if (volume <= 0 || volume > 50) {
        throw InvalidVolume();
    }
    if (price < 0) {
        throw InvalidPrice();
    }
}

Microwave::Microwave() : manufacturer("Default Brand"), volume(20.0f), price(5000.0f) {
    validate();
}

Microwave::Microwave(const std::string& manufacturer, float volume, float price)
    : manufacturer(manufacturer), volume(volume), price(price) {
    validate();
}

std::string Microwave::getManufacturer() const {
    return manufacturer;
}

float Microwave::getVolume() const {
    return volume;
}

float Microwave::getPrice() const {
    return price;
}

void Microwave::setManufacturer(const std::string& manufacturer) {
    this->manufacturer = manufacturer;
    validate();
}

void Microwave::setVolume(float volume) {
    this->volume = volume;
    validate();
}

void Microwave::setPrice(float price) {
    this->price = price;
    validate();
}

void Microwave::print() const {
    std::cout << "Микроволновая печь:\n";
    std::cout << "Производитель: " << manufacturer << "\n";
    std::cout << "Объем: " << volume << " л\n";
    std::cout << "Цена: " << price << " руб.\n";
}