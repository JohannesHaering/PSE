template <typename T> 

class Data {
    private:
        T data;
    public:
        Data(T data);
        ~Data();
        T getData();
};