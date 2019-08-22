#include "build/temp/_test_FSM.c"
#include "FSM.h"
#include "unity.h"




void oprimirBotonCentral(void) {

 actualizarEstadoInterfaz();

}





void reiniciarEstadoDeLaFSM(void) {

 modificarEstadoInterfaz(PANTALLA_APAGADA);

 modificarEstadoPasadoInterfaz(PANTALLA_APAGADA);

}



void setUp(void) {

}



void tearDown(void) {

}





void test_desbloquearPantalla(void) {

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((PANTALLA_APAGADA)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 2)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_INT);

}





void test_entrarMenuUltimoMensaje(void) {

 reiniciarEstadoDeLaFSM();

 oprimirBotonCentral();

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_ULTIMO_MENSAJE)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 4)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}





void test_salirMenuUltimoMensaje(void) {

 UnityAssertEqualNumber((UNITY_INT)((MENU_ULTIMO_MENSAJE)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

 modificarPosSelector(4 + 5);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_ULTIMO_MENSAJE)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 2)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

}





void test_entrarMenuSOS(void) {

 reiniciarEstadoDeLaFSM();

 oprimirBotonCentral();

 modificarPosSelector(4 + 4);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_SOS)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 5)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

}





void test_salirMenuSOS(void) {

 UnityAssertEqualNumber((UNITY_INT)((MENU_SOS)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

 modificarPosSelector(4 + 5);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_SOS)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 2)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

}





void test_entrarMenuConfiguracion(void) {

 reiniciarEstadoDeLaFSM();

 oprimirBotonCentral();

 modificarPosSelector(4 + 5);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_CONFIGURACION)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 5)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT);

}





void test_salirMenuConfiguracion(void) {

 UnityAssertEqualNumber((UNITY_INT)((MENU_CONFIGURACION)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

 modificarPosSelector(4 + 5);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_CONFIGURACION)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 2)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

}









void test_entrarMenuGrupos(void) {

 reiniciarEstadoDeLaFSM();

 oprimirBotonCentral();

 modificarPosSelector(4 + 3);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_GRUPOS)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_INT);

}

void test_salirMenuGrupos(void) {

 modificarPosSelector(4 + 7);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_GRUPOS)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 2)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT);

}
