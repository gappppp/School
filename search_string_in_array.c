/*
Descrizione:Algoritmo di ricerca di una stringa all'interno di un vettore di caratteri randomizzati 
Input:Stringa da cercare
Output:Frequenza della stringa all’interno del vettore e relative posizioni
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DIM 100 //definisco la lunghezza del vettore (100)

int main () {
	char v[DIM], search[DIM];
	int i, j, k=0, l, size, corr, ris[DIM];
	srand((unsigned)time(NULL));
      for (i=0;i<DIM;i++){
      //ciclo per randomizzare il vettore e stamparlo
		do {
                 v[i]=rand()%74+48;
                 //randomizzo il vettore con caratteri ASCII da 48 a 122
		} while ((v[i]>=57 && v[i]<=65) || (v[i]>=90 && v[i]<=97));
            /*nel while: solo i caratteri da 0 a 9 e da a alla z 
            maiuscole e minuscole sono accettate*/
	      printf("%c",v[i]);//stampo il carattere randomizzato
	}
	printf("\nInserisci la stringa da cercare all'interno dell'array" 
      "[premi ENTER o SPACE per confermare]: ");
	i=0;
	do {
		fflush(stdout);
            /*”fflush(stdout)”:pulisco il buffer per evitare di inserire     
            valori indesiderati*/
	     search[i]=getch();//prendo l’input di ogni carattere inserito
		if (search[i]!=32 && search[i]!=13 && ((search[i]>=48 && search[i]<=57) || (search[i]>=65 && search[i]<=90) || (search[i]>=97 && search[i]<=122))) {//l’if controlla se sono valori validi e se corretti:
			printf("%c", search[i]);//stampa l'input inserito 
			i++;//e prosegue il ciclo
		}
	} while (search[i]!=32 && search[i]!=13);
     //while:quando l'input inserito e' SPAZIO o INVIO, termina il ciclo
	size=i;
      /*”size=i”:uso una variabile d'appoggio per sapere la lunghezza 
      della stringa messa in input*/
	for (i=size;i<=DIM;i++) {
      //ciclo che segna la posizione che si e' arrivati nella ricerca
		corr=0;
		l=0;
		for (j=i-size;j<i;j++) {
            /*ciclo che verifichera' se i singoli caratteri della    
            stringa da ricercare sono presenti in una porzione 
            dell'array*/
		    if (search[l]==v[j]) corr++;
                //verifica e incrementa di 1 la variabile corr se uguale
		    l++;
		}
		if (corr>=size) {
            /*se l'if e' vero, vuol dire che la stringa e' presente in 
            quella posizione del vettore*/
		   ris[k]=i;
               //'salvo' il risultato per poi mostrarlo a schermo
		   k++;
  		}
	}
	printf("\nIl risultato della ricerca ha riscontrato %d volte”    
      “all'interno del vettore la stringa '",k);//stampo i risultati
	for (i=0;i<size;i++) printf("%c",search[i]);
	printf("'\n");
	for (i=0;i<k;i++) {
		if (size>1) printf("- dalla posizione %d del vettore alla” 
            “posizione %d\n",ris[i]-size+1,ris[i]);
		else printf("- nella posizione %d del vettore\n",ris[i]);
	}
return 0;
}
