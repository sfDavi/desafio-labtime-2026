#include "SistemaEscudos.h"
#include <iostream>

void SistemaEscudos::onEnergiaCritica(float nivelEnergia)
{
    focoAtual_ = "defesa focada ao nucleo";
    std::cout<< "[Sistema de Escudos] Energia em nivel critico ("<< nivelEnergia <<")! Sistema de escudos alterado para: "<< focoAtual_ <<"/n";
}

void SistemaEscudos::onEnergiaRestaurada(float nivelEnergia)
{
    focoAtual_ = "defesa padrao";
    std::cout<< "[Sistema de Escudos] Energia restaurada ("<< nivelEnergia <<"), sistema de escudos alterado para: "<< focoAtual_ <<"/n";
}
