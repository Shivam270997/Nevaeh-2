#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<sstream>
#include<vector>
#include<climits>
#include<string>

using namespace std;

void tokenize(string const &str, const char delim,vector<string> &out)
{
   int i=0;
    stringstream ss(str);

    string s;

    while (getline(ss, s, delim)) {
        if(i==0 || i==3);
        else{
        out.push_back(s);
        }
        i++;

    }
}

int main()
{
        string A,B;
        string s1,s2;
        ifstream File1;
        ifstream File2;
        ofstream f1,f2,f;
        unsigned int ln=0;
        int count =0;
        string s;
        const char delim = ',';
        cout<<"Enter the file 1 name"<<endl;
        getline(cin,A);
        cout<<"Enter the file 2 name"<<endl;
        getline(cin,B);

        File1.open(A.c_str());
        File2.open(B.c_str());
        f.open("diff.txt");
        while(1)
        {
                getline(File1,s1);
                getline(File2,s2);
                if(File1.eof() && File2.eof()){
                        break;}
                if(File1.eof())
                {
                        f2.open("file2.txt");
                        f2<<"Remaining line of File 2 is given below"<<endl;
                        do
                        {
                                vector<string>e2;
                                tokenize(s2,delim,e2);
                                if(e2.size()==7)
                                {
                                        for(int k=0;k<7;k++){

                                                f2<<e2[k]<<"\t";}
                                }

                                f2<<endl;
                                e2.empty();
                        }while(getline(File2,s2));
                        f2.close();
                        break;
                }
               if(File2.eof())
                {
                        f1.open("file1.txt");
                        f1<<"Remaining lines of file 1 is given below"<<endl;

                        do
                        {
                                vector<string>e1;
                                tokenize(s1,delim,e1);
                                if(e1.size()==7)
                                {
                                        for(int k=0;k<7;k++){

                                                f1<<e1[k]<<"\t";}
                                }
                                f1<<endl;

                                e1.empty();
                        }while(getline(File1,s1));
                        f1.close();
                        break;
                }
                int i=0,j=0;
                vector<string> out1;
                vector<string> out2;
                tokenize(s1,delim,out1);
                tokenize(s2,delim,out2);

                if(out1.size()<7 || out2.size()<7)
                {
                        out1.empty();
                        out2.empty();
                        continue;
                }
                ln++;
                stringstream geek1(out1[0]);
                stringstream geek2(out2[0]);
                int x1=0,x2=0;
                geek1>>x1;
                geek2>>x2;
                if(x1!=ln)
                        {
                                f<<"sequence is missing in file 1"<<endl;

                                break;
                        }
                if(x2!=ln)
                        {
                                f<<"sequence is missing from file 2"<<endl;

                                break;
                        }
                while(i<7)
                        {
                                if((out1[1]!="N"&&out1[1]!="M"&&out1[1]!="X"&&out1[1]!="T"))
                                        {
                                        f<<"from file 1 line no:- "<<ln<<" no N,M,X,T found"<<endl;

                                        break;
                                        }
                                if((out2[1]!="N"&&out2[1]!="M"&&out2[1]!="X"&&out2[1]!="T"))
                                        {
                                        f<<"from file 2 line no:- "<<ln<<" no N,M,X,T found"<<endl;

                                        break;
                                        }
                                if(out1[i].compare(out2[i])!=0)
                                        {
                                        f<<"in both file line no:- "<<ln<<" has unmatched char data"<<endl;

                                        }
                                        i++;
                        }
        out1.empty();
        out2.empty();
        }
        f<<endl<<"END OF FILE"<<endl;
        cout<<"PROGRAM ENDS"<<endl;
        f.close();
        return 0;
}
