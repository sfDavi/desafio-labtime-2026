#pragma once

#include "IObservadorNucleo.h"

/**
 * @brief Observer concreto. 
 * Administra o apagamento de luzes com em niveis criticos de energia.
 */
class SistemaLuzes : public IObservadorNucleo
{
public:
    void onEnergiaCritica(float nivelEnergia) override;
    void onEnergiaRestaurada(float nivelEnergia) override;

private:
    bool acesas_ = true;
};
