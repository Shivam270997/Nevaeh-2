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
        string s1,s2;
        ifstream File1;
        ifstream File2;
        ofstream f;
        int ln=0;
        int count =0;
        string s;
        const char delim = ',';

        File1.open("sample.txt");
        File2.open("sample.txt");
        while(getline(File1,s1)&&getline(File2,s2))
        {

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
                                cout<<"sequence is missing in file 1"<<endl;
                                break;
                        }
                if(x2!=ln)
                        {
                                cout<<"sequence is missing in file 2";
                                break;
                        }
                while(i<7)
                        {
                                if((out1[1]!="N"&&out1[1]!="M"&&out1[1]!="X"&&out1[1]!="T"))
                                        {
                                        cout<<"from file 1 line no:- "<<ln<<" no N,M,X,T found"<<endl;
                                        break;
                                        }
                                if((out2[1]!="N"&&out2[1]!="M"&&out2[1]!="X"&&out2[1]!="T"))
                                        {
                                        cout<<"from file 2 line no:- "<<ln<<" no N,M,X,T found"<<endl;
                                        break;
                                        }
                                if(out1[i].compare(out2[i])!=0)
                                        {
                                        cout<<"in line "<<ln<< " has unmatched char"<<endl;

                                        }
                                        i++;
                        }
        out1.empty();
        out2.empty();
        }
        f<<endl<<"END OF FILE"<<endl;
        cout<<"PROGRAM ENDS"<<endl;
        return 0;
}
