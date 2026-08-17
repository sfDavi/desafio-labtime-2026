#pragma once

#include "ModificadorArma.h"

/**
 * @brief Decorador concreto (Decorator)): adiciona efeito de perfuracao de blindagem.
 */
class DanoPerfurante : public ModificadorArma
{
public:
    explicit DanoPerfurante(std::shared_ptr<IArma> armaDecorada);
    std::string atirar() const override;
    std::string getDescricao() const override;
};