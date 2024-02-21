double n_aumento;
int potencia = 0, total_mascara, aumento, saltos1, octeto1, octeto2, octeto3, octeto4, prefijo, cant_redes, pref_total;
int masc_inicial[32], masc1[8], masc2[8], masc3[8], masc4[8];
int cantidad_host[10000], saltos_VLSM[1000];
int prefijo_total_vlsm, saltosVLSM1;
int hosts_por_subred[10000];
int salto_final1 = 0;
int mascara_1_decimal, mascara_2_decimal, mascara_3_decimal, mascara_4_decimal;
int cambio, bdc, salto_t_VLSM;
int saltosVLSM2 = 0;
int octeto_extra_VLSM = 0, octetos_totalesVLSM[100000];
int mascara_finalVLSM1[10000], mascara_finalVLSM2[10000], mascara_finalVLSM3[10000], mascara_finalVLSM4[10000];
int BDC1[10000], BDC2[10000], BDC3[10000], BDC4[10000], UIP1[10000], UIP2[100000], UIP3[10000], UIP4[100000];
char direccionesIP_totales[100000][50], mascaras_IPVLSM_finales[100000][50], UIP_IPVLSM_finales[100000][50], BDC_IPVLSM_finales[100000][50];
char PIP_IPVLSM_finales[100000][50], host_encontradosVLSM[1000000];

void leerDatos_MascaraFija(const char datos[12]) {
	memset(masc1, 0, sizeof(masc1));
	memset(masc2, 0, sizeof(masc2));
	memset(masc3, 0, sizeof(masc3));
	memset(masc4, 0, sizeof(masc4));
	memset(masc_inicial, 0, sizeof(masc_inicial));
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe tu dirección de red: ");
	scanf("%d.%d.%d.%d", &octeto1, &octeto2, &octeto3, &octeto4);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe el prefijo de red inicial: ");
	scanf("%d", &prefijo);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe la cantidad de redes que quieres obtener: ");
	scanf("%d", &cant_redes);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n");
	
	generar_Mascara(prefijo, cant_redes);
	
	printf("\n\n");
	if (total_mascara <= 8) {
		printf("\nNo es posible hacer subneteo.\n");
	} else if (total_mascara > 8 && total_mascara <= 16) {
		saltos1 = 256 - binarioADecimal_subneteo(masc2);
		generar_subredes(cant_redes, octeto2, 2, saltos1, datos);
	} else if (total_mascara > 16 && total_mascara <= 24) {
		saltos1 = 256 - binarioADecimal_subneteo(masc3);
		generar_subredes(cant_redes, octeto3, 3, saltos1, datos);
	} else if (total_mascara > 24 && total_mascara <= 30) {
		saltos1 = 256 - binarioADecimal_subneteo(masc4);
		generar_subredes(cant_redes, octeto4, 4, saltos1, datos);
	} else {
		printf("\nFuera del rango\n");
	}
}


