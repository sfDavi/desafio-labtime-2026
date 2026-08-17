#include "Mecanico.h"
#include <iostream>

void Mecanico::executarTarefa(const std::string &nomeTripulante) const 
{
    std::cout << nomeTripulante << "[Mecânico] Realiza reparos no motor.\n";
}

std::string Mecanico::getNomeFuncao() const
{
    return "Mecânico";
}
