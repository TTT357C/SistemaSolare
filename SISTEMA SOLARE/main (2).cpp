#include <iostream>
#include <Windows.h>
#include "ftoa.cpp"

using namespace std;
//prototipi

//struct
struct s_sistema{
	string nome;
	string tipo;
	string pianetaapp;
	double massa;
	double diametro;
	double perdiriv;
	double distsol;
};

const int N=100;
const string nomeF="sistemsolar.txt";

//funzioni void
void rig6();
void menu(int n);
void vmenu(int n);
void caricamento();
void caricamento2();
void vpes(s_sistema solare[],int n);
void vdto(s_sistema solare[],int n);
void vord(s_sistema solare[],int n);
void vint(s_sistema solare[],int n);
void vapp(s_sistema solare[],int n);
void salva(s_sistema solare[],int *n);
void modifica(s_sistema solare[],int n);
void cancella(s_sistema solare[],int *n);
void inserisci(s_sistema solare[],int *n);
void visualizza(s_sistema solare[],int n);
void bub(s_sistema solare[],int n,int num);
void sovrascrivi(s_sistema solare[],int *n);

//funzioni int
int cerca(s_sistema solare[],int n);
int carica(s_sistema solare[],int *n);

//creato da Thomas Causetti

int main(int argc, char** argv) {
	//variabili
	s_sistema solare[N];
	int n=0,s,s1,a;
	//do while
	do{
		s=0;
	menu(n);
	cout<<endl;
	cout<<" ";
	cin>>s;
	  //start switch 1
	  switch(s){
		  case 0:
		  	system("cls");
		  	cout<<endl<<endl<<endl;
		  	cout<<"           ____  _   _  _____  __  __    __     ___   "<<endl; 
            cout<<"          (_  _)( )_( )(  _  )(  )(  )  (__)   (  _)  "<<endl;
            cout<<"            )(   ) _ (  )(_)(  )    (  ((__))  _)(    "<<endl;
            cout<<"           (__) (_) (_)(_____)(_)()(_)(__)(__)(___)   "<<endl;
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
		    modifica(solare,n);
		  break;
		  
		  case 6:
		    caricamento();
		    cancella(solare,&n);
		  break;
		  
		  case 7:
		  	  // secondo do while
		      do{
		      	vmenu(n);
		  	     s1=0;
		  	     cin>>s1;
		  	     //start switch 2
		  	      switch(s1){
		  	        case 0:
		            break;
		            
		            case 1:
		            caricamento2();
		            visualizza(solare,n);
		            break;
		            
		            case 2:
		            caricamento2();
		            vpes(solare,n); 
		            break;
		            
		            case 3:
		            caricamento2();
		            vdto(solare,n);
		            break;
		            
		            case 4:
		            caricamento2();
		            vord(solare,n);
		            break;
		            
		            case 5:
		            caricamento2();
		            vint(solare,n);
		            break;
		            
		            case 6:
		            caricamento2();
		            vapp(solare,n);
		            break;
		            
		            default:
		            system("cls");
		            cout<<endl<<endl<<endl;
		            cout<<"           > ERRORE <"<<endl;
		            cout<<endl<<endl<<endl;
		            system("pause");
		            break; 
		        }//end switch 2
		  }while(s1!=0);
		  
		  break;
		  default:
		  system("cls");
		  cout<<endl<<endl<<endl;
		  cout<<"           > ERRORE <"<<endl;
		  cout<<endl<<endl<<endl;
		  system("pause");
		  break;  
	  }
	  //end switch 1
	}while(s!=0);
	
	return 0;
}

// INDICE

// 1-3 caricamento,salvataggio,sovrascrivi
// 4-6 inserimento,visualizza,vpes (visualizzazione pianeti e satelliti)
// 7-9 vdto (vis. dato tipo oggetto),vord (vis.ordinata),bub (bubblesort)
// 10-12 vint (vis. intervallo), cerca, cancella
// 13-14 modifica, vapp (vis. approfondimento)

int carica(s_sistema solare[],int *n){
       //Puntatore al file
	   FILE* fin;
       char riga[100]; //numero caratteri riga massimo
       int cont=0;
         //formato di lettura
           if((fin=fopen(nomeF.c_str(),"r"))!=NULL){
           	    while(fgets(riga,100,fin)){
           	  	    solare[cont].nome=strtok(riga,";");
           	  	    solare[cont].tipo=strtok(NULL,";");
           	  	    solare[cont].pianetaapp=strtok(NULL,";");
           	  	    solare[cont].massa=atof(strtok(NULL,";"));
           	  	    solare[cont].diametro=atof(strtok(NULL,";"));
           	  	    solare[cont].perdiriv=atof(strtok(NULL,";"));
           	  	    solare[cont].distsol=atof(strtok(NULL,";"));
           	  	    cont++;
				}
		   }
		   else{
		   	cout<<"Impossibile caricare file";
		   }
		return cont;
}

