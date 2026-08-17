#include "ModificadorArma.h"
#include <utility>

ModificadorArma::ModificadorArma(std::shared_ptr<IArma> armaDecorada) : armaDecorada_(std::move(armaDecorada))
{
}