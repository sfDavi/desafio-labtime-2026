#pragma once
#include <memory>
#include <string>
#include "IFuncaoTripulante.h"

/**
 * @brief Representa um NPC tripulante.
 * A "estrategia" da funcao pode ser trocada em tempo real com setFuncao() sem precisar destruir ou recriar o tripulante.
 * A classe nao conhece cada funcao concreta que o tripulante pode exercer, podem ser adicionadas novas funcoes ao codigo sem alterar esta classe. 
 */
class Tripulante
{
public:
    Tripulante(std::string nome, std::shared_ptr<IFuncaoTripulante> funcaoInicial);

    /**
     * @brief Altera a funcao do tripulante (padrao strategy).
     */
    void setFuncao(std::shared_ptr<IFuncaoTripulante> novaFuncao);

    /**
     * @brief Chama a execucao de tarefa do tripulante presente na estrategia da funcao atual.
     */
    void trabalhar() const;

    const std::string &getNome() const;

    std::string getFuncao() const;

private:
    std::string nome_;
    std::shared_ptr<IFuncaoTripulante> funcaoAtual_;
};
