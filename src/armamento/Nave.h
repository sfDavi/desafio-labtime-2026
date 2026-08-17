#pragma once
#include <memory>
#include <string>
#include <functional>
#include "IArma.h"

/**
 * @brief Representa a nave, armazena status de armamento e emite o comando de atirar.
 *
 * A Nave so conhece a interface IArma e emite um comando generico
 * atirar(). Nao conhece a arma atual ou seus modificadores (Decorators).
 */
class Nave
{
public:
    /**
     * @brief Altera a arma atual por uma nova arma.
     */
    void equiparArma(std::shared_ptr<IArma> arma);

    /**
     * @brief Utiliza o padrao decorator para adicionar um modificador na arma.
     * @param fabricaModificador funcao que recebe a arma atual e devolve a arma decorada.
     */
    void adicionarModificador(const std::function<std::shared_ptr<IArma>(std::shared_ptr<IArma>)> &fabricaModificador);

    /**
     * @brief Executa o comando de disparar a arma.
     */
    void atirar() const;

    bool possuiArma() const;

    std::string getDescricaoArmaAtual() const;

private:
    std::shared_ptr<IArma> armaAtual_;
};