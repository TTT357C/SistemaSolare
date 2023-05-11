#include <iostream>
#include <Windows.h>
using namespace std;
//prototipi

struct s_sistema{
	string nome;
	string tipo;
	string pianetaapp;
	int massa;
	int diametro;
	int perdiriv;
	int distsol;
};

const int N=100;

void menu(int n);
void vmenu(int n);
int carica(s_sistema solare[],int *n);
void salva(s_sistema solare[],int *n);
void sovrascrivi(s_sistema solare[],int *n);
void inserisci(s_sistema solare[],int *n);
void visualizza(s_sistema solare[],int n);
void vdto(s_sistema solare[],int n);
void caricamento();

//creato da Thomas Causetti

int main(int argc, char** argv) {
	s_sistema solare[N];
	int n=0,s,s1,a;
	do{
		s=0;
	menu(n);
	cout<<endl;
	cout<<" ";
	cin>>s;
	  switch(s){
		  case 0:
		  break; 
		  case 1:
		  caricamento();
		  a=carica(solare,&n);
		  n=n+a;
		  break; 
		  case 2:
		  caricamento();
		  salva(solare,&n);
		  break; 
		  case 3:
		  caricamento();
		  sovrascrivi(solare,&n);
		  break;
		  case 4:
		  caricamento();
		  inserisci(solare,&n);
		  break;
		  case 5:
		  caricamento();
		  //modifica
		  break;
		  case 6:
		  caricamento();
		  //cancella
		  break;
		  case 7:
		      do{
		      	vmenu(n);
		  	    s1=0;
		  	    cin>>s1;
		  	     switch(s1){
		  	        case 0:
		            break;
		            case 1:
		            caricamento();
		            visualizza(solare,n);
		            break;
		            case 2:
		            caricamento();
		            break;
		            case 3:
		            caricamento();
		            vdto(solare,n);
		            break;
		            case 4:
		            caricamento();
		            break;
		            case 5:
		            caricamento();
		            break;
		            case 6:
		            caricamento();
		            break;
		            default:
		            cout<<"  > ERRORE <"<<endl<<endl;
		            break; 
		        }	
		  }while(s1!=0);
		  
		  break;
		  default:
		  cout<<"  > ERRORE <"<<endl;
		  break;  
	  }
	}while(s!=0);
	
	
	 

	
	return 0;
}


int carica(s_sistema solare[],int *n){
       FILE* fin;
       char riga[100];
       int cont=0;
        string nomeF="sistemsolar.txt";   
           if((fin=fopen(nomeF.c_str(),"r"))!=NULL){
           	    while(fgets(riga,100,fin)){
           	  	    solare[cont].nome=strtok(riga,";");
           	  	    solare[cont].tipo=strtok(NULL,";");
           	  	    solare[cont].pianetaapp=strtok(NULL,";");
           	  	    solare[cont].massa=atoi(strtok(NULL,";"));
           	  	    solare[cont].diametro=atoi(strtok(NULL,";"));
           	  	    solare[cont].perdiriv=atoi(strtok(NULL,";"));
           	  	    solare[cont].distsol=atoi(strtok(NULL,";"));
           	  	    cont++;
				}
		   }
		   else{
		   	cout<<"Impossibile caricare file";
		   }
		return cont;
}


void salva(s_sistema solare[],int *n){
	//definire il puntatore al file
	FILE* pFout;
	//formato di scrittura
	char appoggio[10];
	char appoggio1[10];
	char appoggio2[10];
	char appoggio3[10];
	string formato;
	string nomeF="sistemsolar.txt";  
	if((pFout=fopen(nomeF.c_str(),"a"))!=NULL){
		//scrivere su file
		for(int i=0;i<*n;i++){
	    formato=solare[i].nome+";"+solare[i].tipo+";"+solare[i].pianetaapp+";"+itoa(solare[i].massa,appoggio,10)+";"+itoa(solare[i].diametro,appoggio1,10)+";"+itoa(solare[i].perdiriv,appoggio2,10)+";"+itoa(solare[i].distsol,appoggio3,10);
		fputs(formato.c_str(),pFout);
		fputc('\n',pFout);
	    }
	    fclose(pFout);
	}
	else{
		cout<<"Impossibile aprire il file"<<endl;
	}
}


void sovrascrivi(s_sistema solare[],int *n){
	//definire il puntatore al file
	FILE* pFout;
	//formato di scrittura
	char appoggio[10];
	char appoggio1[10];
	char appoggio2[10];
	char appoggio3[10];
	string formato;
	string nomeF="sistemsolar.txt";  
	if((pFout=fopen(nomeF.c_str(),"w"))!=NULL){
		//scrivere su file
		for(int i=0;i<*n;i++){
	    formato=solare[i].nome+";"+solare[i].tipo+";"+solare[i].pianetaapp+";"+itoa(solare[i].massa,appoggio,10)+";"+itoa(solare[i].diametro,appoggio1,10)+";"+itoa(solare[i].perdiriv,appoggio2,10)+";"+itoa(solare[i].distsol,appoggio3,10);
		fputs(formato.c_str(),pFout);
		fputc('\n',pFout);
	    }
	    fclose(pFout);
	}
	else{
		cout<<"Impossibile aprire il file"<<endl;
	}
}

