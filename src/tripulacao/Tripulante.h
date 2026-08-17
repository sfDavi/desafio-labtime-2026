#pragma once
#include <memory>
#include <string>
#include "IFuncaoTripulante.h"

/**
 * @brief Representa um NPC tripulante.
 * A "estratégia" da função pode ser trocada em tempo real com setFuncao() sem precisar destruir ou recriar o tripulante.
 * A classe não conhece cada função concreta que o tripulante pode exercer, podem ser adicionadas novas funções ao código sem alterar esta classe. 
 */
class Tripulante
{
public:
    Tripulante(std::string nome, std::shared_ptr<IFuncaoTripulante> funcaoInicial);

    /**
     * @brief Altera a função do tripulante (padrão strategy).
     */
    void setFuncao(std::shared_ptr<IFuncaoTripulante> novaFuncao);

    /**
     * @brief Chama a execução de tarefa do tripulante presente na estratégia da função atual.
     */
    void trabalhar() const;

    const std::string &getNome() const;

    std::string getFuncao() const;

private:
    std::string nome_;
    std::shared_ptr<IFuncaoTripulante> funcaoAtual_;
};