// 2
void salva(s_sistema solare[],int *n){
	//Puntatore al file
	FILE* pFout;
	//formato di scrittura in aggiunta
	string formato; 
	if((pFout=fopen(nomeF.c_str(),"a"))!=NULL){
		//scrivere su file
		for(int i=0;i<*n;i++){
	    formato=solare[i].nome+";"+solare[i].tipo+";"+solare[i].pianetaapp+";"+ftoa(solare[i].massa)+";"+ftoa(solare[i].diametro)+";"+ftoa(solare[i].perdiriv)+";"+ftoa(solare[i].distsol);
		fputs(formato.c_str(),pFout);
		fputc('\n',pFout);
	    }
	    fclose(pFout);
	}
	else{
		cout<<"Impossibile aprire il file"<<endl;
	}
}

// 3
void sovrascrivi(s_sistema solare[],int *n){
	//Puntatore al file
	FILE* pFout;
	//formato di scrittura
	string formato; 
	if((pFout=fopen(nomeF.c_str(),"w"))!=NULL){
		//scrivere su file
		for(int i=0;i<*n;i++){
	    formato=solare[i].nome+";"+solare[i].tipo+";"+solare[i].pianetaapp+";"+ftoa(solare[i].massa)+";"+ftoa(solare[i].diametro)+";"+ftoa(solare[i].perdiriv)+";"+ftoa(solare[i].distsol);
		fputs(formato.c_str(),pFout);
		fputc('\n',pFout);
	    }
	    fclose(pFout);
	}
	else{
		cout<<"Impossibile aprire il file"<<endl;
	}
}

// 4
void inserisci(s_sistema solare[],int *n){
	int c1=0;
	system("cls"); // cancellazione schermo
	cout<<endl;
	cout<<"                 Inserimento"<<endl<<endl;
	cout<<" Dimmi il nome dell'oggetto: ";
	fflush(stdin);
	getline(cin,solare[*n].nome);   //nome
	
	do{                      //controllo su tipo oggetto
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
	  	solare[*n].pianetaapp="/";    //Per non satelliti
	  }
	cout<<" Dimmi la massa del oggetto (in quadrilioni di kg): ";   //massa
	fflush(stdin);
	cin>>solare[*n].massa;
	cout<<" Dimmi la diametro del oggetto (in km): ";  //diametro
	fflush(stdin);
	cin>>solare[*n].diametro;
	cout<<" Dimmi la periodo di rivoluzione del oggetto (in giorni): ";  //perdiriv
	fflush(stdin);
	cin>>solare[*n].perdiriv;
	cout<<" Dimmi la distanza media dal sole (in ua): ";  //distanza dal sole
	fflush(stdin);
	cin>>solare[*n].distsol;
	*n=*n+1;                          //incremento
}

