#pragma once
#include "IArma.h"

/**
 * @brief Estrategia concreta (Strategy): representa a arma lancadora de misseis.
 */
class Misseis : public IArma
{
public:
    std::string atirar() const override;
    std::string getDescricao() const override;
};