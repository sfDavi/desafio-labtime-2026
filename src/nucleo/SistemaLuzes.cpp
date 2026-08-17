#include "SistemaLuzes.h"
#include <iostream>

void SistemaLuzes::onEnergiaCritica(float nivelEnergia)
{
    acesas_ = false;
    std::cout << "[Sistema de Luzes] Energia em nivel critico (" << nivelEnergia << ")! Apagando as luzes.\n";
}

void SistemaLuzes::onEnergiaRestaurada(float nivelEnergia)
{
    acesas_ = false;
    std::cout << "[Sistema de Luzes] Energia restaurada (" << nivelEnergia << "), retornando as luzes.\n";
}
