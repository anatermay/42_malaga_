/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:13:57 by aternero          #+#    #+#             */
/*   Updated: 2026/04/22 19:15:52 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Data* original = new Data();
    original->name = "TestData";

    std::cout << "=== Prueba de Serialización/Deserialización ===" << std::endl;
    std::cout << "Original Data* : " << original << std::endl;
    std::cout << "Nombre original: " << original->name << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "Serializado (uintptr_t): " << serialized << std::endl;
    std::cout << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserializado Data*: " << deserialized << std::endl;
    std::cout << "Nombre deserializado: " << deserialized->name << std::endl;
    std::cout << std::endl;

    if (original == deserialized)
    {
        std::cout << "EXITO: Los punteros son iguales!" << std::endl;
        std::cout << "original == deserialized: " << (original == deserialized) << std::endl;
    }
    else
    {
        std::cout << "FALLO: Los punteros son diferentes!" << std::endl;
    }

    delete original;
    
    std::cout << std::endl << "=== Fin de la prueba ===" << std::endl;
    return (0);
}
