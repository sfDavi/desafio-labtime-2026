#pragma once

#include <vector>
#include "IObservadorNucleo.h"

/**
 *@brief Subject do Observer.
 *Representa o nucleo de energia.
 */
class NucleoEnergia
{
public:
    /**
     * @param energiaInicial Nivel de energia inicial (0-100).
     * @param limiarCritico Nivel maximo de energia considerado critico.
     */
    explicit NucleoEnergia(float energiaInicial = 100.0f, float limiarCritico = 30.0f);

    /**
     * @brief Registra um novo observador que recebe notificacoes de crises de energia.
     */
    void adicionarObservador(IObservadorNucleo *observador);

    /**
     *@brief Remove um observador.
     */
    void removerObservador(IObservadorNucleo *observador);

    /**
     * @brief Aplica dano ao nucleo reduzindo nivel de energia.
     */
    void tomarDano(float valor);

    /**
     * @brief Reduz nivel de energia.
     */
    void reduzirEnergia(float valor);

    /**
     * @brief Restaura nivel de energia.
     */
    void restaurarEnergia(float valor);

    /**
     * @brief
     *@return Nivel atual de energia.
     */
    float getNivelEnergia() const;

    /**
     * @brief
     * @return true quando o nucleo esta com energia em nivel critico.
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
