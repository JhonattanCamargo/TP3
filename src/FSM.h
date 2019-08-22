#ifndef _FSM_H_
#define _FSM_H_

#include "stdint.h"

#define BRILLO_INICIAL      500
#define BRILLO_MINIMO       100
#define BRILLO_MAXIMO       1000
#define BRILLO_AUMENTO      100

// Posiciones para una columna de 16 opciones (Caben máximo 11 con Sans12)
#define TAM_ACTUAL          11
#define OFFSET              TAM_ACTUAL
#define POS_INI             4
#define MAX_X               128
#define MITAD_X             64
#define MAX_Y               160

#define POS_X_DEF           9
#define POS_X_DEF_2         POS_X_DEF

#define POS_Y_OP_1          POS_INI * TAM_ACTUAL
#define POS_Y_OP_2          POS_Y_OP_1 + TAM_ACTUAL
#define POS_Y_OP_3          POS_Y_OP_2 + TAM_ACTUAL
#define POS_Y_OP_4          POS_Y_OP_3 + TAM_ACTUAL
#define POS_Y_OP_5          POS_Y_OP_4 + TAM_ACTUAL
#define POS_Y_OP_6          POS_Y_OP_5 + TAM_ACTUAL
#define POS_Y_OP_7          POS_Y_OP_6 + TAM_ACTUAL
#define POS_Y_OP_8          POS_Y_OP_7 + TAM_ACTUAL
#define POS_Y_OP_9          POS_Y_OP_8 + TAM_ACTUAL
#define POS_Y_OP_10         POS_Y_OP_9 + TAM_ACTUAL
#define POS_Y_OP_11         POS_Y_OP_10 + TAM_ACTUAL
#define POS_Y_OP_12         POS_Y_OP_11 + TAM_ACTUAL
#define POS_Y_OP_13         POS_Y_OP_12 + TAM_ACTUAL
#define POS_Y_OP_14         POS_Y_OP_13 + TAM_ACTUAL
#define POS_Y_OP_15         POS_Y_OP_14 + TAM_ACTUAL
#define POS_Y_OP_16         POS_Y_OP_15 + TAM_ACTUAL

#define OP_1                POS_INI
#define OP_2                OP_1 + 1
#define OP_3                OP_1 + 2
#define OP_4                OP_1 + 3
#define OP_5                OP_1 + 4
#define OP_6                OP_1 + 5
#define OP_7                OP_1 + 6
#define OP_8                OP_1 + 7
#define OP_9                OP_1 + 8
#define OP_10               OP_1 + 9
#define OP_11               OP_1 + 10
#define OP_12               OP_1 + 11
#define OP_13               OP_1 + 12
#define OP_14               OP_1 + 13
#define OP_15               OP_1 + 14
#define OP_16               OP_1 + 15
#define OP_17               OP_1 + 16
#define OP_18               OP_1 + 17

#define POS_BAT_X           112
#define POS_BAT_Y           152

enum {
    PANTALLA_APAGADA,
    MENU_PRINCIPAL,
    MENU_ULTIMO_MENSAJE,
    MENU_GRUPOS,
    MENU_BASICOS,
    MENU_TIEMPO,
    MENU_SOLICITUDES,
    MENU_NUMEROS,
    MENU_ENVIO,
    MENU_SOS,
    MENU_CONFIGURACION
};

/*
 *  @brief: Retorna el estado actual de la interfaz, para usarlo en otros modulos
 *
 *  @param none
 *  @return estado de la interfaz
 *
 */
uint8_t obtenerEstadoInterfaz(void);

/*
 *  @brief: Asigna el estado actual de la interfaz, para usarlo en otros modulos
 *
 *  @param estado: nuevo estado
 *  @return none
 *
 */
void modificarEstadoInterfaz(uint8_t estado);


/*
 *  @brief: Retorna el estado pasado de la interfaz, para usarlo en otros modulos
 *
 *  @param none
 *  @return estado pasado de la interfaz
 *
 */
uint8_t obtenerEstadoPasadoInterfaz(void);


/*
 *  @brief: Asigna el estado pasado de la interfaz, para usarlo en otros modulos
 *
 *  @param estado: nuevo estado
 *  @return none
 *
 */
void modificarEstadoPasadoInterfaz(uint8_t estado);

/*
 *  @brief: Función que obtiene la posicion del cursor
 *
 *  @param none
 *  @return posicion del selector
 *
 */
int8_t obtenerPosSelector(void);


/*
 *  @brief: Función que actualiza un mensaje escrito con palabras predefinidas
 *
 *  @param OP: posicion del cursor actual
 *  @return none
 *
 */
void modificarPosSelector(int8_t pos);


/*
 *  @brief: Función que actualiza un mensaje escrito con palabras predefinidas
 *
 *  @param OP: posicion del cursor actual
 *  @return none
 *
 */
void actualizarMensaje(uint8_t OP);


/*
 *  @brief: Función que actualiza de la maquina de estados de la interfaz
 *
 *  @param none
 *  @return none
 *
 */
void actualizarEstadoInterfaz(void);

#endif // _FSM_H_
