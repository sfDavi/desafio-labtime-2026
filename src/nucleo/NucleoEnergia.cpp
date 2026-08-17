#include "NucleoEnergia.h"
#include <algorithm>

NucleoEnergia::NucleoEnergia(float energiaInicial, float limiarCritico)
    : nivelEnergia_(energiaInicial), limiarCritico_(limiarCritico), emCrise_(false) {}

void NucleoEnergia::adicionarObservador(IObservadorNucleo *observador)
{
    observadores_.push_back(observador);
}

void NucleoEnergia::removerObservador(IObservadorNucleo *observador)
{
    observadores_.erase(
        std::remove(observadores_.begin(), observadores_.end(), observador),
        observadores_.end());
}

void NucleoEnergia::tomarDano(float valor)
{
    nivelEnergia_ = std::max(0.0f, nivelEnergia_ - valor);
    avaliarEstado();
}

void NucleoEnergia::reduzirEnergia(float valor)
{
    nivelEnergia_ = std::max(0.0f, nivelEnergia_ - valor);
    avaliarEstado();
}

void NucleoEnergia::restaurarEnergia(float valor)
{
    nivelEnergia_ = std::min(100.0f, nivelEnergia_ + valor);
    avaliarEstado();
}

float NucleoEnergia::getNivelEnergia() const
{
    return nivelEnergia_;
}

bool NucleoEnergia::estaEmCrise() const
{
    return emCrise_;
}

void NucleoEnergia::avaliarEstado()
{
    if (nivelEnergia_ <= limiarCritico_ && !emCrise_)
    {
        emCrise_ = true;
        notificarCrise();
    }
    else if (nivelEnergia_ > limiarCritico_ && emCrise_)
    {
        emCrise_ = false;
        notificarRestauracao();
    }
}

void NucleoEnergia::notificarCrise()
{
    for (auto *observador : observadores_)
    {
        observador->onEnergiaCritica(nivelEnergia_);
    }
}

void NucleoEnergia::notificarRestauracao()
{
    for (auto *observador : observadores_)
    {
        observador->onEnergiaRestaurada(nivelEnergia_);
    }
}