void inserisci(s_sistema solare[],int *n){
	int c1=0;
	system("cls");
	cout<<endl;
	cout<<"                 Inserimento"<<endl<<endl;
	cout<<" Dimmi il nome dell'oggetto: ";
	fflush(stdin);
	getline(cin,solare[*n].nome);
	do{
		if(c1>=1){
	    cout<<"  > ERRORE <"<<endl<<endl;
	    }
	cout<<" Dimmi il tipo di oggetto (p=pianeta, a=asteroide, c=cometa, s=satellite): ";
	fflush(stdin);
	getline(cin,solare[*n].tipo);
	c1++;	
	}while(solare[*n].tipo!="a" && solare[*n].tipo!="c" && solare[*n].tipo!="s" && solare[*n].tipo!="p");
	  if(solare[*n].tipo=="s"){
	    cout<<" Dimmi il pianeta di appartenenza dell'oggetto: ";
	    fflush(stdin);
	    getline(cin,solare[*n].pianetaapp);
	  }
	  else{
	  	solare[*n].pianetaapp="/";
	  }
	cout<<" Dimmi la massa del oggetto: ";
	fflush(stdin);
	cin>>solare[*n].massa;
	cout<<" Dimmi la diametro del oggetto: ";
	fflush(stdin);
	cin>>solare[*n].diametro;
	cout<<" Dimmi la periodo di rivoluzione del oggetto: ";
	fflush(stdin);
	cin>>solare[*n].perdiriv;
	cout<<" Dimmi la distanza media dal sole: ";
	fflush(stdin);
	cin>>solare[*n].distsol;
	*n=*n+1;
}


void visualizza(s_sistema solare[],int n){
	system("cls");
	for(int i=0;i<n;i++){
		
		if(solare[i].tipo=="c"){                                                 //cometa
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"     OO          Massa: "<<solare[i].massa<<endl;
            cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<endl;
            cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<endl;
            cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<endl<<endl;
		}
		if(solare[i].tipo=="a"){                                                 //asteroide
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"       :.        Massa: "<<solare[i].massa<<endl;
            cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<endl;
            cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<endl;
            cout<<"             .   Distanza dal sole "<<solare[i].distsol<<endl<<endl;
		}
		if(solare[i].tipo=="s"){                                                 //satellite
			cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<endl;
            cout<<"                 Diametro: "<<solare[i].diametro<<endl;
            cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<endl;
            cout<<"                 Distanza dal sole "<<solare[i].distsol<<endl<<endl;
		}
		if(solare[i].tipo=="p"){                                                 //cometa
			cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<endl;
            cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<endl;
            cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<endl;
            cout<<" .               Distanza dal sole "<<solare[i].distsol<<endl<<endl;
		}
		
	}
	system("pause");
}

void vdto(s_sistema solare[],int n){
	int c1=0;
	string app;
	system("cls");
	do{
    if(c1>=1){
	cout<<"  > ERRORE <"<<endl<<endl;
	}
	cout<<" Dimmi il tipo di oggetto (p=pianeta, a=asteroide, c=cometa, s=satellite): ";
	fflush(stdin);
	getline(cin,app);	
	c1++;
	}while(app!="a" && app!="c" && app!="s" && app!="p");
	system("cls");
	for(int i=0;i<n;i++){
		if(app=="c"){
		if(solare[i].tipo=="c"){                                                 //cometa
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"     OO          Massa: "<<solare[i].massa<<endl;
            cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<endl;
            cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<endl;
            cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<endl<<endl;
		}	
		}
		if(app=="a"){
		if(solare[i].tipo=="a"){                                                 //asteroide
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"       :.        Massa: "<<solare[i].massa<<endl;
            cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<endl;
            cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<endl;
            cout<<"             .   Distanza dal sole "<<solare[i].distsol<<endl<<endl;
		}
	    }
	    if(app=="s"){
		if(solare[i].tipo=="s"){                                                 //satellite
			cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<endl;
            cout<<"                 Diametro: "<<solare[i].diametro<<endl;
            cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<endl;
            cout<<"                 Distanza dal sole "<<solare[i].distsol<<endl<<endl;
		}
	    }
	    if(app=="p"){
		if(solare[i].tipo=="p"){                                                 //cometa
			cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<endl;
            cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<endl;
            cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<endl;
            cout<<" .               Distanza dal sole "<<solare[i].distsol<<endl<<endl;
		}
	    }
	}
	system("pause");
}



