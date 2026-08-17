/**
 * @file main.cpp
 * @brief Loop interativo no console. Utilizado para testar os sistemas da nave.
 * O programa fica lendo comandos digitados pelo usuario e reage em tempo real com os objetos criados a partir de padroes de projeto.
 * 
 */


#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

#include "nucleo/NucleoEnergia.h"
#include "nucleo/PainelNavegacao.h"
#include "nucleo/SistemaEscudos.h"
#include "nucleo/SistemaLuzes.h"

#include "tripulacao/IFuncaoTripulante.h"
#include "tripulacao/Mecanico.h"
#include "tripulacao/OperadorArmas.h"
#include "tripulacao/Piloto.h"
#include "tripulacao/Tripulante.h"

#include "armamento/Nave.h"
#include "armamento/DanoIncendiario.h"
#include "armamento/DanoPerfurante.h"
#include "armamento/Laser.h"
#include "armamento/Misseis.h"

namespace
{

    /**
     * @brief Imprime a lista de comandos no console.
     */
    void imprimirAjuda()
    {
        std::cout << "\nComandos disponiveis:\n"
                     "tomar_dano <valor>              -- dano aplicado ao nucleo\n"
                     "reduzir_energia <valor>         -- consumo de energia do nucleo\n"
                     "restaurar_energia <valor>       -- restaura energia do nucleo\n"
                     "status_nucleo                   -- mostra nivel de energia e estado\n"
                     "listar_tripulantes              -- lista tripulantes e funcoes\n"
                     "trocar_funcao <nome> <funcao>   -- funcao: operador | mecanico | piloto\n"
                     "trabalhar <nome>                -- executa a tarefa da funcao atual\n"
                     "equipar_arma <tipo>             -- tipo: laser | misseis\n"
                     "adicionar_modificador <tipo>    -- tipo: incendiario | perfurante\n"
                     "atirar                          -- dispara a arma atual\n"
                     "ajuda                           -- mostra lista de comandos\n"
                     "sair                            -- encerra o programa\n\n";
    }

    /**
     * @brief Busca um tripulante pelo nome (nullptr se nao encontrado).
     */
    Tripulante *encontrarTripulante(std::vector<Tripulante> &tripulacao, const std::string &nome)
    {
        for (auto &t : tripulacao)
        {
            if (t.getNome() == nome)
                return &t;
        }
        return nullptr;
    }

    /**
     * @brief Fabrica a estrategia concreta correspondente a chave digitada.
     */
    std::shared_ptr<IFuncaoTripulante> criarFuncaoPorNome(const std::string &chave)
    {
        if (chave == "operador")
            return std::make_shared<OperadorArmas>();
        if (chave == "mecanico")
            return std::make_shared<Mecanico>();
        if (chave == "piloto")
            return std::make_shared<Piloto>();
        return nullptr;
    }

}

