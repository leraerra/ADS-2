// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}
uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
double calcItem(double x, uint16_t n) {
    if (n == 0) {
        return 1.0;
    }
    return pown(x, n) / static_cast<double>(fact(n));
}
double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        sum += calcItem(x, i);
    }
    return sum;
}
double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        double term = calcItem(x, 2 * i + 1);
        if (i % 2 == 0) {
            sum += term;
        } else {
            sum -= term;
        }
    }
    return sum;
}
double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        double term = calcItem(x, 2 * i);
        if (i % 2 == 0) {
            sum += term;
        } else {
            sum -= term;
        }
    }
    return sum;
}
