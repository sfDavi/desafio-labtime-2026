#pragma once

/**
 * @brief Interface padrão Observer.
 * Reage a mudanças críticas de energia no nucleo da nave.
 *
 */
class IObservadorNucleo
{
public:
    virtual ~IObservadorNucleo() = default;

    /**
     * @brief Chamado por NucleoEnergia quando o nivel de energia atingir valor crítico.
     * @param nivelEnergia Nível de energia do momento de notificação.
     */
    virtual void onEnergiaCritica(float nivelEnergia) = 0;

    /**
     * @brief Chamado por NucleoEnergia quando o nivel de energia sair de valor crítico.
     * @param nivelEnergia Nível de energia do momento de notificação.
     */
    virtual void onEnergiaRestaurada(float nivelEnergia) = 0;
};

