#include "Piloto.h"
#include <iostream>

void Piloto::executarTarefa(const std::string &nomeTripulante) const 
{
    std::cout << nomeTripulante << "[Piloto] assume o controle da direção da nave.\n";
}

std::string Piloto::getNomeFuncao() const
{
    return "Piloto";
}
