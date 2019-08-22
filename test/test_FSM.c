#include "unity.h"
#include "FSM.h"

// Funcion que imita el evento externo de oprimir el boton central
void oprimirBotonCentral(void) {
	actualizarEstadoInterfaz();
}

// Funcion que reinicia el estado como si estuviera en modo de suspension
void reiniciarEstadoDeLaFSM(void) {
	modificarEstadoInterfaz(PANTALLA_APAGADA);
	modificarEstadoPasadoInterfaz(PANTALLA_APAGADA);
}

void setUp(void) {
}

void tearDown(void) {
}

// Test para evaluar trasicion de PANTALLA_APAGADA a MENU_PRINCIPAL
void test_desbloquearPantalla(void) {
	oprimirBotonCentral();
	TEST_ASSERT_EQUAL(MENU_PRINCIPAL, obtenerEstadoInterfaz());
	TEST_ASSERT_EQUAL(PANTALLA_APAGADA, obtenerEstadoPasadoInterfaz());
	TEST_ASSERT_EQUAL(OP_3, obtenerPosSelector());
}

// Test para evaluar comportamiento de MENU_PRINCIPAL a MENU_ULTIMO_MENSAJE
void test_entrarMenuUltimoMensaje(void) {
	reiniciarEstadoDeLaFSM();
	oprimirBotonCentral();
	oprimirBotonCentral();
	TEST_ASSERT_EQUAL(MENU_ULTIMO_MENSAJE, obtenerEstadoInterfaz());
	TEST_ASSERT_EQUAL(MENU_PRINCIPAL, obtenerEstadoPasadoInterfaz());
	TEST_ASSERT_EQUAL(OP_5, obtenerPosSelector());
}

// Test para evaluar comportamiento de MENU_ULTIMO_MENSAJE a MENU_PRINCIPAL
void test_salirMenuUltimoMensaje(void) {
	TEST_ASSERT_EQUAL(MENU_ULTIMO_MENSAJE, obtenerEstadoInterfaz());
	modificarPosSelector(OP_6);          // Esta funcion permite simular los otros dos botones de subir y bajar
	oprimirBotonCentral();
	TEST_ASSERT_EQUAL(MENU_PRINCIPAL, obtenerEstadoInterfaz());
	TEST_ASSERT_EQUAL(MENU_ULTIMO_MENSAJE, obtenerEstadoPasadoInterfaz());
	TEST_ASSERT_EQUAL(OP_3, obtenerPosSelector());
}

// Test para evaluar comportamiento de MENU_PRINCIPAL a MENU_SOS
void test_entrarMenuSOS(void) {
	reiniciarEstadoDeLaFSM();
	oprimirBotonCentral();
	modificarPosSelector(OP_5);
	oprimirBotonCentral();
	TEST_ASSERT_EQUAL(MENU_SOS, obtenerEstadoInterfaz());
	TEST_ASSERT_EQUAL(MENU_PRINCIPAL, obtenerEstadoPasadoInterfaz());
	TEST_ASSERT_EQUAL(OP_6, obtenerPosSelector());
}

// Test para evaluar comportamiento de MENU_SOS a MENU_PRINCIPAL
void test_salirMenuSOS(void) {
	TEST_ASSERT_EQUAL(MENU_SOS, obtenerEstadoInterfaz());
	modificarPosSelector(OP_6);          // Esta funcion permite simular los otros dos botones de subir y bajar
	oprimirBotonCentral();
	TEST_ASSERT_EQUAL(MENU_PRINCIPAL, obtenerEstadoInterfaz());
	TEST_ASSERT_EQUAL(MENU_SOS, obtenerEstadoPasadoInterfaz());
	TEST_ASSERT_EQUAL(OP_3, obtenerPosSelector());
}

// Test para evaluar comportamiento de MENU_PRINCIPAL a MENU_CONFIGURACION
void test_entrarMenuConfiguracion(void) {
	reiniciarEstadoDeLaFSM();
	oprimirBotonCentral();
	modificarPosSelector(OP_6);
	oprimirBotonCentral();
	TEST_ASSERT_EQUAL(MENU_CONFIGURACION, obtenerEstadoInterfaz());
	TEST_ASSERT_EQUAL(MENU_PRINCIPAL, obtenerEstadoPasadoInterfaz());
	TEST_ASSERT_EQUAL(OP_6, obtenerPosSelector());
}

// Test para evaluar comportamiento de MENU_CONFIGURACION a MENU_PRINCIPAL
void test_salirMenuConfiguracion(void) {
	TEST_ASSERT_EQUAL(MENU_CONFIGURACION, obtenerEstadoInterfaz());
	modificarPosSelector(OP_6);          // Esta funcion permite simular los otros dos botones de subir y bajar
	oprimirBotonCentral();
	TEST_ASSERT_EQUAL(MENU_PRINCIPAL, obtenerEstadoInterfaz());
	TEST_ASSERT_EQUAL(MENU_CONFIGURACION, obtenerEstadoPasadoInterfaz());
	TEST_ASSERT_EQUAL(OP_3, obtenerPosSelector());
}

// Desde aca en adelante se probara la funcionalidad de acceso a cada menu

// Test para evaluar comportamiento de MENU_PRINCIPAL a MENU_GRUPOS
void test_entrarMenuGrupos(void) {
	reiniciarEstadoDeLaFSM();
	oprimirBotonCentral();
	modificarPosSelector(OP_4);
	oprimirBotonCentral();
	TEST_ASSERT_EQUAL(MENU_GRUPOS, obtenerEstadoInterfaz());
	TEST_ASSERT_EQUAL(MENU_PRINCIPAL, obtenerEstadoPasadoInterfaz());
	TEST_ASSERT_EQUAL(OP_1, obtenerPosSelector());
}
void test_salirMenuGrupos(void) {
	modificarPosSelector(OP_8);
	oprimirBotonCentral();
	TEST_ASSERT_EQUAL(MENU_PRINCIPAL, obtenerEstadoInterfaz());
	TEST_ASSERT_EQUAL(MENU_GRUPOS, obtenerEstadoPasadoInterfaz());
	TEST_ASSERT_EQUAL(OP_3, obtenerPosSelector());
}

