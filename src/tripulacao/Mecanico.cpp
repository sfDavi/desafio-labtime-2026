#include "Mecanico.h"
#include <iostream>

void Mecanico::executarTarefa(const std::string &nomeTripulante) const 
{
    std::cout << nomeTripulante << "[Mecanico] Realiza reparos no motor.\n";
}

std::string Mecanico::getNomeFuncao() const
{
    return "Mecanico";
}
