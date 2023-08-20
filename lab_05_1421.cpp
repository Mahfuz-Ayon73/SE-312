#include<iostream>
#include<fstream>

using namespace std;

int main()
{
   ifstream file_read("source_code.txt");

   string str , temp;

   int i=0,m;

   if (file_read.is_open())
    {
       while (file_read)
       {
         getline (file_read, str);

         for(int j=0;str[j];j++)
         {
           if(str[j] == '/' && str[j+1] == '/')
           {
             cout << "line no."<<i<< " ";
             for(int k=j+2; str[k] ;k++)
               {
                  cout << str[k] ;
               }
               cout << endl;
           }

           else if(str[j] == '/' && str[j+1] == '*')
           {
              cout << "line no."<< i << " ";
              for(int k=j+2; str[k] != '*' && str[k+1] != '/' ;k++)
               {
                  if(str[k] == '\0')
                  {
                    getline(file_read,str);
                     while(str[m] == ' ')
                        m++;
                     k = m;
                  }

                  temp += str[k];
               }
               cout <<temp<< endl;
               temp = '\0';
           }
         }
         i++;
        }
     }


}
