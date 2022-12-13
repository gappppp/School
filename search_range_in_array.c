#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int cercaElementi(int min, int max, int v[], int lunghezza, int index[]) {
  int i, ricorrenza = 0, counter = 0;

  for (i = 0; i < lunghezza; i++) {
    //se un valore del vettore e' compreso nel range da cercare:
    if (v[i] >= min && v[i] <= max) {
      //incremento di 1 l'insieme di valori del vettore che sono compresi nel range
      ricorrenza++;
      //memorizzo la posizione del valore
      index[counter] = i;
      // Counter: Tiene conto del posizionamento del vettore “index”
      counter++;
    }
  }

  //ritornera' la frequenza di valori registrati all'interno del range
  return ricorrenza;
}


//crea un vettore di lunghezza x con valori compresi tra minval e maxval
void creaVettore(int v[], int lunghezza, int minVal, int maxVal) {
  srand((unsigned) time(NULL));
  int i;

  for (i = 0; i < lunghezza; i++)
    // randomizza i valori del vettore da minval a maxval
    v[i] = rand() % (maxVal - minVal + 1) + minVal;
}

int main() {
  int v[100], lunghezza = 100, min, max, i, ricorrenza, index[100];


  // richiamo la funzione creaVettore
  creaVettore(v, lunghezza, 1, 100);


  //stampo il vettore randomizzato
  for (i = 0; i < lunghezza; i++) {
    if (i == 0)
      printf("[%d", v[0]);
    else if (i == lunghezza - 1)
      printf(" %d]\n\n", v[i]);
    else
      printf(" %d", v[i]);
  }

  printf("Inserisci un range di numeri che vuoi cercare all'interno "   
  "dell'array [inserire prima valore minimo e poi valore massimo]: ");

  //in input il "range"
  scanf("%d%d", &min, &max);


  //controllo dei valori, se non corretti si dovranno reinserire
  if (min > max) {
    do {
      printf("Inserisci prima il valore minimo e poi il valore " 
      "massimo!!!");

      printf("Inserisca di nuovo il range di numeri tra cui cercare: ");
      scanf("%d%d", &min, &max);
    } while (min > max);
  }


  // La funzione ritorna quante volte e' comparso il un numero del range di numeri
  ricorrenza = cercaElementi(min, max, v, lunghezza, index);

  //stampo i risultati:
  if (ricorrenza == 0) {
    // if (ricorrenza == 0): L'elemento da cercare non compare nel vettore
    printf("\nIl range di elementi da cercare da lei inseriti non sono "
    "presenti nell'array.");
  } else if (ricorrenza == 1) {
    // if (ricorrenza == 1): L'elemento da cercare si trova una volta nel vettore
    printf("\nE' presente un numero all'interno del range da lei "   
    "inserito ");
    printf("e si trova nella seguente posizione dell'array: %d.",  
    index[0]);
  } else {
    // L'elemento da cercare si trova diverse volte nel vettore
    printf("\nSono presenti %d numeri nel range da lei inserito "    
    "all'interno dell'array ", ricorrenza);
    printf("e si trovano nelle seguenti posizioni dell'array:\n");
    for (i = 0; i < ricorrenza; i++)
      printf("%d\n", index[i]);
  }
  return 0;
}
