#include "SistemaLuzes.h"
#include <iostream>

void SistemaLuzes::onEnergiaCritica(float nivelEnergia)
{
    acesas_ = false;
    std::cout << "[Sistema de Luzes] Energia em nível crítico (" << nivelEnergia << ")! Apagando as luzes.";
}

void SistemaLuzes::onEnergiaRestaurada(float nivelEnergia)
{
    acesas_ = false;
    std::cout << "[Sistema de Luzes] Energia restaurada (" << nivelEnergia << "), retornando as luzes.";
}
