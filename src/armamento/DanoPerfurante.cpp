#include "DanoPerfurante.h"

PerfuracaoBLindagem::PerfuracaoBLindagem(std::shared_ptr<IArma> armaDecorada) : ModificadorArma(std::move(armaDecorada))
{
}

std::string PerfuracaoBLindagem::atirar() const
{
    return armaDecorada_->atirar() + "+ DANO PERFURA BLINDAGEM";
}

std::string PerfuracaoBLindagem::getDescricao() const
{
    return armaDecorada_->getDescricao() + " + Perfuração de Blindagem";
}
