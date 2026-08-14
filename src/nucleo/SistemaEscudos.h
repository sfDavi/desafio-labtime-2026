#pragma once

#include <string>
#include "IObservadorNucleo.h"

/**
 *@brief Observer concreto. 
 * Administra o foco de defesa dos escudos.
 */
class SistemaEscudos : public IObservadorNucleo
{
public:
    void onEnergiaCritica(float nivelEnergia) override;
    void onEnergiaRestaurada(float nivelEnergia) override;

private:
    std::string focoAtual_ = "defesa padrão";
};
