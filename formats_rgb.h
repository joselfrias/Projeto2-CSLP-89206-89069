/** @file formats_rgb.h
 *  @brief Cabeçalhos de funções para aplicação em imagens com formato RGB.
 *
 *  Contém os headers das funções necessárias para a manipulação de imagens RGB,
 *  definindo nomes das funções bem como os seus argumentos.
 */

#ifndef _FORMATS_RGB_H
#define _FORMATS_RGB_H
#include "formats_bin.h"
#include "formats_gray.h"

/**
 * @brief Estrutura para representar cada componente existente num pixel de uma imagem RGB.
 *
 * Dada uma imagem RGB, cada pixel é influenciado pela conjunção de três componentes ou cores,
 * sendo estas vermelho, verde e azul. Esta estrutura define então estas características,
 * através do uso de unsigned char 's para as três componentes, visto que cada componente pode assumir
 * um conjunto de valores entre 0 e 255.
 */
typedef struct {
	unsigned char r; /**< Componente vermelha de cada pixel de uma imagem RGB. */
	unsigned char g; /**< Componente verde de cada pixel de uma imagem RGB. */
	unsigned char b; /**< Componente azul de cada pixel de uma imagem RGB. */
} RGB_PIXEL;

/**
 * @brief Estrura para representar uma Imagem RGB.
 *
 * Esta estrutura irá possibilitar a representação de uma imagem RGB, que será caracterizada
 * por um conjunto de estruturas RGB_PIXEL, pelo número de linhas e colunas, pelo seu número de elementos
 * e por um tamanho.
 */
typedef struct {
	RGB_PIXEL *data; /**< Representação dos valores de uma matriz RGB */
	int n; /**< Número de elementos da imagem RGB. */
	int size; /**< Tamanho da matriz RGB. */
	int h; /**<Número de linhas da matriz RGB. */
	int w; /**< Número de colunas da matriz RGB. */

}RGB_IMAGE;

/*
* @brief Função que cria uma imagem em RGB.
* Função que cria uma imagem em RGB
* @param height Numero de linhas da imagem.
* @param width Numero de colunas da imagem.
* @return tmp Retorna uma estrutura RGB_IMAGE.
*/
RGB_IMAGE * CreateImageRGB(int height, int width);


/*
*Função que carrega um ficheiro em rgb para uma estrutura RGB_IMAGE.
* @param nome Nome do ficheiro com a imagem rgb.
* @return Retorna uma estrutura RGB_IMAGE.
*/
RGB_IMAGE * LoadFromFileRGB(char *);
/*
*Função que guarda uma RGB_Image num ficheiro.
* @param img RGB_IMAGE que se quer guardar.
* @param nome Nome do ficheiro onde a imagem será guardada.
* @return Nothing
*/
void saveOnFileRGB(RGB_IMAGE *, char *nome );

/*Função que acede a um pixel RGB.
* @param img RGB_IMAGE onde se pretende aceder.
* @param pix_h Numero da linha do pixel.
* @param pix_w
* @return Nothing
*/
void AccessPixelRGB(RGB_IMAGE *, int pix_h, int pix_w);
/* Função que acede a uma região de interesse
* de uma imagem, retornando uma nova imagem.
* @param img RGB_IMAGE que se pretende alterar.
* @param pix_h_start linha onde se pretende começar a região de interesse.
* @param pix_h_end linha onde se pretende acabar a região de interesse.
* @param pix_w_start coluna onde se pretende começar a região de interesse.
* @param pix_w_end coluna onde se pretende acabar a região de interesse.
* @return image Retorna uma nova RGB_IMAGE que é a região de interesse pretendida.
*/
RGB_IMAGE * access_regionRGB(RGB_IMAGE *, int pix_h_start, int pix_h_end, int pix_w_start, int pix_w_end);

/* Função que altera a intensidade de cada componente rgb
* de uma imagem, retornando uma nova imagem.
* @param img RGB_IMAGE que se pretende alterar.
* @param intensity Valor a alterar em cada uma das componentes de cada pixel.
* @return RGB_IMAGE Retorna uma imagem rgb com as alterações de intensidade.
*/
RGB_IMAGE * change_intensityRGB(RGB_IMAGE *, int intensity);

/*
*Função que aplica uma watermark a uma imagem rgb.
* @param big_img RGB_IMAGE onde se irá ser colocada a watermark.
* @param other_img Imagem da watermark.
* @return RGB_IMAGE Nova Imagem RGB com watermark aplicada.
*/

RGB_IMAGE * applyFilter(RGB_IMAGE *);
RGB_IMAGE * applyWatermarkRGB(RGB_IMAGE *, RGB_IMAGE *, int pix_h_start, int pix_w_start, int pix_h_end, int pix_w_end);

#endif //_FORMATS_RGB_H
