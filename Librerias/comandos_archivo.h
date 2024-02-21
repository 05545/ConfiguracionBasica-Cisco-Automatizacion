//Comandos que se escriben en archivo

void logo_archivo(const char datos[12]){
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	
	fprintf(archivo, "       @@.                                                  %%@@ \n");
	fprintf(archivo, "      %%@  &@@&                                         ,@@@/ %%@\n");
	fprintf(archivo, "      @@  %%   @@@*                                  &@@,   @ *@, \n");
	fprintf(archivo, "     @@  @@@@*  /@@,                            %%@@   &@@@%% *@,  \n");
	fprintf(archivo, "      #@  (@(@@&@   @@&    %%@@@@@@@@@@@@@@(    @@/  %%#@@#&@* %%@ \n");
	fprintf(archivo, "       @/ /((.((((/#  %%@&%%                  @@@.  #((((# %%(  @@ \n");
	fprintf(archivo, "       @@  ( .          .#                  @           #.#  @%%                       \n");
	fprintf(archivo, "       /@  *             @*                @(               &&             .s5SSSs.  .s5SSSs.  .s5SSSSs. .s5SSSs.  .s5SSSs.  .s    s.              \n");
	fprintf(archivo, "        &&                 %%              @                 &%%                  SS.       SS.    SSS          SS.       SS.       SS.              \n");
	fprintf(archivo, "        %%&. @@@@@@@@@  @@@& //          @  @@@@  @@@@@@@@/ %%&.            sS    `:; sS    S%%S    S%%S    sS    `:; sS    S%%S sSs.  S%%S                \n");
	fprintf(archivo, "       /%%.                                                  %%%%            sS    `:; sS    S%%S    S%%S    sS    `:; sS    S%%S sSs.  S%%S   \n");
	fprintf(archivo, "       %%%%              &@%%                  @@(              %%%%           SS        SS    S%%S    S%%S    SS        SS    S%%S SS`S. S%%S         \n");
	fprintf(archivo, "      %%%%         @ @@(    /@              @ ,   @@@ @        *%%,          SS        SSSs. S%%S    S%%S    SS        SS    S%%S SS `S.S%%S    \n");
	fprintf(archivo, "      ##%%.        @ @@.%%@@@ #    /((*    %% @@@,#@#*@        %%.##          SS        SS    S%%S    S%%S    SS        SS    S%%S SS  `sS%%S    \n");
	fprintf(archivo, "      ##  ,@                   ((((((((                  ,@   #%%          SS        SS    `:;    `:;    SS        SS    `:; SS    `:;   \n");
	fprintf(archivo, "      #%%    %% #/              (((((((((*              @  @    #/          SS    ;,. SS    ;,.    ;,.    SS    ;,. SS    ;,. SS    ;,.  \n");
	fprintf(archivo, "      ,#.         %%@%%  *@,    (/      (#    #@   @@          ##           `:;;;;;:' :;    ;:'    ;:'    `:;;;;;:' `:;;;;;:' :;    ;:'     \n");
	fprintf(archivo, "       #( // ##  ,@  @    &@@@    //    @@@,   */ .@,  @  @  ##            \n");
	fprintf(archivo, "        ##    %%@@*    @@@  @@@@@@   *@@@@@@ ,@@(    %%@@*    #%%             \n");
	fprintf(archivo, "         /#(/  &@/    @@@, @@@@@@*  %%@@@@@& (@@%%   .#@*  &##.               \n");
	fprintf(archivo, "            ##      @. #@ #@@@@&#    (@@@@@  @, %%@     /#%%                 \n");
	fprintf(archivo, "              #####@ //    .*,   #@@/   ,*     &  &####*                    \n");
	fprintf(archivo, "                   .####/#####%%&@@@@@@&%%#####/##(#                        \n");
	fprintf(archivo, "\n###########################################################################################################################################################\n\n");
	fprintf(archivo, "                                                    Programa propiedad de @05545 en GitHub\n");
	fprintf(archivo, "\n###########################################################################################################################################################\n\n");
	fprintf(archivo, "\n\n\n");
	
	fclose(archivo);
}

