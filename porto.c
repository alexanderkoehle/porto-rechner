//2AM, Alexander Köhle
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

typedef struct {
	char *name;
	float m1;
	float m2;
	float m3;
	float g;
	float p;
}porto;

void printporto(porto *x) {
	printf("Laenge %.2f\nBreite %.2f\nHoehe %.2f\nGewicht %.2f\nPreis %.2f\n", x->m1, x->m2, x->m3, x->g, x->p);
}

void inputporto(porto *x) {
	printf("Geben Sie die Laenge ein: ");
	scanf("%f", &x->m1);
	printf("Geben Sie die Breite ein: ");
	scanf("%f", &x->m2);
	printf("Geben Sie die Hoehe ein: ");
	scanf("%f", &x->m3);
	printf("Geben Sie das Gewicht ein: ");
	scanf("%f", &x->g);
}

// Super fancy sorting
void sortporto(porto *x) {
	float temp;
	if (x->m1 < x->m2) {
		temp = x->m1;
		x->m1 = x->m2;
		x->m2 = temp;
	}
	if (x->m2 < x->m3) {
		temp = x->m2;
		x->m2 = x->m3;
		x->m3 = temp;
	}
	if (x->m1 < x->m2) {
		temp = x->m1;
		x->m1 = x->m2;
		x->m2 = temp;
	}
}

/*Lassen Sie einen Pointer auf Variablen des Typs Porto in einer for-Schleife über die einzelnen
Feldelement (Tarif) "laufen" (bis der Pointer auf ein Element „mit 0-Werten“ zeigt) und prüfen Sie, ob das
Paket die jeweiligen Kriterien (Gewicht, Größe) des Tarifs erfüllt – wenn ja, geben Sie den Tarif mit Preis
aus (siehe Beispiel)!*/

float portoprice(porto *x) {
	float price = 0;
	if (x->g <= 2) {
		price = 8.94;
	}
	else if (x->g <= 4) {
		price = 14.00;
	}
	else if (x->g <= 10) {
		price = 15.00;
	}
	else if (x->g <= 20) {
		price = 17.00;
	}
	else if (x->g <= 31.5) {
		price = 20.00;
	}
	else if (x->g <= 31.5) {
		price = 29.34;
	}
	else if (x->g <= 31.5) {
		price = 39.44;
	}
	return price;
}

void calcporto(porto *x, porto *Tarife) {
	int i = 0;

	if (x->m1 > 100 || x->m2 > 60 || x->m3 > 60) {
		printf("Paket zu gross");
		if (x->g > 31.5) {
			printf(" und zu schwer\n");
			return;
		}
		else {
			printf("\n");
			return;
		}
	}

	if (x->g > 31.5) {
		printf("Paket zu schwer\n");
		return;
	}


	for (int i = 0; Tarife[i].g; i++) {
		if (x->g <= Tarife[i].g) {
			if (x->m1 <= Tarife[i].m1 && x->m2 <= Tarife[i].m2 && x->m3 <= Tarife[i].m3) {
				printf("Preis: %.2f\n", Tarife[i].p);
				return;
			}
		}
	}
}

void asciart() {
    printf(" ________                   __   ______                               __                                     \n");
    printf("/        |                 /  | /      \\                             /  |                                    \n");
    printf("$$$$$$$$/______    ______  $$/ /$$$$$$  |______    ______    _______ $$ |____   _______    ______    ______  \n");
    printf("   $$ | /      \\  /      \\ /  |$$ |_ $$//      \\  /      \\  /       |$$      \\ /       \\  /      \\  /      \\ \n");
    printf("   $$ | $$$$$$  |/$$$$$$  |$$ |$$   |  /$$$$$$  |/$$$$$$  |/$$$$$$$/ $$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |\n");
    printf("   $$ | /    $$ |$$ |  $$/ $$ |$$$$/   $$ |  $$<  $$    $$< $$ |      $$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$< \n");
    printf("   $$ |/$$$$$$$ |$$ |      $$ |$$ |    $$ |_____/ $$$$$$$  |$$ \\_____ $$ |  $$ |$$ |  $$ |$$$$$$$$/ $$ |_____/ \n");
    printf("   $$ |$$    $$ |$$ |      $$ |$$ |    $$       |/     $$/ $$       |$$ |  $$ |$$ |  $$ |$$       |$$ |       \n");
    printf("   $$/  $$$$$$$/ $$/       $$/ $$/     $$$$$$$/ $$$$$$$/   $$$$$$$/ $$/   $$/ $$/   $$/  $$$$$$$/ $$/        \n");
}



int main() {

//XXS L 35,3 x B 25 x H 3 cm bis 2 kg 8,94
//XS L 100 x B 60 x H 60 cm bis 1 kg 14,00
//S L 100 x B 60 x H 60 cm bis 2 kg 15,00
//M L 100 x B 60 x H 60 cm bis 4 kg 17,00
//L L 100 x B 60 x H 60 cm bis 10 kg 20,00
//XL L 100 x B 60 x H 60 cm bis 20 kg 29,34
//XXL L 100 x B 60 x H 60 cm bis 31,5 kg 39,44

	porto Tarife [] = {
		{"XXS",35.3, 25, 3, 2, 8.94},
		{"XS", 100, 60, 60, 1, 14.00},
		{"S", 100, 60, 60, 2, 15.00},
		{"M", 100, 60, 60, 4, 17.00},
		{"L", 100, 60, 60, 10, 20.00},
		{"XL", 100, 60, 60, 20, 29.34},
		{"XXL", 100, 60, 60, 31.5, 39.44},
		{"NULL", 0, 0, 0, 0, 0}
	};


/*	for (int i = 0; Tarife[i].g; i++) {
		printporto(&Tarife[i]);
	}

	printporto(&Tarife[0]); */
	asciart();
	porto input;
	inputporto(&input);
//	printporto(&input);
	sortporto(&input);
	calcporto(&input, Tarife);
	return 0;
}