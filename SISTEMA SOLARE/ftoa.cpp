using namespace std;

// Funzione da float/double a string
string ftoa(double x){
    string str, str1="",str2, strdec="";
	char tmp[100];
	int xint,e=0,r=0,y=0,c=0,i=0; 
	double xdec;
	int cifre=5;
	// parte intera
	xint = (int) x;
	itoa(xint, tmp, 10);
	str = (string)tmp;
	// parte decimale
	xdec = x-xint;
    for (int i=0; i<cifre; i++) {
 		xdec *= 10;	   	
	}
	xint = (int) xdec;
	itoa(xint, tmp, 10);
	strdec += (string)tmp;	
	// composizione stringa
	str += "." + strdec;
	y=1;
	c=0;
	i=0;
	for(i=str.length()-1; i>=0; i--){            //controllo zeri e nove superflui
	if(i!=0){                                    // unico errore con es 4.006 causato da  xdec = x-xint; riga 15 vengono eliminati i 2 zeri.
	if(str.at(i-1)=='.'){
 		e=1;
		}	
	}
	
		   	if((str.at(i)=='0' || str.at(i)=='9') && e!=1 && y==1){
		   }
		   else{
		   	 str1+=str.at(i);
		   	 y=0;
		   }
		   
    }
    for(i=0; i<str1.length(); i++){ 
	str2+=str1.at(i);	   
    }
    c=str1.length()-1;
    for(i=0; i<str1.length(); i++){ 
	str2.at(c)=str1.at(i);	   
	c--;
    }
	return str2;
}
