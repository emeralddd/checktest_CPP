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
void gcc() {
    freopen("config/gcc.dat","r",stdin);
    string config;
    getline(cin,config);
    if(config[0]=='!') compileCommandPrefix="g++.exe";
    else compileCommandPrefix=char(34)+config+char(34);
}
void testGCC() {
    string basic_cmd=compileCommandPrefix+" -v > nul 2> logs/config_err_logs.txt";
    const char *cmd = basic_cmd.c_str();
    bool status = system(cmd);
    if(status) {
        cout<<"There is an error, please check again your gcc.dat!";
        exit(0);
    }
}
void getCurrentPath() {
    system("echo %cd% > config/tmp.dat");
    freopen("config/tmp.dat","r",stdin);
    getline(cin,currentPath);
    while(currentPath[currentPath.size()-1]==' ') currentPath.erase(currentPath.size()-1,1);
}
void compileFile(string fn) {
    cout<<"Compiling File: "<<fn<<".cpp\n";
    bool status = system((compileCommandPrefix + " -O2 -std=c++11 -c "+currentPath+char(92)+fn+".cpp -o "+currentPath+char(92)+"obj/"+fn+".o 2> logs/compile_err_logs.txt").c_str());
    if(status) {
        cout<<"There is some errors, check compile_err_logs.txt for more details!";
        exit(0);
    }

    status = system((compileCommandPrefix + " -o "+currentPath+char(92)+"bin/"+fn+".exe "+currentPath+char(92)+"obj/"+fn+".o 2> logs/compile_err_logs.txt").c_str());

    if(status) {
        cout<<"There is some errors, check compile_err_logs.txt for more details!";
        exit(0);
    }

    cout<<"Compiled Successfully!\n";
}
void execute(string fn) {
    string s="";
    bool status = system((s+char(34)+currentPath+char(92)+fn+char(34)+" 2> logs/runtime_err_logs.txt").c_str());
    if(status) {
        cout<<"There is some errors, check runtime_err_logs.txt for more details!";
        exit(0);
    }
}
void getOutputPath() {
    freopen("config/compare.txt","r",stdin);
    string output_can,output_jud;
    getline(cin,output_can);
    getline(cin,output_jud);

    cout<<"OUTPUT: "<<output_can<<"\nANS: "<<output_jud<<"\n";

    compareCmd="fc";
    compareCmd=compareCmd+" "+output_can+" "+output_jud+" > nul 2> logs/compare_err_logs.txt";
}
int main() {

    cout<<"Welcome!\nDo you want to rebuild? (Y/N)\n";
    char res;
    cin>>res;

    gcc();

    testGCC();

    getCurrentPath();

    if(res=='Y'||res=='y') {
        compileFile("genInp");
        compileFile("genOut");
        compileFile("sourceCode");
    }

    getOutputPath();

    tests=5;
    cout<<"Number of Testcases will be tested: "<<tests<<"\n";

    cout<<"-------------------------------------------------------\n";

    for(int i=1; i<=tests; i++) {
        cout<<"Test "<<i<<"\n";
        execute("bin/genInp.exe");
        execute("bin/genOut.exe");
        execute("bin/sourceCode.exe");

        bool status=system(compareCmd.c_str());
        if(status) {
            cout<<"There is some differs!";
            exit(0);
        }
        cout<<"Passed!\n";
    }

    cout<<"Passed All!";

//    system("")
}
