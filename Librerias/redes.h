int num_redes_denegar;
int num_redes_permitir;
int cant_host_deny;
int cant_host_permit;

// Constantes para tamaños máximos
#define MAX_EXCLUDED_RANGES 10000
#define MAX_EXCLUDED_HOSTS 10000
#define MAX_POOLS 10000
#define MAX_STRING_LENGTH 10000

// Variables y arreglos globales
char dir_excluded1[MAX_STRING_LENGTH];
char dir_excluded2[MAX_STRING_LENGTH];
char dhcp_command_excluded[MAX_EXCLUDED_RANGES][MAX_STRING_LENGTH];
char DHCP_excluded[MAX_EXCLUDED_HOSTS][MAX_STRING_LENGTH];
char nombre_poool[MAX_POOLS][MAX_STRING_LENGTH];
char dir_red_pool[MAX_POOLS][MAX_STRING_LENGTH];
char subred_mascara[MAX_POOLS][MAX_STRING_LENGTH];
char default_gateway[MAX_POOLS][MAX_STRING_LENGTH];
char direccion_dns[MAX_POOLS][MAX_STRING_LENGTH];
char DHCP_pool[MAX_POOLS][MAX_STRING_LENGTH];

int entrada_salida;
int cambio_posicion = 0;
int id_vlan;

char Nombre_dispositivo[60], contrasena_line_vty[60], contrasena_line0[60], contrasena_enablesecret[60], banner_motd[1000];
char nombres1[50][50], direcciones[50][50], mascaras[50][50], saltos[50][50], nombre[12], direccionIP[15], interfaz[30];
char nombreArchivo[20], nombre_dominio[30], nombre_usuario[90], password_contrasenaRemota[120], password_contrasenaLocal[120];
char mascara_SSHTelnet[40], direccion_gateway[40];

int prefijos[1000]; 
char comandos_denegar_redes[1000][1000]; 
char comandos_permitir_redes[1000][1000]; 
char comandos_denegar_host[1000][1000]; 
char comandos_permitir_host[1000][1000]; 
char direccionesIP[1000][1000]; 

