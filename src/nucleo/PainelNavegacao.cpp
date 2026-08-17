#include <iostream>
#include "PainelNavegacao.h"

void PainelNavegacao::onEnergiaCritica(float nivelEnergia)
{
    alertaAtivo_ = true;
    std::cout << "[Alerta!] Energia em nivel critico (" << nivelEnergia << ").\n";
}

void PainelNavegacao::onEnergiaRestaurada(float nivelEnergia)
{
    alertaAtivo_ = false;
    std::cout << "Energia restaurada (" << nivelEnergia << ").\n";
}
