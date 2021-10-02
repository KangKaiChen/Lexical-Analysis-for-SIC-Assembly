#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef struct {
	string instruction ;
	int column ;
	int label ;
} tabledata;


class Mission {
	public:
	string hs[100] ; //digit hashing table
	string shs[100] ; //String hashing table
	string lhs[100] ; //lable hashing table
    vector<tabledata> totalins ;
	vector<string> totaltoken ;
	vector<string> totalline ;
void Readtable() {
	string instruction ;
	fstream tablefile ;
	string table1 = "Table1.table" ;
	string table2 = "Table2.table" ;
	string table3 = "Table3.table" ;
	string table4 = "Table4.table" ;
	tabledata temp ;
	tablefile.open( table1.c_str(), fstream::in ) ;
	for(int i = 1 ; !tablefile.eof() ; i++) {
		tablefile >> instruction ;
		temp.instruction = instruction ;
		temp.label = 1 ;
		temp.column = i ;
		totalins.push_back(temp) ;
	}
	tablefile.close() ;
	
	tablefile.open( table2.c_str(), fstream :: in ) ;
	for(int i = 1 ; !tablefile.eof() ; i++) {
		tablefile >> instruction ;
		temp.instruction = instruction ;
		temp.label = 2 ;
		temp.column = i ;
		totalins.push_back(temp) ;
	}
	tablefile.close() ;	
	
	tablefile.open(table3.c_str(), fstream::in ) ;
	for(int i = 1 ; !tablefile.eof() ; i++) {
		tablefile >> instruction ;
		temp.instruction = instruction ;
		temp.label = 3 ;
		temp.column = i ;
		totalins.push_back(temp) ;
	}
	tablefile.close() ;	
	
	tablefile.open(table4.c_str(), fstream::in) ;
	for(int i = 1 ; !tablefile.eof() ; i++) {
		tablefile >> instruction ;
		temp.instruction = instruction ;
		temp.label = 4 ;
		temp.column = i ;
		totalins.push_back(temp) ;
	}
	tablefile.close() ;
	//for(int j = 0 ; j<data.size() ; j++) cout << data[j].site ;
	
   // for( int i = 0 ; i < totalins.size() ; i++)
    //  cout << totalins[i].instruction << endl ;
} // readtable/
void read() {
    int time = 0 ;
	fstream inFile, outFile ;
	string temp ;
	string linestr ;
	string filename ;
	do {
		cout << "Input a file name: " << endl ;;
		cout << "// 記得加上用甚麼檔例如.txt .obj "<< endl ;
		cin >> filename ;

		inFile.open(filename.c_str(), fstream::in) ;
		if(inFile.is_open())
			break;
		else cout << "File isn't exist" ;
			 break ;
	} while(true) ;  //end while
	
   if( inFile.is_open() ) {
   	  string str = ""  ;
   	  string line = "" ;
   	  bool have = false ;
   	  bool have1 = false ;
   	  bool havedot = false ;
   	  bool have2 = false ;
   	  bool have3 = false ;
   	  char sum ;
   	  inFile.get(sum) ; 
   for(int i = 0 ;  !inFile.eof() ; i++) {
      while( sum != ' ' && sum != '\n' && sum != '\t' ) {  
    			   	   have3 = false ;
		if( str != " " && sum == ',' || sum == '+' || sum == '-' ||  sum == '*' || sum == '/' || sum == ':'|| sum == ';' || sum == '?' || sum == '\''|| sum == '.' || sum == '=' || sum == '#' ||  sum == '#' || sum == '@' ) {
			 if( sum == '\'' && (str == "C" || str == "c" || str == "x" ||str == "X" )) {
			   have2 = true ;		
		     }
			 totaltoken.push_back( str ) ; 
			 str.clear() ; 
         } //  if 
         else if( sum != '\''  && str == "," || str == "+" || str == "-" ||  str == "*" || str == "/" || str == ":"|| str == ";" || str == "?" || str == "'"|| str == "." || str == "=" || str == "#" ||  str == "#" || str == "@" ) {
			 totaltoken.push_back( str ) ;
			 if( have2 ) {
			   if( str == "\'" ) {
			       str.clear() ; 
			 	  while( sum != '\'' ) {
			 		while( sum == ' ' ) {
					  line += sum ;
					  inFile.get(sum) ;
					 } // while
			 		str += sum ; 
   	                line += sum ;
			 		inFile.get(sum) ;
				 } // while 
				   totaltoken.push_back( str ) ; 
			       str.clear() ; 
			 } // if
			 else {
			   str.clear() ;
			 } // else
			   str.clear() ;
		   	  have2 = false ;
	       } // if
	       else
	       	  str.clear() ;
         } // else if
      	    str += sum ;  
   	        line += sum ;
		    inFile.get(sum) ; 
	    if( inFile.eof() ) {
	     if( line != "")
	       totalline.push_back(line) ;
		   line = "" ;	
	      break ;
		} // if
	  } // while
	   totaltoken.push_back( str ) ;
	   str = "" ;
	  if( sum == '\n') {
	  	totaltoken.push_back("\n") ;
	  	totalline.push_back(line) ;
		 line = "" ;	
	    inFile.get(sum) ;  
	  } // if
	  while( sum == ' ' || sum == '\t'  ) {
	    if( inFile.eof() )
	      break ;
	    line += sum ;
	    inFile.get(sum) ;  
	  } // while
     } // for    
     }  //if
    for(int i = 0 ; i < totaltoken.size() ; i++) {
       if( totaltoken[i] == "\t" || totaltoken[i] == " "  ) 
         totaltoken.erase( totaltoken.begin() + i  ) ; 
      } // for
    compare(filename) ;
    for(int i = 0 ; i < totaltoken.size() ; i++) {
      cout << totaltoken[i] << endl ;
    } // for
 	inFile.close() ;
 	
} // read

void compare(string filename ) {
	tabledata temp ;
    fstream outfile ;
    string output = "";
    vector<tabledata> table567 ;
    int k = 1 ;
    int u = 0 ;
    int j = 0 ;
    bool is_x = false ;
    bool is_c = false ;
	bool havedot = false ;
	bool haveother = false ;
	outfile.open("SIC_OUPUT.txt", fstream::out);
    for(int k = 0 ; k < totalline.size() ; k++) {
    	cout  << totalline[k] << endl ;
    	outfile <<  totalline[k] << endl ;
		for(int i = u ; i < totaltoken.size() ; i++) {
			if(totaltoken[i] != "\n" ){
				if( !havedot) {
			    for ( j = 0 ; j < totalins.size() ; j++) {
				  if(stricmp( totaltoken[i].c_str(), totalins[j].instruction.c_str()) == 0 && totaltoken[i+1] != "\'" ) {
					  cout <<"("<< totalins[j].label<<","<< totalins[j].column<<")" ; 
		              outfile <<"("<<totalins[j].label<<","<<totalins[j].column<<")" ; 
		              if( totaltoken[i] == "."){
		                havedot = true ;
				  	}  // if	
					break;
		          } // if
		          else if ( stricmp( totaltoken[i].c_str(), totalins[j].instruction.c_str()) == 0 && totaltoken[i+1] == "\'" && totaltoken[i] == "\'" ) { // '' 的情況 
		       	      cout <<"("<< totalins[j].label<<","<< totalins[j].column<<")" ; 
		              outfile <<"("<<totalins[j].label<<","<<totalins[j].column<<")" ; 	
		              break;
				  }  // else if 
		          if( i+1 < totaltoken.size() && totaltoken[i+1] == "\'" && (totaltoken[i] == "X" || totaltoken[i] == "x" ) ) {
					is_x = true ;	
				  } // if 
				  else if( i+1 < totaltoken.size() && totaltoken[i+1] == "\'" && ( totaltoken[i] == "c" || totaltoken[i] == "C" ) ) {
		          	is_c = true ;
		   	      } // else if
				} // for
				if(  j == totalins.size() && totaltoken[i] != ""  ) {
				  if( isdig( totaltoken[i] ) == true  ) { // 代表他是數字 	  
		              cout <<"("<< "6" <<","<< dig_hashing( totaltoken[i] )<<")" ; 
				 	   outfile <<"("<< "6" <<","<< dig_hashing( totaltoken[i] )<<")" ; 
				  } // if 
				  else if( islet( totaltoken[i] ) == true ) {
				   if ( i+1 < totaltoken.size() && totaltoken[i+1] == "\'"  && totaltoken[i-1] == "\'" ){ // 代表他是字串
				       if( is_x ) {
					     cout <<"("<< "6" <<","<<  dig_hashing( totaltoken[i] )<<")" ;
				  	     outfile <<"("<< "6" <<","<<  dig_hashing( totaltoken[i] )<<")" ;   
						 is_x = false ;
					   } // if
					   else if( is_c ){
					   	 cout <<"("<< "7" <<","<< label_hashing( totaltoken[i] )<<")" ;
				  	     outfile <<"("<< "7" <<","<< label_hashing( totaltoken[i] )<<")" ;
				  	     is_c = false ;
					   } // else if
					   else {
					     for ( j = 0 ; j < totalins.size() ; j++) {
				           if(stricmp( totaltoken[i].c_str(), totalins[j].instruction.c_str()) == 0 && totaltoken[i+1] == "\'" ) {
					        cout <<"("<< totalins[j].label<<","<< totalins[j].column<<")" ; 
		                    outfile <<"("<<totalins[j].label<<","<<totalins[j].column<<")" ; 	 
		                  break ;
				      } // if
			      } // for
					   } // else
				   } // if 
				   else if( i+1 < totaltoken.size() && totaltoken[i+1] != "\'"  ) {
					   cout <<"("<< "5" <<","<< string_hashing( totaltoken[i] )<<")"  ; 
				   	   outfile <<"("<< "5" <<","<< string_hashing( totaltoken[i] )<<")" ;
				   } // else if
				   else if (i == totaltoken.size()-1 ) {
				       cout <<"("<< "5" <<","<< string_hashing( totaltoken[i] )<<")"  ; 
				   	   outfile <<"("<< "5" <<","<< string_hashing( totaltoken[i] )<<")" ;
				   } // else if
				   else if ( totaltoken[i] != "X" && totaltoken[i] != "x" && totaltoken[i] != "c" && totaltoken[i] != "C" &&  totaltoken[i] != ".") {
				   	   cout << "---" ;
					   cout <<"("<< "5" <<","<< string_hashing( totaltoken[i] )<<")"  ; 
				   	   outfile <<"("<< "5" <<","<< string_hashing( totaltoken[i] )<<")" ;
				   } // else if
				  } // else if 	
				  else if ( totaltoken[i] != "X" && totaltoken[i] != "x" && totaltoken[i] != "c" && totaltoken[i] != "C") {
					 for ( j = 0 ; j < totalins.size() ; j++) {
				       if(stricmp( totaltoken[i].c_str(), totalins[j].instruction.c_str()) == 0 && totaltoken[i+1] == "\'" ) {
					      cout <<"("<< totalins[j].label<<","<< totalins[j].column<<")" ; 
		                  outfile <<"("<<totalins[j].label<<","<<totalins[j].column<<")" ; 	 
		                  break ;
				      } // if
			      } // for
				  } // else if 		  
				}  // if  
			  } // if have dot
			} // if  
			else{ 
			  cout  << endl ;
    	      outfile << endl ;
		      u = i +1 ;
		      havedot = false ;
		      is_x = false ;
		      is_c = false ; 
              break ;
            }//else 
		 } // for
   } //for
   outfile.close() ;
    totalins.clear() ;
	totaltoken.clear() ;
	 totalline.clear() ;
} // compare 

bool isdig(string str) {
	bool have = false ;
	for( int i = 0 ; i < str.size() ; i++ ) {
      if( ( int )str.at(i) >= 48 && (int)str.at(i) <= 57) 
      	have = true ;
      else
        have = false ;
    } // for
 return have ;
}

bool islet (string str) {
	bool have = false ;
	for( int i = 0 ; i < str.size() ; i++ ) {
      if( ( int )str.at(i) >= 48 || (int)str.at(i) <= 123 ) 
      	have = true ;
      else
        have = false ;
    } // for
 return have ;
}

int dig_hashing(string str) {
	int ascii = 0 ;
	for(int i=0; i<100 && str[i] !=NULL; i++) {
    	ascii = ascii + (int)str[i] ; 
    }
	ascii %= 100 ;
	
	while(!hs[ascii].empty() && hs[ascii] != str) {
	  if( strcmp( hs[ascii].c_str() , str.c_str() ) == 0 )
	    break ;
	  ascii++ ;
    } // while
	hs[ascii] = str ;
	return ascii ;
}

int string_hashing(string str) {
	int ascii = 0 ;
	for(int i=0; i<str.size() && str[i] !=NULL; i++) {
    	ascii = ascii + (int)str[i] ; 
    }
	ascii %= 100 ;
	
	while(shs[ascii] != "" ) {
	  if( strcmp(shs[ascii].c_str() , str.c_str() ) == 0 ) 
	    break ;
	  ascii++ ;
} // while
	shs[ascii] = str ;
	return ascii ;
}

int label_hashing(string str) {
	int ascii = 0 ;
	for(int i=0; i<str.size() && str[i] !=NULL; i++) {
    	ascii = ascii + (int)str[i] ; 
    }
	ascii %= 100 ;
	while(lhs[ascii] != "" ) {
	  if( strcmp(lhs[ascii].c_str() , str.c_str() )== 0 ) 
	    break ;
	  ascii++ ;
    } // while
	lhs[ascii] = str ;
	return ascii ;
}
} ; // Mission
	
	
int main() {
  Mission obj;
  int command = 0;
  string filename;
  
  do {
    cout << endl << "************    SP Homework1    ************";
    cout << endl << "* 0. QUIT                                  *";
    cout << endl << "* 1. Get Token & output file               *";
    cout << endl << "********************************************";
    cout << endl << "Input a choice(0, 1): ";
  	cin >> command;
  	switch( command ) {
  		case 0: return 0;
  		case 1: {
  			obj.Readtable();
	  		obj.read() ;
			break;
		} // case1

		default: {
			cout << "Command does not exist!" << endl ; 
			break;
		} // default
  		
	} // switch
  	
  } while(true);
  
  return 0 ;
} 
 