int numeros1[50];
int mascara_inicial[32] = {0}; 
int masc1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int masc2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int masc3[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int masc4[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int octeto1, octeto2, octeto3, octeto4;
int n_vlans1, conteo1, asignacion_puerto_dec, binarios1, cant_bits;
int bitsACL[10000][10000];
int octeto1_acl_inicio, octeto2_acl_inicio, octeto3_acl_inicio, octeto4_acl_inicio;
int octeto1_acl_final, octeto2_acl_final, octeto3_acl_final, octeto4_acl_final;
int ACL_Rango_mascara1[8], ACL_Rango_mascara2[8], ACL_Rango_mascara3[8], ACL_Rango_mascara4[8];
int ACL_Rango_mascara1_f[8], ACL_Rango_mascara2_f[8], ACL_Rango_mascara3_f[8], ACL_Rango_mascara4_f[8];
int RangoBits_Mascara1[10000][10], RangoBits_Mascara2[10000][10], RangoBits_Mascara3[10000][10], RangoBits_Mascara4[10000][10];

void logo_menu() {
	printf("___________________________________________________________________________________________________________________\n");
	printf("                               &@@@ /@         |::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|\n");
	printf("                            ,@@@@@@,@          |::::::::'########::'########:'########::'########::'######::::::::|\n");
	printf("                           @@@@@@@@@@@@        |:::::::: ##.... ##: ##.....:: ##.... ##: ##.....::'##... ##:::::::|\n");
	printf("                          @@@@@@@@@@@@@@,      |:::::::: ##:::: ##: ##::::::: ##:::: ##: ##::::::: ##:::..::::::::|\n");
	printf("                         @@@@@@@@@@@@ #@@      |:::::::: ########:: ######::: ##:::: ##: ######:::. ######::::::::|\n");
	printf("      @@@@@@#            @@@@@@@@@@@@@@@@@@    |:::::::: ##.. ##::: ##...:::: ##:::: ##: ##...:::::..... ##:::::::|\n");
	printf("    @@,     @@@          @@@@@@@@@@@@@@@@      |:::::::: ##::. ##:: ##::::::: ##:::: ##: ##:::::::'##::: ##:::::::|\n");
	printf("   &@#       ,@@        @@@@@@@@@              |:::::::: ##:::. ##: ########: ########:: ########:. ######::::::::|\n");
	printf("    @@@      /@@      @@@@@@@@@@*              |::::::::..:::::..::........::........:::........:::......:::::::::|\n");
	printf("       @@@  @@@    @@@@@@@@@@@@@@              |------------------------------------------------------------------|\n");
	printf("         @@@,   %%@@@@@@@@@@@@@@@@@             |   [1] Configuracion basica     |   [10] NAT                      |\n");
	printf("    @@@@/     @@@@@@@@@@@@@@@@@@@@             |   [2] Creacion de VLANs        |   [11] Seguridad de puertos     |\n");
	printf(" /@@*      #@@@@@@@@@@@@@@@@@@@@@@             |   [3] Asignar puertos de acceso|   [12] Generar claves RSA       |\n");
	printf("@@&      *@@@@@@@@@@@@@@@ *@@@@@@              |   [4] Asignar puertos troncales|   [13] Asignar IP a puerto      |\n");
	printf("@@      @@@@@@@@@@@@@@@@@@@ @@@@@              |   [5] Enrutamiento             |   [14] Calculadora máscara fija |\n");
	printf("*@@    @@@@@@@@@@@@@@@@@@@@,@@@@.              |   [6] Encapsulamiento          |   [15] Calculadora VLSM         |\n");
	printf("  @@.  @@@@@@@@@@@@@@@@@@@@ @@@@               |   [7] ACLs                     |   [16] Convertidor de binarios  |\n");
	printf("    @@@@@@@@@@@@@@@@@@@@#,  %%@@@@@/.           |   [8] Configuracion remota     |   [17] Ayuda (dios?)            |\n");
	printf("       @@@@@@@@@@@@@@@@@@@@@ ,@@@@@@@@         |   [9] DHCP                     |   [18] Opciones                 |\n");
	printf("-------------------------------------------------------------------------------------------------------------------\n");
}

void imprimir_logo_archivo(){
	printf("       @@.                                                  %%@@ \n");
	printf("      %%@  &@@&                                         ,@@@/ %%@\n");
	printf("      @@  %%   @@@*                                  &@@,   @ *@, \n");
	printf("     @@  @@@@*  /@@,                            %%@@   &@@@%% *@,  \n");
	printf("      #@  (@(@@&@   @@&    %%@@@@@@@@@@@@@@(    @@/  %%#@@#&@* %%@ \n");
	printf("       @/ /((.((((/#  %%@&%%                  @@@.  #((((# %%(  @@ \n");
	printf("       @@  ( .          .#                  @           #.#  @%%                       \n");
	printf("       /@  *             @*                @(               &&             .s5SSSs.  .s5SSSs.  .s5SSSSs. .s5SSSs.  .s5SSSs.  .s    s.              \n");
	printf("        &&                 %%              @                 &%%                  SS.       SS.    SSS          SS.       SS.       SS.              \n");
	printf("        %%&. @@@@@@@@@  @@@& //          @  @@@@  @@@@@@@@/ %%&.            sS    `:; sS    S%%S    S%%S    sS    `:; sS    S%%S sSs.  S%%S                \n");
	printf("       /%%.                                                  %%%%            sS    `:; sS    S%%S    S%%S    sS    `:; sS    S%%S sSs.  S%%S   \n");
	printf("       %%%%              &@%%                  @@(              %%%%           SS        SS    S%%S    S%%S    SS        SS    S%%S SS`S. S%%S         \n");
	printf("      %%%%         @ @@(    /@              @ ,   @@@ @        *%%,          SS        SSSs. S%%S    S%%S    SS        SS    S%%S SS `S.S%%S    \n");
	printf("      ##%%.        @ @@.%%@@@ #    /((*    %% @@@,#@#*@        %%.##          SS        SS    S%%S    S%%S    SS        SS    S%%S SS  `sS%%S    \n");
	printf("      ##  ,@                   ((((((((                  ,@   #%%          SS        SS    `:;    `:;    SS        SS    `:; SS    `:;   \n");
	printf("      #%%    %% #/              (((((((((*              @  @    #/          SS    ;,. SS    ;,.    ;,.    SS    ;,. SS    ;,. SS    ;,.  \n");
	printf("      ,#.         %%@%%  *@,    (/      (#    #@   @@          ##           `:;;;;;:' :;    ;:'    ;:'    `:;;;;;:' `:;;;;;:' :;    ;:'     \n");
	printf("       #( // ##  ,@  @    &@@@    //    @@@,   */ .@,  @  @  ##            \n");
	printf("        ##    %%@@*    @@@  @@@@@@   *@@@@@@ ,@@(    %%@@*    #%%             \n");
	printf("         /#(/  &@/    @@@, @@@@@@*  %%@@@@@& (@@%%   .#@*  &##.               \n");
	printf("            ##      @. #@ #@@@@&#    (@@@@@  @, %%@     /#%%                 \n");
	printf("              #####@ //    .*,   #@@/   ,*     &  &####*                    \n");
	printf("                   .####/#####%%&@@@@@@&%%#####/##(#                        \n");
	printf("\n");
	
}

void Configuracion_basica(const char datos[12]) {
	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingresa el nombre del dispositivo              |  ");
	gets(Nombre_dispositivo);
		
	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingresa la contraseña para las líneas VTY 0-15 |  ");
	gets(contrasena_line_vty);
		
	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingresa la contraseña para líneas de consola   |  ");
	gets(contrasena_line0);
		
	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingresa la contraseña para el EXEC privilegiado|  ");
	gets(contrasena_enablesecret);
		
	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe tu mensaje para inicio del dispositivo |  ");
	gets(banner_motd);
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\n                                              Configuracion básica");
	printf("\n#################################################################################################################");
	printf("\n\nenable\nconfigure terminal\nhostname %s\nenable secret %s", Nombre_dispositivo, contrasena_enablesecret);
	printf("\nline console 0\npassword %s\nlogin\nexit\nbanner motd #%s#\nline vty 0 15\npassword %s\nlogin\nexit\n", contrasena_line0, banner_motd, contrasena_line_vty);
	printf("\n#################################################################################################################");
	escribir_configuraciones_en_archivo(1, datos);
}
		
void Creacion_VLANs(const char datos[12]) {
	int n_vlans = 0, acceso, troncales, encapsular;
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe el número de VLANs que quieres crear: ");
	scanf("%d", &n_vlans);
	
	char nombres[n_vlans][50];
	int numeros[n_vlans];
	
	for (int conteo = 0; conteo < n_vlans; conteo++) {
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("[%d] Escribe el número de VLAN y su nombre separados por un espacio: ", conteo + 1);
		scanf("%d %s", &numeros[conteo], nombres[conteo]);
	}

	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\n                                              Creación de VLANs");
	printf("\n#################################################################################################################\n\n");
	for (int i = 0; i < n_vlans; i++) {
		printf("vlan %d\nname %s\n", numeros[i], nombres[i]);
	}
	printf("\n#################################################################################################################");
	fflush(stdin);
	
	escribir_VLANs_en_archivo(n_vlans, numeros, nombres, datos);
	printf("\n\n¿Deseas asignar puertos de acceso a las VLAN creadas? [1] SI [2] No  ");
	scanf("%d", &acceso);
	
	if (acceso == 1) {
		asignacion_puertos_VLAN_acceso(n_vlans, numeros, nombres, datos);
	}
	
	printf("\n¿Deseas asignar puertos troncales a las VLAN creadas? [1] SI [2] No  ");
	scanf("%d", &troncales);
	
	if (troncales == 1) {
		asignacion_puertos_VLAN_troncales(n_vlans, numeros, nombres, datos);
	}

	printf("\n¿Deseeas encapsular las redes? [1] Si [2] No ");
	scanf("%d", &encapsular);
	
	if (encapsular == 1) {
		encapsulamiento(n_vlans, numeros, nombres, datos);
	}
}
		
void asignacion_puertos_VLAN_acceso(int total_vlan, int total_numeros[], char nombresV[][50], const char datos[12]) {
	char interfaces[50][50];
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Utiliza [fa] para FastEthernet y/o [gi] para GigabitEthernet\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	
	for (int i = 0; i < total_vlan; i++) {
		printf("Ingresa el rango de interfaces para VLAN %s: ", nombresV[i]);
		scanf("%s", interfaces[i]);
	}
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\n                                              Puertos en modo acceso");
	printf("\n#################################################################################################################\n\n");
	printf("\nenable\nconfigure terminal\n");
	
	for (int i = 0; i < total_vlan; i++) {
		printf("interface range %s\n", interfaces[i]);
		printf("switchport mode access\nswitchport access vlan %d\nswitchport port-security\n", total_numeros[i]);
	}
	printf("exit\n\n");
	printf("\n#################################################################################################################\n\n");
	escribir_puertos_acceso(total_vlan, total_numeros, interfaces, datos);
}

void leer_datos_vlan(int n_vlans, int numeros[], char nombres[][50]) {
	for (int conteo = 0; conteo < n_vlans; conteo++) {
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("[%d] Escribe el número de VLAN y su nombre separados por un espacio: ", conteo + 1);
		scanf("%d %s", &numeros[conteo], nombres[conteo]);
	}
}
		
void asignacion_puertos_VLAN_troncales(int total_vlan, int total_numeros[], char nombresV[][50], const char datos[12]) {
	char troncales[50][50];
	int total_tr;
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Utiliza [fa] para FastEthernet y/o [gi] para GigabitEthernet\n");
	printf("Ejemplo de asignacion de intervalo: fa0/1-7\nSi no cuentas con un intervalo solo escribe la ID de interfaz\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	
	printf("¿Cuántos puertos troncales tienes?  ");
	scanf("%d", &total_tr);
	
	for (int i = 0; i < total_tr; i++) {
		printf("Ingresa el rango de interfaces para el puerto troncal %d: ", i + 1);
		scanf("%s", troncales[i]);
	}
	
	fflush(stdin);
	
	printf("Interfaces de los puertos troncales:\n");
	for (int i = 0; i < total_tr; i++) {
		printf("Puerto Troncal %d: %s\n", i + 1, troncales[i]);
	}
	
	fflush(stdin);
	int j;

	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\n                                              Puertos en modo troncal");
	printf("\n#################################################################################################################\n\n");
	printf("\nenable\nconfigure terminal\n");
	
	for (int i = 0; i < total_tr; i++) {
		printf("interface range %s\n", troncales[i]);
		printf("switchport mode trunk\n");
		printf("switchport trunk allowed vlan");
		for (j = 0; j < total_vlan; j++) {
			if (j == 0) {
				printf(" %d", total_numeros[j]);
			} else {
				printf(",%d", total_numeros[j]);
			}
		}
		printf("\nswitchport trunk native vlan 1\n");
	}
	printf("exit\n\n");
	printf("\n#################################################################################################################\n\n");
	escribir_puertos_troncales(total_vlan, troncales, total_numeros, total_tr, datos);	
}
		
void enrutamiento(const char datos[12]) {
	int modo_enrutamiento, total_redes, rep10 = 1;
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("¿Cuántas redes deseas enrutar? ");
	scanf("%d", &total_redes);

	leer_direcciones_IP(total_redes);

	while (rep10 == 1){
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Tipos de enrutamiento  ||  [1] Estático | [2] Dinámico \nEscribe la opción que necesites: ");
		scanf("%d", &modo_enrutamiento);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		if (modo_enrutamiento == 1) {
			printf("\n                                               Enrutamiento estático");
			printf("\n#################################################################################################################\n\n");
			printf("enable\nconfigure terminal\n");
			for (int i = 0; i < total_redes; i++) {
				printf("ip route %s %s %s\n", direcciones[i], mascaras[i], saltos[i]);
			}
			printf("\n#################################################################################################################\n\n");
		} else if (modo_enrutamiento == 2) {
			printf("\n                                               Enrutamiento dinámico");
			printf("\n#################################################################################################################\n\n");
			printf("enable\nconfigure terminal\nrouter rip\nversion 2\n");
			for (int i = 0; i < total_redes; i++) {
				printf("network %s\n", direcciones[i]);
			}
			printf("\n#################################################################################################################\n\n");
		} else {
			printf("\nOpción no disponible por el momento");
		}
		
		escribir_enrutamiento(modo_enrutamiento, total_redes, direcciones, mascaras, saltos, datos);
		printf("\n¿Quieres hacer un enrutamiento distinto con la mismas direcciones de red\n\t[1] Si  [2] No\n");
		scanf("%d",&rep10);
	}
}
		
void encapsulamiento(int total_vlan, int total_numeros[], char nombresV[][50], const char datos[12]){
	char interfaz_general[12];
	char ip_vlans[total_vlan][20]; 
	char mascara_vlans[total_vlan][20];
	
	int rep = 1;
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Utiliza [fa] para FastEthernet y/o [gi] para GigabitEthernet\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");

	for(int d = 0; d < total_vlan; d ++){
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		fflush(stdin);
		printf("Escribe la dirección IP para la VLAN %s: ", nombresV[d]);
		gets(ip_vlans[d]);
		
		fflush(stdin);
		printf("Escribe la máscara de red para la VLAN %s: ", nombresV[d]);
		gets(mascara_vlans[d]);
	}
	
	fflush(stdin);
	do {
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		fflush(stdin);
		printf("¿Cuál es la interfaz que necesitas encapsular?  ");
		gets(interfaz_general);
		
		printf("\n\n-----------------------------------------------------------------------------------------------------------------\n");
		printf("\n                                               Puertos encapsulados");
		printf("\n#################################################################################################################\n\n");
		printf("\nenable\nconfigure terminal\nint %s\nno shutdown\n", interfaz_general);
		for (int i = 0; i < total_vlan; i++){
			fflush(stdin);
			printf("int %s%c%d\nencapsulation dot1q %d\n", interfaz_general, 46, total_numeros[i], total_numeros[i]);
			printf("ip address %s %s\nexit\n", ip_vlans[i], mascara_vlans[i]);
		}
		printf("\n\n#################################################################################################################\n\n");
		
		fflush(stdin);
		escribir_encapsulamiento(total_vlan, interfaz_general, total_numeros, ip_vlans, mascara_vlans, datos);	
		printf("\n[1] Encapsular otra red con la misma direccion IP\n[2] Terminar encapsulamiento\n");
		scanf("%d",&rep);
	} while(rep == 1);
}
			
void leer_direcciones_IP(int total_redes) {
	for (int i = 0; i < total_redes; i++) {
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("                                               Red #%d\n", i + 1);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Dirección de red (en formato xxx.xxx.xxx.xxx): ");
		scanf("%s", direcciones[i]);
		fflush(stdin);
		printf("Máscara de red (en formato xxx.xxx.xxx.xxx): ");
		scanf("%s", mascaras[i]);
		fflush(stdin);
		printf("Siguiente salto (interfaz de red por la que se conoce a la red): ");
		scanf("%s", saltos[i]);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
	}
}

void listascontrol(const char datos[12]){
	int select, modo_standard, modo_denegacion, modo_permitir;
	int prefijo, num_list_acc;
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\nRecuerda que para las listas de acceso es muy importante el orden.\nPor eso es recomendable que primero generes las condiciones que deniegan accesos\n y por utlimo las que permitan el acceso de los paquetes\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\nSelecciona la que necesites\n[1] Listas de acceso estandard\n[2] Listas de acceso extendidas\n");
	scanf("%d",&select);
	printf("-----------------------------------------------------------------------------------------------------------------\n");

	if(select == 1){
		printf("\n¿Que lista quieres generar primero?\n[1] Denegear\n[2] Permitir\n");
		scanf("%d", &modo_standard);
		
		if(modo_standard == 1) {
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\n[1] Denegar redes completas\n[2] Denegar host especificos\n[3] Denegar un rango de host\n");
			scanf("%d",&modo_denegacion);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nIngresa el número de lista de acceso\n");
			scanf("%d",&num_list_acc);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			
			if(modo_denegacion == 1){
				denegar_red(num_list_acc, datos);
			} else if (modo_denegacion == 2){
				denegar_host_especifico1(num_list_acc, datos);
			} else if (modo_denegacion == 3){
				denegar_rango_host(num_list_acc, datos);
			} else {
				printf("\nOpcion no disponible\n");
			}
		} else if(modo_standard == 2){
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\n[1] Permitir una red completa\n[2] Permitir un host especifico\n[3] Permitir un rango de host\n");
			scanf("%d",&modo_permitir);
			printf("\nIngresa el número de lista de acceso\n");
			scanf("%d",&num_list_acc);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			
			if (modo_permitir == 1){
				permitir_red(num_list_acc, datos);
			} else if (modo_permitir == 2){
				permitir_host_especifico1(num_list_acc, datos);
			} else if (modo_permitir == 3){
				
			} else {
				printf("\nOpción no disponible\n");
			}
		} else {
			printf("\nOpcion no disponible");
		}
	} else if(select == 2){
		
	} else {
		printf("\nOpcion no disponible. Asegurate de seleccionar una opcion habilitada por favor\n");
	}
}

void denegar_red(int access_list, const char datos[12]) {
	int num_list_acc = access_list;
		
	printf("\nEscribe la cantidad de direcciones de red que quieres denegar: ");
	scanf("%d", &num_redes_denegar);
	fflush(stdin);
	
	int prefijo = 0;
	int deny_host;
	for (int i = 0; i < num_redes_denegar; i++) {
		memset(mascara_inicial, 0, sizeof(mascara_inicial));
		memset(masc1, 0, sizeof(masc1));
		memset(masc2, 0, sizeof(masc2));
		memset(masc3, 0, sizeof(masc3));
		memset(masc4, 0, sizeof(masc4));
		
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("\nEscribe la dirección IP (en formato xxx.xxx.xxx.xxx): ");
		scanf("%s", direccionesIP[i]);
		fflush(stdin);
			
		printf("\nEscribe el prefijo de red (por ejemplo: 16): ");
		scanf("%d", &prefijo);
		
		fflush(stdin);
		invertir_mascara(prefijo);
		fflush(stdin);
		snprintf(comandos_denegar_redes[i], sizeof(comandos_denegar_redes[i]), "access-list %d deny %s %d.%d.%d.%d", access_list, direccionesIP[i], binarioADecimal(masc1), binarioADecimal(masc2), binarioADecimal(masc3), binarioADecimal(masc4));
		fflush(stdin);
	}
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\n¿Deseas denegar el acceso a host\n[1] Si\n[2] No\n");
	scanf("%d", &deny_host);
	fflush(stdin);
	
	switch(deny_host){
	case 1:
		fflush(stdin);
		denegar_host_especifico(num_list_acc);
		fflush(stdin);
		
		printf("\n                                               Lista de control de acceso");
		printf("\n#################################################################################################################\n\n");
		printf("enable\nconfigure terminal\n");
		for (int i = 0; i < num_redes_denegar; i++) {
			fflush(stdin);
			printf("%s\n", comandos_denegar_redes[i]);
		}
		fflush(stdin);
		for (int i = 0; i < cant_host_deny; i++) {
			printf("%s\n", comandos_denegar_host[i]);
		}
		fflush(stdin);
		printf("access-list %d permit any\n", access_list);
		fflush(stdout);
		printf("\n#################################################################################################################\n\n");
		escribir_acls_redes_y_host(num_redes_denegar, comandos_denegar_redes, cant_host_deny, comandos_denegar_host, access_list, datos);
		
		break;
	case 2:
		fflush(stdin);
		printf("\n                                               Lista de control de acceso");
		printf("\n#################################################################################################################\n\n");
		printf("enable\nconfigure terminal\n");
		for (int i = 0; i < num_redes_denegar; i++) {
			printf("%s\n", comandos_denegar_redes[i]);
		}
		fflush(stdin);
		printf("access-list %d permit any\n", access_list);
		fflush(stdout);
		printf("\n#################################################################################################################\n\n");
		escribir_acls_redes(num_redes_denegar, comandos_denegar_redes, access_list, datos);
		
		break;
	default:
		printf("\nOpcion no disponible\n");
	}
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("¿Quieres asignar esta lista de control de acceso a un puerto de tu router?\n[1] Si\n[2] No\n");
	scanf("%d", &asignacion_puerto_dec);
	
	fflush(stdin);
	if(asignacion_puerto_dec == 1) {
		asginacionPuertoListaAcceso(access_list, datos);
	}
}
	
void permitir_red(int access_list, const char datos[12]){
	int num_list_acc = access_list;
	
	memset(mascara_inicial, 0, sizeof(mascara_inicial));
	memset(masc1, 0, sizeof(masc1));
	memset(masc2, 0, sizeof(masc2));
	memset(masc3, 0, sizeof(masc3));
	memset(masc4, 0, sizeof(masc4));
	
	printf("\nEscribe la cantidad de direcciones de red que quieres permitir: ");
	scanf("%d", &num_redes_permitir);
	fflush(stdin);
	
	int prefijo = 0;
	int permit_host;
	
	for (int i = 0; i < num_redes_permitir; i++) {
		memset(mascara_inicial, 0, sizeof(mascara_inicial));
		memset(masc1, 0, sizeof(masc1));
		memset(masc2, 0, sizeof(masc2));
		memset(masc3, 0, sizeof(masc3));
		memset(masc4, 0, sizeof(masc4));
		
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("\nEscribe la dirección IP (en formato xxx.xxx.xxx.xxx): ");
		scanf("%s", direccionesIP[i]);
		fflush(stdin);
		
		printf("\nEscribe el prefijo de red (por ejemplo: 16): ");
		scanf("%d", &prefijo);
		fflush(stdin);
		
		invertir_mascara(prefijo);
		fflush(stdin);
		snprintf(comandos_permitir_redes[i], sizeof(comandos_permitir_redes[i]), "access-list %d permit %s %d.%d.%d.%d", access_list, direccionesIP[i], binarioADecimal(masc1), binarioADecimal(masc2), binarioADecimal(masc3), binarioADecimal(masc4));
		fflush(stdin);
	}
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\n¿Deseas permitir el acceso a host\n[1] Si\n[2] No\n");
	scanf("%d", &permit_host);
	
	if(permit_host == 1){
		permitir_host_especifico(num_list_acc);
		fflush(stdin);
		printf("\n                                               Lista de control de acceso");
		printf("\n#################################################################################################################\n\n");
		printf("enable\nconfigure terminal\n");
		for (int i = 0; i < num_redes_permitir; i++) {
			printf("%s\n", comandos_permitir_redes[i]);
		}
		fflush(stdin);
		for (int i = 0; i < num_redes_permitir; i++) {
			printf("%s\n", comandos_permitir_host[i]);
		}
		fflush(stdin);
		printf("access-list %d deny any\n", access_list);
		fflush(stdout);
		printf("\n#################################################################################################################\n\n");
		escribir_acls_redes_y_host_permit(num_redes_permitir,comandos_permitir_redes, cant_host_permit, comandos_permitir_host, access_list, datos);
		
	} else if (permit_host == 2){
		fflush(stdin);
		printf("\n                                               Lista de control de acceso");
		printf("\n#################################################################################################################\n\n");
		printf("enable\nconfigure terminal\n");
		for (int i = 0; i < num_redes_permitir; i++) {
			printf("%s\n", comandos_permitir_redes[i]);
		}
		fflush(stdin);
		printf("access-list %d deny any\n", access_list);
		fflush(stdout);
		printf("\n#################################################################################################################\n\n");
		escribir_acls_redes_permit(num_redes_permitir, comandos_permitir_redes, access_list, datos);
		
	} else {
		printf("\nOpcion no disponible\n");
	}
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("¿Quieres asignar esta lista de control de acceso a un puerto de tu router?\n[1] Si\n[2] No\n");
	scanf("%d", &asignacion_puerto_dec);
	
	fflush(stdin);
	if(asignacion_puerto_dec == 1) {
		asginacionPuertoListaAcceso(access_list, datos);
	}
}

void denegar_host_especifico(int access_list){
	memset(mascara_inicial, 0, sizeof(mascara_inicial));
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\nEscribe la cantidad de host que quieres denegar: ");
	scanf("%d", &cant_host_deny);
	
	for (int i = 0; i < cant_host_deny; i++) {
		memset(mascara_inicial, 0, sizeof(mascara_inicial));
		
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("\nEscribe la dirección IP (en formato xxx.xxx.xxx.xxx): ");
		scanf("%s", direccionesIP[i]);
		fflush(stdin);
		
		snprintf(comandos_denegar_host[i], sizeof(comandos_denegar_host[i]), "access-list %d deny host %s ", access_list, direccionesIP[i]);
		fflush(stdin);
	}
}

void denegar_host_especifico1(int access_list, const char datos[12]){
	memset(mascara_inicial, 0, sizeof(mascara_inicial));
		
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\nEscribe la cantidad de host que quieres denegar: ");
	scanf("%d", &cant_host_deny);
		
	for (int i = 0; i < cant_host_deny; i++) {
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("\nEscribe la dirección IP (en formato xxx.xxx.xxx.xxx): ");
		scanf("%s", direccionesIP[i]);
		fflush(stdin);
			
		snprintf(comandos_denegar_host[i], sizeof(comandos_denegar_host[i]), "access-list %d deny host %s ", access_list, direccionesIP[i]);
		fflush(stdin);
	}
		
	fflush(stdin);
	printf("\n                                               Lista de control de acceso");
	printf("\n#################################################################################################################\n\n");
	printf("enable\nconfigure terminal\n");
	
	for (int i = 0; i < cant_host_deny; i++) {
		printf("%s\n", comandos_denegar_host[i]);
	}
	fflush(stdin);
	printf("access-list %d permit any\n", access_list);
	fflush(stdout);
	printf("\n#################################################################################################################\n\n");
	printf("\n\n");
	
	fflush(stdin);
	
	escribir_acls_host(cant_host_deny, comandos_denegar_host, access_list, datos, 1);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("¿Quieres asignar esta lista de control de acceso a un puerto de tu router?\n[1] Si\n[2] No\n");
	scanf("%d", &asignacion_puerto_dec);
	
	fflush(stdin);
	if(asignacion_puerto_dec == 1) {
		asginacionPuertoListaAcceso(access_list, datos);
	}
}

void permitir_host_especifico(int access_list){
	memset(mascara_inicial, 0, sizeof(mascara_inicial));
	
	printf("\nEscribe la cantidad de host que quieres permitir: ");
	scanf("%d", &cant_host_permit);
	
	for (int i = 0; i < cant_host_permit; i++) {
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("\nEscribe la dirección IP (en formato xxx.xxx.xxx.xxx): ");
		scanf("%s", direccionesIP[i]);
		fflush(stdin);
		
		snprintf(comandos_permitir_host[i], sizeof(comandos_permitir_host[i]), "access-list %d permit host %s ", access_list, direccionesIP[i]);
		fflush(stdin);
	}
}
	
void permitir_host_especifico1(int access_list, const char datos[12]){
	memset(mascara_inicial, 0, sizeof(mascara_inicial));
		
	printf("\nEscribe la cantidad de host que quieres permitir: ");
	scanf("%d", &cant_host_permit);
		
	for (int i = 0; i < cant_host_permit; i++) {
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("\nEscribe la dirección IP (en formato xxx.xxx.xxx.xxx): ");
		scanf("%s", direccionesIP[i]);
		fflush(stdin);
			
		snprintf(comandos_permitir_host[i], sizeof(comandos_permitir_host[i]), "access-list %d permit host %s ", access_list, direccionesIP[i]);
		fflush(stdin);
	}
		
	fflush(stdin);
	printf("\n                                               Lista de control de acceso");
	printf("\n#################################################################################################################\n\n");
	printf("enable\nconfigure terminal\n");

	for (int i = 0; i < cant_host_permit; i++) {
		printf("%s\n", comandos_permitir_host[i]);
	}
	fflush(stdin);
		
	printf("access-list %d deny any\n", access_list);
	fflush(stdout);
	printf("\n#################################################################################################################\n\n");
	printf("\n\n");
	
	fflush(stdin);
	escribir_acls_host(cant_host_permit, comandos_permitir_host, access_list, datos, 2);
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("¿Quieres asignar esta lista de control de acceso a un puerto de tu router?\n[1] Si\n[2] No\n");
	scanf("%d", &asignacion_puerto_dec);
	
	fflush(stdin);
	if(asignacion_puerto_dec == 1) {
		asginacionPuertoListaAcceso(access_list, datos);
	}
}
		


void denegar_rango_host(int num_acc_lis, char datos[12]) {
	int prefi = 0;
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\nEscribe tu direccion de red: ");
	scanf("%d.%d.%d.%d", &octeto1, &octeto2, &octeto3, &octeto4);
	
	memset(mascara_inicial, 0, sizeof(mascara_inicial));
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\nEscribe tu prefijo de red: ");
	scanf("%d", &prefi);
	fflush(stdin);
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\nEscribe tu direccion de host inicial: ");
	scanf("%d.%d.%d.%d", &octeto1_acl_inicio, &octeto2_acl_inicio, &octeto3_acl_inicio, &octeto4_acl_inicio);
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\nEscribe tu direccion de host final: ");
	scanf("%d.%d.%d.%d", &octeto1_acl_final, &octeto2_acl_final, &octeto3_acl_final, &octeto4_acl_final);
	
	generar_binariosporRango();
	
	memset(mascara_inicial, 0, sizeof(mascara_inicial));
	memset(masc1, 0, sizeof(masc1));
	memset(masc2, 0, sizeof(masc2));
	memset(masc3, 0, sizeof(masc3));
	memset(masc4, 0, sizeof(masc4));
	
	fflush(stdin);
	invertir_mascara(prefi);
	
	fflush(stdin);
	int cambio_posicion1 = detectar_cambio_posicion(mascara_inicial);
	
	fflush(stdin);
	if(cambio_posicion1 < 8) {
		printf("Error Interno");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara1[i]);
		}
		printf(".");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara1_f[i]);
		}
		printf(".");
		
	} else if (cambio_posicion1 > 7 && cambio_posicion1 < 16){
		binarios1 = contar_ACL_binario1(masc2);
		cant_bits = (8 - binarios1) + 16;
		int numeroDeHosts = pow(2, cant_bits) - 2;
		
		printf("Un total de dispositivos: %d\n", numeroDeHosts);
		printf("Cambio en octeto 2");
		printf("\nBits totales para host en la mascara 2: %d", cant_bits);
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara2[i]);
		}
		printf("-");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara3[i]);
		}
		printf(".");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara4[i]);
		}
		printf("\n");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara2_f[i]);
		}
		printf(".");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara3_f[i]);
		}
		printf(".");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara4_f[i]);
		}
		printf("\n");
		
	} else if (cambio_posicion1 > 15 && cambio_posicion1 < 24){
		binarios1 = contar_ACL_binario1(masc3);
		cant_bits = (8 - binarios1) + 8;
		int numeroDeHosts = pow(2, cant_bits) - 2;
		
		printf("Un total de dispositivos: %d\n", numeroDeHosts);
		printf("Cambio en octeto 3");
		printf("\nBits totales para host en la mascara 3: %d", cant_bits);
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara3[i]);
		}
		printf(".");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara4[i]);
		}
		printf("\n");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara3_f[i]);
		}
		printf(".");
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara4_f[i]);
		}
		printf("\n");
		
	} else if (cambio_posicion1 > 23 && cambio_posicion1 < 32){
		binarios1 = contar_ACL_binario1(masc4);
		cant_bits = 8 - binarios1;
		int numeroDeHosts = pow(2, cant_bits) - 2;
		
		printf("Un total de dispositivos: %d\n", numeroDeHosts);
		printf("Cambio en octeto 4");
		printf("\nBits para host en la mascara 4: %d\n", cant_bits);
		
		generar_RangoBits(cant_bits, octeto4_acl_inicio, octeto4_acl_final, cambio_posicion1);
		
	} else {
		printf("\nNo hay cambio en la posición\n");
	}
}

