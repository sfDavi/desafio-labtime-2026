#include "OperadorArmas.h"
#include <iostream>

void OperadorArmas::executarTarefa(const std::string &nomeTripulante) const 
{
    std::cout << nomeTripulante << "[Operador de Armas] Calibra a mira e recarrega as armas da nave.\n";
}

std::string OperadorArmas::getNomeFuncao() const
{
    return "Operador de Armas";
}