void leerDatos_VLSM(const char datos[12]){
	memset(masc1, 0, sizeof(masc1));
	memset(masc2, 0, sizeof(masc2));
	memset(masc3, 0, sizeof(masc3));
	memset(masc4, 0, sizeof(masc4));
	memset(masc_inicial, 0, sizeof(masc_inicial));
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe tu dirección de red: ");
	scanf("%d.%d.%d.%d", &octeto1, &octeto2, &octeto3, &octeto4);
	int octeto1_copia = octeto1, octeto2_copia = octeto2, octeto3_copia = octeto3, octeto4_copia = octeto4;
	
	do {
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe el prefijo de red inicial: ");
		scanf("%d", &prefijo);
		
		if (prefijo < 8 || prefijo > 30) {
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("\nPrefijo no valido. Debe estar entre 8 y 30.\n");
		}
	} while (prefijo < 8 || prefijo > 30);
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Escribe la cantidad de redes que quieres obtener: ");
	scanf("%d", &cant_redes);
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\n");
	
	for(int n_rep = 0; n_rep < cant_redes; n_rep++){
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Escribe la cantidad de host para la red %d: ", n_rep + 1);
		scanf("%d", &cantidad_host[n_rep]);
	}
	
	ordenarDeMayorAMenor(cantidad_host, cant_redes);
	calcularSaltos_VLSM(cantidad_host, cant_redes, saltos_VLSM);
	
	for (int i = 0; i < cant_redes; i ++){
		memset(masc1, 0, sizeof(masc1));
		memset(masc2, 0, sizeof(masc2));
		memset(masc3, 0, sizeof(masc3));
		memset(masc4, 0, sizeof(masc4));
		memset(mascara_inicial, 0, sizeof(mascara_inicial));
		
		prefijo_total_vlsm = (32 - prefijo) - saltos_VLSM[i];
		pref_total = prefijo_total_vlsm + prefijo;
		generar_MascaraVLSM(pref_total);
		
		cambio = asignar_octeto_manipulable(masc1, masc2, masc3, masc4);
		
		switch (cambio){
		case 1:
			fflush(stdin);
			asginar_valor_octeto_sig_VLSM(masc1, cambio, i);
			fflush(stdout);
			break;
		case 2:
			fflush(stdin);
			asginar_valor_octeto_sig_VLSM(masc2, cambio, i);
			fflush(stdout);
			break;
		case 3:
			fflush(stdin);
			asginar_valor_octeto_sig_VLSM(masc3, cambio, i);
			fflush(stdout);
			break;
		case 4:
			fflush(stdin);
			asginar_valor_octeto_sig_VLSM(masc4, cambio, i);
			fflush(stdout);
			break;
		default:
			printf("Error interno");
		}
	}
	
	
	for (int i = 0; i < cant_redes; i ++){
		memset(masc1, 0, sizeof(masc1));
		memset(masc2, 0, sizeof(masc2));
		memset(masc3, 0, sizeof(masc3));
		memset(masc4, 0, sizeof(masc4));
		memset(mascara_inicial, 0, sizeof(mascara_inicial));
		
		prefijo_total_vlsm = (32 - prefijo) - saltos_VLSM[i];
		pref_total = prefijo_total_vlsm + prefijo;
		generar_MascaraVLSM(pref_total);
		
		cambio = asignar_octeto_manipulable(masc1, masc2, masc3, masc4);
		
		if(i == 0){
			sprintf(PIP_IPVLSM_finales[0], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto4 + 1);
		}
		
		switch(cambio){
		case 1:
			saltosVLSM2 = 0;
			saltosVLSM2 = mascara_finalVLSM1[i];
			fflush(stdin);
			
			salto_t_VLSM = 0;
			salto_t_VLSM = (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 1));
			fflush(stdin);
			
			sprintf(direccionesIP_totales[i], "\n| %-4d.%-4d.%-4d.%-4d |", octeto1 + saltosVLSM2, octeto2, octeto3, octeto4);
			sprintf(BDC_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", octeto1 + salto_t_VLSM, 255, 255, 255);
			sprintf(UIP_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", octeto1 + (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 1)), 255, 255, 254);
			sprintf(PIP_IPVLSM_finales[i+1], " %-4d.%-4d.%-4d.%-4d |", octeto1 + saltosVLSM2, octeto2, octeto3, octeto4 + 1);
			
			octeto1 += saltosVLSM2;
			host_encontradosVLSM[i] = pow(2, (32 - pref_total)) - 2;
			fflush(stdin);
			break;
		case 2:
			saltosVLSM2 = 0;
			saltosVLSM2 = mascara_finalVLSM2[i];
			fflush(stdin);
			
			if ((octeto2 + saltosVLSM2) > 255){
				octeto1 = octeto3 + 1;
				saltosVLSM2 = saltosVLSM2 - 255;
			}
			
			sprintf(direccionesIP_totales[i], "\n| %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2 + saltosVLSM2, octeto3, octeto4);
			sprintf(BDC_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2 + (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 1)), 255, 255);
			sprintf(UIP_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2 + (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 1)), 255, 254);
			sprintf(PIP_IPVLSM_finales[i+1], " %-4d.%-4d.%-4d.%-4d |",octeto1, octeto2 + saltosVLSM2, octeto3, octeto4 + 1);
			
			octeto2 += saltosVLSM2;
			host_encontradosVLSM[i] = pow(2, (32 - pref_total)) - 2;
			fflush(stdin);
			break;
		case 3:
			saltosVLSM2 = 0;
			saltosVLSM2 = mascara_finalVLSM3[i];
			fflush(stdin);
			
			if ((octeto3 + saltosVLSM2) > 255){
				octeto2 = octeto3 + 1;
				saltosVLSM2 = saltosVLSM2 - 255;
			}
			
			sprintf(direccionesIP_totales[i], "\n| %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3 + saltosVLSM2, octeto4);
			if(octeto3 + (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 1)) == -1){
				sprintf(BDC_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2 + (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 1)), 255, 255);
			} else {
				sprintf(BDC_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3 + (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 1)), 255);
			}
			
			sprintf(UIP_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3 + (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 1)), 254); 
			sprintf(PIP_IPVLSM_finales[i+1], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3 + saltosVLSM2, octeto4 + 1);
			
			octeto3 += saltosVLSM2;
			host_encontradosVLSM[i] = pow(2, (32 - pref_total)) - 2;
			fflush(stdin);
			break;
		case 4:
			saltosVLSM2 = 0;
			saltosVLSM2 = mascara_finalVLSM4[i];
			fflush(stdin);
			
			if ((octeto4 + saltosVLSM2) > 255){
				octeto3 = octeto3 + 1;
				saltosVLSM2 = saltosVLSM2 - 255;
			}
			
			sprintf(direccionesIP_totales[i], "\n| %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto4 + saltosVLSM2);
			sprintf(BDC_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto4 + (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 1)));
			sprintf(UIP_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto4 + (saltosVLSM2 + (mascara_finalVLSM1[i+1] - 2)));
			sprintf(PIP_IPVLSM_finales[i+1], " %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto4 + saltosVLSM2 + 1);
			
			octeto4 += saltosVLSM2;
			host_encontradosVLSM[i] = pow(2, (32 - pref_total)) - 2;
			fflush(stdin);
			break;
		default:
			printf("Error interno");
		}
	}
	
	for (int i = 0; i < cant_redes; i ++){
		memset(masc1, 0, sizeof(masc1));
		memset(masc2, 0, sizeof(masc2));
		memset(masc3, 0, sizeof(masc3));
		memset(masc4, 0, sizeof(masc4));
		memset(mascara_inicial, 0, sizeof(mascara_inicial));
		
		prefijo_total_vlsm = (32 - prefijo) - saltos_VLSM[i];
		pref_total = prefijo_total_vlsm + prefijo;
		generar_MascaraVLSM(pref_total);
		
		cambio = asignar_octeto_manipulable(masc1, masc2, masc3, masc4);
		
		sprintf(mascaras_IPVLSM_finales[i], " %-4d.%-4d.%-4d.%-4d |", binarioADecimal_subneteo(masc1), binarioADecimal_subneteo(masc2), binarioADecimal_subneteo(masc3), binarioADecimal_subneteo(masc4));
	}
	
	printf("\n#############################################################################################\n\n");
	printf("                           Subredes creadas con mascara variable\n");
	printf("\n#############################################################################################\n\n");
	printf("\n");
	printf("|  Dirección de red   |     Primera IP      |      Ultima IP      |      Broadcast      |  Mascara de subred  |");
	
	int j = 0;
	for (int i = 0; i < cant_redes - 1; i ++){
		if (j == 0){
			printf("\n| %-4d.%-4d.%-4d.%-4d |", octeto1_copia, octeto2_copia, octeto3_copia, octeto4_copia);
			printf("%s", PIP_IPVLSM_finales[0]);
			printf("%s", UIP_IPVLSM_finales[0]);
			printf("%s", BDC_IPVLSM_finales[0]);
			printf("%s", mascaras_IPVLSM_finales[0]);
			j++;
		}
		
		printf("%s", direccionesIP_totales[i]);
		printf("%s", PIP_IPVLSM_finales[i+1]);
		printf("%s", UIP_IPVLSM_finales[i+1]);
		printf("%s", BDC_IPVLSM_finales[i+1]);
		printf("%s", mascaras_IPVLSM_finales[i+1]);	
	}
}

