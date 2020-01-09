template <typename T> 

class Data {
    private:
        T data;
    public:
        Data(T data){
            this.data = data
        }
        ~Data();

        T getData(){
            return data;
        }
};