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

 test_entrarMenuUltimoMensaje();

 UnityAssertEqualNumber((UNITY_INT)((MENU_ULTIMO_MENSAJE)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_INT);

 modificarPosSelector(4 + 5);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_ULTIMO_MENSAJE)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 2)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

}





void test_entrarMenuSOS(void) {

 reiniciarEstadoDeLaFSM();

 oprimirBotonCentral();

 modificarPosSelector(4 + 4);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_SOS)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 5)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

}





void test_salirMenuSOS(void) {

 test_entrarMenuSOS();

 UnityAssertEqualNumber((UNITY_INT)((MENU_SOS)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

 modificarPosSelector(4 + 5);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_SOS)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 2)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

}





void test_entrarMenuConfiguracion(void) {

 reiniciarEstadoDeLaFSM();

 oprimirBotonCentral();

 modificarPosSelector(4 + 5);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_CONFIGURACION)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 5)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

}





void test_salirMenuConfiguracion(void) {

 test_entrarMenuConfiguracion();

 UnityAssertEqualNumber((UNITY_INT)((MENU_CONFIGURACION)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);

 modificarPosSelector(4 + 5);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_CONFIGURACION)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 2)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);

}









void test_entrarMenuGrupos(void) {

 reiniciarEstadoDeLaFSM();

 oprimirBotonCentral();

 modificarPosSelector(4 + 3);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_GRUPOS)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

}

void test_salirMenuGrupos(void) {

 test_entrarMenuGrupos();

 modificarPosSelector(4 + 7);

 oprimirBotonCentral();

 UnityAssertEqualNumber((UNITY_INT)((MENU_PRINCIPAL)), (UNITY_INT)((obtenerEstadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((MENU_GRUPOS)), (UNITY_INT)((obtenerEstadoPasadoInterfaz())), (

((void *)0)

), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4 + 2)), (UNITY_INT)((obtenerPosSelector())), (

((void *)0)

), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);

}
