#include "DanoPerfurante.h"

DanoPerfurante::DanoPerfurante(std::shared_ptr<IArma> armaDecorada) : ModificadorArma(std::move(armaDecorada))
{
}

std::string DanoPerfurante::atirar() const
{
    return armaDecorada_->atirar() + "+ DANO PERFURA BLINDAGEM";
}

std::string DanoPerfurante::getDescricao() const
{
    return armaDecorada_->getDescricao() + " + Perfuração de Blindagem";
}
