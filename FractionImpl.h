//
// Created by gaeta on 01.04.2020.
//

#ifndef INF2_LABO4_FRACTIONIMPL_H
#define INF2_LABO4_FRACTIONIMPL_H

#include "Fraction.h"

template <typename T>
Fraction<T> Fraction<T>::simplify(Fraction<T> fraction) {
    T A = fraction.nominator;
    T B = fraction.denominator;
    T R = A%B;

    // algoritme pour la simplification
    while (R != 0) {
        A = B;
        B = R;
        R = A%B;
    }

    return Fraction<T>(A, B);
}

template <typename T> bool Fraction<T>::identity(Fraction<T> fraction) {
    return this->nominator == fraction.nominator && this->denominator == fraction.denominator;
}

template <typename T> std::ostream& operator<<(std::ostream& os, const Fraction<T>& fra) {
    return os << fra.nominator << "/" << fra.denominator;
}

template<typename T> Fraction<T>::operator float() const {
    return float(this->nominator) / float(this->denominator);
}

template <typename T> Fraction<T> Fraction<T>::operator+=(const Fraction<T> &rhs) {
    auto nomi1 = this->nominator;
    auto deno1 = this->denominator;
    auto nomi2 = rhs.nominator;
    auto deno2 = rhs.denominator;

    // algorithme pour trouver le pgdc des deux denominateur
    while (deno1 != deno2) {
        while (deno1 > deno2) deno2 = deno2 + rhs.denominator;
        while (deno1 < deno2) deno1 = deno1 + this->denominator;
    }
    // multiplication des nominateurs par la division du nouveau denominateur
    nomi1 *= deno1 / this->denominator;
    nomi2 *= deno2 / rhs.denominator;

    this->nominator = nomi1 + nomi2;
    this->denominator = deno1;

    return *this;
}
template <typename T> Fraction<T> operator+(Fraction<T> &lhs, const Fraction<T> &rhs) {
    lhs += rhs;
    return lhs;
}
template <typename T> Fraction<T> Fraction<T>::operator*=(const Fraction<T>& rhs) {
    this->nominator *= rhs.nominator;
    this->denominator *= rhs.denominator;
    return *this;
}
template <typename T> Fraction<T> operator*(Fraction<T> &lhs, const Fraction<T> &rhs) {
    lhs *= rhs;
    return lhs;
}

#endif //INF2_LABO4_FRACTIONIMPL_H
