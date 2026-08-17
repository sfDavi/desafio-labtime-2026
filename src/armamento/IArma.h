#pragma once
#include <string>

/**
 * @brief Interface para armas (Strategy) e modificadores (Decorator).
 * Classes de armas concretas e modificadores implementam esta interface permitindo combinacoes no metodo atirar().
 *
 */
class IArma
{
public:
    virtual ~IArma() = default;

    /**
     * @brief Atira a arma atual
     */
    virtual std::string atirar() const = 0;

    /**
     * @brief Descreve a configuracao da arma atual
     */
    virtual std::string getDescricao() const = 0;
};