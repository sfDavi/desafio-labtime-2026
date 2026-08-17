#pragma once

/**
 * @brief Interface padrao Observer.
 * Reage a mudancas criticas de energia no nucleo da nave.
 *
 */
class IObservadorNucleo
{
public:
    virtual ~IObservadorNucleo() = default;

    /**
     * @brief Chamado por NucleoEnergia quando o nivel de energia atingir valor critico.
     * @param nivelEnergia Nivel de energia do momento de notificacao.
     */
    virtual void onEnergiaCritica(float nivelEnergia) = 0;

    /**
     * @brief Chamado por NucleoEnergia quando o nivel de energia sair de valor critico.
     * @param nivelEnergia Nivel de energia do momento de notificacao.
     */
    virtual void onEnergiaRestaurada(float nivelEnergia) = 0;
};

