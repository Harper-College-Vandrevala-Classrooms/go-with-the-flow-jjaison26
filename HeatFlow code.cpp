#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
using namespace std;
void printLine() {
        cout << "+------";
}
class HeatFlow {
        private:
                float temp_i;
                int num_s;
                float K;
                vector<float> S_S;

        public:
                HeatFlow(float temp_i, int num_s, float K, vector<float> S_S) {
                        this->temp_i = temp_i;
                        this->num_s = num_s;
                        this->K = K;
                        for(int i = 0; i < num_s-1; i++) {
                                S_S.push_back(temp_i);
                        }
                        this->S_S = S_S;
                }
                void tick() {
                        vector<float> S_SClone(this->S_S);
                        for(int i = 0; i < S_S.size(); i++) {
                                if(i == (S_S.size()-1)) {
                                        S_SClone[i] =(S_S[i] + this->K * (S_S[0] - (2 * S_S[i]) + S_S[i-1]));
                                }
                                else if(i == 0) {
                                        S_SClone[i] =(S_S[i] + this->K * (S_S[i+1] - (2 * S_S[i]) + S_S[(S_S.size() -1)] ));
                                }
                                else{
                                S_SClone[i] =(S_S[i] + this->K * (S_S[i+1] - (2 * S_S[i]) + S_S[i-1]));
                                }
                        }
                        for(int i = 0; i < S_S.size(); i++) {
                                this->S_S[i] = S_SClone[i];
                        }

                }

                void pretty_print() {
                        for(int i = 0; i < this->S_S.size(); i++) {
                                printLine();
                        }
                        cout << "+" << endl;
                        for(int i = 0; i < this->S_S.size(); i++) {
                                if(i==0) {
                                        if((10-S_S[i]) <= 0) {
                                cout << "| " << setprecision(1)<< fixed << S_S[i];
                                }
                                        else if((10-S_S[i]) > 0) {
                                cout << "| " << setprecision(2)<< fixed << S_S[i];

                                }
                                }
                                else {
                                if((10-S_S[i]) <=0) {
                                cout << " | " << setprecision(1) << fixed << S_S[i];
                                }
                                else if((10-S_S[i]) > 0) {
                                cout << " | " << setprecision(2)<< fixed << S_S[i];
                                }
                                }
                        }
                        cout << " |" << endl;
                        for(int i = 0; i < this->S_S.size(); i++) {
                                printLine();
                        }
                        cout << "+" << endl << endl;


                }

};

int main() {
        string it_str, num_str, k_str, st_str;
        int num;
        float it, k, st;
        cout << "The ends of the rods are connected" << endl;
        do {
                cout << "Enter a value for the initial temperature: " << endl;
                getline(cin, it_str);
        }while(!isdigit(it_str[0]));
        it = stof(it_str);

        do {
                cout << "Enter a value for the number of sections: " << endl;
                getline(cin, num_str);
        }while(!isdigit(num_str[0]));
        num = stoi(num_str);

        do {
                cout << "Enter a value for the constant K: " << endl;
                getline(cin, k_str);
        }while(!isdigit(k_str[0]));
        k = stof(k_str);

        do {
                cout << "Enter a value for the starting temperature at position 0: " << endl;
                getline(cin, st_str);
        }while(!isdigit(st_str[0]));
        st = stof(st_str);
        vector<float> ss1 = {st};
        HeatFlow h2(it, num, k, ss1);
        for(int i = 0; i < 10; i++) {
                h2.pretty_print();
                h2.tick();
        }

        for(int i = 0; i < 250; i++) {
                h2.tick();
        }
        cout << "After 250 more seconds... :" << endl;
        h2.pretty_print();
        return 0;
}

