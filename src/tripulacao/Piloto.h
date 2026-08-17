#pragma once

#include "IFuncaoTripulante.h"

/**
 * @brief Classe concreta da Strategy.
 *  Comportamento do tripulante com funcao Piloto.
 */
class Piloto : public IFuncaoTripulante
{
public:
    void executarTarefa(const std::string &nomeTripulante) const override;
    std::string getNomeFuncao() const override;
};
