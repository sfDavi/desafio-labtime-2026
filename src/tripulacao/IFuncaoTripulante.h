#pragma once

#include <string>

/**
 * @brief Interface padrão Strategy.
 * Cada função concreta tem seus detalhes de como o tripulante deve se comportar.
 */

class IFuncaoTripulante
{
public:
    virtual ~IFuncaoTripulante() = default;
    /**
     * @brief Executa a tarefa da função do tripulante
     */
    virtual void executarTarefa(const std::string &nometripulante) const = 0;

    /**
     * @return Nome da função do tripulante
     */
    virtual std::string getNomeFuncao() const = 0;
};
