#pragma once

#include <vector>
#include "IObservadorNucleo.h"

/**
 *@brief Subject do Observer.
 *Representa o núcleo de energia.
 */
class NucleoEnergia
{
public:
    /**
     * @param energiaInicial Nível de energia inicial (0-100).
     * @param limiarCritico Nível máximo de energia considerado crítico.
     */
    explicit NucleoEnergia(float energiaInicial = 100.0f, float limiarCritico = 30.0f);

    /**
     * @brief Registra um novo observador que recebe notificações de crises de energia.
     */
    void adicionarObservador(IObservadorNucleo *observador);

    /**
     *@brief Remove um observador.
     */
    void removerObservador(IObservadorNucleo *observador);

    /**
     * @brief Aplica dano ao núcleo reduzindo nível de energia.
     */
    void tomarDano(float valor);

    /**
     * @brief Reduz nível de energia.
     */
    void reduzirEnergia(float valor);

    /**
     * @brief Restaura nível de energia.
     */
    void restaurarEnergia(float valor);

    /**
     * @brief
     *@return Nível atual de energia.
     */
    float getNivelEnergia() const;

    /**
     * @brief
     * @return true quando o núcleo está com energia em nível crítico.
     */
    bool estaEmCrise() const;

private:
    void avaliarEstado();
    void notificarCrise();
    void notificarRestauracao();
    float nivelEnergia_;
    float limiarCritico_;
    bool emCrise_;
    std::vector<IObservadorNucleo *> observadores_;
};
