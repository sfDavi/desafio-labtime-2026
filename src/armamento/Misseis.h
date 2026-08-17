#pragma once
#include "IArma.h"

/**
 * @brief Estrategia concreta (Strategy): representa a arma lançadora de mísseis.
 */
class Misseis : public IArma
{
public:
    std::string atirar() const override;
    std::string getDescricao() const override;
};