#pragma once
#include "IArma.h"

/**
 * @brief Estrategia concreta (Strategy): representa a arma a laser.
 */
class Laser : public IArma
{
public:
    std::string atirar() const override;
    std::string getDescricao() const override;
};