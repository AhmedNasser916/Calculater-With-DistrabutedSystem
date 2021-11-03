#include<mpi/mpi.h>
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<cmath>
#include<algorithm>


using namespace std;

void sort(list<float> &number,list<char>&symble)
{ 
  
int len=symble.size();
list<char> ::iterator it = symble.begin();
list<char> ::iterator it2 = symble.begin();
list<char> ::iterator its = symble.begin();
list<char> ::iterator itss = symble.begin();
list<char> ::iterator end = symble.end();
list<float> ::iterator itn = number.begin();
list<float> ::iterator itns = number.begin();
list<float> ::iterator itnss = number.begin();
bool b=1;



while (b)
{
	b=0;
	for (it;it != end, itn!= number.end();it++, itn++)
	{
		
		//cout << '1' << endl;
		it2 = it;
		its = it;
		itss=it;
		its++;

		//cout << "ggggggggggggggggggggggggggggggggggggggggggggggggggggggggg" << endl;
	
	/* if(*itss=='(')
		{
			itss=symble.erase(itss);
			itns++;
		while (*itss!=')')
		{
		  float one= *itns;
		  itns=number.erase(itns);
		  cout<<one<<endl;
		  cout<<"number" <<*itns<<endl;
		  float sec=*itns;
		  itns=number.erase(itns);
		  cout << sec<<endl;

		  cout << "number" << *itns << endl;

		  float r;
		  char sv=*itss;
		  itss = symble.erase(itss);
		  cout << sv << endl;

		  cout << "sssss" << *itss << endl;

		  itss=symble.erase(itss);
	  	    if(sv=='+')
		    r=one+sec;
	    	else if(sv == '-')
			r = one + sec;
			else if (sv == '*')
				r = one * sec;

			else if (sv == '/')
				r = one / sec;

			else if (sv == '%')
				{
				r= one / sec;
		    	r = (r - trunc(r))*sec;
				}
			else if (sv == '!')
			 {  r=1;
				for (int i = one;i >= 1;i--)
					r *= i;
			 
			 }

			else if (sv == '^')
			 { 
				for (int i = sec;i >= 1;i--)
					r *= one;

			 }

			 number.insert(itns,r);
			 itns--;
			 cout<<*itns<<endl;





		
		}
		
		symble.erase(itss);

		
		}
 
 */





		if ((*it2 == '+' || *it2 == '-') && (*(its) == '/' || *its == '*' || *its == '%'||*its=='^'))
		{
			b=1;
			swap(*it2, *its);
			itns = itn;
			itns++;
			swap(*itn, *itns);
			itns++;
			itn++;
			if (itns != number.end())
			{

				swap(*itn, *itns);
			}

		}
		/*
		1 2 3 2
		+ * / =

		2 3 1 2
		* + / =


		*/

	}

}
//cout<<"ggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"<<endl;

for (it = symble.begin(),itn = number.begin() ;it != symble.end(), itn != number.end();it++, itn++)
{
	
	cout<<*itn<<*it;

}
cout<<endl;



}

