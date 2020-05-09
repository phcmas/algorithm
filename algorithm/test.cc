#include <vector>
#include <iostream>
#include <math.h>

int main() {
    int ndv = -1;
    std::vector<double> datas;
    std::vector<double> normalized_datas;
    std::vector<double> frequencies;
    double temp =0;
    double mean =0;
    double std_deviation =0;
    double total_count =0;
    double kurtosis = -1;

    std::cout << "insert ndv: ";
    std::cin >> ndv;

    if (ndv == -1) {
        int _ndv, highest_frequency, frequency;
        std::cin >> _ndv >> highest_frequency >> frequency;
        for (int i=0; i< _ndv; ++i) {
            if (i %2 ==0) {
                datas.push_back(-i/2);
            } else {
                datas.push_back((i+1)/2);
            }
            if (i == 0) {
                frequencies.push_back( highest_frequency);
                total_count += highest_frequency;
            } else {
                frequencies.push_back(frequency);
                total_count += frequency;
            }
        }
        ndv = _ndv;
    } else {
        for (int i=0; i< ndv; ++i) {
            double data; 
            double frequency;
            std::cin >> data >> frequency;
            datas.push_back(data);
            frequencies.push_back(frequency);
            total_count += frequency;
        }
    }

    for (int i=0; i< ndv; ++i) {
        //std::cout << "datas[i] : " << datas[i] <<std::endl;
        //std::cout << "frequencies[i] : " << frequencies[i] <<std::endl;
        temp += datas[i] * frequencies[i];
    }
    std::cout << "total sum : " << temp << std::endl;
    std::cout << "total count : " << total_count << std::endl;
    mean = temp / total_count;
    temp = 0;

    for (int i=0; i < ndv; ++i) {
        temp += (datas[i]-mean) * (datas[i]-mean);
    }
    std::cout << "upper term : " << temp <<std::endl;
    std_deviation = sqrt(temp / total_count);

    std::cout << "Mean before normalization : " << mean <<", " << "StdDeviation before normalization : " << std_deviation <<std::endl;
    
    for (int i=0; i < ndv; ++i) {
        double num = datas[i];
        double normalized_data = (num -mean)/std_deviation;
        //std::cout << i << "th normalization data : " << normalized_data << std::endl;
        normalized_datas.push_back(normalized_data);
    }

    temp =0;

    for (int i=0; i< ndv; ++i) {
        temp += normalized_datas[i] * frequencies[i];
    }
    mean = temp / total_count;
    temp = 0;

    for (int i=0; i < ndv; ++i) {
        temp += (normalized_datas[i]-mean) * (normalized_datas[i]-mean);
    }
    std_deviation = sqrt(temp / total_count);
    std::cout << "Mean after normalization :" << mean <<", " << "StdDeviation after normalization : " << std_deviation <<std::endl;

    temp =0;
    for (int i=0; i < ndv; ++i) {
        temp += normalized_datas[i] * normalized_datas[i]* normalized_datas[i]* normalized_datas[i];
    }
    std::cout << "Kurtosis : " << temp/total_count <<std::endl;

}



















