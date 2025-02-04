#ifndef DATA_H
#define DATA_H

template <class T>
class Data
{
private:
    T data;

public:
    Data<T>(T data) {
        this->data = data;
    }
    T getData() {
        return data;
    }
};
#endif