void escribir_configuraciones_en_archivo(int n, const char datos[12]) {
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para escribir.\n");
	} else {
		if (1) {
			fprintf(archivo, "\n                                         Configuracion basica generada\n");
			fprintf(archivo, "#################################################################################################################\n\n");
			fprintf(archivo, "\nenable\n");
			fprintf(archivo, "configure terminal\n");
			fprintf(archivo, "hostname %s\n", Nombre_dispositivo);
			fprintf(archivo, "enable secret %s\n", contrasena_enablesecret);
			fprintf(archivo, "line console 0\npassword %s\nlogin\nexit\n", contrasena_line0);
			fprintf(archivo, "banner motd #%s#\n", banner_motd);
			fprintf(archivo, "line vty 0 15\npassword %s\nlogin\nexit\n", contrasena_line_vty);
			fprintf(archivo, "\n#################################################################################################################\n");
		}
	}
	fclose(archivo);
}
	
void escribir_VLANs_en_archivo(int n_vlans, int numeros[], char nombres[][50], const char datos[12]) {
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para escribir.\n");
	} else {
		if (2) {
			fprintf(archivo, "\n                                              Creacion de VLANs\n");
			fprintf(archivo, "#################################################################################################################\n\n");
			for (int i = 0; i < n_vlans; i++) {
				fprintf(archivo, "vlan %d\nname %s\n", numeros[i], nombres[i]);
			}
			fprintf(archivo, "\n#################################################################################################################\n");
		}
	}
	fclose(archivo);
}
	
	
void escribir_puertos_acceso(int total_vlan, int total_numeros[], char interfaces[50][50], const char datos[12]){
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para escribir.\n");
	} else {
		if (2) {
			fprintf(archivo, "\n                                              Puertos en modo acceso\n");
			fprintf(archivo, "#################################################################################################################\n\n");
			fprintf(archivo, "\nenable\nconfigure terminal\n");
			for (int i = 0; i < total_vlan; i++) {
				fprintf(archivo, "interface range %s\n", interfaces[i]);
				fprintf(archivo, "switchport mode access\nswitchport access vlan %d\nswitchport port-security\n", total_numeros[i]);
			}
			fprintf(archivo, "exit\n\n");
			fprintf(archivo, "\n#################################################################################################################");
		}
	}
	fclose(archivo);
}
void escribir_puertos_troncales(int total_vlan, char troncales[][50], int total_numeros[], int total_tr, const char datos[12]){
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para escribir.\n");
	} else {
		fprintf(archivo, "\n\n                                              Puertos en modo troncal");
		fprintf(archivo, "\n#################################################################################################################\n\n");
		fprintf(archivo, "\nenable\nconfigure terminal\n");
		for (int i = 0; i < total_tr; i++) {
			fprintf(archivo, "interface range %s\n", troncales[i]);
			fprintf(archivo, "switchport mode trunk\n");
			fprintf(archivo, "switchport trunk allowed vlan");
			for (int j = 0; j < total_vlan; j++) {
				if (j == 0) {
					fprintf(archivo, " %d", total_numeros[j]);
					fflush(stdin);
				} else {
					fprintf(archivo, ",%d", total_numeros[j]);
					fflush(stdin);
				}
			}
			fprintf(archivo, "\nswitchport trunk native vlan 1\n");
		}
		fprintf(archivo, "exit\n\n");
		fprintf(archivo, "\n#################################################################################################################\n\n");
	}
	fclose(archivo);
}
			void escribir_encapsulamiento(int total_vlan, char interfaz_general1[12], int total_numeros1[], char ip_vlans[total_vlan][20], char mascara_vlans[total_vlan][20], const char datos[12]){
				FILE *archivo;
				sprintf(nombreArchivo, "%s.txt", datos);
				archivo = fopen(nombreArchivo, "a");
				
				if (archivo == NULL) {
					printf("No se pudo abrir el archivo para escribir.\n");
				} else  {
					fprintf(archivo, "\n\n-----------------------------------------------------------------------------------------------------------------\n");
					fprintf(archivo, "\n                                               Puertos encapsulados");
					fprintf(archivo, "\n#################################################################################################################\n\n");
					fprintf(archivo, "\nenable\nconfigure terminal\nint %s\nno shutdown\n", interfaz_general1);
					for (int i = 0; i < total_vlan; i++){
						fflush(stdin);
						fprintf(archivo, "int %s%c%d\nencapsulation dot1q %d\n", interfaz_general1, 46, total_numeros1[i], total_numeros1[i]);
						fprintf(archivo, "ip address %s %s\nexit\n", ip_vlans[i], mascara_vlans[i]);
					}
					fprintf(archivo, "\n#################################################################################################################\n\n");
				}
				fclose(archivo);
			}
				
				
				void escribir_enrutamiento(int modo_enrutamiento, int total_redes, char direcciones[][50], char mascaras[][50], char saltos[][50], const char datos[12]){
					FILE *archivo;
					sprintf(nombreArchivo, "%s.txt", datos);
					archivo = fopen(nombreArchivo, "a");
					
					if (archivo == NULL) {
						printf("No se pudo abrir el archivo para escribir.\n");
					} else  {
						if (modo_enrutamiento == 1) {
							fprintf(archivo, "\n                                               Enrutamiento estático");
							fprintf(archivo, "\n#################################################################################################################\n\n");
							fprintf(archivo, "enable\nconfigure terminal\n");
							for (int i = 0; i < total_redes; i++) {
								fprintf(archivo, "ip route %s %s %s\n", direcciones[i], mascaras[i], saltos[i]);
							}
							fprintf(archivo, "\n#################################################################################################################\n\n");
						} else if (modo_enrutamiento == 2) {
							fprintf(archivo, "\n                                               Enrutamiento dinámico");
							fprintf(archivo, "\n#################################################################################################################\n\n");
							fprintf(archivo, "enable\nconfigure terminal\n");
							fprintf(archivo, "enable\nconfigure terminal\nrouter rip\nversion 2\n");
							for (int i = 0; i < total_redes; i++) {
								fprintf(archivo, "network %s\n", direcciones[i]);
							}
							fprintf(archivo, "\n#################################################################################################################\n\n");
						} else {
							fprintf(archivo, "\nOpción no disponible por el momento");
						}
					}
					fclose(archivo);
				}
					
					void escribir_acls_redes_y_host(int num_redes_denegar, char comandos_denegar_redes[1000][1000], int cant_host_deny, char comandos_denegar_host[1000][1000], int access_list, const char datos[12]){
						FILE *archivo;
						sprintf(nombreArchivo, "%s.txt", datos);
						archivo = fopen(nombreArchivo, "a");
						
						if (archivo == NULL) {
							printf("No se pudo abrir el archivo para escribir.\n");
						} else {
							fprintf(archivo, "\n                                               Lista de control de acceso");
							fprintf(archivo, "\n#################################################################################################################\n\n");
							fprintf(archivo, "enable\nconfigure terminal\n");
							for (int i = 0; i < num_redes_denegar; i++) {
								fflush(stdin);
								fprintf(archivo, "%s\n", comandos_denegar_redes[i]);
							}
							fflush(stdin);
							for (int j = 0; j < cant_host_deny; j++) {
								fprintf(archivo, "%s\n", comandos_denegar_host[j]);
							}
							fflush(stdin);
							fprintf(archivo, "access-list %d permit any\n", access_list);
							fflush(stdout);
							fprintf(archivo, "\n#################################################################################################################\n\n");
						}
						fclose(archivo);
					}
						
						
						void escribir_acls_redes_y_host_permit(int num_redes_denegar, char comandos_denegar_redes[1000][1000], int cant_host_deny, char comandos_denegar_host[1000][1000], int access_list, const char datos[12]){
							FILE *archivo;
							sprintf(nombreArchivo, "%s.txt", datos);
							archivo = fopen(nombreArchivo, "a");
							
							if (archivo == NULL) {
								printf("No se pudo abrir el archivo para escribir.\n");
							} else {
								fprintf(archivo, "\n                                               Lista de control de acceso");
								fprintf(archivo, "\n#################################################################################################################\n\n");
								fprintf(archivo, "enable\nconfigure terminal\n");
								for (int i = 0; i < num_redes_denegar; i++) {
									fflush(stdin);
									fprintf(archivo, "%s\n", comandos_denegar_redes[i]);
								}
								fflush(stdin);
								for (int j = 0; j < cant_host_deny; j++) {
									fprintf(archivo, "%s\n", comandos_denegar_host[j]);
								}
								fflush(stdin);
								fprintf(archivo, "access-list %d deny any\n", access_list);
								fflush(stdout);
								fprintf(archivo, "\n#################################################################################################################\n\n");
							}
							fclose(archivo);
						}
							
							
							void escribir_acls_redes (int num_redes_denegar, char comandos_denegar_redes[1000][1000], int access_list, const char datos[12]){
								FILE *archivo;
								sprintf(nombreArchivo, "%s.txt", datos);
								archivo = fopen(nombreArchivo, "a");
								
								if (archivo == NULL) {
									printf("No se pudo abrir el archivo para escribir.\n");
								} else {
									fflush(stdin);
									fprintf(archivo, "\n                                               Lista de control de acceso");
									fprintf(archivo, "\n#################################################################################################################\n\n");
									fprintf(archivo, "enable\nconfigure terminal\n");
									for (int i = 0; i < num_redes_denegar; i++) {
										fprintf(archivo, "%s\n", comandos_denegar_redes[i]);
									}
									fflush(stdin);
									fprintf(archivo, "access-list %d permit any\n", access_list);
									fflush(stdout);
									fprintf(archivo, "\n#################################################################################################################\n\n");
								}
								fclose(archivo);
							}
								
								void escribir_acls_redes_permit (int num_redes_denegar, char comandos_denegar_redes[1000][1000], int access_list, const char datos[12]){
									FILE *archivo;
									sprintf(nombreArchivo, "%s.txt", datos);
									archivo = fopen(nombreArchivo, "a");
									
									if (archivo == NULL) {
										printf("No se pudo abrir el archivo para escribir.\n");
									} else {
										fflush(stdin);
										fprintf(archivo, "\n                                               Lista de control de acceso");
										fprintf(archivo, "\n#################################################################################################################\n\n");
										fprintf(archivo, "enable\nconfigure terminal\n");
										for (int i = 0; i < num_redes_denegar; i++) {
											fprintf(archivo, "%s\n", comandos_denegar_redes[i]);
										}
										fflush(stdin);
										fprintf(archivo, "access-list %d deny any\n", access_list);
										fflush(stdout);
										fprintf(archivo, "\n#################################################################################################################\n\n");
									}
									fclose(archivo);
								}
									
									
									void escribir_acls_host(int cant_host_permit, char comandos_permitir_host[1000][1000], int access_list, const char datos[12], int modo){
										FILE *archivo;
										sprintf(nombreArchivo, "%s.txt", datos);
										archivo = fopen(nombreArchivo, "a");
										
										if (archivo == NULL) {
											printf("No se pudo abrir el archivo para escribir.\n");
										} else {
											fflush(stdin);
											fprintf(archivo, "\n                                               Lista de control de acceso");
											fprintf(archivo, "\n#################################################################################################################\n\n");
											fprintf(archivo, "enable\nconfigure terminal\n");
											for (int i = 0; i < cant_host_permit; i++) {
												fprintf(archivo, "%s\n", comandos_permitir_host[i]);
											}
											fflush(stdin);
											
											if (modo == 1){
												fprintf(archivo, "access-list %d permit any\n", access_list);
												fflush(stdout);
												fprintf(archivo, "\n#################################################################################################################\n\n");			
											} else if (modo == 2){
												fprintf(archivo, "access-list %d deny any\n", access_list);
												fflush(stdout);
												fprintf(archivo, "\n#################################################################################################################\n\n");
												
											}
										}
										fclose(archivo);
									}
										