void ordenarDeMayorAMenor(int arreglo[], int tamano) {
	int temp;
	for (int i = 0; i < tamano - 1; i++) {
		for (int j = 0; j < tamano - i - 1; j++) {
			if (arreglo[j] < arreglo[j + 1]) {
				temp = arreglo[j];
				arreglo[j] = arreglo[j + 1];
				arreglo[j + 1] = temp;
			}
		}
	}
}


void generar_Mascara(int pref, int n_redes) {
	memset(masc1, 0, sizeof(masc1));
	memset(masc2, 0, sizeof(masc2));
	memset(masc3, 0, sizeof(masc3));
	memset(masc4, 0, sizeof(masc4));
	
	for (int j = 0; j < 8; j++) {
		n_aumento = pow(2, j);
		if (n_aumento >= n_redes) {
			break;
		}
		potencia++;
	}
	
	total_mascara = pref + potencia;
	aumento = 1;
	
	for (int i = 0; i < 32; i++) {
		if (aumento <= total_mascara) {
			masc_inicial[i] = 1;
		} else {
			masc_inicial[i] = 0;
		}
		aumento++;
	}
	
	dividir_mascara1(masc_inicial, total_mascara);
}

void generar_MascaraVLSM(int pref){
	memset(masc1, 0, sizeof(masc1));
	memset(masc2, 0, sizeof(masc2));
	memset(masc3, 0, sizeof(masc3));
	memset(masc4, 0, sizeof(masc4));
	memset(mascara_inicial, 0, sizeof(mascara_inicial));
	
	aumento = 1;
	
	for (int i = 0; i < 32; i++) {
		if (aumento <= pref) {
			masc_inicial[i] = 1;
		} else {
			masc_inicial[i] = 0;
		}
		aumento++;
	}
	
	dividir_mascara1VLSM(masc_inicial, pref);
}

