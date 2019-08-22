#include "FSM.h"


uint8_t estadoInterfaz = PANTALLA_APAGADA;          // Estado de la máquina de estados de la interfaz
uint8_t estadoPasado = PANTALLA_APAGADA;
int8_t posSelector = POS_INI;          // Posición del selector en la pantalla                                           // Limite inferior del selector en la pantalla del menu que se muestre

uint16_t brillo = BRILLO_INICIAL;

// Esta variable simula el pin de PWM conectado al brillo de la pantalla
uint16_t brilloPin;

/*
 *  @brief: Retorna el estado actual de la interfaz, para usarlo en otros modulos
 *
 *  @param none
 *  @return estado de la interfaz
 *
 */
uint8_t obtenerEstadoInterfaz(void) {
	return estadoInterfaz;
}
/*
 *  @brief: Asigna el estado actual de la interfaz, para usarlo en otros modulos
 *
 *  @param estado: nuevo estado
 *  @return none
 *
 */
void modificarEstadoInterfaz(uint8_t estado) {
	estadoInterfaz = estado;
}


/*
 *  @brief: Retorna el estado pasado de la interfaz, para usarlo en otros modulos
 *
 *  @param none
 *  @return estado pasado de la interfaz
 *
 */
uint8_t obtenerEstadoPasadoInterfaz(void){
	return estadoPasado;
}


/*
 *  @brief: Asigna el estado actual de la interfaz, para usarlo en otros modulos
 *
 *  @param estado: nuevo estado
 *  @return none
 *
 */
void modificarEstadoPasadoInterfaz(uint8_t estado) {
	estadoPasado = estado;
}


/*
 *  @brief: Función que obtiene la posicion del cursor
 *
 *  @param none
 *  @return posicion del selector
 *
 */
int8_t obtenerPosSelector(void) {
	return posSelector;
}

/*
  *  @brief: Función que modificar la posicion del cursor
 *
 *  @param OP: posicion del cursor actual
 *  @return none
 *
 */
void modificarPosSelector(int8_t pos) {
	posSelector = pos;
}

/*
 *  @brief: Función que actualiza un mensaje escrito con palabras predefinidas
 *
 *  @param OP: posicion del cursor actual
 *  @return none
 *
 */
void actualizarMensaje(uint8_t OP) {

}

/*
 *  @brief: Función que actualiza de la maquina de estados de la interfaz
 *
 *  @param none
 *  @return none
 *
 */
