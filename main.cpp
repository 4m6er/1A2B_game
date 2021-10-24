#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

vector <int> Question(void);
//bool AnswerIsOk(char[]);
bool AnswerIsOk(string);
int TestA(string,vector<int>);
int TestB(string,vector<int>);
void PrintQuestion();

vector <int> Q;

int main() {
    string onoff;
    char arr[5];
    string input;
    int r=1;
    Start:
        std::cout << "Input 1A2B to start a new game!" << std::endl;
        cin>>onoff;
        cin.ignore();

    if(onoff == "1A2B" ){
        Question();
    } else {
        goto Start;
    }

    // PrintQuestion();

    Loop:
        cout<<"Give 4 different integers :^) "<<endl;
        cin>>input;

    if(!AnswerIsOk(input)) {
        cout<<"Error!! "<<endl;
        goto Loop;
    }



    cout<<r<<": "<<TestA(input,Q)<<"A"<<TestB(input,Q)<<"B"<<endl;
    r++;
    if(TestA(input,Q)!=4) goto Loop;
    else cout<<"congrats!!!! Answer is "<<Q[0]<<" "<<Q[1]<<" "<<Q[2]<<" "<<Q[3]<<endl;

    return 0;
}

vector<int> Question(void){
    vector <int> Q_number = {0,1,2,3,4,5,6,7,8,9};
    int random;
    srand(time(0));

    while(Q.size()<4){
        random=rand()%10;
        if(Q_number[random]==-1) continue;
        Q.push_back(Q_number[random]);
        Q_number[random]=-1;
    }

    return Q;
}

bool AnswerIsOk(string ans){

    if(ans.length() != 4) {
        return false;
    }

    for(int i=0;i<3;i++){
        if((int)ans[i] >57 || (int)ans[i]<48) return false;
        for(int j=i+1; j<4;j++){
            if(ans[i]==ans[j]){
                return false;
            }
        }
    }

    return true;
}


int TestA (string a , vector<int> q){
    int A=0;

    for(int k=0;k<4;k++){
        if((int)a[k]-48==q[k]){
            A++;
        }
    }

    return A ;
}

int TestB(string ar  , vector<int> qq){
    int B=0;

    for(int x=0; x<4 ; x++){
        for(int y=0;y<4;y++){
            if((int)ar[x]-48==qq[y]){
                if(x!=y){
                    B++;
                }
            }
        }
    }

    return B ;
}

void PrintQuestion() {
    cout<<Q[0]<<" "<<Q[1]<<" "<<Q[2]<<" "<<Q[3]<<endl;
}