//animazioni
void menu(int n){
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                   O    "<<endl;
	cout<<" |  0-Exit                                  |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |       O  .      .       "<<endl;
	cout<<" |  1-Carica                                |                        "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                 O      "<<endl;
	cout<<" |  0-Exit                                  |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |         O.      .       "<<endl;
	cout<<" |  1-Carica                                |                        "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                        "<<endl;
	cout<<" |  0-Exit                                  |               O        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");	
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .O     .       "<<endl;
	cout<<" |  1-Carica                                |                        "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                        "<<endl;
	cout<<" |  0-Exit                                  |             O          "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");	
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .   O  .       "<<endl;
	cout<<" |  1-Carica                                |                        "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                        "<<endl;
	cout<<" |  0-Exit                                  |         O              "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");	
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .O      "<<endl;
	cout<<" |  1-Carica                                |                        "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                        "<<endl;
	cout<<" |  0-Exit                                  |      O                 "<<endl;
	cout<<"  |________________________________________|        .               "<<endl;
	Sleep(50);
	system("cls");	
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |                   O    "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |     O                  "<<endl;
	cout<<" |  0-Exit                                  |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");	
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |                        "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO     O  "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
	cout<<" |  5-Modifica un oggetto                   |    O   OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                        "<<endl;
	cout<<" |  0-Exit                                  |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");	
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |                        "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |    O [(((((())))))] O  "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                        "<<endl;
	cout<<" |  0-Exit                                  |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");	
	
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |                        "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |    O     OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO    O   "<<endl;
	cout<<" |  7-Visualizzazioni                       |                        "<<endl;
	cout<<" |  0-Exit                                  |                        "<<endl;
	cout<<"  |________________________________________|                         "<<endl;
	Sleep(50);
	system("cls");	
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                   O    "<<endl;
	cout<<" |  0-Exit                                  |                        "<<endl;
	cout<<"  |________________________________________|      Num Oggetti="<<n<<endl;
	
}
//Thomas
void vmenu(int n){
	
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-Visualizzazioni                       |                   O    "<<endl;
	cout<<" |  0-Exit                                  |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-   ualizzazioni                       |                   O    "<<endl;
	cout<<" |      it                                  |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-       zzazioni                       |                   O    "<<endl;
	cout<<" |                                          |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-          zioni                       |                   O    "<<endl;
	cout<<" |                                          |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-             ni                       |                   O    "<<endl;
	cout<<" |                                          |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-                                      |                   O    "<<endl;
	cout<<" |                                          |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |  Visualizzazione                    |                         "<<endl;
	cout<<"     |  1-Totale                           |                         "<<endl;
	cout<<"     |  2-Pianeti e satelliti              |                         "<<endl;
	cout<<"     |  3-Dati da un tipo di Oggetto       |                         "<<endl;
	cout<<"     |  4-Ordinata                         |                         "<<endl;
	cout<<"     |  5-Intervallo                       |                         "<<endl;
	cout<<"     |  6-Personalizzato                   |                         "<<endl;
	cout<<"     |  0-Exit                             |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;

}
void caricamento(){
	                //non contiene Sleep (non fa attendere) ed è in fase di test
	system("cls");
	for(int i=0;i<5;i++){
		    cout<<endl<<endl<<endl<<endl<<endl<<endl;
		    cout<<"                                                      "<<endl;
		    cout<<"               I>                                    I"<<endl;
		    cout<<"                                                      "<<endl;
		    system("cls");
	}
	for(int i=0;i<5;i++){
		    cout<<endl<<endl<<endl<<endl<<endl<<endl;
		    cout<<"              :   :  .                                "<<endl;
		    cout<<"               I :  .::)>                            I"<<endl;
		    cout<<"               .   :.             20%                 "<<endl;
		    system("cls");
	}
	for(int i=0;i<5;i++){
		    cout<<endl<<endl<<endl<<endl<<endl<<endl;
		    cout<<"                     .   .  . .                       "<<endl;
		    cout<<"               I  .       :.  :.)>                   I"<<endl;
		    cout<<"                    .   .    .    43%                 "<<endl;
		    system("cls");
	}
	for(int i=0;i<5;i++){
		    cout<<endl<<endl<<endl<<endl<<endl<<endl;
		    cout<<"                          .      .  .                 "<<endl;
		    cout<<"               I      .      .   :.: ..)>            I"<<endl;
		    cout<<"                        .       . 60%                 "<<endl;
		    system("cls");
	}
	for(int i=0;i<5;i++){
		    cout<<endl<<endl<<endl<<endl<<endl<<endl;
		    cout<<"                         .    .        ..  .          "<<endl;
		    cout<<"               I                 :    . :.  :.)>     I"<<endl;
		    cout<<"                        .    .    90%   . :           "<<endl;
		    system("cls");
	}
	        
}