void generar_RangoBits(int disp_totales, int octeto_inferior, int octeto_superior, int posicion){
	int lim_inferior = 0;
	int lim_superior = octeto_superior;
	
	if (posicion > 23 && posicion < 32){
		int n_host = octeto_superior - octeto_inferior;
		
		for (int i = 0; i < octeto_inferior; i++){
			lim_inferior++;
		}
		
		int i = 0;
		
		for (lim_inferior; lim_inferior < octeto_superior; lim_inferior++){
			decimalABinario(lim_inferior, RangoBits_Mascara4[i]);
			i++;
		}
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara4[i]);
		}
		printf("\n");
		
		for (int j = 0; j < n_host - 2; j++) {
			for (int k = 0; k < 8; k++) {
				printf("%d", RangoBits_Mascara4[j][k]);
			}
			printf("\n");
		}
		
		for(int i = 0; i < 8; i++){
			printf("%d", ACL_Rango_mascara4_f[i]);
		}
		printf("\n");
		
		int posicionCoincidencia = encontrar_coincidencia(RangoBits_Mascara4, n_host - 2, 10);
		
		if (posicionCoincidencia != -1) {
			printf("Primera coincidencia encontrada en la columna %d\n", posicionCoincidencia);
		} else {
			printf("No se encontraron coincidencias.\n");
		}
		
	}
}

