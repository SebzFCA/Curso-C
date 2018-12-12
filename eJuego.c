/*

El jugador tira dos dados. Cada dado tiene seis caras. Estas caras contienen 1, 2, 3, 4, 5 y 6 puntos. Una vez que
los dados caen, se calcula la suma de los puntos que se encuentran en las caras que ven hacia arriba. Si la suma
es igual a 7 u 11 en el primer tiro, el jugador gana. Si la suma es 2, 3 o 12 en el primer tiro (llamado “craps”),
el jugador pierde (es decir, la “casa” gana). Si la suma es 4, 5, 6, 8, 9, o 10 en el primer tiro, entonces la suma
se convierte en el “punto” del jugador. Para ganar, usted debe continuar tirando los dados hasta que “haga su
punto”. El jugador pierde si tira un 7 antes de hacer su punto.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Estatus { GANA, PIERDE, CONTINUA};

int eTiraDados (void);

int main(){

	enum Estatus eEstatusJuego;

	int ePunto, eSuma;
	
	printf("\n\tPresione una tecla para iniciar el juego de craps.");
	getchar();

	srand(time (NULL));

	eSuma = eTiraDados ();
	
	switch(eSuma){
		
		case 7:
		case 11:
			eEstatusJuego = GANA;
		break;
		
		case 2:
		case 3:
		case 12:
			eEstatusJuego = PIERDE;
		break;
		
		default:
			eEstatusJuego = CONTINUA;
			ePunto = eSuma;
			printf("\nSu punto es %d\n", ePunto);
		break;
		
	} //Fin switch
	
	while (eEstatusJuego == CONTINUA){
		
		eSuma = eTiraDados();
		
		if (eSuma == ePunto){
			eEstatusJuego = GANA;
		}else{
			if (eSuma == 7){
				eEstatusJuego = PIERDE;
			}
		}
		
	} //Fin while
	
	if (eEstatusJuego == GANA){
		printf("\n\aEl jugador gana.");
	}else{
		printf("\n\aEl jugador pierde.");
	}

	getchar();
	return 0;
}

int eTiraDados (void){
	
	int eDado1, eDado2, eSumaTemp;
	
	eDado1 = 1 + (rand() % 6);
	eDado2 = 1 + (rand() % 6);
	
	eSumaTemp = eDado1 + eDado2;
	
	printf("\nEl jugador tiro %d + %d = %d.\n", eDado1, eDado2, eSumaTemp);
	
	return eSumaTemp;
	
}
