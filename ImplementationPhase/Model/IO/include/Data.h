#ifndef DATA_H
#define DATA_H

#include <string>
using namespace std;

template <class T>
class Data {
    private:
        T data;
    public:
        Data<T>(T data){
            this.data = data;
        }
        virtual T getData();
};
#endif