int encontrar_coincidencia(int matriz[10000][10], int filas, int columnas) {
	for (int i = 0; i < filas - 1; i++) {
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j] == matriz[i + 1][j]) {
				return j;
			}
		}
	}
	return -1;
}
	
	
int detectar_cambio_posicion(int mascara[50], int n_octeto){
	for (int i = 0; i < 32; i++) {
		if (mascara[i] != 1) {
			cambio_posicion = i;
			break;
		}
	}
	
	return cambio_posicion;
}
	
int contar_ACL_binario1(int mascara_contable[8]){
	int conta = 0;
	
	for(int i = 0; i < 8; i++){
		if(mascara_contable[i] != 1){
			conta++;
		}
	}
	
	return conta;
}
	
void generar_binariosporRango(){
	memset(ACL_Rango_mascara1, 0, sizeof(ACL_Rango_mascara1));
	memset(ACL_Rango_mascara2, 0, sizeof(ACL_Rango_mascara2));
	memset(ACL_Rango_mascara3, 0, sizeof(ACL_Rango_mascara3));
	memset(ACL_Rango_mascara4, 0, sizeof(ACL_Rango_mascara4));
	memset(ACL_Rango_mascara1_f, 0, sizeof(ACL_Rango_mascara1_f));
	memset(ACL_Rango_mascara2_f, 0, sizeof(ACL_Rango_mascara2_f));
	memset(ACL_Rango_mascara3_f, 0, sizeof(ACL_Rango_mascara3_f));
	memset(ACL_Rango_mascara4_f, 0, sizeof(ACL_Rango_mascara4_f));
	
	decimalABinario(octeto1_acl_inicio, ACL_Rango_mascara1);
	decimalABinario(octeto2_acl_inicio, ACL_Rango_mascara2);
	decimalABinario(octeto3_acl_inicio, ACL_Rango_mascara3);
	decimalABinario(octeto4_acl_inicio, ACL_Rango_mascara4);
	
	decimalABinario(octeto1_acl_final, ACL_Rango_mascara1_f);
	decimalABinario(octeto2_acl_final, ACL_Rango_mascara2_f);
	decimalABinario(octeto3_acl_final, ACL_Rango_mascara3_f);
	decimalABinario(octeto4_acl_final, ACL_Rango_mascara4_f);
	
}
	
