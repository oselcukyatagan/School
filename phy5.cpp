
double calculate(double ampere){
    double upper = 5.1 - (4.1 * ampere);
    double lower =  (4.1 * ampere) - 1 ;

    double result = (upper) / lower;

    return result;
}

void percent(vector<double> r1, vector<double> r2){
    for (int i = 0; i < r1.size(); ++i) {
        double per = (r1[i] - r2[i]) / r1[i];
        double percent = per * 100;

        cout << percent << endl;
    }
}


int main() {

    vector<double> amperes = {0.742, 0.588, 0.508, 0.460, 0.428, 0.405, 0.387, 0.374, 0.363, 0.354};


  /*

    for (int i = 0; i < amperes.size(); i++) {
        cout << calculate(amperes[i]) << endl;
    }

  */

  vector<double> r1 = {1.02, 2.003, 3.081, 4.235, 5.250, 5.666, 7.333, 7.696, 8.804, 10.111};
  vector<double> r2 = {1.007, 1.906, 2.786, 3.628, 4.432, 5.207, 5.988, 6.687, 7.496, 8.083};

  percent(r1,r2);


}