void escribir_acls_rangos_host(){
	
}

void escribir_interfaz_acl(int int_out, char interface[30], int num_access_ls, const char datos[12]){
	fflush(stdin);
											
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	fflush(stdin);
											
	if (archivo == NULL) {
	fprintf(archivo, "No se pudo abrir el archivo para escribir.\n");
	} else {
	fprintf(archivo,"\n                                               Asignacion de ACL a Puerto");
	fprintf(archivo,"\n#################################################################################################################\n\n");
	fprintf(archivo,"enable\nconfigure terminal\n");
	if(int_out == 1){
		fprintf(archivo,"interface %s\nip access-group %d in\n",interface, num_access_ls);
		fprintf(archivo,"\n#################################################################################################################\n\n");
	} else if (int_out == 2){
		fprintf(archivo,"interface %s\nip access-group %d out\n",interface, num_access_ls);
		fprintf(archivo,"\n#################################################################################################################\n\n");
		}
	}
	fclose(archivo);
}

void escribir_subneteo_mascaraFija(int octeto1, int octeto2, int octeto3, int octeto4, int cant_redes1, int octeto_manipulable, int n, int salto, const char datos[12], int hosts_por_subred[10000]){
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	
	fprintf(archivo, "\n###########################################################################################################################################################\n\n");
	fprintf(archivo, "                                                               Subredes creadas con mascara fija\n", nombre);
	fprintf(archivo, "\n###########################################################################################################################################################\n\n");
	fprintf(archivo, "\n");
	fprintf(archivo, "|  Dirección de red   |     Primera IP      |      Ultima IP      |      Broadcast      |       Gateway       |  Mascara de subred  |  Host Encontrados |");
	int octeto_extra;
	
	if (n == 2){
		fprintf(archivo, "\n");
		for(int i = 0; i < cant_redes1; i++){
			octeto_extra = octeto_manipulable;
			fprintf(archivo, "| %-4d.%-4d.%-4d.%-4d | %-4d.%-4d.%-4d.%-4d |", octeto1, octeto_manipulable, octeto3, octeto4, octeto1, octeto_manipulable, octeto3, octeto4+1);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto_extra + salto -1, 255, 254);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto_extra + salto -1, 255, 255);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto_manipulable, octeto3, octeto4 + 1);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", binarioADecimal_subneteo(masc1), binarioADecimal_subneteo(masc2), binarioADecimal_subneteo(masc3), binarioADecimal_subneteo(masc4));
			fprintf(archivo, "        %-4d       |", hosts_por_subred[i]);
			octeto_manipulable += salto;
			fprintf(archivo, "\n");
		}
	} else if (n == 3){
		fprintf(archivo, "\n");
		for(int i = 0; i < cant_redes1; i++){
			octeto_extra = octeto_manipulable;
			fprintf(archivo, "| %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_manipulable, octeto4);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_manipulable, octeto4 + 1);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_extra + salto -1, 254);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_extra + salto -1, 255);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_manipulable, octeto4 + 1);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", binarioADecimal_subneteo(masc1), binarioADecimal_subneteo(masc2), binarioADecimal_subneteo(masc3), binarioADecimal_subneteo(masc4));
			fprintf(archivo, "        %-4d       |", hosts_por_subred[i]);
			octeto_manipulable += salto;
			fprintf(archivo, "\n");
		}
	} else if (n == 4) {
		fprintf(archivo, "\n");
		for(int i = 0; i < cant_redes1; i++){
			octeto_extra = octeto_manipulable;
			fprintf(archivo, "| %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_manipulable);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_manipulable + 1);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_extra + salto -2);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_extra + salto -1);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_manipulable + 1);
			fprintf(archivo, " %-4d.%-4d.%-4d.%-4d |", binarioADecimal_subneteo(masc1), binarioADecimal_subneteo(masc2), binarioADecimal_subneteo(masc3), binarioADecimal_subneteo(masc4));
			fprintf(archivo, "        %-4d       |", hosts_por_subred[i]);
			octeto_manipulable += salto;
			fprintf(archivo, "\n");
		}
	}
	fclose(archivo);
}
void escribir_SSH(int n, const char datos[12]){
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");

	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para escribir.\n");
	} else {
		if (1) {
			fflush(stdin);
			if (n == 1){
				fprintf(archivo, "\n                                              Configuracion de SSH");
				fprintf(archivo, "\n#################################################################################################################\n\n");
				fprintf(archivo, "\nenable\nconfigure terminal\nhostname %s\nint %s", Nombre_dispositivo, interfaz);
				fprintf(archivo, "\nip address %s %s\nno shut\nexit\n", direccionIP, mascara_SSHTelnet);
				fprintf(archivo, "\nip domain-name %s\nusername %s privilege 15 secret %s", nombre_dominio, nombre_usuario, password_contrasenaRemota);
				fprintf(archivo, "\ncrypto key generate rsa\nyes\n2048\nip ssh ver 2\nenable secret %s", password_contrasenaLocal);
				fprintf(archivo, "\nline vty 0 15\ntransport input ssh\nlogin local\nexit\n");
				fprintf(archivo, "\n#################################################################################################################\n\n");
				
			} else if (n == 2) {
				fprintf(archivo, "\n                                              Configuracion de SSH");
				fprintf(archivo, "\n#################################################################################################################\n\n");
				fprintf(archivo, "\nenable\nconfigure terminal\nhostname %s\nint vlan %d", Nombre_dispositivo, id_vlan);
				fprintf(archivo, "\nip address %s %s\nno shut\nexit\n", direccionIP, mascara_SSHTelnet);
				fprintf(archivo, "\nip default-gateway %s\nip domain-name %s", direccion_gateway, nombre_dominio);
				fprintf(archivo, "\ncrypto key generate rsa\nyes\n2048\nip ssh ver 2");
				fprintf(archivo, "\nline vty 0 15\ntransport input ssh\nlogin local\nexit\n");
				fprintf(archivo, "\nusername %s privilege 15 secret %s", nombre_usuario, password_contrasenaRemota);
				fprintf(archivo, "\nenable secret %s\n", password_contrasenaLocal);
				fprintf(archivo, "\n#################################################################################################################\n\n");
			}
		}
	}
	fclose(archivo);
}
void escribir_claves_rsa(int tamano, const char datos[12]){
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para escribir.\n");
	} else {
		switch(tamano){
		case 1:
			fprintf(archivo, "\n                                                   Claves RSA generadas");
			fprintf(archivo, "\n#################################################################################################################\n\n");
			fprintf(archivo, "enable\nconfigure terminal\ncrypto key generate rsa\n512\n\n");
			fprintf(archivo, "\n#################################################################################################################\n\n");
			break;
		case 2:
			fprintf(archivo, "\n                                                   Claves RSA generadas");
			fprintf(archivo, "\n#################################################################################################################\n\n");
			fprintf(archivo, "enable\nconfigure terminal\ncrypto key generate rsa\n1024\n\n");
			fprintf(archivo, "\n#################################################################################################################\n\n");
			break;
		case 3:
			fprintf(archivo, "\n                                                   Claves RSA generadas");
			fprintf(archivo, "\n#################################################################################################################\n\n");
			fprintf(archivo, "enable\nconfigure terminal\ncrypto key generate rsa\n2048\n\n");
			fprintf(archivo, "\n#################################################################################################################\n\n");
			break;
		default: 
			printf("\nOpcion no disponible\n");
		}
	}
	fclose(archivo);
}
void escribir_DHCP(int excluidos1, int excluidos2, int cant_host_DHCP_excluir, int cant_ip_DHCP_excluir, int cant_pool, char dhcp_comand_excluded[10000][10000], char dhcp_excluded[10000][10000], char dhcp_pool[10000][10000], const char datos[12]){
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	
	fprintf(archivo, "\n###########################################################################################################################################################\n\n");
	fprintf(archivo, "                                                                  DHCP generado\n", nombre);
	fprintf(archivo, "\n###########################################################################################################################################################\n\n");
	
	if (excluidos1 == 1) {
		for (int i = 0; i < cant_host_DHCP_excluir; i++) {
			fprintf(archivo, "%s\n", dhcp_command_excluded[i]);
		}
	}
	
	if (excluidos2 == 1) {
		for (int i = 0; i < cant_ip_DHCP_excluir; i++) {
			fprintf(archivo, "ip dhcp excluded-address %s\n", dhcp_excluded[i]);
		}
	}
	
	for (int i = 0; i < cant_pool; i++) {
		fprintf(archivo, "%s\n", dhcp_pool[i]);
	}
	
	fprintf(archivo, "\n###########################################################################################################################################################\n\n");
	
	fclose(archivo);
}
void escribir_asignacionPuertos(char comandos[10000], const char datos[12]){
	FILE *archivo;
	sprintf(nombreArchivo, "%s.txt", datos);
	archivo = fopen(nombreArchivo, "a");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para escribir.\n");
	} else {
		fprintf(archivo, "\n                                               Direcciones IP asignadas");
		fprintf(archivo, "\n#################################################################################################################\n\n");
		fprintf(archivo, "%s", comandos);
		fprintf(archivo, "\n#################################################################################################################\n\n");	
	}
	fclose(archivo);
}