void actualizarEstadoInterfaz(void)          // Actualiza máquina de estados de la Interfaz
{
	// Los cambios de estado sólo se ejecutan si el botón de enter fue presionado
	switch (estadoInterfaz) {          // En función del la variable estadoInterfaz y el diagrama de FSM cambia.
		case PANTALLA_APAGADA:          // Si está apagada
			estadoInterfaz = MENU_PRINCIPAL;          // Pasar al menú principal
			estadoPasado = PANTALLA_APAGADA;          // Guardar estado pasado
			posSelector = OP_3;          // Primera posición del menu principal
			break;
		case MENU_PRINCIPAL:          // Si está en menú principal
			if (posSelector == OP_3) {          // Y el selector está en 3
				estadoInterfaz = MENU_ULTIMO_MENSAJE;          // Pasar a MENU_ULTIMO_MENSAJE
				posSelector = OP_5;
			}
			else if (posSelector == OP_4) {          // O si el selector está en 4
				estadoInterfaz = MENU_GRUPOS;          // Pasar a MENU_GRUPOS
				posSelector = OP_1;
			}
			else if (posSelector == OP_5) {          // O si el selector está en 5
				estadoInterfaz = MENU_SOS;          // Pasar a MENU_SOS
				posSelector = OP_6;
			}
			else if (posSelector == OP_6) {          // O si el selector está en 6
				estadoInterfaz = MENU_CONFIGURACION;          // Pasar a MENU_CONFIGURACION
				posSelector = OP_6;
			}
			estadoPasado = MENU_PRINCIPAL;          // Guardar estado anterior
			break;

		case MENU_ULTIMO_MENSAJE:          // Si esta en el menú de último mensaje
			if (posSelector == OP_5) {          // Si el selector está en 5
				estadoInterfaz = MENU_ENVIO;          // Pasar a MENU_ENVIO
				posSelector = OP_3;
			}
			else if (posSelector == OP_6) {          // O si el selector está en 6
				estadoInterfaz = MENU_PRINCIPAL;          // Pasar a MENU_PRINCIPAL
				posSelector = OP_3;
			}
			estadoPasado = MENU_ULTIMO_MENSAJE;          // Guardar ultimo estado
			break;

		case MENU_GRUPOS:          // Si está en MENU_GRUPOS
			if (posSelector == OP_1) {          // Y el selector está en 1
				estadoInterfaz = MENU_BASICOS;          // Pasar a MENU_BASICOS
				posSelector = OP_1;
			}
			else if (posSelector == OP_2) {          // O si el selector está en 2
				estadoInterfaz = MENU_TIEMPO;          // Pasar a MENU_TIEMPO
				posSelector = OP_1;
			}
			else if (posSelector == OP_3) {          // O si el selector está en 3
				estadoInterfaz = MENU_SOLICITUDES;          // Pasar a MENU_SOLICITUDES
				posSelector = OP_1;
			}
			else if (posSelector == OP_4) {          // O si el selector está en 4
				estadoInterfaz = MENU_NUMEROS;          // Pasar a MENU_SOLICITUDES
				posSelector = OP_1;
			}
			else if (posSelector == OP_5) {          // O si el selector está en 4
				estadoInterfaz = MENU_GRUPOS;          // No cambiar de menu
				actualizarMensaje(OP_5);          // Actualizar el mensaje escrito
			}
			else if (posSelector == OP_6) {          // O si el selector está en 6
				estadoInterfaz = MENU_ENVIO;          // Pasar a MENU_ENVIO
			}
			else if (posSelector == OP_7) {          // O si el selector está en 7
				estadoInterfaz = MENU_GRUPOS;          // No cambiar de menu
				actualizarMensaje(OP_7);          // Actualizar el mensaje escrito
			}
			else if (posSelector == OP_8) {          // O si el selector está en 8
				estadoInterfaz = MENU_PRINCIPAL;          // Pasar a MENU_PRINCIPAL
				posSelector = OP_3;
			}
			estadoPasado = MENU_GRUPOS;          // Guardar último estado
			break;

		case MENU_SOS:          // Si esta en el menú SOS
			if (posSelector == OP_5) {          // O si el selector está en 6
				estadoInterfaz = MENU_ENVIO;          // Pasar a MENU_ENVIO
			}
			else if (posSelector == OP_6) {          // O si el selector está en 6
				estadoInterfaz = MENU_PRINCIPAL;          // No cambiar de menu
				posSelector = OP_3;
			}
			estadoPasado = MENU_SOS;
			break;

		case MENU_CONFIGURACION:
			if (posSelector == OP_4) {          // O si el selector está en 6
				estadoInterfaz = MENU_CONFIGURACION;          // No cambiar de menu
				brillo += BRILLO_AUMENTO;
				if (brillo > BRILLO_MAXIMO)
					brillo = BRILLO_MAXIMO;
				brilloPin = (brillo);
			}
			else if (posSelector == OP_5) {          // O si el selector está en 6
				estadoInterfaz = MENU_CONFIGURACION;          // No cambiar de menu
				brillo -= BRILLO_AUMENTO;
				if (brillo < BRILLO_MINIMO)
					brillo = BRILLO_MINIMO;
				brilloPin = (brillo);
			}
			else if (posSelector == OP_6) {          // O si el selector está en 6
				estadoInterfaz = MENU_PRINCIPAL;          // No cambiar de menu
				posSelector = OP_3;
			}
			estadoPasado = MENU_CONFIGURACION;
			break;

		case MENU_BASICOS:          // Si está en MENU_BASICOS
			if (posSelector == OP_1) {          // Y el selector está en 2
				estadoInterfaz = MENU_BASICOS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_1);
			}
			else if (posSelector == OP_2) {          // O si el selector está en 3
				estadoInterfaz = MENU_BASICOS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_2);
			}
			else if (posSelector == OP_3) {          // O si el selector está en 4
				estadoInterfaz = MENU_BASICOS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_3);
			}
			else if (posSelector == OP_4) {          // O si el selector está en 5
				estadoInterfaz = MENU_BASICOS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_4);
			}
			else if (posSelector == OP_5) {          // O si el selector está en 6
				estadoInterfaz = MENU_BASICOS;          // Volver a MENU_GRUPOS
				actualizarMensaje(OP_5);
			}
			else if (posSelector == OP_6) {          // O si el selector está en 6
				estadoInterfaz = MENU_GRUPOS;          // Volver a MENU_GRUPOS
			}
			estadoPasado = MENU_BASICOS;
			break;

		case MENU_SOLICITUDES:          // Si está en MENU_SOLICITUDES
			if (posSelector == OP_1) {          // Y el selector está en 1
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_1);
			}
			else if (posSelector == OP_2) {          // O si el selector está en 2
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_2);
			}
			else if (posSelector == OP_3) {          // O si el selector está en 3
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_3);
			}
			else if (posSelector == OP_4) {          // O si el selector está en 4
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_4);
			}
			else if (posSelector == OP_5) {          // O si el selector está en 5
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_5);
			}
			else if (posSelector == OP_6) {          // O si el selector está en 6
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_6);
			}
			else if (posSelector == OP_7) {          // O si el selector está en 7
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_7);
			}
			else if (posSelector == OP_8) {          // O si el selector está en 8
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_8);
			}
			else if (posSelector == OP_9) {          // O si el selector está en 9
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_9);
			}
			else if (posSelector == OP_10) {          // O si el selector está en 10
				estadoInterfaz = MENU_SOLICITUDES;          // No Cambiar, agregar comando
				actualizarMensaje(OP_10);
			}
			else if (posSelector == OP_11) {          // O si el selector está en 11
				estadoInterfaz = MENU_GRUPOS;          // Volver a MENU_GRUPOS
				posSelector = OP_1;
			}
			estadoPasado = MENU_SOLICITUDES;          // Guardar útimo estado
			break;

		case MENU_TIEMPO:          // Si está en MENU_TIEMPO
			if (posSelector == OP_1) {          // Y el selector está en 1
				estadoInterfaz = MENU_TIEMPO;          // No Cambiar, agregar comando
				actualizarMensaje(OP_1);
			}
			else if (posSelector == OP_2) {          // O si el selector está en 2
				estadoInterfaz = MENU_TIEMPO;          // No Cambiar, agregar comando
				actualizarMensaje(OP_2);
			}
			else if (posSelector == OP_3) {          // O si el selector está en 3
				estadoInterfaz = MENU_TIEMPO;          // No Cambiar, agregar comando
				actualizarMensaje(OP_3);
			}
			else if (posSelector == OP_4) {          // O si el selector está en 4
				estadoInterfaz = MENU_TIEMPO;          // No Cambiar, agregar comando
				actualizarMensaje(OP_4);
			}
			else if (posSelector == OP_5) {          // O si el selector está en 5
				estadoInterfaz = MENU_TIEMPO;          // No Cambiar, agregar comando
				actualizarMensaje(OP_5);
			}
			else if (posSelector == OP_6) {          // O si el selector está en 6
				estadoInterfaz = MENU_GRUPOS;          // Cambiar a MENU_GRUPOS
				posSelector = OP_1;
			}
			estadoPasado = MENU_TIEMPO;          // Guardar último estado
			break;

		case MENU_NUMEROS:          // Si está en MENU_TIEMPO
			if (posSelector == OP_1) {          // Y el selector está en 1
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_1);
			}
			else if (posSelector == OP_2) {          // O si el selector está en 2
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_2);
			}
			else if (posSelector == OP_3) {          // O si el selector está en 3
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_3);
			}
			else if (posSelector == OP_4) {          // O si el selector está en 4
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_4);
			}
			else if (posSelector == OP_5) {          // O si el selector está en 5
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_5);
			}
			else if (posSelector == OP_6) {          // O si el selector está en 6
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_6);
			}
			else if (posSelector == OP_7) {          // O si el selector está en 7
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_7);
			}
			else if (posSelector == OP_8) {          // O si el selector está en 8
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_8);
			}
			else if (posSelector == OP_9) {          // O si el selector está en 9
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_9);
			}
			else if (posSelector == OP_10) {          // O si el selector está en 10
				estadoInterfaz = MENU_NUMEROS;          // No Cambiar, agregar comando
				actualizarMensaje(OP_10);
			}
			else if (posSelector == OP_11) {          // O si el selector está en 11
				estadoInterfaz = MENU_GRUPOS;          // Cambiar a Menu_grupos
			}
			estadoPasado = MENU_NUMEROS;          // Guardar último estado
			break;

		default:
			estadoInterfaz = MENU_PRINCIPAL;          // Si no se encuentra en ninguno de estos estados, ir al menú principal
			estadoPasado = PANTALLA_APAGADA;          // Establercer el pasado como pantalla apagada
			posSelector = OP_3;
			break;
	}
}