int main (int *arge,char**argec)
{ 
int rank,size;
MPI_Init(arge,&argec);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

int x=5;
int n=1;
if (rank==0)
{ 


  char g='#';	 
  list<float> df;
  list<char> sym;

	
  float number;
  cout << "enter the  number :";
  cin >> number;
  df.push_back(number);


	while (true)
	{
		cout << "enter the symble :";
		cin >> g; 
	/*	if(isdigit(g))
		{   
			df.push_back(int(g)-48);


		}
		else
		{
			

		}*/
		sym.push_back(g);
		if (g == '=')
			break;
        else if(g=='!'|| g == '#'||g=='('|| g == ')')
		   continue;
		cout << "enter the  number :";
		cin >> number;
		df.push_back(number);

	}

	/*
	1+2-(5*7)/3
	*/
	 
	sort(df,sym);
	list<float>::iterator it = df.begin();

	list<char>::iterator its = sym.begin();

	while (sym.size()!=1)
	{
		float reslut;
		it = df.begin();
		its = sym.begin();
	
		cout << *(its) << endl;
	
	if(*(its)=='*')
	{



	//cout<<"adam"<<endl;

	//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float one = *(it++);
		df.pop_front();
  //  cout<<"one"<<one<<endl;
	MPI_Send(&one, 1, MPI_FLOAT, 1, 1, MPI_COMM_WORLD);

	
//	cout << "size: " << sym.size() << "pop" << *(its) << endl;

	char symble = *(its++);
	sym.pop_front();
	//cout << "synm" << symble << endl;
	MPI_Send(&symble, 1, MPI_CHAR,1, 1, MPI_COMM_WORLD);



	//cout << "size: " << df.size() << "pop" << *(it) << endl;
	float sec = *(it++);
	df.pop_front();
	//cout << "sec" << sec << endl;
	MPI_Send(&sec, 1, MPI_FLOAT, 1, 1, MPI_COMM_WORLD);



	MPI_Recv(&reslut, 1, MPI_FLOAT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	cout << "reslult: " << reslut << endl;
	df.push_front(reslut);
	//cout << "sizee: " << df.size() << endl;
	cout << "--------------------------------------------" << endl;



	}


	else if( *(its) == '+')
	{  

	//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float one = *(it++);
		df.pop_front();

		MPI_Send(&one, 1, MPI_FLOAT, 2, 2, MPI_COMM_WORLD);


	//	cout << "size: " << sym.size() << "pop" << *(its) << endl;

		char symble = *(its++);
		sym.pop_front();

		MPI_Send(&symble, 1, MPI_CHAR, 2, 2, MPI_COMM_WORLD);



	//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float sec = *(it++);
		df.pop_front();

		MPI_Send(&sec, 1, MPI_FLOAT, 2, 2, MPI_COMM_WORLD);



		MPI_Recv(&reslut, 1, MPI_FLOAT, 2, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "reslult: " << reslut << endl;
		df.push_front(reslut);
		//cout << "sizee: " << df.size() << endl;
		cout << "--------------------------------------------" << endl;


	
	}

	else if (*(its) == '-' )
	{

		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
	   float one = *(it++);
		df.pop_front();

		MPI_Send(&one, 1, MPI_FLOAT, 3, 3, MPI_COMM_WORLD);


		//	cout << "size: " << sym.size() << "pop" << *(its) << endl;

		char symble = *(its++);
		sym.pop_front();

		MPI_Send(&symble, 1, MPI_CHAR, 3, 3, MPI_COMM_WORLD);



		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float sec = *(it++);
		df.pop_front();

		MPI_Send(&sec, 1, MPI_FLOAT, 3, 3, MPI_COMM_WORLD);



		MPI_Recv(&reslut, 1, MPI_FLOAT, 3, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "reslult: " << reslut << endl;
		df.push_front(reslut);
	//	cout << "sizee: " << df.size() << endl;
		cout << "--------------------------------------------" << endl;



	}

	else if (*(its) == '/' )
	{

		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float one = *(it++);
		df.pop_front();

		MPI_Send(&one, 1, MPI_FLOAT, 4, 4, MPI_COMM_WORLD);


		//	cout << "size: " << sym.size() << "pop" << *(its) << endl;

		char symble = *(its++);
		sym.pop_front();
		
		MPI_Send(&symble, 1, MPI_CHAR, 4, 4, MPI_COMM_WORLD);



		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float sec = *(it++);
		df.pop_front();

		MPI_Send(&sec, 1, MPI_FLOAT, 4, 4, MPI_COMM_WORLD);



		MPI_Recv(&reslut, 1, MPI_FLOAT, 4, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "reslult: " << reslut << endl;
		df.push_front(reslut);
	//    cout << "sizee: " << df.size() << endl;
		cout << "--------------------------------------------" << endl;



	}
	else if (*(its) == '%')
	{

		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float one = *(it++);
		df.pop_front();

		MPI_Send(&one, 1, MPI_FLOAT, 5, 5, MPI_COMM_WORLD);


		//	cout << "size: " << sym.size() << "pop" << *(its) << endl;

		char symble = *(its++);
		sym.pop_front();

		MPI_Send(&symble, 1, MPI_CHAR, 5, 5, MPI_COMM_WORLD);



		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float sec = *(it++);
		df.pop_front();

		MPI_Send(&sec, 1, MPI_FLOAT, 5, 5, MPI_COMM_WORLD);



		MPI_Recv(&reslut, 1, MPI_FLOAT, 5, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "reslult: " << reslut << endl;
		df.push_front(reslut);
		//    cout << "sizee: " << df.size() << endl;
		cout << "--------------------------------------------" << endl;



	}
	
	else if (*(its) == '!')
	{

		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float one = *(it++);
		df.pop_front();
		//cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
		MPI_Send(&one, 1, MPI_FLOAT, 7, 7, MPI_COMM_WORLD);


		//	cout << "size: " << sym.size() << "pop" << *(its) << endl;

		char symble = *(its++);
		sym.pop_front();
	
		MPI_Send(&symble, 1, MPI_CHAR, 7, 7, MPI_COMM_WORLD);



		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		/*float sec = *(it++);
		df.pop_front();

		MPI_Send(&sec, 1, MPI_FLOAT, 5, 5, MPI_COMM_WORLD);
*/

		
		MPI_Recv(&reslut, 1, MPI_FLOAT, 7, 7, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "reslult: " << reslut << endl;
		df.push_front(reslut);
		//    cout << "sizee: " << df.size() << endl;
		cout << "--------------------------------------------" << endl;



	}
	else if (*(its) == '^')
	{

		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float one = *(it++);
		df.pop_front();

		MPI_Send(&one, 1, MPI_FLOAT, 6, 6, MPI_COMM_WORLD);


		//	cout << "size: " << sym.size() << "pop" << *(its) << endl;

		char symble = *(its++);
		sym.pop_front();

		MPI_Send(&symble, 1, MPI_CHAR, 6, 6, MPI_COMM_WORLD);



		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float sec = *(it++);
		df.pop_front();

		MPI_Send(&sec, 1, MPI_FLOAT, 6, 6, MPI_COMM_WORLD);



		MPI_Recv(&reslut, 1, MPI_FLOAT, 6, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "reslult: " << reslut << endl;
		df.push_front(reslut);
		cout << "---------------------------------------------" << endl;
		//    cout << "sizee: " << df.size() << endl;



	}

	else if (*(its) == '#')
	{

		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		float one = *(it++);
		df.pop_front();
	
		MPI_Send(&one, 1, MPI_FLOAT, 8, 8, MPI_COMM_WORLD);


		//	cout << "size: " << sym.size() << "pop" << *(its) << endl;

		char symble = *(its++);
		sym.pop_front();
	
		MPI_Send(&symble, 1, MPI_CHAR, 8, 8, MPI_COMM_WORLD);



		//	cout << "size: " << df.size() << "pop" << *(it) << endl;
		/*float sec = *(it++);
		df.pop_front();

		MPI_Send(&sec, 1, MPI_FLOAT, 5, 5, MPI_COMM_WORLD);
		*/

		
		MPI_Recv(&reslut, 1, MPI_FLOAT, 8, 8, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "reslult : " << reslut << endl;
		//df.push_front(reslut);
		//    cout << "sizee: " << df.size() << endl;
		cout << "---------------------------------------------" << endl;



	}


	n++;
	}
	






}




			if(rank==1)
			{
			 char symble;
			 float one , reslut,second;
			 MPI_Recv(&one, 1, MPI_FLOAT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			 //cout<<"one: "<<one<<endl;
			 MPI_Recv(&symble, 1, MPI_CHAR, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			 //cout << "one: " << symble << endl;
			 MPI_Recv(&second, 1, MPI_FLOAT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			 //cout << "one: " << second << endl;
			  reslut=one*second;
			 // cout << "size: " <<reslut<<endl;
			  cout << "oparetion is : * " << endl;
		
			MPI_Send(&reslut, 1, MPI_FLOAT, 0, 1, MPI_COMM_WORLD);
		  
			 
          

			}







	        else if (rank ==2)
			{

				char symble;
				float one, reslut, second;
				MPI_Recv(&one, 1, MPI_FLOAT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&symble, 1, MPI_CHAR, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&second, 1, MPI_FLOAT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				reslut = one+second;
				MPI_Send(&reslut, 1, MPI_FLOAT, 0, 2, MPI_COMM_WORLD);
				cout << "oparetion is : +" << endl;



			}
			else if(rank==3)
			{
				char symble;
				float one, reslut, second;
				MPI_Recv(&one, 1, MPI_FLOAT, 0, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&symble, 1, MPI_CHAR, 0, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&second, 1, MPI_FLOAT, 0, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				reslut = one - second;
				MPI_Send(&reslut, 1, MPI_FLOAT, 0, 3, MPI_COMM_WORLD);
				cout << "oparetion is : -" << endl;



			}
			else if(rank==4)
			{
				char symble;
				float one, reslut=0, second;
				MPI_Recv(&one, 1, MPI_FLOAT, 0, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&symble, 1, MPI_CHAR, 0, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&second, 1, MPI_FLOAT, 0, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				if(second!=0)
				reslut = one / second;
				MPI_Send(&reslut, 1, MPI_FLOAT, 0, 4, MPI_COMM_WORLD);
				cout << "oparetion is : /" << endl;



			}
			else if (rank == 5)
			{
				char symble;
				float one, reslut = 0, second,temp;
				MPI_Recv(&one, 1, MPI_FLOAT, 0, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&symble, 1, MPI_CHAR, 0, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&second, 1, MPI_FLOAT, 0, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				if (second != 0)
					reslut = one / second;
					reslut= (reslut-trunc(reslut))*second;

				MPI_Send(&reslut, 1, MPI_FLOAT, 0, 5, MPI_COMM_WORLD);
				cout << "oparetion is : %" << endl;



			}

			else if (rank == 6)
			{
				char symble;
				float one, reslut = 1, second, temp;
				MPI_Recv(&one, 1, MPI_FLOAT, 0, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&symble, 1, MPI_CHAR, 0, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&second, 1, MPI_FLOAT, 0, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				//cout << "cccc" << second<<endl;

				for(int i=second;i>=1;i--)
				    reslut*=one;

				MPI_Send(&reslut, 1, MPI_FLOAT, 0, 6, MPI_COMM_WORLD);
				cout << "oparetion is : ^" << endl;



			}


			else if (rank == 7)  
			{
				char symble;
				float one, reslut = 1, second, temp;
				MPI_Recv(&one, 1, MPI_FLOAT, 0, 7, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&symble, 1, MPI_CHAR, 0, 7, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				//cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
				for (int i =one;i >= 1;i--)
					reslut *= i;

				MPI_Send(&reslut, 1, MPI_FLOAT, 0, 7, MPI_COMM_WORLD);
				cout << "oparetion is : !" << endl;



			}
			else if (rank == 8)
			{
				char symble;
				float one, reslut = 1, second, temp;
				MPI_Recv(&one, 1, MPI_FLOAT, 0, 8, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&symble, 1, MPI_CHAR, 0, 8, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				//cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
				
				if (one == 0 || one == 1) {
					reslut = 0;
				}
				else {
					for (int i = 2; i <= one / 2; ++i) {
						if (int(one) % i == 0) 
						{
	                        reslut=0;					   
							break;
						}
					}
				}



				MPI_Send(&reslut, 1, MPI_FLOAT, 0, 8, MPI_COMM_WORLD);
				cout << "oparetion is : prime or not ::  " << endl;



			}




MPI_Finalize();
return(0);

}