void generar_MatrizACL_Rango(int cantidad_total_bits_host){
	
	for(int i = 0; i < cantidad_total_bits_host; i ++){
		
	}
}
	
void invertir_mascara(int prefijo) {
	memset(masc1, 0, sizeof(masc1));
	memset(masc2, 0, sizeof(masc2));
	memset(masc3, 0, sizeof(masc3));
	memset(masc4, 0, sizeof(masc4));
	
	for (int i = 0; i < prefijo; i++) {
		mascara_inicial[i] = 1;
	}

	dividir_mascara(mascara_inicial, prefijo);
}

void decimalABinario(int decimal, int binario[8]) {
	for (int i = 7; i >= 0; i--) {
		binario[i] = decimal % 2;
		decimal /= 2;
	}
}

void dividir_mascara(int mascara_inicial[32], int prefijo) {
	int i = 0;
	
	if (prefijo < 8) {
		for (i = 0; i < 8; i++) {
			masc1[i] = mascara_inicial[i];
		}
	} else if (prefijo < 16) {
		for (i = 0; i < 8; i++) {
			masc1[i] = mascara_inicial[i];
		}
		for (i = 0; i < 8; i++) {
			masc2[i] = mascara_inicial[i + 8];
		}
	} else if (prefijo < 24) {
		for (i = 0; i < 8; i++) {
			masc1[i] = mascara_inicial[i];
		}
		for (i = 0; i < 8; i++) {
			masc2[i] = mascara_inicial[i + 8];
		}
		for (i = 0; i < 8; i++) {
			masc3[i] = mascara_inicial[i + 16];
		}
	} else if (prefijo < 32) {
		for (i = 0; i < 8; i++) {
			masc1[i] = mascara_inicial[i];
		}
		for (i = 0; i < 8; i++) {
			masc2[i] = mascara_inicial[i + 8];
		}
		for (i = 0; i < 8; i++) {
			masc3[i] = mascara_inicial[i + 16];
		}
		for (i = 0; i < 8; i++) {
			masc4[i] = mascara_inicial[i + 24];
		}
	}
	
	invertirArreglo(masc1);
	invertirArreglo(masc2);
	invertirArreglo(masc3);
	invertirArreglo(masc4);
}
int binarioADecimal(int mascara[8]) {
	fflush(stdin);
	int decimal = 0;
	
	for (int i = 7; i >= 0; i--) {
		decimal += mascara[i] * pow(2, 7 - i);
	}
	return decimal;
}

