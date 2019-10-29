/** @file formats_bin.h
 *  @brief Cabeçalhos de funções para aplicação em imagens em formato binário.
 *
 *  Contém os headers das funções necessárias para a manipulação de imagens binárias,
 *  definindo nomes das funções bem como os seus argumentos.
 */

#ifndef _FORMATS_BIN_H
#define _FORMATS_BIN_H
#include "formats_gray.h"
#include "formats_rgb.h"

/**
 * @brief Estrutura para representar a componente binária existente num pixel de uma imagem binária.
 *
 * Dada uma imagem binária, cada pixel só pode assumir um valor de dois possíveis: 0 ou 1.
 * No entanto, foi usado um unsigned char para representar cada pixel,
 * o que não se torna muito eficiente.
 */
typedef struct {
  unsigned char bit;/**< Componente para representar cada pixel de uma imagem em binário. */

}BIN_PIXEL;

/**
 * @brief Estrutura para representar uma imagem em binário.

 * Esta estrutura permite a representação de uma imagem em binário, que é caracterizada por um conjunto
 * de pixeis BIN_PIXEL, definidos anteriormente, pelo número de elementos da matriz binária, por um número de linhas
 * e colunas e consequentemente por um tamanho.
 */
typedef struct {
  BIN_PIXEL *data;  /**<Representação dos valores da matriz binária */
  int n; /**<Número de elementos da matriz binária. */
  int size; /**<Tamanho da matriz binária. */
  int h; /**<Número de linhas da matriz. */
  int w; /**<Número de colunas da matriz. */

}BIN_IMAGE;

/*
* Função que cria uma imagem em binario
* @param height Numero de linhas da imagem.
* @param width Numero de colunas da imagem.
* @return tmp Retorna uma estrutura BIN_IMAGE.
*/
BIN_IMAGE * CreateImageBIN(int height, int width);

void AppendBIN( BIN_IMAGE *, BIN_PIXEL pix);
void AccessPixelBIN(BIN_IMAGE *, int pix_h, int pix_w);

/*
* Função que carrega de um ficheiro que contém uma Imagem EM Grayscale
* para uma estrutura BIN_IMAGE.
* @param nome Nome do ficheiro da imagem pretendida.
* @return img Retorna uma nova estrutura BIN_IMAGE.
*/
BIN_IMAGE * LoadFromGrayFile(char *, int threshold);

/*
* Função que carrega de um ficheiro que contém uma Imagem EM BINARIO
* para uma estrutura BIN_IMAGE.
* @param nome Nome do ficheiro da imagem pretendida.
* @return img Retorna uma nova estrutura BIN_IMAGE.
*/
BIN_IMAGE * LoadFromBinFile(char *);
/*
*Função que guarda uma BIN_Image num ficheiro.
* @param img BIN_IMAGE que se quer guardar.
* @param nome Nome do ficheiro onde a imagem será guardada.
* @return Nothing
*/
void saveOnFileBIN(BIN_IMAGE *, char *nome );

#endif //_FORMATS_BIN_H
