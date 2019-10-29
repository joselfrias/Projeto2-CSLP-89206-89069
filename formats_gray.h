/** @file formats_gray.h
 *  @brief Cabeçalhos de funções para aplicação em imagens com formato Grayscale.
 *
 *  Contém os headers das funções necessárias para a manipulação de imagens Grayscale,
 *  definindo nomes das funções bem como os seus argumentos.
 */

#ifndef _FORMATS_GRAY_H
#define _FORMATS_GRAY_H
#include "formats_bin.h"
#include "formats_rgb.h"

/**
 * @brief Estrutura para representar a componente grayscale existente num pixel de uma imagem Grayscale.
 *
 * Dada uma imagem Grayscale, cada pixel é influenciado só por uma componente,
 * podendo assumir esta um valor entre 0 e 255, sendo então representada por um unsigned
 * char, que também assume um conjunto de valores possíveis igual ao descrito anteriormente.
 */
typedef struct {
  unsigned char gray; /**< Componente para representar cada pixel de uma imagem em Grayscale. */

}GRAY_PIXEL;

/**
 * @brief Estrutura para representar uma imagem em Grayscale.

 * Esta estrutura permite a representação de uma imagem em Grayscale, que é caracterizada por um conjunto
 * de pixeis GRAY_PIXEL, definidos anteriormente, pelo número de elementos da matriz Grayscale, por um número de linhas
 * e colunas e consequentemente por um tamanho.
 */
typedef struct {
  GRAY_PIXEL *data; /**<Representação dos valores da matriz Grayscale */
  int n; /**<Número de elementos da matriz Grayscale. */
  int size; /**<Tamanho da matriz Grayscale. */
  int h; /**<Número de linhas da matriz. */
  int w; /**<Número de colunas da matriz. */

}GRAY_IMAGE;

/*
* Função que cria uma imagem em GRAYSCALE
* @param height Numero de linhas da imagem.
* @param width Numero de colunas da imagem.
* @return tmp Retorna uma estrutura GRAY_IMAGE.
*/
GRAY_IMAGE * CreateImageGRAY(int height, int width);

/*
* Função que converte uma imagem RGB para uma em Grayscale.
* @param img Imagem RGB que se quer converter.
* @return tmp Imagem Grayscale que se quer obter.
*/
GRAY_IMAGE * convertToGray(RGB_IMAGE *);
/*
* Função que converte uma imagem RGB para uma em grayscale de acordo
* com o channel pretendido.
* @param img RGB_IMAGE que se quer converter.
* @param channel Channel que se quer obter na imagem grayscale.
* @return tmp Imagem em grayscale de acordo com a imagem rgb e o channel pretendido.
*/
GRAY_IMAGE * convertToChannel(RGB_IMAGE *, char *);

/*
* Função que carrega de um ficheiro que contém uma Imagem GRAYSCALE
* para uma estrutura GRAY_IMAGE.
* @param nome Nome do ficheiro da imagem pretendida.
* @return img Retorna uma nova estrutura GRAY_IMAGE.
*/
GRAY_IMAGE * LoadFromFileGRAY(char *nome);

/*
*Função que guarda uma Gray_Image num ficheiro.
* @param img GRAY_IMAGE que se quer guardar.
* @param nome Nome do ficheiro onde a imagem será guardada.
* @return Nothing
*/
void saveOnFileGRAY(GRAY_IMAGE *, char *nome );

/*
*Função que acede a um pixel numa imagem Grayscale.
* @param img Imagem em grayscale a que se pretende aceder.
* @param pix_h Linha do pixel a que se pretende obter.
* @param pix_w Coluna do pixel a que se pretende aceder.
* @return Nothing.
*/
void AccessPixelGRAY(GRAY_IMAGE *, int pix_h, int pix_w);

/* Função que altera a intensidade da componente grayscale
* de uma imagem, retornando uma nova imagem.
* @param img GRAY_IMAGE que se pretende alterar.
* @param intensity Valor a alterar na componente grayscale de cada pixel.
* @return GRAY_IMAGE Retorna uma imagem grayscale com as alterações de intensidade.
*/
GRAY_IMAGE * change_intensityGRAY(GRAY_IMAGE *, int intensity);

GRAY_IMAGE * access_regionGRAY(GRAY_IMAGE *img, int pix_h_start, int pix_w_start, int pix_h_end, int pix_w_end);

GRAY_IMAGE * applyWatermarkGRAY(GRAY_IMAGE *, GRAY_IMAGE *,int pix_h_start, int pix_w_start,int  pix_h_end, int pix_w_end);

#endif //_FORMATS_GRAY_H