void invertirArreglo(int arreglo[32]) {
	fflush(stdin);
	for (int i = 0; i < 8; i++) {
		arreglo[i] = (arreglo[i] == 1) ? 0 : 1; 
	}
}
void asginacionPuertoListaAcceso(int access_list, const char datos[12]){
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Utiliza [fa] para FastEthernet y/o [gi] para GigabitEthernet\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	
	printf("\ningresa la ID de interfaz que quieres asignar: ");
	gets(interfaz);
	fflush(stdin);
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\nTu puerto es de:\n[1] Entrada\n[2] Salida\n");
	scanf("%d", &entrada_salida);
	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	
	printf("\n                                               Asignacion de ACL a Puerto");
	printf("\n#################################################################################################################\n\n");
	printf("enable\nconfigure terminal\n");
	if(entrada_salida == 1){
		fflush(stdin);
		printf("interface %s\nip access-group %d in\n",interfaz, access_list);
		printf("\n#################################################################################################################\n\n");
		escribir_interfaz_acl(entrada_salida, interfaz, access_list, datos);
	} else if (entrada_salida == 2){
		fflush(stdin);
		printf("interface %s\nip access-group %d out\n",interfaz, access_list);
		printf("\n#################################################################################################################\n\n");
		escribir_interfaz_acl(entrada_salida, interfaz, access_list, datos);
	} else {
		printf("\nOpcion no valida");
	}
	
	fflush(stdin);
}



void calculo_acl_rango(){
	
}

void configuracion_remota(const char datos[12]){
	int opc_ConfiRemota, n;
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("[1] SSH\n[2] Telnet\n");
	scanf("%d", &opc_ConfiRemota);
	
	switch(opc_ConfiRemota){
	case 1:
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Configuracion SSH para:\n[1] Router\n[2] Switch\n");
		scanf("%d",&n);
		leer_datos_ConfRemota(n, datos);
		break;
	case 2:
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Configuracion Telnet para:\n[1] Router\n[2] Switch\n");
		scanf("%d",&n);
		leer_datos_ConfRemotaTELNET(n, datos);
		break;
	default:
		printf("\nOpcion no disponible\n");
	}
}
	
void leer_datos_ConfRemota(int n, const char datos[12]){
	fflush(stdin);
	if (n == 1){
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe el nombre del dispositivo de red: ");
		gets(Nombre_dispositivo);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Utiliza [fa] para FastEthernet y/o [gi] para GigabitEthernet\nPor ejemplo: fa0/1\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe la interfaz que tendrá el SSH: ");
		gets(interfaz); 
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe el nombre de dominio: ");
		gets(nombre_dominio);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe el nombre de usuario (sin espacios): ");
		gets(nombre_usuario);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la contraseña para el acceso remoto: ");
		gets(password_contrasenaRemota);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la contraseña para el acceso local: ");
		gets(password_contrasenaLocal);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la direccion IP que tiene la interfaz %s: ", interfaz);
		gets(direccionIP);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la máscara de red de la dirección IP %s: ", direccionIP);
		gets(mascara_SSHTelnet);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("\n                                              Configuracion de SSH");
		printf("\n#################################################################################################################\n\n");
		printf("\nenable\nconfigure terminal\nhostname %s\nint %s", Nombre_dispositivo, interfaz);
		printf("\nip address %s %s\nno shut\nexit\n", direccionIP, mascara_SSHTelnet);
		printf("\nip domain-name %s\nusername %s privilege 15 secret %s", nombre_dominio, nombre_usuario, password_contrasenaRemota);
		printf("\ncrypto key generate rsa\nyes\n2048\nip ssh ver 2\nenable secret %s", password_contrasenaLocal);
		printf("\nline vty 0 15\ntransport input ssh\nlogin local\nexit\n");
		printf("\n#################################################################################################################\n\n");
		escribir_SSH(n, datos);
	} else if (n == 2){
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe el nombre del dispositivo de red: ");
		gets(Nombre_dispositivo);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la ID de VLAN que tendrá el SSH: ");
		scanf("%d", &id_vlan);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe el nombre de dominio: ");
		gets(nombre_dominio);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe el nombre de usuario (sin espacios): ");
		gets(nombre_usuario);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la contraseña para el acceso remoto: ");
		gets(password_contrasenaRemota);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la contraseña para el acceso local: ");
		gets(password_contrasenaLocal);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la direccion IP que tiene la VLAN %d: ", id_vlan);
		gets(direccionIP);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la máscara de red de la dirección IP %s: ", direccionIP);
		gets(mascara_SSHTelnet);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("Escribe la direccion de gateway: ");
		gets(direccion_gateway);
		fflush(stdin);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		printf("\n                                              Configuracion de SSH");
		printf("\n#################################################################################################################\n\n");
		printf("\nenable\nconfigure terminal\nhostname %s\nint vlan %d", Nombre_dispositivo, id_vlan);
		printf("\nip address %s %s\nno shut\nexit\n", direccionIP, mascara_SSHTelnet);
		printf("\nip default-gateway %s\nip domain-name %s", direccion_gateway, nombre_dominio);
		printf("\ncrypto key generate rsa\nyes\n2048\nip ssh ver 2");
		printf("\nline vty 0 15\ntransport input ssh\nlogin local\nexit\n");
		printf("\nusername %s privilege 15 secret %s", nombre_usuario, password_contrasenaRemota);
		printf("\nenable secret %s\n", password_contrasenaLocal);
		printf("\n#################################################################################################################\n\n");
		escribir_SSH(n, datos);
	}
}
	