void dividir_mascara1(int mascara_inicial[32], int total_mascara) {
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
}

void dividir_mascara1VLSM(int mascara_inicial[32], int total_mascara) {
	int i = 0;
	
	if (pref_total < 8) {
		for (i = 0; i < 8; i++) {
			masc1[i] = mascara_inicial[i];
		}
	} else if (pref_total < 16) {
		for (i = 0; i < 8; i++) {
			masc1[i] = mascara_inicial[i];
		}
		for (i = 0; i < 8; i++) {
			masc2[i] = mascara_inicial[i + 8];
		}
	} else if (pref_total < 24) {
		for (i = 0; i < 8; i++) {
			masc1[i] = mascara_inicial[i];
		}
		for (i = 0; i < 8; i++) {
			masc2[i] = mascara_inicial[i + 8];
		}
		for (i = 0; i < 8; i++) {
			masc3[i] = mascara_inicial[i + 16];
		}
	} else if (pref_total < 32) {
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
}

int binarioADecimal_subneteo(int mascara[8]) {
	fflush(stdin);
	int decimal = 0;
	
	for (int i = 7; i >= 0; i--) {
		decimal += mascara[i] * pow(2, 7 - i);
	}
	return decimal;
}

void generar_subredes(int cant_redes1, int octeto_manipulable, int n, int salto, const char datos[12]){
	for (int i = 0; i < cant_redes; i++) {
		hosts_por_subred[i] = (int)pow(2, 32 - total_mascara) - 2;
	}
	
	printf("\n###########################################################################################################################################################\n\n");
	printf("                                                 Subredes creadas con mascara fija\n", nombre);
	printf("\n###########################################################################################################################################################\n\n");
	printf("\n");
	printf("|  Dirección de red   |     Primera IP      |      Ultima IP      |      Broadcast      |       Gateway       |  Mascara de subred  |  Host Encontrados |");
	int octeto_extra, exponente = 0;
	
	if (n == 2){
		printf("\n");
		for(int i = 0; i < cant_redes1; i++){
			octeto_extra = octeto_manipulable;
			printf("| %-4d.%-4d.%-4d.%-4d | %-4d.%-4d.%-4d.%-4d |", octeto1, octeto_manipulable, octeto3, octeto4, octeto1, octeto_manipulable, octeto3, octeto4+1);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto_extra + salto -1, 255, 254);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto_extra + salto -1, 255, 255);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto_manipulable, octeto3, octeto4 + 1);
			printf(" %-4d.%-4d.%-4d.%-4d |", binarioADecimal_subneteo(masc1), binarioADecimal_subneteo(masc2), binarioADecimal_subneteo(masc3), binarioADecimal_subneteo(masc4));
			printf("        %-4d       |", hosts_por_subred[i]);
			octeto_manipulable += salto;
			printf("\n");
		}
		escribir_subneteo_mascaraFija(octeto1, octeto2, octeto3, octeto4, cant_redes, octeto_manipulable, 2, salto, datos, hosts_por_subred);
	} else if (n == 3){
		printf("\n");
		for(int i = 0; i < cant_redes1; i++){
			octeto_extra = octeto_manipulable;
			printf("| %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_manipulable, octeto4);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_manipulable, octeto4 + 1);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_extra + salto -1, 254);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_extra + salto -1, 255);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto_manipulable, octeto4 + 1);
			printf(" %-4d.%-4d.%-4d.%-4d |", binarioADecimal_subneteo(masc1), binarioADecimal_subneteo(masc2), binarioADecimal_subneteo(masc3), binarioADecimal_subneteo(masc4));
			printf("        %-4d       |", hosts_por_subred[i]);
			octeto_manipulable += salto;
			printf("\n");
		}
		escribir_subneteo_mascaraFija(octeto1, octeto2, octeto3, octeto4, cant_redes, octeto_manipulable, 3, salto, datos, hosts_por_subred);
	} else if (n == 4) {
		printf("\n");
		for(int i = 0; i < cant_redes1; i++){
			octeto_extra = octeto_manipulable;
			printf("| %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_manipulable);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_manipulable + 1);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_extra + salto -2);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_extra + salto -1);
			printf(" %-4d.%-4d.%-4d.%-4d |", octeto1, octeto2, octeto3, octeto_manipulable + 1);
			printf(" %-4d.%-4d.%-4d.%-4d |", binarioADecimal_subneteo(masc1), binarioADecimal_subneteo(masc2), binarioADecimal_subneteo(masc3), binarioADecimal_subneteo(masc4));
			printf("        %-4d       |", hosts_por_subred[i]);
			octeto_manipulable += salto;
			printf("\n");
		}
		escribir_subneteo_mascaraFija(octeto1, octeto2, octeto3, octeto4, cant_redes, octeto_manipulable, 4, salto, datos, hosts_por_subred);
	}
}	

void calcularSaltos_VLSM(int cantidad_host[], int cant_redes, int saltos_VLSM[]) {
	for (int i = 0; i < cant_redes; i++) {
		int n = 0;
		while (pow(2, n) - 2 < cantidad_host[i]) {
			n++;
		}
		saltos_VLSM[i] = n;
	}
}

int asignar_octeto_manipulable(int masc1[8], int masc2[8], int masc3[8], int masc4[8]){
	mascara_1_decimal = binarioADecimal_subneteo(masc1);
	mascara_2_decimal = binarioADecimal_subneteo(masc2);
	mascara_3_decimal = binarioADecimal_subneteo(masc3);
	mascara_4_decimal = binarioADecimal_subneteo(masc4);
	
	if (mascara_1_decimal < 255) {
		return 1;
	} else if (mascara_2_decimal < 255){
		return 2;
	} else if (mascara_3_decimal < 255) {
		return 3;
	} else if (mascara_4_decimal < 255){
		return 4;
	}
}


void asginar_valor_octeto_sig_VLSM(int octeto_modificable[8], int cambio_total, int i){
	int valor = binarioADecimal_subneteo(octeto_modificable);
	
	if (cambio_total == 1){
		mascara_finalVLSM1[i] = 256 - valor;
	} else if (cambio_total == 2){
		mascara_finalVLSM2[i] = 256 - valor;
	} else if (cambio_total == 3) {
		mascara_finalVLSM3[i] = 256 - valor;
	} else if (cambio_total == 4){
		mascara_finalVLSM4[i] = 256 - valor;
	}
}
