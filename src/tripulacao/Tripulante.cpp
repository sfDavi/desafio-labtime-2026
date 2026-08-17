#include "Tripulante.h"
#include <utility>

Tripulante::Tripulante(std::string nome, std::shared_ptr<IFuncaoTripulante> funcaoInicial)
    : nome_(std::move(nome)), funcaoAtual_(std::move(funcaoInicial)) {}

void Tripulante::setFuncao(std::shared_ptr<IFuncaoTripulante> novaFuncao)
{
    funcaoAtual_ = std::move(novaFuncao);
}

void Tripulante::trabalhar() const
{
    funcaoAtual_->executarTarefa(nome_);
}

const std::string &Tripulante::getNome() const
{
    return nome_;
}

std::string Tripulante::getFuncao() const
{
    return funcaoAtual_->getNomeFuncao();
}
