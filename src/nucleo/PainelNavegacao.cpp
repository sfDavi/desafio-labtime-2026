#include <iostream>
#include "PainelNavegacao.h"

void PainelNavegacao::onEnergiaCritica(float nivelEnergia)
{
    alertaAtivo_ = true;
    std::cout << "[Painel de Navegacao] Alerta! Energia em nivel critico (" << nivelEnergia << ").\n";
}

void PainelNavegacao::onEnergiaRestaurada(float nivelEnergia)
{
    alertaAtivo_ = false;
    std::cout << "[Painel de Navegacao] Energia restaurada (" << nivelEnergia << ").\n";
}
