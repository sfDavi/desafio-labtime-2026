#pragma once
#include <memory>
#include "IArma.h"

/**
 * @brief Decorador abstrato (Decorator).
 * Decora uma IArma, aplicando um efeito de modificador para a arma sem precisar criar uma classe nova para cada combinação possível de arma + modificador.
 */
class ModificadorArma : public IArma
{
public:
    explicit ModificadorArma(std::shared_ptr<IArma> armaDecorada);
    ~ModificadorArma() override = default;

protected:
    std::shared_ptr<IArma> armaDecorada_;
};
