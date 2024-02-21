struct comandos {
	char name[50];
	char descripcion[500];
	char ejemplo[1000];
};

void convertir_binario_decimal(){
	int seleccion_convertir;
	int binario[1000];
	int numerobin;
	int decimal;
	int conversion_veces;
	int numerodeci, base, divisor, i;
	int inicio, fin;
	
	do {
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("[1] Binario a decimal\n[2] Decimal a binario\n[3] Generar un rango de números en binario\n");
		scanf("%d", &seleccion_convertir);
		fflush(stdin);
		
		switch(seleccion_convertir){
		case 1:
			fflush(stdin);
			numerodeci = 0, base = 1;
			
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nEscribe el número binario: ");
			scanf("%d",&numerobin);
			fflush(stdin);
			
			while(numerobin > 0){
				divisor = numerobin % 10;
				numerodeci = numerodeci + divisor * base;
				
				numerobin = numerobin / 10;
				base = base * 2;
			}
			
			printf("El número es: %d\n", numerodeci);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			
			break;
		case 2:
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nEscribe el número decimal: ");
			scanf("%d",&decimal);
			
			i = 0;
			while(decimal > 0){
				binario[i] = decimal % 2;
				decimal = decimal / 2;
				i++;
			}
			
			printf("El número binario es: ");
			
			for (int j = i - 1; j >= 0; j--) {
				printf("%d", binario[j]);
			}
			printf("\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			break;
		case 3:
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Ingrese el valor inicial: ");
			scanf("%d", &inicio);
			printf("Ingrese el valor final: ");
			scanf("%d", &fin);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			Rango_Binario(inicio, fin);
			break;
		default:
			printf("\nOpcion no válida\n");
		}
		printf("¿Deseas hacer la conversion de un número más?\n[1] Si\n[2] No\n");
		scanf("%d", &conversion_veces);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
	} while(conversion_veces == 1);
}

void Rango_Binario(int inicio, int fin) {
	int bits_total = (int)log2(fin) + 1;
	
	printf("\n| Decimal | Binario\n");
	for (int i = inicio; i <= fin; i++) {
		printf("|  %.5d  ", i);
		decimal_binario(i, bits_total);
	}
}
	
void decimal_binario(int n, int numero_bits) {
	int binarios_arreglo[numero_bits];
	for (int i = 0; i < numero_bits; i++) {
		binarios_arreglo[i] = (n >> (numero_bits - 1 - i)) & 1;
	}
	
	printf("|  ");
	for (int i = 0; i < numero_bits; i++) {
		printf("%d", binarios_arreglo[i]);
	}
	printf("  |\n");
}


void cambiar_color(){
	int fondo, texto;
	int configuracion_color = 1;
	
	while(configuracion_color == 1){
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("\n[0] Negro        [8] Gris\n[1] Azul         [9] Azul claro\n[2] Verde        [10] Verde claro\n[3] Aguamarina   [11] Aguamarino claro\n[4] Rojo         [12] Rojo claro\n[5] Purpura      [13] Purpura claro\n[6] Amarillo     [14] Amarillo claro\n[7] Blanco       [15] Blanco brillante\n");
		printf("\n-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escoge un color para el fondo: ");
		scanf("%d", &fondo);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escoge un color para el texto: ");
		scanf("%d", &texto);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		
		if (fondo >= 0 && fondo <= 15 && texto >= 0 && texto <= 15) {
			char comando[50];
			sprintf(comando, "color %X%X", fondo, texto);
			system(comando);
			system("color"); 
		} else {
			printf("Valores de color no válidos. Segurate de que se encuentren en el rango de 0 a 15.\n");
		}
		
		printf("\n\n¿Quieres volver a cambiar el color? \n[1] Si\n[2] No\n");
		scanf("%d",&configuracion_color);
	}
}

void diccionario_comandos(struct comandos comandos_diccionario[]){
	strcpy(comandos_diccionario[0].name, "write");
	strcpy(comandos_diccionario[0].descripcion, "Permite guardar los cambios realizados en la configuración para que persistan incluso después de reiniciar\nel dispositivo.");
	strcpy(comandos_diccionario[0].ejemplo, "Supongamos que hemos realizado algunos cambios en la configuración de un enrutador y queremos guardar\nesos cambios. Podemos hacerlo de la siguiente manera:\nRouter> enable\nRouter# write");

	strcpy(comandos_diccionario[1].name, "enable");
	strcpy(comandos_diccionario[1].descripcion, "Permite acceder al modo de privilegios elevados para realizar configuraciones avanzadas. (Se diferencia por la\nnotacion con un '#'");
	strcpy(comandos_diccionario[1].ejemplo, "\nRouter> enable\nRouter# ");
	
	strcpy(comandos_diccionario[2].name, "configure terminal");
	strcpy(comandos_diccionario[2].descripcion, "Permite acceder al modo de configuración global para modificar la configuración del dispositivo.");
	strcpy(comandos_diccionario[2].ejemplo, "\nRouter# configure terminal\nRouter(config)# ");
	
	strcpy(comandos_diccionario[3].name, "interface");
	strcpy(comandos_diccionario[3].descripcion, "Permite ingresar a una interfaz del dispositivo. Se puede aplicar con 'interface <id de interfaz>'");
	strcpy(comandos_diccionario[3].ejemplo, "\nRouter# configure terminal\nRouter(config)#interface GigabitEthernet0/1 \nRouter(config-if)# ");

	strcpy(comandos_diccionario[4].name, "exit");
	strcpy(comandos_diccionario[4].descripcion, "Se utiliza para salir del modo de configuración actual y retroceder a un nivel de\nconfiguración anterior.");
	strcpy(comandos_diccionario[4].ejemplo, "\nRouter# configure terminal\nRouter(config)#interface GigabitEthernet0/1 \nRouter(conf-if)# \nRouter(config)#");
	
	strcpy(comandos_diccionario[5].name, "ping");
	strcpy(comandos_diccionario[5].descripcion, "Se utiliza para enviar paquetes de prueba a una dirección IP o un host para\nverificar la conectividad de red y medir el tiempo de respuesta.");
	strcpy(comandos_diccionario[5].ejemplo, "\nRouter# ping 192.168.1.1");

	strcpy(comandos_diccionario[6].name, "hostname");
	strcpy(comandos_diccionario[6].descripcion, "Se utiliza para cambiar o establecer el nombre del dispositivo, que se muestra en el\nprompt de línea de comandos.");
	strcpy(comandos_diccionario[6].ejemplo, "\nRouter(config)# hostname MiRouter\nMiRouter(config)#");
	
	strcpy(comandos_diccionario[7].name, "enable secret");
	strcpy(comandos_diccionario[7].descripcion, "Se utiliza para establecer una contraseña encriptada que se requiere para acceder al modo de privilegios\nelevados (modo privilegiado).");
	strcpy(comandos_diccionario[7].ejemplo, "Router(config)# enable secret class");
	
	strcpy(comandos_diccionario[8].name, "show ip interface");
	strcpy(comandos_diccionario[8].descripcion, "Muestra información sobre las interfaces IP configuradas en el dispositivo.");
	strcpy(comandos_diccionario[8].ejemplo, "Router# show ip interface");
	
	strcpy(comandos_diccionario[9].name, "show running-config");
	strcpy(comandos_diccionario[9].descripcion, "Muestra la configuración actual en ejecución del dispositivo.");
	strcpy(comandos_diccionario[9].ejemplo, "Router# show running-config");
	
	strcpy(comandos_diccionario[10].name, "ip nat outside source list");
	strcpy(comandos_diccionario[10].descripcion, "Configura una lista de acceso extendida para definir una regla de traducción de direcciones NAT para tráfico saliente.");
	strcpy(comandos_diccionario[10].ejemplo, "Router(config)# ip nat outside source list MiLista pool MiPool");
	
	strcpy(comandos_diccionario[11].name, "show vlan brief");
	strcpy(comandos_diccionario[11].descripcion, "Muestra un resumen de las VLAN configuradas en el dispositivo.");
	strcpy(comandos_diccionario[11].ejemplo, "Switch# show vlan brief");
	
	strcpy(comandos_diccionario[12].name, "access-list");
	strcpy(comandos_diccionario[12].descripcion, "Permite configurar listas de acceso para controlar el tráfico de red.");
	strcpy(comandos_diccionario[12].ejemplo, "Router(config)# access-list 1 permit 192.168.1.0 0.0.0.255");
	
	strcpy(comandos_diccionario[13].name, "ip route");
	strcpy(comandos_diccionario[13].descripcion, "Agrega una ruta estática a la tabla de enrutamiento del dispositivo.");
	strcpy(comandos_diccionario[13].ejemplo, "Router(config)# ip route 0.0.0.0 0.0.0.0 192.168.1.1");
	
	strcpy(comandos_diccionario[14].name, "shutdown");
	strcpy(comandos_diccionario[14].descripcion, "Apaga una interfaz para detener el tráfico a través de ella.");
	strcpy(comandos_diccionario[14].ejemplo, "Router(config-if)# shutdown");
	
	strcpy(comandos_diccionario[15].name, "no shutdown");
	strcpy(comandos_diccionario[15].descripcion, "Enciende una interfaz previamente apagada para permitir el tráfico.");
	strcpy(comandos_diccionario[15].ejemplo, "Router(config-if)# no shutdown");
	
	strcpy(comandos_diccionario[16].name, "show ip route");
	strcpy(comandos_diccionario[16].descripcion, "Muestra la tabla de enrutamiento del dispositivo con las rutas configuradas.");
	strcpy(comandos_diccionario[16].ejemplo, "Router# show ip route");
	
	strcpy(comandos_diccionario[17].name, "copy running-config startup-config");
	strcpy(comandos_diccionario[17].descripcion, "Guarda la configuración en ejecución en la configuración de inicio para que se mantenga después\n de reiniciar.");
	strcpy(comandos_diccionario[17].ejemplo, "Router# copy running-config startup-config");
	
	strcpy(comandos_diccionario[18].name, "show interfaces");
	strcpy(comandos_diccionario[18].descripcion, "Muestra información detallada sobre las interfaces del dispositivo, incluyendo estado y estadísticas.");
	strcpy(comandos_diccionario[18].ejemplo, "Router# show interfaces");
	
	strcpy(comandos_diccionario[19].name, "ip access-group");
	strcpy(comandos_diccionario[19].descripcion, "Aplica una lista de acceso a una interfaz para controlar el tráfico entrante o saliente.");
	strcpy(comandos_diccionario[19].ejemplo, "Router(config-if)# ip access-group 1 in");
	
	strcpy(comandos_diccionario[20].name, "clear counters");
	strcpy(comandos_diccionario[20].descripcion, "Restablece los contadores de estadísticas en las interfaces del dispositivo.");
	strcpy(comandos_diccionario[20].ejemplo, "Router# clear counters");
	
	strcpy(comandos_diccionario[21].name, "show arp");
	strcpy(comandos_diccionario[21].descripcion, "Muestra la tabla ARP del dispositivo que relaciona direcciones IP con direcciones MAC.");
	strcpy(comandos_diccionario[21].ejemplo, "Router# show arp");
	
	strcpy(comandos_diccionario[22].name, "ip nat inside source");
	strcpy(comandos_diccionario[22].descripcion, "Configura una regla de traducción de direcciones para el servicio de traducción de direcciones de red (NAT).");
	strcpy(comandos_diccionario[22].ejemplo, "Router(config)# ip nat inside source static 192.168.1.10 203.0.113.5");
	
	strcpy(comandos_diccionario[23].name, "show version");
	strcpy(comandos_diccionario[23].descripcion, "Muestra información detallada sobre la versión y configuración del dispositivo.");
	strcpy(comandos_diccionario[23].ejemplo, "Router# show version");
	
	strcpy(comandos_diccionario[24].name, "clock set");
	strcpy(comandos_diccionario[24].descripcion, "Configura la fecha y hora en el dispositivo.");
	strcpy(comandos_diccionario[24].ejemplo, "Router(config)# clock set 13:45:00 July 15 2023");
	
	strcpy(comandos_diccionario[25].name, "show access-lists");
	strcpy(comandos_diccionario[25].descripcion, "Muestra las listas de acceso configuradas en el dispositivo.");
	strcpy(comandos_diccionario[25].ejemplo, "Router# show access-lists");
	
	strcpy(comandos_diccionario[26].name, "debug");
	strcpy(comandos_diccionario[26].descripcion, "Habilita la depuración de eventos y mensajes para diagnóstico y resolución de problemas.");
	strcpy(comandos_diccionario[26].ejemplo, "Router# debug ip routing");
	
	strcpy(comandos_diccionario[27].name, "show interfaces status");
	strcpy(comandos_diccionario[27].descripcion, "Muestra el estado de las interfaces, incluyendo si están arriba o abajo.");
	strcpy(comandos_diccionario[27].ejemplo, "Switch# show interfaces status");
	
	strcpy(comandos_diccionario[28].name, "show ip bgp summary");
	strcpy(comandos_diccionario[28].descripcion, "Muestra información resumida sobre el estado de las sesiones BGP (Border Gateway Protocol).");
	strcpy(comandos_diccionario[28].ejemplo, "Router# show ip bgp summary");
	
	strcpy(comandos_diccionario[29].name, "show crypto isakmp sa");
	strcpy(comandos_diccionario[29].descripcion, "Muestra las asociaciones de seguridad ISAKMP (Internet Security Association and Key Management Protocol).");
	strcpy(comandos_diccionario[29].ejemplo, "Router# show crypto isakmp sa");
	
	strcpy(comandos_diccionario[30].name, "show ip ospf neighbor");
	strcpy(comandos_diccionario[30].descripcion, "Muestra información sobre vecinos OSPF (Open Shortest Path First) en el dispositivo.");
	strcpy(comandos_diccionario[30].ejemplo, "Router# show ip ospf neighbor");
	
	strcpy(comandos_diccionario[31].name, "copy tftp flash");
	strcpy(comandos_diccionario[31].descripcion, "Copia archivos desde un servidor TFTP (Trivial File Transfer Protocol) al almacenamiento flash del dispositivo.");
	strcpy(comandos_diccionario[31].ejemplo, "Router# copy tftp flash");
	
	strcpy(comandos_diccionario[32].name, "show mac address-table");
	strcpy(comandos_diccionario[32].descripcion, "Muestra la tabla de direcciones MAC utilizada para el reenvío de tráfico Ethernet.");
	strcpy(comandos_diccionario[32].ejemplo, "Switch# show mac address-table");
	
	strcpy(comandos_diccionario[33].name, "ip dhcp pool");
	strcpy(comandos_diccionario[33].descripcion, "Configura un pool DHCP para asignar direcciones IP a dispositivos en la red.");
	strcpy(comandos_diccionario[33].ejemplo, "Router(config)# ip dhcp pool MiPool");
	
	strcpy(comandos_diccionario[34].name, "show ip eigrp topology");
	strcpy(comandos_diccionario[34].descripcion, "Muestra información sobre la topología EIGRP (Enhanced Interior Gateway Routing Protocol).");
	strcpy(comandos_diccionario[34].ejemplo, "Router# show ip eigrp topology");
	
	strcpy(comandos_diccionario[35].name, "interface Vlan");
	strcpy(comandos_diccionario[35].descripcion, "Permite configurar una interfaz de VLAN en un switch para la segmentación de redes.");
	strcpy(comandos_diccionario[35].ejemplo, "Switch(config)# interface Vlan10");
	
	strcpy(comandos_diccionario[36].name, "show ip route ospf");
	strcpy(comandos_diccionario[36].descripcion, "Muestra la tabla de enrutamiento OSPF utilizada para la toma de decisiones de enrutamiento.");
	strcpy(comandos_diccionario[36].ejemplo, "Router# show ip route ospf");
	
	strcpy(comandos_diccionario[37].name, "ip access-list extended");
	strcpy(comandos_diccionario[37].descripcion, "Permite configurar una lista de acceso extendida para controlar el tráfico de red con reglas más detalladas.");
	strcpy(comandos_diccionario[37].ejemplo, "Router(config)# ip access-list extended MiLista");
	
	strcpy(comandos_diccionario[38].name, "show ip route static");
	strcpy(comandos_diccionario[38].descripcion, "Muestra la tabla de enrutamiento estático con las rutas configuradas manualmente.");
	strcpy(comandos_diccionario[38].ejemplo, "Router# show ip route static");
	
	strcpy(comandos_diccionario[39].name, "username");
	strcpy(comandos_diccionario[39].descripcion, "Permite configurar un nombre de usuario en un dispositivo para autenticación y control de acceso.");
	strcpy(comandos_diccionario[39].ejemplo, "Router(config)# username Usuario privilege 15 secret Contraseña");
	
	strcpy(comandos_diccionario[40].name, "show interfaces description");
	strcpy(comandos_diccionario[40].descripcion, "Muestra una descripción de las interfaces, lo que facilita la identificación de las conexiones.");
	strcpy(comandos_diccionario[40].ejemplo, "Router# show interfaces description");
	
	strcpy(comandos_diccionario[41].name, "ip nat");
	strcpy(comandos_diccionario[41].descripcion, "Permite configurar la traducción de direcciones de red (NAT) para permitir el acceso a Internet.");
	strcpy(comandos_diccionario[41].ejemplo, "Router(config)# ip nat inside source list 1 interface GigabitEthernet0/0 overload");
	
	strcpy(comandos_diccionario[42].name, "show ip ospf interface");
	strcpy(comandos_diccionario[42].descripcion, "Muestra información detallada sobre las interfaces utilizadas por OSPF.");
	strcpy(comandos_diccionario[42].ejemplo, "Router# show ip ospf interface");
	
	strcpy(comandos_diccionario[43].name, "copy running-config tftp");
	strcpy(comandos_diccionario[43].descripcion, "Copia la configuración en ejecución a un servidor TFTP para su respaldo o análisis.");
	strcpy(comandos_diccionario[43].ejemplo, "Router# copy running-config tftp");
	
	strcpy(comandos_diccionario[44].name, "ip access-list standard");
	strcpy(comandos_diccionario[44].descripcion, "Permite configurar una lista de acceso estándar para controlar el tráfico de red.");
	strcpy(comandos_diccionario[44].ejemplo, "Router(config)# ip access-list standard MiLista");
	
	strcpy(comandos_diccionario[45].name, "show ip bgp neighbors");
	strcpy(comandos_diccionario[45].descripcion, "Muestra información detallada sobre los vecinos BGP (Border Gateway Protocol).");
	strcpy(comandos_diccionario[45].ejemplo, "Router# show ip bgp neighbors");
	
	strcpy(comandos_diccionario[46].name, "show ip route connected");
	strcpy(comandos_diccionario[46].descripcion, "Muestra las rutas directamente conectadas en la tabla de enrutamiento IP.");
	strcpy(comandos_diccionario[46].ejemplo, "Router# show ip route connected");
	
	strcpy(comandos_diccionario[47].name, "access-list extended");
	strcpy(comandos_diccionario[47].descripcion, "Permite configurar una lista de acceso extendida para controlar el tráfico de red detalladamente.");
	strcpy(comandos_diccionario[47].ejemplo, "Router(config)# access-list extended MiLista");
	
	strcpy(comandos_diccionario[48].name, "show spanning-tree");
	strcpy(comandos_diccionario[48].descripcion, "Muestra información sobre el protocolo Spanning Tree utilizado en redes Ethernet.");
	strcpy(comandos_diccionario[48].ejemplo, "Switch# show spanning-tree");
	
	strcpy(comandos_diccionario[49].name, "interface Loopback");
	strcpy(comandos_diccionario[49].descripcion, "Permite configurar una interfaz de bucle virtual utilizada para diversas aplicaciones.");
	strcpy(comandos_diccionario[49].ejemplo, "Router(config)# interface Loopback0");
	
	strcpy(comandos_diccionario[50].name, "show ip nat translations");
	strcpy(comandos_diccionario[50].descripcion, "Muestra una lista de traducciones NAT (Network Address Translation) activas en el dispositivo.");
	strcpy(comandos_diccionario[50].ejemplo, "Router# show ip nat translations");
	
	strcpy(comandos_diccionario[51].name, "show ip bgp routes");
	strcpy(comandos_diccionario[51].descripcion, "Muestra las rutas BGP (Border Gateway Protocol) en la tabla de enrutamiento.");
	strcpy(comandos_diccionario[51].ejemplo, "Router# show ip bgp routes");
	
	strcpy(comandos_diccionario[52].name, "interface Port-channel");
	strcpy(comandos_diccionario[52].descripcion, "Permite configurar una interfaz de agregación de enlaces para unir múltiples puertos.");
	strcpy(comandos_diccionario[52].ejemplo, "Switch(config)# interface Port-channel1");
	
	strcpy(comandos_diccionario[53].name, "show ip route rip");
	strcpy(comandos_diccionario[53].descripcion, "Muestra la tabla de enrutamiento RIP (Routing Information Protocol) en el dispositivo.");
	strcpy(comandos_diccionario[53].ejemplo, "Router# show ip route rip");
	
	strcpy(comandos_diccionario[54].name, "ip dhcp pool");
	strcpy(comandos_diccionario[54].descripcion, "Configura un pool DHCP para asignar direcciones IP a dispositivos en la red.");
	strcpy(comandos_diccionario[54].ejemplo, "Router(config)# ip dhcp pool MiPool");
	
	strcpy(comandos_diccionario[55].name, "show ip bgp summary");
	strcpy(comandos_diccionario[55].descripcion, "Muestra un resumen del estado de las sesiones BGP en el dispositivo.");
	strcpy(comandos_diccionario[55].ejemplo, "Router# show ip bgp summary");
	
	strcpy(comandos_diccionario[56].name, "show ip route ospf");
	strcpy(comandos_diccionario[56].descripcion, "Muestra la tabla de enrutamiento OSPF (Open Shortest Path First) en el dispositivo.");
	strcpy(comandos_diccionario[56].ejemplo, "Router# show ip route ospf");
	
	strcpy(comandos_diccionario[57].name, "ip access-group");
	strcpy(comandos_diccionario[57].descripcion, "Aplica una lista de acceso a una interfaz para controlar el tráfico entrante o saliente.");
	strcpy(comandos_diccionario[57].ejemplo, "Router(config-if)# ip access-group 1 in");
	
	strcpy(comandos_diccionario[58].name, "clear counters");
	strcpy(comandos_diccionario[58].descripcion, "Restablece los contadores de estadísticas en las interfaces del dispositivo.");
	strcpy(comandos_diccionario[58].ejemplo, "Router# clear counters");
	
	strcpy(comandos_diccionario[59].name, "show ip bgp neighbors");
	strcpy(comandos_diccionario[59].descripcion, "Muestra información detallada sobre los vecinos BGP (Border Gateway Protocol).");
	strcpy(comandos_diccionario[59].ejemplo, "Router# show ip bgp neighbors");
	
	strcpy(comandos_diccionario[60].name, "show ip route static");
	strcpy(comandos_diccionario[60].descripcion, "Muestra la tabla de enrutamiento estático con las rutas configuradas manualmente.");
	strcpy(comandos_diccionario[60].ejemplo, "Router# show ip route static");
	
	strcpy(comandos_diccionario[61].name, "show interfaces description");
	strcpy(comandos_diccionario[61].descripcion, "Muestra una descripción de las interfaces, lo que facilita la identificación de las conexiones.");
	strcpy(comandos_diccionario[61].ejemplo, "Router# show interfaces description");
	
	strcpy(comandos_diccionario[62].name, "ip nat inside source");
	strcpy(comandos_diccionario[62].descripcion, "Configura una regla de traducción de direcciones para el servicio de traducción de direcciones de red (NAT).");
	strcpy(comandos_diccionario[62].ejemplo, "Router(config)# ip nat inside source static 192.168.1.10 203.0.113.5");
	
	strcpy(comandos_diccionario[63].name, "show ip ospf interface");
	strcpy(comandos_diccionario[63].descripcion, "Muestra información detallada sobre las interfaces utilizadas por OSPF.");
	strcpy(comandos_diccionario[63].ejemplo, "Router# show ip ospf interface");
	
	strcpy(comandos_diccionario[64].name, "copy running-config tftp");
	strcpy(comandos_diccionario[64].descripcion, "Copia la configuración en ejecución a un servidor TFTP para su respaldo o análisis.");
	strcpy(comandos_diccionario[64].ejemplo, "Router# copy running-config tftp");
	
	strcpy(comandos_diccionario[65].name, "show ip rip database");
	strcpy(comandos_diccionario[65].descripcion, "Muestra la base de datos RIP (Routing Information Protocol) en el dispositivo.");
	strcpy(comandos_diccionario[65].ejemplo, "Router# show ip rip database");
	
	strcpy(comandos_diccionario[66].name, "banner motd");
	strcpy(comandos_diccionario[66].descripcion, "Configura un mensaje del día (MOTD) que se muestra cuando se inicia la sesión en el dispositivo.");
	strcpy(comandos_diccionario[66].ejemplo, "Router(config)# banner motd #Mensaje de bienvenida#");
	
	strcpy(comandos_diccionario[67].name, "show ip eigrp neighbors");
	strcpy(comandos_diccionario[67].descripcion, "Muestra información detallada sobre los vecinos EIGRP (Enhanced Interior Gateway Routing Protocol).");
	strcpy(comandos_diccionario[67].ejemplo, "Router# show ip eigrp neighbors");
	
	strcpy(comandos_diccionario[68].name, "ip nat inside");
	strcpy(comandos_diccionario[68].descripcion, "Configura una interfaz como interfaz interna para NAT (Network Address Translation).");
	strcpy(comandos_diccionario[68].ejemplo, "Router(config)# interface GigabitEthernet0/0\nRouter(config-if)# ip nat inside");
	
	strcpy(comandos_diccionario[69].name, "show ip route bgp");
	strcpy(comandos_diccionario[69].descripcion, "Muestra la tabla de enrutamiento BGP (Border Gateway Protocol) en el dispositivo.");
	strcpy(comandos_diccionario[69].ejemplo, "Router# show ip route bgp");
	
	strcpy(comandos_diccionario[70].name, "interface Vlan");
	strcpy(comandos_diccionario[70].descripcion, "Permite configurar una interfaz de VLAN en un switch para la segmentación de redes.");
	strcpy(comandos_diccionario[70].ejemplo, "Switch(config)# interface Vlan10");
	
	strcpy(comandos_diccionario[71].name, "show ip eigrp topology");
	strcpy(comandos_diccionario[71].descripcion, "Muestra información sobre la topología EIGRP (Enhanced Interior Gateway Routing Protocol).");
	strcpy(comandos_diccionario[71].ejemplo, "Router# show ip eigrp topology");
	
	strcpy(comandos_diccionario[72].name, "ip access-list extended");
	strcpy(comandos_diccionario[72].descripcion, "Permite configurar una lista de acceso extendida para controlar el tráfico de red con reglas detalladas.");
	strcpy(comandos_diccionario[72].ejemplo, "Router(config)# ip access-list extended MiLista");
	
	strcpy(comandos_diccionario[73].name, "show cdp neighbors");
	strcpy(comandos_diccionario[73].descripcion, "Muestra información sobre los vecinos descubiertos a través del protocolo CDP (Cisco Discovery Protocol).");
	strcpy(comandos_diccionario[73].ejemplo, "Router# show cdp neighbors");
	
	strcpy(comandos_diccionario[74].name, "show ip route rip");
	strcpy(comandos_diccionario[74].descripcion, "Muestra la tabla de enrutamiento RIP (Routing Information Protocol) en el dispositivo.");
	strcpy(comandos_diccionario[74].ejemplo, "Router# show ip route rip");
	
	strcpy(comandos_diccionario[75].name, "ip access-list standard");
	strcpy(comandos_diccionario[75].descripcion, "Permite configurar una lista de acceso estándar para controlar el tráfico de red.");
	strcpy(comandos_diccionario[75].ejemplo, "Router(config)# ip access-list standard MiLista");
	
	strcpy(comandos_diccionario[76].name, "show mac address-table");
	strcpy(comandos_diccionario[76].descripcion, "Muestra la tabla de direcciones MAC utilizada para el reenvío de tráfico Ethernet.");
	strcpy(comandos_diccionario[76].ejemplo, "Switch# show mac address-table");
	
	strcpy(comandos_diccionario[77].name, "interface Loopback");
	strcpy(comandos_diccionario[77].descripcion, "Permite configurar una interfaz de bucle virtual utilizada para diversas aplicaciones.");
	strcpy(comandos_diccionario[77].ejemplo, "Router(config)# interface Loopback0");
	
	strcpy(comandos_diccionario[78].name, "show ip nat translations");
	strcpy(comandos_diccionario[78].descripcion, "Muestra una lista de traducciones NAT (Network Address Translation) activas en el dispositivo.");
	strcpy(comandos_diccionario[78].ejemplo, "Router# show ip nat translations");
	
	strcpy(comandos_diccionario[79].name, "show ip eigrp topology all-links");
	strcpy(comandos_diccionario[79].descripcion, "Muestra información sobre la topología EIGRP, incluyendo todas las rutas posibles.");
	strcpy(comandos_diccionario[79].ejemplo, "Router# show ip eigrp topology all-links");
	
	strcpy(comandos_diccionario[80].name, "ip dhcp excluded-address");
	strcpy(comandos_diccionario[80].descripcion, "Excluye direcciones IP específicas de ser asignadas por un servidor DHCP en una red.");
	strcpy(comandos_diccionario[80].ejemplo, "Router(config)# ip dhcp excluded-address 192.168.1.1 192.168.1.10");
	
	strcpy(comandos_diccionario[81].name, "show ip ospf database");
	strcpy(comandos_diccionario[81].descripcion, "Muestra la base de datos OSPF (Open Shortest Path First) en el dispositivo.");
	strcpy(comandos_diccionario[81].ejemplo, "Router# show ip ospf database");
	
	strcpy(comandos_diccionario[82].name, "ip dhcp pool");
	strcpy(comandos_diccionario[82].descripcion, "Configura un pool DHCP para asignar direcciones IP a dispositivos en la red.");
	strcpy(comandos_diccionario[82].ejemplo, "Router(config)# ip dhcp pool MiPool");
	
	strcpy(comandos_diccionario[83].name, "show ip bgp summary");
	strcpy(comandos_diccionario[83].descripcion, "Muestra un resumen del estado de las sesiones BGP en el dispositivo.");
	strcpy(comandos_diccionario[83].ejemplo, "Router# show ip bgp summary");
	
	strcpy(comandos_diccionario[84].name, "show ip route ospf");
	strcpy(comandos_diccionario[84].descripcion, "Muestra la tabla de enrutamiento OSPF (Open Shortest Path First) en el dispositivo.");
	strcpy(comandos_diccionario[84].ejemplo, "Router# show ip route ospf");
	
	strcpy(comandos_diccionario[85].name, "ip access-group");
	strcpy(comandos_diccionario[85].descripcion, "Aplica una lista de acceso a una interfaz para controlar el tráfico entrante o saliente.");
	strcpy(comandos_diccionario[85].ejemplo, "Router(config-if)# ip access-group 1 in");
	
	strcpy(comandos_diccionario[86].name, "clear counters");
	strcpy(comandos_diccionario[86].descripcion, "Restablece los contadores de estadísticas en las interfaces del dispositivo.");
	strcpy(comandos_diccionario[86].ejemplo, "Router# clear counters");
	
	strcpy(comandos_diccionario[87].name, "show ip bgp neighbors");
	strcpy(comandos_diccionario[87].descripcion, "Muestra información detallada sobre los vecinos BGP (Border Gateway Protocol).");
	strcpy(comandos_diccionario[87].ejemplo, "Router# show ip bgp neighbors");
	
	strcpy(comandos_diccionario[88].name, "show ip route static");
	strcpy(comandos_diccionario[88].descripcion, "Muestra la tabla de enrutamiento estático con las rutas configuradas manualmente.");
	strcpy(comandos_diccionario[88].ejemplo, "Router# show ip route static");
	
	strcpy(comandos_diccionario[89].name, "show ip route rip");
	strcpy(comandos_diccionario[89].descripcion, "Muestra la tabla de enrutamiento RIP (Routing Information Protocol) en el dispositivo.");
	strcpy(comandos_diccionario[89].ejemplo, "Router# show ip route rip");
	
	strcpy(comandos_diccionario[90].name, "ip access-list standard");
	strcpy(comandos_diccionario[90].descripcion, "Permite configurar una lista de acceso estándar para controlar el tráfico de red.");
	strcpy(comandos_diccionario[90].ejemplo, "Router(config)# ip access-list standard MiLista");
	
	strcpy(comandos_diccionario[91].name, "show mac address-table");
	strcpy(comandos_diccionario[91].descripcion, "Muestra la tabla de direcciones MAC utilizada para el reenvío de tráfico Ethernet.");
	strcpy(comandos_diccionario[91].ejemplo, "Switch# show mac address-table");
	
	strcpy(comandos_diccionario[92].name, "interface Loopback");
	strcpy(comandos_diccionario[92].descripcion, "Permite configurar una interfaz de bucle virtual utilizada para diversas aplicaciones.");
	strcpy(comandos_diccionario[92].ejemplo, "Router(config)# interface Loopback0");
	
	strcpy(comandos_diccionario[93].name, "show ip nat translations");
	strcpy(comandos_diccionario[93].descripcion, "Muestra una lista de traducciones NAT (Network Address Translation) activas en el dispositivo.");
	strcpy(comandos_diccionario[93].ejemplo, "Router# show ip nat translations");
	
	strcpy(comandos_diccionario[94].name, "show ip eigrp topology all-links");
	strcpy(comandos_diccionario[94].descripcion, "Muestra información sobre la topología EIGRP, incluyendo todas las rutas posibles.");
	strcpy(comandos_diccionario[94].ejemplo, "Router# show ip eigrp topology all-links");
	
	strcpy(comandos_diccionario[95].name, "ip dhcp excluded-address");
	strcpy(comandos_diccionario[95].descripcion, "Excluye direcciones IP específicas de ser asignadas por un servidor DHCP en una red.");
	strcpy(comandos_diccionario[95].ejemplo, "Router(config)# ip dhcp excluded-address 192.168.1.1 192.168.1.10");
	
	strcpy(comandos_diccionario[96].name, "show ip ospf database");
	strcpy(comandos_diccionario[96].descripcion, "Muestra la base de datos OSPF (Open Shortest Path First) en el dispositivo.");
	strcpy(comandos_diccionario[96].ejemplo, "Router# show ip ospf database");
	
	strcpy(comandos_diccionario[97].name, "ip dhcp pool");
	strcpy(comandos_diccionario[97].descripcion, "Configura un pool DHCP para asignar direcciones IP a dispositivos en la red.");
	strcpy(comandos_diccionario[97].ejemplo, "Router(config)# ip dhcp pool MiPool");
	
	strcpy(comandos_diccionario[98].name, "show ip bgp summary");
	strcpy(comandos_diccionario[98].descripcion, "Muestra un resumen del estado de las sesiones BGP en el dispositivo.");
	strcpy(comandos_diccionario[98].ejemplo, "Router# show ip bgp summary");
	
	strcpy(comandos_diccionario[99].name, "show ip route ospf");
	strcpy(comandos_diccionario[99].descripcion, "Muestra la tabla de enrutamiento OSPF (Open Shortest Path First) en el dispositivo.");
	strcpy(comandos_diccionario[99].ejemplo, "Router# show ip route ospf");
	
	strcpy(comandos_diccionario[100].name, "ip access-group");
	strcpy(comandos_diccionario[100].descripcion, "Aplica una lista de acceso a una interfaz para controlar el tráfico entrante o saliente.");
	strcpy(comandos_diccionario[100].ejemplo, "Router(config-if)# ip access-group 1 in");
	
	strcpy(comandos_diccionario[101].name, "clear counters");
	strcpy(comandos_diccionario[101].descripcion, "Restablece los contadores de estadísticas en las interfaces del dispositivo.");
	strcpy(comandos_diccionario[101].ejemplo, "Router# clear counters");
	
	strcpy(comandos_diccionario[102].name, "show ip bgp neighbors");
	strcpy(comandos_diccionario[102].descripcion, "Muestra información detallada sobre los vecinos BGP (Border Gateway Protocol).");
	strcpy(comandos_diccionario[102].ejemplo, "Router# show ip bgp neighbors");
	
	strcpy(comandos_diccionario[103].name, "show ip route static");
	strcpy(comandos_diccionario[103].descripcion, "Muestra la tabla de enrutamiento estático con las rutas configuradas manualmente.");
	strcpy(comandos_diccionario[103].ejemplo, "Router# show ip route static");
	
	strcpy(comandos_diccionario[104].name, "show interfaces description");
	strcpy(comandos_diccionario[104].descripcion, "Muestra una descripción de las interfaces, lo que facilita la identificación de las conexiones.");
	strcpy(comandos_diccionario[104].ejemplo, "Router# show interfaces description");
	
	strcpy(comandos_diccionario[105].name, "ip nat inside source");
	strcpy(comandos_diccionario[105].descripcion, "Configura una regla de traducción de direcciones para el servicio de traducción de direcciones de red (NAT).");
	strcpy(comandos_diccionario[105].ejemplo, "Router(config)# ip nat inside source static 192.168.1.10 203.0.113.5");
	
	strcpy(comandos_diccionario[106].name, "show ip ospf interface");
	strcpy(comandos_diccionario[106].descripcion, "Muestra información detallada sobre las interfaces utilizadas por OSPF.");
	strcpy(comandos_diccionario[106].ejemplo, "Router# show ip ospf interface");
	
	strcpy(comandos_diccionario[107].name, "copy running-config tftp");
	strcpy(comandos_diccionario[107].descripcion, "Copia la configuración en ejecución a un servidor TFTP para su respaldo.");
	strcpy(comandos_diccionario[107].ejemplo, "Router# copy running-config tftp");
	
	strcpy(comandos_diccionario[108].name, "show ip ospf neighbor");
	strcpy(comandos_diccionario[108].descripcion, "Muestra información sobre los vecinos OSPF (Open Shortest Path First) en el dispositivo.");
	strcpy(comandos_diccionario[108].ejemplo, "Router# show ip ospf neighbor");
	
	strcpy(comandos_diccionario[109].name, "show access-lists");
	strcpy(comandos_diccionario[109].descripcion, "Muestra todas las listas de acceso configuradas en el dispositivo.");
	strcpy(comandos_diccionario[109].ejemplo, "Router# show access-lists");
	
	strcpy(comandos_diccionario[110].name, "ip helper-address");
	strcpy(comandos_diccionario[110].descripcion, "Especifica la dirección IP del servidor DHCP o el servidor de tiempo que se utilizará para un interfaz.");
	strcpy(comandos_diccionario[110].ejemplo, "Router(config-if)# ip helper-address 192.168.1.2");
	
	
	
	

}

void buscar_comando(struct comandos comandos_diccionario[], int tamano_diccionario, const char *nombre_comando) {
	int encontrado = 0;
	for (int i = 0; i < tamano_diccionario; i++) {
		if (strcmp(nombre_comando, comandos_diccionario[i].name) == 0) {
			printf("\n#################################################################################################################\n");
			printf("\nComando: %s\n", comandos_diccionario[i].name);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Descripción:\n%s\n", comandos_diccionario[i].descripcion);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("Ejemplo:\n%s\n", comandos_diccionario[i].ejemplo);
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			encontrado = 1;
			break;
		}
	}
	
	
	if (!encontrado) {
		printf("\nComando no encontrado");
	}
}
void notas (){
	int num_nota, rep_nota;
	
	do {
		printf("\n[1] Asignar direcciones IP a interfaces\n[2] Subneteo con mascara fija\n[3] Subneteo con mascara variable (VLSM)\n");
		printf("[4] Crear enrutamientos\n[5] VLAN\n[6] Listas de control de acceso\n");
		scanf("%d",&num_nota);
		fflush(stdin);
		system("cls");
		
		switch(num_nota){
		case 1:
			printf("\n-----------------------------------------------------------------------------------------------------------------\n");
			printf("                                         Asignar direcciones Ip a interfaces\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nPaso 1. Acceder al modo de configuración de la interfaz\n\tComandos:\n\t1. enable (entrar en modo privilegiado)");
			printf("\n\t2. configure terminal (entrar al modo de configuración global)\n\t3. interface <id de interfaz> (acceder a la interfaz que deseas configurar)");
			printf("\n\nPaso 2. Configurar la dirección IP de la interfaz\n\tComandos:\n\t1. ip address <dirección IP> <máscara de subred> (asignar la dirección IP a la interfaz)");
			printf("\n\t2. no shutdown (habilitar la interfaz si está apagada)\n\t3. exit (salir del modo de configuración de la interfaz)");
			printf("\n\nPaso 3. Verificar la configuración\n\tComandos:\n\t1. show ip interface brief (verificar que la dirección IP se haya asignado correctamente)");
			printf("\n-----------------------------------------------------------------------------------------------------------------\n");
			break;
		case 2:
			printf("\n-----------------------------------------------------------------------------------------------------------------\n");
			printf("                     Subneteo con Máscara Fija (Ejemplo de Clase C)\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nPaso 1: Elige una dirección IP de partida y una máscara de subred fija.\n");
			printf("    Dirección IP base: 192.168.1.0\n");
			printf("    Máscara de subred fija: 255.255.255.192\n");
			printf("\nPaso 2: Convierte la máscara de subred en notación binaria.\n");
			printf("    Máscara de subred en binario: 11111111.11111111.11111111.11000000\n");
			printf("\nPaso 3: Determina la cantidad de bits de red y de host.\n");
			printf("    Bits de red: 26\n");
			printf("    Bits de host: 6\n");
			printf("\nPaso 4: Calcula el número de subredes posibles.\n");
			printf("    Número de subredes posibles: 64\n");
			printf("\nPaso 5: Calcula el número de hosts por subred.\n");
			printf("    Número de hosts por subred: 62\n");
			printf("\nPaso 6: Identifica las subredes.\n");
			printf("    Primera subred: 192.168.1.0\n");
			printf("    Segunda subred: 192.168.1.64\n");
			printf("    Y así sucesivamente...\n");
			printf("\nPaso 7: Calcula las direcciones de red y de broadcast para cada subred.\n");
			printf("    Dirección de red de la primera subred: 192.168.1.0\n");
			printf("    Dirección de broadcast de la primera subred: 192.168.1.63\n");
			printf("    Y así sucesivamente...\n");
			printf("\nPaso 8: Asigna direcciones IP a los hosts dentro de cada subred.\n");
			printf("	Dentro de cada subred, asigna direcciones IP a los hosts en el rango disponible.\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			break;
		case 3:
			printf("\n-----------------------------------------------------------------------------------------------------------------\n");
			printf("                    Subneteo VLSM (Variable Length Subnet Masking)\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nPaso 1: Identifica las necesidades de cada segmento de red.\n");
			printf("    Ejemplo:\n");
			printf("    - Red A necesita 20 hosts.\n");
			printf("    - Red B necesita 8 hosts.\n");
			printf("    - Red C necesita 4 hosts.\n");
			printf("\nPaso 2: Convierte las necesidades en potencias de 2 y determina las máscaras.\n");
			printf("    - Para Red A, necesitas al menos 32 direcciones (2^5), por lo que necesitas una máscara /27.\n");
			printf("    - Para Red B, necesitas al menos 16 direcciones (2^4), por lo que necesitas una máscara /28.\n");
			printf("    - Para Red C, necesitas al menos 8 direcciones (2^3), por lo que necesitas una máscara /29.\n");
			printf("\nPaso 3: Comienza con una dirección IP de partida y la máscara más grande.\n");
			printf("    Dirección IP base: 192.168.1.0\n");
			printf("    Máscara inicial: 255.255.255.0 (/24)\n");
			printf("\nPaso 4: Asigna la primera subred (Red A) usando la máscara más pequeña.\n");
			printf("    - Subred A: 192.168.1.0/27 (32 direcciones)\n");
			printf("\nPaso 5: Asigna la segunda subred (Red B) usando la siguiente máscara.\n");
			printf("    - Subred B: 192.168.1.32/28 (16 direcciones)\n");
			printf("\nPaso 6: Asigna la tercera subred (Red C) usando la siguiente máscara.\n");
			printf("    - Subred C: 192.168.1.48/29 (8 direcciones)\n");
			printf("\nPaso 7: Asigna direcciones IP a los hosts dentro de cada subred.\n");
			printf("    - Red A: 192.168.1.1 - 192.168.1.30 (31-62 son hosts)\n");
			printf("    - Red B: 192.168.1.33 - 192.168.1.46 (34-45 son hosts)\n");
			printf("    - Red C: 192.168.1.49 - 192.168.1.54 (50-53 son hosts)\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			break;
		case 4:
			printf("\n-----------------------------------------------------------------------------------------------------------------\n");
			printf("                                               Enrutamiento estático\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nPaso 1. Acceder al modo de configuración del router\n\tComandos:\n\t1. enable (entrar en modo privilegiado)");
			printf("\n\t2. configure terminal (entrar al modo de configuración global)\n\nPaso 2. Paso 2. Agregar una ruta estática (etse paso se repite cuantas veces sea necesario");
			printf("\n\tComandos:\n\t1. ip route <red de destino> <máscara de subred> <siguiente salto> (agregar una ruta estática)");
			printf("\n\nPaso 3. Verificar la configuración\n\tComandos\n\t1. show ip route (verificar que la ruta estática se haya configurado correctamente)");
			printf("\n\n-----------------------------------------------------------------------------------------------------------------\n");
			printf("                                           Enrutamiento dinámico con RIP\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nPaso 1. Acceder al modo de configuración de enrutamiento dinámico\n\tComandos:\n\t1. enable (entrar en modo privilegiado)\n\t2. configure terminal (entrar al modo de configuración global)");
			printf("\n\t3. router rip\n\tversion 2\n\t4. network <dirección de red> <máscara de subred> area <área> (agregar las redes que deseas anunciar)\n\t");
			printf("5. exit (salir del modo de configuración de enrutamiento)\n\nPaso 2. Verificar la configuración");
			printf("\n\tComandos:\n\t1. show ip route (verificar la tabla de enrutamiento)"); 
			printf("\n-----------------------------------------------------------------------------------------------------------------\n");
			break;
		case 5:
			printf("\n-----------------------------------------------------------------------------------------------------------------\n");
			printf("                                                          VLAN\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nPaso 1. Crear VLANs en cada Switch\n\tComandos:\n\t1. enable\n\t2. configure terminal\n\t3. vlan <número de VLAN>\n");
			printf("\t4. name <nombre>\n\t6. end\n\t5. show vlan brief (verificar que se hayan creado correctamente)\n\nPaso 2. Asignar puertos de acceso (los que tienen contacto directo con el usuario)");
			printf("\n\tComandos:\n\t1. interface <id de interfaz>\n\t2. swicthport mode access\n\t3. switchport access vlan <número de VLAN>\n\t4. switchport port-security (agrega seguridad al puerto)");
			printf("\n\t5. Exit\n\nPaso 3. Configurar puertos troncales (los que interconectan switch con router o con otro switch)\n\tComandos:\n\t1. interface <id de interfaz>");
			printf("\n\t2. switchport mode trunk\n\t3. switchport trunk allowed vlan <vlans>\n\t4. switchport trunk native vlan <vlan>\n\t5. exit\n\nPaso 4. Configurar y encapsular VLANs en el router (nunca olvidarse de las nativas)");
			printf("\n\tComandos:\n\t1. enable\n\t2. configure terminal\n\t3. interface <id de interfaz>\n\t4. no shut\n\t5. interface <id de subinterfaz>\n\t6. encapsulation dot1q <num_vlan>");
			printf("\n\t7. ip address <dirección IP de Gateway> <Máscara de subred>\n\t8. exit\n\t9. interface <id de subinterfaz nativa>\n\t10. encapsulation dot1q <num_vlan_nat> native\n\t11. ip address <dirección_ip> <máscara>");
			printf("\n\t12. exit\n\nPaso 5. Configurar direcciones IP de los clientes\n\tPasos:\n\t1. Se configura dirección IP dentro del rango de la subred\n\t2. Se le asigna máscara conforme a la subred\n\t3. Se configura el gateway\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			break;
		default:
			printf("\nOpcion no disponible por el momento\n");
		}
		
		printf("\n¿Quieres consultar otras notas?\n[1] Si\n[2] No\n");
		scanf("%d", &rep_nota);
	} while(rep_nota == 1);
}
