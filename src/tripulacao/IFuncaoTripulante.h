#pragma once

#include <string>

/**
 * @brief Interface padrao Strategy.
 * Cada funcao concreta tem seus detalhes de como o tripulante deve se comportar.
 */

class IFuncaoTripulante
{
public:
    virtual ~IFuncaoTripulante() = default;
    /**
     * @brief Executa a tarefa da funcao do tripulante
     */
    virtual void executarTarefa(const std::string &nometripulante) const = 0;

    /**
     * @return Nome da funcao do tripulante
     */
    virtual std::string getNomeFuncao() const = 0;
};
