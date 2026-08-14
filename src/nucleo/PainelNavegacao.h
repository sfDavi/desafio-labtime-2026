#pragma once

#include "IObservadorNucleo.h"

/**
 * @brief Observer concreto. 
 * Exibe ou remove alertas nos paineis.
 */
class PainelNavegacao : public IObservadorNucleo
{
public:
    void onEnergiaCritica(float nivelEnergia) override;
    void onEnergiaRestaurada(float nivelEnergia) override;

private:
    bool alertaAtivo_ = false;
};
