#include "DanoIncendiario.h"
#include <utility>

DanoIncendiario::DanoIncendiario(std::shared_ptr<IArma> armaDecorada) : ModificadorArma(std::move(armaDecorada))
{
}

std::string DanoIncendiario::atirar() const
{
    return armaDecorada_->atirar() + "+ DANO DE FOGO";
}

std::string DanoIncendiario::getDescricao() const
{
    return armaDecorada_->getDescricao() + " + Dano de fogo";
}
