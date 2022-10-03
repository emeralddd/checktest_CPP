/**
darkemeralddd
**/
#include <bits/stdc++.h>
#define l2 long long
#define st first
#define nd second
#define ll2 pair<l2,l2>
#define ii pair<int,int>
#define iii pair<int,ii>
#define il2 pair<int,l2>
#define l2i pair<l2,int>
#define emerald ""
#define memset(a,b) memset(a,b,sizeof(a))
#define ladd(a) a=" "+a
#define bit(x,y) (((y)>>(x))&1)
#define infinity() for(;;)
const l2 mod = 1000000007;
using namespace std;
string compileCommandPrefix,currentPath,compareCmd;
int tests;
string slash,quote,backslash;
ifstream file;
void gcc() {
    cout<<"Searching for GCC configuration ...\n";
    string config;
    file.open(("conf"+slash+"gcc.txt").c_str());
        getline(file,config);
    file.close();
    if(config[0]=='!') compileCommandPrefix="g++.exe";
    else compileCommandPrefix=quote+config+quote;
}
void testGCC() {
    cout<<"Checking GCC configuration ...\n";

    string basic_cmd=compileCommandPrefix+" -v > nul 2> logs/config_err_logs.txt";
    const char *cmd = basic_cmd.c_str();
    bool status = system(cmd);
    if(status) {
        cout<<"There is an error, please check again your gcc.txt!";
        exit(0);
    }
}
void getCurrentPath() {
    cout<<"Getting Current Path ...\n";
    system("echo %cd% > tmp");

    file.open("tmp");
        getline(file,currentPath);
    file.close();

    while(currentPath[currentPath.size()-1]==' ') currentPath.erase(currentPath.size()-1,1);
}
void compileFile(string fn) {
    cout<<"Compiling File: "<<fn<<".cpp\n";
    bool status = system((compileCommandPrefix + " -O2 -std=c++11 -c "+currentPath+backslash+fn+".cpp -o "+currentPath+backslash+"obj/"+fn+".o 2> logs/compile_err_logs.txt").c_str());
    if(status) {
        cout<<"There is some errors, check compile_err_logs.txt for more details!";
        exit(0);
    }

    status = system((compileCommandPrefix + " -o "+currentPath+backslash+"bin/"+fn+".exe "+currentPath+backslash+"obj/"+fn+".o 2> logs/compile_err_logs.txt").c_str());

    if(status) {
        cout<<"There is some errors, check compile_err_logs.txt for more details!";
        exit(0);
    }

    cout<<"Compiled Successfully!\n";
}
void execute(string fn) {
    string s="";
    bool status = system((s+quote+currentPath+backslash+fn+quote+" 2> logs/runtime_err_logs.txt").c_str());
    if(status) {
        cout<<"There is some errors, check runtime_err_logs.txt for more details!";
        exit(0);
    }
}
void getOutputPath() {
    cout<<"Getting Output and Answer Path ...\n";

    string output_can,output_jud;
    file.open(("conf"+slash+"compare.txt").c_str());
        getline(file,output_can);
        getline(file,output_jud);
    file.close();

    cout<<"-------------------------------------------------------\n";
    cout<<"OUTPUT: "<<output_can<<"\nANS: "<<output_jud<<"\n";

    compareCmd="fc";
    compareCmd=compareCmd+" "+output_can+" "+output_jud+" > nul 2> logs/compare_err_logs.txt";
}
int main() {
    slash+=char(47);
    backslash+=char(92);
    quote+=char(34);

    gcc();
    testGCC();
    getCurrentPath();
    getOutputPath();

    cout<<"-------------------------------------------------------\n";
    cout<<"Welcome!\nDo you want to rebuild? (Y/N)\n";
    char res;
    cin>>res;

    if(res=='Y'||res=='y') {
        compileFile("genInp");
        compileFile("genOut");
        compileFile("sourceCode");
    }

    file.open(("conf"+slash+"tests.txt").c_str());
        file>>tests;
    file.close();

    cout<<"Number of Testcases will be tested: "<<tests<<"\n";

    cout<<"-------------------------------------------------------\n";

    for(int i=1; i<=tests; i++) {
        cout<<"Test "<<i<<"\n";
        execute("bin/genInp.exe");
        execute("bin/genOut.exe");
        execute("bin/sourceCode.exe");

        bool status=system(compareCmd.c_str());
        if(status) {
            cout<<"There is some differs or errors!";
            exit(0);
        }
        cout<<"Passed!\n";
    }

    cout<<"Passed All!";
}