void leer_datos_ConfRemotaTELNET(int n, const char datos[12]){
	fflush(stdin);
	if(n == 1){
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Utiliza [fa] para FastEthernet y/o [gi] para GigabitEthernet\nPor ejemplo: fa0/1\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe la interfaz que tendrá el SSH: ");
		gets(Nombre_dispositivo);
		fflush(stdin);
		
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe la dirección IP para la interfaz %s: ", interfaz);
		gets(direccionIP);
		fflush(stdin);
	
	} else if (n == 2){
		int vlan_opcion = 0;
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("[1] Usar VLAN existente\n[2] Crear VLAN nueva\n");
		scanf("%d", &vlan_opcion);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("\n");
		
		if (vlan_opcion == 1){
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la ID de VLAN (por ejemplo '3'): ");
			scanf("%d",&id_vlan);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la dirección IP para la VLAN %d: ", id_vlan);
			gets(direccionIP);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la máscara de red para la IP %s: ", direccionIP);
			gets(mascara_SSHTelnet);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la contraseña para las lineas VTY 0 15: ");
			gets(contrasena_line_vty);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la contraseña para el modo privilegiado: ");
			gets(contrasena_enablesecret);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			
			printf("\n                                              Configuracion de Telnet");
			printf("\n#################################################################################################################\n\n");
			printf("\nenable\nconfigure terminal\ninterface VLAN %d", id_vlan);
			printf("\nip address %s %s\nexit\nline vty 0 15\ntransport input telnet", direccionIP, mascara_SSHTelnet);
			printf("\npassword %s\nlogin\nexit\nenable secret %s\n", contrasena_line_vty, contrasena_enablesecret);
			printf("\n#################################################################################################################\n\n");
			
		} else if (vlan_opcion == 2){
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la ID de VLAN: ");
			scanf("%d", &id_vlan);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe el nombre para la VLAN %d: ",id_vlan);
			gets(Nombre_dispositivo);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escriube la interfaz para asginar la VLAN %d: ", id_vlan);
			gets(interfaz);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la direccion IP para la VLAN %d: ", id_vlan);
			gets(direccionIP);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la mascara de red para la IP %s: ", direccionIP);
			gets(mascara_SSHTelnet);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la contraseña para las lineas VTY 0 15: ");
			gets(contrasena_line_vty);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe la contraseña para el modo privilegiado: ");
			gets(contrasena_enablesecret);
			fflush(stdin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			
			printf("\n                                              Configuracion de Telnet");
			printf("\n#################################################################################################################\n\n");
			printf("\nenable\nconfigure terminal\nvlan %d\nname %s", id_vlan, Nombre_dispositivo);
			printf("\nexit\ninterface vlan %d\nip address %s %s", id_vlan, direccionIP, mascara_SSHTelnet);
			printf("\nexit\ninterface %s\nswitchport mode access\nswitchport access vlan %d\nswitchport port-security", interfaz, id_vlan);
			printf("\nexit\nline vty 0 15\ntransport input telnet\npassword %s\nlogin\nexit\nenable secret %s\n", contrasena_line_vty, contrasena_enablesecret);
			printf("\n#################################################################################################################\n\n");
			
		} else {
			printf("\nOpción no disponible\n");
		}
		
	} else {
		printf("\nOpcion no disponible\n");
	}
	
}


void DHCP(const char datos[12]) {
	int rep_excluded;
	int cant_host_DHCP_excluir = 0;
	int selec_excluded, excluidos1, excluidos2, cant_ip_DHCP_excluir, cant_pool;
	
	do {
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Selecciona lo que requieras primero: \n[1] Excluir rangos\n[2] Excluir host unicos\n");
		scanf("%d", &selec_excluded);
		while (getchar() != '\n'); // Limpiar el búfer de entrada
		
		switch(selec_excluded) {
		case 1: 
			excluidos1 = 1;
			for (int i = 0; i < MAX_EXCLUDED_RANGES; i++) { 
				printf("-----------------------------------------------------------------------------------------------------------------\n");
				printf("Escribe la dirección IP inicial del rango (en formato xxx.xxx.xxx.xxx) escribe 'fin' para terminar:\n ");
				fgets(dir_excluded1, sizeof(dir_excluded1), stdin);
				dir_excluded1[strcspn(dir_excluded1, "\n")] = '\0'; // Eliminar el carácter de nueva línea
				
				if (strcmp(dir_excluded1, "fin") == 0) {
					break; 
				}
				
				printf("-----------------------------------------------------------------------------------------------------------------\n");
				printf("Escribe la dirección IP final del rango (en formato xxx.xxx.xxx.xxx): ");
				fgets(dir_excluded2, sizeof(dir_excluded2), stdin);
				dir_excluded2[strcspn(dir_excluded2, "\n")] = '\0'; // Eliminar el carácter de nueva línea
				
				snprintf(dhcp_command_excluded[i], sizeof(dhcp_command_excluded[i]), "ip dhcp excluded-address %s %s", dir_excluded1, dir_excluded2);
				cant_host_DHCP_excluir++;
			}
			
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("¿Quieres excluir direcciones IP especificas?\n[1] Si\n[2] No\n");
			scanf("%d", &selec_excluded);
			while (getchar() != '\n'); // Limpiar el búfer de entrada
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			
			if (selec_excluded == 1) {
				excluidos2 = 1;
				printf("-----------------------------------------------------------------------------------------------------------------\n");
				printf("Escribe cuántas direcciones vas a evitar que DHCP asigne: ");
				scanf("%d", &cant_ip_DHCP_excluir);
				while (getchar() != '\n'); // Limpiar el búfer de entrada
				printf("-----------------------------------------------------------------------------------------------------------------\n");
				
				for (int i = 0; i < cant_ip_DHCP_excluir; i++) {
					printf("-----------------------------------------------------------------------------------------------------------------\n");
					printf("Ingresa la dirección IP a excluir %d: ", i + 1);
					fgets(DHCP_excluded[i], sizeof(DHCP_excluded[i]), stdin);
					DHCP_excluded[i][strcspn(DHCP_excluded[i], "\n")] = '\0'; // Eliminar el carácter de nueva línea
				}
			}
			break;
			
		case 2:
			excluidos2 = 1;
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Escribe cuántas direcciones vas a evitar que DHCP asigne: ");
			scanf("%d", &cant_ip_DHCP_excluir);
			while (getchar() != '\n'); // Limpiar el búfer de entrada
			
			for (int i = 0; i < cant_ip_DHCP_excluir; i++) {
				printf("-----------------------------------------------------------------------------------------------------------------\n");
				printf("Ingresa la dirección IP a excluir %d: ", i + 1);
				fgets(DHCP_excluded[i], sizeof(DHCP_excluded[i]), stdin);
				DHCP_excluded[i][strcspn(DHCP_excluded[i], "\n")] = '\0'; // Eliminar el carácter de nueva línea
			}
			
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("¿Quieres excluir un rango de direcciones?\n[1] Si\n[2] No\n");
			scanf("%d", &selec_excluded);
			while (getchar() != '\n'); // Limpiar el búfer de entrada
			
			if (selec_excluded == 1) {
				excluidos1 = 1;
				for (int i = 0; i < MAX_EXCLUDED_RANGES; i++) { 
					printf("-----------------------------------------------------------------------------------------------------------------\n");
					printf("Escribe la dirección IP inicial (en formato xxx.xxx.xxx.xxx) si ya has agregado todos los rangos, escribe 'fin':\n ");
					fgets(dir_excluded1, sizeof(dir_excluded1), stdin);
					dir_excluded1[strcspn(dir_excluded1, "\n")] = '\0'; // Eliminar el carácter de nueva línea
					
					if (strcmp(dir_excluded1, "fin") == 0) {
						break; 
					}
						
					printf("-----------------------------------------------------------------------------------------------------------------\n");
					printf("Escribe la dirección IP final (en formato xxx.xxx.xxx.xxx): ");
					fgets(dir_excluded2, sizeof(dir_excluded2), stdin);
					dir_excluded2[strcspn(dir_excluded2, "\n")] = '\0'; // Eliminar el carácter de nueva línea
					
					snprintf(dhcp_command_excluded[i], sizeof(dhcp_command_excluded[i]), "ip dhcp excluded-address %s %s", dir_excluded1, dir_excluded2);
					cant_host_DHCP_excluir++;
				}
			}
			
			break;
			
		default:
			printf("\nOpción no disponible\n");
		}
			
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("¿Quieres agregar más exclusiones?\n[1] Si\n[2] No\n");
		scanf("%d", &selec_excluded);
		
	} while(selec_excluded == 1);
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe cuántos conjuntos (POOL) necesitas asignar: ");
	scanf("%d", &cant_pool);
	while (getchar() != '\n'); // Limpiar el búfer de entrada
	
	for (int i = 0; i < cant_pool; i++) {
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe el nombre para el conjunto %d: ", i + 1);
		fgets(nombre_poool[i], sizeof(nombre_poool[i]), stdin);
		nombre_poool[i][strcspn(nombre_poool[i], "\n")] = '\0'; // Eliminar el carácter de nueva línea
		
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Ingresa la dirección de red: ");
		fgets(dir_red_pool[i], sizeof(dir_red_pool[i]), stdin);
		dir_red_pool[i][strcspn(dir_red_pool[i], "\n")] = '\0'; // Eliminar el carácter de nueva línea
		
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe la máscara de red para la IP: ");
		fgets(subred_mascara[i], sizeof(subred_mascara[i]), stdin);
		subred_mascara[i][strcspn(subred_mascara[i], "\n")] = '\0'; // Eliminar el carácter de nueva línea
		
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe el gateway predeterminado: ");
		fgets(default_gateway[i], sizeof(default_gateway[i]), stdin);
		default_gateway[i][strcspn(default_gateway[i], "\n")] = '\0'; // Eliminar el carácter de nueva línea
		
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe la dirección DNS: ");
		fgets(direccion_dns[i], sizeof(direccion_dns[i]), stdin);
		direccion_dns[i][strcspn(direccion_dns[i], "\n")] = '\0'; // Eliminar el carácter de nueva línea
		
		snprintf(DHCP_pool[i], sizeof(DHCP_pool[i]), "ip dhcp pool %s\nnetwork %s %s\ndefault-router %s\ndns-server %s\n", nombre_poool[i], dir_red_pool[i], subred_mascara[i], default_gateway[i], direccion_dns[i]);
	}
		
	printf("\n###########################################################################################################################################################\n\n");
	printf("                                                                    DHCP\n", nombre);
	printf("\n###########################################################################################################################################################\n\n");
	
	if (excluidos1 == 1) {
		for (int i = 0; i < cant_host_DHCP_excluir; i++) {
			printf("%s\n", dhcp_command_excluded[i]);
		}
	}
	
	if (excluidos2 == 1) {
		for (int i = 0; i < cant_ip_DHCP_excluir; i++) {
			printf("ip dhcp excluded-address %s\n", DHCP_excluded[i]);
		}
	}
	
	for (int i = 0; i < cant_pool; i++) {
		printf("%s\n", DHCP_pool[i]);
	}
	
	printf("\n###########################################################################################################################################################\n\n");
	
	escribir_DHCP(excluidos1, excluidos2, cant_host_DHCP_excluir, cant_ip_DHCP_excluir, cant_pool, dhcp_command_excluded, DHCP_excluded, DHCP_pool, datos);
}
	
void seguridad_puertos(const char datos[12]){
	int numero_puertos;
	
	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe la cantidad de puertos para seguridad: ");
	scanf("%d", &numero_puertos);
	
	for (int indice = 0; indice < numero_puertos; indice ++){
		
	}
}

void generar_claves_rsa(const char datos[12]){
	int tamano_contrasena_rsa;
	
	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Selecciona el tamaño de la contraseña\n[1] 512 bits\n[2] 1024 bits\n[3] 2048 bits\n");
	scanf("%d", &tamano_contrasena_rsa);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	
	switch(tamano_contrasena_rsa){
	case 1:
		printf("\n                                                   Claves RSA generadas");
		printf("\n#################################################################################################################\n\n");
		printf("enable\nconfigure terminal\ncrypto key generate rsa\n512\n\n");
		printf("\n#################################################################################################################\n\n");
		break;
	case 2:
		printf("\n                                                   Claves RSA generadas");
		printf("\n#################################################################################################################\n\n");
		printf("enable\nconfigure terminal\ncrypto key generate rsa\n1024\n\n");
		printf("\n#################################################################################################################\n\n");
		break;
	case 3:
		printf("\n                                                   Claves RSA generadas");
		printf("\n#################################################################################################################\n\n");
		printf("enable\nconfigure terminal\ncrypto key generate rsa\n2048\n\n");
		printf("\n#################################################################################################################\n\n");
		break;
	default: 
		printf("\nOpcion no disponible\n");
	}
	
	escribir_claves_rsa(tamano_contrasena_rsa, datos);
}

void asignar_IP_puertos(const char datos[12]) {
	int numero_puertos;
	char id_interfaz[20], IP_puerto[20], Masc_puerto[20];
	
	fflush(stdin);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe la cantidad de puertos a los que deseas asignar IP: ");
	scanf("%d", &numero_puertos);
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Utiliza [fa] para FastEthernet y/o [gi] para GigabitEthernet\nPor ejemplo fa0/6\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	
	char comandos[10000]; 
	comandos[0] = '\0';
	
	for (int i = 0; i < numero_puertos; i++) {
		fflush(stdin);
		printf("\nPuerto %d: ", i + 1);
		gets(id_interfaz);
		
		fflush(stdin);
		printf("Escribe la direccion IP para %s: ", id_interfaz);
		gets(IP_puerto);
		
		fflush(stdin);
		printf("Escribe la máscara para %s: ", IP_puerto);
		gets(Masc_puerto);
		
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		sprintf(comandos + strlen(comandos), "\nint %s\nip address %s %s\nno shut\n", id_interfaz, IP_puerto, Masc_puerto);
	}
	
	printf("\n                                               Direcciones IP asignadas");
	printf("\n#################################################################################################################\n\n");
	printf("%s", comandos);
	printf("\n#################################################################################################################\n\n");

	escribir_asignacionPuertos(comandos, datos);
}
