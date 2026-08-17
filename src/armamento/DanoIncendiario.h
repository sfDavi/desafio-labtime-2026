#pragma once

#include "ModificadorArma.h"

/**
 * @brief Decorador concreto (Decorator)): adiciona efeito de dano de fogo.
 */
class DanoIncendiario : public ModificadorArma
{
public:
    explicit DanoIncendiario(std::shared_ptr<IArma> armaDecorada);
    std::string atirar() const override;
    std::string getDescricao() const override;
};