int main()
{
    // ---------- Nucleo de Energia + Observers ----------
    NucleoEnergia nucleo(100.0f, 30.0f);
    SistemaEscudos escudos;
    SistemaLuzes luzes;
    PainelNavegacao painel;

    nucleo.adicionarObservador(&escudos);
    nucleo.adicionarObservador(&luzes);
    nucleo.adicionarObservador(&painel);

    // ---------- Tripulacao (Strategy) ----------
    std::vector<Tripulante> tripulacao;
    tripulacao.emplace_back("Pedro", std::make_shared<OperadorArmas>());
    tripulacao.emplace_back("Mario", std::make_shared<Mecanico>());
    tripulacao.emplace_back("Carol", std::make_shared<Piloto>());

    // ---------- Armamento (Strategy + Decorator) ----------
    Nave nave;

    std::cout << "=== Simulador de Contingencia da Nave ===\n\n";
    std::cout << "Nucleo inicia com 100 de energia (limiar critico: 30).\n";
    std::cout << "Tripulantes iniciais: Pedro (operador), Mario (mecanico), Carol (piloto).\n";
    std::cout << "Digite 'ajuda' para ver os comandos disponiveis.\n";

    std::string linha;
    std::cout << "\n> ";
    while (std::getline(std::cin, linha))
    {
        std::istringstream iss(linha);
        std::string comando;
        iss >> comando;

        if (comando.empty())
        {
            std::cout << "> ";
            continue;
        }
        else if (comando == "ajuda")
        {
            imprimirAjuda();
        }
        else if (comando == "sair")
        {
            std::cout << "Encerrando simulador.\n";
            break;
        }
        else if (comando == "tomar_dano" || comando == "reduzir_energia" || comando == "restaurar_energia")
        {
            float valor;
            if (!(iss >> valor))
            {
                std::cout << "Uso: " << comando << " <valor>\n";
            }
            else
            {
                if (comando == "tomar_dano")
                    nucleo.tomarDano(valor);
                else if (comando == "reduzir_energia")
                    nucleo.reduzirEnergia(valor);
                else
                    nucleo.restaurarEnergia(valor);

                std::cout << "[Nucleo] Energia atual: " << nucleo.getNivelEnergia()
                          << (nucleo.estaEmCrise() ? " (EM CRISE)" : " (estavel)") << "\n";
            }
        }
        else if (comando == "status_nucleo")
        {
            std::cout << "[Nucleo] Energia atual: " << nucleo.getNivelEnergia()
                      << (nucleo.estaEmCrise() ? " (EM CRISE)" : " (estavel)") << "\n";
        }
        else if (comando == "listar_tripulantes")
        {
            for (auto &t : tripulacao)
            {
                std::cout << "  - " << t.getNome() << " : " << t.getFuncao() << "\n";
            }
        }
        else if (comando == "trocar_funcao")
        {
            std::string nome, funcao;
            iss >> nome >> funcao;
            Tripulante *t = encontrarTripulante(tripulacao, nome);
            auto novaFuncao = criarFuncaoPorNome(funcao);
            if (!t)
            {
                std::cout << "Tripulante '" << nome << "' nao encontrado. Use 'listar_tripulantes'.\n";
            }
            else if (!novaFuncao)
            {
                std::cout << "Funcao invalida. Use: operador | mecanico | piloto\n";
            }
            else
            {
                t->setFuncao(novaFuncao);
                std::cout << t->getNome() << " agora e: " << t->getFuncao() << "\n";
            }
        }
        else if (comando == "trabalhar")
        {
            std::string nome;
            iss >> nome;
            Tripulante *t = encontrarTripulante(tripulacao, nome);
            if (!t)
            {
                std::cout << "Tripulante '" << nome << "' nao encontrado. Use 'listar_tripulantes'.\n";
            }
            else
            {
                t->trabalhar();
            }
        }
        else if (comando == "equipar_arma")
        {
            std::string tipo;
            iss >> tipo;
            if (tipo == "laser")
                nave.equiparArma(std::make_shared<Laser>());
            else if (tipo == "misseis")
                nave.equiparArma(std::make_shared<Misseis>());
            else
                std::cout << "Arma invalida. Use: laser | misseis\n";
        }
        else if (comando == "adicionar_modificador")
        {
            std::string tipo;
            iss >> tipo;
            if (tipo == "incendiario")
            {
                nave.adicionarModificador([](std::shared_ptr<IArma> arma)
                                          { return std::make_shared<DanoIncendiario>(arma); });
            }
            else if (tipo == "perfurante")
            {
                nave.adicionarModificador([](std::shared_ptr<IArma> arma)
                                          { return std::make_shared<DanoPerfurante>(arma); });
            }
            else
            {
                std::cout << "Modificador invalido. Use: incendiario | perfurante\n";
            }
        }
        else if (comando == "atirar")
        {
            nave.atirar();
        }
        else
        {
            std::cout << "Comando desconhecido: '" << comando << "'. Digite 'ajuda' para ver a lista.\n";
        }

        std::cout << "\n> ";
    }

    return 0;
}