// 5
void visualizza(s_sistema solare[],int n){
	system("cls");
	cout<<endl;
	for(int i=0;i<n;i++){
		
		if(solare[i].tipo=="a"){                                                 //asteroide
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
		if(solare[i].tipo=="c"){                                                 //cometa
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
		if(solare[i].tipo=="s"){                                                 //satellite
			cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
		if(solare[i].tipo=="p"){                                                 //pianeta
			cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
		
	}
	system("pause");
}

// 6
void vpes(s_sistema solare[],int n){
	system("cls");
	string a;
	int lun=0;
	cout<<endl;                     //ricerca pianeta
	for(int i=0;i<n;i++){
		if(solare[i].tipo=="p"){
			a=solare[i].nome;
			   cout<<"     OOOO    .   Nome:  "<<solare[i].nome<<endl;
               cout<<" .  OOOOOO       Tipo:  "<<solare[i].tipo<<endl;
               cout<<"     OOOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
               cout<<"   .         "<<endl;
               
		for(int i=0;i<n;i++){                            //ricerca lune
		      if(solare[i].tipo=="s" && solare[i].pianetaapp==a){
		      	 if(lun==0){
		      	    cout<<"              Lune: "<<endl;
			     }
			     cout<<"                            .   Nome:  "<<solare[i].nome<<endl;
                 cout<<"                .    OOO        Tipo:  "<<solare[i].tipo<<endl;
                 cout<<"                     OOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
                 cout<<endl;
                 lun++;
			  }
		
	    }	
		}
	}
	cout<<endl;
	system("pause");
}

// 7
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
		if(app=="a"){
		if(solare[i].tipo=="a"){                                                 //asteroide
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}	
		}
		if(app=="c"){
		if(solare[i].tipo=="c"){                                                 //cometa
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
	    }
	    if(app=="s"){
		if(solare[i].tipo=="s"){                                                 //satellite
			cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
	    }
	    if(app=="p"){
		if(solare[i].tipo=="p"){                                                 //pianeta
			cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
	    }
	}
	system("pause");
}

// 8
void vord(s_sistema solare[],int n){
	int a=0,e=1;
	do{
	if(e==1 && a!=0){
	system("cls");	
	cout<<" ERRORE "<<endl<<endl;	
	}
	cout<<endl;
	cout<<"         Visualizzazione ordinata scelta criterio"<<endl<<endl;
	cout<<" 1-Nome"<<endl;
	cout<<" 2-Tipo"<<endl;
	cout<<" 3-Massa"<<endl;
	cout<<" 4-Diametro"<<endl;
	cout<<" 5-Periodo di rivoluzione"<<endl;
	cout<<" 6-Distanza dal sole"<<endl;
	cout<<" 7-Pianeta di appartenenza: "<<endl;
	cin>>a;
	if(a==1 || a==2 || a==3 || a==4 || a==5 || a==6 || a==7){
	bub(solare,n,a);
	e=0;
	}
	}while(e==1);
	
	for(int i=0;i<n;i++){
		
		if(solare[i].tipo=="a"){                                                 //asteroide
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
		if(solare[i].tipo=="c"){                                                 //cometa
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
		if(solare[i].tipo=="s"){                                                 //satellite
			cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
		if(solare[i].tipo=="p"){                                                 //pianeta
			cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
		}
		
	}
	system("pause");
}

// 9
void bub(s_sistema solare[],int n,int num){
bool bol;
s_sistema temp;
switch(num){
		case 1:       //in base al num in entrata viene ordinato in base al criterio
		do{
		bol=false;
		     for(int i=0;i<n-1;i++){
	          	if(solare[i].nome>solare[i+1].nome){
	          		temp=solare[i];
	          		solare[i]=solare[i+1];
	          		solare[i+1]=temp;
	          		bol=true;
				}
	         }
	    }while(bol==true);
		break;
		case 2:
		do{
		bol=false;
		     for(int i=0;i<n-1;i++){
	          	if(solare[i].tipo>solare[i+1].tipo){
	          		temp=solare[i];
	          		solare[i]=solare[i+1];
	          		solare[i+1]=temp;
	          		bol=true;
				}
	         }
	    }while(bol==true);
		break;
		case 3:
		do{
		bol=false;
		     for(int i=0;i<n-1;i++){
	          	if(solare[i].massa>solare[i+1].massa){
	          		temp=solare[i];
	          		solare[i]=solare[i+1];
	          		solare[i+1]=temp;
	          		bol=true;
				}
	         }
	    }while(bol==true);
		break;
		case 4:
		do{
		bol=false;
		     for(int i=0;i<n-1;i++){
	          	if(solare[i].diametro>solare[i+1].diametro){
	          		temp=solare[i];
	          		solare[i]=solare[i+1];
	          		solare[i+1]=temp;
	          		bol=true;
				}
	         }
	    }while(bol==true);
		break;
		case 5:
		do{
		bol=false;
		     for(int i=0;i<n-1;i++){
	          	if(solare[i].perdiriv>solare[i+1].perdiriv){
	          		temp=solare[i];
	          		solare[i]=solare[i+1];
	          		solare[i+1]=temp;
	          		bol=true;
				}
	         }
	    }while(bol==true);
		break;
		case 6:
		do{
		bol=false;
		     for(int i=0;i<n-1;i++){
	          	if(solare[i].distsol>solare[i+1].distsol){
	          		temp=solare[i];
	          		solare[i]=solare[i+1];
	          		solare[i+1]=temp;
	          		bol=true;
				}
	         }
	    }while(bol==true);
		break;
		case 7:
		do{
		bol=false;
		     for(int i=0;i<n-1;i++){
	          	if(solare[i].pianetaapp>solare[i+1].pianetaapp){
	          		temp=solare[i];
	          		solare[i]=solare[i+1];
	          		solare[i+1]=temp;
	          		bol=true;
				}
	         }
	    }while(bol==true);
		break;
	}	
	
}

//10
void vint(s_sistema solare[],int n){
	int e=1,a=0;
	float dat1,dat2;
	do{
	if(e==1 && a!=0){
	system("cls");	
	cout<<" ERRORE "<<endl<<endl;	//controllo errore
	}	
	cout<<endl;
	cout<<"         Visualizzazione intervallo, sceglire criterio"<<endl<<endl;  //menu
	cout<<" 1-Massa"<<endl;
	cout<<" 2-Diametro"<<endl;
	cout<<" 3-Periodo di rivoluzione"<<endl;
	cout<<" 4-Distanza dal sole"<<endl;
	cout<<"   ";
	cin>>a;
	if(a==1 || a==2 || a==3 || a==4){
	e=0;
	}
	}while(e==1);
	cout<<" Dato 1 < Dato 2 "<<endl;   //dati
	cout<<" Dato 1: ";
	cin>>dat1;
	cout<<" Dato 2: ";
	cin>>dat2;
	   if(a==1){                          //in base a l'input ci sono casi siversi
	      system("cls");
	      cout<<endl;                 
	      for(int i=0;i<n;i++){
		        // visualizzazione 1
		        if(solare[i].tipo=="a" && solare[i].massa>dat1 && solare[i].massa<dat2){                                                 
			        cout<<"     .           Nome:  "<<solare[i].nome<<endl;
                    cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="c" && solare[i].massa>dat1 && solare[i].massa<dat2){                                                 
					cout<<"     .           Nome:  "<<solare[i].nome<<endl;
           		 	cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
           			cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
           		 	cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="s" && solare[i].massa>dat1 && solare[i].massa<dat2){                                                 
					cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            		cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            		cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="p" && solare[i].massa>dat1 && solare[i].massa<dat2){                                                
					cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            		cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
			
				  }
				}
			if(a==2){
	         system("cls");
	         cout<<endl;
	         for(int i=0;i<n;i++){
		         // visualizzazione 2
		        if(solare[i].tipo=="a" && solare[i].diametro>dat1 && solare[i].diametro<dat2){                                                 //cometa
			        cout<<"     .           Nome:  "<<solare[i].nome<<endl;
                    cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="c" && solare[i].diametro>dat1 && solare[i].diametro<dat2){                                                 //asteroide
					cout<<"     .           Nome:  "<<solare[i].nome<<endl;
           		 	cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
           			cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
           		 	cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="s" && solare[i].diametro>dat1 && solare[i].diametro<dat2){                                                 //satellite
					cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            		cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            		cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="p" && solare[i].diametro>dat1 && solare[i].diametro<dat2){                                                 //cometa
					cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            		cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
			
				  }
				}
			if(a==3){
	          system("cls");
	          cout<<endl;
	          for(int i=0;i<n;i++){
		         // visualizzatzione 3
		        if(solare[i].tipo=="a" && solare[i].perdiriv>dat1 && solare[i].perdiriv<dat2){                                                 //cometa
			        cout<<"     .           Nome:  "<<solare[i].nome<<endl;
                    cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="c" && solare[i].perdiriv>dat1 && solare[i].perdiriv<dat2){                                                 //asteroide
					cout<<"     .           Nome:  "<<solare[i].nome<<endl;
           		 	cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
           			cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
           		 	cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="s" && solare[i].perdiriv>dat1 && solare[i].perdiriv<dat2){                                                 //satellite
					cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            		cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            		cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="p" && solare[i].perdiriv>dat1 && solare[i].perdiriv<dat2){                                                 //cometa
					cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            		cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
			
				  }
				}
			if(a==4){
	          system("cls");
	          cout<<endl;
	          for(int i=0;i<n;i++){
		         // visualizzatzione 4
		        if(solare[i].tipo=="a" && solare[i].distsol>dat1 && solare[i].distsol<dat2){                                                 //cometa
			        cout<<"     .           Nome:  "<<solare[i].nome<<endl;
                    cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="c" && solare[i].distsol>dat1 && solare[i].distsol<dat2){                                                 //asteroide
					cout<<"     .           Nome:  "<<solare[i].nome<<endl;
           		 	cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
           			cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
           		 	cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="s" && solare[i].distsol>dat1 && solare[i].distsol<dat2){                                                 //satellite
					cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            		cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            		cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
				if(solare[i].tipo=="p" && solare[i].distsol>dat1 && solare[i].distsol<dat2){                                                 //cometa
					cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            		cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            		cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            		cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            		cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            		cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
					}
			
				  }
				}
	system("pause");
}
 
//11
int cerca(s_sistema solare[],int n){                   //ritorna -1 se non trova niente
	int e=0,c=0;
	string in;
	do{
	if(e==2){
			cout<<" < Errore > ";
		}
		e=2;                                           //controllo errore
	cout<<" Dimmi l'oggetto (EXIT per uscire): ";      //EXIT per uscire
	fflush(stdin);
	getline(cin,in);
	   for(int i=0;i<n;i++){
		 if(in==solare[i].nome){
			c=i;
			e=1;
			break;
		 }
	}
	}while(e!=1 && in!="EXIT");
	if(in!="EXIT"){
		return c;
	}	
	else{
		return -1;                                 //se non trovi niente
	}
}

//12
void cancella(s_sistema solare[],int *n){
	int c;
	for(int i=0;i<*n;i++){                            //visualizzazione codici
	  cout<<" "<<solare[i].nome<<endl;	
	  }
	c=cerca(solare,*n);                      //chiamata a cerca
	if(c!=-1){                             //se si trova
	for(int i=c;i<*n;i++){
		solare[i]=solare[i+1];
	}
	*n=*n-1;	                           //decremento
	}
}

//13
void modifica(s_sistema solare[],int n){
	cout<<endl;
	int c;
	int c1=0;
	
	for(int i=0;i<n;i++){                          //visualizzazione codici
	   cout<<" "<<solare[i].nome<<endl;	
	}
	c=cerca(solare,n);	                  //chiamata a cerca
	if(c!=-1){
		cout<<" Dimmi il nome: ";        //input
	       fflush(stdin);
		    getline(cin,solare[c].nome);
		do{ 
	    if(c1>=1){
	    cout<<"  > ERRORE <"<<endl<<endl;
	    }
	    cout<<" Dimmi il tipo di oggetto (p=pianeta, a=asteroide, c=cometa, s=satellite): ";
	       fflush(stdin);
            getline(cin,solare[c].tipo);
	         c1++;	
	    }while(solare[c].tipo!="a" && solare[c].tipo!="c" && solare[c].tipo!="s" && solare[c].tipo!="p");
	      if(solare[c].tipo=="s"){
	        cout<<" Dimmi il pianeta di appartenenza dell'oggetto: ";
	         fflush(stdin);
	        getline(cin,solare[c].pianetaapp);
	     }
	    cout<<" Dimmi la massa (in quadrilioni di kg): ";        //input
	        cin>>solare[c].massa;
	    cout<<" Dimmi il diametro (in km): ";        //input
	        cin>>solare[c].diametro;
	    cout<<" Dimmi il periodo di rivoluzione (in giorni): ";        //input
	        cin>>solare[c].perdiriv;
	    cout<<" Dimmi la distanza dal sole (in ua): ";        //input
	        cin>>solare[c].distsol;
	}
}

//Approfondimento: impostare preventivamente tutti i criteri di selezione 
//( es. tipo di oggetto, intervallo di dati, visualizzazione o meno dei satelliti)

//14
void vapp(s_sistema solare[],int n){
	string y,w;
	int e=1,a=0,c1=0;
	float dat1,dat2;
	int lun=0;
	do{
	cout<<" Visualizzazione satelliti (si o no)? ";   //visualizzazione satelliti?
	cin>>y;	
	}while(y!="si" && y!="no");
	if(y=="si"){
		
		do{
			if(e==1 && a!=0){
				system("cls");	
				cout<<" ERRORE "<<endl<<endl;	   //controllo errore
				}	
				cout<<endl;
				cout<<"       Intervallo, sceglire criterio (per pianeti)"<<endl<<endl;
				cout<<" 1-Massa"<<endl;
				cout<<" 2-Diametro"<<endl;
				cout<<" 3-Periodo di rivoluzione"<<endl;         //menu
				cout<<" 4-Distanza dal sole"<<endl;
				cout<<"   ";
				cin>>a;
					if(a==1 || a==2 || a==3 || a==4){   //controllo
					e=0;
					}
		}while(e==1);
		cout<<" Dato 1 < Dato 2 "<<endl;   //immissione dati
		cout<<" Dato 1: ";
	    cin>>dat1;
		cout<<" Dato 2: ";
		cin>>dat2;
	 if(a==1){                     //visualizzazioni diverse
	 system("cls");
	 string q;                       //1
	 cout<<endl;
	 for(int i=0;i<n;i++){
		if(solare[i].tipo=="p" && solare[i].massa>dat1 && solare[i].massa<dat2){
			q=solare[i].nome;
			   cout<<"     OOOO    .   Nome:  "<<solare[i].nome<<endl;
               cout<<" .  OOOOOO       Tipo:  "<<solare[i].tipo<<endl;
               cout<<"     OOOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
               cout<<"   .         "<<endl;
               
		for(int i=0;i<n;i++){
			  
		      if(solare[i].tipo=="s" && solare[i].pianetaapp==q){
		      	 if(lun==0){
			  	 cout<<"              Lune: "<<endl;
			     }
			     cout<<"                            .   Nome:  "<<solare[i].nome<<endl;
                 cout<<"                .    OOO        Tipo:  "<<solare[i].tipo<<endl;
                 cout<<"                     OOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
                 cout<<endl;
                 lun++;
			  }
		
	    }	
		}
	}
	}
	if(a==2){
	 system("cls");                    //2
	 string q;
	 cout<<endl;
	 for(int i=0;i<n;i++){
		if(solare[i].tipo=="p" && solare[i].diametro>dat1 && solare[i].diametro<dat2){
			q=solare[i].nome;
			   cout<<"     OOOO    .   Nome:  "<<solare[i].nome<<endl;
               cout<<" .  OOOOOO       Tipo:  "<<solare[i].tipo<<endl;
               cout<<"     OOOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
               cout<<"   .         "<<endl;
               cout<<"              Lune: "<<endl;
		for(int i=0;i<n;i++){
		      if(solare[i].tipo=="s" && solare[i].pianetaapp==q){
			     if(lun==0){
			  	 cout<<"              Lune: "<<endl;
			     }
			     cout<<"                            .   Nome:  "<<solare[i].nome<<endl;
                 cout<<"                .    OOO        Tipo:  "<<solare[i].tipo<<endl;
                 cout<<"                     OOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
                 cout<<endl;
                 lun++;
			  }
		
	    }	
		}
	}
	}
	if(a==3){
	 system("cls");                      //3
	 string q;
	 cout<<endl;
	 for(int i=0;i<n;i++){
		if(solare[i].tipo=="p" && solare[i].perdiriv>dat1 && solare[i].perdiriv<dat2){
			q=solare[i].nome;
			   cout<<"     OOOO    .   Nome:  "<<solare[i].nome<<endl;
               cout<<" .  OOOOOO       Tipo:  "<<solare[i].tipo<<endl;
               cout<<"     OOOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
               cout<<"   .         "<<endl;
               cout<<"              Lune: "<<endl;
		for(int i=0;i<n;i++){
		      if(solare[i].tipo=="s" && solare[i].pianetaapp==q){
			     if(lun==0){
			  	 cout<<"              Lune: "<<endl;
			     }
			     cout<<"                            .   Nome:  "<<solare[i].nome<<endl;
                 cout<<"                .    OOO        Tipo:  "<<solare[i].tipo<<endl;
                 cout<<"                     OOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
                 cout<<endl;
                 lun++;
			  }
		
	    }	
		}
	}
	}
	if(a==4){
	 system("cls");                  //4
	 string q;
	 cout<<endl;
	 for(int i=0;i<n;i++){
		if(solare[i].tipo=="p" && solare[i].distsol>dat1 && solare[i].distsol<dat2){
			q=solare[i].nome;
			   cout<<"     OOOO    .   Nome:  "<<solare[i].nome<<endl;
               cout<<" .  OOOOOO       Tipo:  "<<solare[i].tipo<<endl;
               cout<<"     OOOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
               cout<<"   .         "<<endl;
               cout<<"              Lune: "<<endl;
		for(int i=0;i<n;i++){
		      if(solare[i].tipo=="s" && solare[i].pianetaapp==q){
			     if(lun==0){
			  	 cout<<"              Lune: "<<endl;
			     }
			     cout<<"                            .   Nome:  "<<solare[i].nome<<endl;
                 cout<<"                .    OOO        Tipo:  "<<solare[i].tipo<<endl;
                 cout<<"                     OOO  .     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
                 cout<<endl;
                 lun++;
			  }
		
	    }	
		}
	}
	}
	
	cout<<endl;	
	}
	else{                          //se no satelliti
		do{
			if(e==1 && a!=0){
				system("cls");	
				cout<<" ERRORE "<<endl<<endl;        //controllo errrore	
				}	
				cout<<endl;
				cout<<"       Intervallo, sceglire criterio (per pianeti)"<<endl<<endl;
				cout<<" 1-Massa"<<endl;
				cout<<" 2-Diametro"<<endl;
				cout<<" 3-Periodo di rivoluzione"<<endl;
				cout<<" 4-Distanza dal sole"<<endl;
				cout<<"   ";
				cin>>a;
					if(a==1 || a==2 || a==3 || a==4){
					e=0;
					}
			}while(e==1);
			cout<<" Dato 1 < Dato 2 "<<endl;   //immissione dati
			cout<<" Dato 1: ";
	        cin>>dat1;
			cout<<" Dato 2: ";
			cin>>dat2;
		do{	
    	if(c1>=1){
	    	cout<<"  > ERRORE <"<<endl<<endl;   //controllo
	    	}
	    	cout<<" Dimmi il tipo di oggetto (p=pianeta, a=asteroide, c=cometa, s=satellite): ";
	    	fflush(stdin);
	    	getline(cin,w);
		c1++;	
		}while(w!="a" && w!="c" && w!="s" && w!="p");
		system("cls");
		cout<<endl;
		if(a==1){                                 //visualizzazione 1
		  for(int i=0;i<n;i++){
		
			if(w=="a" && solare[i].massa>dat1 && solare[i].massa<dat2){                                                 //cometa
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="c" && solare[i].massa>dat1 && solare[i].massa<dat2){                                                 //asteroide
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="s" && solare[i].massa>dat1 && solare[i].massa<dat2){                                                 //satellite
			cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="p" && solare[i].massa>dat1 && solare[i].massa<dat2){                                                 //cometa
			cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			
		}
	    }
	    if(a==2){                              //visualizzazione 2
		for(int i=0;i<n;i++){
		
			if(w=="a" && solare[i].diametro>dat1 && solare[i].diametro<dat2){                                                 //cometa
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="c" && solare[i].diametro>dat1 && solare[i].diametro<dat2){                                                 //asteroide
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="s" && solare[i].diametro>dat1 && solare[i].diametro<dat2){                                                 //satellite
			cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="p" && solare[i].diametro>dat1 && solare[i].diametro<dat2){                                                 //cometa
			cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			
		}
		}
		if(a==3){                                   //visualizzazione 3
		for(int i=0;i<n;i++){
		
			if(w=="a" && solare[i].perdiriv>dat1 && solare[i].perdiriv<dat2){                                                 //cometa
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="c" && solare[i].perdiriv>dat1 && solare[i].perdiriv<dat2){                                                 //asteroide
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="s" && solare[i].perdiriv>dat1 && solare[i].perdiriv<dat2){                                                 //satellite
			cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="p" && solare[i].perdiriv>dat1 && solare[i].perdiriv<dat2){                                                 //cometa
			cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			
		}
		}
		if(a==4){                                      //visualizzazione 4
		for(int i=0;i<n;i++){
		
			if(w=="a" && solare[i].distsol>dat1 && solare[i].distsol<dat2){                                                 //cometa
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .       :      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"     OO          Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    OOOOO .      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"      OOO        Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"   :         .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="c" && solare[i].distsol>dat1 && solare[i].distsol<dat2){                                                 //asteroide
			cout<<"     .           Nome:  "<<solare[i].nome<<endl;
            cout<<"  .   :   .      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"       :.        Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"    .   ::.      Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         :O      Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"             .   Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="s" && solare[i].distsol>dat1 && solare[i].distsol<dat2){                                                 //satellite
			cout<<"              .  Nome:  "<<solare[i].nome<<endl;
            cout<<"   .   OOOO      Tipo:  "<<solare[i].tipo<<endl;
            cout<<"      OOOOOO     Pianeta di appartenenza: "<<solare[i].pianetaapp<<endl;
            cout<<"    .  OOOO  .   Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"                 Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"         .       Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<"                 Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			if(w=="p" && solare[i].distsol>dat1 && solare[i].distsol<dat2){                                                 //cometa
			cout<<"             .   Nome:  "<<solare[i].nome<<endl;
            cout<<"     OOOOO       Tipo:  "<<solare[i].tipo<<endl;
            cout<<"   OOOOOOOOO     Massa: "<<solare[i].massa<<" Quadrilioni di Kg"<<endl;
            cout<<"   OOOOOOOOO     Diametro: "<<solare[i].diametro<<" Km"<<endl;
            cout<<"     OOOOO   .   Periodo di rivoluzione "<<solare[i].perdiriv<<" Giorni"<<endl;
            cout<<" .               Distanza dal sole "<<solare[i].distsol<<" Ua"<<endl<<endl;
			}
			
		}
		}
	}
	system("pause");
}

//animazioni
//menu
void menu(int n){
	system("cls");
	cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
//ripetizione prime 6 righe
void rig6(){
	cout<<endl;
    cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]     "<<endl;
	cout<<" |  5-Modifica un oggetto                   |        OOOOOOOOOO      "<<endl;
	cout<<" |  6-Cancella oggetto                      |    .     OOOOOO        "<<endl;	
}

//menu a tendina
void vmenu(int n){
	system("cls");
	rig6();
	cout<<" |  7-Visualizzazioni                       |                   O    "<<endl;
	cout<<" |  0-Exit                                  |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	
	system("cls");
	rig6();
	cout<<" |  7-   ualizzazioni                       |                   O    "<<endl;
	cout<<" |      it                                  |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	rig6();
	cout<<" |  7-       zzazioni                       |                   O    "<<endl;
	cout<<" |                                          |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	rig6();
	cout<<" |  7-          zioni                       |                   O    "<<endl;
	cout<<" |                                          |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	rig6();
	cout<<" |  7-             ni                       |                   O    "<<endl;
	cout<<" |                                          |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	rig6();
	cout<<" |  7-                                      |                   O    "<<endl;
	cout<<" |                                          |                        "<<endl;
	cout<<"  |________________________________________|        .                "<<endl;
	Sleep(50);
	system("cls");
	rig6();
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	rig6();
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	rig6();
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	rig6();
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	rig6();
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |                                     |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(50);
	system("cls");
	rig6();
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
	rig6();
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
	rig6();
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
	rig6();
	cout<<" |  7-______________________________________|                   O    "<<endl;
	cout<<"  |__|                                     |        .                "<<endl;
	cout<<"     |  Visualizzazione                    |                         "<<endl;
	cout<<"     |  1-Totale                           |                         "<<endl;
	cout<<"     |  2-Pianeti e satelliti              |                         "<<endl;
	cout<<"     |  3-Dati da un tipo di Oggetto       |                         "<<endl;
	cout<<"     |  4-Ordinata                         |                         "<<endl;
	cout<<"     |  5-Intervallo                       |                         "<<endl;
	cout<<"     |  6-Personalizzato                   |                         "<<endl;
	cout<<"     |  0-Torna al menu principale         |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;

}

//caricamento dopo menu normale (1) / tendina (2) 
//1
void caricamento(){
	system("cls");
	cout<<endl;
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
	cout<<"  |________________________________________|        .                "<<endl;
	
	Sleep(80);
	system("cls");
	cout<<endl;
	cout<<"                   -  > ME   < --                             "<<endl<<endl;
	cout<<"   __  ___  ___   ___     ______________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1 Ca  a                                |                        "<<endl;
	cout<<"    2-Sa a (in ag unta)                              O   OO        "<<endl;
	cout<<"     -Sov scrivi                                    OOOOO   OO   .  "<<endl;
	cout<<" |  4-Inse   sci nuovo og to                      [(((  ())))))]     "<<endl;
	cout<<"      Modifica un o etto                   |        OOO     OO      "<<endl;
	cout<<" |  6-Ca   lla og tto                      |    .     O   OO        "<<endl;
	cout<<" |   -Visu   zzaz   i                       |                        "<<endl;
	cout<<" |  0-Ex t                                                           "<<endl;
	cout<<"  |______   _____    _____    ___________|        .                "<<endl;
	
	Sleep(80);
	system("cls");
	cout<<endl;
	cout<<"                   -     E   < --                             "<<endl<<endl;
	cout<<"   __  ___  ___   ___     ____  ______                          "<<endl;
	cout<<"  |                                                        .       "<<endl;
	cout<<" |    Ca                                   |                        "<<endl;
	cout<<"       a (i      ta                                           "<<endl;
	cout<<"     -    sc  vi                                         O    .  "<<endl;
	cout<<" |   -I  e   s    o og to                      [(     )       "<<endl;
	cout<<"      M     c  u  o et                     |        O       OO      "<<endl;
	cout<<" |   -Ca   l  o                              .     O            "<<endl;
	cout<<" |   -Vi     z     i                       |                        "<<endl;
	cout<<" |     x t                                                           "<<endl;
	cout<<"  |______   _____    _____    ___      __         .                "<<endl;
	
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
//2
void caricamento2(){
	system("cls");
	cout<<endl;
	cout<<"                   -- > MENU < --                             "<<endl<<endl;
	cout<<"   ________________________________________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1-Carica                                |     O                  "<<endl;
	cout<<" |  2-Salva (in aggiunta)                   |          OOOOOO        "<<endl;
	cout<<" |  3-Sovrascrivi                           |        OOOOOOOOOO   .  "<<endl;
	cout<<" |  4-Inserisci nuovo oggetto               |      [(((((())))))]    "<<endl;
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
	cout<<"     |  0-Torna al menu principale         |                         "<<endl;
	cout<<"     |_____________________________________|                         "<<endl;
	Sleep(80);
	system("cls");
	cout<<endl;
	cout<<"                   -  > ME   < --                             "<<endl<<endl;
	cout<<"   __  ___  ___   ___     ______________                          "<<endl;
	cout<<"  |                                        |          .      .       "<<endl;
	cout<<" |  1 Ca  a                                |                        "<<endl;
	cout<<"    2-Sa a (in ag unta)                              O   OO        "<<endl;
	cout<<"     -Sov scrivi                                    OOOOO   OO   .  "<<endl;
	cout<<" |  4-Inse   sci nuovo og to                      [(((  ())))))]     "<<endl;
	cout<<"      Modifica un o etto                   |        OOO     OO      "<<endl;
	cout<<" |  6-Ca   lla og tto                      |    .     O   OO        "<<endl;
	cout<<" |  7-____  _____  _______  ______  _____ |                   O    "<<endl;
	cout<<"  |_ |                                     |        .                "<<endl;
	cout<<"     |   isual zione                    |                         "<<endl;
	cout<<"     |   -Totale                           |                         "<<endl;
	cout<<"        2-P  net  satelliti              |                         "<<endl;
	cout<<"     |   -Dati da un tipo di Oggetto       |                         "<<endl;
	cout<<"        4-Or  nata                         |                         "<<endl;
	cout<<"         -Intervallo                       |                         "<<endl;
	cout<<"     |  6-Pe  nalizzato                                             "<<endl;
	cout<<"     |   -Tor a a   nu principale         |                         "<<endl;
	cout<<"     |______  ________  ________  ________|                         "<<endl;
	Sleep(80);
	system("cls");
	cout<<endl;
	cout<<"                   -     E   < --                             "<<endl<<endl;
	cout<<"   __  ___  ___   ___     ____  ______                          "<<endl;
	cout<<"  |                                                        .       "<<endl;
	cout<<" |    Ca                                   |                        "<<endl;
	cout<<"    2-Sa a (in ag unta)                              O             "<<endl;
	cout<<"     -    sc  vi                                    O    O    .  "<<endl;
	cout<<" |   -I  e   s    o og to                      [(     ))]     "<<endl;
	cout<<"      M     c  u  o et                     |        O O     OO      "<<endl;
	cout<<" |   -Ca   l  o                              .     O            "<<endl;
	cout<<" |  7-____  _____  _______  _  _  _                            "<<endl;
	cout<<"  |_ |                                     |        .                "<<endl;
	cout<<"         i l zi e                                             "<<endl;
	cout<<"     |   -Tot  e                           |                         "<<endl;
	cout<<"        2-P  net  s e  ti              |                         "<<endl;
	cout<<"     |   -D  i da       di    tto       |                         "<<endl;
	cout<<"        4-Or  na                         |                         "<<endl;
	cout<<"         -I te  a  o                       |                         "<<endl;
	cout<<"     |   -Pe  n    z                                              "<<endl;
	cout<<"        -Tor a a   nu p     le         |                         "<<endl;
	cout<<"     |__  __  ___   _  ___  ___  __  ___|                         "<<endl;
	Sleep(80);
	system("cls");
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

