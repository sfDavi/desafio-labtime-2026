#include "Nave.h"
#include <iostream>
#include <utility>

void Nave::equiparArma(std::shared_ptr<IArma> arma)
{
    armaAtual_ = std::move(arma);
    std::cout << "[Nave] Arma equipada: " << armaAtual_->getDescricao() << "\n";
}

void Nave::adicionarModificador(const std::function<std::shared_ptr<IArma>(std::shared_ptr<IArma>)> &fabricaModificador)
{
    if (!armaAtual_)
    {
        std::cout << "[Nave] Nenhuma arma equipada (Use 'equipar_arma').\n";
        return;
    }
    armaAtual_ = fabricaModificador(armaAtual_);
    std::cout << "[Nave] Modificador aplicado." << armaAtual_->getDescricao() << "\n";
}

void Nave::atirar() const
{
    if (!armaAtual_)
    {
        std::cout << "[Nave] Nenhuma arma equipada (Use 'equipar_arma').\n";
        return;
    }
    std::cout << "[Nave] Comando de atirar: " << armaAtual_->atirar() << "\n";
}

bool Nave::possuiArma() const
{
    return armaAtual_ != nullptr;
}

std::string Nave::getDescricaoArmaAtual() const
{
    return armaAtual_ ? armaAtual_->getDescricao() : "nenhuma";
}
