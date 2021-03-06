// Karetni_hra.cpp 

#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "Karty.h"

int main(){
    // info o hre
	printf("Vitejte ve hre JEDNADVACET!"
        "\nCilem hry je dosahnout hodnoty 21."
        "\nHodnota karet je: 7, 8, 9, 10, svrsek nebo spodek = 1, kral = 2, eso = 11, 2 esa = 21!\n\n");

        // ukazatel na aktualni kartu
		struct Karty * aktKarta;
        // alokovani pameti
		aktKarta = (struct Karty *)malloc(sizeof(struct Karty));

        // hrac voli zda chce dalsi kartu nebo ne
		printf("Pro vytahnuti karty stisknete y, pokud dalsi kartu nechcete, stisknete n.\n");
		char volba;
		int vytazeneKarty = 0;
		int skoreHrace1 = 0;
		int skoreHrace2 = 0;
		int nahoda = 0;

		do{
			scanf_s("%s", &volba, sizeof(volba));
			switch(volba){
                // dostane dalsi kartu (v promenne se hodnoty sectou)
			    case 'y' :
                    // pokud dojdou v balicku karty
			        if (vytazeneKarty >= 32){
                        printf("Nelze vytahnout dalsi kartu.\n");
                        volba = 'q';
                    }
                    else{
                        // nahodne vezme cislo z intervalu <0;31>
                        nahoda = rand() % 32;
                        while(aktKarta->cisloKarty == nahoda){
                            // vypsani karty hrace1 (barva a nazev)
                            printf("HRAC 1: Vase karta je: %s - %s\n", aktKarta->barva, aktKarta->nazev);
                            // skoreHrace1 se navysi o hodnotu vytazene karty
                            skoreHrace1 += aktKarta->hodnota;
                            // vypis skoreHrace1
                            printf("HRAC 1: Hodnota karet je: %d\n", skoreHrace1);
                            // cislo karty se zvysi mimo kontrolovanou hodnotu => pri kontrole "nelze nalezt"
                            aktKarta->cisloKarty = 32;
                        }
                        // uvolneni pameti aktKarty
                        free(aktKarta);
                        vytazeneKarty++;
                    }
                // hrac1 uz nechce kartu, nyni je na rade hrac2 (automat)
                case 'n' :
                    if(vytazeneKarty >= 32){
                        printf("Nelze vytahnout dalsi kartu.\n");
                        volba = 'q';
                    }
                    else{
                        int i;
                        for (i = 0; i < 3; i++){
                            // nahodne vezme cislo z intervalu <0;31>
                            nahoda = rand() % 32;
                            while (aktKarta->cisloKarty == nahoda){
                                // skoreHrace2 se navysi o hodnotu vytazene karty
                                skoreHrace2 += aktKarta->hodnota;
                                // cislo karty se zvysi mimo kontrolovanou hodnotu => pri kontrole "nelze nalezt"
                                aktKarta->cisloKarty = 32;
                            }
                            // uvolneni pameti aktKarty
                            free(aktKarta);
                            vytazeneKarty++;
                            volba = 'q';
                        }
                    }
                    // konecne skoreHrace1
                    printf("HRAC 1: Vase skore je: %d\n", skoreHrace1);
                    // konecne skoreHrace2
                    printf("HRAC 2: Skore je: %d\n", skoreHrace2);
                // osetreni volby neceho jineho
				default :
				printf("Chybna volba. Pro dalsi kartu stisknete y, pokud dalsi kartu nechcete, stisknete n.\n ");
			}
		}while (volba != 'q');
		
		// vyhodnoceni hry

        //oba hraci maji 21 - vyhra hrace1
		if ((skoreHrace1 == 21) && (skoreHrace2 == 21)){
			printf("VYHRA, GRATULUJI!\n");
			return 0;
		}
        //hrac2 ma 21 - vyhra hrace2
		else if (skoreHrace2 == 21){
			printf("PROHRA :(\n");
			return 0;
		}
		// oba hraci > 21, nikdo nevyhral
		else if ((skoreHrace1 > 21) && (skoreHrace2 > 21)){
			printf("Nikdo nevyhral.\n");
			return 0;
		}
		// hrac2 >= hrac1 a zaroven hrac2 < 21 - vyhra hrace2
		else if ((skoreHrace2 >= skoreHrace1) && (skoreHrace2 < 21)){
			printf("PROHRA :(\n");
			return 0;
		}
		// hrac1 > 21 a zaroven hrac2 < 21 - vyhra hrace2
		else if ((skoreHrace1 > 21) && (skoreHrace2 < 21)){
			printf("PROHRA :(\n");
			return 0;
		}
		//hrac1 >= hrac2 a zaroven hrac1 < 21
		else if ((skoreHrace1 >= skoreHrace2) && (skoreHrace1 < 21)){
            //hrac1 je blize hodnote 21
		    printf("VYHRA, GRATULUJI!");
			return 0;
		}
	return 0;
}